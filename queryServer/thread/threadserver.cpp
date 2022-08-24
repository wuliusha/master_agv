#include "threadserver.h"
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase)

threadServer::threadServer(QObject *parent) : QObject(parent)
{
    threadTimer = new QTimer(this);
    connect(threadTimer,&QTimer::timeout,this,&threadServer::threadServerTimer);
    threadTimer->start(800);
}

void threadServer::threadServerTimer()
{
    QElapsedTimer timer;timer.start();
    if(!Servercountbool){return;}
    Servercountbool=false;
    /************* 基础信息部分  ServerInitItem***********/
    if(!ServerInitbool){

        if(ServerInitItem.sapPathMap.isEmpty()){
            setSapPathMap();            //读取数据库的路径配置信息
            qDebug()<<"ServerInitItem.sapPathMap.size():"<<ServerInitItem.sapPathMap.size();
        }if(ServerInitItem.UserInfoList.isEmpty()){
            UserInfoListInit();         //获取登录用户信息
            qDebug()<<"ServerInitItem.UserInfoList.size():"<<ServerInitItem.UserInfoList.size();
        }if(ServerInitItem.errorTypeMap.isEmpty()){
            errorTypeMapInit();         //任务状态的错误码与译文
            qDebug()<<"ServerInitItem.errorTypeMap.size():"<<ServerInitItem.errorTypeMap.size();
        }if(ServerInitItem.taskStatusMap.isEmpty()){
            taskStatusMapInit();        //任务状态的错误码与译文
            qDebug()<<"ServerInitItem.taskStatusMap.size():"<<ServerInitItem.taskStatusMap.size();
        }if(ServerInitItem.doorSubTaskMap.isEmpty()){
            automaticDoorMapInit();     //所有自动门的基础信息
            qDebug()<<"ServerInitItem.doorSubTaskMap.size():"<<ServerInitItem.doorSubTaskMap.size();
        }if(ServerInitItem.eventCodeMap.isEmpty()){
            eventCodeMapInit();         //ESS-P 事件 回调类型
            qDebug()<<"ServerInitItem.eventCodeMap.size():"<<ServerInitItem.eventCodeMap.size();
        }if(ServerInitItem.StationCodeMap.isEmpty()){
            StationCodeMapInit();       //ESS工作站与 ESS-P坐标点
            qDebug()<<"ServerInitItem.StationCodeMap.size():"<<ServerInitItem.StationCodeMap.size();
        }if(ServerInitItem.StationPointMap.isEmpty()){
            StationPointMapInit();      //二维码站点与二维码绑定
            qDebug()<<"ServerInitItem.StationPointMap.size():"<<ServerInitItem.StationPointMap.size();
        }if(ServerInitItem.BindescPodIdMap.isEmpty()){
            shelfBinInfoMapInit();      //实时获取 Bin 的基础信息
            qDebug()<<"ServerInitItem.BindescPodIdMap.size():"<<ServerInitItem.BindescPodIdMap.size();
        }

        if(!ServerInitItem.sapPathMap.isEmpty() && !ServerInitItem.UserInfoList.isEmpty()
                && !ServerInitItem.errorTypeMap.isEmpty() && !ServerInitItem.taskStatusMap.isEmpty()
                && !ServerInitItem.doorSubTaskMap.isEmpty() && !ServerInitItem.eventCodeMap.isEmpty()
                && !ServerInitItem.StationCodeMap.isEmpty() && !ServerInitItem.StationPointMap.isEmpty()
                && !ServerInitItem.BindescPodIdMap.isEmpty()){
            ServerInitbool=true;
        }else{

        }

    }

    /************* 基础信息部分  CurrentServerItem***********/
    if(!ServerItembool){
        if(CurrentServerItem.LiftCodeMap.isEmpty()){
            LiftTaskInit();                                                              //获取升降机的任务信息
            qDebug()<<"CurrentServerItem.LiftCodeMap.size():"<<CurrentServerItem.LiftCodeMap.size();
        }if(CurrentServerItem.AGVCurrentTaskMap.isEmpty()){
            AGVTCurrentTask_Init();                                                     //当前AGV运行信息
            qDebug()<<"CurrentServerItem.AGVCurrentTaskMap.size():"<<CurrentServerItem.AGVCurrentTaskMap.size();
        }if(CurrentServerItem.currentSAPExcelInfoTask.isEmpty()){
            CurrentServerItem.currentSAPExcelInfoTask=readSAPExcelInfoTask(taskFnish_not,"select");   //SAP 正在执行或未完成的任务 taskstatus<=4
        }

        if(!CurrentServerItem.LiftCodeMap.isEmpty()
                && !CurrentServerItem.AGVCurrentTaskMap.isEmpty()){
            ServerItembool=true;
        }
    }

    threadServercount++;
    if(ServerInitbool && ServerItembool){
        if(threadServercount%2==1){
            queryServer::getInstance()->setCurrentServerInitItem(CurrentServerItem,ServerInitItem);     //基础信息
        }else{
            ESS_Single::getInstance()->setCurrentServerItem(CurrentServerItem,ServerInitItem);          //需要实时更信息 链表表 整合
        }
    }

    Servercountbool=true;
    if(threadServercount>3000){threadServercount=0;}
    if(timer.elapsed()>1000){
        qDebug()<<"Server read data cost:"<<timer.elapsed()<<"ms  "<<QDateTime::currentDateTime().toString("hh:mm ss");timer.restart();
    }

}

