#include "transformarray.h"
transFormArray* transFormArray::transFormArrayItiem=0;
QMutex transFormArray::mutex;

transFormArray::transFormArray(QObject *parent)
{
    analysDescMap.insert("A","甲班");
    analysDescMap.insert("B","乙班");
    analysDescMap.insert("C","丙班");
    analysDescMap.insert("1","低温库");
    analysDescMap.insert("2","高温库");

}

void transFormArray::setServerItemcount(int Itemcount)
{
    ServerItemcount=Itemcount;
}

void transFormArray::setCurrentServerItem(ServerItem CServerItem)
{
     if(ServerItemcount<100){
         ServerItemcount++;
     }
     CurrentServerItem=CServerItem;
}

ServerItem transFormArray::getCurrentServerItem()
{
    if(ServerItemcount>=100){
        return CurrentServerItem;
    }
    ServerItem CServerItem;
    return CServerItem;
}

void transFormArray::setShelfBinInfoMapInit(QMap<int, shelfBinInfo> shelfBinInfoMap)
{
    currentShelfBinInfoMap=shelfBinInfoMap;
}

QByteArray transFormArray::getAGVCurrentTaskInfo()
{
    return AGVCurrentAnalysisArray;
}

//void transFormArray::setAGVCurrentTaskInfo(QMap<QString, AGVCurrentTask> AGVCurrentTaskMap_1,int AGVChargeAction_all)
//{
//    QJsonObject ReJson;
//    QJsonArray rootFruitList;
////    QMap<QString,AGVCurrentTask>::const_iterator iter= AGVCurrentTaskMap_1.begin();
////    while (iter!=AGVCurrentTaskMap_1.end()){
////        QJsonObject tasksJson;
////        tasksJson.insert("AGVIP",iter.value().AGVIP);
////        if(iter.value().isOnline){
////            if(AGVChargeAction_all>0){
////                tasksJson.insert("isOnline","在线-充电");
////            }else{
////                tasksJson.insert("isOnline","在线");
////            }
////        }else {
////            if(AGVChargeAction_all>0){
////                tasksJson.insert("isOnline","离线-充电");
////            }else{
////                tasksJson.insert("isOnline","离线");
////            }
////        }
////        tasksJson.insert("keyId",iter.value().keyId);
////        tasksJson.insert("taskType",iter.value().taskType);
////        tasksJson.insert("taskStatusDesc",iter.value().taskStatusDesc);
////        tasksJson.insert("Currentpoint",QString::number(iter.value().Currentpoint));

////        int point=iter.value().Currentpoint;
////        if(point>0 && point<=145){
////            tasksJson.insert("pointAreaDesc","保温室");
////        }if(point>145 && point<=222){
////            tasksJson.insert("pointAreaDesc","主通道");
////        }if(point>222 && point<=292){
////            tasksJson.insert("pointAreaDesc","缓冲车间");
////        }if(point>=293 && point<=360){
////            tasksJson.insert("pointAreaDesc","罐装车间");
////        }

////        tasksJson.insert("VoltageState",QString::number(iter.value().VoltageState));
////        tasksJson.insert("agverror",CurrentServerItem.errorTypeMap.value(iter.value().agverror));

////        mapPoint mapPoint0=CurrentServerItem.currentMapPoint.value(iter.value().Currentpoint);
////        if(mapPoint0.cardPoint>0.00){
////            tasksJson.insert("movex",QString::number(int(mapPoint0.movex)));
////            tasksJson.insert("movey",QString::number(int(mapPoint0.movey)));
////            //qDebug()<<iter.value().AGVIP<<"movex"<<mapPoint0.movex<<"movey"<<mapPoint0.movey;
////        }

////        rootFruitList.append(tasksJson);
////        iter++;
////    }

////    ReJson.insert("taskType","AGVTask");      //类型识别号
////    ReJson.insert("ArrayType",rootFruitList);

//    AGVCurrentAnalysisArray = QJsonDocument(ReJson).toJson();


//}

shelfBinInfo transFormArray::getShelfBin_Emty(QString keyId, QString storage_Site, QString storage_Area)
{
    shelfBinInfo shelfBinInfoI;
    QMap<int ,shelfBinInfo >::const_iterator iter= currentShelfBinInfoMap.begin();  //实时获取 Bin 的基础信息
    while (iter!=currentShelfBinInfoMap.end()) {
//        if(iter.value().binEnable==1 && iter.value().storage_Site.right(3)== storage_Site
//                && iter.value().storage_Area==storage_Area){
//            if(iter.value().status==0 &&  iter.value().setFull==0){
//                if(shelfBinInfoI.shelfBinIndex==0){
//                    shelfBinInfoI=iter.value();
//                }if(iter.value().shelfBinIndex<=shelfBinInfoI.shelfBinIndex){
//                    shelfBinInfoI=iter.value();
//                }
//            }
//        }
        iter++;
    }

    if(shelfBinInfoI.shelfBinIndex>0){
        QMap<int, SAPExcelInfo>::iterator iter_= CurrentServerItem.currentSAPExcelInfoTask.begin();
        while (iter_!=CurrentServerItem.currentSAPExcelInfoTask.end()) {
            if(iter_.value().shelfBinIndex==shelfBinInfoI.shelfBinIndex
                    && (iter_.value().taskStatus<15 || (iter_.value().taskStatus>=20 && iter_.value().taskStatus<50))){
                shelfBinInfoI.shelfBinIndex=0;
                qDebug()<<"存在未完成任务-->"<<shelfBinInfoI.shelfBinIndex<<shelfBinInfoI.shelfBindesc
                       <<iter_.value().taskStatus;
            }
            iter_++;
        }
    }

    if(shelfBinInfoI.shelfBinIndex>0){
        QMap<int ,shelfBinInfo >::iterator iter= currentShelfBinInfoMap.begin();  //实时获取 Bin 的基础信息
        while (iter!=currentShelfBinInfoMap.end()) {
            if(shelfBinInfoI.shelfBinIndex==iter.value().shelfBinIndex){
                iter.value().setFull=1;
                iter.value().status=1;              //0 空闲  1任务占用中
                //iter.value().keyId=keyId;           //唯一识别号 由Lims 创建并绑定
            }
            iter++;
        }
    }

    qDebug()<<"getShelfBin_Emty-->"<<shelfBinInfoI.shelfBinIndex<<shelfBinInfoI.shelfBindesc<<" storage_Area:"<<storage_Site<<storage_Area;
    return shelfBinInfoI;
}

