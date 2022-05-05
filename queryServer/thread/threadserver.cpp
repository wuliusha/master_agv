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
    if(!allSeverInit()){ //所有基础信息  均初始化完成
        return;
    }
    if(!Servercountbool){return;}
    threadServercount++;
    if(threadServercount%5==0 && Servercountbool){
        Servercountbool=false;
        CurrentServerItem.currentSAPExcelInfoTask=readSAPExcelInfoTask(99,"run");        //SAP 正在执行或未完成的任务 taskstatus<=4
        Servercountbool=true;
    }

    if(threadServercount%3==0 && Servercountbool){
        Servercountbool=false;
        if(CurrentServerItem.shelfBinInfoMap.isEmpty()){
            shelfBinInfoMapInit();                          //实时获取 Bin 的基础信息
        }if(CurrentServerItem.StationInfoMap.isEmpty()){    //所有站点的基础信息
            StationInfoMapMapInit();
        }if(CurrentServerItem.AGVCurrentTaskMap.isEmpty()){ //当前AGV运行信息
            AGVTCurrentTask_Init();
        }
        Servercountbool=true;
    }

    queryServer::getInstance()->setCurrentServerInitItem(ServerInitItem);               //基础信息
    ESS_Single::GetInstance()->setCurrentServerItem(CurrentServerItem,ServerInitItem);  //需要实时更信息 链表表 整合

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
    if(taskType=="run"){
        sqlQuery.prepare("select * from sapExcelinfo "
                         "where (taskStatus >=:taskStatus and taskStatus <=:taskStatus) or "
                         "(creatTimer >=:creatTimer or finishTimer >=:finishTimer);");
        sqlQuery.addBindValue(0);
        sqlQuery.addBindValue(taskstatus);
        sqlQuery.addBindValue(QDateTimeS);
        sqlQuery.addBindValue(QDateTimeS);

    }else if(taskType=="select"){
        sqlQuery.prepare("select * from sapExcelinfo "
                         "where (taskStatus >=:taskStatus and taskStatus <=:taskStatus) or "
                         "(creatTimer >=:creatTimer or finishTimer >=:finishTimer);");
        sqlQuery.addBindValue(0);
        sqlQuery.addBindValue(99);
        sqlQuery.addBindValue(QDateTimeS);
        sqlQuery.addBindValue(QDateTimeS);
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
            SAPExcelInfoI.floorId=sqlQuery.value("floorId").toString();         //楼层走向  2F-3F 3F-2F

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
                //qDebug()<<"wait119:"<<SAPExcelInfoI.SAPTaskIndex<<SAPExcelInfoI.Material<<SAPExcelInfoI.taskStatus<<SAPExcelInfoI.taskTimer;
            }
            //qDebug()<<missionInfoI.ikey<<missionInfoI.updateQty<<sqlQuery.record();
        }
    }else {
        qDebug()<<"queryNewMissionInfo"<<sqlQuery.record();
    }

    return SAPExcelInfoTask;
}

bool threadServer::allSeverInit()
{
    if(!Servercountbool){return false;}
    Servercountbool=false;
    if(ServerInitItem.sapPathMap.isEmpty()){
        setSapPathMap();                            //读取数据库的路径配置信息
    }if(ServerInitItem.UserInfoList.isEmpty()){
        UserInfoListInit();                         //获取登录用户信息
    }if(ServerInitItem.taskStatusMap.isEmpty()){
        taskStatusMapInit();                        //任务状态的错误码与译文
    }if(ServerInitItem.errorTypeMap.isEmpty()){
        errorTypeMapInit();                         //任务状态的错误码与译文
    }if(ServerInitItem.StationCodeMap.isEmpty()){   //工作站与 ESS-P坐标点
        StationCodeMapInit();
    } if(ServerInitItem.eventCodeMap.isEmpty()){    //ESS-P 事件 回调类型
        eventCodeMapInit();
    }if(ServerInitItem.doorSubTaskMap.isEmpty()){   //所有自动门的基础信息
        automaticDoorMapInit();
    }if(CurrentServerItem.LiftCodeMap.isEmpty()){
        LiftTaskInit();                             //获取升降机的任务信息
    }


    Servercountbool=true;
    return true;
}

