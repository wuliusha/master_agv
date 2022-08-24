#include "system_agv.h"
#include "ui_system_agv.h"

system_agv::system_agv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::system_agv)
{
    ui->setupUi(this);
    system_agvInit();          //初始化函数
}

system_agv::~system_agv()
{
    delete ui;
}

void system_agv::system_agvInit()
{
    this->setWindowTitle(QString("AGV—参数"));
    qRegisterMetaType<AGVCurrentTask>("AGVCurrentTask");

    wrexcelprocessItiem =new wrexcelprocess;

    Actionbtns<<ui->query_agvip<<ui->add_agvip<<ui->delete_agvip<<ui->update_agvip
             <<ui->query_LineInfo<<ui->add_LineInfo<<ui->delete_LineInfo<<ui->update_LineInfo
             <<ui->query_rule<<ui->add_rule<<ui->add_rule_2<<ui->delete_rule<<ui->delete_rule_2<<ui->update_rule;

    for(int i=0;i<Actionbtns.length();i++){
        connect(Actionbtns[i],&QPushButton::pressed,this,&system_agv::ON_Pressed);
        connect(Actionbtns[i],&QPushButton::released,this,&system_agv::ON_Released);
    }

    //IconHelper::Instance()->setIcon(ui->detail_Button, 0xf05a, 20);
    table_single::GetInstance()->TableWidgetInit(ui->tableWidget_agv,12,"QHeaderView::section{background-color:rgb(193,205,205);font:12pt '宋体';color: black;};",35,35);
    table_single::GetInstance()->TableWidgetInit(ui->tableWidget_Line,12,"QHeaderView::section{background-color:rgb(193,205,205);font:12pt '宋体';color: black;};",35,35);
    table_single::GetInstance()->TableWidgetInit(ui->tableWidget_rule,12,"QHeaderView::section{background-color:rgb(193,205,205);font:12pt '宋体';color: black;};",35,35);

    connect(ui->tableWidget_agv,&QTableWidget::cellClicked,this,&system_agv::SlotsetCurrentItem_agv);           //AGV参数配置
    connect(ui->tableWidget_Line,&QTableWidget::cellClicked,this,&system_agv::SlotsetCurrentItem_Line);         //路线信息
    connect(ui->tableWidget_rule,&QTableWidget::cellClicked,this,&system_agv::SlotsetCurrentItem_rule);         //路线规则

    //ui->tabWidget->setLayoutDirection(Qt::RightToLeft);

    QLabel *label = new QLabel;
    ui->tabWidget->setCornerWidget(label,Qt::TopLeftCorner);
    label->setText("基本参数配置");
}

//AGV参数配置
void system_agv::SlotsetCurrentItem_agv(int row, int column)
{
    if(!AGVCurrentTaskMap.isEmpty()){
        QString AGVIP=ui->tableWidget_agv->item(row,1)->text().trimmed();
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
            ++iter;
        }
        if(column<2){
            TableWidget_show_agv();
        }
    }

}

//路线信息
void system_agv::SlotsetCurrentItem_Line(int row, int column)
{
    if(!agvSubTaskListinit.isEmpty()){
        int TaskId=ui->tableWidget_Line->item(row,1)->text().trimmed().toInt();
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
            ++iter;
        }
        if(column<2){
            TableWidget_show_Line();
        }
    }
}

//路线规则
void system_agv::SlotsetCurrentItem_rule(int row, int column)
{
    if(!currentAssistRouteI.mianRouteMap.isEmpty()){
        int TaskId=ui->tableWidget_rule->item(row,2)->text().trimmed().toInt();
        QMap<QString, mianRoute>::iterator iter= currentAssistRouteI.mianRouteMap.begin();
        while (iter !=currentAssistRouteI.mianRouteMap.end()) {
            if(TaskId==iter.value().TaskId && iter.value().checked==0){
                iter.value().checked=1;
            }else {
                iter.value().checked=0;
            }
            ++iter;
        }
        TableWidget_show_rule(currentAssistRouteI);                        //显示当前路线信息
    }
}

void system_agv::TableWidget_show_agv()
{
    ui->tableWidget_agv->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    QList<RW_Excel> ExcelList=TableWidget_agv(AGVCurrentTaskMap);
    QStringList comBoxlist;//comBoxlist<<"0"<<"-1";
    table_single::GetInstance()->UP_TableWidget(ui->tableWidget_agv,ExcelList,comBoxlist,0);
    if(ExcelList.isEmpty()){
        ui->tableWidget_agv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
        return;
    }
    ui->tableWidget_agv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
    ui->tableWidget_agv->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    ui->tableWidget_agv->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->tableWidget_agv->horizontalHeader()->setSectionResizeMode(6,QHeaderView::ResizeToContents);
}

