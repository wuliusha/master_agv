#include "taskmanager.h"
#include "ui_taskmanager.h"
//http://172.16.21.101/workplace-manage
taskManager::taskManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::taskManager)
{
    ui->setupUi(this);


    qRegisterMetaType<ESS_Request >("ESS_Request");
    qRegisterMetaType<QMap<int,SAPExcelInfo>>("QMap<int,SAPExcelInfo>");

    taskManagerInit();

    StTimer = new QTimer(this);
    connect(StTimer,&QTimer::timeout,this,&taskManager::ON_taskManagerTimer);
    StTimer->start(600);

}

taskManager::~taskManager()
{
    delete ui;
}

void taskManager::taskManagerInit()
{

    actionIdMap.insert("创建ESS任务_IN","action4");     //出库
    actionIdMap.insert("创建ESS任务_OUT","action2");    //回库-->入库
    actionIdMap.insert("取消ESS任务","action5");        //任务取消请求
    actionIdMap.insert("STATION-01_入场","action6");
    actionIdMap.insert("STATION-03_离场","action7");
    actionIdMap.insert("STATION-04_离场","action7");

    wrexcelprocessItiem=new wrexcelprocess;
    wrexcelprocessItiem->hide();

    //IconHelper::Instance()->setIcon(ui->last_Button, 0xf0ec, 15);
    ui->Selete_DateEdit->setDateTime(QDateTime::fromString(QDateTime::currentDateTime().toString("yyyy-MM-dd")+" 00:00:00" ,"yyyy-MM-dd hh:mm:ss"));
    ui->Selete_DateEdit_2->setDateTime(QDateTime::fromString(QDateTime::currentDateTime().toString("yyyy-MM-dd")+" 23:59:00" ,"yyyy-MM-dd hh:mm:ss"));

    table_single::GetInstance()->TableWidgetInit(ui->tableWidget,12,"QHeaderView::section{background-color:rgb(211, 215, 212);font:12pt '宋体';color: black;};",30,30);
    connect(ui->tableWidget,&QTableWidget::cellClicked,this,&taskManager::SlotsetCurrentItem);

    Actionbtns2<<ui->Qury_Button<<ui->Cancel_Button<<ui->Delete_Button;
    for(int i=0;i<Actionbtns2.length();i++){
        connect(Actionbtns2[i],&QPushButton::pressed,this, &taskManager::ON_Pressed);
        connect(Actionbtns2[i],&QPushButton::released,this,&taskManager::ON_Released);
    }

    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->widget(0)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget_3->setCurrentIndex(0);
    ui->stackedWidget_3->widget(0)->layout()->setContentsMargins(0,0,0,0);

}

void taskManager::postAgvStatus_ESS(QString robotCode)
{
    if(robotCodeiKey==""){//agvStatusiKey为空时: AGV系统往 MES服务器实时更新 AGV小车的状态信息
        robotCodeiKey="robot:"+QDateTime::currentDateTime().toString("ddhhmmss");
        ESS_Request ESS_RequestI;
        ESS_RequestI.pathId=1010;
        ESS_RequestI.actionId="action0";
        ESS_RequestI.robotCode=robotCode;
        ESS_RequestI.robotCodes.append(robotCode);    //机器人查询接口
        ESS_RequestI.taskCodes.append(robotCode);     //任务查询接口
        sapMsgInterface::getInstance()->robotCodes_query(robotCodeiKey,ESS_RequestI,"UserNuber",ESS_RequestI.pathId);
    }else {
        if(postStatuscount%100==0){robotCodeiKey="";}
        ESSRobot ESSRobotI=sapMsgInterface::getInstance()->GetMsgRecv_robot(robotCodeiKey);
        if(ESSRobotI.iKey!=""){
            robotCodeiKey="";
            if(ESSRobotI.robotCode!=""){
                ESS_Single::GetInstance()->setESSRobot(ESSRobotI.robotCode,ESSRobotI);
            }
        }
    }

}


void taskManager::ON_taskManagerTimer()
{

    ServerInitItem=queryServer::getInstance()->getCurrentServerInitItem();
    CurrentServerItem=ESS_Single::GetInstance()->getCurrentServerItem();
    currentSAPExcelInfoTask=getcurrentSAPExcelInfoTask(currentSAPExcelInfoTask);

    TableWidgetcount++;
    if(!ui->checkBox_Edite->isChecked() && countbool){
       countbool=false;
       tableWidget_Show();  //未编辑操作下  实时更新 tableWidget 显示
       if(TableWidgetcount%2==0){

       }if(TableWidgetcount%3==0){
           tableWidget_Show();  //未编辑操作下  实时更新 tableWidget 显示
       }
       countbool=true;
    }

    postStatuscount++;
    if(postStatuscount%5==0){
       postAgvStatus_ESS("kubot-1");                  //AGV系统往 实时更新 海柔AGV的状态信息
    }

    if(postStatuscount>1000){postStatuscount=0;}
    if(TableWidgetcount>10000){TableWidgetcount=0;}

}

