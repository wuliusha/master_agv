#include "threadquery.h"
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase)

threadQuery::threadQuery(QObject *parent) : QObject(parent)
{
    threadTimer = new QTimer(this);
    connect(threadTimer,&QTimer::timeout,this,&threadQuery::threadQueryTimer);
    threadTimer->start(600);
}

void threadQuery::threadQueryTimer()
{
    QElapsedTimer timer;timer.start();
    if(!Servercountbool){return;}
    threadServercount++;

    if(threadServercount>3000){threadServercount=0;}
    if(timer.elapsed()>1000){
        qDebug()<<"Query read data cost:"<<timer.elapsed()<<"ms  "<<QDateTime::currentDateTime().toString("hh:mm ss");timer.restart();
    }
}


bool threadQuery::setshelfBinInfo_Status(QMap<QString,shelfBinInfo>shelfBinInfoMap)
{
    bool update=true;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    QMap<QString,shelfBinInfo>::const_iterator iter=shelfBinInfoMap.begin();
    while (iter!=shelfBinInfoMap.end()) {
        if(iter!=nullptr){
            sqlQuery.prepare("UPDATE [dbo].[shelfInfo] SET [status]=:status,[containerIndex]=:containerIndex,"
                             "[containerCode]=:containerCode,[LabelNo]=:LabelNo "
                             "WHERE ([shelfBindesc]=:shelfBindesc);");
            sqlQuery.addBindValue(iter.value().status);
            sqlQuery.addBindValue(iter.value().containerIndex);
            sqlQuery.addBindValue(iter.value().containerCode);
            sqlQuery.addBindValue(iter.value().LabelNo);
            sqlQuery.addBindValue(iter.value().shelfBindesc);
            if(sqlQuery.exec()){
                qDebug()<<"shelfInfo S"<<iter.value().shelfBinIndex<<iter.value().shelfBindesc<<iter.value().containerCode<<iter.value().status;
            }else {
                update= false;
                qDebug()<<"shelfInfo E"<<iter.value().shelfBinIndex<<iter.value().shelfBindesc<<iter.value().containerCode<<iter.value().status;
            }
        }else{
             return false;
        }
        iter++;
    }

    return update;
}

bool threadQuery::setStationInfo_Status(QMap<int,StationInfo>StationInfoMap)
{
    bool update=true;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    QMap<int,StationInfo>::const_iterator iter=StationInfoMap.begin();
    while (iter!=StationInfoMap.end()) {
        if(iter!=nullptr){
            sqlQuery.prepare("UPDATE TOP(1) [dbo].[StationInfo] SET [action]=:action,"
                             "[taskStatus]=:taskStatus,[containerCode]=:containerCode,"
                             "[TaskIndexListdesc]=:TaskIndexListdesc,[updateTimer]=:updateTimer "
                             "WHERE ([StationId]=:StationId);");

            sqlQuery.addBindValue(iter.value().action);
            sqlQuery.addBindValue(iter.value().taskStatus);
            sqlQuery.addBindValue(iter.value().containerCode);
            sqlQuery.addBindValue(iter.value().TaskIndexListdesc);
            sqlQuery.addBindValue(QDateTime::currentDateTime());
            sqlQuery.addBindValue(iter.value().StationId);

            if(sqlQuery.exec()){
                qDebug()<<"set StationInfo S"<<iter.value().StationId<<iter.value().action<<iter.value().containerCode<<iter.value().TaskIndexListdesc;
            }else {
                update= false;
                qDebug()<<"set StationInfo E"<<iter.value().StationId<<iter.value().action<<iter.value().containerCode<<iter.value().TaskIndexListdesc;
            }

        }else{
             return false;
        }
        iter++;
    }

    return update;
}

bool threadQuery::setmaterialShelfbinMap(materialShelfbin materialShelfbinI,QString  actionType)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    if(actionType=="update"){
        sqlQuery.prepare("UPDATE [dbo].[materialShelfbinMap] SET [status]=:status,"
                         "[lastCheckTimer]=:lastCheckTimer "
                         "WHERE ([containerIndex]=:containerIndex);");
        sqlQuery.addBindValue(materialShelfbinI.status);
        sqlQuery.addBindValue(QDateTime::currentDateTime());
        sqlQuery.addBindValue(materialShelfbinI.containerIndex);
        if(sqlQuery.exec()){
            return true;
        }else {
            return false;
        }
    }if(actionType=="delete"){
        sqlQuery.prepare(QString("DELETE FROM materialShelfbinMap WHERE [containerIndex]=:containerIndex"));
        sqlQuery.addBindValue(materialShelfbinI.containerIndex);
        if(sqlQuery.exec()){
            return true;
        }else {
            return false;
        }
    }
    return true;
}