QMap<int, SAPExcelInfo> threadServer::readSAPExcelInfoTask(int taskstatus, QString taskType)
{
    QMap<int, SAPExcelInfo> SAPExcelInfoTask;
    QDateTime QDateTimeS=QDateTime::fromString(QDateTime::currentDateTime().toString("yyyy-MM-dd")+" 00:00:00" ,"yyyy-MM-dd hh:mm:ss");
    QDateTime QDateTimeE=QDateTime::fromString(QDateTime::currentDateTime().toString("yyyy-MM-dd")+" 23:59:00" ,"yyyy-MM-dd hh:mm:ss");

    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.setForwardOnly(true);

    //"where pickStation =:pickStation and ((orderId =:orderId and missionId =:missionId) and (status =:status and taskType =:taskType));"
    sqlQuery.prepare("select * from sapExcelinfo "
                     "where (taskStatus >=:taskStatus and taskStatus <=:taskStatus) or "
                     "(creatTimer >=:creatTimer or finishTimer >=:finishTimer);");
    sqlQuery.addBindValue(0);
    sqlQuery.addBindValue(taskstatus);
    sqlQuery.addBindValue(QDateTimeS);
    sqlQuery.addBindValue(QDateTimeS);

    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            SAPExcelInfo SAPExcelInfoI;
            SAPExcelInfoI.SAPTaskIndex=sqlQuery.value("SAPTaskIndex").toInt();          //索引 唯一值
            if(SAPExcelInfoTask.contains(SAPExcelInfoI.SAPTaskIndex)){
                continue;
            }

            SAPExcelInfoI.taskType=sqlQuery.value("taskType").toString();               //任务类型  OUT-出库  IN-入库  MOVE-移库  Empty-返空箱
            SAPExcelInfoI.taskTypeDesc=sqlQuery.value("taskTypeDesc").toString();

            SAPExcelInfoI.taskId=sqlQuery.value("taskId").toString();                   //任务编码 唯一性
            SAPExcelInfoI.taskId_ess=sqlQuery.value("taskId_ess").toString();           //夹抱机器人 任务编码 唯一性
            SAPExcelInfoI.taskId_agv=sqlQuery.value("taskId_agv").toString();           //举升机器人 任务编码 唯一性
            SAPExcelInfoI.floorId=sqlQuery.value("floorId").toString();                 //楼层走向  2F-3F 3F-2F

            SAPExcelInfoI.taskStatus=sqlQuery.value("taskStatus").toInt();              //任务状态
            SAPExcelInfoI.latstaskStatus=SAPExcelInfoI.taskStatus;                      //上一个任务状态   当前状态与上一状态不一致时更新数据库
            SAPExcelInfoI.taskStatusDesc=sqlQuery.value("taskStatusDesc").toString();   //任务状态注释

            SAPExcelInfoI.sourcestation=sqlQuery.value("sourcestation").toString();     //来源 入库为NULL，出库为库位
            SAPExcelInfoI.pickDesc_s=sqlQuery.value("pickDesc_s").toString();           //起始站点的对接码头

            SAPExcelInfoI.pickDesc_e=sqlQuery.value("pickDesc_e").toString();           //目标站点的对接码头
            SAPExcelInfoI.destination=sqlQuery.value("destination").toString();         //目的地。入库为库位，出库为线体

            SAPExcelInfoI.podIdDesc=sqlQuery.value("podIdDesc").toString();             //所属架位注释 -- MES
            SAPExcelInfoI.shelfBindesc=sqlQuery.value("shelfBindesc").toString();       //所属架位注释 -- ESS
            SAPExcelInfoI.containerCode=sqlQuery.value("containerCode").toString();     //容器编码 (即胶箱编码) ->唯一

            SAPExcelInfoI.oldIdDesc=sqlQuery.value("oldIdDesc").toString();             //所属架位注释 -- MES
            SAPExcelInfoI.oldBinDesc=sqlQuery.value("oldBinDesc").toString();           //改架前的 Bin   (用于AGV内部移库) -- ESS

            SAPExcelInfoI.newIdDesc=sqlQuery.value("newIdDesc").toString();             //所属架位注释 -- MES
            SAPExcelInfoI.newBinDesc=sqlQuery.value("newBinDesc").toString();           //改架后的 Bin   (用于AGV内部移库) -- ESS

            SAPExcelInfoI.cancelTask=sqlQuery.value("cancelTask").toInt();              //大于0  取消
            SAPExcelInfoI.Priority=sqlQuery.value("Priority").toDouble();               //出库任务 优先级 1-100 由高到低  默认值不变100
            SAPExcelInfoI.taskError=sqlQuery.value("taskError").toInt();                //任务错误代码
            SAPExcelInfoI.errortextEdit=sqlQuery.value("errortextEdit").toString();     //异常原因详细信息

            SAPExcelInfoI.lastuser=sqlQuery.value("lastuser").toString();               //操作员
            SAPExcelInfoI.taskTimer=QDateTime::currentDateTime();
            SAPExcelInfoI.creatTimer=sqlQuery.value("creatTimer").toDateTime();         //创建时间
            SAPExcelInfoI.finishTimer=sqlQuery.value("finishTimer").toDateTime();       //完成时间

        /********************* MES 的订单物料信息 *********************/

            SAPExcelInfoI.LabelNo=sqlQuery.value("LabelNo").toString();                 //贴纸凭证号
            SAPExcelInfoI.Material=sqlQuery.value("Material").toString();               //物料编码
            SAPExcelInfoI.customsType=sqlQuery.value("customsType").toString();         //类型属性
            SAPExcelInfoI.storeCode=sqlQuery.value("storeCode").toString();             //仓号属性
            SAPExcelInfoI.taskQty=sqlQuery.value("taskQty").toDouble();                  //数量
            SAPExcelInfoI.MaterialListdesc=sqlQuery.value("MaterialListdesc").toString();//物料编码 集合
            SAPExcelInfoI.MaterialList=SAPExcelInfoI.MaterialListdesc.split("&");        //物料编码 集合
            //SAPExcelInfoI.MaterialListdesc= SAPExcelInfoI.MaterialList.join("&");

            if(!SAPExcelInfoTask.contains(SAPExcelInfoI.SAPTaskIndex)){
                SAPExcelInfoTask.insert(SAPExcelInfoI.SAPTaskIndex,SAPExcelInfoI);
                //qDebug()<<"wait119:"<<SAPExcelInfoI.SAPTaskIndex<<SAPExcelInfoI.Material<<SAPExcelInfoI.taskStatus<<SAPExcelInfoI.taskTimer;
            }
            //qDebug()<<missionInfoI.ikey<<missionInfoI.updateQty<<sqlQuery.record();
        }
    }else {
        qDebug()<<"taskType:"<<taskType<<"querySAPExcelInfoTask"<<sqlQuery.record();
    }

    return SAPExcelInfoTask;
}


