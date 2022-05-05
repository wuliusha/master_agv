#include "managerinfo.h"
#include "ui_managerinfo.h"

ManagerInfo::ManagerInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerInfo)
{
    ui->setupUi(this);
    ManagerInfoInit();

    ManagerTimer = new QTimer(this);
    connect(ManagerTimer,&QTimer::timeout,this,&ManagerInfo::ON_ManagerTimer);
    ManagerTimer->start(800);

//  setAttribute(Qt::WA_TranslucentBackground, true);//1. 有边框黑色背景
//  setWindowFlags(Qt::FramelessWindowHint |Qt::WindowStaysOnTopHint); //2. 无边框白色背景（默认）

}

ManagerInfo::~ManagerInfo()
{
    delete ui;
}


void ManagerInfo::ON_ManagerTimer()
{
    ServerInitItem=queryServer::getInstance()->getCurrentServerInitItem();
    if(qdebug_logstop){
        QString logtext=log_single::GetInstance()->getqDebug_log();
        if(logtext!=""){ui->qdebug_log->append(logtext);}
    }

}

//出入库查询
void ManagerInfo::on_Qury_Button_clicked()
{

}

void ManagerInfo::on_Cancel_Button_clicked()
{

}

void ManagerInfo::ManagerInfoInit()
{
    threadQueryI=new threadQuery;
    threadQueryItem=new QThread();
    threadQueryI->moveToThread(threadQueryItem);
    threadQueryItem->start();

    wrexcelprocessItiem=new wrexcelprocess();
    wrexcelprocessItiem->hide();

    Network_WidgetItiem=new Network_Widget;
    Network_WidgetItiem->hide();
    ui->stackedWidget->insertWidget(2,Network_WidgetItiem);

    ui->Selete_DateEdit->setDateTime(QDateTime::fromString(QDateTime::currentDateTime().toString("yyyy-MM-dd")+" 00:00:00" ,"yyyy-MM-dd hh:mm:ss"));
    ui->Selete_DateEdit_2->setDateTime(QDateTime::fromString(QDateTime::currentDateTime().toString("yyyy-MM-dd")+" 23:59:00" ,"yyyy-MM-dd hh:mm:ss"));

    helperInfoItem.fontScale=0.65;
    helperInfoItem.sizeScale=0.50;
    helperInfoItem.listColorBg<<"#aa6666"<<"#aaaa66"<<"#5d9aa1";
    helperInfoItem.listColorBg1<<"#aa6666"<<"#aaaa66"<<"#5d9aa1";

    helperInfoItem.listColorText<<"#FEFEFE"<<"#FEFEFE"<<"#FEFEFE";
    helperInfoItem.listChar <<0xf03A<<0xf0ee<<0xf0e8;
    helperInfoItem.listText <<"日志界面"<<"任务记录"<<"接口测试";
    helperInfoItem.btns <<ui->logInfo_Button<<ui->Binchage_Button<<ui->Network_Button;
    button_single::GetInstance()->iconhelperinit(helperInfoItem);
    ui->Binchage_Button->setVisible(false);

    Actionbtns<<ui->Qury_Button<<ui->Cancel_Button<<ui->sureLead_Button<<ui->Cancel_Button_2
             <<ui->stop_Button<<ui->clear_Button;
    for(int i=0;i<Actionbtns.length();i++){
        connect(Actionbtns[i],&QPushButton::pressed,this,&ManagerInfo::ON_Pressed);
        connect(Actionbtns[i],&QPushButton::released,this,&ManagerInfo::ON_Released);
    }

    table_single::GetInstance()->TableWidgetInit(ui->tableWidget,12,"QHeaderView::section{background-color:rgb(211, 215, 212);font:12pt '宋体';color: black;};",30,30);
    connect(ui->tableWidget,&QTableWidget::cellClicked,this,&ManagerInfo::SlotsetCurrentItem);

    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->widget(0)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget->widget(1)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget->widget(2)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget_3->widget(0)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget_3->widget(1)->layout()->setContentsMargins(0,0,0,0);

}


void ManagerInfo::tableWidget_Show()
{
     //上架架位更新记录显示
//    Instance::GetInstance()->UP_TableWidget(ui->tableWidget,currentPostWS02MapShow());
//    if(currentPostWS02Map.isEmpty()){
//        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
//        return;
//    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(7, QHeaderView::ResizeToContents);

}


void ManagerInfo::SlotsetCurrentItem(int row, int column)
{
    if(ui->tableWidget ->item(row, column)->checkState() == Qt::Checked){
        slecetCurrentItem(ui->tableWidget->item(row,1)->text(), ui->tableWidget->item(row,2)->text(),1,row,column);
    }

    if(ui->tableWidget ->item(row, column)->checkState() != Qt::Checked){
         slecetCurrentItem(ui->tableWidget->item(row,1)->text(), ui->tableWidget->item(row,2)->text(),0,row,column);
    }
    tableWidget_Show();

}

void ManagerInfo::slecetCurrentItem(QString LabelNo, QString Material, int add, int row, int column)
{
    LabelNo=LabelNo.trimmed();
    Material=Material.trimmed();


    return;
}


void ManagerInfo::on_sureLead_Button_clicked(){

    if(!seletSAPExcelInfoTask.isEmpty()){

    }else {
         queryServer::getInstance()->SetMessagebox("当前导出任务列表为空，无法导出.");
    }

}

void ManagerInfo::on_Cancel_Button_2_clicked()
{
    boolPostWS02Map=false;
    tableWidget_Show();
}


void ManagerInfo::on_logInfo_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    button_single::GetInstance()->ButtonChageiconhelper(helperInfoItem,ui->logInfo_Button->text());
}

void ManagerInfo::on_Binchage_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    button_single::GetInstance()->ButtonChageiconhelper(helperInfoItem,ui->Binchage_Button->text());
}

void ManagerInfo::on_Network_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    button_single::GetInstance()->ButtonChageiconhelper(helperInfoItem,ui->Network_Button->text());
}

void ManagerInfo::on_stop_Button_clicked()
{
    if(qdebug_logstop){
        qdebug_logstop=false;
        ui->stop_Button->setText("暂停");
    }else{
        qdebug_logstop=true;
        ui->stop_Button->setText("启动");
    }
}

void ManagerInfo::on_clear_Button_clicked()
{
    ui->qdebug_log->clear();
}


void ManagerInfo::ON_Pressed()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    Instance::GetInstance()->SetButton_pressed(Button,"background-color: rgb(85,255,127);color:#ffffff;color: white;  border: 2px groove gray;\
                                               border-radius:15px;border-style: outset");
}

void ManagerInfo::ON_Released()
{
    QPushButton *Button = (QPushButton *)this->sender();
    Instance::GetInstance()->SetButton_released(Button,"color:#ffffff;color: white;  border: 2px groove gray;\
                                                border-radius:15px;border-style: outset");
}
