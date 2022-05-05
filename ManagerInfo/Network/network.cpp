#include "network.h"
Network* Network::instance=nullptr;
QMutex Network::mutex;

Network::Network(QObject *parent) : QObject(parent)
{
    connect(&NetworkMgr, SIGNAL(finished(QNetworkReply *)),
            SLOT(ReadResponse(QNetworkReply *)));
    
}

Network *Network::getInstance()
{
    if(instance != nullptr)
        return instance;
    else
    {
        mutex.lock();
        instance=new Network;
        mutex.unlock();
        return instance;
    }
}

void Network::ReadResponse(QNetworkReply *Reply)
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
            int HttpStatus = Reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
            qDebug()<<"http Status"<<HttpStatus<<QString(ReplyData);
            QJsonDocument JsonAnalyse; QJsonParseError JsonError;
            JsonAnalyse = QJsonDocument::fromJson(ReplyData,&JsonError);
            if(JsonError.error == QJsonParseError::NoError)
            {
                if(!(JsonAnalyse.isEmpty() || JsonAnalyse.isNull()))
                {
                    if(JsonAnalyse.isObject())
                    {
                        QJsonObject ReplyJson = JsonAnalyse.object();//取得最外层这个大对象
                        qDebug()<<"ReplyJson:";
                        qDebug()<<ReplyJson;

                        for(int i=0;i<WebServiceItiemList.length();i++){
                            if(WebServiceItiemList[i].NetworkRepItiem==Reply){
                                emit ReplyWebService(WebServiceItiemList[i].RequestJson,ReplyJson,
                                                     WebServiceItiemList[i].UserBadge,WebServiceItiemList[i].ActionType);
                            }
                        }
                    }
                }
            }
            else
            {
                qDebug() << JsonError.errorString();
            }
        }
            break;
        default:
        {
            int HttpStatus = Reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
            QString Errorinfo="error http Status= "+QString::number(HttpStatus);
            QString Errorinfo1=(QString("Network transport error (%1): %2").arg(Reply->error()).arg(Reply->errorString()));
            emit ReplyError(Errorinfo+"\n"+Errorinfo1);

            for(int i=0;i<WebServiceItiemList.length();i++){
                if(WebServiceItiemList[i].NetworkRepItiem==Reply){

                    if(WebServiceItiemList[i].NetworkRepItiem->isFinished()){
                        WebServiceItiemList[i].NetworkRepItiem->deleteLater();
                        WebServiceItiemList.removeAt(i);i--;return;
                    }
                    if(!WebServiceItiemList[i].NetworkRepItiem->isFinished()){
                        WebServiceItiemList[i].NetworkRepItiem->abort();
                        WebServiceItiemList[i].NetworkRepItiem->deleteLater();
                        WebServiceItiemList.removeAt(i);i--;return;
                    }
                }
            }
        }
            break;
    }

}

//UrlPath :地址信息   JsonGet:以json格式提交数据   UserBadge:员工工号   ActionType:动作类型
void Network::ON_WebService_get(QString UrlPath, QJsonObject JsonGet, QString UserBadge, QString ActionType)
{
    UrlPath=UrlPath+JsonGet.value("Label").toString();//label 物料号
    qDebug()<<"手动 UrlPath : "<<UrlPath<<UserBadge;
    QUrl url(UrlPath);
    QNetworkRequest NetworkRequest;
    NetworkRequest.setUrl(url);

    //ASM
    NetworkRequest.setRawHeader("User",QString("{%1}").arg(UserBadge).toLatin1());
    NetworkRequest.setRawHeader("Accept-Language","{en-US}");

    bool Replysave=false;
    QNetworkReply*  NetworkReply = NetworkMgr.get(NetworkRequest);
    for(int i=0;i<WebServiceItiemList.length();i++){
        if(WebServiceItiemList[i].ActionType==ActionType && WebServiceItiemList[i].RequestJson==JsonGet){
            Replysave=true;
            WebServiceItiemList[i].RequestJson=JsonGet;
            WebServiceItiemList[i].UserBadge=UserBadge;
            WebServiceItiemList[i].NetworkRepItiem->deleteLater();
            WebServiceItiemList[i].NetworkRepItiem=NetworkReply;
        }
    }

    if(!Replysave){
        WebServiceI WebServiceItiem0;
        WebServiceItiem0.ActionType=ActionType;//ActionType:动作类型
        WebServiceItiem0.NetworkRepItiem=NetworkReply;
        WebServiceItiem0.RequestJson=JsonGet;//请求数据
        WebServiceItiem0.UserBadge=UserBadge;//员工工号
        WebServiceItiemList.append(WebServiceItiem0);
    }

}

//UrlPath :地址信息   JsonPost:以json格式提交数据   UserBadge:员工工号   ActionType:动作类型
void Network::ON_WebService_post(QString UrlPath, QJsonObject JsonPost, QString UserBadge, QString ActionType)
{
    QUrl url(UrlPath);
    QNetworkRequest NetworkRequest;
    NetworkRequest.setUrl(url);//地址信息
//    //YI_AN
//    NetworkRequest.setRawHeader("appkey",QString("{%1}").arg("B60D488D0D8547E1B8944C2C2BEDE878").toLatin1());
//    NetworkRequest.setRawHeader("Accept-Language","{en-US}");//选中语言类型
//    NetworkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"text/json");//"text/json"  内容编码类型

    //ASM
    NetworkRequest.setRawHeader("User",QString("{%1}").arg(UserBadge).toLatin1());//
    NetworkRequest.setRawHeader("Accept-Language","{en-US}");//选中语言类型
    NetworkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"text/json");//"text/json"  内容编码类型

    bool Replysave=false;
    QNetworkReply*NetworkReply=NetworkMgr.post(NetworkRequest,QJsonDocument(JsonPost).toJson());
    for(int i=0;i<WebServiceItiemList.length();i++){
        if(WebServiceItiemList[i].ActionType==ActionType && WebServiceItiemList[i].RequestJson==JsonPost){
            Replysave=true;
            WebServiceItiemList[i].RequestJson=JsonPost;
            WebServiceItiemList[i].UserBadge=UserBadge;
            WebServiceItiemList[i].NetworkRepItiem->deleteLater();
            WebServiceItiemList[i].NetworkRepItiem=NetworkReply;
        }
    }
    if(!Replysave){
        WebServiceI WebServiceItiem0;
        WebServiceItiem0.ActionType=ActionType;//ActionType:动作类型
        WebServiceItiem0.NetworkRepItiem=NetworkReply;
        WebServiceItiem0.RequestJson=JsonPost;//请求数据
        WebServiceItiem0.UserBadge=UserBadge;//员工工号
        WebServiceItiemList.append(WebServiceItiem0);
    }
    //qDebug()<<"being posted"<<QJsonDocument(JsonPost).toJson();
}