void taskManager::SlotsetCurrentItem(int row, int column)
{
    SAPExcelInfo SAPExcelInfoI;
    seletSAPExcelInfoI=SAPExcelInfoI;
    int SAPTaskIndex=ui->tableWidget->item(row,9)->text().trimmed().toInt();
    QMap<int, SAPExcelInfo>::iterator iter= currentSAPExcelInfoTask.begin();
    while (iter !=currentSAPExcelInfoTask.end()) {
        if(iter.value().SAPTaskIndex==SAPTaskIndex && iter.value().taskError==0){
            if(iter.value().checked==0){//选中
                iter.value().checked=1;
                seletSAPExcelInfoI=iter.value();
            }else {
                iter.value().checked=0;
            }
        }
        iter++;
    }
    tableWidget_Show();//tableWidget 更新显示

    ui->lineEdit_table->setText("---->Priority:"+QString::number(seletSAPExcelInfoI.Priority)+"  taskCode:"+seletSAPExcelInfoI.taskId_ess+"  taskId_agv:"+seletSAPExcelInfoI.taskId_agv+
                                "   taskStatus:"+QString::number(seletSAPExcelInfoI.taskStatus));

}

void taskManager::ONUP_SAPExcelInfo(SAPExcelInfo SAPExcelInfoI)
{
//    if(SAPExcelInfoI.taskType!="Empty"){//实时更新（60s）
//        taskStatusiKey=QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");
//        WWYLPOST WWYLPOSTI=ESS_Single::GetInstance()->getWWYLPOSTI(SAPExcelInfoI,"WS02");
//        sapMsgInterface::getInstance()->taskCodes_WW(taskStatusiKey,WWYLPOSTI,"UserNuber",2012);
////        qDebug()<<"定时 给MES 更新任务状态信息--> actionId:"<<WWYLPOSTI.actionId<<" SAPTaskIndex:"<<SAPExcelInfoI.SAPTaskIndex
////               <<" taskStatus:"<<SAPExcelInfoI.taskStatus<<" taskStatusDesc:"<<SAPExcelInfoI.taskStatusDesc;
//    }

}

QMap<int, SAPExcelInfo> taskManager::getcurrentSAPExcelInfoTask(QMap<int, SAPExcelInfo> SAPExcelInfoTask)
{
    QMap<int, SAPExcelInfo>::const_iterator iter= CurrentServerItem.currentSAPExcelInfoTask.begin();
    while (iter!=CurrentServerItem.currentSAPExcelInfoTask.end()){
        if(iter!=nullptr){
            if(!SAPExcelInfoTask.contains(iter.value().SAPTaskIndex)){
                SAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
            }else{
                int taskStatus=SAPExcelInfoTask.value(iter.value().SAPTaskIndex).taskStatus;
                if(iter.value().taskStatus>taskStatus){
                    SAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
                    qDebug()<<"taskManager-->任务状态变化:"<<iter.value().SAPTaskIndex<<iter.value().taskStatus<<iter.value().taskStatusDesc;
                }
                //qDebug()<<"SAPTaskIndex:"<<iter.value().SAPTaskIndex<<iter.value().taskStatus<<taskStatus;
            }
        }
        iter++;
    }
    return SAPExcelInfoTask;
}


void taskManager::tableWidget_Show()
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

}

