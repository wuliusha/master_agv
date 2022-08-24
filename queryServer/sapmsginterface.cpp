#include "sapmsginterface.h"
//sapMsgInterface* sapMsgInterface::instance=nullptr;
//QMutex sapMsgInterface::mutex;

STATEMENTINSTANCE(sapMsgInterface)
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase0)

sapMsgInterface::sapMsgInterface(QObject *parent) : QObject(parent)
{
    setSapPathMap();
    //ws01Path="http://algnts30.algex.asmpt.com/SpecialStorageWS/OKAGVWarehouseWS.svc/REST/Details?label=";
    //ws01Path="http://10.16.209.76/Service.svc/Details?label=";

    qRegisterMetaType<QList<labelMsgStruct >>("QList<labelMsgStruct >");
    qRegisterMetaType<QList<retMsgStruct >>("QList<retMsgStruct >");
    qRegisterMetaType<QMap<int,sapPath>>("QMap<int,sapPath>");

    connect(&NetworkMgr, SIGNAL(finished(QNetworkReply *)),SLOT(ReadResponse(QNetworkReply *)));

    connect(this,&sapMsgInterface::ReplyError,this,&sapMsgInterface::ONReplyError);

    MsgTimer = new QTimer(this);
    connect(MsgTimer,&QTimer::timeout,this,&sapMsgInterface::sapMsgTimer);
    MsgTimer->start(300);

}

void sapMsgInterface::sapMsgTimer()
{
    if(WebServiceItiemMap.isEmpty() && !WebServiceMap.isEmpty()){
        WebService WebServiceI= WebServiceMap.first();
        setWebService_Get(WebServiceI.LabelNo,sapPathMap.value(WebServiceI.pathId).Path+WebServiceI.LabelNo,
                          WebServiceI.UserBadge,sapPathMap.value(WebServiceI.pathId).Type);
        WebServiceMap.remove(WebServiceI.LabelNo);
        qDebug()<<"WS01 LabelNo 0:"<<WebServiceI.LabelNo<<"  size: "<<WebServiceMap.size()<<WebServiceItiemMap.size();
    }

}

//SAP 返回数据
void sapMsgInterface::ReadResponse(QNetworkReply *Reply)
{
    switch (Reply->error()) {
        case QNetworkReply::NoError:
        case QNetworkReply::ContentAccessDenied://数据库拒绝访问
        case QNetworkReply::ContentOperationNotPermittedError://内容操作批准未通过
        case QNetworkReply::ContentNotFoundError://内容没有找到
        case QNetworkReply::UnknownContentError:
        {
            QByteArray ReplyData;
            ReplyData=Reply->readAll();
            //qDebug()<<"ReplyData: "<<ReplyData;

            QJsonDocument JsonAnalyse; QJsonParseError JsonError;
            QJsonArray Jsonarray;
            JsonAnalyse = QJsonDocument::fromJson(ReplyData,&JsonError);

            if(JsonError.error == QJsonParseError::NoError)
            {
                if(!(JsonAnalyse.isEmpty() || JsonAnalyse.isNull()))
                {
                    for(int i=0;i<WebServiceItiemMap.length();i++){
                        if(WebServiceItiemMap[i].NetworkRepItiem==Reply){
//                            qDebug()<<"MES 返回数据--->actionType:"<<WebServiceItiemMap[i].actionType<<WebServiceItiemMap[i].ikey<<"\n"
//                                      <<"JsonAnalyse:"<<JsonAnalyse;
                            analysReplyJson(WebServiceItiemMap[i].ikey,JsonAnalyse,WebServiceItiemMap[i].actionType,WebServiceItiemMap[i].positionCode);
                            WebServiceItiemMap[i].NetworkRepItiem->deleteLater();//关闭
                            WebServiceItiemMap.removeAt(i);
                            i--;
                        }
                    }
                }
            }
        }
            break;
        default:
        {
            // HTTP错误代码解析: https://blog.csdn.net/qq_32963841/article/details/78365449
            int HttpStatus = Reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();//错误代码
            QString Errorinfo="error http Status: "+QString::number(HttpStatus);
            QString Errorinfo1=(QString("Network transport error (%1): %2").arg(Reply->error()).arg(Reply->errorString()));//系统信息

            QJsonObject ReplyJson ;
            QJsonDocument JsonAnalyse; QJsonParseError JsonError;
            for(int i=0;i<WebServiceItiemMap.length();i++){
                if(WebServiceItiemMap[i].NetworkRepItiem==Reply){
                    QByteArray ReplyData;
                    ReplyData=Reply->readAll();
                    JsonAnalyse = QJsonDocument::fromJson(ReplyData,&JsonError);
                    //qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd_hh:mm:ss")<<"ikey:"<<WebServiceItiemMap[i].ikey<<"size:"<<WebServiceItiemMap.size();
                    qDebug()<<"Errorinfo:"<<Errorinfo<<Errorinfo1<<Reply->error();

                    ReplyJson.insert("result","E1");
                    ReplyJson.insert("message","请求超时");
                    analysReplyJson(WebServiceItiemMap[i].ikey,JsonAnalyse,WebServiceItiemMap[i].actionType,"");
//                    WebServiceItiemMap[i].NetworkRepItiem->deleteLater();//关闭
//                    WebServiceItiemMap.removeAt(i);i--;

                    emit ReplyError(WebServiceItiemMap[i]);//因网络异常 重发 三次机制
                }
            }

        }
        break;
    }
}

