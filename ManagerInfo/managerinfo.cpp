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
    ManagerTimer->start(1200);
}

ManagerInfo::~ManagerInfo()
{
    delete ui;
}


void ManagerInfo::ON_ManagerTimer()
{
    if(ServerInitItem.UserInfoList.isEmpty()){
        /************** 基础信息赋值 *******************/
        allServerInit ALLServerInitItem=queryServer::getInstance()->getCurrentServerInitItem();
        ServerInitItem=ALLServerInitItem.ServerInitItem;
    }
}


void ManagerInfo::ManagerInfoInit()
{
    threadQueryI=new threadQuery;
    threadQueryItem=new QThread();
    threadQueryI->moveToThread(threadQueryItem);
    threadQueryItem->start();

    wrexcelprocessItiem=new wrexcelprocess();
    wrexcelprocessItiem->hide();

    taskmanagerItem=new taskManager;
    ui->tabWidget->insertTab(0,taskmanagerItem,"任务管理");

    StoreInfoItem=new StoreInfo;
    ui->tabWidget->insertTab(1,StoreInfoItem,"库存管理");

    ui->tabWidget->setCurrentIndex(0);

    QLabel *label = new QLabel;
    ui->tabWidget->setCornerWidget(label,Qt::TopRightCorner);
    label->setText("系统数据管理界面");

//    Actionbtns<<ui->stop_Button<<ui->clear_Button;
//    for(int i=0;i<Actionbtns.length();i++){
//        connect(Actionbtns[i],&QPushButton::pressed,this,&ManagerInfo::ON_Pressed);
//        connect(Actionbtns[i],&QPushButton::released,this,&ManagerInfo::ON_Released);
//    }


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
