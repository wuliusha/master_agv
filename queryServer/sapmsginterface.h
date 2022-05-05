#ifndef SAPMSGINTERFACE_H
#define SAPMSGINTERFACE_H

#include <QObject>
#include<QNetworkReply>
#include<QNetworkRequest>
#include<QJsonObject>
#include<QJsonArray>
#include<QUrl>
#include<QJsonDocument>
#include<QMap>
#include <QMutex>
#include<QtXml>
#include<QtCore/QCoreApplication>
#include<QDomDocument>

#include "getinstancedefine.h"
#include "comm/config/cfgsetting.h"
#include "singleProject/single_project.h"
#include "queryServer/queryserver.h"
#include "comm/datebaseConnectPool/connectpoolfactory.h"

struct WebServiceItiem
{
    QString userBadge="";       // 员工工号
    QString LabelNo="";
    QString actionType="";      // 操作类型 WS01 WS02 WS03 ……
    QString ikey="";            // 唯一键
    QString UrlPath="";         //路径
    int restcount=0;            //发送计数 最多三次

    QString positionCode="";    //特殊ikey

    QJsonObject queryJson;      // JSON 请求数据 WS02,WS05
    QDomDocument doc;           // xml 请求数据 WS04
    QJsonArray postArray;       //WS06
    QNetworkReply *NetworkRepItiem; //网络回复
};

//
struct retMsgStruct{
    QString iKey="";
    QString result=""; //"result":"S",           //结果, S为成功, E为错误
    QString message="";//"message":""            //系统讯息
    QString errorType="0";//错误类型
};


struct sapPath_Print{
   int PathID;          //打印路径
   QString IssueType;   //发料类型
   QString printer;     //打印机型号
   QString input_type;  //打印类型
};

struct WebService{
    QString LabelNo;
    QString UserBadge;
    int pathId;
};

/*******微网优联  MES************/
struct WWYLPOST{

    QString actionId="MES接口";
    QString taskId="";  //任务唯一编码
    QString operate=""; //操作,IN-入库，OUT-出库
    QString boxNo="";   //箱号
    QStringList pcbList;//pcb集合

    QString source="";      //来源  入库为NULL，出库为库位
    QString destination="";//目的地。入库为仓库，出库为线体

    /*******下达订单任务************/
    QString proNo="";   //产品编码
    QString pcbNum="";  //pcb数量

    /*******返回任务状态************/
    QString resultStatus="";//执行结果,1-开始执行，2-执行中，3执行失败，4-执行成功


};


/*******海柔************/
struct ESS_Request{

    int pathId=0;
    QString actionId="";//0查询状态  1任务查询  2出库  3移库  4回库  5任务取消

/********** 状态查询 ************/
    QString robotCode="";
    QList<QString>robotCodes; //机器人查询接口
    QList<QString>taskCodes;  //任务查询接口

/********** 任务指令 ************/
    QString taskGroupCode="";//任务组号
    QString groupPriority="";//组优先级

    /********** tasks  任务列表************/
    QString taskCode="";       //任务号
    QString taskPriority="";   //任务优先级

    //QString deadline;         //(出库)截单时间
    QString taskTemplateCode="";   //(移库,回库)任务模板   ()任务模板

    /********** tasks  任务列表 (taskDescribe  任务描述) ************/
    QString containerCode="";      //货箱编码
    //QString toStationType;    //(出库)目标工作站类型
    QString toStationCode="";      //(出库)目标工作站编码
    QString toLocationCode="";     //(移库 回库)目标库位编码
    QString fromLocationCode="";   //(出库)起始工作位  (移库)起始库位编码

    QString positionCode="";      //容器入场 / 容器离场

};

struct ESS_Repost{