QList<RW_Excel> system_agv::TableWidget_agv(QMap<QString, AGVCurrentTask> AGVCurrentTaskMap)
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

        ++iter;
    }

    return ExcelList;
}

void system_agv::TableWidget_show_Line()
{
    ui->tableWidget_Line->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    QList<RW_Excel> ExcelList=TableWidget_Line(agvSubTaskListinit);
    QStringList comBoxlist;
    table_single::GetInstance()->UP_TableWidget(ui->tableWidget_Line,ExcelList,comBoxlist,0);
    if(ExcelList.isEmpty()){
        ui->tableWidget_Line->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
        return;
    }
    ui->tableWidget_Line->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
    //ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);

}

QList<RW_Excel> system_agv::TableWidget_Line(QMap<int, agvSubTask> SubTaskListinit)
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
            ++iter;
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

void system_agv::TableWidget_show_rule(assistRoute assistRouteI)
{
    ui->keyId->setText(assistRouteI.keyId);
    ui->assistRoute_S->setText(assistRouteI.assistRoute_S);
    ui->assistPoint_S->setText(QString::number(assistRouteI.assistPoint_S));
    ui->assistRoute_E->setText(assistRouteI.assistRoute_E);
    ui->assistPoint_E->setText(QString::number(assistRouteI.assistPoint_E));

    ui->tableWidget_rule->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    QList<RW_Excel> ExcelList=TableWidget_rule(assistRouteI.mianRouteMap);
    QStringList comBoxlist;
    table_single::GetInstance()->UP_TableWidget(ui->tableWidget_rule,ExcelList,comBoxlist,0);
    if(ExcelList.isEmpty()){
        ui->tableWidget_rule->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
        return;
    }
    ui->tableWidget_rule->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
    ui->tableWidget_rule->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);

}

QList<RW_Excel> system_agv::TableWidget_rule(QMap<QString, mianRoute> mianRouteMap)
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
        ++iter;
    }
    return ExcelList;
}

assistRoute system_agv::getAssistRouteI()
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

mianRoute system_agv::getmianRoute()
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

void system_agv::on_query_agvip_clicked()
{
    QString AGVIP=ui->AGVIP->text().trimmed();
    AGVCurrentTaskMap=query_Single::GetInstance()->query_AGVCurrentTask(AGVIP);//查找当前AGV信息
    TableWidget_show_agv();
}

//创建AGV--项
void system_agv::on_add_agvip_clicked()
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
            on_query_agvip_clicked();//查询AGV小车信息
        }else{

        }
    }

}

//删除AGV--项
void system_agv::on_delete_agvip_clicked()
{
    if(!AGVCurrentTaskMap.isEmpty()){
        if(AGVCurrentTaskI.AGVIP!=""){
            query_Single::GetInstance()->AGVCurrentTask_Delete(AGVCurrentTaskI.AGVIP); //删除 AGV信息
            on_query_agvip_clicked();//查询AGV小车信息
        }
    }
}

//更新AGV参数信息
void system_agv::on_update_agvip_clicked()
{
    if(!AGVCurrentTaskMap.isEmpty()){
        if(AGVCurrentTaskI.AGVIP!=""){
            AGVCurrentTaskI.AGVId=ui->tableWidget_agv->item(AGVCurrentTaskI.row,0)->text().trimmed().toInt();
            AGVCurrentTaskI.enable=ui->tableWidget_agv->item(AGVCurrentTaskI.row,2)->text().trimmed().toInt();
            AGVCurrentTaskI.AGVType=ui->tableWidget_agv->item(AGVCurrentTaskI.row,3)->text().trimmed().toInt();
            AGVCurrentTaskI.floornum=ui->tableWidget_agv->item(AGVCurrentTaskI.row,4)->text().trimmed().toInt();
            AGVCurrentTaskI.waitPoint=ui->tableWidget_agv->item(AGVCurrentTaskI.row,5)->text().trimmed().toInt();
            AGVCurrentTaskI.chargeIP=ui->tableWidget_agv->item(AGVCurrentTaskI.row,6)->text().trimmed();
            AGVCurrentTaskI.ChargePoint=ui->tableWidget_agv->item(AGVCurrentTaskI.row,7)->text().trimmed().toInt();
            AGVCurrentTaskI.ChargeWait=ui->tableWidget_agv->item(AGVCurrentTaskI.row,8)->text().trimmed().toInt();
            AGVCurrentTaskI.MoveAnage=ui->tableWidget_agv->item(AGVCurrentTaskI.row,9)->text().trimmed().toInt();

            QMap<QString, AGVCurrentTask> AGVCurrentTaskMap_;
            AGVCurrentTaskMap_.insert(AGVCurrentTaskI.AGVIP,AGVCurrentTaskI);
            query_Single::GetInstance()->AGVCurrentTask_update(AGVCurrentTaskMap_); //更新 AGV信息
            on_query_agvip_clicked();//查询AGV小车信息
        }

    }
}


