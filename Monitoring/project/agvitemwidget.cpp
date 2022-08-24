#include "agvitemwidget.h"
#include "ui_agvitemwidget.h"
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase)


AgvItemWidget::AgvItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgvItemWidget)
{
    ui->setupUi(this);
    AgvItemWidgetInit();
    ItemTimer = new QTimer(this);
    connect(ItemTimer,&QTimer::timeout,this,&AgvItemWidget::ON_ItemTimer);
    ItemTimer->start(800);

}

AgvItemWidget::~AgvItemWidget()
{
    delete ui;
}

void AgvItemWidget::AgvItemWidgetInit()
{
    this->setWindowTitle(QString("AGV—参数"));
    qRegisterMetaType<AGVCurrentTask>("AGVCurrentTask");

    agvStatus = new AgvStatus();

    Actionbtns<<ui->AgvExecute<<ui->CancelButton<<ui->task_sure<<ui->task_cancel
             <<ui->start_charge<<ui->close_charge;

    for(int i=0;i<Actionbtns.length();i++){
        connect(Actionbtns[i],&QPushButton::pressed,this,&AgvItemWidget::ON_Pressed);
        connect(Actionbtns[i],&QPushButton::released,this,&AgvItemWidget::ON_Released);
    }

    ui->stackedWidget->insertWidget(0,agvStatus);
    ui->stackedWidget->widget(0)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget->setCurrentIndex(0);
    IconHelper::Instance()->setIcon(ui->detail_Button, 0xf05a, 20);

}



QMap<QString, int> AgvItemWidget::getStation_ShowMap(QString floor,QString floor_)
{
    QMap<QString,int>StationPointMap;               //工作站名称 与 二维码绑定
    QMap<QString,int>::const_iterator iter=ServerInitItem.StationPointMap.begin();
    while (iter!=ServerInitItem.StationPointMap.end()) {
        if(iter!=nullptr){
            if(iter.key().left(2)==floor || iter.key().left(2)==floor_){
                StationPointMap.insert(iter.key(),iter.value());
            }
        }else{
            return StationPointMap;
        }
        ++iter;
    }
    return StationPointMap;
}

void AgvItemWidget::ON_ItemTimer()
{
    ItemTimercount++;
    if(ServerInitItem.AGVIPInitMap.isEmpty()){
        /************** 基础信息赋值 *******************/
        allServerInit ALLServerInitItem=queryServer::getInstance()->getCurrentServerInitItem();
        ServerInitItem=ALLServerInitItem.ServerInitItem;

        ServerInitItem.StationPointMap.insert("2F-L1",58);
        ServerInitItem.StationPointMap.insert("2F-L2",61);
        ServerInitItem.StationPointMap.insert("3F-L1",200);
        ServerInitItem.StationPointMap.insert("3F-L2",129);

        ui->taskStatusBox_AGV->addItems(ServerInitItem.AGVIPInitMap.keys());
        ui->taskstation_IP->addItems(ServerInitItem.AGVIPInitMap.keys());
        ui->StationDesc_s->addItems(ServerInitItem.StationPointMap.keys());
        ui->StationDesc_e->addItems(ServerInitItem.StationPointMap.keys());
    }

    if(ui->checkBox_Edite->isChecked() && ItemTimercount%20==0){
        on_task_sure_clicked();//创建AGV搬运任务
    }
    if(ItemTimercount>10000){
        ItemTimercount=0;
    }
}




//显示AGV 状态信息
void AgvItemWidget::on_detail_Button_clicked()
{

}


//提交AGV 单个动作指令
void AgvItemWidget::on_AgvExecute_clicked()
{
    int AGVAction=0;
    quint32 EndQRPoint=quint32(ui->taskEndQRPoint->text().trimmed().toInt());
    quint32 StartQRPoint=quint32(ui->taskSTQRPoint->text().trimmed().toInt());
    if(ui->taskActionBox_AGV->currentText().trimmed()=="移动指令"){
        AGVAction=1;
    }if(ui->taskActionBox_AGV->currentText().trimmed()=="举升指令"){
        AGVAction=3;
    }if(ui->taskActionBox_AGV->currentText().trimmed()=="下降指令"){
        AGVAction=4;
    }if(ui->taskActionBox_AGV->currentText().trimmed()=="开始充电"){
        AGVAction=10;
    }if(ui->taskActionBox_AGV->currentText().trimmed()=="结束充电"){
        AGVAction=11;
    }if(ui->taskActionBox_AGV->currentText().trimmed()=="初始化命令"){
        AGVAction=100;
    }if(ui->taskActionBox_AGV->currentText().trimmed()=="同步帧编码"){
        AGVAction=101;
    }

    agvORderTask agvORderTaskI;
    emit sigAGVMoveTask(ui->taskStatusBox_AGV->currentText().trimmed(),StartQRPoint, EndQRPoint,AGVAction,0,agvORderTaskI);

}

//取消AGV 单个动作指令
void AgvItemWidget::on_CancelButton_clicked()
{

}

