#include "ess_single.h"
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase)

ESS_Single* ESS_Single::ESS_SingleItiem=0;
QMutex ESS_Single::mutex;

ESS_Single::ESS_Single(QObject *parent)
{

}

void ESS_Single::setCurrentServerItem(ServerItem CServerItem, ServerInit CServerInit)
{
    if(ServerItemcount<100){
        ServerItemcount++;
    }
    ServerInitItem=CServerInit;
    CurrentServerItem=CServerItem;
    if(!CurrentServerItem.shelfBinInfoMap.isEmpty()){
        shelfBinInfoMap=CurrentServerItem.shelfBinInfoMap;
    } if(StationInfoMap.isEmpty() && !CurrentServerItem.StationInfoMap.isEmpty()){
        StationInfoMap=CurrentServerItem.StationInfoMap;
    }

}

ServerItem ESS_Single::getCurrentServerItem()
{
    if(ServerItemcount>=100){
        return CurrentServerItem;
    }
    ServerItem CServerItem;
    return CServerItem;
}

bool ESS_Single::setNewSAPExcelInfoList(SAPExcelInfo SAPExcelInfoI)
{
    if(!newSAPExcelInfoList.contains(SAPExcelInfoI.taskId)){
        newSAPExcelInfoList.insert(SAPExcelInfoI.taskId,SAPExcelInfoI);
        return true;
    }
    return false;
}

QMap<QString, SAPExcelInfo> ESS_Single::getNewSAPExcelInfoList()
{
    QMap<QString, SAPExcelInfo>newSAPExcelInfoListI;
    newSAPExcelInfoListI=newSAPExcelInfoList;
    newSAPExcelInfoList.clear();
    return newSAPExcelInfoListI;

}

QMap<int, SAPExcelInfo> ESS_Single::getCurrentSAPExcelInfoTask()
{
    return  CurrentServerItem.currentSAPExcelInfoTask;
}

void ESS_Single::setshelfBinInfoMap(QMap<QString, shelfBinInfo> shelfBinInfoMap_)
{
    shelfBinInfoMap=shelfBinInfoMap_;
}

QMap<QString, shelfBinInfo> ESS_Single::getshelfBinInfoMap()
{
    QMap<QString, shelfBinInfo> shelfBinInfoMap_;
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

            if(!shelfBinInfoMap_.contains(shelfBinInfoI.shelfBindesc)){
                shelfBinInfoMap_.insert(shelfBinInfoI.shelfBindesc,shelfBinInfoI);
                //qDebug()<<shelfBinInfoI.shelfBinIndex<<shelfBinInfoI.shelfBindesc<<shelfBinInfoI.podId<<shelfBinInfoI.podIdDesc;
            }
        }
    }

    if(!shelfBinInfoMap_.isEmpty()){
        shelfBinInfoMap=shelfBinInfoMap_;
        return shelfBinInfoMap_;
    }

    return  shelfBinInfoMap;
}


//入库时获取空闲的 库位
shelfBinInfo ESS_Single::getshelfBinInfo_Empty(SAPExcelInfo SAPExcelInfoI)
{
    shelfBinInfo shelfBinInfoI;
    QMap<QString ,shelfBinInfo>::const_iterator iter=shelfBinInfoMap.begin();
    while (iter!=shelfBinInfoMap.end()) {
        if(iter!=nullptr){
            if(SAPExcelInfoI.destination!="" && SAPExcelInfoI.destination.size()==10){
                if(SAPExcelInfoI.destination==iter.value().podIdDesc){
                    shelfBinInfoI=iter.value();//指定库位入库
                }
            }else{//获取空闲的库位
                if(shelfBinInfoI.shelfBinIndex==0 && iter.value().containerCode==""){
                    shelfBinInfoI=iter.value();
                }if(shelfBinInfoI.shelfBinIndex>iter.value().shelfBinIndex && iter.value().containerCode==""){
                    shelfBinInfoI=iter.value();
                }
            }
        }else{
            qDebug()<<"getshelfBinInfo_Empty --E->  shelfBindesc:"<<shelfBinInfoI.shelfBindesc<<" podIdDesc:"<<shelfBinInfoI.podIdDesc;
            return shelfBinInfoI;
        }
        iter++;
    }

    qDebug()<<"getshelfBinInfo_Empty --S->  shelfBindesc:"<<shelfBinInfoI.shelfBindesc<<" podIdDesc:"<<shelfBinInfoI.podIdDesc;

    return shelfBinInfoI;
}