shelfBinInfo transFormArray::getShelfBin_Emty_(QString storage_Site, QString storage_Area)
{
    shelfBinInfo shelfBinInfoI;
    QMap<int ,shelfBinInfo >::const_iterator iter= currentShelfBinInfoMap.begin();  //实时获取 Bin 的基础信息
    while (iter!=currentShelfBinInfoMap.end()) {
//        if(iter.value().binEnable==1 && iter.value().storage_Site.right(3)== storage_Site
//                && iter.value().shelfBindesc.right(7)==storage_Area){
//           shelfBinInfoI=iter.value();
//        }
        iter++;
    }
    qDebug()<<"getShelfBin_Emty_-->"<<shelfBinInfoI.shelfBinIndex<<shelfBinInfoI.shelfBindesc<<" storage_Area:"<<storage_Site<<storage_Area;
    return shelfBinInfoI;
}

void transFormArray::setShelfBin_Info(QMap<int, shelfBinInfo> shelfBinInfoMap)
{
    QMap<int ,shelfBinInfo >::iterator iter= currentShelfBinInfoMap.begin();  //实时获取 Bin 的基础信息
    while (iter!=currentShelfBinInfoMap.end()) {
       shelfBinInfo shelfBinInfoI= shelfBinInfoMap.value(iter.value().shelfBinIndex);
       if(iter.value().shelfBinIndex==shelfBinInfoI.shelfBinIndex
               && shelfBinInfoI.shelfBinIndex!=0){
           iter.value().setFull=shelfBinInfoI.setFull;
           iter.value().status=shelfBinInfoI.status;              //0 空闲  1任务占用中
           qDebug()<<"setShelfBin_Info-->"<<shelfBinInfoI.shelfBinIndex<<shelfBinInfoI.shelfBindesc
                     <<shelfBinInfoI.setFull<<shelfBinInfoI.status;
       }
      iter++;
    }
}

bool transFormArray::getTaskType_Emty(SAPExcelInfo SAPExcelInfoI)
{
    QMap<int, SAPExcelInfo>::const_iterator iter= CurrentServerItem.currentSAPExcelInfoTask.begin();
    while (iter !=CurrentServerItem.currentSAPExcelInfoTask.end()){
//        if(SAPExcelInfoI.taskType==iter.value().taskType
//                && SAPExcelInfoI.canningDevice==iter.value().canningDevice
//                && iter.value().taskStatus<50){
//            qDebug()<<"getTaskType_Emty--> true"<<SAPExcelInfoI.taskType<<SAPExcelInfoI.canningDevice
//                    <<iter.value().canningDevice<<iter.value().taskStatus;
//            return true;
//        }
        iter++;
    }

    qDebug()<<"getTaskType_Emty-->false"<<CurrentServerItem.currentSAPExcelInfoTask.size();
    return false;
}

bool transFormArray::getTaskType_task(SAPExcelInfo SAPExcelInfoI)
{
    QMap<int, SAPExcelInfo>::const_iterator iter= CurrentServerItem.currentSAPExcelInfoTask.begin();
    while (iter !=CurrentServerItem.currentSAPExcelInfoTask.end()){
        if(SAPExcelInfoI.shelfBinIndex==iter.value().shelfBinIndex && iter.value().taskError==0
                && iter.value().taskStatus<=50){
//            qDebug()<<"getTaskType_task 判断当前存在重复任务--> true"<<SAPExcelInfoI.taskType<<SAPExcelInfoI.canningDevice
//                    <<iter.value().canningDevice<<iter.value().taskStatus;
            return true;
        }
        iter++;
    }

    qDebug()<<"getTaskType_task  当前不存在重复任务-->false"<<CurrentServerItem.currentSAPExcelInfoTask.size();
    return false;
}