//创建AGV搬运任务
void AgvItemWidget::on_task_sure_clicked()
{
    //创建 AGV 搬运任务
    AGVCurrentTask AGVCurrentTaskI;
    AGVCurrentTaskI.AGVIP=ui->taskstation_IP->currentText().trimmed();
    AGVCurrentTaskI.AGVType=0;       //AGV类型    0举升AGV  1滚筒AGV  2夹抱AGV
    if(ui->AGVType->currentText().trimmed()=="滚筒类型"){
        AGVCurrentTaskI.AGVType=1;
    }if(ui->AGVType->currentText().trimmed()=="夹抱类型"){
        AGVCurrentTaskI.AGVType=2;
    }
    AGVCurrentTaskI.destpoint=ui->taskstation_s->text().trimmed().toInt();
    AGVCurrentTaskI.Nextdestpoint=ui->taskstation_e->text().trimmed().toInt();

    if(ui->actionType->currentText().trimmed()=="是"){
        AGVCurrentTaskI.actionType=1;           //动作类型 0到达站点不需要返回  1到达站点倒计时结束后返回
        AGVCurrentTaskI.actionTimerCount=ui->waitTimer->text().trimmed().toInt();//倒计时 计数
    }
    //创建 AGV 搬运任务
    if(AGVCurrentTaskI.AGVIP!="" && AGVCurrentTaskI.destpoint>0 && AGVCurrentTaskI.Nextdestpoint>0
            && AGVCurrentTaskI.destpoint!=AGVCurrentTaskI.Nextdestpoint){
        emit newAGVMoveTask(AGVCurrentTaskI.AGVIP,"add",AGVCurrentTaskI);
        ui->masege->setText("手动创建AGV搬运任务--> "+QDateTime::currentDateTime().toString("hh::mm::ss"));
    }else {
        ui->masege->setText("无法创建AGV运输任务--> "+QDateTime::currentDateTime().toString("hh::mm::ss"));
    }

}

//取消AGV搬运任务
void AgvItemWidget::on_task_cancel_clicked()
{
    //创建 AGV 搬运任务
    AGVCurrentTask AGVCurrentTaskI;
    AGVCurrentTaskI.AGVIP=ui->taskstation_IP->currentText().trimmed();
    //创建 AGV 搬运任务
    if(AGVCurrentTaskI.AGVIP!=""){
        if(queryServer::getInstance()->SetMessagebox("是否取消当前小车运输任务")){
            emit newAGVMoveTask(AGVCurrentTaskI.AGVIP,"delete",AGVCurrentTaskI);
        }
    }
}

//手动开始充电任务
void AgvItemWidget::on_start_charge_clicked()
{
    if(queryServer::getInstance()->SetMessagebox("是否执行充电任务?")){
        AGVCurrentTask AGVCurrentTaskI;
        AGVCurrentTaskI.AGVIP=ui->taskstation_IP->currentText().trimmed();
        emit newAGVMoveTask(ui->taskStatusBox_AGV->currentText().trimmed(),"charge",AGVCurrentTaskI);
    }

}

//手动结束充电任务
void AgvItemWidget::on_close_charge_clicked()
{
    if(queryServer::getInstance()->SetMessagebox("是否取消充电任务?")){
        AGVCurrentTask AGVCurrentTaskI;
        AGVCurrentTaskI.AGVIP=ui->taskstation_IP->currentText().trimmed();
        emit newAGVMoveTask(ui->taskStatusBox_AGV->currentText().trimmed(),"charge_",AGVCurrentTaskI);
    }
}


void AgvItemWidget::ON_Pressed()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    if(Button->objectName()=="NextButton" || Button->objectName()=="LastButton"){
        Instance::GetInstance()->SetButton_pressed(Button,"background-color: rgb(85,255,127);color:#ffffff;");
    }else{
        Instance::GetInstance()->SetButton_pressed(Button,"background-color: rgb(85,255,127);color:#ffffff;color: white;  border: 2px groove gray;\
                                                   border-radius:15px;border-style: outset");
    }
}

void AgvItemWidget::ON_Released()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    Instance::GetInstance()->SetButton_released(Button,"color: white;border: 2px groove gray;border-radius:15px;border:none;background-color: rgb(0, 166, 172);");
    if(Button->objectName()=="detail_Button"){
        Instance::GetInstance()->SetButton_released(Button,"color: white;border: 2px groove gray;border-radius:15px;border:none;");
    }
}

void AgvItemWidget::on_station_statrt_currentTextChanged(const QString &arg1)
{
    ui->taskstation_s->setText(QString::number(ServerInitItem.StationPointMap.value(arg1)));
}

void AgvItemWidget::on_station_dest_currentTextChanged(const QString &arg1)
{
    ui->taskstation_e->setText(QString::number(ServerInitItem.StationPointMap.value(arg1)));
}

void AgvItemWidget::on_taskstation_IP_currentTextChanged(const QString &arg1)
{
    ui->station_statrt->clear();
    ui->station_dest->clear();
    if(arg1=="172.16.21.111"){
        ui->station_statrt->addItems(getStation_ShowMap("ST","2F").keys());
        ui->station_dest->addItems(getStation_ShowMap("ST","2F").keys());
    }else{
        ui->station_statrt->addItems(getStation_ShowMap("3F","3F").keys());
        ui->station_dest->addItems(getStation_ShowMap("3F","3F").keys());
    }
}

