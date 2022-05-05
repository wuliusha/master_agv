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
    wrexcelprocessItiem =new wrexcelprocess;

    //this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    Actionbtns<<ui->AgvExecute<<ui->CancelButton<<ui->task_sure<<ui->task_cancel
             <<ui->start_charge<<ui->close_charge
            <<ui->AlterButton<<ui->detail_Button<<ui->query_Button<<ui->updateButton
           <<ui->addButton<<ui->deleteButton<<ui->addButton_<<ui->deleteButton_
           <<ui->query_Button_2<<ui->addButton_Info<<ui->deleteButton_Info<<ui->updateButton_2
           <<ui->query_Button_3<<ui->addButton_Info_2<<ui->deleteButton_Info_2<<ui->updateButton_3
           <<ui->query_Button_4<<ui->addButton_Info_4<<ui->deleteButton_Info_4<<ui->updateButton_5
          <<ui->query_Button_agvip<<ui->addButton_agvip<<ui->deleteButton_agvip<<ui->updateButton_agvip;

    for(int i=0;i<Actionbtns.length();i++){
        connect(Actionbtns[i],&QPushButton::pressed,this,&AgvItemWidget::ON_Pressed);
        connect(Actionbtns[i],&QPushButton::released,this,&AgvItemWidget::ON_Released);
    }

    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->widget(0)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget->widget(1)->layout()->setContentsMargins(0,0,0,0);

    ui->stackedWidget_2->setCurrentIndex(0);
    ui->stackedWidget_2->widget(0)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget_2->widget(1)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget_2->widget(2)->layout()->setContentsMargins(0,0,0,0);

    ui->stackedWidget_3->setCurrentIndex(0);
    ui->stackedWidget_3->widget(0)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget_3->widget(1)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget_3->widget(2)->layout()->setContentsMargins(0,0,0,0);

    ui->stackedWidget_4->insertWidget(0,agvStatus);
    ui->stackedWidget_4->widget(0)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget_4->setCurrentIndex(0);

    IconHelper::Instance()->setIcon(ui->detail_Button, 0xf05a, 20);
    table_single::GetInstance()->TableWidgetInit(ui->tableWidget,12,"QHeaderView::section{background-color:rgb(193,205,205);font:12pt '宋体';color: black;};",35,35);
    table_single::GetInstance()->TableWidgetInit(ui->tableWidget_2,12,"QHeaderView::section{background-color:rgb(193,205,205);font:12pt '宋体';color: black;};",35,35);
    table_single::GetInstance()->TableWidgetInit(ui->tableWidget_3,12,"QHeaderView::section{background-color:rgb(193,205,205);font:12pt '宋体';color: black;};",35,35);
    table_single::GetInstance()->TableWidgetInit(ui->tableWidget_4,12,"QHeaderView::section{background-color:rgb(193,205,205);font:12pt '宋体';color: black;};",35,35);
    table_single::GetInstance()->TableWidgetInit(ui->tableWidget_5,12,"QHeaderView::section{background-color:rgb(193,205,205);font:12pt '宋体';color: black;};",35,35);


    connect(ui->tableWidget,&QTableWidget::cellClicked,this,&AgvItemWidget::SlotsetCurrentItem);        //路线规则
    connect(ui->tableWidget_2,&QTableWidget::cellClicked,this,&AgvItemWidget::SlotsetCurrentItem_2);    //路线信息
    connect(ui->tableWidget_3,&QTableWidget::cellClicked,this,&AgvItemWidget::SlotsetCurrentItem_3);    //站点绑定
    connect(ui->tableWidget_4,&QTableWidget::cellClicked,this,&AgvItemWidget::SlotsetCurrentItem_4);    //AGV参数配置
    connect(ui->tableWidget_5,&QTableWidget::cellClicked,this,&AgvItemWidget::SlotsetCurrentItem_5);    //自动门设置

    treeWidgetInit();

}

void AgvItemWidget::treeWidgetInit()
{
    ui->treeWidget->header()->hide();
    QTreeWidgetItemIterator itemList(ui->treeWidget);
//    while (*itemList) {
//        (*itemList)->setIcon(0, QIcon(":/image/appico.ico"));
//        ++itemList;
    //    }
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
        iter++;
    }
    return StationPointMap;
}

