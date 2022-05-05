


#include "httpserver.h"


#include <QTcpServer>

QHash<int, QString> STATUS_CODES;

HttpServer::HttpServer(QObject *parent)
    : QObject(parent)
    , m_tcpServer(0)
{
#define STATUS_CODE(num, reason) STATUS_CODES.insert(num, reason);
// {{{
  STATUS_CODE(100, "Continue")
  STATUS_CODE(101, "Switching Protocols")
  STATUS_CODE(102, "Processing")                 // RFC 2518) obsoleted by RFC 4918
  STATUS_CODE(200, "OK")
  STATUS_CODE(201, "Created")
  STATUS_CODE(202, "Accepted")
  STATUS_CODE(203, "Non-Authoritative Information")
  STATUS_CODE(204, "No Content")
  STATUS_CODE(205, "Reset Content")
  STATUS_CODE(206, "Partial Content")
  STATUS_CODE(207, "Multi-Status")               // RFC 4918
  STATUS_CODE(300, "Multiple Choices")
  STATUS_CODE(301, "Moved Permanently")
  STATUS_CODE(302, "Moved Temporarily")
  STATUS_CODE(303, "See Other")
  STATUS_CODE(304, "Not Modified")
  STATUS_CODE(305, "Use Proxy")
  STATUS_CODE(307, "Temporary Redirect")
  STATUS_CODE(400, "Bad Request")
  STATUS_CODE(401, "Unauthorized")
  STATUS_CODE(402, "Payment Required")
  STATUS_CODE(403, "Forbidden")
  STATUS_CODE(404, "Not Found")
  STATUS_CODE(405, "Method Not Allowed")
  STATUS_CODE(406, "Not Acceptable")
  STATUS_CODE(407, "Proxy Authentication Required")
  STATUS_CODE(408, "Request Time-out")
  STATUS_CODE(409, "Conflict")
  STATUS_CODE(410, "Gone")
  STATUS_CODE(411, "Length Required")
  STATUS_CODE(412, "Precondition Failed")
  STATUS_CODE(413, "Request Entity Too Large")
  STATUS_CODE(414, "Request-URI Too Large")
  STATUS_CODE(415, "Unsupported Media Type")
  STATUS_CODE(416, "Requested Range Not Satisfiable")
  STATUS_CODE(417, "Expectation Failed")
  STATUS_CODE(418, "I\"m a teapot")              // RFC 2324
  STATUS_CODE(422, "Unprocessable Entity")       // RFC 4918
  STATUS_CODE(423, "Locked")                     // RFC 4918
  STATUS_CODE(424, "Failed Dependency")          // RFC 4918
  STATUS_CODE(425, "Unordered Collection")       // RFC 4918
  STATUS_CODE(426, "Upgrade Required")           // RFC 2817
  STATUS_CODE(500, "Internal Server Error")
  STATUS_CODE(501, "Not Implemented")
  STATUS_CODE(502, "Bad Gateway")
  STATUS_CODE(503, "Service Unavailable")
  STATUS_CODE(504, "Gateway Time-out")
  STATUS_CODE(505, "HTTP Version not supported")
  STATUS_CODE(506, "Variant Also Negotiates")    // RFC 2295
  STATUS_CODE(507, "Insufficient Storage")       // RFC 4918
  STATUS_CODE(509, "Bandwidth Limit Exceeded")
  STATUS_CODE(510, "Not Extended")                // RFC 2774
// }}}

    qRegisterMetaType<SAPExcelInfo >("SAPExcelInfo");

    errorMsgMap.insert(-1,"非法值错误");
    errorMsgMap.insert(0,"创建成功");
    errorMsgMap.insert(1,"胶箱编码异常");
    errorMsgMap.insert(2,"任务类型异常");
    errorMsgMap.insert(3,"物料编码异常");
    errorMsgMap.insert(4,"数量异常");
    errorMsgMap.insert(5,"胶箱编码重复");
    errorMsgMap.insert(6,"当前任务无法出库");

    errorMsgMap.insert(100,"接收成功");

//  StTimer = new QTimer(this);
//  connect(StTimer,&QTimer::timeout,this,&HttpServer::ON_HttpServerTimer);
//  StTimer->start(500);

}

HttpServer::~HttpServer()
{
}