void sapMsgInterface::ONReplyError(WebServiceItiem WebServiceItiemI)
{
    int count=1;
    if(currentIkeyMap.contains(WebServiceItiemI.ikey)){
        qDebug()<<"重发结束 ONReplyError e: "<<WebServiceItiemI.ikey<<WebServiceItiemI.actionType<<"第几次: "<<count;
        return;
    }

    if(!currentIkeyMap.contains(WebServiceItiemI.ikey)){
        currentIkeyMap.insert(WebServiceItiemI.ikey,count);
    }

    qDebug()<<"ONReplyError: "<<WebServiceItiemI.ikey<<WebServiceItiemI.actionType<<"第几次: "<<count;
    QJsonObject ReplyJson;
    if(WebServiceItiemI.actionType=="action0"){
         ReplyJson_robot(WebServiceItiemI.ikey,ReplyJson);        //获取Robot信息返回
    }else{
        if(WebServiceItiemI.actionType=="action21" || WebServiceItiemI.actionType=="action22"){
            ReplyJson_Msg_MES(WebServiceItiemI.ikey,ReplyJson,WebServiceItiemI.actionType);      //MES 接口返回
        }else{
            ReplyJson_Msg_ESS(WebServiceItiemI.ikey,ReplyJson,WebServiceItiemI.actionType,"");   //ESS 接口返回
        }
    }

    /*************** ASM *************/
    if(WebServiceItiemI.actionType=="ws011"){
        setWebService_Get(WebServiceItiemI.ikey,WebServiceItiemI.UrlPath,WebServiceItiemI.userBadge, WebServiceItiemI.actionType);
    }
    if(WebServiceItiemI.actionType=="ws021"){
         setWebService_Post(WebServiceItiemI.ikey,WebServiceItiemI.UrlPath,WebServiceItiemI.queryJson,WebServiceItiemI.userBadge,WebServiceItiemI.actionType,"");
    }
    if(WebServiceItiemI.actionType=="ws04"){
        setWebService_SAOP_Post(WebServiceItiemI.ikey,WebServiceItiemI.UrlPath,WebServiceItiemI.doc,WebServiceItiemI.userBadge,WebServiceItiemI.actionType);
    }if(WebServiceItiemI.actionType=="ws051"){
        setWebService_Post(WebServiceItiemI.ikey,WebServiceItiemI.UrlPath,WebServiceItiemI.queryJson,WebServiceItiemI.userBadge,WebServiceItiemI.actionType,"");
    }
    if(WebServiceItiemI.actionType=="ws061"){
        setWebService_Post_WS06(WebServiceItiemI.ikey,WebServiceItiemI.UrlPath,WebServiceItiemI.postArray,WebServiceItiemI.userBadge,WebServiceItiemI.actionType);
    }

}


//SAP 反馈数据解析
void sapMsgInterface::analysReplyJson(QString iKey, QJsonDocument JsonAnalyse, QString actionType,QString positionCode)
{
    QJsonObject ReplyJson = JsonAnalyse.object();//取得最外层这个大对象
    if(actionType=="action0" || actionType=="action1"){
         if(actionType=="action0"){
             ReplyJson_robot(iKey,ReplyJson);        //获取Robot信息返回
         }if(actionType=="action1"){
             ReplyJson_taskCode(iKey,ReplyJson);     //获取Robot信息返回
         }

    }else{
        if(actionType=="action21" || actionType=="action22"){
            ReplyJson_Msg_MES(iKey,ReplyJson,actionType);                   //MES 接口返回
        }else{
            ReplyJson_Msg_ESS(iKey,ReplyJson,actionType,positionCode);      //ESS 接口返回
        }
    }
}

void sapMsgInterface::setSapPathMap()
{
    QVariant valuemin;
    if(setting::getInstance()->getSettingValueInterface("ASMOrderDB/sapPath", valuemin))
    {
        currentsapPath = valuemin.toInt();
    }
    //currentsapPath=30;
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
            sapPathMap.insert(sapPathI.Id,sapPathI);
        }
    }

}

QMap<int ,sapPath > sapMsgInterface::getsapPathMap()
{
    return sapPathMap;
}

void sapMsgInterface::setLabelMsgclear()
{
    WebServiceMap.clear();
}

//<<<<<<<<<<WS01<<<<<<<<<<<<
void sapMsgInterface::getLabelMsg(QString LabelNo, QString UserBadge,int pathId)
{
    WebService WebServiceI;
    WebServiceI.LabelNo=LabelNo;
    WebServiceI.UserBadge=UserBadge;
    WebServiceI.pathId=pathId;
    if(WebServiceItiemMap.size()<WebConut){
        setWebService_Get(LabelNo,sapPathMap.value(pathId).Path+LabelNo,UserBadge,sapPathMap.value(pathId).Type);
        return;
    }
    if(!WebServiceMap.contains(LabelNo)){
        WebServiceMap.insert(WebServiceI.LabelNo,WebServiceI);
    }
}