/************   路线信息   ***************/
void system_agv::on_query_LineInfo_clicked()
{
    if(!ui->currentLine->text().trimmed().isNull()){
        int SubTaskType=0;
        QString RouteName=ui->currentLine->text().trimmed();
        if(ui->lineType->currentText().trimmed()=="反向"){SubTaskType=-1;}
        agvSubTaskListinit=query_Single::GetInstance()->query_agvSubTaskListinit(RouteName,SubTaskType);
        TableWidget_show_Line();
    }
}

//添加路径二维码信息
void system_agv::on_add_LineInfo_clicked()
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
            ++iter;
        }
        agvSubTaskListinit=agvSubTaskListinit_;
        currentAgvSubTask.TaskId++;
        agvSubTaskListinit.insert(currentAgvSubTask.TaskId,currentAgvSubTask);
        TableWidget_show_Line();
    }
}

//删除路径二维码信息
void system_agv::on_delete_LineInfo_clicked()
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
                ++iter;
            }
            agvSubTaskListinit=agvSubTaskListinit_;
        }
        TableWidget_show_Line();
    }
}

//更新路径二维码信息
void system_agv::on_update_LineInfo_clicked()
{
    if(!ui->currentLine->text().trimmed().isNull()){
       qDebug()<<currentAgvSubTask.TaskId<<currentAgvSubTask.row<<currentAgvSubTask.RouteName;
        if(currentAgvSubTask.TaskId>0){
            int TaskId =currentAgvSubTask.TaskId-1;
            currentAgvSubTask.Point=quint8(ui->tableWidget_Line->item(TaskId,2)->text().trimmed().toInt());                            //AGV基本任务 起始点
            currentAgvSubTask.NextPoint=quint8(ui->tableWidget_Line->item(TaskId,3)->text().trimmed().toInt());                        //AGV基本任务 下一点
            currentAgvSubTask.NextPointDistance=quint8(ui->tableWidget_Line->item(TaskId,4)->text().trimmed().toInt());                //AGV基本任务 下一点距离
            currentAgvSubTask.AGVSpeed=quint8(ui->tableWidget_Line->item(TaskId,5)->text().trimmed().toInt());                         //AGV基本任务 速度
            currentAgvSubTask.RotaryLowBarrierInstruction=quint8(ui->tableWidget_Line->item(TaskId,6)->text().trimmed().toInt());      //AGV基本任务 顶盘降下时 激光方案（无货架）
            currentAgvSubTask.RotaryHighBarrierInstruction=quint8(ui->tableWidget_Line->item(TaskId,7)->text().trimmed().toInt());     //AGV基本任务 顶盘举升时 激光方案（有货架）
            currentAgvSubTask.postureAngle=quint8(ui->tableWidget_Line->item(TaskId,8)->text().trimmed().toInt());                     //AGV基本任务 姿态角度
            currentAgvSubTask.AGVMoveAnage=quint8(ui->tableWidget_Line->item(TaskId,9)->text().trimmed().toInt());                     //AGV基本任务 移动角度
            currentAgvSubTask.AGVRotaryAngle=quint8(ui->tableWidget_Line->item(TaskId,10)->text().trimmed().toInt());                  //AGV基本任务 转盘角度
            currentAgvSubTask.SubTaskType =ui->tableWidget_Line->item(TaskId,11)->text().trimmed().toInt();                            //AGV基本任务 基本任务类型  0正向  -1反向

            agvSubTaskListinit.insert(currentAgvSubTask.TaskId,currentAgvSubTask);
        }

        int SubTaskType=0;
        QString RouteName=ui->currentLine->text().trimmed();
        if(ui->lineType->currentText().trimmed()=="反向"){SubTaskType=-1;}
        query_Single::GetInstance()->agvSubTask_Delete(RouteName,SubTaskType);              //删除路线信息
        query_Single::GetInstance()->SubTaskListinit_insert(agvSubTaskListinit);            //更新路线 信息 写入数据库

        TableWidget_show_Line();
    }

}