//更新接升降机状态信息
bool threadQuery::setLiftCodeMap_Status(QMap<QString, LiftCode> LiftCodeMap)
{
    bool update=true;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    QMap<QString, LiftCode>::const_iterator iter=LiftCodeMap.begin();
    while (iter!=LiftCodeMap.end()) {
        if(iter!=nullptr){
            sqlQuery.prepare("UPDATE TOP(1) [dbo].[LiftTask] SET [Liftstatus]=:Liftstatus,"
                             "[status]=:status,[SAPTaskIndex]=:SAPTaskIndex,"
                             "[containerCode]=:containerCode "
                             "WHERE ([codeDesc]=:codeDesc);");

            sqlQuery.addBindValue(iter.value().Liftstatus);             //升降机感应器状态 (IN-D100 D103 D105:1可放料,2-3去X楼) (OUT-D101 D102 D104: 1可取料,2取料完成)
            sqlQuery.addBindValue(iter.value().status);                 //任务锁定状态:0空闲  1 锁定  2到达 0空闲
            sqlQuery.addBindValue(iter.value().SAPTaskIndex);           //任务索引 唯一值
            sqlQuery.addBindValue(iter.value().containerCode);          //容器编码 (即胶箱编码) ->唯一
            sqlQuery.addBindValue(iter.value().codeDesc);               //升降机接驳台命名
            if(sqlQuery.exec()){
                qDebug()<<"set codeDesc S"<<iter.value().codeDesc<<iter.value().Liftstatus<<iter.value().status<<iter.value().SAPTaskIndex;
            }else {
                update= false;
                qDebug()<<"set codeDesc E"<<iter.value().codeDesc<<iter.value().Liftstatus<<iter.value().status<<iter.value().SAPTaskIndex;
            }

        }else{
             return false;
        }
        iter++;
    }

    return update;
}

//更新AGV状态信息
bool threadQuery::setAGVCurrentTaskMap_Status(QMap<QString, AGVCurrentTask> AGVCurrentTaskMap)
{
    bool update=true;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    QMap<QString, AGVCurrentTask>::const_iterator iter=AGVCurrentTaskMap.begin();
    while (iter!=AGVCurrentTaskMap.end()) {
        if(iter!=nullptr){

            sqlQuery.prepare("UPDATE [dbo].[AGVCurrentTask] SET [Currentdestpoint]=:Currentdestpoint,"
                             "[destpoint]=:destpoint,[Nextdestpoint]=:Nextdestpoint,[waitdestpoint]=:waitdestpoint,"
                             "[Action_agv]=:Action_agv,[Action_ess]=:Action_ess,[Action_all]=:Action_all,"
                             "[actionType]=:actionType,[taskId]=:taskId,[lastTaskId]=:lastTaskId,[taskType]=:taskType,"
                             "[SAPTaskIndex]=:SAPTaskIndex,[containerCode]=:containerCode "
                             "WHERE ([AGVIP]=:AGVIP);");

            sqlQuery.addBindValue(iter.value().Currentdestpoint);       //当前目标二维码
            sqlQuery.addBindValue(iter.value().destpoint);              //第一个目标二维码
            sqlQuery.addBindValue(iter.value().Nextdestpoint);          //下一个目标二维码
            sqlQuery.addBindValue(iter.value().waitdestpoint);          //目标点等待点二维码
            sqlQuery.addBindValue(iter.value().Action_agv);             //二维码带举升动作
            sqlQuery.addBindValue(iter.value().Action_ess);             //夹包机器人
            sqlQuery.addBindValue(iter.value().Action_all);             //总动作计数
            sqlQuery.addBindValue(iter.value().actionType);             //动作类型 0到达站点不需要返回  1到达站点倒计时结束后返回
            sqlQuery.addBindValue(iter.value().actionTimerCount);       //倒计时 计数
            sqlQuery.addBindValue(iter.value().taskId);                 //唯一识别号
            sqlQuery.addBindValue(iter.value().lastTaskId);             //上一个任务--唯一识别号

            sqlQuery.addBindValue(iter.value().taskType);               //任务类型 IN入库  OUT出库
            sqlQuery.addBindValue(iter.value().SAPTaskIndex);           //任务索引 唯一值
            sqlQuery.addBindValue(iter.value().containerCode);          //容器编码 (即胶箱编码) ->唯一
            sqlQuery.addBindValue(iter.value().AGVIP);                  //容器编码 (即胶箱编码) ->唯一

            if(sqlQuery.exec()){
                qDebug()<<"set codeDesc S---->AGVIP:"<<iter.value().AGVIP<<" Action_agv:"<<iter.value().Action_agv
                       <<" taskType:"<<iter.value().taskType<<" SAPTaskIndex:"<<iter.value().SAPTaskIndex;
            }else {
                update= false;
                qDebug()<<"set codeDesc ---->AGVIP:"<<iter.value().AGVIP<<" Action_agv:"<<iter.value().Action_agv
                       <<" taskType:"<<iter.value().taskType<<" SAPTaskIndex:"<<iter.value().SAPTaskIndex;
            }
        }else{
             return false;
        }
        iter++;
    }

    return update;
}

//*************************出入库，查仓日志部分*****************************//