void AgvItemWidget::ON_ItemTimer()
{
    ItemTimercount++;
    if(ServerInitItem.AGVIPInitMap.isEmpty()){
        ServerInitItem=queryServer::getInstance()->getCurrentServerInitItem();
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

void AgvItemWidget::SlotsetCurrentItem(int row, int column)
{
    if(!currentAssistRouteI.mianRouteMap.isEmpty()){
        int TaskId=ui->tableWidget->item(row,2)->text().trimmed().toInt();
        QMap<QString, mianRoute>::iterator iter= currentAssistRouteI.mianRouteMap.begin();
        while (iter !=currentAssistRouteI.mianRouteMap.end()) {
            if(TaskId==iter.value().TaskId && iter.value().checked==0){
                iter.value().checked=1;
            }else {
                iter.value().checked=0;
            }
            iter++;
        }
        setAssistRouteI_show(currentAssistRouteI);                        //显示当前路线信息
    }

}

void AgvItemWidget::SlotsetCurrentItem_2(int row, int column)
{
    if(!agvSubTaskListinit.isEmpty()){
        int TaskId=ui->tableWidget_2->item(row,1)->text().trimmed().toInt();
        QMap<int,agvSubTask >::iterator iter= agvSubTaskListinit.begin();
        while (iter!=agvSubTaskListinit.end()) {
            if(iter.value().RouteName!=nullptr){
                if(TaskId==iter.value().TaskId && iter.value().checked==0){
                    iter.value().checked=1;
                }else {
                    iter.value().checked=0;
                }
            }else{
                return;
            }
            iter++;
        }
        if(column<2){
            TableWidget_show_2();
        }
    }
}

void AgvItemWidget::SlotsetCurrentItem_3(int row, int column)
{
    if(!Stationmap_Map.isEmpty()){
        QString StationName=ui->tableWidget_3->item(row,1)->text().trimmed();
        QMap<QString,Stationmap>::iterator iter= Stationmap_Map.begin();
        while (iter!=Stationmap_Map.end()) {
            if(iter.value().StationName!=nullptr){
                if(StationName==iter.value().StationName){
                    iter.value().checked=1;
                }else {
                    iter.value().checked=0;
                }
            }else{
                return;
            }
            iter++;
        }
        if(column<2){
            TableWidget_show_3();
        }
    }
}

//AGV参数配置
void AgvItemWidget::SlotsetCurrentItem_4(int row, int column)
{
    if(!AGVCurrentTaskMap.isEmpty()){
        QString AGVIP=ui->tableWidget_4->item(row,1)->text().trimmed();
        QMap<QString, AGVCurrentTask>::iterator iter= AGVCurrentTaskMap.begin();
        while (iter!=AGVCurrentTaskMap.end()) {
            if(iter.value().AGVIP!=nullptr){
                if(AGVIP==iter.value().AGVIP){
                    iter.value().checked=1;
                }else {
                    iter.value().checked=0;
                }
            }else{
                return;
            }
            iter++;
        }
        if(column<2){
            TableWidget_show_4();
        }
    }
}

//自动门设置
void AgvItemWidget::SlotsetCurrentItem_5(int row, int column)
{
    if(!doorSubTaskMap.isEmpty()){
        int doorId=ui->tableWidget_5->item(row,0)->text().trimmed().toInt();
        QMap<int,doorSubTask>::iterator iter= doorSubTaskMap.begin();
        while (iter!=doorSubTaskMap.end()) {
            if(iter.value().doorIP!=nullptr){
                if(doorId==iter.value().doorId){
                    iter.value().checked=1;
                }else {
                    iter.value().checked=0;
                }
            }else{
                return;
            }
            iter++;
        }
        if(column<2){
            TableWidget_show_5();
        }
    }
}

//显示AGV 状态信息
void AgvItemWidget::on_detail_Button_clicked()
{
    if(ui->stackedWidget_4->currentIndex()==0){
         ui->stackedWidget_4->setCurrentIndex(1);
    }else{
         ui->stackedWidget_4->setCurrentIndex(0);
    }
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
        AGVAction=1004;
    }if(ui->taskActionBox_AGV->currentText().trimmed()=="同步帧编码"){
        AGVAction=1020;
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


//根据路线编号 查找对应路线信息
void AgvItemWidget::on_query_Button_clicked()
{
    currentAssistRouteI=query_Single::GetInstance()->queryAssistRoute(ui->keyId->text().trimmed());
    setAssistRouteI_show(currentAssistRouteI);                 //显示当前路线信息
}

//创建路线编号
void AgvItemWidget::on_addButton_clicked()
{
    if(!ui->keyId->text().trimmed().isEmpty()){
        currentAssistRouteI=query_Single::GetInstance()->queryAssistRoute(ui->keyId->text().trimmed());
        if(currentAssistRouteI.keyId==""){                                          //不存在则创建
            assistRoute assistRouteI=getAssistRouteI_show();                        //创建路线信息
            if(assistRouteI.keyId!=""){
                query_Single::GetInstance()->assistRoute_Insert(assistRouteI);      //创建路线信息 写入数据库
                on_query_Button_clicked();                                          //根据路线编号 查找对应路线信息
            }
        }
    }else{
        queryServer::getInstance()->SetMessagebox("keyId 不能为空");
    }
    setAssistRouteI_show(currentAssistRouteI);                   //显示当前路线信息
}

//删除路线编号
void AgvItemWidget::on_deleteButton_clicked()
{
    currentAssistRouteI=query_Single::GetInstance()->queryAssistRoute(ui->keyId->text().trimmed());
    if(currentAssistRouteI.keyId!=""){
        if(queryServer::getInstance()->SetMessagebox("是否删除:"+currentAssistRouteI.keyId+"?")){
            query_Single::GetInstance()->assistRoute_Delete(currentAssistRouteI);                        //删除路线信息 删除数据库
            if(!currentAssistRouteI.mianRouteMap.isEmpty()){
                query_Single::GetInstance()->mianRouteMap_Delete(currentAssistRouteI.keyId);             //删除途经路线信息
            }
            currentAssistRouteI=query_Single::GetInstance()->queryAssistRoute(ui->keyId->text().trimmed());
        }
    }
    setAssistRouteI_show(currentAssistRouteI);                          //显示当前路线信息
}

//添加路线编号 ---途经的子路线信息
void AgvItemWidget::on_addButton__clicked()
{
    if(currentAssistRouteI.keyId!=""){
        mianRoute mianRouteI=getmianRoute_show();//创建途经路线信息
        if(currentMianRoute.TaskId==0){
            mianRouteI.TaskId=++currentAssistRouteI.TaskId;
        }else{
            mianRouteI.TaskId=++currentMianRoute.TaskId;
        }

        if(!currentAssistRouteI.mianRouteMap.isEmpty()){
            QMap<QString,mianRoute>::iterator iter=currentAssistRouteI.mianRouteMap.begin();
            while (iter!=currentAssistRouteI.mianRouteMap.end()) {
                if(iter.value().TaskId>mianRouteI.TaskId){
                    iter.value().TaskId++;
                }
                iter++;
            }
        }

        if(mianRouteI.keyId!="" && !currentAssistRouteI.mianRouteMap.contains(mianRouteI.RouteName)){
            currentAssistRouteI.mianRouteMap.insert(mianRouteI.RouteName,mianRouteI);
        }
        setAssistRouteI_show(currentAssistRouteI);                   //显示当前路线信息
    }
}

//删除路线编号 ---途经的子路线信息
void AgvItemWidget::on_deleteButton__clicked()
{
    if(!currentAssistRouteI.mianRouteMap.isEmpty() && currentMianRoute.TaskId!=0){
        QMap<QString,mianRoute>::iterator iter=currentAssistRouteI.mianRouteMap.begin();
        while (iter!=currentAssistRouteI.mianRouteMap.end()) {
            if(iter.value().TaskId==currentMianRoute.TaskId){
                currentAssistRouteI.mianRouteMap.remove(currentMianRoute.RouteName);
                if(currentAssistRouteI.mianRouteMap.isEmpty()){
                    setAssistRouteI_show(currentAssistRouteI);                   //显示当前路线信息
                    return;
                }
            }
            iter++;
        }

        if(!currentAssistRouteI.mianRouteMap.isEmpty()){
            QMap<QString,mianRoute>::iterator iter=currentAssistRouteI.mianRouteMap.begin();
            while (iter!=currentAssistRouteI.mianRouteMap.end()) {
                if(iter.value().TaskId>currentMianRoute.TaskId){
                    iter.value().TaskId--;
                }
                iter++;
            }
        }
        setAssistRouteI_show(currentAssistRouteI);                   //显示当前路线信息
    }

}

//把路线编号信息提交到数据库
void AgvItemWidget::on_updateButton_clicked()
{
    if(currentAssistRouteI.keyId!=""){
        if(!currentAssistRouteI.mianRouteMap.isEmpty()){
            query_Single::GetInstance()->mianRouteMap_Delete(currentAssistRouteI.keyId);            //删除途经路线信息
            query_Single::GetInstance()->mianRouteMap_Insert(currentAssistRouteI.mianRouteMap);     //创建路线的途经路线 信息 写入数据库
        }
        on_query_Button_clicked();                                                                  //根据路线编号 查找对应路线信息
    }
}

//导入路线二维码信息
void AgvItemWidget::on_AlterButton_clicked()
{
    QMap<int,agvSubTask > agvSubTaskListinit_;
    QMap<int,agvSubTask > agvSubTaskListinit_0;
    QMap<QString,agvSubTask > agvSubTaskListinit=wrexcelprocessItiem->ON_read_movepointmap();//读取路径信息
    if(!agvSubTaskListinit.isEmpty()){
        bool UPShelfbool=queryServer::getInstance()->SetMessagebox("是否导入当前信息？");
        if(UPShelfbool){
            QMap<QString ,agvSubTask >::const_iterator iter=agvSubTaskListinit.begin();
            while (iter!=agvSubTaskListinit.end()) {
                if(iter!=nullptr){
                    if(iter.value().SubTaskType==0){
                        agvSubTaskListinit_.insert(iter.value().TaskId,iter.value());
                    }if(iter.value().SubTaskType==-1){
                        agvSubTaskListinit_0.insert(iter.value().TaskId,iter.value());
                    }
                }else{
                    return;
                }
                iter++;
            }
            query_Single::GetInstance()->SubTaskListinit_insert(agvSubTaskListinit_);
            query_Single::GetInstance()->SubTaskListinit_insert(agvSubTaskListinit_0);
        }
        agvSubTaskListinit.clear();
    }
}


//查询路线二维码信息
void AgvItemWidget::on_query_Button_2_clicked()
{
    if(!ui->currentLine->text().trimmed().isNull()){
        int SubTaskType=0;
        QString RouteName=ui->currentLine->text().trimmed();
        if(ui->lineType->currentText().trimmed()=="反向"){SubTaskType=-1;}
        agvSubTaskListinit=query_Single::GetInstance()->query_agvSubTaskListinit(RouteName,SubTaskType);
        TableWidget_show_2();
    }

}

//添加路线二维码信息
void AgvItemWidget::on_addButton_Info_clicked()
{
    if(currentAgvSubTask.RouteName!=""){
        QMap<int,agvSubTask> agvSubTaskListinit_;
        QMap<int,agvSubTask>::iterator iter=agvSubTaskListinit.begin();
        while (iter!=agvSubTaskListinit.end()) {
            iter.value().checked=0;
            if(iter.value().TaskId>currentAgvSubTask.TaskId){
                iter.value().Id++;
                iter.value().TaskId++;
            }
            agvSubTaskListinit_.insert(iter.value().TaskId,iter.value());
            iter++;
        }
        agvSubTaskListinit=agvSubTaskListinit_;
        currentAgvSubTask.TaskId++;
        agvSubTaskListinit.insert(currentAgvSubTask.TaskId,currentAgvSubTask);
        TableWidget_show_2();
    }
}

//删除路线二维码信息
void AgvItemWidget::on_deleteButton_Info_clicked()
{
    if(!agvSubTaskListinit.isEmpty() && currentAgvSubTask.TaskId!=0){
        if(!agvSubTaskListinit.isEmpty()){
            QMap<int,agvSubTask> agvSubTaskListinit_;
            QMap<int,agvSubTask>::iterator iter=agvSubTaskListinit.begin();
            while (iter!=agvSubTaskListinit.end()) {
                iter.value().checked=0;
                if(iter.value().TaskId!=currentAgvSubTask.TaskId){
                    if(iter.value().TaskId>currentAgvSubTask.TaskId){
                        iter.value().TaskId--;
                    }
                    agvSubTaskListinit_.insert(iter.value().TaskId,iter.value());
                }
                iter++;
            }
            agvSubTaskListinit=agvSubTaskListinit_;
        }
        TableWidget_show_2();
    }
}

//把路线二维码信息提交到数据库
void AgvItemWidget::on_updateButton_2_clicked()
{
    if(!ui->currentLine->text().trimmed().isNull()){
       qDebug()<<currentAgvSubTask.TaskId<<currentAgvSubTask.row<<currentAgvSubTask.RouteName;
        if(currentAgvSubTask.TaskId>0){
            int TaskId =currentAgvSubTask.TaskId-1;

            currentAgvSubTask.Point=quint8(ui->tableWidget_2->item(TaskId,2)->text().trimmed().toInt());                            //AGV基本任务 起始点
            currentAgvSubTask.NextPoint=quint8(ui->tableWidget_2->item(TaskId,3)->text().trimmed().toInt());                        //AGV基本任务 下一点
            currentAgvSubTask.NextPointDistance=quint8(ui->tableWidget_2->item(TaskId,4)->text().trimmed().toInt());                //AGV基本任务 下一点距离
            currentAgvSubTask.AGVSpeed=quint8(ui->tableWidget_2->item(TaskId,5)->text().trimmed().toInt());                         //AGV基本任务 速度
            currentAgvSubTask.RotaryLowBarrierInstruction=quint8(ui->tableWidget_2->item(TaskId,6)->text().trimmed().toInt());      //AGV基本任务 顶盘降下时 激光方案（无货架）
            currentAgvSubTask.RotaryHighBarrierInstruction=quint8(ui->tableWidget_2->item(TaskId,7)->text().trimmed().toInt());     //AGV基本任务 顶盘举升时 激光方案（有货架）
            currentAgvSubTask.postureAngle=quint8(ui->tableWidget_2->item(TaskId,8)->text().trimmed().toInt());                     //AGV基本任务 姿态角度
            currentAgvSubTask.AGVMoveAnage=quint8(ui->tableWidget_2->item(TaskId,9)->text().trimmed().toInt());                     //AGV基本任务 移动角度
            currentAgvSubTask.AGVRotaryAngle=quint8(ui->tableWidget_2->item(TaskId,10)->text().trimmed().toInt());                  //AGV基本任务 转盘角度
            currentAgvSubTask.SubTaskType =ui->tableWidget_2->item(TaskId,11)->text().trimmed().toInt();                            //AGV基本任务 基本任务类型  0正向  -1反向

            agvSubTaskListinit.insert(currentAgvSubTask.TaskId,currentAgvSubTask);
        }

        int SubTaskType=0;
        QString RouteName=ui->currentLine->text().trimmed();
        if(ui->lineType->currentText().trimmed()=="反向"){SubTaskType=-1;}
        query_Single::GetInstance()->agvSubTask_Delete(RouteName,SubTaskType);              //删除路线信息
        query_Single::GetInstance()->SubTaskListinit_insert(agvSubTaskListinit);            //更新路线 信息 写入数据库

        on_query_Button_2_clicked();
    }
}



/************   站点绑定界面   ***************/

//查询站点绑定信息
void AgvItemWidget::on_query_Button_3_clicked()
{
    QString StationName=ui->StationName->text().trimmed();
    Stationmap_Map=query_Single::GetInstance()->query_Stationmap(StationName);
    TableWidget_show_3();
}

//添加站点信息
void AgvItemWidget::on_addButton_Info_2_clicked()
{
    if(ui->StationName->text()!=""){
        Stationmap StationmapI;
        QMap<QString,Stationmap >Stationmap_Map;
        StationmapI.StationName=ui->StationName->text().trimmed();
        Stationmap_Map.insert(currentStationmap.StationName,StationmapI);
        query_Single::GetInstance()->Stationmap_insert(Stationmap_Map);    //添加 站点路线信息 到数据库
        on_query_Button_3_clicked();//查询站点绑定信息
        ui->StationName->setText("");
    }else{

    }
}

//删除站点信息
void AgvItemWidget::on_deleteButton_Info_2_clicked()
{
    if(!Stationmap_Map.isEmpty()){
        if(currentStationmap.StationName!=""){
            query_Single::GetInstance()->Stationmap_Delete(currentStationmap.StationName); //删除 站点路线信息
            on_query_Button_3_clicked();//查询站点绑定信息
        }
    }
}

//更新站点信息到数据库
void AgvItemWidget::on_updateButton_3_clicked()
{
    if(!Stationmap_Map.isEmpty()){
        if(currentStationmap.StationName==ui->tableWidget_3->item(currentStationmap.row,1)->text().trimmed()){
            currentStationmap.StationPoint=ui->tableWidget_3->item(currentStationmap.row,2)->text().trimmed().toInt();                  //工位二维码
            currentStationmap.StartPoint = ui->tableWidget_3->item(currentStationmap.row,3)->text().trimmed().toInt();                    // StationPoint==StartPoint  出去  StationPoint！=StartPoint  进工位
            currentStationmap.PassPoint = ui->tableWidget_3->item(currentStationmap.row,4)->text().trimmed().toInt();                     //经过二维码 0
            currentStationmap.PassPoint1 = ui->tableWidget_3->item(currentStationmap.row,5)->text().trimmed().toInt();                    //经过二维码 1
            currentStationmap.PassPoint2 = ui->tableWidget_3->item(currentStationmap.row,6)->text().trimmed().toInt();                    //经过二维码 2
            currentStationmap.PassPoint3 = ui->tableWidget_3->item(currentStationmap.row,7)->text().trimmed().toInt();                    //经过二维码 3
            currentStationmap.assistPoint = ui->tableWidget_3->item(currentStationmap.row,8)->text().trimmed().toInt();                   //辅路线  对接点
            currentStationmap.assistRoute=ui->tableWidget_3->item(currentStationmap.row,9)->text().trimmed();                //与工位连接的辅路线
            currentStationmap.SubTaskType = ui->tableWidget_3->item(currentStationmap.row,10)->text().trimmed().toInt();                   //AGV基本任务 基本任务类型  0正向  -1反向
            QMap<QString,Stationmap> Stationmap_Map;
            Stationmap_Map.insert(currentStationmap.StationName,currentStationmap);
            query_Single::GetInstance()->Stationmap_update(Stationmap_Map);    //更新 站点路线信息
        }
        on_query_Button_3_clicked();//查询站点绑定信息
    }
}


/************   自动门配置界面   ***************/

//查询自动门信息
void AgvItemWidget::on_query_Button_4_clicked()
{
    QString doorIP=ui->doorIP->text().trimmed();
    doorSubTaskMap=query_Single::GetInstance()->query_doorSubTaskMap(doorIP,0);//查找当前自动门信息
    TableWidget_show_5();
}

//添加自动门
void AgvItemWidget::on_addButton_Info_4_clicked()
{
    if(ui->doorIP->text().trimmed()!=""){
        doorSubTask doorSubTask_;
        doorSubTask_.doorIP=ui->doorIP->text().trimmed();
        if(doorSubTask_.doorIP!=""){
            QMap<int,doorSubTask>doorSubTaskMap;
            doorSubTaskMap.insert(doorSubTask_.doorId,doorSubTask_);
            query_Single::GetInstance()->doorSubTaskMap_insert(doorSubTaskMap);    //添加 自动门信息 到数据库
            ui->doorIP->setText("");
            on_query_Button_4_clicked();//查询自动门信息
        }else{

        }
    }
}

//删除自动门
void AgvItemWidget::on_deleteButton_Info_4_clicked()
{
    if(!doorSubTaskMap.isEmpty()){
        if(doorSubTaskI.doorIP!="" && doorSubTaskI.doorId>0){
            query_Single::GetInstance()->doorSubTask_Delete(doorSubTaskI.doorId); //删除 站点路线信息
            on_query_Button_4_clicked();        //查询自动门信息
        }
    }
}

//提交更新自动门
void AgvItemWidget::on_updateButton_5_clicked()
{
    if(!doorSubTaskMap.isEmpty() && doorSubTaskI.doorIP!=""){
        int doorId=ui->tableWidget_5->item(doorSubTaskI.row,0)->text().trimmed().toInt();
        if(doorSubTaskI.doorIP!="" && doorSubTaskI.doorId==doorId){
            doorSubTaskI.doorDesc=ui->tableWidget_5->item(doorSubTaskI.row,2)->text().trimmed();
            doorSubTaskI.Point=ui->tableWidget_5->item(doorSubTaskI.row,3)->text().trimmed().toInt();
            doorSubTaskI.NextPoint=ui->tableWidget_5->item(doorSubTaskI.row,4)->text().trimmed().toInt();
            doorSubTaskI.NextPointdesc=ui->tableWidget_5->item(doorSubTaskI.row,5)->text().trimmed();
            doorSubTaskI.enable=ui->tableWidget_5->item(doorSubTaskI.row,9)->text().trimmed().toInt();
            doorSubTaskI.page=ui->tableWidget_5->item(doorSubTaskI.row,10)->text().trimmed().toInt();

            QMap<int,doorSubTask>doorSubTaskMap_;
            doorSubTaskMap_.insert(doorSubTaskI.doorId,doorSubTaskI);
            query_Single::GetInstance()->doorSubTask_update(doorSubTaskMap_);       //更新 自动门信息
            on_query_Button_4_clicked(); //查找当前自动门信息
        }
    }
}


/************   AGV小车参数配置界面   ***************/

//查询AGV小车信息
void AgvItemWidget::on_query_Button_agvip_clicked()
{
    QString AGVIP=ui->AGVIP->text().trimmed();
    AGVCurrentTaskMap=query_Single::GetInstance()->query_AGVCurrentTask(AGVIP);//查找当前AGV信息
    TableWidget_show_4();
}

//添加AGV小车信息
void AgvItemWidget::on_addButton_agvip_clicked()
{
    if(ui->AGVIP->text().trimmed()!=""){
        AGVCurrentTask AGVCurrentTaskI;
        AGVCurrentTaskI.AGVIP=ui->AGVIP->text().trimmed();
        AGVCurrentTaskI.AGVId=AGVCurrentTaskI.AGVIP.right(2).toInt();
        if(AGVCurrentTaskI.AGVIP!=""){
            QMap<QString, AGVCurrentTask> AGVCurrentTaskMap_;
            AGVCurrentTaskMap_.insert(AGVCurrentTaskI.AGVIP,AGVCurrentTaskI);
            query_Single::GetInstance()->AGVCurrentTask_insert(AGVCurrentTaskMap_);    //添加 AGV信息 到数据库
            ui->AGVIP->setText("");
            on_query_Button_agvip_clicked();//查询AGV小车信息
        }else{

        }
    }


}

//删除AGV小车信息
void AgvItemWidget::on_deleteButton_agvip_clicked()
{
    if(!AGVCurrentTaskMap.isEmpty()){
        if(AGVCurrentTaskI.AGVIP!=""){
            query_Single::GetInstance()->AGVCurrentTask_Delete(AGVCurrentTaskI.AGVIP); //删除 AGV信息
            on_query_Button_agvip_clicked();//查询AGV小车信息
        }
    }
}

//更新AGV小车信息
void AgvItemWidget::on_updateButton_agvip_clicked()
{
    if(!AGVCurrentTaskMap.isEmpty()){
        if(AGVCurrentTaskI.AGVIP!=""){
            AGVCurrentTaskI.AGVId=ui->tableWidget_4->item(AGVCurrentTaskI.row,0)->text().trimmed().toInt();
            AGVCurrentTaskI.enable=ui->tableWidget_4->item(AGVCurrentTaskI.row,2)->text().trimmed().toInt();
            AGVCurrentTaskI.AGVType=ui->tableWidget_4->item(AGVCurrentTaskI.row,3)->text().trimmed().toInt();
            AGVCurrentTaskI.floornum=ui->tableWidget_4->item(AGVCurrentTaskI.row,4)->text().trimmed().toInt();
            AGVCurrentTaskI.waitPoint=ui->tableWidget_4->item(AGVCurrentTaskI.row,5)->text().trimmed().toInt();
            AGVCurrentTaskI.chargeIP=ui->tableWidget_4->item(AGVCurrentTaskI.row,6)->text().trimmed();
            AGVCurrentTaskI.ChargePoint=ui->tableWidget_4->item(AGVCurrentTaskI.row,7)->text().trimmed().toInt();
            AGVCurrentTaskI.ChargeWait=ui->tableWidget_4->item(AGVCurrentTaskI.row,8)->text().trimmed().toInt();
            AGVCurrentTaskI.MoveAnage=ui->tableWidget_4->item(AGVCurrentTaskI.row,9)->text().trimmed().toInt();

            QMap<QString, AGVCurrentTask> AGVCurrentTaskMap_;
            AGVCurrentTaskMap_.insert(AGVCurrentTaskI.AGVIP,AGVCurrentTaskI);
            query_Single::GetInstance()->AGVCurrentTask_update(AGVCurrentTaskMap_); //更新 AGV信息
            on_query_Button_agvip_clicked();//查询AGV小车信息
        }

    }
}



//显示当前路线信息
void AgvItemWidget::setAssistRouteI_show(assistRoute assistRouteI)
{
    ui->keyId->setText(assistRouteI.keyId);
    ui->assistRoute_S->setText(assistRouteI.assistRoute_S);
    ui->assistPoint_S->setText(QString::number(assistRouteI.assistPoint_S));
    ui->assistRoute_E->setText(assistRouteI.assistRoute_E);
    ui->assistPoint_E->setText(QString::number(assistRouteI.assistPoint_E));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    QList<RW_Excel> ExcelList=TableWidget(assistRouteI.mianRouteMap);
    QStringList comBoxlist;
    table_single::GetInstance()->UP_TableWidget(ui->tableWidget,ExcelList,comBoxlist,0);
    if(ExcelList.isEmpty()){
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
        return;
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);

}

assistRoute AgvItemWidget::getAssistRouteI_show()
{
    assistRoute assistRouteI;
    assistRouteI.keyId=ui->keyId->text().trimmed();                             //路线编号
    assistRouteI.assistRoute_S=ui->assistRoute_S->text().trimmed();             //起始路线
    assistRouteI.assistPoint_S=ui->assistPoint_S->text().trimmed().toInt();     //起始路线 离开点
    assistRouteI.assistRoute_E=ui->assistRoute_E->text().trimmed();             //目标路线
    assistRouteI.assistPoint_E=ui->assistPoint_E->text().trimmed().toInt();     //目标路线  进入点
    if(assistRouteI.keyId=="" || assistRouteI.assistRoute_S=="" || assistRouteI.assistPoint_S==0
            || assistRouteI.assistRoute_E=="" || assistRouteI.assistPoint_E==0){
       queryServer::getInstance()->SetMessagebox("关键项为空,无法创建");
       assistRouteI.keyId="";
    }

    return assistRouteI;
}

mianRoute AgvItemWidget::getmianRoute_show()
{
    mianRoute mianRouteI;
    mianRouteI.keyId=ui->keyId->text().trimmed();                       //路线编号
    //mianRouteI.TaskId=ui->TaskId->text().trimmed().toInt();           //路径内序号  按照从小到大 执行
    mianRouteI.Point_S = ui->Point_S->text().trimmed().toInt();         //起始二维码
    mianRouteI.RouteName=ui->RouteName->text().trimmed();               //路线名称
    mianRouteI.Point_E = ui->Point_E->text().trimmed().toInt();         //离开二维码
    mianRouteI.SubTaskType = ui->SubTaskType->text().trimmed().toInt(); //AGV基本任务 基本任务类型  0正向  -1反向

    if(mianRouteI.keyId=="" || mianRouteI.Point_S==0 || mianRouteI.RouteName=="" || mianRouteI.Point_E==0){
       queryServer::getInstance()->SetMessagebox("关键项为空,无法创建");
       mianRouteI.keyId="";
    }
    return  mianRouteI;
}

QList<RW_Excel> AgvItemWidget::TableWidget(QMap<QString, mianRoute> mianRouteMap)
{
    mianRoute mianRouteI;
    currentMianRoute=mianRouteI;
    QList<RW_Excel> ExcelList;
    QMap<QString, mianRoute>::const_iterator iter= mianRouteMap.begin();
    while (iter!=mianRouteMap.end()) {
        int incount=0;
        RW_Excel RW_ExcelItem;
        RW_ExcelItem.ExcelA=QString::number(ExcelList.size()+1);
        RW_ExcelItem.ExcelB=iter.value().keyId;                         //路线编号
        RW_ExcelItem.ExcelC=QString::number(iter.value().TaskId);       //路径内序号  按照从小到大 执行
        RW_ExcelItem.ExcelD=QString::number(iter.value().Point_S);      //起始二维码
        RW_ExcelItem.ExcelE=iter.value().RouteName;                     //路线名称
        RW_ExcelItem.ExcelF=QString::number(iter.value().Point_E);      //离开二维码
        RW_ExcelItem.ExcelG=QString::number(iter.value().SubTaskType);  //0正向  -1反向

        RW_ExcelItem.checked=iter.value().checked;
        if(iter.value().checked==1){
            currentMianRoute=iter.value();
            currentMianRoute.row=ExcelList.size();
        }
        if(incount==0){
            incount=1;
            RW_ExcelItem.corlor=0;       // 0
            ExcelList.append(RW_ExcelItem);
        }
        iter++;
    }
    return ExcelList;
}

void AgvItemWidget::TableWidget_show_2()
{
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    QList<RW_Excel> ExcelList=TableWidget_2(agvSubTaskListinit);
    QStringList comBoxlist;
    table_single::GetInstance()->UP_TableWidget(ui->tableWidget_2,ExcelList,comBoxlist,0);
    if(ExcelList.isEmpty()){
        ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
        return;
    }
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
    //ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);

}

QList<RW_Excel> AgvItemWidget::TableWidget_2(QMap<int, agvSubTask> SubTaskListinit)
{
    agvSubTask AgvSubTaskI;
    currentAgvSubTask=AgvSubTaskI;
    QList<RW_Excel> ExcelList;
    QMap<int, QString>TaskIdMap;
    for (int i=0;i<=SubTaskListinit.size();i++) {
        agvSubTask AgvSubTaskI;
        QMap<int,agvSubTask>::const_iterator iter= SubTaskListinit.begin();
        while (iter!=SubTaskListinit.end()) {
            if(!TaskIdMap.contains(iter.value().TaskId)){
                if(AgvSubTaskI.TaskId==0){
                    AgvSubTaskI=iter.value();
                }if(AgvSubTaskI.TaskId>iter.value().TaskId){
                    AgvSubTaskI=iter.value();
                }
            }
            iter++;
        }

        if(AgvSubTaskI.TaskId>0){
            int incount=0;
            RW_Excel RW_ExcelItem;
            RW_ExcelItem.ExcelA=AgvSubTaskI.RouteName;                                             //路线名
            RW_ExcelItem.ExcelB=QString::number(AgvSubTaskI.TaskId);                               //路径内序号
            RW_ExcelItem.ExcelC=QString::number(AgvSubTaskI.Point);                                //AGV基本任务 起始点
            RW_ExcelItem.ExcelD=QString::number(AgvSubTaskI.NextPoint);                            //AGV基本任务 下一点
            RW_ExcelItem.ExcelE=QString::number(AgvSubTaskI.NextPointDistance);                    //AGV基本任务 下一点距离
            RW_ExcelItem.ExcelF=QString::number(AgvSubTaskI.AGVSpeed);                             //AGV基本任务 速度
            RW_ExcelItem.ExcelG=QString::number(AgvSubTaskI.RotaryLowBarrierInstruction);          //AGV基本任务 顶盘降下时 激光方案（无货架）
            RW_ExcelItem.ExcelH=QString::number(AgvSubTaskI.RotaryHighBarrierInstruction);         //AGV基本任务 顶盘举升时 激光方案（有货架）
            RW_ExcelItem.ExcelI=QString::number(AgvSubTaskI.postureAngle);                         //AGV基本任务 姿态角度
            RW_ExcelItem.ExcelJ=QString::number(AgvSubTaskI.AGVMoveAnage);                         //AGV基本任务 移动角度
            RW_ExcelItem.ExcelK=QString::number(AgvSubTaskI.AGVRotaryAngle);                       //AGV基本任务 转盘角度
            RW_ExcelItem.ExcelL=QString::number(AgvSubTaskI.SubTaskType);                          //AGV基本任务 基本任务类型  0正向  -1反向
            RW_ExcelItem.checked=AgvSubTaskI.checked;
            if(AgvSubTaskI.checked==1){
                currentAgvSubTask=AgvSubTaskI;
                currentAgvSubTask.row=ExcelList.size();
            }
            if(incount==0){
                incount=1;
                RW_ExcelItem.corlor=0;       // 0
                ExcelList.append(RW_ExcelItem);
                TaskIdMap.insert(AgvSubTaskI.TaskId,AgvSubTaskI.RouteName);
            }
        }

    }

    return ExcelList;
}

void AgvItemWidget::TableWidget_show_3()
{
    ui->tableWidget_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    QList<RW_Excel> ExcelList=TableWidget_3(Stationmap_Map);
    QStringList comBoxlist;//comBoxlist<<"0"<<"-1";
    table_single::GetInstance()->UP_TableWidget(ui->tableWidget_3,ExcelList,comBoxlist,0);
    if(ExcelList.isEmpty()){
        ui->tableWidget_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
        return;
    }
    ui->tableWidget_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
    //ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);

}

QList<RW_Excel> AgvItemWidget::TableWidget_3(QMap<QString, Stationmap> Stationmap_)
{

    QList<RW_Excel> ExcelList;
    Stationmap StationmapI;
    currentStationmap=StationmapI;
    QMap<QString, Stationmap>::const_iterator iter= Stationmap_.begin();
    while (iter!=Stationmap_.end()) {
        int incount=0;
        RW_Excel RW_ExcelItem;
        RW_ExcelItem.ExcelA=QString::number(ExcelList.size()+1);
        RW_ExcelItem.ExcelB=iter.value().StationName;                   //工位名称
        RW_ExcelItem.ExcelC=QString::number(iter.value().StationPoint); //工位二维码
        RW_ExcelItem.ExcelD=QString::number(iter.value().StartPoint);   // StationPoint==StartPoint  出去  StationPoint！=StartPoint  进工位
        RW_ExcelItem.ExcelE=QString::number(iter.value().PassPoint);    //经过二维码 0
        RW_ExcelItem.ExcelF=QString::number(iter.value().PassPoint1);   //经过二维码 1
        RW_ExcelItem.ExcelG=QString::number(iter.value().PassPoint2);   //经过二维码 2
        RW_ExcelItem.ExcelH=QString::number(iter.value().PassPoint3);   //经过二维码 3
        RW_ExcelItem.ExcelI=QString::number(iter.value().assistPoint);  //辅路线  对接点
        RW_ExcelItem.ExcelJ=iter.value().assistRoute;                   //与工位连接的辅路线
        RW_ExcelItem.ExcelK=QString::number(iter.value().SubTaskType); //AGV基本任务 基本任务类型  0正向  -1反向

        RW_ExcelItem.checked=iter.value().checked;
        if(iter.value().checked==1){
            currentStationmap=iter.value();
            currentStationmap.row=ExcelList.size();
        }
        if(incount==0){
            incount=1;
            RW_ExcelItem.corlor=0;       // 0
            ExcelList.append(RW_ExcelItem);
        }
        iter++;
    }

    return ExcelList;
}

void AgvItemWidget::TableWidget_show_5()
{
    ui->tableWidget_5->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    QList<RW_Excel> ExcelList=TableWidget_5(doorSubTaskMap);
    QStringList comBoxlist;//comBoxlist<<"0"<<"-1";
    table_single::GetInstance()->UP_TableWidget(ui->tableWidget_5,ExcelList,comBoxlist,0);
    if(ExcelList.isEmpty()){
        ui->tableWidget_5->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
        return;
    }
    ui->tableWidget_5->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
    ui->tableWidget_5->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    ui->tableWidget_5->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->tableWidget_5->horizontalHeader()->setSectionResizeMode(5,QHeaderView::ResizeToContents);

}

QList<RW_Excel> AgvItemWidget::TableWidget_5(QMap<int, doorSubTask> doorSubTaskMap_)
{
    QList<RW_Excel> ExcelList;
    doorSubTask doorSubTask_;
    doorSubTaskI=doorSubTask_;
    QMap<int, doorSubTask>::const_iterator iter= doorSubTaskMap_.begin();
    while (iter!=doorSubTaskMap_.end()) {
        int incount=0;
        RW_Excel RW_ExcelItem;
        RW_ExcelItem.ExcelA=QString::number(iter.value().doorId);
        RW_ExcelItem.ExcelB=iter.value().doorIP;
        RW_ExcelItem.ExcelC=iter.value().doorDesc;
        RW_ExcelItem.ExcelD=QString::number(iter.value().Point);
        RW_ExcelItem.ExcelE=QString::number(iter.value().NextPoint);
        RW_ExcelItem.ExcelF=iter.value().NextPointdesc;
        RW_ExcelItem.ExcelG="---";
        RW_ExcelItem.ExcelH="---";
        RW_ExcelItem.ExcelI="---";
        RW_ExcelItem.ExcelJ=QString::number(iter.value().enable);
        RW_ExcelItem.ExcelK=QString::number(iter.value().page);

        RW_ExcelItem.checked=iter.value().checked;
        if(iter.value().checked==1){
            doorSubTaskI=iter.value();
            doorSubTaskI.row=ExcelList.size();
        }if(incount==0){
            incount=1;
            RW_ExcelItem.corlor=0;       // 0
            ExcelList.append(RW_ExcelItem);
        }
        iter++;
    }

    return ExcelList;
}

void AgvItemWidget::TableWidget_show_4()
{
    ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    QList<RW_Excel> ExcelList=TableWidget_4(AGVCurrentTaskMap);
    QStringList comBoxlist;//comBoxlist<<"0"<<"-1";
    table_single::GetInstance()->UP_TableWidget(ui->tableWidget_4,ExcelList,comBoxlist,0);
    if(ExcelList.isEmpty()){
        ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
        return;
    }
    ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
    ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(6,QHeaderView::ResizeToContents);

}

QList<RW_Excel> AgvItemWidget::TableWidget_4(QMap<QString, AGVCurrentTask> AGVCurrentTaskMap)
{
    QList<RW_Excel> ExcelList;
    AGVCurrentTask AGVCurrentTask_;
    AGVCurrentTaskI=AGVCurrentTask_;
    QMap<QString, AGVCurrentTask>::const_iterator iter= AGVCurrentTaskMap.begin();
    while (iter!=AGVCurrentTaskMap.end()) {
        int incount=0;
        RW_Excel RW_ExcelItem;
        RW_ExcelItem.ExcelA=QString::number(iter.value().AGVId);
        RW_ExcelItem.ExcelB=iter.value().AGVIP;
        RW_ExcelItem.ExcelC=QString::number(iter.value().enable);
        RW_ExcelItem.ExcelD=QString::number(iter.value().AGVType);
        RW_ExcelItem.ExcelE=QString::number(iter.value().floornum);
        RW_ExcelItem.ExcelF=QString::number(iter.value().waitPoint);
        RW_ExcelItem.ExcelG=iter.value().chargeIP;
        RW_ExcelItem.ExcelH=QString::number(iter.value().ChargePoint);
        RW_ExcelItem.ExcelI=QString::number(iter.value().ChargeWait);
        RW_ExcelItem.ExcelJ=QString::number(iter.value().MoveAnage);
        RW_ExcelItem.checked=iter.value().checked;

        if(iter.value().checked==1){
            AGVCurrentTaskI=iter.value();
            AGVCurrentTaskI.row=ExcelList.size();
        }if(incount==0){
            incount=1;
            RW_ExcelItem.corlor=0;
            ExcelList.append(RW_ExcelItem);
        }

        iter++;
    }

    return ExcelList;
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

void AgvItemWidget::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    ui->treeWidget->verticalScrollBar()->setVisible(false);
    ui->treeWidget->horizontalScrollBar()->setVisible(false);
    QString treeWidget=item->text(column);
    if(treeWidget=="AGV管理" || treeWidget=="测试界面"){
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget_2->setCurrentIndex(0);
    }if(treeWidget=="参数配置" || treeWidget=="自动门"){
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget_2->setCurrentIndex(2);
    }if(treeWidget=="AGV参数"){
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget_2->setCurrentIndex(1);
    }

    if(treeWidget=="路线管理" || treeWidget=="路线规则"){
        ui->stackedWidget->setCurrentIndex(1);
        ui->stackedWidget_3->setCurrentIndex(0);
    }if(treeWidget=="路线信息"){
        ui->stackedWidget->setCurrentIndex(1);
        ui->stackedWidget_3->setCurrentIndex(1);
    }if(treeWidget=="站点绑定"){
        ui->stackedWidget->setCurrentIndex(1);
        ui->stackedWidget_3->setCurrentIndex(2);
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

void AgvItemWidget::on_start_charge_clicked()
{
    if(queryServer::getInstance()->SetMessagebox("是否执行充电任务?")){
        AGVCurrentTask AGVCurrentTaskI;
        AGVCurrentTaskI.AGVIP=ui->taskstation_IP->currentText().trimmed();
        emit newAGVMoveTask(ui->taskStatusBox_AGV->currentText().trimmed(),"charge",AGVCurrentTaskI);
    }

}

void AgvItemWidget::on_close_charge_clicked()
{
    if(queryServer::getInstance()->SetMessagebox("是否取消充电任务?")){
        AGVCurrentTask AGVCurrentTaskI;
        AGVCurrentTaskI.AGVIP=ui->taskstation_IP->currentText().trimmed();
        emit newAGVMoveTask(ui->taskStatusBox_AGV->currentText().trimmed(),"charge_",AGVCurrentTaskI);
    }

}