ReplyJson transFormArray::newSAPExcelInfoTask_Process(QString ClientIP, QByteArray AnalysisArray, ReplyJson ReplyJsonI)
{

    //qDebug()<<"ReplyJson "<<ReplyJson;
    //qDebug()<<"ReplyJson -->"<<ReplyJson.value("taskType").toString() <<value.isArray();
    QJsonValue value = ReplyJsonI.ReplyJson.value("ArrayType");//获取 QJsonObject 对象
    QString taskType= ReplyJsonI.ReplyJson.value("taskType").toString();
    QJsonArray rootFruitList=ReplyJsonI.ReplyJson.value("ArrayType").toArray();
    if(value.isArray() &&!rootFruitList.isEmpty() ){
        if(ReplyJsonI.taskType=="newSAP"){//新的的入库任务
           ReplyJsonI= SAP_transFor_SAPExcelInfo(taskType,rootFruitList,value,ReplyJsonI);
        }if(ReplyJsonI.taskType=="Advacen"){//提前出库
            ReplyJsonI= AdvaceSAP_transFor(taskType,rootFruitList,value,ReplyJsonI);
        }if(ReplyJsonI.taskType=="delete"){//删除任务
            ReplyJsonI= deleteSAP_transFor(taskType,rootFruitList,value,ReplyJsonI);
        }if(ReplyJsonI.taskType=="AGVRun"){//放行任务
            ReplyJsonI= AGVRunSAP_transFor(taskType,rootFruitList,value,ReplyJsonI);
        }if(ReplyJsonI.taskType=="AreaClear"){//清除库位信息
            ReplyJsonI= AreaClearSAP_transFor(taskType,rootFruitList,value,ReplyJsonI);
        }if(ReplyJsonI.taskType=="change"){//更改任务信息
            ReplyJsonI= changeSAP_transFor(taskType,rootFruitList,value,ReplyJsonI);
        }

    }else{
        qDebug()<<"ReplyJson false-->"<<ReplyJsonI.ReplyJson.value("taskType").toString() <<value.isArray();
    }
    return ReplyJsonI;
}

QMap<int, SAPExcelInfo> transFormArray::getNewSAPExcelInfoTask()
{
    QMap<int, SAPExcelInfo>newSAPExcelInfoTask_=newSAPExcelInfoTask;
    newSAPExcelInfoTask.clear();
    return newSAPExcelInfoTask_;
}

QMap<int, SAPExcelInfo> transFormArray::getdeleteSAPExcelInfoTask()
{
    QMap<int, SAPExcelInfo>deleteSAPExcelInfoTask_=deleteSAPExcelInfoTask;
    deleteSAPExcelInfoTask.clear();
    return deleteSAPExcelInfoTask_;
}

QMap<int, SAPExcelInfo> transFormArray::getAdvaceSAPExcelInfoTask()
{
    QMap<int, SAPExcelInfo>AdvaceSAPExcelInfoTask_=AdvaceSAPExcelInfoTask;
    AdvaceSAPExcelInfoTask.clear();
    return AdvaceSAPExcelInfoTask_;
}

QMap<int, SAPExcelInfo> transFormArray::getAGVRunSAPExcelInfoTask()
{
    QMap<int, SAPExcelInfo>AGVRunSAPExcelInfoTask_=AGVRunSAPExcelInfoTask;
    AGVRunSAPExcelInfoTask.clear();
    return AGVRunSAPExcelInfoTask_;

}

QMap<int, shelfBinInfo> transFormArray::getshelfBinInfoMap_clesr()
{
    QMap<int, shelfBinInfo>shelfBinInfoMap_clesr_=shelfBinInfoMap_clesr;
    shelfBinInfoMap_clesr.clear();
    return shelfBinInfoMap_clesr_;
}

QMap<int, SAPExcelInfo> transFormArray::getchangeSAPExcelInfoTask()
{
    QMap<int, SAPExcelInfo>changeSAPExcelInfoTask_=changeSAPExcelInfoTask;
    changeSAPExcelInfoTask.clear();
    return changeSAPExcelInfoTask_;
}

int transFormArray::getSAPTaskIndex()
{
    int SAPTaskIndex=0;
    if(!AGVRunSAPExcelInfoTask.isEmpty()){
        SAPTaskIndex=AGVRunSAPExcelInfoTask.firstKey();
    } if(!deleteSAPExcelInfoTask.isEmpty()){
        SAPTaskIndex=deleteSAPExcelInfoTask.firstKey();
    } if(!AdvaceSAPExcelInfoTask.isEmpty()){
        SAPTaskIndex=AdvaceSAPExcelInfoTask.firstKey();
    }
    return SAPTaskIndex;
}


/************* User_transFor ************/
QByteArray transFormArray::User_transFor_Array(QString taskType,QMap<QString,User_Info>UserInfoListMap)
{
    QJsonObject ReJson;
    QJsonArray rootFruitList;
    QMap<QString,User_Info>::iterator iter=UserInfoListMap.begin();
    while (iter!=UserInfoListMap.end()) {
        QJsonObject tasksJson;
        tasksJson.insert("UserNuber",iter.value().UserNuber);
        tasksJson.insert("UserName",iter.value().UserName);
        tasksJson.insert("PassWord",iter.value().PassWord);
        tasksJson.insert("Jurisdiction",iter.value().Jurisdiction);
        tasksJson.insert("UserGrage",iter.value().UserGrage);
        tasksJson.insert("Status",iter.value().Status);
        rootFruitList.append(tasksJson);
        iter++;
    }

    ReJson.insert("taskType",taskType);      //类型识别号
    ReJson.insert("ArrayType",rootFruitList);

    QByteArray AnalysisArray = QJsonDocument(ReJson).toJson();

    return  AnalysisArray;
}