QMap<int, record_log> threadQuery::queryRecord_log(slecetSAP_Log slecetSAP_LogI)
{
    qDebug()<<"queryRecord_log ->"<<slecetSAP_LogI.taskStatus_s<<slecetSAP_LogI.taskStatus_e
           <<slecetSAP_LogI.operaterIndex<<slecetSAP_LogI.labelNoMap.size()<<slecetSAP_LogI.materialMap.size();
    QMap<int, record_log> record_logMap;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.setForwardOnly(true);

    if(!slecetSAP_LogI.labelNoMap.isEmpty() || !slecetSAP_LogI.materialMap.isEmpty()){
        QMap<QString,QString>selectMap;int action=0;//0标签号 1 件号
        if(!slecetSAP_LogI.labelNoMap.isEmpty()){
            selectMap=slecetSAP_LogI.labelNoMap;
        }else if(!slecetSAP_LogI.materialMap.isEmpty()) {
            selectMap=slecetSAP_LogI.materialMap;action=1;
        }
        QMap<QString,QString>::iterator iter =selectMap.begin();
        while(iter !=selectMap.end()){
            if(action==0){//标签号
                sqlQuery.prepare("select * from record_log "
                                 "where LabelNo=:LabelNo and Time >=:Time and Time <=:Time;");
                sqlQuery.addBindValue(iter.value());
                sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeS);
                sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeE);
            }else {
                sqlQuery.prepare("select * from record_log "
                                 "where Material=:Material and Time >=:Time and Time <=:Time;");
                sqlQuery.addBindValue(iter.value());
                sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeS);
                sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeE);
            }

            if(sqlQuery.exec())
            {
                while(sqlQuery.next())
                {
                    record_log record_logI;
                    record_logI.logId=sqlQuery.value("logId").toInt();//索引 唯一值
                    if(record_logMap.contains(record_logI.logId)){
                        continue;
                    }
                    record_logI.TypeId =sqlQuery.value("TypeId").toInt();
                    record_logI.LabelNo=sqlQuery.value("LabelNo").toString();     //标签
                    record_logI.Material=sqlQuery.value("Material").toString();    //物料件号
                    record_logI.shelfBinIndex=sqlQuery.value("shelfBinIndex").toInt();    //架位 Bin index
                    record_logI.shelfBindesc=sqlQuery.value("shelfBindesc").toString();   //架位号   desc
                    record_logI.store=sqlQuery.value("store").toString();          //仓号
                    record_logI.batch=sqlQuery.value("batch").toString();          //批次
                    record_logI.Unit=sqlQuery.value("Unit").toString();           //单位
                    record_logI.sapQty=sqlQuery.value("sapQty").toDouble();          //贴纸数量
                    record_logI.readlQty=sqlQuery.value("readlQty").toDouble();        //实际数量
                    record_logI.UserNumber=sqlQuery.value("UserNumber").toString();     //操作员
                    record_logI.taskType=sqlQuery.value("taskType").toString();       //任务类型  1出库  2入库 3盘点 4查仓 5改位入库
                    record_logI.errorTypeId=sqlQuery.value("errorTypeId").toInt();       //错误类型.
                    record_logI.errormassega=sqlQuery.value("errormassega").toString();   //错误注释
                    record_logI.Time=sqlQuery.value("Time").toDateTime();         //时间
                    record_logI.nowDate=sqlQuery.value("nowDate").toString();        //日期

                    record_logI.base_weigh=sqlQuery.value("base_weigh").toDouble();//SAP单个数量 的重量 kg
                    record_logI.WeighType=sqlQuery.value("WeighType").toString();//称重类型   称重  计数
                    record_logI.allWeigh=sqlQuery.value("allWeigh").toDouble();//称出总重   (kg)
                    record_logI.weigh_base=sqlQuery.value("weigh_base").toDouble();//称出单个重量
                    record_logI.weigh_pcs=sqlQuery.value("weigh_pcs").toDouble();//计数的数量
                    record_logI.IssueType=sqlQuery.value("IssueType").toString();//发料类型  344 LM DN SL
                    record_logI.LabelType=sqlQuery.value("LabelType").toString();//贴纸类型 N KT
                    record_logI.operaterIndex=sqlQuery.value("operaterIndex").toInt();//操作台编号
                    record_logI.pickType=sqlQuery.value("pickType").toString();
                    record_logI.creatTime=sqlQuery.value("creatTime").toString();

                    if(!record_logMap.contains(record_logI.logId)){
                        record_logMap.insert(record_logI.logId,record_logI);
                        //qDebug()<<"query record_log S0"<<record_logI.LabelNo<<record_logI.Material<<record_logI.readlQty;
                    }
                }
            }else {
                qDebug()<<"query record_log E0"<<sqlQuery.record();
            }

            iter++;
        }

    }else {

        if(slecetSAP_LogI.operaterIndex!=0){
            sqlQuery.prepare("select * from record_log "
                             "where operaterIndex=:operaterIndex and Time >=:Time and Time <=:Time;");
            sqlQuery.addBindValue(slecetSAP_LogI.operaterIndex);
            sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeS);
            sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeE);

        }else if(slecetSAP_LogI.taskType!=0){
            sqlQuery.prepare("select * from record_log "
                             "where TypeId=:TypeId and Time >=:Time and Time <=:Time;");
            sqlQuery.addBindValue(slecetSAP_LogI.taskType);
            sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeS);
            sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeE);
        }else {
            sqlQuery.prepare("select * from record_log "
                             "where Time >=:Time and Time <=:Time;");
            sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeS);
            sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeE);
        }


        if(sqlQuery.exec())
        {
            while(sqlQuery.next())
            {
                record_log record_logI;
                record_logI.logId=sqlQuery.value("logId").toInt();//索引 唯一值
                if(record_logMap.contains(record_logI.logId)){
                    continue;
                }
                record_logI.TypeId =sqlQuery.value("TypeId").toInt();
                record_logI.LabelNo=sqlQuery.value("LabelNo").toString();     //标签
                record_logI.Material=sqlQuery.value("Material").toString();    //物料件号
                record_logI.shelfBinIndex=sqlQuery.value("shelfBinIndex").toInt();    //架位 Bin index
                record_logI.shelfBindesc=sqlQuery.value("shelfBindesc").toString();   //架位号   desc
                record_logI.store=sqlQuery.value("store").toString();          //仓号
                record_logI.batch=sqlQuery.value("batch").toString();          //批次
                record_logI.Unit=sqlQuery.value("Unit").toString();           //单位
                record_logI.sapQty=sqlQuery.value("sapQty").toDouble();          //贴纸数量
                record_logI.readlQty=sqlQuery.value("readlQty").toDouble();        //实际数量
                record_logI.UserNumber=sqlQuery.value("UserNumber").toString();     //操作员
                record_logI.taskType=sqlQuery.value("taskType").toString();       //任务类型  1出库  2入库 3盘点 4查仓 5改位入库
                record_logI.errorTypeId=sqlQuery.value("errorTypeId").toInt();       //错误类型.
                record_logI.errormassega=sqlQuery.value("errormassega").toString();   //错误注释
                record_logI.Time=sqlQuery.value("Time").toDateTime();         //时间
                record_logI.nowDate=sqlQuery.value("nowDate").toString();        //日期

                record_logI.base_weigh=sqlQuery.value("base_weigh").toDouble();//SAP单个数量 的重量 kg
                record_logI.WeighType=sqlQuery.value("WeighType").toString();//称重类型   称重  计数
                record_logI.allWeigh=sqlQuery.value("allWeigh").toDouble();//称出总重   (kg)
                record_logI.weigh_base=sqlQuery.value("weigh_base").toDouble();//称出单个重量
                record_logI.weigh_pcs=sqlQuery.value("weigh_pcs").toDouble();//计数的数量
                record_logI.IssueType=sqlQuery.value("IssueType").toString();//发料类型  344 LM DN SL
                record_logI.LabelType=sqlQuery.value("LabelType").toString();//贴纸类型 N KT
                record_logI.operaterIndex=sqlQuery.value("operaterIndex").toInt();//操作台编号
                record_logI.pickType=sqlQuery.value("pickType").toString();
                record_logI.creatTime=sqlQuery.value("creatTime").toString();

                if(!record_logMap.contains(record_logI.logId)){
                    record_logMap.insert(record_logI.logId,record_logI);
                    //qDebug()<<"query record_log S1"<<record_logI.LabelNo<<record_logI.Material<<record_logI.IssueType<<record_logI.readlQty;
                }
            }
        }else {
            qDebug()<<"query record_log E1"<<sqlQuery.record();
        }
    }
    qDebug()<<"query record_logMap "<<record_logMap.size();
    return record_logMap;
}

