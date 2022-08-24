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
    StTimer->start(1200);

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
        //sapMsgInterface::getInstance()->robotCodes_query(robotCodeiKey,ESS_RequestI,"UserNuber",ESS_RequestI.pathId);
    }else {
        if(postStatuscount%100==0){robotCodeiKey="";}
        ESSRobot ESSRobotI=sapMsgInterface::getInstance()->GetMsgRecv_robot(robotCodeiKey);
        if(ESSRobotI.iKey!=""){
            robotCodeiKey="";
            if(ESSRobotI.robotCode!=""){
                ESS_Single::getInstance()->setESSRobot(ESSRobotI.robotCode,ESSRobotI);
            }
        }
    }

}


void taskManager::ON_taskManagerTimer()
{
    TableWidgetcount++;
    if(countbool){
        countbool=false;

        if(ServerInitItem.UserInfoList.isEmpty()){
            /************** 基础信息赋值 *******************/
            allServerInit ALLServerInitItem=queryServer::getInstance()->getCurrentServerInitItem();
            ServerInitItem=ALLServerInitItem.ServerInitItem;
            CurrentServerItem=ALLServerInitItem.CurrentServerItem;
        }

        if(TableWidgetcount%3==0){
           if(!currentlabelMap.isEmpty()){
               ReplyMsg ReplyMsgI=sapMsgInterface::getInstance()->GetMsgRecv_Msg(currentlabelMap.firstKey());
               if(ReplyMsgI.keyId!=""){
                   ui->lineEdit_table->setText("指令执行反馈-->Msg:"+ReplyMsgI.errorMsg+"   更新时间:"+QDateTime::currentDateTime().toString());
                   currentlabelMap.remove(currentlabelMap.firstKey());
               }
           }
       }
       countbool=true;
    }

    postStatuscount++;
    if(postStatuscount%10==0){
       //postAgvStatus_ESS("kubot-1");                  //AGV系统往 实时更新 海柔AGV的状态信息
    }

    if(postStatuscount>1000){postStatuscount=0;}
    if(TableWidgetcount>10000){TableWidgetcount=0;}

}

