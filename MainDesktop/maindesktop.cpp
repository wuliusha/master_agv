#include "maindesktop.h"
#include "ui_maindesktop.h"
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase)

MainDesktop::MainDesktop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainDesktop)
{
    ui->setupUi(this);
    MainDesktopInit();

    DesktopTimer = new QTimer(this);
    connect(DesktopTimer,&QTimer::timeout,this,&MainDesktop::ON_MainDesktopTimer);
    DesktopTimer->start(1200);

}

MainDesktop::~MainDesktop()
{
    delete ui;
}

void MainDesktop::MainDesktopInit()
{
    monitoringI = new monitoring;
    ui->stackedWidget->insertWidget(0,monitoringI);
    ui->stackedWidget->widget(0)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget->setCurrentIndex(0);

    table_single::GetInstance()->TableWidgetInit(ui->tableWidget,14,"QHeaderView::section{background-color:rgb(77,135,165);font:12pt '宋体';color: white;};",35,35);
    table_single::GetInstance()->TableWidgetInit(ui->tableWidget_agv,14,"QHeaderView::section{background-color:rgb(77,135,165);font:12pt '宋体';color: white;};",35,35);
    connect(ui->tableWidget,&QTableWidget::cellClicked,this,&MainDesktop::SlotsetCurrentItem);
    connect(ui->tableWidget_agv,&QTableWidget::cellClicked,this,&MainDesktop::SlotsetCurrentItem_2);

    ui->tabWidget->setCurrentIndex(0);
    currentlabel = new QPushButton;
    connect(currentlabel,&QPushButton::clicked,this,&MainDesktop::ON_Click);
    currentlabel->setText("    ");
    currentlabel->setMinimumSize(30,25);
    IconHelper::Instance()->setIcon(currentlabel, 0xf02c, 15);
    currentlabel->setToolTip("当容器到位后，机器人不去取货时可先解绑，再重新绑定");
    ui->tabWidget->setCornerWidget(currentlabel,Qt::TopRightCorner);
    AGVCurrentTaskI=new AGVCurrentTask;

}