//**********************************任务查询********************************//

QMap<int, SAPExcelInfo> threadQuery::querySAPExcelInfoList(slecetSAP_Log slecetSAP_LogI)
{
    qDebug()<<"querySAPExcelInfoList ->"<<slecetSAP_LogI.taskStatus_s<<slecetSAP_LogI.taskStatus_e
           <<slecetSAP_LogI.operaterIndex<<slecetSAP_LogI.labelNoMap.size()<<slecetSAP_LogI.materialMap.size();

    QMap<int, SAPExcelInfo> SAPExcelInfoTask;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();

    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.setForwardOnly(true);

    if(!slecetSAP_LogI.labelNoMap.isEmpty() || !slecetSAP_LogI.materialMap.isEmpty()){
        QMap<QString,QString>selectMap;int action=0;//0标签号 1 件号
        if(!slecetSAP_LogI.labelNoMap.isEmpty()){
            selectMap=slecetSAP_LogI.labelNoMap;
        }else if(!slecetSAP_LogI.materialMap.isEmpty()) {
            selectMap=slecetSAP_LogI.materialMap;action=1;
        }
        QMap<QString,QString>::iterator iter =selectMap.begin();
        while(iter !=selectMap.end()){

            if(action==0){//标签号
                sqlQuery.prepare("select * from sapExcelinfo "
                                 "where taskType=:taskType and LabelNo =:LabelNo and taskStatus >=:taskStatus and taskStatus <=:taskStatus "
                                 "and creatTimer >=:creatTimer and creatTimer <=:creatTimer;");
                sqlQuery.addBindValue(1);
                sqlQuery.addBindValue(iter.value());
                sqlQuery.addBindValue(slecetSAP_LogI.taskStatus_s);
                sqlQuery.addBindValue(slecetSAP_LogI.taskStatus_e);
                sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeS);
                sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeE);
            }else {
                sqlQuery.prepare("select * from sapExcelinfo "
                                 "where taskType=:taskType and Material =:Material and taskStatus >=:taskStatus and taskStatus <=:taskStatus "
                                 "and creatTimer >=:creatTimer and creatTimer <=:creatTimer;");
                sqlQuery.addBindValue(1);
                sqlQuery.addBindValue(iter.value());
                sqlQuery.addBindValue(slecetSAP_LogI.taskStatus_s);
                sqlQuery.addBindValue(slecetSAP_LogI.taskStatus_e);
                sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeS);
                sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeE);
            }

            if(sqlQuery.exec())
            {
                while(sqlQuery.next())
                {
                    SAPExcelInfo SAPExcelInfoI;
                    SAPExcelInfoI.SAPTaskIndex=sqlQuery.value("SAPTaskIndex").toInt();//索引 唯一值
                    if(SAPExcelInfoTask.contains(SAPExcelInfoI.SAPTaskIndex)){
                        continue;
                    }

                    SAPExcelInfoI.taskType=sqlQuery.value("taskType").toString();        //任务类型  OUT-出库  IN-入库  MOVE-移库  Empty-返空箱
                    SAPExcelInfoI.taskTypeDesc=sqlQuery.value("taskTypeDesc").toString();

                    SAPExcelInfoI.taskId=sqlQuery.value("taskId").toString();          //任务编码 唯一性
                    SAPExcelInfoI.taskId_ess=sqlQuery.value("taskId_ess").toString();      //夹抱机器人 任务编码 唯一性
                    SAPExcelInfoI.taskId_agv=sqlQuery.value("taskId_agv").toString();      //举升机器人 任务编码 唯一性

                    SAPExcelInfoI.taskStatus=sqlQuery.value("taskStatus").toInt();          //任务状态
                    SAPExcelInfoI.taskStatusDesc=sqlQuery.value("taskStatusDesc").toString();  //任务状态注释

                    SAPExcelInfoI.sourcestation=sqlQuery.value("sourcestation").toString();   //来源 入库为NULL，出库为库位
                    SAPExcelInfoI.pickDesc_s=sqlQuery.value("pickDesc_s").toString();       //起始站点的对接码头

                    SAPExcelInfoI.pickDesc_e=sqlQuery.value("pickDesc_e").toString();      //目标站点的对接码头
                    SAPExcelInfoI.destination=sqlQuery.value("destination").toString();     //目的地。入库为库位，出库为线体

                    SAPExcelInfoI.podIdDesc=sqlQuery.value("podIdDesc").toString();       //所属架位注释 -- MES
                    SAPExcelInfoI.shelfBindesc=sqlQuery.value("shelfBindesc").toString();    //所属架位注释 -- ESS
                    SAPExcelInfoI.containerCode=sqlQuery.value("containerCode").toString();   //容器编码 (即胶箱编码) ->唯一

                    SAPExcelInfoI.oldIdDesc=sqlQuery.value("oldIdDesc").toString();       //所属架位注释 -- MES
                    SAPExcelInfoI.oldBinDesc=sqlQuery.value("oldBinDesc").toString();         //改架前的 Bin   (用于AGV内部移库) -- ESS

                    SAPExcelInfoI.newIdDesc=sqlQuery.value("newIdDesc").toString();       //所属架位注释 -- MES
                    SAPExcelInfoI.newBinDesc=sqlQuery.value("newBinDesc").toString();         //改架后的 Bin   (用于AGV内部移库) -- ESS

                    SAPExcelInfoI.cancelTask=sqlQuery.value("cancelTask").toInt();          //大于0  取消
                    SAPExcelInfoI.Priority=sqlQuery.value("Priority").toDouble();       //出库任务 优先级 1-100 由高到低  默认值不变100
                    SAPExcelInfoI.taskError=sqlQuery.value("taskError").toInt();           //任务错误代码
                    SAPExcelInfoI.errortextEdit=sqlQuery.value("errortextEdit").toString();  //异常原因详细信息

                    SAPExcelInfoI.lastuser=sqlQuery.value("lastuser").toString();          //操作员
                    SAPExcelInfoI.taskTimer=QDateTime::currentDateTime();
                    SAPExcelInfoI.creatTimer=sqlQuery.value("creatTimer").toDateTime();      //创建时间
                    SAPExcelInfoI.finishTimer=sqlQuery.value("finishTimer").toDateTime();     //完成时间

                /********************* MES 的订单物料信息 *********************/

                    SAPExcelInfoI.LabelNo=sqlQuery.value("LabelNo").toString();        //贴纸凭证号
                    SAPExcelInfoI.Material=sqlQuery.value("Material").toString();       //物料编码
                    SAPExcelInfoI.customsType=sqlQuery.value("customsType").toString();    //类型属性
                    SAPExcelInfoI.storeCode=sqlQuery.value("storeCode").toString();      //仓号属性
                    SAPExcelInfoI.taskQty=sqlQuery.value("taskQty").toDouble();      //数量
                    SAPExcelInfoI.MaterialListdesc=sqlQuery.value("MaterialListdesc").toString();     //物料编码 集合
                    SAPExcelInfoI.MaterialList=SAPExcelInfoI.MaterialListdesc.split("&");             //物料编码 集合

                    if(!SAPExcelInfoTask.contains(SAPExcelInfoI.SAPTaskIndex)){
                        SAPExcelInfoTask.insert(SAPExcelInfoI.SAPTaskIndex,SAPExcelInfoI);
                        //qDebug()<<"wait119:"<<SAPExcelInfoI.SAPTaskIndex<<SAPExcelInfoI.Material<<SAPExcelInfoI.taskStatus;
                    }
                    //qDebug()<<missionInfoI.ikey<<missionInfoI.updateQty<<sqlQuery.record();
                }
            }else {
                qDebug()<<"queryNewMissionInfo"<<sqlQuery.record();
            }
            iter++;
        }

    }else {

        if(slecetSAP_LogI.operaterIndex!=0){
            sqlQuery.prepare("select * from sapExcelinfo "
                             "where taskType=:taskType and pickStation =:pickStation and taskStatus >=:taskStatus and taskStatus <=:taskStatus "
                             "and creatTimer >=:creatTimer and creatTimer <=:creatTimer;");
            sqlQuery.addBindValue(1);
            sqlQuery.addBindValue(slecetSAP_LogI.operaterIndex);
            sqlQuery.addBindValue(slecetSAP_LogI.taskStatus_s);
            sqlQuery.addBindValue(slecetSAP_LogI.taskStatus_e);
            sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeS);
            sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeE);

        }if(slecetSAP_LogI.operaterIndex==0 && slecetSAP_LogI.ShelfBindesc==""){
            sqlQuery.prepare("select * from sapExcelinfo "
                             "where taskType=:taskType and taskStatus >=:taskStatus and taskStatus <=:taskStatus "
                             "and creatTimer >=:creatTimer and creatTimer <=:creatTimer;");
            sqlQuery.addBindValue(1);
            sqlQuery.addBindValue(slecetSAP_LogI.taskStatus_s);
            sqlQuery.addBindValue(slecetSAP_LogI.taskStatus_e);
            sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeS);
            sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeE);
        }else {
            sqlQuery.prepare("select * from sapExcelinfo "
                             "where taskStatus >=:taskStatus and taskStatus <=:taskStatus "
                             "and creatTimer >=:creatTimer and creatTimer <=:creatTimer;");
            sqlQuery.addBindValue(slecetSAP_LogI.taskStatus_s);
            sqlQuery.addBindValue(slecetSAP_LogI.taskStatus_e);
            sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeS);
            sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeE);

        }

        if(sqlQuery.exec())
        {
            while(sqlQuery.next())
            {
                SAPExcelInfo SAPExcelInfoI;
                SAPExcelInfoI.SAPTaskIndex=sqlQuery.value("SAPTaskIndex").toInt();//索引 唯一值
                if(SAPExcelInfoTask.contains(SAPExcelInfoI.SAPTaskIndex)){
                    continue;
                }

                SAPExcelInfoI.taskType=sqlQuery.value("taskType").toString();        //任务类型  OUT-出库  IN-入库  MOVE-移库  Empty-返空箱
                SAPExcelInfoI.taskTypeDesc=sqlQuery.value("taskTypeDesc").toString();

                SAPExcelInfoI.taskId=sqlQuery.value("taskId").toString();          //任务编码 唯一性
                SAPExcelInfoI.taskId_ess=sqlQuery.value("taskId_ess").toString();      //夹抱机器人 任务编码 唯一性
                SAPExcelInfoI.taskId_agv=sqlQuery.value("taskId_agv").toString();      //举升机器人 任务编码 唯一性

                SAPExcelInfoI.taskStatus=sqlQuery.value("taskStatus").toInt();          //任务状态
                SAPExcelInfoI.taskStatusDesc=sqlQuery.value("taskStatusDesc").toString();  //任务状态注释

                SAPExcelInfoI.sourcestation=sqlQuery.value("sourcestation").toString();   //来源 入库为NULL，出库为库位
                SAPExcelInfoI.pickDesc_s=sqlQuery.value("pickDesc_s").toString();       //起始站点的对接码头

                SAPExcelInfoI.pickDesc_e=sqlQuery.value("pickDesc_e").toString();      //目标站点的对接码头
                SAPExcelInfoI.destination=sqlQuery.value("destination").toString();     //目的地。入库为库位，出库为线体

                SAPExcelInfoI.podIdDesc=sqlQuery.value("podIdDesc").toString();       //所属架位注释 -- MES
                SAPExcelInfoI.shelfBindesc=sqlQuery.value("shelfBindesc").toString();    //所属架位注释 -- ESS
                SAPExcelInfoI.containerCode=sqlQuery.value("containerCode").toString();   //容器编码 (即胶箱编码) ->唯一

                SAPExcelInfoI.oldIdDesc=sqlQuery.value("oldIdDesc").toString();       //所属架位注释 -- MES
                SAPExcelInfoI.oldBinDesc=sqlQuery.value("oldBinDesc").toString();         //改架前的 Bin   (用于AGV内部移库) -- ESS

                SAPExcelInfoI.newIdDesc=sqlQuery.value("newIdDesc").toString();       //所属架位注释 -- MES
                SAPExcelInfoI.newBinDesc=sqlQuery.value("newBinDesc").toString();         //改架后的 Bin   (用于AGV内部移库) -- ESS

                SAPExcelInfoI.cancelTask=sqlQuery.value("cancelTask").toInt();          //大于0  取消
                SAPExcelInfoI.Priority=sqlQuery.value("Priority").toDouble();       //出库任务 优先级 1-100 由高到低  默认值不变100
                SAPExcelInfoI.taskError=sqlQuery.value("taskError").toInt();           //任务错误代码
                SAPExcelInfoI.errortextEdit=sqlQuery.value("errortextEdit").toString();  //异常原因详细信息

                SAPExcelInfoI.lastuser=sqlQuery.value("lastuser").toString();          //操作员
                SAPExcelInfoI.taskTimer=QDateTime::currentDateTime();
                SAPExcelInfoI.creatTimer=sqlQuery.value("creatTimer").toDateTime();      //创建时间
                SAPExcelInfoI.finishTimer=sqlQuery.value("finishTimer").toDateTime();     //完成时间

            /********************* MES 的订单物料信息 *********************/

                SAPExcelInfoI.LabelNo=sqlQuery.value("LabelNo").toString();        //贴纸凭证号
                SAPExcelInfoI.Material=sqlQuery.value("Material").toString();       //物料编码
                SAPExcelInfoI.customsType=sqlQuery.value("customsType").toString();    //类型属性
                SAPExcelInfoI.storeCode=sqlQuery.value("storeCode").toString();      //仓号属性
                SAPExcelInfoI.taskQty=sqlQuery.value("taskQty").toDouble();      //数量
                SAPExcelInfoI.MaterialListdesc=sqlQuery.value("MaterialListdesc").toString();     //物料编码 集合
                SAPExcelInfoI.MaterialList=SAPExcelInfoI.MaterialListdesc.split("&");             //物料编码 集合

                if(!SAPExcelInfoTask.contains(SAPExcelInfoI.SAPTaskIndex)){
                    SAPExcelInfoTask.insert(SAPExcelInfoI.SAPTaskIndex,SAPExcelInfoI);
                    //qDebug()<<"wait119:"<<SAPExcelInfoI.SAPTaskIndex<<SAPExcelInfoI.Material<<SAPExcelInfoI.taskStatus;
                }
                //qDebug()<<missionInfoI.ikey<<missionInfoI.updateQty<<sqlQuery.record();
            }
        }else {
            qDebug()<<"queryNewMissionInfo"<<sqlQuery.record();
        }

    }
    qDebug()<<"querySAPExcelInfoList_T size ->"<<SAPExcelInfoTask.size();
    return SAPExcelInfoTask;
}