//导入路线二维码信息
void system_agv::on_Alter_LineInfo_clicked()
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
                ++iter;
            }
            query_Single::GetInstance()->SubTaskListinit_insert(agvSubTaskListinit_);
            query_Single::GetInstance()->SubTaskListinit_insert(agvSubTaskListinit_0);
        }
        agvSubTaskListinit.clear();
    }

}


/************   路线规则   ***************/
void system_agv::on_query_rule_clicked()
{
    currentAssistRouteI=query_Single::GetInstance()->queryAssistRoute(ui->keyId->text().trimmed());
    TableWidget_show_rule(currentAssistRouteI);                 //显示当前路线信息
}

//创建路径规则--项
void system_agv::on_add_rule_clicked()
{
    if(!ui->keyId->text().trimmed().isEmpty()){
        currentAssistRouteI=query_Single::GetInstance()->queryAssistRoute(ui->keyId->text().trimmed());
        if(currentAssistRouteI.keyId==""){                                          //不存在则创建
            assistRoute assistRouteI=getAssistRouteI();                        //创建路线信息
            if(assistRouteI.keyId!=""){
                query_Single::GetInstance()->assistRoute_Insert(assistRouteI);      //创建路线信息 写入数据库
                on_query_rule_clicked();                                          //根据路线编号 查找对应路线信息
            }
        }
    }else{
        queryServer::getInstance()->SetMessagebox("keyId 不能为空");
    }
    TableWidget_show_rule(currentAssistRouteI);                 //显示当前路线信息
}

//删除路径规则--项
void system_agv::on_delete_rule_clicked()
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
    TableWidget_show_rule(currentAssistRouteI);                          //显示当前路线信息
}

//添加路线编号 ---途经的子路线信息
void system_agv::on_add_rule_2_clicked()
{
    if(currentAssistRouteI.keyId!=""){
        mianRoute mianRouteI=getmianRoute();//创建途经路线信息
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
                ++iter;
            }
        }

        if(mianRouteI.keyId!="" && !currentAssistRouteI.mianRouteMap.contains(mianRouteI.RouteName)){
            currentAssistRouteI.mianRouteMap.insert(mianRouteI.RouteName,mianRouteI);
        }
        TableWidget_show_rule(currentAssistRouteI);                   //显示当前路线信息
    }

}

//删除路线编号 ---途经的子路线信息
void system_agv::on_delete_rule_2_clicked()
{
    if(!currentAssistRouteI.mianRouteMap.isEmpty() && currentMianRoute.TaskId!=0){
        QMap<QString,mianRoute>::iterator iter=currentAssistRouteI.mianRouteMap.begin();
        while (iter!=currentAssistRouteI.mianRouteMap.end()) {
            if(iter.value().TaskId==currentMianRoute.TaskId){
                currentAssistRouteI.mianRouteMap.remove(currentMianRoute.RouteName);
                if(currentAssistRouteI.mianRouteMap.isEmpty()){
                    TableWidget_show_rule(currentAssistRouteI);                   //显示当前路线信息
                    return;
                }
            }
            ++iter;
        }

        if(!currentAssistRouteI.mianRouteMap.isEmpty()){
            QMap<QString,mianRoute>::iterator iter=currentAssistRouteI.mianRouteMap.begin();
            while (iter!=currentAssistRouteI.mianRouteMap.end()) {
                if(iter.value().TaskId>currentMianRoute.TaskId){
                    iter.value().TaskId--;
                }
                ++iter;
            }
        }
        TableWidget_show_rule(currentAssistRouteI);                   //显示当前路线信息
    }

}

//把路线规则信息提交到数据库
void system_agv::on_update_rule_clicked()
{
    if(currentAssistRouteI.keyId!=""){
        if(!currentAssistRouteI.mianRouteMap.isEmpty()){
            query_Single::GetInstance()->mianRouteMap_Delete(currentAssistRouteI.keyId);            //删除途经路线信息
            query_Single::GetInstance()->mianRouteMap_Insert(currentAssistRouteI.mianRouteMap);     //创建路线的途经路线 信息 写入数据库
        }
        on_query_rule_clicked();                                                                  //根据路线编号 查找对应路线信息
    }
}

void system_agv::ON_Pressed()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    Instance::GetInstance()->SetButton_pressed(Button,"background-color: rgb(85,255,127);color:#ffffff;color: white;  border: 2px groove gray;\
                                               border-radius:15px;border-style: outset");
}

void system_agv::ON_Released()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    Instance::GetInstance()->SetButton_released(Button,"color: white;border: 2px groove gray;border-radius:15px;border:none;background-color: rgb(0, 166, 172);");
}