void threadServer::setSapPathMap()
{

    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.setForwardOnly(true);
    sqlQuery.prepare("select * from sapPath;");

    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            sapPath sapPathI;
            sapPathI.Id=sqlQuery.value("Id").toInt();
            sapPathI.Path=sqlQuery.value("Path").toString();
            sapPathI.funcation=sqlQuery.value("funcation").toString();
            sapPathI.para1=sqlQuery.value("para1").toString();
            sapPathI.para2=sqlQuery.value("para2").toString();
            sapPathI.para3=sqlQuery.value("para3").toString();

            if(sapPathI.funcation!="" && sapPathI.Id<100){
                QString path=sapPathI.funcation+"?";
                if(sapPathI.para1!=""){
                     path=path+sapPathI.para1+"=";
                    if(sapPathI.para2!=""){
                         path="&"+path+sapPathI.para2+"=";
                        if(sapPathI.para3!=""){
                             path="&"+path+sapPathI.para3+"=";
                        }
                    }
                }
                sapPathI.Path=sapPathI.Path+path;
            }

            sapPathI.Type=sqlQuery.value("Type").toString();        //路径类型 发料时根据类型 选择路径
            sapPathI.PathName=sqlQuery.value("PathName").toString();
            ServerInitItem.sapPathMap.insert(sapPathI.Id,sapPathI);
        }
    }

}