QByteArray transFormArray::sapPath_transFor_Array(QString taskType, QMap<int, sapPath> sapPathMap)
{
    QJsonObject ReJson;
    QJsonArray rootFruitList;
    QMap<int, sapPath>::iterator iter=sapPathMap.begin();
    while (iter!=sapPathMap.end()) {
        QJsonObject tasksJson;
        tasksJson.insert("Id",iter.value().Id);
        tasksJson.insert("Path",iter.value().Path);
        tasksJson.insert("funcation",iter.value().funcation);
        tasksJson.insert("para1",iter.value().para1);
        tasksJson.insert("para2",iter.value().para2);
        tasksJson.insert("para3",iter.value().para3);
        tasksJson.insert("Type",iter.value().Type);
        tasksJson.insert("PathName",iter.value().PathName);
        rootFruitList.append(tasksJson);
        iter++;
    }

    ReJson.insert("taskType",taskType);      //类型识别号
    ReJson.insert("ArrayType",rootFruitList);

    QByteArray AnalysisArray = QJsonDocument(ReJson).toJson();

    return  AnalysisArray;
}


/************* shelfBinInfo ************/
QByteArray transFormArray::shelfBin_transFor_Array(QString taskType, QMap<int, shelfBinInfo> shelfBinInfoMap)
{
//    QJsonObject ReJson;
//    QJsonArray rootFruitList;
//    QMap<int,shelfBinInfo>::iterator iter=shelfBinInfoMap.begin();
//    while (iter!=shelfBinInfoMap.end()) {
//        if(rootFruitList.size()<30){
//            QJsonObject tasksJson;
//            tasksJson.insert("shelfBinIndex",QString::number(iter.value().shelfBinIndex));       //所属架位索引
//            tasksJson.insert("setFull",QString::number(iter.value().setFull));       //所属架位索引
//            tasksJson.insert("status",QString::number(iter.value().status));       //所属架位索引
//            tasksJson.insert("storage_Site",iter.value().storage_Site);       //所属架位索引
//            tasksJson.insert("storage_Area",iter.value().storage_Area);       //所属架位索引

//            //tasksJson.insert("shelfBinIndex",iter.value().shelfBinIndex);       //所属架位索引

//            rootFruitList.append(tasksJson);
//        }

//        iter++;
//    }

//    ReJson.insert("taskType",taskType);      //类型识别号
//    ReJson.insert("ArrayType",rootFruitList);

//    QByteArray AnalysisArray = QJsonDocument(ReJson).toJson();

//    return  AnalysisArray;

}

/************* SAP_transFor ************/
QByteArray transFormArray::SAP_transFor_Array(QString taskType, QMap<int, SAPExcelInfo> currentSAPExcelInfoTask)
{
    QJsonObject ReJson;
    QJsonArray rootFruitList;
    QMap<int, SAPExcelInfo>::iterator iter= currentSAPExcelInfoTask.begin();
//    while (iter!=currentSAPExcelInfoTask.end()) {
//        QJsonObject tasksJson;
//        tasksJson.insert("SAPTaskIndex",iter.value().SAPTaskIndex);     //任务索引 唯一值
//        tasksJson.insert("keyId",iter.value().keyId);     //任务索引 唯一值
//        tasksJson.insert("taskType",iter.value().taskType);     //任务索引 唯一值
//        tasksJson.insert("classes",iter.value().classes);               //班次
//        tasksJson.insert("canningDevice",iter.value().canningDevice);   //罐装机号
//        tasksJson.insert("storage_Site",iter.value().storage_Site);     //取样地点
//        tasksJson.insert("storage_Area",iter.value().storage_Area);     //取样区域 (样品在保温室存放位置为:保温室低温库 Af001)
//        tasksJson.insert("sampling_time",iter.value().sampling_time.toString("yyyy-MM-dd hh:mm"));//取样时间 即罐装车间取样时间(创建时间)
//        tasksJson.insert("taskStatus",iter.value().taskStatus);             //任务状态
//        tasksJson.insert("taskStatusDesc",iter.value().taskStatusDesc);     //任务状态注释

//        rootFruitList.append(tasksJson);

////        qDebug()<<taskType<<" SAPExcelInfoTask--> 样品Id:"<<iter.value().material_ID<<" 存储位置:"<<iter.value().storage_Site<<iter.value().storage_Area
////              <<" taskStatus:"<<iter.value().taskStatus <<" 数量:"<<iter.value().storageReal_Qty;

//        iter++;
//    }

    ReJson.insert("taskType",taskType);      //类型识别号
    ReJson.insert("ArrayType",rootFruitList);

    QByteArray AnalysisArray = QJsonDocument(ReJson).toJson();

    return  AnalysisArray;
}