void taskManager::SlotsetCurrentItem(int row, int column)
{
    SAPExcelInfo SAPExcelInfoI;
    seletSAPExcelInfoI=SAPExcelInfoI;
    int SAPTaskIndex=ui->tableWidget->item(row,9)->text().trimmed().toInt();
    QMap<int, SAPExcelInfo>::iterator iter= seletSAPExcelInfoTask.begin();
    while (iter !=seletSAPExcelInfoTask.end()) {
        if(iter.value().SAPTaskIndex==SAPTaskIndex){
            if(iter.value().checked==0){//选中
                iter.value().checked=1;
                seletSAPExcelInfoI=iter.value();
            }else {
                iter.value().checked=0;
            }
        }else{
            iter.value().checked=0;
        }
        ++iter;
    }
    tableWidget_Show();//tableWidget 更新显示

    ui->bundleBox->setCurrentText(seletSAPExcelInfoI.pickDesc_s);
    ui->containerCode->setText(seletSAPExcelInfoI.containerCode);
    ui->shelfBindesc->setText(seletSAPExcelInfoI.podIdDesc);
    ui->shelfBindesc_e->setText(seletSAPExcelInfoI.shelfBindesc);

    ui->lineEdit_table->setText("-----> LabelNo:"+seletSAPExcelInfoI.LabelNo+"  containerCode:"+seletSAPExcelInfoI.containerCode
                                +"  podIdDesc:"+seletSAPExcelInfoI.podIdDesc+"  shelfBindesc:"+seletSAPExcelInfoI.shelfBindesc
                                +"  taskCode:"+seletSAPExcelInfoI.taskId_ess+"  taskId_agv:"+seletSAPExcelInfoI.taskId_agv+
                                "   taskStatus:"+QString::number(seletSAPExcelInfoI.taskStatus)+seletSAPExcelInfoI.taskStatusDesc);

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
    QString taskTy=ui->taskTypeBox->currentText().trimmed();
    foreach(SAPExcelInfo iter,seletSAPExcelInfoTask.values())
    {
        int incount=0;
        RW_Excel RW_ExcelItem;
        //RW_ExcelItem.ExcelA=QString::number(iter.value().SAPTaskIndex);
        RW_ExcelItem.ExcelB=iter.taskTypeDesc;                          //操作 OUT-出库  IN-入库
        RW_ExcelItem.ExcelC=iter.containerCode;                         //容器编码 (即胶箱编码) ->唯一
        RW_ExcelItem.ExcelD=iter.LabelNo;                               //工单编码
        RW_ExcelItem.ExcelE=QString::number(iter.taskQty);              //数量

        if(iter.taskType=="IN"){
            RW_ExcelItem.ExcelF=iter.destination;                       //起始站点
            RW_ExcelItem.ExcelG=iter.sourcestation;                     //线体名称  入库时对接 输送线对接码头   出库时对应放箱码头
        }if(iter.taskType=="OUT"){
            RW_ExcelItem.ExcelF=iter.sourcestation;                     //起始站点
            RW_ExcelItem.ExcelG=iter.destination;                       //线体名称  入库时对接 输送线对接码头   出库时对应放箱码头
        }if(iter.taskType=="Empty"){
            RW_ExcelItem.ExcelF="---";                                  //起始站点
            RW_ExcelItem.ExcelG=iter.sourcestation;                     //线体名称  入库时对接 输送线对接码头   出库时对应放箱码头
        }

        RW_ExcelItem.ExcelH=iter.taskStatusDesc+"-"+QString::number(iter.taskStatus);                        //任务状态注释
        RW_ExcelItem.ExcelI=iter.pickDesc_s;                            //任务状态注释
        RW_ExcelItem.ExcelJ=QString::number(iter.SAPTaskIndex);
        RW_ExcelItem.ExcelK=iter.creatTimer.toString("MM-dd hh:mm:ss"); //创建时间
        RW_ExcelItem.checked=iter.checked;

        if(incount==0 && iter.taskStatus!=100){
            incount=1;
            RW_ExcelItem.corlor=2;       // 0
            ExcelList2.append(RW_ExcelItem);
        }if(incount==0){
            incount=1;
            RW_ExcelItem.corlor=0;       // 0
            ExcelList3.append(RW_ExcelItem);
        }

    }

    ExcelList=ExcelList0+ExcelList1+ExcelList2+ExcelList3;
    for (int i=0;i<ExcelList.size();i++) {
        ExcelList[i].ExcelA=QString::number(i+1);
    }
    ui->lineEdit_count->setText("项数:"+QString::number(ExcelList.size()));
    return ExcelList;
}

void taskManager::on_Delete_Button_clicked()
{
    if(ui->checkBox_Edite->isChecked()){
        if(seletSAPExcelInfoI.SAPTaskIndex>0){
            emit sig_deleteSAPExcelInfoTask(seletSAPExcelInfoI);
        }else{
            ui->lineEdit_table->setText("存在正在执行的任务,无法执行删除");
        }
        on_Cancel_Button_clicked();
    }
}