//<<<<<<<<<<WS01 Reply<<<<<<<<<<<<
void sapMsgInterface::ReplyJson_robot(QString iKey, QJsonObject ReplyJsonI)
{

    if(ReplyJsonI.isEmpty()){
        ESSRobot ESSRobotI;
        if(!ESSRobotInfoMap.contains(iKey)){
            ESSRobotI.iKey=iKey;
            ESSRobotInfoMap.insert(iKey,ESSRobotI);
            qDebug()<<"ESSRobot 获取失败--->iKey:"<<iKey<<"robotCode:"<<ESSRobotI.robotCode<<" stationCode:"<<ESSRobotI.stationCode<<" locationCode:"<<ESSRobotI.locationCode<<" positionCode:"<<ESSRobotI.pointCode;
        }
        return;
    }

    QString msg=ReplyJsonI.value("msg").toString();
    if(msg=="success"){
        QJsonObject ReplyJson;
        QJsonArray rootFruitList=ReplyJsonI.value("data").toArray();
        QJsonValue value = ReplyJsonI.value("data");//第一级对象 的值
        if(value.isObject()){  //判读第二级对象是否存在
            ReplyJson=value.toObject();
            QJsonArray rootFruitList=ReplyJson.value("robots").toArray();
            QJsonValue value = ReplyJson.value("robots");//第一级对象 的值
            if(value.isObject()){  //判读第二级对象是否存在
                QJsonObject ReJson=value.toObject();
            }else if(value.isArray() && !rootFruitList.isEmpty()){  //判读第二级对象是以数组形式存在
                for(int i=0;i<rootFruitList.size();i++){
                    ESSRobot ESSRobotI;
                    ESSRobotI.iKey=iKey;
                    QJsonObject ReJson=value[i].toObject();
                    ESSRobotI.robotCode=ReJson.value("robotCode").toString();               //机器人编码
                    ESSRobotI.robotTypeCode=ReJson.value("robotTypeCode").toString();       //型号
                    ESSRobotI.pointCode=ReJson.value("pointCode").toString();               //节点编码
                    ESSRobotI.positionX=ReJson.value("positionX").toInt();                  //坐标x
                    ESSRobotI.positionY=ReJson.value("positionY").toInt();                  //坐标y
                    ESSRobotI.theta=ReJson.value("theta").toInt();                          //角度
                    ESSRobotI.forkHeight=ReJson.value("forkHeight").toInt();                //货叉高度
                    ESSRobotI.forkLength=ReJson.value("forkLength").toInt();                //货叉长度
                    ESSRobotI.forkTheta=ReJson.value("forkTheta").toInt();                  //货叉相对机器人角度
                    ESSRobotI.stationCode=ReJson.value("stationCode").toInt();              //工作站编码
                    ESSRobotI.locationCode=ReJson.value("locationCode").toString();         //工作位编码

                    QJsonArray rootFruitList_=ReJson.value("trays").toArray();
                    QJsonValue value_ = ReJson.value("trays");//第一级对象 的值
                    if(value_.isObject()){  //判读第二级对象是否存在
                        QJsonObject ReJson=value_.toObject();
                    }else if(value_.isArray() && !rootFruitList_.isEmpty()){  //判读第二级对象是以数组形式存在
                        for(int j=0;j<rootFruitList_.size();j++){
                            ESStrays ESStraysI;
                            QJsonObject ReJson=value_[j].toObject();
                            ESStraysI.trayLevel=ReJson.value("trayLevel").toInt();            //背篓序号
                            ESStraysI.containerCode=ReJson.value("containerCode").toString();   //货箱编码
                            ESStraysI.positionCode=ReJson.value("positionCode").toString();    //位置编码
                            if(!ESSRobotI.ESStraysMap.contains(ESStraysI.trayLevel)){
                                ESSRobotI.ESStraysMap.insert(ESStraysI.trayLevel,ESStraysI);
                            }
                            //qDebug()<<" trayLevel:"<<ESStraysI.trayLevel<<" containerCode:"<<ESStraysI.containerCode<<" positionCode:"<<ESStraysI.positionCode;//<<ReJson;
                        }
                    }

                    if(!ESSRobotInfoMap.contains(iKey)){
                        ESSRobotInfoMap.insert(iKey,ESSRobotI);
                        //qDebug()<<" robotCode:"<<ESSRobotI.robotCode<<" stationCode:"<<ESSRobotI.stationCode<<" locationCode:"<<ESSRobotI.locationCode<<" positionCode:"<<ESSRobotI.pointCode;
                    }

                }
            }
        }else{
            qDebug()<<" ReplyJson_robot-->JSON对象获取失败 ReplyJsonI:"<<ReplyJsonI;
        }
    }

}

ESSRobot sapMsgInterface::GetMsgRecv_robot(QString iKey)
{
    ESSRobot ESSRobotI;
    if(ESSRobotInfoMap.contains(iKey)){
        ESSRobotI=ESSRobotInfoMap.value(iKey);
        ESSRobotInfoMap.remove(iKey);
        //qDebug()<<"<<<<< get GetMsgRecv_robot <<<<< iKey:"<<iKey<<" robotCode:"<<ESSRobotI.robotCode<<" size:"<<ESSRobotInfoMap.size();
    }
    return ESSRobotI;
}