    QString timer_str="";      //唯一标识 时间戳
    QString eventCode_="";      //ESS-P 事件 回调类型
    QString eventCodeDesc="";  //ESS-P 事件 回调类型  注释
    QString taskCode="";       //任务号
    QString taskStatus="";     //任务状态
    QString actionCode="";     //任务行为编号 (LOAD取箱成功)
    QString robotCode="";      //机器人编码
    QString containerCode="";  //货箱编码
    QString trayLevel="";      //背篓层号
    QString stationCode="";    //工作站编码
    QString locationCode="";   //入库取箱:库位编码  出库放箱: 工作位编码
    QString positionCode="";   //位置编码

    eventCode eventCodeI;
    QMap<QString,int>containerCode_Tray;//货箱编码-背篓序号  (在机器人到达工作站时)

};


//(备注: 任务执行过程中,取箱与放箱操作可重复执行,用于任务异常时，人工纠正后可继续执行)

//出库:-1 默认值  0开始执行  1ESS前往取箱  2到达工作站  3容器到位  4取箱成功  5离开工作站  6放箱成功  7任务完成


//入库:-1 默认值  0开始执行  1ESS前往工作站  2到达工作站  3容器到位  4取箱成功  5离开工作站  6放箱成功  7任务完成


struct ESS_Reply{
    int actionId;//0查询状态  1任务查询  2出库  3移库  4回库  5任务取消

    QString taskCode;       //任务号
    int code;       // 0 代表正常，其余代表异常
    QString msg;
    QString data;   //返回数据对象，如果需要(任务号 货箱编码)
};

struct CurrentSend{
    QString UrlPath="";
    QJsonObject postJson;
    QDomDocument postdoc;           // xml 请求数据

    QString Errorinfo="";
    QByteArray ReplyData;
};


class sapMsgInterface : public QObject
{
    Q_OBJECT
private:
    explicit sapMsgInterface(QObject *parent = nullptr);

public:
    REGISTERGETINSTANCE(sapMsgInterface)

    //static sapMsgInterface* getInstance();
    QTimer *MsgTimer;
    CurrentSend CurrentSendI;
    CurrentSend CurrentSendI_;
    QMap<int ,sapPath >sapPathMap;
    QMap<QString ,int>currentIkeyMap;//SAP 数据 错误计时  最多只发 3次

    QMap<QString,WebService>WebServiceMap;//待 请求

    void setSapPathMap();           //读取数据库的路径配置信息
    void setCurrentSend(CurrentSend CurrentSend0);
    CurrentSend getCurrentSend();   //缓存最新提交的路径以及数据信息

    void setCurrentSend_(CurrentSend CurrentSend0);
    CurrentSend getCurrentSend_();   //缓存最新提交的路径以及数据信息

    QMap<int ,sapPath > getsapPathMap();//获取数据库的路径配置信息
    void setLabelMsgclear();//取消查询sap接口任务任务

public slots:

    //读取服务器回复
    void ReadResponse(QNetworkReply *Reply);
    void sapMsgTimer();
    void ONReplyError(WebServiceItiem WebServiceItiemI);//重复发送机制

public:
    //返回数据解析  actionType= "0" 失败
    void analysReplyJson(QString iKey,QJsonDocument JsonAnalyse,QString actionType,QString positionCode);

public:

    //<<<<<<<<<<WS01 Request <<<<<<<<<<<<
    QMap<QString,ESSRobot>labelMsgStructMap;
    void getLabelMsg(QString LabelNo, QString UserBadge,int pathId);

    //<<<<<<<<<<ESS 海柔夹包机器人状态信息 Reply<<<<<<<<<<<<
    QMap<QString,ESSRobot>ESSRobotInfoMap;
    void ReplyJson_robot(QString iKey, QJsonObject ReplyJsonI);
    ESSRobot GetMsgRecv_robot(QString iKey);

    //<<<<<<<<<< POST 接口返回 <<<<<<<<<<<<
    QMap<QString,ReplyMsg>ReplyMsgMap;
    void ReplyJson_Msg_MES(QString iKey, QJsonObject ReplyJson,QString actionType);//MES 接口返回