void threadServer::UserInfoListInit()
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    QSqlQuery sqlQuery2(sqlDatabase);

    sqlQuery2.setForwardOnly(true);
    ServerInitItem.UserInfoList.clear();
    sqlQuery2.prepare("select * from userinfo;");
    if(sqlQuery2.exec())
    {
        while(sqlQuery2.next())
        {
            User_Info UserInfoItiem;
            UserInfoItiem. UserNuber=sqlQuery2.value("UserNuber").toString();      //编号
            UserInfoItiem. UserName=sqlQuery2.value("UserName").toString();       //姓名
            UserInfoItiem. PassWord=sqlQuery2.value("PassWord").toString();       //密码
            UserInfoItiem. Jurisdiction=sqlQuery2.value("Jurisdiction").toString();   //权限
            UserInfoItiem. UserGrage=sqlQuery2.value("UserGrage").toString();      // 等级
            UserInfoItiem. Status=sqlQuery2.value("Status").toString();        //编辑状态 -1删除
            ServerInitItem.UserInfoList.append(UserInfoItiem);
            //qDebug()<<UserInfoItiem. UserNuber<<UserInfoItiem. UserName<<UserInfoItiem. PassWord;
        }
    }

}

void threadServer::automaticDoorMapInit()
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    sqlQuery.prepare("select * from doorSubTask ;");

    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            doorSubTask doorSubTaskI;
            doorSubTaskI.doorId=sqlQuery.value("doorId").toInt();
            doorSubTaskI.doorIP=sqlQuery.value("doorIP").toString();            //自动门IP
            doorSubTaskI.doorDesc=sqlQuery.value("doorDesc").toString();
            doorSubTaskI.Point=sqlQuery.value("Point").toInt();         //起始点  用于开门
            doorSubTaskI.NextPoint=sqlQuery.value("NextPoint").toInt(); //下一点  用于开门
            doorSubTaskI.door_acionI.Point=doorSubTaskI.Point;
            doorSubTaskI.door_acionI.NextPoint=doorSubTaskI.NextPoint;
            doorSubTaskI.NextPointdesc=sqlQuery.value("NextPointdesc").toString();  //保持开门信号二维码链表
            QStringList NextPointList=doorSubTaskI.NextPointdesc.split("&");       //保持开门信号二维码链表

            for(int i=0;i<NextPointList.size();i++){
                doorSubTaskI.NextPointList.append(NextPointList[i].toInt());
                doorSubTaskI.door_acionI.NextPointList.append(NextPointList[i].trimmed().toInt());
            }

            doorSubTaskI.enable=sqlQuery.value("enable").toInt();
            doorSubTaskI.page=sqlQuery.value("page").toInt();

            //doorSubTaskI.NextPointdesc= doorSubTaskI.NextPointList.join("&");
            if(!ServerInitItem.doorSubTaskMap.contains(doorSubTaskI.doorIP)){
                ServerInitItem.doorSubTaskMap.insert(doorSubTaskI.doorIP,doorSubTaskI);
//                qDebug()<<" 自动门的基础信息:"<<doorSubTaskI.doorId<<doorSubTaskI.doorIP<<doorSubTaskI.Point<<doorSubTaskI.NextPoint
//                       <<doorSubTaskI.NextPointdesc;
            }

        }
    }

}