void sapMsgInterface::ReplyJson_taskCode(QString iKey, QJsonObject ReplyJsonI)
{
    if(ReplyJsonI.isEmpty()){
        if(!taskCodeInfoMap.contains(iKey)){
            taskCodeInfoMap.insert(iKey,"postFail");//提交失败
            qDebug()<<"ReplyJson_taskCode 提交失败--->iKey:"<<iKey;
        }
        return;
    }

    QString msg=ReplyJsonI.value("msg").toString();
    if(msg=="success"){
        QJsonObject ReplyJson;
        QJsonArray rootFruitList=ReplyJsonI.value("data").toArray();
        QJsonValue value = ReplyJsonI.value("data");//第一级对象 的值
        if(value.isObject()){  //判读第二级对象是否存在
            ReplyJson=value.toObject();
            QJsonArray rootFruitList=ReplyJson.value("tasks").toArray();
            QJsonValue value = ReplyJson.value("tasks");//第一级对象 的值
            if(value.isObject()){  //判读第二级对象是否存在
                QJsonObject ReJson=value.toObject();
            }else if(value.isArray() && !rootFruitList.isEmpty()){  //判读第二级对象是以数组形式存在
                for(int i=0;i<rootFruitList.size();i++){
                    QJsonObject ReJson=value[i].toObject();
                    QString taskCode =ReJson.value("taskCode").toString();
                    QString taskStatus =ReJson.value("taskStatus").toString();
                    QString actionType =ReJson.value("actionType").toString();
                    QString robotCode =ReJson.value("robotCode").toString();
                    QString containerCode =ReJson.value("containerCode").toString();
                    QString stationCode =ReJson.value("stationCode").toString();
                    QString locationCode =ReJson.value("locationCode").toString();
                    if(!taskCodeInfoMap.contains(iKey)){
                        taskCodeInfoMap.insert(iKey,taskStatus);
//                        qDebug()<<"实时获取 ESS 任务执行状态 S--->iKey:"<<iKey<<" taskCode:"<<taskCode
//                               <<" taskStatus:"<<taskStatus<<" actionType:"<<actionType
//                              <<" robotCode:"<<robotCode<<" containerCode:"<<containerCode
//                              <<" stationCode:"<<stationCode<<" locationCode:"<<locationCode;
                    }
                }
            }
        }else{
            qDebug()<<" ReplyJson_robot-->JSON对象获取失败 ReplyJsonI:"<<ReplyJsonI;
        }
    }

}

QString sapMsgInterface::GetMsgRecv_taskCode(QString iKey)
{
    QString taskStatus="";
    if(taskCodeInfoMap.contains(iKey)){
        taskStatus=taskCodeInfoMap.value(iKey);
        taskCodeInfoMap.remove(iKey);
        qDebug()<<"<<<<< get GetMsgRecv_taskCode <<<<< iKey:"<<iKey<<" taskStatus:"<<taskStatus<<" size:"<<taskCodeInfoMap.size();
    }
    return taskStatus;
}

void sapMsgInterface::ReplyJson_Msg_MES(QString iKey, QJsonObject ReplyJson,QString actionType)
{
    ReplyMsg ReplyMsgI;
    ReplyMsgI.keyId=iKey;
    if(!ReplyJson.isEmpty()){
        ReplyMsgI.status=ReplyJson.value("type").toInt();
        ReplyMsgI.errorMsg=ReplyJson.value("msg").toString();
    }else{
        ReplyMsgI.status=-1;
        ReplyMsgI.errorMsg="提交失败";
    }
    ReplyMsgI.ReplyJson=ReplyJson;

    ReplyMsgMap.insert(iKey,ReplyMsgI);
    qDebug()<<"<<<<< set ReplyJson_Msg_MES <<<<< iKey:"<<iKey<<" status:"<<ReplyMsgI.status<<" errorMsg:"<<ReplyMsgI.errorMsg<<" Json:"<<ReplyMsgI.ReplyJson;

}

void sapMsgInterface::ReplyJson_Msg_ESS(QString iKey, QJsonObject ReplyJson,QString actionType,QString positionCode)
{
    ReplyMsg ReplyMsgI;
    ReplyMsgI.keyId=iKey;
    if(!ReplyJson.isEmpty()){
        ReplyMsgI.status=ReplyJson.value("code").toInt();
        ReplyMsgI.errorMsg=ReplyJson.value("msg").toString();
        ReplyMsgI.ReplyJson=ReplyJson;

        QJsonObject ReJson;
        QJsonValue value = ReplyJson.value("data");//获取 QJsonObject 对象
        if (value.isObject()){                          //判断 ArrayType 第二级对象是否存在
            QString dataMsg="";
            ReJson=value.toObject();
            if(actionType=="action6" || actionType=="action7"){
                dataMsg=ReJson.value(positionCode).toString();
            }else{
                dataMsg=ReJson.value(iKey).toString();
            }

            if(dataMsg!="OK"){
                ReplyMsgI.status=-1;
                ReplyMsgI.errorMsg=dataMsg;
            }
            qDebug() <<"-->dataMsg:"<<dataMsg<<" -->ReJson:"<<ReJson;
        }
    }else{
        ReplyMsgI.status=-1;
        ReplyMsgI.errorMsg="提交失败";
    }

    ReplyMsgMap.insert(iKey,ReplyMsgI);
    qDebug()<<"<<<<< set ReplyJson_Msg_ESS <<<<< iKey:"<<iKey<<" status:"<<ReplyMsgI.status<<" errorMsg:"<<ReplyMsgI.errorMsg<<" Json:"<<ReplyMsgI.ReplyJson;
}

ReplyMsg sapMsgInterface::GetMsgRecv_Msg(QString iKey)
{
    ReplyMsg ReplyMsgI;
    if(ReplyMsgMap.contains(iKey)){
        ReplyMsgI=ReplyMsgMap.value(iKey);
        ReplyMsgMap.remove(iKey);
        qDebug()<<"<<<<< get GetMsgRecv_Mes <<<<< keyId:"<<iKey<<" status:" <<ReplyMsgI.status<<" errorMsg:"<<ReplyMsgI.errorMsg<<ReplyMsgI.datalist.size();
    }
    return ReplyMsgI;
}