void threadQuery::UP_SAPExcelInfotaskCode(QMap<int, SAPExcelInfo> slecetSAPExcelInfoList)
{

    QMap<QString,shelfBinInfo>shelfBinInfoMap;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    QMap<int, SAPExcelInfo>::const_iterator iter= slecetSAPExcelInfoList.begin();
    while (iter !=slecetSAPExcelInfoList.end()) {
        if(iter!=nullptr){
            sqlQuery.prepare("UPDATE TOP(1) [dbo].[sapExcelinfo] SET [taskId_ess]=:taskId_ess,[taskId_agv]=:taskId_agv,"
                             "[taskStatus]=:taskStatus,[taskStatusDesc]=:taskStatusDesc,[taskError]=:taskError,"
                             "[errortextEdit]=:errortextEdit "
                             "WHERE ([SAPTaskIndex]=:SAPTaskIndex);");
            sqlQuery.addBindValue(iter.value().taskId_ess);
            sqlQuery.addBindValue(iter.value().taskId_agv);
            sqlQuery.addBindValue(iter.value().taskStatus);
            sqlQuery.addBindValue(iter.value().taskStatusDesc);
            sqlQuery.addBindValue(iter.value().taskError);
            sqlQuery.addBindValue(iter.value().errortextEdit);
            sqlQuery.addBindValue(iter.value().SAPTaskIndex);
            if(sqlQuery.exec()){
                if(!shelfBinInfoMap.contains(iter.value().shelfBindesc)){
                    shelfBinInfo shelfBinInfoI;
                    if(iter.value().taskType=="IN" && iter.value().taskStatus==100){
                        shelfBinInfoI.status=2;
                        shelfBinInfoI.containerIndex=iter.value().containerCode.right(2).toInt();
                        shelfBinInfoI.containerCode=iter.value().containerCode;
                        shelfBinInfoI.shelfBindesc=iter.value().shelfBindesc;
                        shelfBinInfoI.LabelNo=iter.value().LabelNo;
                        shelfBinInfoMap.insert(shelfBinInfoI.shelfBindesc,shelfBinInfoI);
                    }if(iter.value().taskType=="OUT"){
                        if(iter.value().taskStatus>=2 && iter.value().taskStatus<9){//容器离场前
                            shelfBinInfoI.status=3;//0 空闲  1入库中  2入库完成  3出库中  0出库完成--空闲
                            shelfBinInfoI.containerIndex=iter.value().containerCode.right(2).toInt();
                            shelfBinInfoI.containerCode=iter.value().containerCode;
                            shelfBinInfoI.shelfBindesc=iter.value().shelfBindesc;
                            shelfBinInfoI.LabelNo=iter.value().LabelNo;
                            shelfBinInfoMap.insert(shelfBinInfoI.shelfBindesc,shelfBinInfoI);
                        } if(iter.value().taskStatus>=12 && iter.value().taskStatus<=14){//容器离场前
                            shelfBinInfoI.status=0;//0 空闲  1入库中  2入库完成  3出库中  0出库完成--空闲
                            shelfBinInfoI.shelfBindesc=iter.value().shelfBindesc;
                            shelfBinInfoMap.insert(shelfBinInfoI.shelfBindesc,shelfBinInfoI);
                        }if(iter.value().taskStatusDesc=="任务失败" && iter.value().taskStatus==100){
                            shelfBinInfoI.status=2;//0 空闲  1入库中  2入库完成  3出库中  0出库完成--空闲
                            shelfBinInfoI.containerIndex=iter.value().containerCode.right(2).toInt();
                            shelfBinInfoI.containerCode=iter.value().containerCode;
                            shelfBinInfoI.shelfBindesc=iter.value().shelfBindesc;
                            shelfBinInfoI.LabelNo=iter.value().LabelNo;
                            shelfBinInfoMap.insert(shelfBinInfoI.shelfBindesc,shelfBinInfoI);
                        }

                    }

                }
                qDebug()<<"taskId_ess S"<<iter.value().SAPTaskIndex<<iter.value().taskId_ess
                       <<iter.value().containerCode<<iter.value().taskStatus<<iter.value().taskStatusDesc;
            }else {
                qDebug()<<"taskId_ess E"<<iter.value().SAPTaskIndex<<iter.value().taskId_ess
                       <<iter.value().containerCode<<iter.value().taskStatus<<sqlQuery.lastError();
            }
        }else{
            return;
        }
        iter++;
    }

    if(!shelfBinInfoMap.isEmpty()){
        setshelfBinInfo_Status(shelfBinInfoMap);
    }

}