void threadServer::setSapPathMap()
{

    int currentsapPath=17;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.setForwardOnly(true);
    if(currentsapPath==30){
        sqlQuery.prepare("select * from sapPath_New;");
    }else {
        sqlQuery.prepare("select * from sapPath;");
    }

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
            shelfBinInfoI.podId=sqlQuery.value("podId").toInt();                        //货架编号
            shelfBinInfoI.podIdDesc=sqlQuery.value("podIdDesc").toString();             //货架注释

            shelfBinInfoI.containerIndex=sqlQuery.value("containerIndex").toInt();      //容器编码索引 ->唯一
            shelfBinInfoI.containerCode=sqlQuery.value("containerCode").toString();     //容器编码 (即胶箱编码) ->唯一
            shelfBinInfoI.LabelNo=sqlQuery.value("LabelNo").toString();                 //工单凭证号
            shelfBinInfoI.storeCode=sqlQuery.value("storeCode").toString();             //仓号属性

            shelfBinInfoI.binEnable=sqlQuery.value("binEnable").toInt();                //使用/禁用
            shelfBinInfoI.showEnable=sqlQuery.value("showEnable").toInt();              //是否显示
            shelfBinInfoI.setFull=sqlQuery.value("setFull").toInt();                    //0未满  1已满
            shelfBinInfoI.status=sqlQuery.value("status").toInt();                      //0 空闲  1任务占用中

            shelfBinInfoI.layer=sqlQuery.value("layer").toInt();                        //第几层
            shelfBinInfoI.side=sqlQuery.value("side").toInt();                          //A,B 面

            shelfBinInfoI.volume=sqlQuery.value("volume").toDouble();                   //Bin的体积 14升
            shelfBinInfoI.allvolume=sqlQuery.value("allvolume").toDouble();             //总体积

            shelfBinInfoI.percent=sqlQuery.value("percent").toDouble();                 //占用 %
            shelfBinInfoI.realqty=sqlQuery.value("realqty").toDouble();                 //实际存放数量

            shelfBinInfoI.weight=sqlQuery.value("weight").toDouble();                   //实际存放重量
            shelfBinInfoI.maxweight=sqlQuery.value("maxweight").toDouble();             //最大存放重量

            CurrentServerItem.PoidAndDesc.insert(shelfBinInfoI.podIdDesc,shelfBinInfoI.shelfBindesc);
            if(!CurrentServerItem.shelfBinInfoMap.contains(shelfBinInfoI.shelfBindesc)){
                CurrentServerItem.shelfBinInfoMap.insert(shelfBinInfoI.shelfBindesc,shelfBinInfoI);
                //qDebug()<<shelfBinInfoI.shelfBinIndex<<shelfBinInfoI.shelfBindesc<<shelfBinInfoI.podId<<shelfBinInfoI.podIdDesc;
            }
        }
    }

}