void sapMsgInterface::taskCodes_WW(QString iKey, WWYLPOST WWYLPOSTII, QString UserBadge, int pathId)
{
    //qDebug()<<iKey<<WWYLPOSTII.actionId<<UserBadge<<pathId;
    QJsonObject postJson=posttaskCodes_WW(iKey,WWYLPOSTII);
    setWebService_Post(iKey,sapPathMap.value(pathId).Path,postJson,UserBadge,sapPathMap.value(pathId).Type,"");

}

QJsonObject sapMsgInterface::posttaskCodes_WW(QString iKey, WWYLPOST WWYLPOSTII)
{
    //0查询状态  1任务查询  2出库  3移库  4回库  5任务取消
    QJsonObject ReJson;
    ReJson.insert("taskId",WWYLPOSTII.taskId);            //任务唯一编码
    ReJson.insert("taskType",WWYLPOSTII.taskType);        //操作,IN-入库，OUT-出库
    /*******下达订单任务************/
    if(WWYLPOSTII.actionId=="WS01"){
        ReJson.insert("boxNo",WWYLPOSTII.boxNo);              //箱号
        ReJson.insert("proNo",WWYLPOSTII.proNo);              //工单号
        ReJson.insert("boxNum",WWYLPOSTII.boxNum.toInt());            //数量
        ReJson.insert("source",WWYLPOSTII.source);            //只有在移库时不为空
        ReJson.insert("destination",WWYLPOSTII.destination);  //目的地。入库为仓库，出库为线体
    }

    /*******返回任务状态************/
    if(WWYLPOSTII.actionId=="WS02"){

        ReJson.insert("boxNo",WWYLPOSTII.boxNo);
        ReJson.insert("proNo",WWYLPOSTII.proNo);
        ReJson.insert("taskStatus",WWYLPOSTII.taskStatus);
        ReJson.insert("taskStatusDesc",WWYLPOSTII.taskStatusDesc);
        ReJson.insert("current",WWYLPOSTII.source);
        ReJson.insert("destination",WWYLPOSTII.destination);

    }
    //qDebug()<<iKey<<ReJson;
    return  ReJson;
}


 /***ESS_P协议: 0查询状态  1任务查询  2出库  3移库  4回库  5任务取消***/
void sapMsgInterface::robotCodes_query(QString iKey, ESS_Request ESS_RequestI,QString UserBadge,int pathId)
{
    QJsonObject postJson=postrobotCodes_query(iKey,ESS_RequestI);
    setWebService_Post(iKey,sapPathMap.value(pathId).Path,postJson,UserBadge,sapPathMap.value(pathId).Type,"");
}

void sapMsgInterface::robotCodes_query_Get(QString iKey, ESS_Request ESS_RequestI, QString UserBadge, int pathId)
{
    setWebService_Get(iKey,sapPathMap.value(pathId).Path+ESS_RequestI.robotCode,UserBadge,sapPathMap.value(pathId).Type);

}

QJsonObject sapMsgInterface::postrobotCodes_query(QString iKey, ESS_Request ESS_RequestI)
{
    QJsonObject rootObj;
    QJsonArray rootFruitList;
    for(int i = 0;i<ESS_RequestI.robotCodes.size();i++){
        rootFruitList.append(ESS_RequestI.robotCodes.at(i));
    }
    rootObj.insert("robotCodes", rootFruitList);
    return  rootObj;
}

void sapMsgInterface::taskCodes_query(QString iKey, ESS_Request ESS_RequestI,QString UserBadge,int pathId)
{
    QJsonObject postJson=posttaskCodes_query(iKey,ESS_RequestI);
    setWebService_Post(iKey,sapPathMap.value(pathId).Path,postJson,UserBadge,sapPathMap.value(pathId).Type,"");
}

QJsonObject sapMsgInterface::posttaskCodes_query(QString iKey, ESS_Request ESS_RequestI)
{
    QJsonObject rootObj;
    QJsonArray rootFruitList;
    for(int i = 0;i<ESS_RequestI.taskCodes.size();i++){
        rootFruitList.append(ESS_RequestI.taskCodes.at(i));
    }
    rootObj.insert("taskCodes", rootFruitList);
    return  rootObj;
}

void sapMsgInterface::taskCodes_actionId(QString iKey, ESS_Request ESS_RequestI, QString UserBadge,int pathId)
{
    qDebug()<<"taskCodes_actionId:"<<iKey<<ESS_RequestI.actionId<<UserBadge<<pathId;
    QJsonObject postJson;
    if(ESS_RequestI.pathId >=1016){
        postJson=postcontainerCode_actionId(iKey,ESS_RequestI);
    }else{
        postJson=posttaskCodes_actionId(iKey,ESS_RequestI);
    }
    setWebService_Post(iKey,sapPathMap.value(pathId).Path,postJson,UserBadge,sapPathMap.value(pathId).Type,ESS_RequestI.positionCode);

}