bool threadQuery::UP_SetPrioritySAP(QMap<int, SAPExcelInfo> slecetSAPExcelInfoList)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    QMap<int, SAPExcelInfo>::iterator iter= slecetSAPExcelInfoList.begin();
    while (iter !=slecetSAPExcelInfoList.end()) {
        if(iter.value().checked==1){//选择勾选   -1默认状态   0 默认不勾选   1勾选状
            sqlQuery.prepare("UPDATE [dbo].[sapExcelinfo] SET [Priority]=:Priority "
                             "WHERE [SAPTaskIndex]=:SAPTaskIndex;");
            sqlQuery.addBindValue(1);//出库任务 优先级 0-100 由高到低 数据员可修改
            sqlQuery.addBindValue(iter.value().SAPTaskIndex);
            if(sqlQuery.exec()){
                qDebug()<<"UP_SetPrioritySAP S"<<iter.value().SAPTaskIndex<<iter.value().taskId
                       <<iter.value().taskStatus;
            }else {
                qDebug()<<"UP_SetPrioritySAP E"<<iter.value().SAPTaskIndex<<iter.value().taskId
                       <<iter.value().taskStatus<<sqlQuery.lastError();
            }
        }
        iter++;
    }
    return true;
}

bool threadQuery::UP_cancelTaskSAP(QMap<int, SAPExcelInfo> slecetSAPExcelInfoList)
{
    QMap<QString,shelfBinInfo>shelfBinInfoMap;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    QMap<int, SAPExcelInfo>::const_iterator iter= slecetSAPExcelInfoList.begin();
    while (iter !=slecetSAPExcelInfoList.end()) {
        if(iter!=nullptr){
            sqlQuery.prepare("UPDATE TOP(1) [dbo].[sapExcelinfo] SET [taskStatus]=:taskStatus,"
                             "[taskStatusDesc]=:taskStatusDesc,[taskError]=:taskError,"
                             "[errortextEdit]=:errortextEdit,[finishTimer]=:finishTimer "
                             "WHERE [SAPTaskIndex]=:SAPTaskIndex;");

            sqlQuery.addBindValue(100);
            sqlQuery.addBindValue("已删除");
            sqlQuery.addBindValue(15);
            sqlQuery.addBindValue("已删除");
            sqlQuery.addBindValue(QDateTime::currentDateTime());
            sqlQuery.addBindValue(iter.value().SAPTaskIndex);

            if(sqlQuery.exec()){
                qDebug()<<"UP_cancelTaskSAP S"<<iter.value().SAPTaskIndex<<iter.value().taskId<<iter.value().Priority
                       <<iter.value().taskStatus<<iter.value().cancelTask;
                shelfBinInfo shelfBinInfoI;
                if(iter.value().taskType=="IN"){
                    shelfBinInfo shelfBinInfoI;
                    shelfBinInfoI.shelfBindesc=iter.value().shelfBindesc;
                    shelfBinInfoMap.insert(shelfBinInfoI.shelfBindesc,shelfBinInfoI);
                }if(iter.value().taskType=="OUT"){
                    if(iter.value().taskStatus>=9){
                        shelfBinInfoI.status=0;
                        shelfBinInfoI.shelfBindesc=iter.value().shelfBindesc;
                        shelfBinInfoMap.insert(shelfBinInfoI.shelfBindesc,shelfBinInfoI);
                    }
                }

            }else {
                qDebug()<<"UP_cancelTaskSAP E"<<iter.value().SAPTaskIndex<<iter.value().taskId<<iter.value().Priority
                       <<iter.value().taskStatus<<sqlQuery.lastError();
            }
        }else{
            return false;
        }

        iter++;
    }
    if(!shelfBinInfoMap.isEmpty()){
        setshelfBinInfo_Status(shelfBinInfoMap);
    }

    return true;
}


