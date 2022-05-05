
#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#define HTTPSERVER_VERSION_MAJOR 0
#define HTTPSERVER_VERSION_MINOR 1
#define HTTPSERVER_VERSION_PATCH 0

#include <QObject>
#include <QHostAddress>
#include <QObject>
#include<QNetworkReply>
#include<QNetworkRequest>
#include<QJsonObject>
#include<QJsonArray>
#include<QUrl>
#include<QJsonDocument>
#include<QMap>
#include <QMutex>
#include<QtCore/QCoreApplication>

#include "httprequest.h"
#include "httpresponse.h"
#include "httpconnection.h"

#include "taskmanager/ess_single.h"
#include "queryServer/queryserver.h"
#include "singleProject/single_project.h"

class QTcpServer;
class HttpRequest;
class HttpResponse;


//请求和响应头的表
typedef QHash<QString, QString> HeaderHash;

//状态代码
extern QHash<int, QString> STATUS_CODES;


class HttpServer : public QObject
{
	Q_OBJECT
public:
	HttpServer(QObject *parent = 0);
	virtual ~HttpServer();
//    QTimer *StTimer;int stTimercount=0;
    CurrentSend CurrentSendI;
    ServerInit ServerInitItem;      //基础信息

	bool listen(const QHostAddress &address = QHostAddress::Any, quint16 port=0);
	bool listen(quint16 port);


signals:
	//void newRequest(QHttpRequest *request, QHttpResponse *response);
    void sig_SAPExcelInfo_new(SAPExcelInfo SAPExcelInfoI);


private slots:
    void newConnection();
    void ON_newReplyData_task(QString ClientIP,ReplyJson ReplyJsonI,QJsonObject ReplyJson);


    void onRequest(HttpRequest*, HttpResponse*);

    void ON_HttpServerTimer();

private:
	QTcpServer *m_tcpServer;

    //MES 创建订单任务
    ReplyJson analysReplyJson_new(QJsonObject ReplyJson_,ReplyJson ReplyJsonI);

    //MES 任务状态反馈
    ReplyJson analysReplyJson_taskStatus(QJsonObject ReplyJson_,ReplyJson ReplyJsonI);

    //创建 AGV 任务
    ReplyJson analysReplyJson_agvnew(QJsonObject ReplyJson_,ReplyJson ReplyJsonI);

    //AGV任务状态反馈
    ReplyJson analysReplyJson_agvStatus(QJsonObject ReplyJson_,ReplyJson ReplyJsonI);



    ReplyJson currentReplyJsonI;
    QJsonObject _ReplyJson(QString action,ReplyJson ReplyJsonI);//http 接口数据解析返回

    QMap<int,QString>errorMsgMap;
    ReplyJson checkTaskRepeat(SAPExcelInfo SAPExcelInfoI,ReplyJson ReplyJsonI);      //判断当前任务是否重复下达 或者有未完成的任务


};

#endif