QJsonObject sapMsgInterface::posttaskCodes_actionId(QString iKey, ESS_Request ESS_RequestI)
{
    //0查询状态  1任务查询  2出库  3移库  4回库  5任务取消
    QJsonObject ReJson;
    QJsonObject tasksJson;
    QJsonObject taskDescribeJson;

    /********** tasks  任务列表 (taskDescribe  任务描述) ************/
    taskDescribeJson.insert("containerCode",ESS_RequestI.containerCode);                //货箱编码

    if(ESS_RequestI.actionId=="action2"){
        taskDescribeJson.insert("toStationCode",ESS_RequestI.toStationCode);            //(出库)目标工作站编码
        //taskDescribeJson.insert("fromLocationCode",ESS_RequestI.fromLocationCode);    //(出库)起始工作位  (移库)起始库位编码
    }
    if(ESS_RequestI.actionId=="action3" ){
         taskDescribeJson.insert("toLocationCode",ESS_RequestI.toLocationCode);         //(移库)目标库位编码
         taskDescribeJson.insert("fromLocationCode",ESS_RequestI.fromLocationCode);     //(出库)起始工作位  (移库)起始库位编码
    }if(ESS_RequestI.actionId=="action4" ){
         taskDescribeJson.insert("locationCode",ESS_RequestI.toLocationCode);           //(回库)目标库位编码
   }

    /********** tasks  任务列表************/
    if(ESS_RequestI.actionId=="action3" || ESS_RequestI.actionId=="action4"){
        tasksJson.insert("taskTemplateCode",ESS_RequestI.taskTemplateCode);//(移库,回库)任务模板   ()任务模板
    }
    tasksJson.insert("taskCode",ESS_RequestI.taskCode);//任务号
    tasksJson.insert("taskPriority",ESS_RequestI.taskPriority);//任务优先级

    /********** 任务指令 ************/
    ReJson.insert("taskGroupCode",ESS_RequestI.taskGroupCode);//任务组号
    ReJson.insert("groupPriority",ESS_RequestI.groupPriority);//组优先级

    tasksJson.insert("taskDescribe",taskDescribeJson);

    QJsonArray rootFruitList;
    rootFruitList.append(tasksJson);

    ReJson.insert("tasks",rootFruitList);
    qDebug()<<iKey<<ReJson;
    return  ReJson;
}

QJsonObject sapMsgInterface::postcontainerCode_actionId(QString iKey, ESS_Request ESS_RequestI)
{
    QJsonObject ReJson;
    QJsonObject tasksJson;
    if(ESS_RequestI.actionId=="action6" || ESS_RequestI.actionId=="action7"){
        tasksJson.insert("containerCode",ESS_RequestI.containerCode); //货箱编码
        tasksJson.insert("positionCode",ESS_RequestI.positionCode);   //容器入场 / 容器离场
    }if(ESS_RequestI.actionId=="action8"){
        tasksJson.insert("containerCode",ESS_RequestI.containerCode); //货箱编码
        tasksJson.insert("positionCode",ESS_RequestI.shelfBindesc);   //容器入场 / 容器离场
    }if(ESS_RequestI.actionId=="action9"){
        tasksJson.insert("containerCode",ESS_RequestI.containerCode); //货箱编码
        tasksJson.insert("containerTypeCode","C"); //货箱编码
        tasksJson.insert("storageTag",""); //货箱编码
    }

    QJsonArray rootFruitList;
    rootFruitList.append(tasksJson);
    if(ESS_RequestI.actionId=="action6"){
        ReJson.insert("containerMoveIns",rootFruitList);
    }if(ESS_RequestI.actionId=="action7"){
        ReJson.insert("containerMoveOuts",rootFruitList);
    }if(ESS_RequestI.actionId=="action8"){
        ReJson.insert("containerMoveOuts",rootFruitList);
    }if(ESS_RequestI.actionId=="action9"){
        ReJson.insert("containerAdds",rootFruitList);
    }
    qDebug()<<iKey<<ReJson;
    return  ReJson;
}

void sapMsgInterface::taskCodes_actionId_Map(QString iKey, QMap<QString, ESS_Request> ESS_RequestMap, QString UserBadge, int pathId)
{
    qDebug()<<"taskCodes_actionId_Map: --> size:"<<ESS_RequestMap.size()<<" ikey:"<<iKey<<UserBadge<<pathId;
    QJsonObject postJson=posttaskCodes_actionId_Map(iKey,ESS_RequestMap);
    setWebService_Post(iKey,sapPathMap.value(pathId).Path,postJson,UserBadge,sapPathMap.value(pathId).Type,"");

}