//**********************************库存管理********************************//
void threadQuery::upMaterialshelfBinMap_Check(QMap<QString,materialShelfbin>materialShelfbinMap, int type)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    sqlDatabase.transaction();
    QSqlQuery sqlQuery(sqlDatabase);

    QMap<QString,materialShelfbin>::iterator iter= materialShelfbinMap.begin();
    while (iter !=materialShelfbinMap.end()) {
        sqlQuery.prepare("UPDATE TOP(1) [dbo].[materialShelfbinMap] SET [lastuser]=:lastuser,"
                         " [lastCheckTimer]=:lastCheckTimer WHERE ([materialNumber]=:materialNumber and "
                         " [storeCode]=:storeCode);");

        //iter.value().lastCheckTimer=QDateTime::currentDateTime();
        sqlQuery.addBindValue(iter.value().lastuser);
        sqlQuery.addBindValue(iter.value().lastCheckTimer);
        sqlQuery.addBindValue(iter.value().materialNumber);
        sqlQuery.addBindValue(iter.value().storeCode);

        if(sqlQuery.exec()){
            qDebug()<<"UPDATE  check materialShelfbinMap: "<<iter.value().shelfBinIndex<<iter.value().materialNumber<<iter.value().storeCode;
        }
        iter++;
    }

    if(!sqlDatabase.commit()){
        sqlDatabase.rollback();
    }

}

void threadQuery::up_ShelfBinInfo(QMap<int, shelfBinInfo> shelfBinInfoMap)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    QMap<int, shelfBinInfo>::iterator iter= shelfBinInfoMap.begin();
    while (iter!=shelfBinInfoMap.end()) {
        if(iter.value().customsType!=""){
            sqlQuery.prepare("UPDATE [dbo].[shelfInfo] SET [storeCode]=:storeCode,"
                              "[customsType]=:customsType WHERE ([shelfBinIndex]=:shelfBinIndex);");
            sqlQuery.addBindValue(iter.value().storeCode);
            sqlQuery.addBindValue(iter.value().customsType);
            sqlQuery.addBindValue(iter.value().shelfBinIndex);
            if(sqlQuery.exec()){
                qDebug()<<"update  shelfInfo S"<<iter.value().shelfBinIndex<<iter.value().storeCode<<iter.value().customsType;

            }else {
                qDebug()<<"update  shelfInfo E"<<iter.value().shelfBinIndex<<iter.value().storeCode<<iter.value().customsType;
            }
        }
        iter++;
    }
}