void MainDesktop::tableWidget_Show()
{
    //解决显示卡顿问题:  https://blog.csdn.net/u014746838/article/details/102642083
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    QStringList comBoxlist;
    QList<RW_Excel> ExcelList=TableWidget();
    table_single::GetInstance()->UP_TableWidget(ui->tableWidget,ExcelList,comBoxlist,0);
    if(ExcelList.isEmpty()){
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
        return;
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    ui->tableWidget->sortItems(8, Qt::AscendingOrder);// 对 n 列排序, 默认升序

}

QList<RW_Excel> MainDesktop::TableWidget()
{
    QList<RW_Excel> ExcelList;
    QList<RW_Excel> ExcelList0;
    QList<RW_Excel> ExcelList1;
    QList<RW_Excel> ExcelList2;
    QList<RW_Excel> ExcelList3;
    QMap<int, SAPExcelInfo>::const_iterator iter= seletSAPExcelInfoTask.begin();
    while (iter!=seletSAPExcelInfoTask.end()) {
        if(iter!=nullptr){
            if(iter.value().taskStatus<taskFnish){
                int incount=0;
                RW_Excel RW_ExcelItem;
                RW_ExcelItem.ExcelB=iter.value().taskTypeDesc;                          //操作 OUT-出库  IN-入库
                RW_ExcelItem.ExcelC=iter.value().containerCode;                         //容器编码 (即胶箱编码) ->唯一
                RW_ExcelItem.ExcelD=iter.value().LabelNo;                               //订单编码
                RW_ExcelItem.ExcelE=iter.value().pickDesc_s;                              //物料号
                if(iter.value().taskType=="IN"){
                    RW_ExcelItem.ExcelF=iter.value().sourcestation;                       //起始站点
                    RW_ExcelItem.ExcelG=iter.value().destination;                     //线体名称  入库时对接 输送线对接码头   出库时对应放箱码头
                }if(iter.value().taskType=="OUT"){
                    RW_ExcelItem.ExcelF=iter.value().sourcestation;                     //起始站点
                    RW_ExcelItem.ExcelG=iter.value().destination;                       //线体名称  入库时对接 输送线对接码头   出库时对应放箱码头
                }if(iter.value().taskType=="Empty"){
                    RW_ExcelItem.ExcelF=iter.value().sourcestation;                     //起始站点
                    RW_ExcelItem.ExcelG=iter.value().destination;                       //线体名称  入库时对接 输送线对接码头   出库时对应放箱码头
                }

                RW_ExcelItem.ExcelH=iter.value().taskStatusDesc+"-"+QString::number(iter.value().taskStatus);                        //任务状态注释
                RW_ExcelItem.ExcelI=QString::number(iter.value().SAPTaskIndex);
                RW_ExcelItem.ExcelJ=iter.value().creatTimer.toString("MM-dd hh:mm:ss"); //创建时间
                RW_ExcelItem.checked=iter.value().checked;

                //二楼正在运行
                if(incount==0 && (iter.value().taskStatus>0 && iter.value().taskStatus<9)){
                    incount=1;
                    RW_ExcelItem.corlor=2;
                    ExcelList0.append(RW_ExcelItem);
                }
                if(incount==0 && (iter.value().taskStatus>9 && iter.value().taskStatus<15)){
                    incount=1;
                    RW_ExcelItem.corlor=3;
                    ExcelList1.append(RW_ExcelItem);
                }

                if(incount==0 && iter.value().taskStatus==0){
                    incount=1;
                    RW_ExcelItem.corlor=0;
                    ExcelList2.append(RW_ExcelItem);
                }

                if(incount==0){
                    incount=1;
                    RW_ExcelItem.corlor=0;
                    ExcelList3.append(RW_ExcelItem);
                }

            }
        }else{
            return ExcelList;
        }
        ++iter;
    }

    ExcelList=ExcelList0+ExcelList1+ExcelList2+ExcelList3;
    for(int i=0;i<ExcelList.size();i++){
        ExcelList[i].ExcelA=QString::number(i+1);
    }
    return ExcelList;
}

void MainDesktop::tableWidget_Show_agv()
{
    //解决显示卡顿问题:  https://blog.csdn.net/u014746838/article/details/102642083
    ui->tableWidget_agv->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    QStringList comBoxlist;
    QList<RW_Excel> ExcelList=TableWidget_agv();
    table_single::GetInstance()->UP_TableWidget(ui->tableWidget_agv,ExcelList,comBoxlist,0);
    if(ExcelList.isEmpty()){
        ui->tableWidget_agv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
        return;
    }
    ui->tableWidget_agv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
    ui->tableWidget_agv->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    ui->tableWidget_agv->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
}

QList<RW_Excel> MainDesktop::TableWidget_agv()
{
    QList<RW_Excel> ExcelList;
    QList<RW_Excel> ExcelList0;
    QMap<QString,AGVCurrentTask*>::iterator iter;
    foreach(AGVCurrentTask* iter,AGVCurrentTaskMap.values()){
        int incount=0;
        RW_Excel RW_ExcelItem;
        RW_ExcelItem.ExcelA=QString::number(iter->AGVId);
        RW_ExcelItem.ExcelB=iter->AGVIP;
        RW_ExcelItem.ExcelC=QString::number(iter->AGVType);
        RW_ExcelItem.ExcelD=QString::number(iter->floornum);
        RW_ExcelItem.ExcelE=QString::number(iter->Currentpoint);
        RW_ExcelItem.ExcelF=QString::number(iter->destpoint);
        RW_ExcelItem.ExcelG=QString::number(iter->Nextdestpoint);
        RW_ExcelItem.ExcelH=QString::number(iter->Currentdestpoint);
        RW_ExcelItem.ExcelI=QString::number(iter->Action_agv);
        RW_ExcelItem.ExcelJ=QString::number(iter->SAPTaskIndex);
        RW_ExcelItem.ExcelK=iter->taskId;
        RW_ExcelItem.ExcelL=iter->lastTaskId;
        RW_ExcelItem.ExcelM=QString::number(iter->ChargeAction);
        RW_ExcelItem.ExcelN=QString::number(iter->VoltageState);

        RW_ExcelItem.checked=iter->checked;
        if(incount==0 ){
            incount=1;
            RW_ExcelItem.corlor=0;
            if(!iter->isOnline){
                RW_ExcelItem.corlor=4;
                RW_ExcelItem.ExcelO="离线";
            }else{
                if(iter->agverror!=0){
                    RW_ExcelItem.corlor=4;
                }if(iter->VoltageState<30){
                    RW_ExcelItem.corlor=3;
                }
                RW_ExcelItem.ExcelO=QString::number(iter->agverror);
            }
            ExcelList.append(RW_ExcelItem);
        }
    }
    return ExcelList;
}

void MainDesktop::CancelInit(QString taskType)
{
    if(taskType=="task"){
        SAPExcelInfo SAPExcelInfoI;
        seletSAPExcelInfoI=SAPExcelInfoI;
        QMap<int, SAPExcelInfo>::iterator iter= seletSAPExcelInfoTask.begin();
        while (iter!=seletSAPExcelInfoTask.end()){
            iter.value().checked=0;
            ++iter;
        }
        tableWidget_Show();//tableWidget 更新显示
    }if(taskType=="AGV"){
        AGVCurrentTaskI=new AGVCurrentTask;
    }
}

bool MainDesktop::setAGVCurrentTaskMap_Status(QMap<QString, AGVCurrentTask*> AGVCurrentTaskMap)
{
    //更新AGV状态信息
    bool update=true;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    QMap<QString, AGVCurrentTask*>::const_iterator iter=AGVCurrentTaskMap.begin();
    while (iter!=AGVCurrentTaskMap.end()) {
        if(iter!=nullptr){
            sqlQuery.prepare("UPDATE [dbo].[AGVCurrentTask] SET [Currentdestpoint]=:Currentdestpoint,"
                             "[destpoint]=:destpoint,[Nextdestpoint]=:Nextdestpoint,[waitdestpoint]=:waitdestpoint,"
                             "[Action_agv]=:Action_agv,[Action_ess]=:Action_ess,[Action_all]=:Action_all,"
                             "[actionType]=:actionType,[taskId]=:taskId,[lastTaskId]=:lastTaskId,[taskType]=:taskType,"
                             "[SAPTaskIndex]=:SAPTaskIndex,[containerCode]=:containerCode "
                             "WHERE ([AGVIP]=:AGVIP);");

            sqlQuery.addBindValue(iter.value()->Currentdestpoint);       //当前目标二维码
            sqlQuery.addBindValue(iter.value()->destpoint);              //第一个目标二维码
            sqlQuery.addBindValue(iter.value()->Nextdestpoint);          //下一个目标二维码
            sqlQuery.addBindValue(iter.value()->waitdestpoint);          //目标点等待点二维码
            sqlQuery.addBindValue(iter.value()->Action_agv);             //二维码带举升动作
            sqlQuery.addBindValue(iter.value()->Action_ess);             //夹包机器人
            sqlQuery.addBindValue(iter.value()->Action_all);             //总动作计数
            sqlQuery.addBindValue(iter.value()->actionType);             //动作类型 0到达站点不需要返回  1到达站点倒计时结束后返回
            sqlQuery.addBindValue(iter.value()->taskId);                 //唯一识别号
            sqlQuery.addBindValue(iter.value()->lastTaskId);             //上一个任务--唯一识别号

            sqlQuery.addBindValue(iter.value()->taskType);               //任务类型 IN入库  OUT出库
            sqlQuery.addBindValue(iter.value()->SAPTaskIndex);           //任务索引 唯一值
            sqlQuery.addBindValue(iter.value()->containerCode);          //容器编码 (即胶箱编码) ->唯一
            sqlQuery.addBindValue(iter.value()->AGVIP);                  //容器编码 (即胶箱编码) ->唯一

            if(sqlQuery.exec()){
//                qDebug()<<"set codeDesc S---->AGVIP:"<<iter.value().AGVIP<<" Action_agv:"<<iter.value().Action_agv
//                       <<" taskType:"<<iter.value().taskType<<" SAPTaskIndex:"<<iter.value().SAPTaskIndex;
            }else {
                update= false;
//                qDebug()<<"set codeDesc ---->AGVIP:"<<iter.value().AGVIP<<" Action_agv:"<<iter.value().Action_agv
//                       <<" taskType:"<<iter.value().taskType<<" SAPTaskIndex:"<<iter.value().SAPTaskIndex;
            }
        }else{
             return false;
        }
        ++iter;
    }

    return update;

}

void MainDesktop::ON_MainDesktopTimer()
{
    if(Desktop){
        Desktop=false;
        TableWidgetcount++;
        switch (TableWidgetcount%remainder)
        {
            case 0:
            {
                if(seletSAPExcelInfoI.SAPTaskIndex==0){
                    seletSAPExcelInfoTask=ESS_Single::getInstance()->getCurrentSAPExcelInfoTask();
                    tableWidget_Show();                             //tableWidget 更新显示
                }
            }
                break;
            case 2:
            {
                setAGVCurrentTaskMap_Status(AGVCurrentTaskMap);
            }
                break;
            case 4:
            {
                if(AGVCurrentTaskI->AGVIP==""){
                    tableWidget_Show_agv();
                }
            }
                break;
            default:
                break;
        }
        Desktop=true;
    }
    if(TableWidgetcount>10000){TableWidgetcount=0;}
}

void MainDesktop::SlotsetCurrentItem(int row, int column)
{
    SAPExcelInfo SAPExcelInfoI;
    seletSAPExcelInfoI=SAPExcelInfoI;
    int SAPTaskIndex=ui->tableWidget->item(row,8)->text().trimmed().toInt();
    QMap<int, SAPExcelInfo>::iterator iter= seletSAPExcelInfoTask.begin();
    while (iter !=seletSAPExcelInfoTask.end()) {
        if(iter.value().SAPTaskIndex==SAPTaskIndex){
            if(iter.value().checked==0){//选中
                iter.value().checked=1;
                seletSAPExcelInfoI=iter.value();
                ui->widget->setVisible(true);
            }else {
                iter.value().checked=0;
            }
        }else{
            iter.value().checked=0;
        }
        ++iter;
    }

    tableWidget_Show();//tableWidget 更新显示
}

void MainDesktop::SlotsetCurrentItem_2(int row, int column)
{
    AGVCurrentTaskI=new AGVCurrentTask;
    QString AGVIP=ui->tableWidget_agv->item(row,1)->text().trimmed();
    QMap<QString, AGVCurrentTask*>::iterator iter= AGVCurrentTaskMap.begin();
    while (iter !=AGVCurrentTaskMap.end()) {
        if(iter.value()->AGVIP==AGVIP){
            if(iter.value()->checked==0){//选中
                iter.value()->checked=1;
                AGVCurrentTaskI=iter.value();
                ui->widget_2->setVisible(true);
            }else {
                iter.value()->checked=0;
            }
        }else{
            iter.value()->checked=0;
        }
        ++iter;
    }
    tableWidget_Show_agv();

}

void MainDesktop::slotAGVCurrentTaskMap(QMap<QString, AGVCurrentTask *> AGVCurrentTaskMapI)
{
    AGVCurrentTaskMap=AGVCurrentTaskMapI;
}

void MainDesktop::ON_Click()
{
    if(ui->widget->isVisible()){
        ui->widget->setVisible(false);
    }else{
        ui->widget->setVisible(true);
    }if(ui->widget_2->isVisible()){
        ui->widget_2->setVisible(false);
    }else{
        ui->widget_2->setVisible(true);
    }
}


void MainDesktop::on_taskStatusBox_ESS_currentTextChanged(const QString &arg1)
{
    if(ui->taskStatusBox_ESS->currentIndex()!=0){
        if(seletSAPExcelInfoI.SAPTaskIndex>0){
            ESS_Request ESS_RequestI;
            if(queryServer::getInstance()->SetMessagebox("是否执行当前ESS工作站指令?")){
                bool sendTask=false;
                int taskStatus=seletSAPExcelInfoI.taskStatus;
                if(seletSAPExcelInfoI.taskType=="IN"){
                    if(arg1=="料框入场" && (taskStatus>=2 && taskStatus<6)){
                        sendTask=true;
                        seletSAPExcelInfoI.taskStatus=3;    //3容器到位  4容器到位下发成功
                    }if(arg1=="任务完成"){
                        sendTask=true;
                        seletSAPExcelInfoI.taskStatus=taskFnish;  //入库完成
                    }
                }

                if(seletSAPExcelInfoI.taskType=="OUT"){
                    if(arg1=="料框离场"){
                        sendTask=true;
                        seletSAPExcelInfoI.taskStatus=12;
                    }if(arg1=="电梯前往目标楼层" && (taskStatus>=9 && taskStatus<100)){
                        sendTask=true;
                        seletSAPExcelInfoI.taskStatus=15;
                    }if(arg1== "执行运输任务_S"){
                        sendTask=true;
                        seletSAPExcelInfoI.taskStatus=10;
                    }if(arg1== "前往目标楼层"){
                        sendTask=true;
                        seletSAPExcelInfoI.taskStatus=tasklift_ess;
                    }if(arg1== "执行运输任务_E"){
                        sendTask=true;
                        seletSAPExcelInfoI.taskStatus=17;
                    }if(arg1=="任务完成" && (taskStatus>=9 && taskStatus<100)){
                        sendTask=true;
                        seletSAPExcelInfoI.taskStatus=taskFnish;
                    }
                }

                if(seletSAPExcelInfoI.taskType=="Empty" ){
                    if(arg1== "执行运输任务_S"){
                        sendTask=true;
                        seletSAPExcelInfoI.taskStatus=10;
                    }if(arg1== "前往目标楼层"){
                        sendTask=true;
                        seletSAPExcelInfoI.taskStatus=tasklift_ess;
                    }if(arg1== "执行运输任务_E"){
                        sendTask=true;
                        seletSAPExcelInfoI.taskStatus=17;
                    }
                }

                if(sendTask){//允许更改状态
                    emit sig_UPSAPExcelInfoTask(seletSAPExcelInfoI);
                }else{
                    queryServer::getInstance()->SetMessagebox("无法执行当前指令->:"+arg1);
                }
            }
        }else{
            queryServer::getInstance()->SetMessagebox("请选择需要更改项");
        }
    }
    ui->taskStatusBox_ESS->setCurrentIndex(0);
}

void MainDesktop::on_Delete_Button_clicked()
{
    if(ui->checkBox_Edite->isChecked()){
        if(seletSAPExcelInfoI.SAPTaskIndex>0){
            seletSAPExcelInfoI.taskStatus=taskStatus_delete_;
            emit sig_deleteSAPExcelInfoTask(seletSAPExcelInfoI);
        }else{
            queryServer::getInstance()->SetMessagebox("存在正在执行的任务,无法执行删除");
        }
        CancelInit("task");
    }
}
void MainDesktop::on_taskFnish__clicked()
{
    if(seletSAPExcelInfoI.SAPTaskIndex>0){
        seletSAPExcelInfoI.taskStatus=taskFnish;
        emit sig_deleteSAPExcelInfoTask(seletSAPExcelInfoI);
    }else{
        queryServer::getInstance()->SetMessagebox("存在正在执行的任务,无法执行删除");
    }
    CancelInit("task");
}

void MainDesktop::on_taskStatusBox_AGV_currentTextChanged(const QString &arg1)
{
    int Action=0;
    if(ui->taskStatusBox_AGV->currentIndex()!=0){
        if(AGVCurrentTaskI->AGVIP!=""){
            ESS_Request ESS_RequestI;
            if(queryServer::getInstance()->SetMessagebox("是否执行当前AGV工作站指令?")){
                 bool sendTask=false;
                 if(arg1== "前往起始站点"){
                     Action=0;
                     sendTask=true;
                 }if(arg1== "执行举升动作"){
                     Action=1;
                     sendTask=true;
                 }if(arg1== "前往目标站点"){
                     Action=2;
                     sendTask=true;
                 }if(arg1== "执行下降动作"){
                     Action=4;
                     sendTask=true;
                 }if(arg1== "任务完成"){
                     Action=5;
                     sendTask=true;
                 }if(arg1== "任务取消"){
                     Action=100;
                     sendTask=true;
                 }
                 if(sendTask){
                     //手动更新AGV当前动作指令状态
                     emit sig_AGVCurrentTaskAction(AGVCurrentTaskI->AGVIP, "Type", Action);
                     qDebug()<<"手动更新AGV当前动作指令状态--sig0->AGVIP:"<<AGVCurrentTaskI->AGVIP;
                 }else{
                    queryServer::getInstance()->SetMessagebox("当前任务无法执行->:"+arg1);
                 }
            }
        }else{
            queryServer::getInstance()->SetMessagebox("请选择需要更改项");
        }
        ui->taskStatusBox_AGV->setCurrentIndex(0);
        CancelInit("AGV");
    }
}

void MainDesktop::on_Button_Init_clicked()
{
    if(ui->checkBox_Edite_2->isChecked()){
        if(queryServer::getInstance()->SetMessagebox("是否初始化当前AGV?")){
            if(AGVCurrentTaskI->AGVIP!=""){
                //手动更新AGV当前动作指令状态
                emit sig_AGVCurrentTaskAction(AGVCurrentTaskI->AGVIP,"Type",100);
                qDebug()<<"手动更新AGV当前动作指令状态--sig1->AGVIP:"<<AGVCurrentTaskI->AGVIP;
            }else {
                queryServer::getInstance()->SetMessagebox("请选择需要更改项");
            }
        }
        CancelInit("AGV");
    }

}