QJsonObject sapMsgInterface::posttaskCodes_actionId_Map(QString iKey, QMap<QString, ESS_Request> ESS_RequestMap)
{

    //0查询状态  1任务查询  2出库  3移库  4回库  5任务取消
    QJsonObject ReJson;
    ESS_Request ESS_RequestI;
    QJsonArray rootFruitList;
    QMap<QString, ESS_Request>::iterator iter= ESS_RequestMap.begin();
    while (iter !=ESS_RequestMap.end()) {
        ESS_RequestI=iter.value();

        QJsonObject tasksJson;
        QJsonObject taskDescribeJson;
        /********** tasks  任务列表 (taskDescribe  任务描述) ************/
        taskDescribeJson.insert("containerCode",ESS_RequestI.containerCode);            //货箱编码
        if(ESS_RequestI.actionId=="action2"){
            taskDescribeJson.insert("toStationCode",ESS_RequestI.toStationCode);        //(出库)目标工作站编码
        }if(ESS_RequestI.actionId=="action3" ){
             taskDescribeJson.insert("toLocationCode",ESS_RequestI.toLocationCode);     //(移库)目标库位编码
             taskDescribeJson.insert("fromLocationCode",ESS_RequestI.fromLocationCode); //(移库)起始库位编码
        }if(ESS_RequestI.actionId=="action4" ){
             taskDescribeJson.insert("locationCode",ESS_RequestI.toLocationCode);     //(回库)目标库位编码
       }

        /********** tasks  任务列表************/

        tasksJson.insert("taskTemplateCode",ESS_RequestI.taskTemplateCode);//(移库,回库)任务模板   ()任务模板
        tasksJson.insert("taskCode",ESS_RequestI.taskCode);//任务号
        tasksJson.insert("taskPriority",ESS_RequestI.taskPriority);//任务优先级

        tasksJson.insert("taskDescribe",taskDescribeJson);

        rootFruitList.append(tasksJson);

        ++iter;
    }

    /********** 任务指令 ************/
    ReJson.insert("taskGroupCode",ESS_RequestI.taskGroupCode);//任务组号
    ReJson.insert("groupPriority",ESS_RequestI.groupPriority);//组优先级

    ReJson.insert("tasks",rootFruitList);
    qDebug()<<iKey<<ReJson;
    return  ReJson;

}

void sapMsgInterface::taskCodes_cancel(QString iKey, ESS_Request ESS_RequestI,QString UserBadge,int pathId)
{
    qDebug()<<"taskCodes_cancel:"<<iKey<<ESS_RequestI.actionId;
    QJsonObject postJson=posttaskCodes_cancel(iKey,ESS_RequestI);
    setWebService_Post(iKey,sapPathMap.value(pathId).Path,postJson,UserBadge,sapPathMap.value(pathId).Type,"");
}

QJsonObject sapMsgInterface::posttaskCodes_cancel(QString iKey, ESS_Request ESS_RequestI)
{
    QJsonObject rootObj;
    QJsonArray rootFruitList;
    for(int i = 0;i<ESS_RequestI.taskCodes.size();i++){
        rootFruitList.append(ESS_RequestI.taskCodes.at(i));
    }
    rootObj.insert("taskCodes", rootFruitList);
    return  rootObj;
}

void sapMsgInterface::taskCodes_request(QString iKey, ESS_Request ESS_RequestI, QString UserBadge, int pathId)
{
    QJsonObject postJson=posttaskCodes_request(iKey,ESS_RequestI);
    setWebService_Post(iKey,sapPathMap.value(pathId).Path,postJson,UserBadge,sapPathMap.value(pathId).Type,"");
}

QJsonObject sapMsgInterface::posttaskCodes_request(QString iKey, ESS_Request ESS_RequestI)
{
    //0查询状态  1任务查询  2出库  3移库  4回库  5任务取消
    QJsonObject ReJson;
    QJsonObject tasksJson;

    /********** 任务指令 ************/
    ReJson.insert("eventCode","eventCode");//ESS-P 事件 回调类型
    ReJson.insert("taskCode",ESS_RequestI.taskCode);//任务号
    ReJson.insert("taskStatus","taskStatus");//任务状态
    ReJson.insert("actionCode","actionCode");//任务优先级
    ReJson.insert("robotCode","robotCode");//任务优先级
    ReJson.insert("containerCode","containerCode");//任务优先级
    ReJson.insert("trayLevel","trayLevel");//任务优先级


    tasksJson.insert("containerCode","containerCode2211");//任务优先级
    tasksJson.insert("trayLevel","trayLevel");//任务优先级
    tasksJson.insert("positionCode","positionCode");//任务优先级

    QJsonArray rootFruitList;
    rootFruitList.append(tasksJson);
    rootFruitList.append(tasksJson);
    rootFruitList.append(tasksJson);

    ReJson.insert("trays",rootFruitList);
    qDebug()<<iKey<<ReJson;
    return  ReJson;
}


//Get SAP 数据
void sapMsgInterface::setWebService_Get(QString LabelNo, QString UrlPath,
                                        QString UserBadge, QString Type)
{
    allWebConut++;
    QUrl url(UrlPath);
    QNetworkRequest NetworkRequest;
    NetworkRequest.setUrl(url);
    NetworkRequest.setRawHeader("User",QString("{%1}").arg("User6537").toLatin1());
    NetworkRequest.setRawHeader("Accept-Language","{en-US}");
    QNetworkReply*  NetworkReply = NetworkMgr.get(NetworkRequest);

    for(int i=0;i<WebServiceItiemMap.length();i++){
        if(WebServiceItiemMap[i].ikey==LabelNo){
            WebServiceItiemMap[i].NetworkRepItiem->deleteLater();//关闭
            WebServiceItiemMap.removeAt(i);i--;
            qDebug()<<"WebServiceItiemMap.removeAt(i) "<<UrlPath;
        }
    }

    WebServiceItiem WebServiceItiem0;
    WebServiceItiem0.ikey=LabelNo;             //唯一键
    WebServiceItiem0.UrlPath=UrlPath;       //路径
    WebServiceItiem0.actionType=Type;       //操作类型  WS02 WS03 …… post
    WebServiceItiem0.userBadge=UserBadge;   //员工工号
    WebServiceItiem0.LabelNo=LabelNo;
    WebServiceItiem0.NetworkRepItiem=NetworkReply;
    WebServiceItiemMap.append(WebServiceItiem0);

    qDebug()<<"ikey:"<<WebServiceItiem0.ikey<<" Send UrlPath: "<<UrlPath;

}