void threadServer::StationInfoMapMapInit()
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    sqlQuery.setForwardOnly(true);
    sqlQuery.prepare("select * from StationInfo ;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            StationInfo StationInfoI;
            StationInfoI.StationId=sqlQuery.value("StationId").toInt();           //站点Id
            StationInfoI.StationDesc=sqlQuery.value("StationDesc").toString();    //站点名称
            StationInfoI.StationIP=sqlQuery.value("StationIP").toString();        //站点IP地址
            StationInfoI.floor=sqlQuery.value("floor").toInt();
            StationInfoI.action=sqlQuery.value("action").toInt();                   //当前动作指令
            StationInfoI.StationType=sqlQuery.value("StationType").toString();      //站点类型  IN二楼入库  OUT二楼出库   2F_L二楼升降机 3F_L三楼升降机  3F_S 三楼产线
            StationInfoI.page=sqlQuery.value("page").toInt();                       //当前页面索引

            StationInfoI.currentpoint=sqlQuery.value("currentpoint").toInt();       //站点所在二维码
            StationInfoI.liftpoint=sqlQuery.value("liftpoint").toInt();             //对应升降机的二维码

            StationInfoI.TaskIndexListdesc=sqlQuery.value("TaskIndexListdesc").toString();  //用于二楼出库时 判断接驳台任务分配
            StationInfoI.TaskIndexList=StationInfoI.TaskIndexListdesc.split("&");           //用于二楼出库时 判断接驳台任务分配
            //StationInfoI.TaskIndexListdesc= StationInfoI.TaskIndexList.join("&");

            StationInfoI.taskStatus=sqlQuery.value("taskStatus").toInt();           //任务状态  正在出库  正在入库
            StationInfoI.containerCode=sqlQuery.value("containerCode").toString();  //容器编码 (即胶箱编码) ->唯一

            StationInfoI.enable=sqlQuery.value("enable").toInt();                  //使用禁用使能

            ServerInitItem.StationPointMap.insert(StationInfoI.StationDesc,StationInfoI.currentpoint);//工作站名称 与 二维码绑定
            if(!CurrentServerItem.StationInfoMap.contains(StationInfoI.StationIP)
                    && StationInfoI.enable==1){
                CurrentServerItem.StationInfoMap.insert(StationInfoI.StationIP,StationInfoI);
                qDebug()<<StationInfoI.StationType<<StationInfoI.StationId<<StationInfoI.StationDesc<<StationInfoI.containerCode;
            }
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
            AGVCurrentTask AGVCurrentTaskI;
            AGVCurrentTaskI.AGVId=sqlQuery.value("AGVId").toInt();                      //小车编号
            AGVCurrentTaskI.AGVIP=sqlQuery.value("AGVIP").toString();                   //小车 ip
            AGVCurrentTaskI.enable=sqlQuery.value("enable").toInt();                    //1使用  0禁用
            AGVCurrentTaskI.AGVType=sqlQuery.value("AGVType").toInt();                  //AGV类型    0默认小精灵   1夹抱AGV
            AGVCurrentTaskI.floornum=sqlQuery.value("floornum").toInt();                //AGV所在楼层
            AGVCurrentTaskI.waitPoint=sqlQuery.value("waitPoint").toInt();              //待机点二维码

            AGVCurrentTaskI.Currentdestpoint=sqlQuery.value("Currentdestpoint").toInt();//当前目标二维码
            AGVCurrentTaskI.destpoint=sqlQuery.value("destpoint").toInt();              //第一个目标二维码
            AGVCurrentTaskI.Nextdestpoint=sqlQuery.value("Nextdestpoint").toInt();      //下一个目标二维码
            AGVCurrentTaskI.waitdestpoint=sqlQuery.value("waitdestpoint").toInt();      //目标点等待点二维码

            AGVCurrentTaskI.Action_agv=sqlQuery.value("Action_agv").toInt();            //二维码带举升动作
            AGVCurrentTaskI.Action_ess=sqlQuery.value("Action_ess").toInt();            //夹包机器人
            AGVCurrentTaskI.Action_all=sqlQuery.value("Action_all").toInt();            //总动作计数
            AGVCurrentTaskI.actionType=sqlQuery.value("actionType").toInt();            //动作类型 0到达站点不需要返回  1到达站点倒计时结束后返回

            AGVCurrentTaskI.taskId=sqlQuery.value("taskId").toString();                 //唯一识别号
            AGVCurrentTaskI.lastTaskId=sqlQuery.value("lastTaskId").toString();         //上一个任务--唯一识别号
            AGVCurrentTaskI.taskType=sqlQuery.value("taskType").toString();             //任务类型 IN入库  OUT出库
            AGVCurrentTaskI.SAPTaskIndex=sqlQuery.value("SAPTaskIndex").toInt();        //任务索引 唯一值
            AGVCurrentTaskI.containerCode=sqlQuery.value("containerCode").toString();   //容器编码 (即胶箱编码) ->唯一

            AGVCurrentTaskI.chargeIP=sqlQuery.value("chargeIP").toString();             //充电桩IP
            AGVCurrentTaskI.ChargePoint=sqlQuery.value("ChargePoint").toInt();          //充电点二维码
            AGVCurrentTaskI.ChargeWait=sqlQuery.value("ChargeWait").toInt();            //充电点前一个二维码
            AGVCurrentTaskI.MoveAnage=sqlQuery.value("MoveAnage").toInt();              //小车进出充电位置 姿态以及移动角度
            AGVCurrentTaskI.ChargeAction=sqlQuery.value("ChargeAction").toInt();        //充电动作指令
            AGVCurrentTaskI.ChargeTimer=sqlQuery.value("ChargeTimer").toInt();          //充电计时 还剩余多少 分钟  60 *60 =3600秒
            AGVCurrentTaskI.ChargeAction_all=sqlQuery.value("ChargeAction_all").toInt();//总的充电动作逻辑

            if(!CurrentServerItem.AGVCurrentTaskMap.contains(AGVCurrentTaskI.AGVIP)
                    && AGVCurrentTaskI.enable==1){
                CurrentServerItem.AGVCurrentTaskMap.insert(AGVCurrentTaskI.AGVIP,AGVCurrentTaskI);
                ServerInitItem.AGVIPInitMap.insert(AGVCurrentTaskI.AGVIP,AGVCurrentTaskI.waitPoint);              //AGVIP 与 待机点
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