void taskManager::on_Qury_Button_clicked()
{
    seletSAPExcelInfoTask.clear();
    this->setCursor(Qt::BusyCursor);//后台运行状态
    ui->Qury_Button->setEnabled(false);

    slecetSAP_Log slecetSAP_LogI;
    if(ui->taskStatusBox->currentText().trimmed()=="全部状态"){
        slecetSAP_LogI.taskStatus_s=0;
        slecetSAP_LogI.taskStatus_e=100;
    }if(ui->taskStatusBox->currentText().trimmed()=="等待执行"){
         slecetSAP_LogI.taskStatus_s=0;
         slecetSAP_LogI.taskStatus_e=0;
    }if(ui->taskStatusBox->currentText().trimmed()=="正在运输"){
        slecetSAP_LogI.taskStatus_s=1;
        slecetSAP_LogI.taskStatus_e=99;
    }if(ui->taskStatusBox->currentText().trimmed()=="已完成"){
        slecetSAP_LogI.taskStatus_s=100;
        slecetSAP_LogI.taskStatus_s=100;
    }

    if(ui->taskTypeBox->currentIndex()!=0){
        if(ui->taskTypeBox->currentText().trimmed()=="入库任务"){
            slecetSAP_LogI.taskType="IN";
        }if(ui->taskTypeBox->currentText().trimmed()=="出库任务"){
            slecetSAP_LogI.taskType="OUT";
        }if(ui->taskTypeBox->currentText().trimmed()=="移库任务"){
            slecetSAP_LogI.taskType="MOVE";
        }if(ui->taskTypeBox->currentText().trimmed()=="返空料框"){
            slecetSAP_LogI.taskType="Empty";
        }
    }

    int labelNoNumber=ui->LabelNolineEdit->document()->lineCount(); //读取TextEdit里的行数
    for(int n=0;n<labelNoNumber;n++){
         QString labelNo=ui->LabelNolineEdit->toPlainText().section('\n',n-labelNoNumber,n-labelNoNumber,QString::SectionSkipEmpty); //取得每行（以换行符进行换行）
         if(!slecetSAP_LogI.labelNoMap.contains(labelNo) && labelNo!=""){
             slecetSAP_LogI.labelNoMap.insert(labelNo,labelNo);
         }
    }

    int CodeNumber=ui->GetorderId->document()->lineCount(); //读取TextEdit里的行数
    for(int n=0;n<CodeNumber;n++){
         QString material=ui->GetorderId->toPlainText().section('\n',n-CodeNumber,n-CodeNumber,QString::SectionSkipEmpty); //取得每行（以换行符进行换行）
         if(!slecetSAP_LogI.materialMap.contains(material) && material!=""){
             slecetSAP_LogI.materialMap.insert(material,material);
         }
    }

    slecetSAP_LogI.QDateTimeS=ui->Selete_DateEdit->dateTime();
    slecetSAP_LogI.QDateTimeE=ui->Selete_DateEdit_2->dateTime();
    seletSAPExcelInfoTask=queryServer::getInstance()->querySAPExcelInfoList(slecetSAP_LogI);

    tableWidget_Show();//tableWidget 更新显示

    ui->Qury_Button->setEnabled(true);
    this->setCursor(Qt::ArrowCursor);//正常状态
}

void taskManager::on_Cancel_Button_clicked()
{
    SAPExcelInfo SAPExcelInfoI;
    seletSAPExcelInfoI=SAPExcelInfoI;
//    QMap<int, SAPExcelInfo>::iterator iter= seletSAPExcelInfoTask.begin();
//    while (iter!=seletSAPExcelInfoTask.end()){
//        iter.value().checked=0;
//        ++iter;
//    }
    seletSAPExcelInfoTask.clear();
    tableWidget_Show();//tableWidget 更新显示
}

void taskManager::on_unbundle_clicked()
{
    if(seletSAPExcelInfoI.taskId!=""){
        ESS_Request ESS_RequestI;
        ESS_RequestI.actionId="action7";
        ESS_RequestI.positionCode=ui->bundleBox->currentText().trimmed();
        ESS_RequestI.containerCode=ui->containerCode->text().trimmed();

        seletSAPExcelInfoI.pickDesc_s=ui->bundleBox->currentText().trimmed();
        seletSAPExcelInfoI.containerCode=ui->containerCode->text().trimmed();
        seletSAPExcelInfoI.podIdDesc=ui->shelfBindesc->text().trimmed();
        seletSAPExcelInfoI.shelfBindesc=ui->shelfBindesc_e->text().trimmed();

        ESS_RequestI=ESS_Single::getInstance()->setESS_RequestI(seletSAPExcelInfoI,ESS_RequestI,ESS_RequestI.actionId);
        if(ESS_RequestI.pathId!=0){//容器离场
            sapMsgInterface::getInstance()->taskCodes_actionId(ESS_RequestI.iKey,ESS_RequestI,"action7",ESS_RequestI.pathId);
        }
        qDebug()<<" 手动解绑-->SAPTaskIndex:"<<seletSAPExcelInfoI.SAPTaskIndex
               <<" containerCode:"<<ESS_RequestI.containerCode<<" positionCode:"<<ESS_RequestI.positionCode;
        currentlabelMap.insert(ESS_RequestI.iKey,ESS_RequestI.containerCode);

        on_Cancel_Button_clicked();
        ui->lineEdit_table->setText("手动重新绑定-->:"+ESS_RequestI.positionCode+" "+ESS_RequestI.containerCode+"  时间:"+QDateTime::currentDateTime().toString("hh:mm:ss"));
    }else{
        ui->lineEdit_table->setText("注释:请选择入库选项 "+QDateTime::currentDateTime().toString());
    }

}