//出库时获取当前胶箱库位
shelfBinInfo ESS_Single::getcontainerCode_desc(QString containerCode)
{
    shelfBinInfo shelfBinInfoI;
    QMap<QString,shelfBinInfo >::iterator iter=shelfBinInfoMap.begin();
    while (iter!=shelfBinInfoMap.end()) {
        if(iter.value().containerCode == containerCode && containerCode!=""){
            shelfBinInfoI=iter.value();
        }
        iter++;
    }
    return shelfBinInfoI;
}

void ESS_Single::UP_StationInfoMap(QMap<QString, StationInfo> StationInfoMap_)
{
    StationInfoMap=StationInfoMap_;
}

QMap<QString, StationInfo> ESS_Single::getStationInfoMap()
{
    return StationInfoMap;
}

void ESS_Single::setLiftCodeMap(QMap<QString, LiftCode> LiftCodeMap_)
{
    LiftCodeMap=LiftCodeMap_;
}

QMap<QString, LiftCode> ESS_Single::getLiftCodeMap()
{
    if(LiftCodeMap.isEmpty()){
        LiftCodeMap=CurrentServerItem.LiftCodeMap;
    }
    return LiftCodeMap;
}

void ESS_Single::setESSRobot(QString robotCode, ESSRobot ESSRobotI)
{
    if(!ESSRobotInfoMap.contains(robotCode)){
        ESSRobotInfoMap.insert(robotCode,ESSRobotI);
        qDebug()<<"setESSRobot--------->robotCode:"<<robotCode;
    }
}