    void ReplyJson_Msg_ESS(QString iKey, QJsonObject ReplyJson,QString actionType,QString positionCode);//ESS 接口返回

    ReplyMsg GetMsgRecv_Msg(QString iKey);


    //<<<<<<<<<<ESS Reply<<<<<<<<<<<<
    void ReplyJson_ESS(QString iKey, QJsonObject ReplyJson);//创建 ESS 任务返回
    labelMsgStruct GetMsgRecv_ESS(QString iKey);

    /***  微网优联 任务下达 以及状态返回***/
    void taskCodes_WW(QString iKey,WWYLPOST WWYLPOSTII,QString UserBadge,int pathId);
    QJsonObject posttaskCodes_WW(QString iKey,WWYLPOST WWYLPOSTII);



    /***ESS_P协议: 0查询状态  1任务查询  2出库  3移库  4回库  5任务取消***/
    QMap<QString ,ESS_Request>ESS_RequestMap;

    //机器人查询接口
    void robotCodes_query(QString iKey,ESS_Request ESS_RequestI,QString UserBadge,int pathId);
    void robotCodes_query_Get(QString iKey,ESS_Request ESS_RequestI,QString UserBadge,int pathId);
    QJsonObject postrobotCodes_query(QString iKey,ESS_Request ESS_RequestI);

    //任务查询接口
    void taskCodes_query(QString iKey,ESS_Request ESS_RequestI,QString UserBadge,int pathId);
    QJsonObject posttaskCodes_query(QString iKey,ESS_Request ESS_RequestI);

    //2出库  3移库  4回库
    void taskCodes_actionId(QString iKey,ESS_Request ESS_RequestI,QString UserBadge,int pathId);
    QJsonObject posttaskCodes_actionId(QString iKey,ESS_Request ESS_RequestI);
    QJsonObject postcontainerCode_actionId(QString iKey,ESS_Request ESS_RequestI);

    void taskCodes_actionId_Map(QString iKey,QMap<QString, ESS_Request>ESS_RequestMap,QString UserBadge,int pathId);
    QJsonObject posttaskCodes_actionId_Map(QString iKey,QMap<QString, ESS_Request>ESS_RequestMap);


    //任务取消
    void taskCodes_cancel(QString iKey,ESS_Request ESS_RequestI,QString UserBadge,int pathId);
    QJsonObject posttaskCodes_cancel(QString iKey,ESS_Request ESS_RequestI);


    //事件回调
    void taskCodes_request(QString iKey,ESS_Request ESS_RequestI,QString UserBadge,int pathId);
    QJsonObject posttaskCodes_request(QString iKey,ESS_Request ESS_RequestI);


signals:
    void ReplyWebService(QJsonObject RequestJson, QJsonObject ReplyJson,QString UserBadge,QString ActionType);
    void ReplyError(WebServiceItiem WebServiceItiemI);


private:

    QNetworkAccessManager NetworkMgr;
    QList<WebServiceItiem > WebServiceItiemList;

//  static QMutex mutex;
//  static sapMsgInterface* instance;

    QList<WebServiceItiem>WebServiceItiemMap;

    //Get SAP 数据
    void setWebService_Get(QString LabelNo,QString UrlPath,QString UserBadge,QString Type);
    //post 数据给 SAP
    void setWebService_Post(QString iKey,QString UrlPath,QJsonObject postJson,
                            QString UserBadge,QString Type,QString positionCode);

    //post 数据给 SAP
    void setWebService_Post_WS06(QString iKey,QString UrlPath,QJsonArray postJson,
                            QString UserBadge,QString Type);


    //post 数据给 SAP
    void setWebService_SAOP_Post(QString iKey,QString UrlPath,QDomDocument doc,
                            QString UserBadge,QString Type);


public:
   int currentsapPath=17;//SAP路径选择
   int WebConut=2;int allWebConut=0;

};

#endif // SAPMSGINTERFACE_H