QList<RW_Excel> taskManager::TableWidget()
{
    QList<RW_Excel> ExcelList;
    QList<RW_Excel> ExcelList0;
    QList<RW_Excel> ExcelList1;
    QList<RW_Excel> ExcelList2;
    QList<RW_Excel> ExcelList3;
    QMap<int, SAPExcelInfo>::const_iterator iter= currentSAPExcelInfoTask.begin();
    while (iter!=currentSAPExcelInfoTask.end()) {
        int incount=0;
        RW_Excel RW_ExcelItem;
        //RW_ExcelItem.ExcelA=QString::number(iter.value().SAPTaskIndex);
        RW_ExcelItem.ExcelB=iter.value().taskTypeDesc;                          //操作 OUT-出库  IN-入库
        RW_ExcelItem.ExcelC=iter.value().containerCode;                         //容器编码 (即胶箱编码) ->唯一
        RW_ExcelItem.ExcelD=iter.value().Material;                              //物料号
        RW_ExcelItem.ExcelE=QString::number(iter.value().taskQty);              //数量
        if(iter.value().taskType=="IN"){
            RW_ExcelItem.ExcelF=iter.value().destination;                       //起始站点
            RW_ExcelItem.ExcelG=iter.value().sourcestation;                     //线体名称  入库时对接 输送线对接码头   出库时对应放箱码头
        }if(iter.value().taskType=="OUT"){
            RW_ExcelItem.ExcelF=iter.value().sourcestation;                     //起始站点
            RW_ExcelItem.ExcelG=iter.value().destination;                       //线体名称  入库时对接 输送线对接码头   出库时对应放箱码头
        }if(iter.value().taskType=="Empty"){
            RW_ExcelItem.ExcelF="---";                                          //起始站点
            RW_ExcelItem.ExcelG=iter.value().sourcestation;                     //线体名称  入库时对接 输送线对接码头   出库时对应放箱码头
        }

        RW_ExcelItem.ExcelH=iter.value().taskStatusDesc+"-"+QString::number(iter.value().taskStatus);                        //任务状态注释
        RW_ExcelItem.ExcelI=iter.value().pickDesc_s;                            //任务状态注释
        RW_ExcelItem.ExcelJ=QString::number(iter.value().SAPTaskIndex);
        RW_ExcelItem.ExcelK=iter.value().creatTimer.toString("MM-dd hh:mm:ss"); //创建时间
        RW_ExcelItem.checked=iter.value().checked;


        //二楼正在运行
        if(incount==0 && (iter.value().taskStatus>0 && iter.value().taskStatus<9)){
            incount=1;
            RW_ExcelItem.corlor=0;       // 0
            ExcelList0.append(RW_ExcelItem);
        }

        if(incount==0 && (iter.value().taskStatus>9 && iter.value().taskStatus<15)){
            incount=1;
            RW_ExcelItem.corlor=0;       // 0
            ExcelList1.append(RW_ExcelItem);
        }

        if(incount==0 && iter.value().taskStatus==0){
            incount=1;
            RW_ExcelItem.corlor=0;       // 0
            ExcelList2.append(RW_ExcelItem);
        }

        if(incount==0 && iter.value().taskStatus!=100){
            incount=1;
            RW_ExcelItem.corlor=0;       // 0
            ExcelList3.append(RW_ExcelItem);
        }

        iter++;
    }

    ExcelList=ExcelList0+ExcelList1+ExcelList2+ExcelList3;
    for (int i=0;i<ExcelList.size();i++) {
        ExcelList[i].ExcelA=QString::number(i+1);
    }
    ui->lineEdit_count->setText("项数:"+QString::number(ExcelList.size()));
    return ExcelList;
}

void taskManager::ON_Pressed()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    Instance::GetInstance()->SetButton_pressed(Button,"background-color: rgb(85,255,127);color:#ffffff;color: white;  border: 2px groove gray;\
                                               border-radius:15px;border-style: outset");
}

void taskManager::ON_Released()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    if(Button->objectName()=="Qury_Button"|| Button->objectName()=="Cancel_Button"){
        Instance::GetInstance()->SetButton_pressed(Button,"background-color: rgb(0, 166, 172);color:#ffffff;color: white;  border: 2px groove gray;\
                                                         border-radius:15px;border-style: outset");
    }else{
        Instance::GetInstance()->SetButton_pressed(Button,"color:#ffffff;color: white;  border: 2px groove gray;\
                                                             border-radius:15px;border-style: outset");
    }
}

void taskManager::on_Delete_Button_clicked()
{
    if(ui->checkBox_Edite->isChecked()){
        //taskStatus>0  iter.value().taskStatus<100
        if(seletSAPExcelInfoI.SAPTaskIndex>0){
            QMap<int, SAPExcelInfo>seletSAPExcelInfoTask;
            seletSAPExcelInfoTask.insert(seletSAPExcelInfoI.SAPTaskIndex,seletSAPExcelInfoI);
            emit sig_deleteSAPExcelInfoTask(seletSAPExcelInfoTask);
        }else{
            ui->lineEdit_table->setText("存在正在执行的任务,无法执行删除");
        }
        on_Cancel_Button_clicked();
    }
}

