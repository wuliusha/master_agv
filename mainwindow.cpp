#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("AGV仓储系统");
    NewClassItiem();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::WidgetInit(bool Visible)
{
    if(Visible){
        //this->setWindowFlags(Qt::FramelessWindowHint);    // 设置窗口标志
        this->setWindowState(Qt::WindowMaximized);
        this->setStyleSheet(tr("border:0xp"));
        this->showMaximized();

        ui->widget->setVisible(true);
        IconHelper::Instance()->setIcon(ui->lab_Ico, QChar(0xf015), 22);
        IconHelper::Instance()->setIcon(ui->btn_log, QChar(0xf05a), 20);
        IconHelper::Instance()->setIcon(ui->btn_Edite, QChar(0xf0c9), 18);
        IconHelper::Instance()->setIcon(ui->btn_Device, QChar(0xf0e8), 18);
        IconHelper::Instance()->setIcon(ui->btn_System, QChar(0xf085), 18);

    }else{
        //获取可用桌面大小
        QRect deskRect =  QApplication::desktop()->availableGeometry(this);
        this->resize(int(deskRect.width()*0.8),int(deskRect.height()*0.75));
        ui->widget->setVisible(false);
        //this->setWindowFlags(Qt::FramelessWindowHint);    // 设置窗口标志
    }
}

void MainWindow::NewClassItiem()
{
   loginItiem=new Login;
   ManagerInfoItem=new ManagerInfo;         //菜单管理
   dailyRecordItem=new dailyRecord;         //日志

   MainDesktopItem=new MainDesktop;           //主页

   managerServerI=new managerServer;          //设备管理
   threaddeviceServer=new QThread();
   managerServerI->moveToThread(threaddeviceServer);
   threaddeviceServer->start();

   systemServerI=new systemServer;          //系统管理
   threadsystemServer=new QThread();
   systemServerI->moveToThread(threadsystemServer);
   threadsystemServer->start();


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

   ui->stackedWidget->insertWidget(0,loginItiem);
   ui->stackedWidget->insertWidget(1,MainDesktopItem);     //主页
   ui->stackedWidget->insertWidget(2,dailyRecordItem);                      //日志界面
   ui->stackedWidget->insertWidget(3,ManagerInfoItem);                      //菜单管理
   ui->stackedWidget->insertWidget(4,managerServerI->DeviceManageItem);      //设备管理
   ui->stackedWidget->insertWidget(5,systemServerI->systemManageI);         //系统管理

   ui->stackedWidget->setCurrentIndex(0);
   ui->stackedWidget->widget(0)->layout()->setContentsMargins(0,0,0,0);
   ui->stackedWidget->widget(1)->layout()->setContentsMargins(0,0,0,0);

   WidgetInit(false);
   CreateConnect();

   Actionbtns<<ui->lab_Ico<<ui->btn_log<<ui->btn_Edite<<ui->btnMax<<ui->btn_Device<<ui->btn_System;
   for(int i=0;i<Actionbtns.length();i++){
       connect(Actionbtns[i],&QPushButton::pressed,this, &MainWindow::ON_Pressed);
       connect(Actionbtns[i],&QPushButton::released,this,&MainWindow::ON_Released);
   }

}

