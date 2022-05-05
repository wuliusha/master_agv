#include "agvserver.h"

AGVServer::AGVServer()
{
    SendTimer = new QTimer(this);
    connect(SendTimer,&QTimer::timeout,this,&AGVServer::ON_DeviceTimer);
    SendTimer->start(1000);
}

AGVServer::~AGVServer()
{

}

bool AGVServer::SetClientSend(QString DeviceIP, QByteArray SendArray)
{
    for(int i=0;i<ClientSendList.length();i++){
        if(ClientSendList[i].ClientIP==DeviceIP){
            ClientSendList[i].SendArrayList.append(SendArray);
            return true;
        }
    }
    ClientSend ClientSendItiem;
    ClientSendItiem.ClientIP=DeviceIP;
    ClientSendItiem.SendArrayList.append(SendArray);
    return false;
}

void AGVServer::ON_DeviceTimer()
{
    for(int i=0;i<ClientSendList.length();i++){
        if(ClientSendList[i].SendArrayList.isEmpty()){}
        if(!ClientSendList[i].SendArrayList.isEmpty()){//
            bool Sendok=SetWrite(ClientSendList[i].ClientIP, ClientSendList[i].SendArrayList[0]);
            if(Sendok){
                ClientSendList[i].SendArrayList.removeAt(0);
            }
        }
    }
}

void AGVServer::incomingConnection(int socketDescriptor)
{
    ClientSocket ClientSocketItiem;
    ClientSocketItiem._tcpSocket = new QTcpSocket();
    ClientSocketItiem._tcpSocket->setSocketDescriptor(socketDescriptor);
    connect(ClientSocketItiem._tcpSocket,SIGNAL(readyRead()),this,SLOT(ReceiveData()));
    connect(ClientSocketItiem._tcpSocket,SIGNAL(disconnected()),this,SLOT(_Disconnected()));

    ClientSocketItiem.ClientIP=ClientSocketItiem._tcpSocket->peerAddress().toString().mid(7,ClientSocketItiem._tcpSocket->peerAddress().toString().size());
    ClientSocketList.append(ClientSocketItiem);//客户端连接链表
    qDebug()<<ClientSocketItiem.ClientIP<<"[TcpServer]------------------new Connection !!! The Num:"<< ClientSocketList.count()<<"socketDescriptor "<<socketDescriptor<<endl;

}

bool AGVServer::SetWrite(QString DeviceIP, QByteArray SendArray)
{
    for(int i = 0; i < ClientSocketList.count(); i++){
        if(ClientSocketList[i].ClientIP==DeviceIP){
            if(ClientSocketList[i]._tcpSocket->state() == QTcpSocket::ConnectedState)
            {
                ClientSocketList[i]._tcpSocket->write(SendArray);
                ClientSocketList[i]._tcpSocket->flush();
                return true;
            }
        }
    }
    return false;
}

void AGVServer::ReceiveData()
{
    TcpSocket *SocketTemp = (TcpSocket *)this->sender();
    QByteArray ReceiveArray;
    ReceiveArray = SocketTemp->readAll();
    int descriptor=SocketTemp->socketDescriptor();
    for(int i = 0; i < ClientSocketList.count(); i++){
        int _descriptor= ClientSocketList[i]._tcpSocket->socketDescriptor();
        if(_descriptor == descriptor){
            emit ReDeviceArray(ClientSocketList[i].ClientIP,ReceiveArray);
        }
    }
}

void AGVServer::_Disconnected()
{
    TcpSocket *SocketTemp = (TcpSocket *)this->sender();
    int descriptor=SocketTemp->socketDescriptor();
    for(int i = 0; i < ClientSocketList.count(); i++){
        int  _descriptor= ClientSocketList[i]._tcpSocket->socketDescriptor();
        if(-1 == _descriptor || _descriptor == descriptor)//测试中发现，当disconnected()信号发出，item->socketDescriptor()返回值已经为-1了，不能通过item->socketDescriptor() == descriptor来进行判断了。。。所以删除返回值为-1的QTcpSocket对象
        {
            ClientSocketList[i]._tcpSocket->deleteLater();
            ClientSocketList.removeAt(i);i--;//如果有客户端断开连接， 就将列表中的套接字删除
            qDebug()<< "[TcpSocket]-------------------------------Disconnect:" <<descriptor<< endl;
            return;
        }
    }
    return;
}