//ESS任务指令
void taskManager::on_taskStatusBox_ESS_currentTextChanged(const QString &arg1)
{
    if(ui->taskStatusBox_ESS->currentIndex()!=0){

        if(seletSAPExcelInfoI.SAPTaskIndex>0){
            ESS_Request ESS_RequestI;
            ESS_RequestI.actionId=actionIdMap.value(arg1);
            ESS_RequestI.containerCode=seletSAPExcelInfoI.containerCode;
            QStringList positionCode=arg1.split("_");
            if(!positionCode.isEmpty()){
                ESS_RequestI.positionCode=ServerInitItem.StationCodeMap.value(positionCode[0]);
            }
            if(queryServer::getInstance()->SetMessagebox("是否执行当前ESS工作站指令?")){
                bool sendTask=false;
                if(seletSAPExcelInfoI.taskType!="MOVE"){
                   if(seletSAPExcelInfoI.taskType=="IN" && arg1=="STATION-01_入场" && seletSAPExcelInfoI.taskStatus<=4){
                        sendTask=true;
                        seletSAPExcelInfoI.taskStatus=3;//3容器到位  4容器到位下发成功
                   }
                   if(seletSAPExcelInfoI.taskType=="OUT" && (arg1=="STATION-03_离场" || arg1=="STATION-04_离场")){
                       sendTask=true;
                       seletSAPExcelInfoI.taskStatus=12;
                   }if(seletSAPExcelInfoI.taskType=="IN" && arg1=="入库完成" && seletSAPExcelInfoI.taskStatus>=3){
                       sendTask=true;
                       seletSAPExcelInfoI.taskStatus=100;
                   }if(seletSAPExcelInfoI.taskType=="OUT" && arg1=="出库完成" && seletSAPExcelInfoI.taskStatus>=9){
                       sendTask=true;
                       seletSAPExcelInfoI.taskStatus=100;
                   }
                   if(arg1=="取消ESS任务" && seletSAPExcelInfoI.taskStatus==0){
                       //sendTask=true;
                   }
                   if(sendTask){
                       QMap<int, SAPExcelInfo>seletSAPExcelInfoTask;
                       seletSAPExcelInfoTask.insert(seletSAPExcelInfoI.SAPTaskIndex,seletSAPExcelInfoI);
                       emit sig_UPSAPExcelInfoTask(seletSAPExcelInfoTask,ESS_RequestI,"ESSTask");
                   }else{
                       queryServer::getInstance()->SetMessagebox("无法执行当前指令->:"+arg1);
                   }
                }
            }
        }else{
            queryServer::getInstance()->SetMessagebox("请选择需要更改项");
        }
        ui->taskStatusBox_ESS->setCurrentIndex(0);
        on_Cancel_Button_clicked();
    }

}

//AGV运输指令
void taskManager::on_taskStatusBox_AGV_currentTextChanged(const QString &arg1)
{
    if(ui->taskStatusBox_AGV->currentIndex()!=0){
        if(seletSAPExcelInfoI.SAPTaskIndex>0){
            ESS_Request ESS_RequestI;
            if(queryServer::getInstance()->SetMessagebox("是否执行当前AGV工作站指令?")){
                 bool sendTask=false;
                 if(seletSAPExcelInfoI.taskType=="Empty" ){
                     if(arg1== "执行起始楼层任务" && seletSAPExcelInfoI.taskStatus==0){
                         sendTask=true;
                     }if(arg1== "执行目标楼层任务" && seletSAPExcelInfoI.taskStatus==17){
                         sendTask=true;
                     }
                 }if(seletSAPExcelInfoI.taskType=="OUT"){
                     if(arg1== "执行起始楼层任务" && seletSAPExcelInfoI.taskStatus==9){
                        sendTask=true;
                     }if(arg1== "执行目标楼层任务" && seletSAPExcelInfoI.taskStatus==17){
                        sendTask=true;
                     }
                     sendTask=true;
                 }
                 if(sendTask){
                    QMap<int, SAPExcelInfo>seletSAPExcelInfoTask;
                    seletSAPExcelInfoTask.insert(seletSAPExcelInfoI.SAPTaskIndex,seletSAPExcelInfoI);
                    emit sig_UPSAPExcelInfoTask(seletSAPExcelInfoTask,ESS_RequestI,"ESSTask");
                 }else{
                    queryServer::getInstance()->SetMessagebox("当前任务无法执行->:"+arg1);
                 }
            }
        }else{
            queryServer::getInstance()->SetMessagebox("请选择需要更改项");
        }
        ui->taskStatusBox_AGV->setCurrentIndex(0);
        on_Cancel_Button_clicked();
    }
}

void taskManager::on_Qury_Button_clicked()
{

}

void taskManager::on_Cancel_Button_clicked()
{
    SAPExcelInfo SAPExcelInfoI;
    seletSAPExcelInfoI=SAPExcelInfoI;
    QMap<int, SAPExcelInfo>::iterator iter= currentSAPExcelInfoTask.begin();
    while (iter!=currentSAPExcelInfoTask.end()){
        iter.value().checked=0;
        iter++;
    }
    tableWidget_Show();//tableWidget 更新显示
}