ReplyJson transFormArray::SAP_transFor_SAPExcelInfo(QString taskType, QJsonArray rootFruitList, QJsonValue value, ReplyJson ReplyJsonI)
{

//    if(!rootFruitList.isEmpty()){  //判读第二级对象是以数组形式存在
//        for(int i=0;i<rootFruitList.size();i++){
//            SAPExcelInfo SAPExcelInfoI;
//            QJsonObject ReJson=value[i].toObject();

//            SAPExcelInfoI.SAPTaskIndex=ReJson.value("SAPTaskIndex").toInt();        //任务索引 唯一值
//            SAPExcelInfoI.keyId=ReJson.value("keyId").toString();                   //唯一识别号 由Lims 创建并绑定
//            SAPExcelInfoI.taskType=ReJson.value("taskType").toString();             //任务类型 IN 入库  OUT 出库
//            SAPExcelInfoI.creatDate=ReJson.value("creatDate").toString();           //生产日期
//            SAPExcelInfoI.classes=analysDescMap.value(ReJson.value("classes").toString());//班次
//            SAPExcelInfoI.material_ID=ReJson.value("material_ID").toString();       //样品ID
//            SAPExcelInfoI.material_Desc=ReJson.value("material_Desc").toString();   //样品名称
//            SAPExcelInfoI.material_Type=ReJson.value("material_Type").toString();   //样品性质
//            SAPExcelInfoI.canningDevice=ReJson.value("canningDevice").toString();   //罐装机号
//            SAPExcelInfoI.Stationpoint=CurrentServerItem.analysDeviceMap.value(SAPExcelInfoI.canningDevice);//罐装机对应的二维码
//            SAPExcelInfoI.canning_ID=ReJson.value("canning_ID").toString();         //罐号

//            SAPExcelInfoI.storage_Site=analysDescMap.value(ReJson.value("storage_Site").toString());     //取样地点
//            SAPExcelInfoI.storage_Area=ReJson.value("storage_Area").toString();     //取样区域 (样品在保温室存放位置为:保温室低温库 Af001)

//            ReplyJsonI.keyId=SAPExcelInfoI.keyId;

//            if(SAPExcelInfoI.taskType=="Empty"){
//                bool savebool=getTaskType_Emty(SAPExcelInfoI);//判断当前空料框任务是否重复
//                if(!savebool){
//                    ReplyJsonI.taskStatus=0;
//                    ReplyJsonI.errortextEdit="";
//                    SAPExcelInfoI.taskStatus=0;
//                    SAPExcelInfoI.taskStatusDesc="待配送";
//                }else{
//                    ReplyJsonI.taskStatus=3;
//                    ReplyJsonI.errortextEdit="任务重复";
//                    return ReplyJsonI;
//                }
//            }

//            if(SAPExcelInfoI.taskType=="newtask_In" || SAPExcelInfoI.taskType=="newtask_Out"){

//                //判断当前库位是否存在并可用
//                shelfBinInfo shelfBinInfoI=getShelfBin_Emty_(SAPExcelInfoI.storage_Site,SAPExcelInfoI.storage_Area);
//                if(shelfBinInfoI.shelfBinIndex==0){
//                    ReplyJsonI.taskStatus=1;
//                    ReplyJsonI.errortextEdit="库位信息错误";
//                    SAPExcelInfoI.taskStatus=-1;
//                    SAPExcelInfoI.taskStatusDesc="库位信息错误";
//                    return ReplyJsonI;
//                }else{

//                    SAPExcelInfoI.layer=shelfBinInfoI.layer;                    //第几层
//                    SAPExcelInfoI.shelfBinIndex=shelfBinInfoI.shelfBinIndex;    //所属架位索引
//                    SAPExcelInfoI.shelfBindesc=shelfBinInfoI.shelfBindesc;      //所属架位注释
//                    SAPExcelInfoI.Currentpoint=shelfBinInfoI.Currentpoint;      //当前所在二维码
//                    SAPExcelInfoI.actionDirection=shelfBinInfoI.actionDirection;//货架在左边 0x01   在右边 0x02

//                    bool savebool=getTaskType_task(SAPExcelInfoI); //判断当前库存位置是否存在重复任务
//                    if(savebool){//当前存储位置已存在任务
//                        ReplyJsonI.taskStatus=1;
//                        ReplyJsonI.errortextEdit="当前库位已存在任务";
//                        SAPExcelInfoI.taskStatus=-1;
//                        SAPExcelInfoI.taskStatusDesc="当前库位已存在任务";
//                        return ReplyJsonI;
//                    }else{
//                        ReplyJsonI.taskStatus=0;
//                        ReplyJsonI.errortextEdit="";
//                        if(SAPExcelInfoI.taskType=="newtask_In"){
//                            SAPExcelInfoI.taskStatus=0;
//                            SAPExcelInfoI.taskStatusDesc="待配送";
//                        }if(SAPExcelInfoI.taskType=="newtask_Out"){
//                            SAPExcelInfoI.taskStatus=20;
//                            SAPExcelInfoI.taskStatusDesc="待出库";
//                        }
//                    }
//                }

//            }

//            QString storageReal_Qty =ReJson.value("storageReal_Qty").toString();
//            SAPExcelInfoI.storageReal_Qty=storageReal_Qty.toDouble();               //库存数量

//            SAPExcelInfoI.causation_Type=ReJson.value("causation_Type").toString();     //取样原因
//            SAPExcelInfoI.insulation_Cycle=ReJson.value("insulation_Cycle").toString(); //保温周期

//            QString sampling_time=ReJson.value("sampling_time").toString();
//            SAPExcelInfoI.sampling_time=QDateTime::fromString(sampling_time,"yyyy-MM-dd hh:mm:ss"); //取样时间 即罐装车间取样时间(创建时间)

//            QString sampling_time_=ReJson.value("sampling_time_").toString();
//            SAPExcelInfoI.sampling_time_=QDateTime::fromString(sampling_time_,"yyyy-MM-dd hh:mm:ss");

//            SAPExcelInfoI.taskNumber_SAP=ReJson.value("taskNumber_SAP").toString();     //SAP任务号

//            SAPExcelInfoI.Priority=ReJson.value("Priority").toInt();                        //出库任务 优先级 1-100 由高到低
//            QString creatTimer=ReJson.value("creatTimer").toString();
//            SAPExcelInfoI.creatTimer=QDateTime::fromString(creatTimer,"yyyy-MM-dd hh:mm:ss");  //创建时间

//            QString finishTimer=ReJson.value("finishTimer").toString();
//            SAPExcelInfoI.finishTimer=QDateTime::fromString(finishTimer,"yyyy-MM-dd hh:mm:ss");//完成时间

//            if(taskType=="newSAP" && (SAPExcelInfoI.taskStatus==0 || SAPExcelInfoI.taskStatus==20)
//                   && !newSAPExcelInfoTask.contains(SAPExcelInfoI.SAPTaskIndex)){
//                newSAPExcelInfoTask.insert(SAPExcelInfoI.SAPTaskIndex,SAPExcelInfoI);
//                qDebug()<<taskType<<" SAPExcelInfoTask--> 样品Id:"<<SAPExcelInfoI.material_ID<<" 存储位置:"
//                       <<SAPExcelInfoI.storage_Site<<SAPExcelInfoI.storage_Area
//                      <<" taskStatus:"<<SAPExcelInfoI.taskStatus <<" 数量:"<<SAPExcelInfoI.storageReal_Qty
//                       <<" Client.size:"<<newSAPExcelInfoTask.size();
//            }

//        }
//    }

    return ReplyJsonI;
}

