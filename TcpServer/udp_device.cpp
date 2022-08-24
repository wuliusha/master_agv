#include "udp_device.h"

Udp_Device::Udp_Device(QObject *parent) : QObject(parent)
{

    qRegisterMetaType<controlbox >("controlbox");
    SendTimer = new QTimer(this);
    connect(SendTimer,&QTimer::timeout,this,&Udp_Device::ON_SendTimer);
    SendTimer->start(500);
}

Udp_Device::~Udp_Device()
{

}

void Udp_Device::setListen(quint16 port)
{
    UDPSocket = new QUdpSocket(this);
    if(!UDPSocket->bind(port,QUdpSocket::ShareAddress))
    {
       qDebug()<<"绑定端口失败valeobatterySocket";
    }
    connect(UDPSocket,&QUdpSocket::readyRead,this,&Udp_Device::slotReadySocketReadDatagrams);
}

QByteArray Udp_Device::getActionArray(QString DeviceIP)
{
    QByteArray ActionArray;
    if(TcpServer_deviceMap.contains(DeviceIP)){//平板客户端链接缓存
        QMap<QString,TcpServer_device>::iterator iter =TcpServer_deviceMap.begin();
        while (iter != TcpServer_deviceMap.end()) {
            if(iter.value().deviceIP!=nullptr){
                if(iter.value().deviceIP== DeviceIP){
                    if(!iter.value().deviceActionArray.isEmpty()){  //动作指令
                        ActionArray=iter.value().deviceActionArray.first();
                        if(iter.value().Infocount<95){
                            iter.value().deviceActionArray_.remove(DeviceIP);
                        }else{
                            iter.value().Infocount--;
                        }
                        qDebug()<<"Udp_Device send--> DeviceIP:"<<DeviceIP<<" Infocount:"<<iter.value().Infocount;
                        return ActionArray;
                    }else{
                         return iter.value().deviceQueryArray;//查询指令
                    }
                }
            }else{
                return  ActionArray;
            }
            ++iter;
        }
    }
    return ActionArray;
}

void Udp_Device::ON_SendTimer()
{
    if(TcpSocketbool){
        SendTimercount++;
        TcpSocketbool=false;
        if(!SocketqueryMap.isEmpty()){
            QMap<QString,QByteArray>::const_iterator iter=SocketqueryMap.begin();
            while (iter!=SocketqueryMap.end()){
                if(iter.key()!=nullptr){
                    if(SendTimercount%2==0){
                        UDPSocket->writeDatagram(iter.value(),QHostAddress(iter.key()),9003);//查询
                    }if(SendTimercount%2==1){
                        QByteArray ActionArray=getActionArray(iter.key());
                        if(!ActionArray.isEmpty()){
                            UDPSocket->writeDatagram(ActionArray,QHostAddress(iter.key()),9003);
                        }
                    }
                }else{
                    return;
                }
                ++iter;
            }
        }
        if(SendTimercount>10000){SendTimercount=0;}
        TcpSocketbool=true;
    }
}

void Udp_Device::slotReadySocketReadDatagrams()
{
    while(UDPSocket->hasPendingDatagrams()){
        QByteArray BoxByteArray;
        QHostAddress recvIp;
        BoxByteArray.resize(UDPSocket->pendingDatagramSize());
        UDPSocket->readDatagram(BoxByteArray.data(),BoxByteArray.size(),&recvIp);
        recvIp = QHostAddress(recvIp.toIPv4Address());
        QString  DeviceIP =recvIp.toString();
        if(!BoxByteArray.isEmpty() && DeviceIP!=""){
            TcpServerProcessing(BoxByteArray,DeviceIP);
        }
    }
}

void Udp_Device::TcpServerProcessing(QByteArray AnalysisArray, QString DeviceIP)
{
    if(AnalysisArray.size()==19 && DeviceIP!=""){
        if(quint16(AnalysisArray.at(7)&0x1) == 0x01){   //动作指令返回
            emit sigDeviceStatuschage(DeviceIP,AnalysisArray);
        }if(quint16(AnalysisArray.at(7)&0x10) == 0x10){ //状态指令返回
            emit sigDeviceStatuschage(DeviceIP,AnalysisArray);
        }
    }
}


void Udp_Device::setDeviceInit(QString DeviceIP,QByteArray queryArray)
{
    //指令类型 orderType--> query查询   action动作  动作指令 Action-->1开  2关
    if(DeviceIP!=""){
        TcpServer_device TcpServer_deviceI;
        TcpServer_deviceI.deviceIP=DeviceIP;
        TcpServer_deviceI.deviceQueryArray=queryArray;
        if(!SocketqueryMap.contains(DeviceIP)){
            SocketqueryMap.insert(DeviceIP,TcpServer_deviceI.deviceQueryArray);
            TcpServer_deviceMap.insert(DeviceIP,TcpServer_deviceI);
            //qDebug()<<"自动门初始化:"<<DeviceIP<<deviceType;
        }
    }
}


void Udp_Device::ON_DeviceStatusAction(QString DeviceIP,QString deviceType, QString orderType, int Action)
{
    QByteArray actionArray=array_Single::GetInstance()->device_action(deviceType,orderType);
    if(TcpServer_deviceMap.contains(DeviceIP) && !actionArray.isEmpty()){//平板客户端链接缓存
        QMap<QString,TcpServer_device>::iterator iter =TcpServer_deviceMap.begin();
        while (iter != TcpServer_deviceMap.end()) {
            if(iter.value().deviceIP!=nullptr){
                if(iter.value().deviceIP== DeviceIP ){
                    iter.value().Infocount=100;
                    iter.value().deviceActionArray_.insert(DeviceIP,actionArray);
                    qDebug()<<"Udp_Device---insert_--> DeviceIP:"<<DeviceIP<<" ActionArray:"<<actionArray.toHex();
                }
            }else{
                return;
            }
            ++iter;
        }
    }
}