ESS_Request ESS_Single::setESS_RequestI(SAPExcelInfo SAPExcelInfoI, ESS_Request ESS_RequestI,QString actionId)
{

    qDebug()<<"actionId:"<<actionId<<"actionId:"<<ESS_RequestI.actionId;
    QMap<int ,sapPath >::iterator iter=ServerInitItem.sapPathMap.begin();
    while (iter !=ServerInitItem.sapPathMap.end()) {//
        if(actionId==iter.value().Type){
            ESS_RequestI.pathId=iter.value().Id;
            ESS_RequestI.actionId=iter.value().Type;

            ESS_RequestI.taskGroupCode=iter.value().para1+QDateTime::currentDateTime().toString("zzz");          //任务组号
            ESS_RequestI.taskTemplateCode=iter.value().para2;
        }
        iter++;
    }

    qDebug()<<"actionId1:"<<actionId<<"actionId1:"<<ESS_RequestI.actionId;

    /********** 任务指令 ************/
    ESS_RequestI.groupPriority="0";                                 //组优先级
    ESS_RequestI.taskCodes.append(SAPExcelInfoI.taskId_ess);          //ESS-P 任务号 数组

    /********** tasks  任务列表************/
    ESS_RequestI.taskCode=SAPExcelInfoI.taskId_ess;                   //ESS-P 当前任务号
    ESS_RequestI.taskPriority="0";                                  //任务优先级

    /********** tasks  任务列表 (taskDescribe  任务描述) ************/
    ESS_RequestI.containerCode=SAPExcelInfoI.containerCode;         //货箱编码

    if(SAPExcelInfoI.taskType=="OUT"){      //action2
        ESS_RequestI.toStationCode=SAPExcelInfoI.pickDesc_s;              //(出库)目标工作站编码
        ESS_RequestI.positionCode=ServerInitItem.StationCodeMap.value(SAPExcelInfoI.pickDesc_s);//容器入场 / 容器离场 (入库时对接 输送线对接码头   出库时对应放箱码头)
    }if(SAPExcelInfoI.taskType=="MOVE"){    //action3
        ESS_RequestI.fromLocationCode=SAPExcelInfoI.sourcestation;      //(出库)起始工作位  (移库)起始库位编码
        ESS_RequestI.toLocationCode=SAPExcelInfoI.destination;          //(移库 回库)目标库位编码
    }if(SAPExcelInfoI.taskType=="IN"){      //action4
        ESS_RequestI.toLocationCode=SAPExcelInfoI.shelfBindesc;          //(移库 回库--即入库)目标库位编码
        ESS_RequestI.positionCode=ServerInitItem.StationCodeMap.value(SAPExcelInfoI.pickDesc_s);//容器入场 / 容器离场 (入库时对接 输送线对接码头   出库时对应放箱码头)
    }

    if(ESS_RequestI.pathId!=0){
        QString iKey=SAPExcelInfoI.taskId_ess;
        //QString iKey=QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");
        if(ESS_RequestI.actionId=="action0"){//机器人状态查询
            sapMsgInterface::getInstance()->robotCodes_query(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
        }if(ESS_RequestI.actionId=="action1"){//任务状态查询
            sapMsgInterface::getInstance()->taskCodes_query(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
        }if(ESS_RequestI.actionId=="action2"){//下达出库任务
            sapMsgInterface::getInstance()->taskCodes_actionId(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
        }if(ESS_RequestI.actionId=="action3"){//下达移库任务
            sapMsgInterface::getInstance()->taskCodes_actionId(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
        }if(ESS_RequestI.actionId=="action4"){//下达入库(回库)任务
            sapMsgInterface::getInstance()->taskCodes_actionId(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
        }if(ESS_RequestI.actionId=="action5"){//任务取消
            sapMsgInterface::getInstance()->taskCodes_cancel(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
        }if(ESS_RequestI.actionId=="action6"){//容器入场
            sapMsgInterface::getInstance()->taskCodes_actionId(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
        }if(ESS_RequestI.actionId=="action7"){//容器离场
            sapMsgInterface::getInstance()->taskCodes_actionId(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
        }
    }

    qDebug()<<"setESS_RequestI---> actionId:"<<ESS_RequestI.actionId<<" pathId:"<<ESS_RequestI.pathId<<" taskType:"<<SAPExcelInfoI.taskType<<" Material:"<<SAPExcelInfoI.Material
           <<" containerCode:"<<SAPExcelInfoI.containerCode<<" pickDesc:"<<SAPExcelInfoI.pickDesc_s
           <<" destination:"<<SAPExcelInfoI.destination<<" sourcestation:"<<SAPExcelInfoI.sourcestation;
    return ESS_RequestI;
}

QMap<QString, ESS_Request> ESS_Single::setESS_RequestI_Map(QMap<int, SAPExcelInfo> SAPExcelInfoTask, ESS_Request ESS_RequestI,QString actionId)
{
    QMap<QString, ESS_Request>ESS_RequestMap;
    QMap<int, SAPExcelInfo>::iterator iter=SAPExcelInfoTask.begin();
    while (iter!=SAPExcelInfoTask.end()) {
        //ESS_Request ESS_RequestI;

        QMap<int ,sapPath >::iterator iter1=sapPathMap.begin();
        while (iter1 !=sapPathMap.end()) {//
            if(actionId==iter1.value().Type){
                ESS_RequestI.pathId=iter1.value().Id;
                ESS_RequestI.actionId=iter1.value().Type;

                ESS_RequestI.taskGroupCode=iter1.value().para1+QDateTime::currentDateTime().toString("zzz");          //任务组号
                ESS_RequestI.taskTemplateCode=iter1.value().para2;
            }
            iter1++;
        }

        /********** 任务指令 ************/
        ESS_RequestI.groupPriority="0";                                 //组优先级
        ESS_RequestI.taskCodes.append(iter.value().taskId_ess);          //ESS-P 任务号 数组

        /********** tasks  任务列表************/
        ESS_RequestI.taskCode=iter.value().taskId_ess;                   //ESS-P 当前任务号
        ESS_RequestI.taskPriority="0";                                  //任务优先级

        /********** tasks  任务列表 (taskDescribe  任务描述) ************/
        ESS_RequestI.containerCode=iter.value().containerCode;         //货箱编码

        ESS_RequestI.toStationCode=iter.value().pickDesc_s;              //(出库)目标工作站编码

        ESS_RequestI.toLocationCode=iter.value().destination;          //(移库 回库)目标库位编码
        ESS_RequestI.fromLocationCode=iter.value().sourcestation;      //(出库)起始工作位  (移库)起始库位编码

        ESS_RequestI.positionCode=ServerInitItem.StationCodeMap.value(iter.value().pickDesc_s);//容器入场 / 容器离场 (入库时对接 输送线对接码头   出库时对应放箱码头)
        if(!ESS_RequestMap.contains(ESS_RequestI.taskCode)){
            ESS_RequestMap.insert(ESS_RequestI.taskCode,ESS_RequestI);
        }

        iter++;
    }

    if(!ESS_RequestMap.isEmpty()){
        QString iKey=QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");
        sapMsgInterface::getInstance()->taskCodes_actionId_Map(iKey,ESS_RequestMap,"",ESS_RequestMap.first().pathId);
    }

    return ESS_RequestMap;
}

bool ESS_Single::setCurrentESS_Repost( QString taskId_ess,QString eventCodeDesc)
{
    CurrentESS_RepostMap.insert(taskId_ess,eventCodeDesc);
    qDebug()<<"----> taskId_ess:"<<taskId_ess<<" eventCodeDesc:"<<eventCodeDesc<<" size:"<<CurrentESS_RepostMap.size();
    return true;
}

QString ESS_Single::getCurrentESS_Repost(QString taskId_ess)
{
    QString eventCodeDesc="";
    if(CurrentESS_RepostMap.contains(taskId_ess)){
         eventCodeDesc=CurrentESS_RepostMap.value(taskId_ess);
         CurrentESS_RepostMap.remove(taskId_ess);
    }
    return eventCodeDesc;
}

QMap<int, SAPExcelInfo> ESS_Single::getSAPExcelInfoTask(QMap<int, SAPExcelInfo> SAPExcelInfoTask)
{
    QMap<int, SAPExcelInfo>::const_iterator iter= CurrentServerItem.currentSAPExcelInfoTask.begin();
    while (iter!=CurrentServerItem.currentSAPExcelInfoTask.end()){
        if(iter!=nullptr){
            if(!SAPExcelInfoTask.contains(iter.value().SAPTaskIndex)){
                SAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
            }else{
                int taskStatus=SAPExcelInfoTask.value(iter.value().SAPTaskIndex).taskStatus;
                qDebug()<<"任务变化:"<<iter.value().SAPTaskIndex<<iter.value().taskStatus<<taskStatus;
                if(iter.value().taskStatus>taskStatus){
                    SAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
                    qDebug()<<"任务状态变化:"<<iter.value().SAPTaskIndex<<iter.value().taskStatus<<iter.value().taskStatusDesc;
                }
            }
        }else{
            return SAPExcelInfoTask;
        }
        //qDebug()<<"SAPTaskIndex:"<<iter.value().SAPTaskIndex<<iter.value().taskStatus<<iter.value().taskStatusDesc;
        iter++;
    }
    return SAPExcelInfoTask;
}

WWYLPOST ESS_Single::getWWYLPOSTI(SAPExcelInfo SAPExcelInfoI, QString actionId)
{
    WWYLPOST WWYLPOST1;
    WWYLPOST1.actionId=actionId;
    WWYLPOST1.taskId=SAPExcelInfoI.taskId_ess;      //夹抱机器人 任务编码 唯一性
    WWYLPOST1.operate=SAPExcelInfoI.taskType;       //操作,IN-入库，OUT-出库
    WWYLPOST1.boxNo=SAPExcelInfoI.containerCode;    //箱号
    WWYLPOST1.pcbList=SAPExcelInfoI.MaterialList;   //pcb集合
    WWYLPOST1.source=SAPExcelInfoI.sourcestation;   //来源 入库为NULL，出库为库位
    WWYLPOST1.destination=SAPExcelInfoI.destination;//目的地。入库为仓库，出库为线体
    WWYLPOST1.resultStatus=QString::number(SAPExcelInfoI.taskStatus);//执行结果,1-开始执行，2-执行中，3执行失败，4-执行成功

//    qDebug()<<" getWWYLPOSTI:"<<WWYLPOST1.actionId<<WWYLPOST1.operate<<WWYLPOST1.boxNo<<WWYLPOST1.pcbList
//           <<WWYLPOST1.resultStatus<<" SAPTaskIndex:"<<SAPExcelInfoI.SAPTaskIndex<<SAPExcelInfoI.taskStatusDesc;

    return WWYLPOST1;
}

void ESS_Single::getAGVInfo()
{
    QString RobotIP="";
    QSqlDatabase db = Singleton<ConnectionPool>::getInstance().getConnection();
    if(!db.connectionName().isEmpty()){
        QSqlQuery query(db);
        query.exec("select * from robotInfo");
        while(query.next()){
            RobotIP=query.value("robotIP").toString();
            qDebug()<<"RobotIP:"<<RobotIP;
        }
    }
    Singleton<ConnectionPool>::getInstance().releaseConnection(db);
}

ESS_Single *ESS_Single::GetInstance()
{
    if(ESS_SingleItiem != nullptr){
        return ESS_SingleItiem;
    }else{
        mutex.lock();
        ESS_SingleItiem=new ESS_Single;
        mutex.unlock();
        return ESS_SingleItiem;
    }
}