void MainWindow::CreateConnect()
{

   /******************** 系统登录页面 *******************/
   connect(loginItiem,&Login::UserLogin,this,&MainWindow::ON_UserLogin);

   /***************** 业务与系统任务状态逻辑部分 **********/
   connect(taskManagerServerI,&taskManagerServer::sigAGVMoveTask,agvCarPool1,&agvCarPool::onAGVMoveTask);
   connect(taskManagerServerI,&taskManagerServer::sigChargeTask,agvCarPool1,&agvCarPool::ON_AGVChargeTask);

   /*****************   主页显示部分 *******************/
   connect(MainDesktopItem->monitoringI,&monitoring::sigAGVMoveTask,agvCarPool1,&agvCarPool::onAGVMoveTask);
   connect(MainDesktopItem->monitoringI,&monitoring::newAGVMoveTask,taskManagerServerI,&taskManagerServer::ON_AGVMoveTask);

   connect(MainDesktopItem,&MainDesktop::sig_UPSAPExcelInfoTask,taskManagerServerI,&taskManagerServer::ON_UPSAPExcelInfoTask);
   connect(MainDesktopItem,&MainDesktop::sig_AGVCurrentTaskAction,taskManagerServerI,&taskManagerServer::ON_AGVCurrentTaskAction);

   connect(MainDesktopItem,&MainDesktop::sig_deleteSAPExcelInfoTask,taskManagerServerI,&taskManagerServer::ON_deleteSAPExcelInfoTask);

   /*****************   菜单管理部分 *******************/
   connect(ManagerInfoItem->StoreInfoItem,&StoreInfo::sig_SAPExcelInfo_new,taskManagerServerI,&taskManagerServer::ON_SAPExcelInfo_new);
   connect(ManagerInfoItem->StoreInfoItem,&StoreInfo::sig_containerCode_clear,taskManagerServerI,&taskManagerServer::ON_containerCode_clear);
   connect(ManagerInfoItem->StoreInfoItem->binwidgetItem,&binwidget::sig_taskCodes_WW,taskManagerServerI,&taskManagerServer::ON_taskCodes_WW);

   connect(ManagerInfoItem->taskmanagerItem,&taskManager::sig_deleteSAPExcelInfoTask,taskManagerServerI,&taskManagerServer::ON_deleteSAPExcelInfoTask);

   connect(taskManagerServerI,&taskManagerServer::sigLiftCodeMap,managerServerI->DeviceManageItem,&DeviceManage::ON_LiftCodeMap);
   connect(taskManagerServerI,&taskManagerServer::sigAGVCurrentTaskMap,MainDesktopItem,&MainDesktop::slotAGVCurrentTaskMap);

   /**************** AGV状态反馈以及显示  ***************/
   connect(agvCarPool1,&agvCarPool::AgvStateWidget,taskManagerServerI,&taskManagerServer::ON_AgvStateWidget);
   connect(agvCarPool1,&agvCarPool::AgvStateWidget,MainDesktopItem->monitoringI,&monitoring::ON_AgvStateWidget);

   /********************* 升降机部分 *******************/
   connect(managerServerI->DeviceManageItem,&DeviceManage::sig_LiftTaskStatus,taskManagerServerI,&taskManagerServer::ON_LiftTaskStatus);
   connect(managerServerI->DeviceManageItem,&DeviceManage::sig_LiftCodeStatus_clear,taskManagerServerI,&taskManagerServer::ON_LiftCodeStatus_clear);


   connect(taskManagerServerI,&taskManagerServer::sigsetLiftactionArray,managerServerI->DeviceManageItem,&DeviceManage::ON_setLiftactionArray);

   /******************** 接驳台部分 *******************/
   connect(taskManagerServerI,&taskManagerServer::sigDeviceStatus, managerServerI->DeviceManageItem->stationItemI,&stationItem::ON_DeviceStatus);
   connect(taskManagerServerI,&taskManagerServer::sigDeviceStatusAction,managerServerI->DeviceManageItem,&DeviceManage::ON_DeviceStatusAction);

}

void MainWindow::ON_UserLogin(QString UserNuber,QString UserName)
{
    WidgetInit(true);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_lab_Ico_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btn_log_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btn_Edite_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_btn_Device_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_btn_System_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::ON_Pressed()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    Instance::GetInstance()->SetButton_pressed(Button,"background-color: rgb(85,255,127);color:#ffffff;color: white;  border: 2px groove gray;\
                                               border-radius:15px;border-style: outset");
}

void MainWindow::ON_Released()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    Instance::GetInstance()->SetButton_released(Button,"color: white;border: 2px groove gray;border-radius:15px;border:none;background-color: rgb(71, 71, 71);");
}