ReplyJson transFormArray::AdvaceSAP_transFor(QString taskType, QJsonArray rootFruitList, QJsonValue value, ReplyJson ReplyJsonI)
{
//    if(!rootFruitList.isEmpty()){  //判读第二级对象是以数组形式存在
//        AdvaceSAPExcelInfoTask.clear();

//        for(int i=0;i<rootFruitList.size();i++){
//            SAPExcelInfo SAPExcelInfoI;
//            QJsonObject ReJson=value[i].toObject();

//            SAPExcelInfoI.SAPTaskIndex=ReJson.value("SAPTaskIndex").toInt();        //任务索引 唯一值
//            SAPExcelInfoI.keyId=ReJson.value("keyId").toString();                   //唯一识别号 由Lims 创建并绑定
//            SAPExcelInfoI.taskType=ReJson.value("taskType").toString();             //任务类型 IN 入库  OUT 出库
//            SAPExcelInfoI.material_ID=ReJson.value("material_ID").toString();       //样品ID
//            ReplyJsonI.keyId=SAPExcelInfoI.keyId;

//            if(taskType=="Advacen"){
//                QMap<int, SAPExcelInfo>::iterator iter= CurrentServerItem.currentSAPExcelInfoTask.begin();
//                while (iter!=CurrentServerItem.currentSAPExcelInfoTask.end()) {

//                    if(iter.value().keyId==SAPExcelInfoI.keyId && iter.value().taskError==0
//                            && iter.value().taskStatus==15){
//                        qDebug()<<taskType<<" AdvaceSAPExcelInfoTask--> keyId:"<<SAPExcelInfoI.keyId<<" size:"<<AdvaceSAPExcelInfoTask.size();
//                        if(!AdvaceSAPExcelInfoTask.contains(iter.value().SAPTaskIndex)){
//                            iter.value().checked=1;
//                            iter.value().taskStatus=20;
//                            iter.value().taskStatusDesc="待出库";
//                            AdvaceSAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
//                        }
//                    }
//                    iter++;
//                }

//                qDebug()<<taskType<<" Advace SAPExcelInfoTask--> keyId:"<<SAPExcelInfoI.keyId<<" size:"<<AdvaceSAPExcelInfoTask.size()
//                       <<CurrentServerItem.currentSAPExcelInfoTask.size();
//            }

//        }
//    }
//    if(AdvaceSAPExcelInfoTask.isEmpty()){
//        ReplyJsonI.taskStatus=2;
//        ReplyJsonI.errortextEdit="当前任务无法出库";
//    }else{
//        ReplyJsonI.taskStatus=0;
//        ReplyJsonI.errortextEdit="";
//    }

    return ReplyJsonI;
}