void threadServer::AGVTCurrentTask_Init()
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    sqlQuery.setForwardOnly(true);
    sqlQuery.prepare("select * from AGVCurrentTask ;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            AGVCurrentTask *AGVCurrentTaskI=new AGVCurrentTask;
            AGVCurrentTaskI->AGVId=sqlQuery.value("AGVId").toInt();                      //小车编号
            AGVCurrentTaskI->AGVIP=sqlQuery.value("AGVIP").toString();                   //小车 ip
            AGVCurrentTaskI->enable=sqlQuery.value("enable").toInt();                    //1使用  0禁用
            AGVCurrentTaskI->AGVType=sqlQuery.value("AGVType").toInt();                  //AGV类型    0默认小精灵   1夹抱AGV
            AGVCurrentTaskI->floornum=sqlQuery.value("floornum").toInt();                //AGV所在楼层
            AGVCurrentTaskI->waitPoint=sqlQuery.value("waitPoint").toInt();              //待机点二维码

            AGVCurrentTaskI->Currentdestpoint=sqlQuery.value("Currentdestpoint").toInt();//当前目标二维码
            AGVCurrentTaskI->destpoint=sqlQuery.value("destpoint").toInt();              //第一个目标二维码
            AGVCurrentTaskI->Nextdestpoint=sqlQuery.value("Nextdestpoint").toInt();      //下一个目标二维码
            AGVCurrentTaskI->waitdestpoint=sqlQuery.value("waitdestpoint").toInt();      //目标点等待点二维码

            AGVCurrentTaskI->Action_agv=sqlQuery.value("Action_agv").toInt();            //二维码带举升动作
            AGVCurrentTaskI->Action_ess=sqlQuery.value("Action_ess").toInt();            //夹包机器人
            AGVCurrentTaskI->Action_all=sqlQuery.value("Action_all").toInt();            //总动作计数
            AGVCurrentTaskI->actionType=sqlQuery.value("actionType").toInt();            //动作类型 0到达站点不需要返回  1到达站点倒计时结束后返回

            AGVCurrentTaskI->taskId=sqlQuery.value("taskId").toString();                 //唯一识别号
            AGVCurrentTaskI->lastTaskId=sqlQuery.value("lastTaskId").toString();         //上一个任务--唯一识别号
            AGVCurrentTaskI->taskType=sqlQuery.value("taskType").toString();             //任务类型 IN入库  OUT出库
            AGVCurrentTaskI->SAPTaskIndex=sqlQuery.value("SAPTaskIndex").toInt();        //任务索引 唯一值
            AGVCurrentTaskI->containerCode=sqlQuery.value("containerCode").toString();   //容器编码 (即胶箱编码) ->唯一

            AGVCurrentTaskI->chargeIP=sqlQuery.value("chargeIP").toString();             //充电桩IP
            AGVCurrentTaskI->ChargePoint=sqlQuery.value("ChargePoint").toInt();          //充电点二维码
            AGVCurrentTaskI->ChargeWait=sqlQuery.value("ChargeWait").toInt();            //充电点前一个二维码
            AGVCurrentTaskI->MoveAnage=sqlQuery.value("MoveAnage").toInt();              //小车进出充电位置 姿态以及移动角度
            AGVCurrentTaskI->ChargeAction=sqlQuery.value("ChargeAction").toInt();        //充电动作指令
            AGVCurrentTaskI->ChargeTimer=sqlQuery.value("ChargeTimer").toInt();          //充电计时 还剩余多少 分钟  60 *60 =3600秒
            AGVCurrentTaskI->ChargeAction_all=sqlQuery.value("ChargeAction_all").toInt();//总的充电动作逻辑

            if(!CurrentServerItem.AGVCurrentTaskMap.contains(AGVCurrentTaskI->AGVIP)
                    && AGVCurrentTaskI->enable==1){
                CurrentServerItem.AGVCurrentTaskMap.insert(AGVCurrentTaskI->AGVIP,AGVCurrentTaskI);
                ServerInitItem.AGVIPInitMap.insert(AGVCurrentTaskI->AGVIP,AGVCurrentTaskI->waitPoint);              //AGVIP 与 待机点
                //qDebug()<<"AGVIP:"<<AGVCurrentTaskI.AGVIP<<" AGVType:"<<AGVCurrentTaskI.AGVType<<" chargeIP:"<<AGVCurrentTaskI.chargeIP;
            }

        }
    }

}

void threadServer::LiftTaskInit()
{

    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    sqlQuery.setForwardOnly(true);
    sqlQuery.prepare("select * from LiftTask ;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            LiftCode LiftCodeI;
            LiftCodeI.codeDesc=sqlQuery.value("codeDesc").toString();           //升降机接驳台命名 2F-IN
            LiftCodeI.Liftstatus=sqlQuery.value("Liftstatus").toInt();          //升降机感应器状态 (IN-D100 D103 D105:1可放料,2-3去X楼) (OUT-D101 D102 D104: 1可取料,2取料完成)
            LiftCodeI.codeType=sqlQuery.value("codeType").toString();           //(IN- D100 D103 D105:1可放料,2-3去X楼)  ( OUT- D101 D102 D104: 1可取料,2取料完成)
            LiftCodeI.status=sqlQuery.value("status").toInt();                  //任务锁定状态:0空闲  1 锁定  2到达 0空闲
            LiftCodeI.SAPTaskIndex=sqlQuery.value("SAPTaskIndex").toInt();      //任务索引 唯一值
            LiftCodeI.containerCode=sqlQuery.value("containerCode").toString(); //容器编码 (即胶箱编码) ->唯一
            if(!CurrentServerItem.LiftCodeMap.contains(LiftCodeI.codeDesc)){
                CurrentServerItem.LiftCodeMap.insert(LiftCodeI.codeDesc,LiftCodeI);
//                qDebug()<<"codeDesc:"<<LiftCodeI.codeDesc<<" status:"<<LiftCodeI.status
//                       <<" SAPTaskIndex:"<<LiftCodeI.SAPTaskIndex<<" containerCode:"<<LiftCodeI.containerCode;
            }
        }
    }
}

