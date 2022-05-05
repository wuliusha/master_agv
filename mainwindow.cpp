#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    this->setWindowTitle("微网优联仓储系统");
    this->setAttribute(Qt::WA_DeleteOnClose);
    NewClassItiem();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::WidgetInit()
{
//    QDesktopWidget* desktopWidget = QApplication::desktop();
//    QRect deskRect = desktopWidget->availableGeometry();    //获取可用桌面大小
//    this->setStyleSheet("background-color: rgb(66, 66, 66)");
//    this->resize(deskRect.width(),deskRect.height());
//    this->setWindowFlags(Qt::FramelessWindowHint);    // 设置窗口标志

    this->setWindowState(Qt::WindowMaximized);
    this->setStyleSheet(tr("border:0xp"));
    this->showMaximized();
    ui->stackedWidget_2->setMaximumWidth(this->width()-40);

    //IconHelper::Instance()->setIcon(ui->Btn_Close, 0xf00d, 35);
//    helperInfoItem.fontScale=1.0;
//    helperInfoItem.sizeScale=1.0;
    helperInfoItem.listColorBg<<"#aa6666"<<"#aaaa66"<<"#5d9aa1"<<"#9999aa"<<"#CDB38B";
    helperInfoItem.listColorBg1<<"#aa6666"<<"#aaaa66"<<"#5d9aa1"<<"#9999aa"<<"#CDB38B";

    helperInfoItem.listColorText<<"#FEFEFE"<<"#FEFEFE"<<"#FEFEFE"<<"#FEFEFE"<<"#FEFEFE";
    helperInfoItem.listChar <<0xf108<<0xf2C2<<0xf07b<<0xf085<< 0xf03A;
    helperInfoItem.listText <<"主页"<<"任务管理"<<"库存管理"<<"设备管理"<<"日志";
    helperInfoItem.btns <<ui->Desktop_Button<< ui->OutStore_Button<<ui->StoreInfo_Button
                       <<ui->System_Button<<ui->logInfo_Button;
    button_single::GetInstance()->iconhelperinit(helperInfoItem);

}

void MainWindow::NewClassItiem()
{
   loginItiem=new Login;
   ManagerInfoItiem=new ManagerInfo;

   desktopServerI=new desktopServer;        //主页
   threaddesktopServer=new QThread();
   desktopServerI->moveToThread(threaddesktopServer);
   threaddesktopServer->start();

   storeInfoServerI=new storeInfoServer;    //库存管理
   threadstoreInfoServer=new QThread();
   storeInfoServerI->moveToThread(threadstoreInfoServer);
   threadstoreInfoServer->start();

   deviceServerI=new deviceServer;          //设备管理
   threaddeviceServer=new QThread();
   deviceServerI->moveToThread(threaddeviceServer);
   threaddeviceServer->start();

   taskManagerServerI=new taskManagerServer;//任务管理
   threadtaskManagerServer=new QThread();
   taskManagerServerI->moveToThread(threadtaskManagerServer);
   threadtaskManagerServer->start();

   threadServerI=new threadServer;
   threadServerItem=new QThread();
   threadServerI->moveToThread(threadServerItem);
   threadServerItem->start();

   agvCarPool1=new agvCarPool;
   agvCarPool1->listen(QHostAddress::Any,9001);
   ThreadagvCarPool=new QThread();
   agvCarPool1->moveToThread(ThreadagvCarPool);
   ThreadagvCarPool->start();
   //agvCarPool1->init();

   ui->stackedWidget->insertWidget(1,loginItiem);
   ui->stackedWidget->setCurrentIndex(1);

   ui->stackedWidget_2->insertWidget(0,desktopServerI->MainDesktopItiem);
   ui->stackedWidget_2->insertWidget(1,taskManagerServerI->taskmanagerItem);
   ui->stackedWidget_2->insertWidget(2,storeInfoServerI->StoreInfoItem);
   ui->stackedWidget_2->insertWidget(3,deviceServerI->DeviceManageItem);
   ui->stackedWidget_2->insertWidget(4,ManagerInfoItiem);

   ui->stackedWidget_2->setCurrentIndex(0);
   ui->stackedWidget->widget(0)->layout()->setContentsMargins(0,0,0,0);
   ui->stackedWidget->widget(1)->layout()->setContentsMargins(0,0,0,0);
   ui->stackedWidget_2->widget(0)->layout()->setContentsMargins(0,0,0,0);
   ui->stackedWidget_2->widget(1)->layout()->setContentsMargins(0,0,0,0);
   ui->stackedWidget_2->widget(2)->layout()->setContentsMargins(0,0,0,0);
   ui->stackedWidget_2->widget(3)->layout()->setContentsMargins(0,0,0,0);
   ui->stackedWidget_2->widget(4)->layout()->setContentsMargins(0,0,0,0);

   WidgetInit();
   CreateConnect();
}