ReplyJson transFormArray::deleteSAP_transFor(QString taskType, QJsonArray rootFruitList, QJsonValue value, ReplyJson ReplyJsonI)
{
//    if(!rootFruitList.isEmpty()){  //判读第二级对象是以数组形式存在
//        deleteSAPExcelInfoTask.clear();
//        for(int i=0;i<rootFruitList.size();i++){
//            SAPExcelInfo SAPExcelInfoI;
//            QJsonObject ReJson=value[i].toObject();

//            SAPExcelInfoI.SAPTaskIndex=ReJson.value("SAPTaskIndex").toInt();        //任务索引 唯一值
//            SAPExcelInfoI.keyId=ReJson.value("keyId").toString();                   //唯一识别号 由Lims 创建并绑定
//            SAPExcelInfoI.taskType=ReJson.value("taskType").toString();             //任务类型 IN 入库  OUT 出库
//            SAPExcelInfoI.material_ID=ReJson.value("material_ID").toString();       //样品ID
//            ReplyJsonI.keyId=SAPExcelInfoI.keyId;

//            if(taskType=="delete"){
//                QMap<int, SAPExcelInfo>::iterator iter= CurrentServerItem.currentSAPExcelInfoTask.begin();
//                while (iter!=CurrentServerItem.currentSAPExcelInfoTask.end()) {
//                    if(iter.value().keyId==SAPExcelInfoI.keyId && iter.value().taskError==0
//                            && (iter.value().taskStatus==0 || iter.value().taskStatus==15
//                                || iter.value().taskStatus==20)){
//                        qDebug()<<taskType<<" deleteSAPExcelInfoTask--> keyId:"<<SAPExcelInfoI.keyId<<" size:"<<deleteSAPExcelInfoTask.size();
//                        if(!deleteSAPExcelInfoTask.contains(iter.value().SAPTaskIndex)){
//                            iter.value().checked=1;
//                            iter.value().taskStatus=100;
//                            iter.value().taskStatusDesc="已删除";
//                            iter.value().taskError=15;
//                            iter.value().errortextEdit="已删除";
//                            deleteSAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
//                        }
//                    }
//                    iter++;
//                }
//                qDebug()<<taskType<<" delete SAPExcelInfoTask--> keyId:"<<SAPExcelInfoI.keyId<<" size:"<<deleteSAPExcelInfoTask.size()
//                       <<CurrentServerItem.currentSAPExcelInfoTask.size();
//            }
//        }
//    }
//    if(deleteSAPExcelInfoTask.isEmpty()){
//        ReplyJsonI.taskStatus=2;
//        ReplyJsonI.errortextEdit="任务删除失败";
//    }else{
//        ReplyJsonI.taskStatus=0;
//        ReplyJsonI.errortextEdit="";
//    }


    return ReplyJsonI;
}

ReplyJson transFormArray::AGVRunSAP_transFor(QString taskType, QJsonArray rootFruitList, QJsonValue value, ReplyJson ReplyJsonI)
{
//    if(!rootFruitList.isEmpty()){  //判读第二级对象是以数组形式存在
//        AGVRunSAPExcelInfoTask.clear();
//        for(int i=0;i<rootFruitList.size();i++){
//            SAPExcelInfo SAPExcelInfoI;
//            QJsonObject ReJson=value[i].toObject();

//            SAPExcelInfoI.SAPTaskIndex=ReJson.value("SAPTaskIndex").toInt();        //任务索引 唯一值
//            SAPExcelInfoI.keyId=ReJson.value("keyId").toString();                   //唯一识别号 由Lims 创建并绑定
//            SAPExcelInfoI.taskType=ReJson.value("taskType").toString();             //任务类型 IN 入库  OUT 出库
//            SAPExcelInfoI.material_ID=ReJson.value("material_ID").toString();       //样品ID
//            ReplyJsonI.keyId=SAPExcelInfoI.keyId;

//            if(taskType=="AGVRun" && SAPExcelInfoI.keyId!=""
//                    && SAPExcelInfoI.SAPTaskIndex>0){
//                if(!AGVRunSAPExcelInfoTask.contains(SAPExcelInfoI.SAPTaskIndex)){
//                    AGVRunSAPExcelInfoTask.insert(SAPExcelInfoI.SAPTaskIndex,SAPExcelInfoI);
//                }
//            }

//            qDebug()<<taskType<<" AGVRun  SAPExcelInfoTask--> keyId:"<<SAPExcelInfoI.keyId
//                   <<SAPExcelInfoI.SAPTaskIndex<<" size:"<<AGVRunSAPExcelInfoTask.size();
//        }
//    }
//    if(AGVRunSAPExcelInfoTask.isEmpty()){
//        ReplyJsonI.taskStatus=2;
//        ReplyJsonI.errortextEdit="任务放行失败";
//    }else{
//        ReplyJsonI.taskStatus=0;
//        ReplyJsonI.errortextEdit="";
//    }


    return ReplyJsonI;
}

ReplyJson transFormArray::AreaClearSAP_transFor(QString taskType, QJsonArray rootFruitList, QJsonValue value, ReplyJson ReplyJsonI)
{
//    if(!rootFruitList.isEmpty()){  //判读第二级对象是以数组形式存在
//        shelfBinInfoMap_clesr.clear();
//        for(int i=0;i<rootFruitList.size();i++){

//            QJsonObject ReJson=value[i].toObject();
//            QString storage_Site=analysDescMap.value(ReJson.value("storage_Site").toString());
//            QString storage_Area=ReJson.value("storage_Area").toString();
//            ReplyJsonI.keyId=ReJson.value("keyId").toString();                   //唯一识别号 由Lims 创建并绑定

//            QMap<int ,shelfBinInfo >::iterator iter= currentShelfBinInfoMap.begin();  //实时获取 Bin 的基础信息
//            while (iter!=currentShelfBinInfoMap.end()) {
//                if(iter.value().binEnable==1 && iter.value().storage_Site== storage_Site
//                        && iter.value().storage_Area==storage_Area){
//                    ReplyJsonI.taskStatus=0;
//                    ReplyJsonI.errortextEdit="";

//                    iter.value().status=0;
//                    iter.value().setFull=0;
//                    shelfBinInfoMap_clesr.insert(iter.value().shelfBinIndex,iter.value());
//                }
//                iter++;
//            }

//            qDebug()<<taskType<<" AreaClear  ----->storage_Site:"<<storage_Site
//                   <<" storage_Area:"<<storage_Area<<" size:"<<shelfBinInfoMap_clesr.size();

//        }
//    }

//    return ReplyJsonI;
}