//post 数据给 SAP
void sapMsgInterface::setWebService_Post(QString iKey,QString UrlPath, QJsonObject postJson,
                                         QString UserBadge, QString Type,QString positionCode)
{
    QUrl url(UrlPath);
    QNetworkRequest NetworkRequest;
    NetworkRequest.setUrl(url);//地址信息

    NetworkRequest.setRawHeader("User",QString("{%1}").arg(UserBadge).toLatin1());
    NetworkRequest.setRawHeader("Accept-Language","{en-US}");//选中语言类型
    NetworkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/json;charset=utf-8");//"text/json" 内容编码类型
    QNetworkReply*NetworkReply=NetworkMgr.post(NetworkRequest,QJsonDocument(postJson).toJson());

    for(int i=0;i<WebServiceItiemMap.length();i++){
        if(WebServiceItiemMap[i].ikey==iKey){
            WebServiceItiemMap[i].NetworkRepItiem->deleteLater();//关闭
            WebServiceItiemMap.removeAt(i);i--;
        }
    }

    WebServiceItiem WebServiceItiem0;
    WebServiceItiem0.ikey=iKey;                 //唯一键
    WebServiceItiem0.UrlPath=UrlPath;           //路径
    WebServiceItiem0.queryJson=postJson;        //请求数据
    WebServiceItiem0.userBadge=UserBadge;       //员工工号
    WebServiceItiem0.actionType=Type;           //操作类型  WS02 WS03 …… post
    WebServiceItiem0.positionCode=positionCode; //特殊ikey

    WebServiceItiem0.NetworkRepItiem=NetworkReply;
    WebServiceItiemMap.append(WebServiceItiem0);

    if(Type!="action0" && Type!="action1"){
        qDebug()<<"Post-->UrlPath: "<<UrlPath;
        qDebug()<<"Post-->postJson: "<<postJson;
    }

}


void sapMsgInterface::setWebService_Post_WS06(QString iKey, QString UrlPath, QJsonArray postJson, QString UserBadge, QString Type)
{
    QUrl url(UrlPath);
    QNetworkRequest NetworkRequest;
    NetworkRequest.setUrl(url);//地址信息

    NetworkRequest.setRawHeader("User",QString("{%1}").arg(UserBadge).toLatin1());
    NetworkRequest.setRawHeader("Accept-Language","{en-US}");//选中语言类型
    NetworkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/json;charset=utf-8");//"text/json" 内容编码类型
    QNetworkReply*NetworkReply=NetworkMgr.post(NetworkRequest,QJsonDocument(postJson).toJson());

    for(int i=0;i<WebServiceItiemMap.length();i++){
        if(WebServiceItiemMap[i].ikey==iKey){
            WebServiceItiemMap[i].NetworkRepItiem->deleteLater();//关闭
            WebServiceItiemMap.removeAt(i);i--;
        }
    }

    WebServiceItiem WebServiceItiem0;
    WebServiceItiem0.ikey=iKey;             //唯一键
    WebServiceItiem0.UrlPath=UrlPath;       //路径
    WebServiceItiem0.actionType=Type;       //操作类型  WS02 WS03 …… post
    WebServiceItiem0.userBadge=UserBadge;   //员工工号
    WebServiceItiem0.postArray=postJson;    //请求数据
    WebServiceItiem0.NetworkRepItiem=NetworkReply;
    WebServiceItiemMap.append(WebServiceItiem0);

    if(Type!="action0" && Type!="action22"){
        qDebug()<<"Post-WS06->UrlPath: "<<UrlPath;
        qDebug()<<"Post-WS06->postJson: "<<postJson;
    }

}

void sapMsgInterface::setWebService_SAOP_Post(QString iKey, QString UrlPath, QDomDocument doc, QString UserBadge, QString Type)
{
    QUrl url(UrlPath);
    QNetworkRequest NetworkRequest;
    NetworkRequest.setUrl(url);//地址信息

    NetworkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"text/xml;charset=utf-8");//"text/json" 内容编码类型
    NetworkRequest.setRawHeader("SOAPAction", "http://tempuri.org/IJDSWS/PrintLabel");
    QNetworkReply*NetworkReply=NetworkMgr.post(NetworkRequest,doc.toString().toUtf8().constData());

    for(int i=0;i<WebServiceItiemMap.length();i++){
        if(WebServiceItiemMap[i].ikey==iKey){
            WebServiceItiemMap[i].NetworkRepItiem->deleteLater();//关闭
            WebServiceItiemMap.removeAt(i);i--;
        }
    }

    WebServiceItiem WebServiceItiem0;
    WebServiceItiem0.ikey=iKey;             //唯一键
    WebServiceItiem0.UrlPath=UrlPath;       //路径
    WebServiceItiem0.actionType=Type;       //操作类型  WS02 WS03 …… post
    WebServiceItiem0.userBadge=UserBadge;   //员工工号
    WebServiceItiem0.doc=doc;    //请求数据
    WebServiceItiem0.NetworkRepItiem=NetworkReply;
    WebServiceItiemMap.append(WebServiceItiem0);

    if(Type!="action0" && Type!="action22"){
        qDebug()<<"--SAOP-->UrlPath: "<<UrlPath;
        qDebug()<<"--SAOP-->DOC: "<<doc.toString().toUtf8().constData();
    }

}