void threadServer::taskStatusMapInit()
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.setForwardOnly(true);
    ServerInitItem.taskStatusMap.clear();
    sqlQuery.prepare("select * from StatusMap;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            ServerInitItem.taskStatusMap.insert(sqlQuery.value("statusId").toString(),sqlQuery.value("taskStatus").toString());
        }
    }

}

void threadServer::errorTypeMapInit()
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.setForwardOnly(true);
    ServerInitItem.errorTypeMap.clear();
    sqlQuery.prepare("select * from errorType;");//操作时 错误类型 错误码与译文
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            ServerInitItem.errorTypeMap.insert(sqlQuery.value("errorTypeId").toInt(),sqlQuery.value("errorTypeDesc").toString());
        }
    }
}

void threadServer::StationCodeMapInit()
{

    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.setForwardOnly(true);
    ServerInitItem.StationCodeMap.clear();
    sqlQuery.prepare("select * from StationCode;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            //qDebug()<<sqlQuery.value("pickDesc").toString()<<sqlQuery.value("positionCode").toString();
            ServerInitItem.StationCodeMap.insert(sqlQuery.value("pickDesc").toString(),sqlQuery.value("positionCode").toString());
        }
    }
}

void threadServer::eventCodeMapInit()
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.setForwardOnly(true);
    ServerInitItem.eventCodeMap.clear();
    sqlQuery.prepare("select * from eventCodeMap;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            QMap<QString,eventCode>eventCodeMap;      //ESS-P 事件 回调类型
            eventCode eventCodeI;
            eventCodeI.eventCode=sqlQuery.value("eventCode").toString();
            eventCodeI.eventCodeDesc=sqlQuery.value("eventCodeDesc").toString();
            eventCodeI.taskType_IN=sqlQuery.value("taskType_IN").toString();
            eventCodeI.taskType_OUT=sqlQuery.value("taskType_OUT").toString();
            eventCodeI.taskType_Empty=sqlQuery.value("taskType_Empty").toString();

            ServerInitItem.eventCodeMap.insert(eventCodeI.eventCode,eventCodeI);
            //qDebug()<<eventCodeI.eventCode<<eventCodeI.eventCodeDesc<<eventCodeI.taskType_IN<<eventCodeI.taskType_OUT;
        }
    }

}

void threadServer::StationPointMapInit()
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    sqlQuery.setForwardOnly(true);
    sqlQuery.prepare("select * from deviceI where  enable =:enable;");
    sqlQuery.addBindValue(1);
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            deviceI deviceItem;
            /******************* 接驳台类型 **************/
            deviceItem.stationDesc=sqlQuery.value("stationDesc").toString();         //站点名称
            deviceItem.Currentpoint=sqlQuery.value("Currentpoint").toInt();          //当前所在二维码
            ServerInitItem.StationPointMap.insert(deviceItem.stationDesc,deviceItem.Currentpoint);
        }
    }

}

void threadServer::shelfBinInfoMapInit()
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.setForwardOnly(true);
    sqlQuery.prepare("select * from shelfInfo ;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            shelfBinInfo shelfBinInfoI;
            shelfBinInfoI.shelfBinIndex=sqlQuery.value("shelfBinIndex").toInt();        //所属架位索引
            shelfBinInfoI.shelfBindesc=sqlQuery.value("shelfBindesc").toString();       //所属架位注释
            shelfBinInfoI.podIdDesc=sqlQuery.value("podIdDesc").toString();             //货架注释
            ServerInitItem.BindescPodIdMap.insert(shelfBinInfoI.podIdDesc,shelfBinInfoI.shelfBindesc);
        }
    }

}
