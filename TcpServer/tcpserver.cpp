#include "tcpserver.h"

TcpServer::TcpServer()
{
    SendTimer = new QTimer(this);
    connect(SendTimer,&QTimer::timeout,this,&TcpServer::ON_SendTimer);
    SendTimer->start(600);

}

TcpServer::~TcpServer()
{

}

void TcpServer::ON_SendTimer()
{

    if(TcpSocketbool && !TcpSocketList.isEmpty()){
        TcpSocketbool=false;
        QMap<QString,QTcpSocket*>::const_iterator iter_ =TcpSocketList.begin();
        while (iter_ != TcpSocketList.end()) {
            if(iter_==TcpSocketList.end() || iter_==nullptr){
                return ;
            }
            if(deleteSocketList.isEmpty()){
                if(iter_.value()->state()==QAbstractSocket::ConnectedState){
                    QByteArray ActionArray=getActionArray(iter_.key());
                    if(!ActionArray.isEmpty()){
                        iter_.value()->write(ActionArray,ActionArray.size());
                        //iter_.value()->flush();
                    }
                }
            }else{
                if(TcpSocketList.contains(deleteSocketList.first())){
                    TcpSocketList.remove(deleteSocketList.first());
                    deleteSocketList.removeFirst();
                    TcpSocketbool=true;
                    return;
                }
                return;
            }
            iter_++;
        }
        TcpSocketbool=true;
    }
}

void TcpServer::incomingConnection(qintptr Descriptor)
{
    QTcpSocket *tcpsocket = new QTcpSocket();
    tcpsocket->setSocketDescriptor(Descriptor);

    connect(tcpsocket,SIGNAL(readyRead()),this,SLOT(ON_ReceiveData()));
    //connect(tcpsocket,SIGNAL(disconnected()),this,SLOT(ON_ClientDisconnected()));

    QHostAddress peerAddress(tcpsocket->peerAddress().toIPv4Address());
    TcpSocketList.insert(peerAddress.toString(),tcpsocket);

//    deviceServer deviceServerI;
//    deviceServerI.deviceIP=peerAddress.toString();                       //平板客户端 IP
//    deviceServerMap.insert(deviceServerI.deviceIP,deviceServerI);

    qDebug()<<"new Connection TcpClient]--------:"<<peerAddress.toString()<<"  size:"<<TcpSocketList.count()<<endl;

}

void TcpServer::ON_ReceiveData()
{
    TcpSocket *SocketTemp = (TcpSocket *)this->sender();
    QByteArray BoxByteArray;
    BoxByteArray = SocketTemp->readAll();
    qintptr descriptor=SocketTemp->socketDescriptor();
    if(SocketTemp != nullptr){
        QHostAddress peerAddress(SocketTemp->peerAddress().toIPv4Address());
        QString ClientIP=peerAddress.toString();
        if(TcpSocketList.contains(ClientIP)){
            if(!BoxByteArray.isEmpty() && TcpSocketbool){
                TcpSocketbool=false;
                TcpServerProcessing(ClientIP,BoxByteArray,descriptor);
                TcpSocketbool=true;
            }
        }
    }

}

void TcpServer::TcpServerProcessing(QString ClientIP,QByteArray AnalysisArray, qintptr descriptor)
{
    QMap<QString,deviceServer>::iterator iter =deviceServerMap.begin();
    while (iter != deviceServerMap.end()) {
        if(iter.value().deviceIP== ClientIP && !AnalysisArray.isEmpty()
                && AnalysisArray.size()==19){
            //iter.value().AnalysisArrayMap.insert(ClientIP,AnalysisArray);
            //qDebug()<<"TcpServerProcessing----> ClientIP:"<<ClientIP<<" AnalysisArray:"<<AnalysisArray.toHex();
            emit sigDeviceStatuschage(ClientIP,AnalysisArray);      //实时更新设备状态信息
        }
        ++iter;
    }

}

void TcpServer::ON_ClientDisconnected()
{
    TcpSocket *SocketTemp = (TcpSocket *)this->sender();
    qintptr descriptor=SocketTemp->socketDescriptor();
    if(SocketTemp != nullptr){
        QHostAddress peerAddress(SocketTemp->peerAddress().toIPv4Address());
        QString ClientIP=peerAddress.toString();
        if(TcpSocketList.contains(ClientIP)){
            deleteSocketList.append(ClientIP);
            qDebug()<< "[TcpSocket]-------------------------TcpClient------Disconnect:" <<ClientIP<< descriptor << endl;
            SocketTemp->deleteLater();
        }
    }
}

void TcpServer::setdeviceServerInfo(deviceServer deviceServerI)
{
    if(!deviceServerMap.contains(deviceServerI.deviceIP)){
        deviceServerMap.insert(deviceServerI.deviceIP,deviceServerI);
    }
}

void TcpServer::setdeviceServerAction(QString deviceIP, QByteArray ActionArray)
{
    if(deviceServerMap.contains(deviceIP)){
        QMap<QString,deviceServer>::iterator iter =deviceServerMap.begin();
        while (iter != deviceServerMap.end()) {
            if(iter.value().deviceIP!=nullptr){
                if(iter.value().deviceIP== deviceIP && !iter.value().deviceActionArray.contains(ActionArray)){
                    iter.value().deviceActionArray.insert(ActionArray,ActionArray);
                    qDebug()<<"insert--> Action:"<<deviceIP<<" ActionArray:"<<ActionArray.toHex();
                }
            }else{
                return;
            }
            ++iter;
        }
    }
}

QByteArray TcpServer::getActionArray(QString ClientIP)
{
    QByteArray ActionArray;
    if(deviceServerMap.contains(ClientIP)){//平板客户端链接缓存
        QMap<QString,deviceServer>::iterator iter =deviceServerMap.begin();
        while (iter != deviceServerMap.end()) {
            if(iter.value().deviceIP!=nullptr){
                if(deleteSocketList.isEmpty()){
                    if(iter.value().deviceIP== ClientIP){
                        if(!iter.value().deviceActionArray.isEmpty()){  //动作指令
                            ActionArray=iter.value().deviceActionArray.first();
                            iter.value().deviceActionArray.remove(ActionArray);
                            qDebug()<<"send--> Action:"<<ClientIP<<iter.value().deviceActionArray.size();
                            return ActionArray;
                        }else{
                             //qDebug()<<"query--> Action:"<<ClientIP<<iter.value().queryArray.toHex();
                             return iter.value().queryArray;//查询指令
                        }
                    }
                }else {
                    return  ActionArray;
                }
            }else{
                return  ActionArray;
            }
            ++iter;
        }
    }
    return ActionArray;
}