void HttpServer::newConnection()
{
    Q_ASSERT(m_tcpServer);
    while(m_tcpServer->hasPendingConnections()) {
        HttpConnection *connection = new HttpConnection(m_tcpServer->nextPendingConnection(), this);
        connect(connection,&HttpConnection::newReplyData_task,this,&HttpServer::ON_newReplyData_task);
        connect(connection, SIGNAL(newRequest(HttpRequest*, HttpResponse*)),
		   this, SLOT(onRequest(HttpRequest*, HttpResponse*)));

    }
}

bool HttpServer::listen(const QHostAddress &address, quint16 port)
{
    m_tcpServer = new QTcpServer;
    connect(m_tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    return m_tcpServer->listen(address, port);
}

bool HttpServer::listen(quint16 port)
{
    return listen(QHostAddress::Any, port);
}

//127.0.0.1:58890/
void HttpServer::onRequest(HttpRequest* req, HttpResponse* resp)
{
	//实现你的响应代码
	QString reply  = tr("<html><head><title>Rokh Server Test</title></head><body><h1>hello!</h1></body></html>");
	resp->setHeader("Content-Type", "text/html");
	resp->setStatus(200);

    //http 接口数据解析返回
    QJsonObject postJson=_ReplyJson(currentReplyJsonI.taskType,currentReplyJsonI);
    resp->jsend_(postJson);

//    QJsonArray rootFruitList;
//    rootFruitList.append(postJson);
//    resp->jsend(rootFruitList);

	return;

}

void HttpServer::ON_HttpServerTimer()
{

}

void HttpServer::ON_newReplyData_task(QString ClientIP,ReplyJson ReplyJsonI,QJsonObject ReplyJson)
{
    currentReplyJsonI=ReplyJsonI;

    CurrentSendI.postJson=ReplyJson;
    CurrentSendI.UrlPath="server";
    //sapMsgInterface::getInstance()->setCurrentSend_(CurrentSendI);

    if(ReplyJsonI.taskType=="newTask"){     //MES 创建订单任务
        currentReplyJsonI=analysReplyJson_new(ReplyJson,currentReplyJsonI);
    }if(ReplyJsonI.taskType=="taskStatus"){ //MES 任务状态反馈
        currentReplyJsonI=analysReplyJson_taskStatus(ReplyJson,currentReplyJsonI);
    }

    if(ReplyJsonI.taskType=="agvTask"){         //创建 ESS-AGV 任务
        currentReplyJsonI=analysReplyJson_agvnew(ReplyJson,currentReplyJsonI);
    }if(ReplyJsonI.taskType=="agvStatus"){      //ESS-AGV任务状态反馈
        currentReplyJsonI=analysReplyJson_agvStatus(ReplyJson,currentReplyJsonI);
    }

}

ReplyJson HttpServer::analysReplyJson_new(QJsonObject ReplyJson_,ReplyJson ReplyJsonI)
{
    QJsonObject ReplyJson=ReplyJson_;
    SAPExcelInfo SAPExcelInfoI;
    SAPExcelInfoI.taskId=ReplyJson.value("taskId").toString();
    SAPExcelInfoI.taskType=ReplyJson.value("operate").toString();               //操作 OUT-出库  IN-入库
    if(SAPExcelInfoI.taskType=="IN"){
        SAPExcelInfoI.taskTypeDesc="入库";
        SAPExcelInfoI.sourcestation="STATION-01";
        SAPExcelInfoI.destination="";
    }if(SAPExcelInfoI.taskType=="OUT"){
        SAPExcelInfoI.taskTypeDesc="出库";
        SAPExcelInfoI.sourcestation="";
    }if(SAPExcelInfoI.taskType=="MOVE"){
        SAPExcelInfoI.taskTypeDesc="移库";
        SAPExcelInfoI.sourcestation=ReplyJson.value("source").toString();       //目的地。入库为库位，出库为线体
    }

    SAPExcelInfoI.destination=ReplyJson.value("destination").toString();    //目的地。入库为库位，出库为线体
    SAPExcelInfoI.containerCode=ReplyJson.value("boxNo").toString();            //容器编码 (即胶箱编码) ->唯一
    SAPExcelInfoI.Material=ReplyJson.value("proNo").toString();                 //物料号 产品编码
    QString taskQty=ReplyJson.value("pcbNum").toString();
    SAPExcelInfoI.taskQty=taskQty.toDouble();                                   //数量

    QJsonArray rootFruitList=ReplyJson.value("pcbList").toArray();
    for(int i=0;i<rootFruitList.size();i++){
        SAPExcelInfoI.MaterialList.append(rootFruitList.at(i).toString());
    }
    SAPExcelInfoI.MaterialListdesc= SAPExcelInfoI.MaterialList.join("&");

    //SAPExcelInfoI.MaterialListdesc=ReplyJson.value("pcbList").toString();
    //SAPExcelInfoI.MaterialList=SAPExcelInfoI.MaterialListdesc.split("&");             //物料编码 集合

    SAPExcelInfoI.creatTimer=QDateTime::currentDateTime();

    ReplyJsonI.status=0;
    if(SAPExcelInfoI.containerCode.trimmed().size()!=10){
        ReplyJsonI.status=1;
    }if(SAPExcelInfoI.taskType==""){
        ReplyJsonI.status=2;
    }

    if(ReplyJsonI.status==0){
        ReplyJsonI=checkTaskRepeat(SAPExcelInfoI,ReplyJsonI);//判断当前任务是否重复下达 或者有未完成的任务
        if(ReplyJsonI.status==0){
            SAPExcelInfoI.taskStatus=0;
            SAPExcelInfoI.taskStatusDesc="待执行";
            emit sig_SAPExcelInfo_new(SAPExcelInfoI);// new task
        }else{

        }
    }

    ReplyJsonI.errorMsg=errorMsgMap.value(ReplyJsonI.status);

    qDebug()<<"MES 下达任务--> 类型:"<<SAPExcelInfoI.taskType<<" taskId:"<<SAPExcelInfoI.taskId
           <<" sourcestation:"<<SAPExcelInfoI.sourcestation<<" destination:"<<SAPExcelInfoI.destination
          <<" containerCode:"<<SAPExcelInfoI.containerCode<<"errorMsg:"<<ReplyJsonI.errorMsg;

    return ReplyJsonI;
}

ReplyJson HttpServer::analysReplyJson_taskStatus(QJsonObject ReplyJson_, ReplyJson ReplyJsonI)
{
    QJsonObject ReplyJson=ReplyJson_;
    SAPExcelInfo SAPExcelInfoI;
    SAPExcelInfoI.taskType=ReplyJson.value("taskType").toString();
    SAPExcelInfoI.taskId=ReplyJson.value("taskId").toString();
    SAPExcelInfoI.taskStatus=ReplyJson.value("taskStatus").toInt();
    SAPExcelInfoI.taskStatusDesc=ReplyJson.value("taskStatusDesc").toString();

    if(SAPExcelInfoI.taskId!=""){
        ReplyJsonI.status=100;
        ReplyJsonI.errorMsg=errorMsgMap.value(ReplyJsonI.status);
    }
    qDebug()<<"MES 状态返回--> 类型: taskType:"<<SAPExcelInfoI.taskType<<" taskId:"<<SAPExcelInfoI.taskId
           <<" taskStatus"<<SAPExcelInfoI.taskStatus<<" taskStatusDesc:"<<SAPExcelInfoI.taskStatusDesc;

    return ReplyJsonI;
}

ReplyJson HttpServer::analysReplyJson_agvnew(QJsonObject ReplyJson_, ReplyJson ReplyJsonI)
{
    QJsonObject ReplyJson=ReplyJson_;
    SAPExcelInfo SAPExcelInfoI;

//    SAPExcelInfoI.taskId=ReplyJson.value("taskId").toString();
//    SAPExcelInfoI.agvNum=ReplyJson.value("agvId").toInt();
//    SAPExcelInfoI.priority=ReplyJson.value("priority").toInt();

//    QJsonArray rootFruitList=ReplyJson.value("taskList").toArray();
//    QJsonValue value = ReplyJson.value("taskList");//第一级对象 的值
//    if(value.isObject()){  //判读第二级对象是否存在
//        QJsonObject ReJson=value.toObject();
//    }else if(value.isArray() && !rootFruitList.isEmpty()){  //判读第二级对象是以数组形式存在
//        for(int i=0;i<rootFruitList.size();i++){
//            SAPExcelInfo SAPExcelInfoI;
//            QJsonObject ReJson=value[i].toObject();
//            QString load=ReJson.value("load").toString();
//            QString unLoad=ReJson.value("unLoad").toString();
//            qDebug()<<"agvnew --> load:"<<load<<" unLoad:"<<unLoad;
//        }
//    }

//    qDebug()<<"agvnew --> taskId:"<<SAPExcelInfoI.taskId<<" agvNum:"<<SAPExcelInfoI.agvNum
//         <<" priority:"<<SAPExcelInfoI.priority<<" rootFruitList.size:"<< rootFruitList.size();

    return ReplyJsonI;
}

ReplyJson HttpServer::analysReplyJson_agvStatus(QJsonObject ReplyJson_, ReplyJson ReplyJsonI)
{
    QJsonObject ReplyJson=ReplyJson_;

    ESS_Repost ESS_ReplyI;
    ESS_ReplyI.eventCode_=ReplyJson.value("eventCode").toString();           //ESS-P 事件 回调类型
    ESS_ReplyI.taskCode=ReplyJson.value("taskCode").toString();             //任务号
    ESS_ReplyI.taskStatus=ReplyJson.value("taskStatus").toString();         //任务状态
    ESS_ReplyI.actionCode=ReplyJson.value("actionCode").toString();         //任务行为编号 (LOAD取箱成功)
    ESS_ReplyI.robotCode=ReplyJson.value("robotCode").toString();           //机器人编码
    ESS_ReplyI.containerCode=ReplyJson.value("containerCode").toString();   //货箱编码
    ESS_ReplyI.trayLevel=ReplyJson.value("trayLevel").toString();           //背篓层号
    ESS_ReplyI.stationCode=ReplyJson.value("stationCode").toString();       //工作站编码
    ESS_ReplyI.locationCode=ReplyJson.value("locationCode").toString();     //入库取箱:库位编码  出库放箱: 工作位编码

    QJsonObject ReJson;
    QJsonArray rootFruitList=ReplyJson.value("trays").toArray();
    QJsonValue value = ReplyJson.value("trays");//第一级对象 的值
    if (value.isObject()){  //判读第二级对象是否存在
        ReJson=value.toObject();
        qDebug() <<"ReJson 1"<<ReJson;
    }if(value.isArray()){//判读第二级对象是以数组形式存在
        for(int i=0;i<rootFruitList.size();i++){
            ReJson=value[i].toObject();
            QString containerCode=ReJson.value("containerCode").toString();   //货箱编码
            QString trayLevel=ReJson.value("trayLevel").toString();           //背篓层号
            QString positionCode=ReJson.value("positionCode").toString();     //位置编码
            if(!ESS_ReplyI.containerCode_Tray.contains(containerCode)){
                ESS_ReplyI.containerCode_Tray.insert(containerCode,trayLevel.toInt());
                qDebug() <<"ReJson 2-----货箱编码:"<<containerCode<<" 背篓层号:"<<trayLevel<<" 位置编码:"<<positionCode<<"size "<<rootFruitList.size();
            }
        }
    }

    if(ESS_ReplyI.eventCode_!=""){                                   //未知事件
        if(ServerInitItem.eventCodeMap.contains(ESS_ReplyI.eventCode_)){
            ESS_ReplyI.eventCodeDesc=ServerInitItem.eventCodeMap.value(ESS_ReplyI.eventCode_).eventCodeDesc;
        }else{
            ESS_ReplyI.eventCodeDesc=ESS_ReplyI.eventCode_;
        }
        ESS_ReplyI.eventCodeI=ServerInitItem.eventCodeMap.value(ESS_ReplyI.eventCode_);
        ESS_ReplyI.timer_str=QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");
        ESS_Single::GetInstance()->setCurrentESS_Repost(ESS_ReplyI.taskCode,ESS_ReplyI.eventCodeI.eventCodeDesc);


    }

    qDebug()<<"--->回调类型:"<<ESS_ReplyI.eventCode_<<" 事件注释:"<<ESS_ReplyI.eventCodeDesc
         <<" 任务号:"<<ESS_ReplyI.taskCode<<" 任务行为编号:"<<ESS_ReplyI.actionCode
         <<" 货箱编码:"<<ESS_ReplyI.containerCode
         <<" 工作站编码"<<ESS_ReplyI.stationCode<<" 库位编码/工作位编码"<<ESS_ReplyI.locationCode
         <<" 位置编码:"<<ESS_ReplyI.positionCode
         <<" 任务状态"<<ESS_ReplyI.eventCodeI.eventCodeDesc<<"  IN:"<<ESS_ReplyI.eventCodeI.taskType_IN
         <<" OUT:"<<ESS_ReplyI.eventCodeI.taskType_OUT<<" MOVE"<<ESS_ReplyI.eventCodeI.taskType_Empty;

    return ReplyJsonI;
}

//http 接口数据解析返回
QJsonObject HttpServer::_ReplyJson(QString action, ReplyJson ReplyJsonI)
{
    QJsonObject ReJson;
    QJsonObject tasksJson;

    QString taskType=currentReplyJsonI.taskType;
    if(taskType== "newTask" || taskType== "taskStatus"){
        ReJson.insert("type",ReplyJsonI.status);            //0 代表正常，其余代表异常
        ReJson.insert("msg",ReplyJsonI.errorMsg);           //0 代表正常，其余代表异常
    }

    if(taskType== "agvTask" || taskType== "agvStatus"){      //创建 AGV 任务
        ReJson.insert("code",ReplyJsonI.status);             //0 代表正常，其余代表异常
        ReJson.insert("msg",ReplyJsonI.errorMsg);
    }

    QJsonArray FruitList;
    for(int i=0;i<ReplyJsonI.datalist.size();i++){
        FruitList.append(ReplyJsonI.datalist[i]);
    }
    FruitList.append(tasksJson);
    ReJson.insert("data",FruitList);

    QJsonDocument document=QJsonDocument(ReJson);
    QByteArray ReplyData = document.toJson();// 转换成QByteArray
    CurrentSendI.ReplyData=ReplyData;
    CurrentSendI.Errorinfo=currentReplyJsonI.errorMsg;
    sapMsgInterface::getInstance()->setCurrentSend_(CurrentSendI);

    qDebug()<<"_ReplyJson: "<<action<<" error:"<<ReplyJsonI.status<<ReplyJsonI.errorMsg<<" ReJson:"<<ReJson;

    return  ReJson;

}

ReplyJson HttpServer::checkTaskRepeat(SAPExcelInfo SAPExcelInfoI,ReplyJson ReplyJsonI)
{
    if(SAPExcelInfoI.taskType=="OUT"){ReplyJsonI.status=6;}
    bool move_s=false;bool move_e=false;
    QMap<QString, shelfBinInfo> shelfBinInfoMap= ESS_Single::GetInstance()->getshelfBinInfoMap();
    QMap<QString ,shelfBinInfo>::const_iterator iter_=shelfBinInfoMap.begin();
    while (iter_!=shelfBinInfoMap.end()) {
        if(iter_!=nullptr){
            if(SAPExcelInfoI.containerCode==iter_.value().containerCode){
                if(SAPExcelInfoI.taskType=="IN"){   //检查胶框是否重复
                    ReplyJsonI.status=5;
                }if(SAPExcelInfoI.taskType=="OUT"){//检查是否满足出库条件
                    if(iter_.value().status==2){    //0 空闲  1入库中  2入库完成  3出库中  0出库完成--空闲
                        ReplyJsonI.status=0;
                    }else{
                        ReplyJsonI.status=6;
                    }
                }
            }

            if(SAPExcelInfoI.taskType=="MOVE"){
                if(SAPExcelInfoI.sourcestation==iter_.value().podIdDesc //检查起始库位
                        && SAPExcelInfoI.containerCode==iter_.value().containerCode){
                    move_s=true;
                }if(SAPExcelInfoI.destination==iter_.value().podIdDesc //检查目标库位
                        && iter_.value().containerCode==""){
                    move_e=true;
                }
            }

        }else{
            return  ReplyJsonI;
        }
        iter_++;
    }

    if(SAPExcelInfoI.taskType=="MOVE"){
        if(!move_s || !move_e){
            ReplyJsonI.status=6;
        }
    }

    return ReplyJsonI;
}