void MainWindow::CreateConnect()
{
   connect(loginItiem,&Login::UserLogin,this,&MainWindow::ON_UserLogin);
   connect(agvCarPool1,&agvCarPool::AgvStateWidget,desktopServerI->MainDesktopItiem->monitoringServerI->monitoringI,&monitoring::ON_AgvStateWidget);
   connect(agvCarPool1,&agvCarPool::AgvStateWidget,taskManagerServerI,&taskManagerServer::ON_AgvStateWidget);

   connect(deviceServerI->DeviceManageItem,&DeviceManage::sig_LiftTaskStatus,taskManagerServerI,&taskManagerServer::ON_LiftTaskStatus);
   connect(deviceServerI->DeviceManageItem,&DeviceManage::sigDeviceStatus_station,taskManagerServerI,&taskManagerServer::ON_DeviceStatus_station);

   connect(taskManagerServerI,&taskManagerServer::sigDeviceStatusAction,deviceServerI->DeviceManageItem,&DeviceManage::ON_DeviceStatusAction);
   connect(taskManagerServerI,&taskManagerServer::sigsetLiftactionArray,deviceServerI->DeviceManageItem,&DeviceManage::ON_setLiftactionArray);

   //connect(taskManagerServerI,&taskManagerServer::sigDeviceStatusAction,deviceServerI->DeviceManageItem,&DeviceManage::ON_DeviceStatusAction);

   connect(taskManagerServerI,&taskManagerServer::sigChargeTask,agvCarPool1,&agvCarPool::ON_AGVChargeTask);
   connect(taskManagerServerI,&taskManagerServer::sigAGVMoveTask,agvCarPool1,&agvCarPool::onAGVMoveTask);



   connect(desktopServerI->MainDesktopItiem->monitoringServerI->monitoringI,&monitoring::sigAGVMoveTask,agvCarPool1,&agvCarPool::onAGVMoveTask);
   connect(desktopServerI->MainDesktopItiem->monitoringServerI->monitoringI,&monitoring::newAGVMoveTask,taskManagerServerI,&taskManagerServer::ON_AGVMoveTask);

   connect(storeInfoServerI->StoreInfoItem->binwidgetItem,&binwidget::sig_SAPExcelInfo_new,taskManagerServerI,&taskManagerServer::ON_SAPExcelInfo_new);
   connect(storeInfoServerI->StoreInfoItem->binwidgetItem,&binwidget::sig_containerCode_clear,taskManagerServerI,&taskManagerServer::ON_containerCode_clear);


   //connect(InStroageItiem,&InStroage::ChangeMaterialInfo,OutStroageItiem,&OutStroage::ON_ChangeMaterialInfo);


}

void MainWindow::ON_UserLogin(QString UserNuber,QString UserName)
{
    WidgetInit();
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_UserNuber->setText("工号:"+UserNuber);ui->label_UserName->setText("姓名:"+UserName);
}


//桌面显示
void MainWindow::on_Desktop_Button_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    button_single::GetInstance()->ButtonChageiconhelper(helperInfoItem,ui->Desktop_Button->text());
}
//出库管理操作
void MainWindow::on_OutStore_Button_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    button_single::GetInstance()->ButtonChageiconhelper(helperInfoItem,ui->OutStore_Button->text());
}
//库存管理
void MainWindow::on_StoreInfo_Button_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
    button_single::GetInstance()->ButtonChageiconhelper(helperInfoItem,ui->StoreInfo_Button->text());
}

//系统设置
void MainWindow::on_System_Button_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
    button_single::GetInstance()->ButtonChageiconhelper(helperInfoItem,ui->System_Button->text());
}

//日志管理
void MainWindow::on_logInfo_Button_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(4);
    button_single::GetInstance()->ButtonChageiconhelper(helperInfoItem,ui->logInfo_Button->text());
}