ReplyJson transFormArray::changeSAP_transFor(QString taskType, QJsonArray rootFruitList, QJsonValue value, ReplyJson ReplyJsonI)
{
//    if(!rootFruitList.isEmpty()){  //判读第二级对象是以数组形式存在
//        for(int i=0;i<rootFruitList.size();i++){
//            SAPExcelInfo SAPExcelInfoI;
//            QJsonObject ReJson=value[i].toObject();

//            SAPExcelInfoI.SAPTaskIndex=ReJson.value("SAPTaskIndex").toInt();        //任务索引 唯一值
//            SAPExcelInfoI.keyId=ReJson.value("keyId").toString();                   //唯一识别号 由Lims 创建并绑定
//            SAPExcelInfoI.storage_Site=analysDescMap.value(ReJson.value("storage_Site").toString());//取样地点
//            SAPExcelInfoI.storage_Area=ReJson.value("storage_Area").toString();                     //取样区域 (样品在保温室存放位置为:保温室低温库 Af001)

//            ReplyJsonI.keyId=SAPExcelInfoI.keyId;

//            //判断当前库位是否存在并可用
//            shelfBinInfo shelfBinInfoI=getShelfBin_Emty_(SAPExcelInfoI.storage_Site,SAPExcelInfoI.storage_Area);
//            if(shelfBinInfoI.shelfBinIndex==0){
//                ReplyJsonI.taskStatus=1;
//                ReplyJsonI.errortextEdit="库位信息错误";
//                SAPExcelInfoI.taskStatus=-1;
//                SAPExcelInfoI.taskStatusDesc="库位信息错误";
//                return ReplyJsonI;
//            }
//            else{
//                ReplyJsonI.taskStatus=0;
//                ReplyJsonI.errortextEdit="";
//            }

//            SAPExcelInfoI.layer=shelfBinInfoI.layer;                    //第几层
//            SAPExcelInfoI.shelfBinIndex=shelfBinInfoI.shelfBinIndex;    //所属架位索引
//            SAPExcelInfoI.shelfBindesc=shelfBinInfoI.shelfBindesc;      //所属架位注释
//            SAPExcelInfoI.Currentpoint=shelfBinInfoI.Currentpoint;      //当前所在二维码
//            SAPExcelInfoI.actionDirection=shelfBinInfoI.actionDirection;//货架在左边 0x01   在右边 0x02

//            QString storageReal_Qty =ReJson.value("storageReal_Qty").toString();
//            SAPExcelInfoI.storageReal_Qty=storageReal_Qty.toDouble();               //库存数量

//            SAPExcelInfoI.causation_Type=ReJson.value("causation_Type").toString();     //取样原因
//            SAPExcelInfoI.insulation_Cycle=ReJson.value("insulation_Cycle").toString(); //保温周期

//            QString sampling_time=ReJson.value("sampling_time").toString();
//            SAPExcelInfoI.sampling_time=QDateTime::fromString(sampling_time,"yyyy-MM-dd hh:mm"); //取样时间 即罐装车间取样时间(创建时间)

//            QString sampling_time_=ReJson.value("sampling_time_").toString();
//            SAPExcelInfoI.sampling_time_=QDateTime::fromString(sampling_time_,"yyyy-MM-dd hh:mm");

//            if(!changeSAPExcelInfoTask.contains(SAPExcelInfoI.SAPTaskIndex)
//                    && SAPExcelInfoI.keyId!=""){
//                changeSAPExcelInfoTask.insert(SAPExcelInfoI.SAPTaskIndex,SAPExcelInfoI);
//                qDebug()<<taskType<<" 更改任务信息--> SAPTaskIndex:"<<SAPExcelInfoI.SAPTaskIndex<<" keyId:"<<SAPExcelInfoI.keyId
//                       <<" 存储位置:"<<SAPExcelInfoI.shelfBinIndex<<SAPExcelInfoI.shelfBindesc
//                      <<" sampling_time_:"<<SAPExcelInfoI.sampling_time_;
//            }else {
//                ReplyJsonI.taskStatus=1;
//                ReplyJsonI.errortextEdit="当前任务无法更改";
//            }

//        }
//    }

    return ReplyJsonI;
}

transFormArray *transFormArray::GetInstance()
{
    if(transFormArrayItiem != nullptr)
        return transFormArrayItiem;
    else
    {
        mutex.lock();
        transFormArrayItiem=new transFormArray;
        return transFormArrayItiem;
        mutex.unlock();
    }

}