QByteArray AGVServer::JsonToArray(AgvState agvState0)//把AGV 状态信息 转化为 QByteArray
{
     QJsonObject Json_Object;
//     Json_Object.insert("Json","AgvState");
//     Json_Object.insert("AGVIP",agvState0.AGVIP);      //AGVIP
//     Json_Object.insert("FinishInit",agvState0.FinishInit); //AGV已完成初始化
//     Json_Object.insert("agvFinishInitcount",QString::number(agvState0.agvFinishInitcount)); //AGV已完成初始化 延时计数
//     Json_Object.insert("QRCodeState",agvState0.QRCodeState);//AGV运行任务状态
//     Json_Object.insert("moveTaskState",agvState0.moveTaskState);//AGV在二维码上标志 "0"=false --- "1"=true
//     Json_Object.insert("RotaryLowState",agvState0.RotaryLowState);//AGV转盘下限位感应 "0"=false --- "1"=true
//     Json_Object.insert("RotaryHighState",agvState0.RotaryHighState);//AGV转盘上限位感应 "0"=false --- "1"=true
//     Json_Object.insert("RotaryOriginState",agvState0.RotaryOriginState);//AGV转盘原点检测状态 "0"=false --- "1"=true
//     Json_Object.insert("CurrentQRCode",agvState0.CurrentQRCode);//AGV上次读到的二维码点
//     Json_Object.insert("X_OffsetState",agvState0.X_OffsetState); //AGV当前点X偏移
//     Json_Object.insert("Y_OffsetState",agvState0.Y_OffsetState); //AGV当前点Y偏移
//     Json_Object.insert("AttitudeAngleState",agvState0.AttitudeAngleState); //AGV当前姿态角度
//     Json_Object.insert("RotaryAngleState",agvState0.RotaryAngleState);//AGV当前转盘角度
//     Json_Object.insert("MoveAngleState",agvState0.MoveAngleState); //AGV当前移动角度
//     Json_Object.insert("CurrentTaskNumberState",agvState0.CurrentTaskNumberState);//AGV当前执行任务编号
//     Json_Object.insert("RemainTaskCountState",agvState0.RemainTaskCountState); //AGV当前剩余任务数
//     Json_Object.insert("RotaryHeightState",agvState0.RotaryHeightState);//AGV当前转盘高度
//     Json_Object.insert("LeftWheelSpeedState",agvState0.LeftWheelSpeedState);//AGV当前左轮速度/AGV当前前轮速度(mm/s)
//     Json_Object.insert("RightWheelSpeedState",agvState0.RightWheelSpeedState); //AGV当前右轮速度/AGV当前后轮速度(mm/s)
//     Json_Object.insert("RotaryLiftSpeedState",agvState0.RotaryLiftSpeedState);//AGV当前转盘举升速度(mm/s)
//     Json_Object.insert("RotaryRotateSpeedState",agvState0.RotaryRotateSpeedState);//AGV当前转盘旋转速度(度/s)
//     Json_Object.insert("VoltageState",agvState0.VoltageState);//AGV当前电池电压值(mV)
//     Json_Object.insert("SystemCurrentState",agvState0.SystemCurrentState); //AGV当前系统电流值(mA)
//     Json_Object.insert("ErrorCodeState",agvState0.ErrorCodeState);//AGV当前错误代码
//     Json_Object.insert("WarningCodeState",agvState0.WarningCodeState);//AGV当前警告代码
//     Json_Object.insert("StorageNumberState",agvState0.StorageNumberState);//AGV当前举升货架编号
//     Json_Object.insert("CompletedTaskNumberState",agvState0.CompletedTaskNumberState);//AGV当前完成的任务编号
//     Json_Object.insert("ErrorMessagesState",agvState0.ErrorMessagesState);//AGV所有错误信息
//     Json_Object.insert("WarningMessagesState",agvState0.WarningMessagesState); //AGV所有警告信息
//     Json_Object.insert("ChargingCircuit",agvState0.ChargingCircuit);//AGV充电回路状态  "0"=false --- "1"=true


     QByteArray agvState_array = QJsonDocument(Json_Object).toJson();
     return agvState_array;

}


