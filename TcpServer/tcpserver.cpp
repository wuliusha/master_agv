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
                        iter_.value()->flush();
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

//    TcpServer_device TcpServer_deviceI;
//    TcpServer_deviceI.deviceIP=peerAddress.toString();                       //平板客户端 IP
//    TcpServer_deviceMap.insert(TcpServer_deviceI.deviceIP,TcpServer_deviceI);

    qDebug()<<"new Connection TcpClient]--------:"<<peerAddress.toString()<<"  size:"<<TcpSocketList.count()<<endl;

}

void TcpServer::ON_ReceiveData()
{
    TcpSocket *SocketTemp = (TcpSocket *)this->sender();
    QByteArray BoxByteArray;
    BoxByteArray = SocketTemp->readAll();
    qintptr descriptor=SocketTemp->socketDescriptor();
    //qDebug()<<" BoxByteArray:"<<BoxByteArray.toHex();
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
    QMap<QString,TcpServer_device>::iterator iter =TcpServer_deviceMap.begin();
    while (iter != TcpServer_deviceMap.end()) {
        if(iter.value().deviceIP== ClientIP && !AnalysisArray.isEmpty()){
            iter.value().AnalysisArrayMap.insert(ClientIP,AnalysisArray);
            //qDebug()<<"TcpServerProcessing----> ClientIP:"<<ClientIP<<" AnalysisArray:"<<AnalysisArray.toHex();
            //emit sigLiftStatuschage(ClientIP,AnalysisArray);                     //实时更新电梯状态信息
            emit sigDeviceStatuschage(ClientIP,AnalysisArray);      //实时更新设备状态信息

            //ReplyJson ReplyJsonI;
            //transFormArray::GetInstance()->newSAPExcelInfoTask_Process(ClientIP,AnalysisArray,ReplyJsonI);
        }
        iter++;
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

void TcpServer::setTcpServer_deviceInfo(TcpServer_device TcpServer_deviceI)
{
    if(!TcpServer_deviceMap.contains(TcpServer_deviceI.deviceIP)){
        TcpServer_deviceMap.insert(TcpServer_deviceI.deviceIP,TcpServer_deviceI);
    }
}

void TcpServer::setTcpServer_deviceAction(QString deviceIP, QByteArray ActionArray)
{
    if(TcpServer_deviceMap.contains(deviceIP)){//平板客户端链接缓存
        QMap<QString,TcpServer_device>::iterator iter =TcpServer_deviceMap.begin();
        while (iter != TcpServer_deviceMap.end()) {
            if(iter.value().deviceIP!=nullptr){
                if(iter.value().deviceIP== deviceIP && !iter.value().deviceActionArray.contains(ActionArray)){
                    iter.value().deviceActionArray.insert(ActionArray,ActionArray);
                    qDebug()<<"insert--> Action:"<<deviceIP<<" ActionArray:"<<ActionArray.toHex();
                }
            }else{
                return;
            }
            iter++;
        }
    }
}

QByteArray TcpServer::getActionArray(QString ClientIP)
{
    QByteArray ActionArray;
    if(TcpServer_deviceMap.contains(ClientIP)){//平板客户端链接缓存
        QMap<QString,TcpServer_device>::iterator iter =TcpServer_deviceMap.begin();
        while (iter != TcpServer_deviceMap.end()) {
            if(iter.value().deviceIP!=nullptr){
                if(deleteSocketList.isEmpty()){
                    if(iter.value().deviceIP== ClientIP){
                        if(!iter.value().deviceActionArray.isEmpty()){  //动作指令
                            ActionArray=iter.value().deviceActionArray.first();
                            iter.value().deviceActionArray.remove(ActionArray);
                            qDebug()<<"send--> Action:"<<ClientIP<<iter.value().deviceActionArray.size();
                            return ActionArray;
                        }else{
                             //qDebug()<<"query--> Action:"<<ClientIP<<iter.value().deviceQueryArray.toHex();
                             return iter.value().deviceQueryArray;//查询指令
                        }
                    }
                }else {
                    return  ActionArray;
                }
            }else{
                return  ActionArray;
            }
            iter++;
        }
    }
    return ActionArray;
}

//设备动作指令——————> DeviceIP：设备IP     deviceType：设备类型   orderType：动作指令   Action：动作标识
void TcpServer::ON_DeviceStatusAction(QString DeviceIP, QString deviceType, QString orderType, int Action)
{
    QByteArray actionArray=array_Single::GetInstance()->device_action(deviceType,orderType);
    if(TcpServer_deviceMap.contains(DeviceIP) && !actionArray.isEmpty()){//平板客户端链接缓存
        QMap<QString,TcpServer_device>::iterator iter =TcpServer_deviceMap.begin();
        while (iter != TcpServer_deviceMap.end()) {
            if(iter.value().deviceIP!=nullptr){
                if(iter.value().deviceIP == DeviceIP ){
                    if(!iter.value().deviceActionArray.contains(actionArray)){
                        iter.value().deviceActionArray.insert(actionArray,actionArray);
                        qDebug()<<"TcpServer---insert_--> DeviceIP:"<<DeviceIP<<" ActionArray:"<<actionArray.toHex();
                    }
                }
            }else{
                return;
            }
            iter++;
        }
    }

}


void TcpServer::ON_setConfigureArray(QString TaskType, QByteArray AnalysisArray)
{
    ConfigureArray_Info.insert(TaskType,AnalysisArray);//基础信息 缓存链表
    //qDebug()<<"ON_setConfigureArray-->"<<AnalysisArray.size();
}