void taskManager::on_rebundle_clicked()
{
    if(seletSAPExcelInfoI.taskId!=""){
        ESS_Request ESS_RequestI;
        ESS_RequestI.actionId="action6";
        ESS_RequestI.positionCode=ui->bundleBox->currentText().trimmed();
        ESS_RequestI.containerCode=ui->containerCode->text().trimmed();

        seletSAPExcelInfoI.pickDesc_s=ui->bundleBox->currentText().trimmed();
        seletSAPExcelInfoI.containerCode=ui->containerCode->text().trimmed();
        seletSAPExcelInfoI.podIdDesc=ui->shelfBindesc->text().trimmed();
        seletSAPExcelInfoI.shelfBindesc=ui->shelfBindesc_e->text().trimmed();

        ESS_RequestI=ESS_Single::getInstance()->setESS_RequestI(seletSAPExcelInfoI,ESS_RequestI,ESS_RequestI.actionId);
        if(ESS_RequestI.pathId!=0){
            sapMsgInterface::getInstance()->taskCodes_actionId(ESS_RequestI.iKey,ESS_RequestI,"action6",ESS_RequestI.pathId);
        }
        qDebug()<<" 手动重新绑定-->SAPTaskIndex:"<<seletSAPExcelInfoI.SAPTaskIndex
               <<" containerCode:"<<ESS_RequestI.containerCode<<" positionCode:"<<ESS_RequestI.positionCode;
        currentlabelMap.insert(ESS_RequestI.iKey,ESS_RequestI.containerCode);

        on_Cancel_Button_clicked();
        ui->lineEdit_table->setText("手动重新绑定-->:"+ESS_RequestI.positionCode+" "+ESS_RequestI.containerCode+"  时间:"+QDateTime::currentDateTime().toString("hh:mm:ss"));
    }else{
        ui->lineEdit_table->setText("注释:请选择入库选项 "+QDateTime::currentDateTime().toString());
    }
}

void taskManager::on_unbundle_ess_clicked()
{
    if(seletSAPExcelInfoI.taskId!=""){
        ESS_Request ESS_RequestI;
        ESS_RequestI.actionId="action8";
        ESS_RequestI.positionCode=ui->shelfBindesc_e->text().trimmed();
        ESS_RequestI.containerCode=ui->containerCode->text().trimmed();

        seletSAPExcelInfoI.pickDesc_s=ui->bundleBox->currentText().trimmed();
        seletSAPExcelInfoI.containerCode=ui->containerCode->text().trimmed();
        seletSAPExcelInfoI.podIdDesc=ui->shelfBindesc->text().trimmed();
        seletSAPExcelInfoI.shelfBindesc=ui->shelfBindesc_e->text().trimmed();
        ESS_RequestI=ESS_Single::getInstance()->setESS_RequestI(seletSAPExcelInfoI,ESS_RequestI,ESS_RequestI.actionId);
        if(ESS_RequestI.pathId!=0){
            sapMsgInterface::getInstance()->taskCodes_actionId(ESS_RequestI.iKey,ESS_RequestI,"action8",ESS_RequestI.pathId);
        }
        qDebug()<<" 手动解绑远程库位-->SAPTaskIndex:"<<seletSAPExcelInfoI.SAPTaskIndex
               <<" containerCode:"<<ESS_RequestI.containerCode<<" positionCode:"<<ESS_RequestI.positionCode;
        currentlabelMap.insert(ESS_RequestI.iKey,ESS_RequestI.containerCode);

        on_Cancel_Button_clicked();
        ui->lineEdit_table->setText("手动解绑远程库位-->:"+ESS_RequestI.positionCode+" "+ESS_RequestI.containerCode+"  时间:"+QDateTime::currentDateTime().toString("hh:mm:ss"));
    }else{
        ui->lineEdit_table->setText("注释:请选择入库选项 "+QDateTime::currentDateTime().toString());
    }
}
