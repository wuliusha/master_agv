#include "barcodepool.h"


barcodePool::barcodePool()
{
     SendTimer = new QTimer(this);
     connect(SendTimer,&QTimer::timeout,this,&barcodePool::ON_SendTimer);
     SendTimer->start(1000);

     DeviceInit("192.168.151.211");//设备初始化
     DeviceInit("192.168.151.212");
     DeviceInit("192.168.151.215");
     DeviceInit("192.168.151.216");

}

barcodePool::~barcodePool()
{

}

void barcodePool::ON_SendTimer()
{
    for(int i = 0; i < TcpSocketList.count(); i++){
        QTcpSocket *item = TcpSocketList.at(i);
        if(item->isOpen() && (item->state()==QAbstractSocket::ConnectedState)){
            QByteArray ByteArray=Get_CurrentArray(item->peerAddress().toString());//获取当前设备  当前发送数据
            if(!ByteArray.isEmpty()){
                item->write(ByteArray);
                item->flush();
                //qDebug()<<item->peerAddress().toString()<<ByteArray<<"barcodePool 32";
            }
        }
    }
}

void barcodePool::DeviceInit(QString DeviceIP)
{
    DeviceArray DeviceArray1;
    DeviceArray1.DeviceIP=DeviceIP;
    DeviceArray1.Query_ByteArray=Box_ByteArrayInit();
    DeviceArrayList.append(DeviceArray1);//当前需要发送
}

//获取新的Socket连接
void barcodePool::incomingConnection(qintptr Descriptor)
{
    QTcpSocket *tcpsocket = new QTcpSocket();
    tcpsocket->setSocketDescriptor(Descriptor);

    connect(tcpsocket,SIGNAL(readyRead()),this,SLOT(ReceiveData_slot()));
    connect(tcpsocket,SIGNAL(disconnected()),this,SLOT(ClientDisconnected_slot()));

    TcpSocketList.append(tcpsocket);
    qDebug()<<tcpsocket->peerAddress().toString()<<"[TcpServer]------------------new Connection !!! The Num:"<< TcpSocketList.count()<<endl;

}

void barcodePool::Scoket_Data_Processing(QByteArray AnalysisArray, int descriptor)
{
    for(int i = 0; i < TcpSocketList.count(); i++){
        QTcpSocket *item = TcpSocketList.at(i);
        if(item->socketDescriptor() == descriptor)//通过descriptor在QList中查找对应的QTcpSocket对象
        {
            foreach (DeviceArray DeviceArray1, DeviceArrayList){
                if(DeviceArray1.DeviceIP==item->peerAddress().toString().mid(7,item->peerAddress().toString().size())){
                    if(quint8(AnalysisArray.at(0)) == 0xFC  && AnalysisArray.size()!=11){
                        emit controlBox(DeviceArray1.DeviceIP,AnalysisArray);//货位光电感应状态
//                        qDebug()<<"From ---> "<< item->peerAddress().toString() <<":"<<item->peerPort();
                        return;
                    }
                    if((quint8)AnalysisArray.at(0) == 0xFC && AnalysisArray.size()==11){
                        emit AGVChargeStatus(DeviceArray1.DeviceIP,AnalysisArray);//实时更新 充电桩 状态
                        //qDebug()<<"//实时更新 充电桩 状态";
                    }
                   // qDebug()<<item->peerAddress().toString()<<AnalysisArray<<"barcodePool 77  size= "<<AnalysisArray.size();
                    return;
                }
            }
            QByteArray SendArray =Get_JsonByteArray(AnalysisArray);//返回扫码枪数据
            if(!SendArray.isEmpty()){
                item->write(SendArray);
                item->flush();
            }
        }
    }
}


QByteArray barcodePool::Box_ByteArrayInit()
{
    QByteArray cmdData1;
    cmdData1.append(0xFC);
    cmdData1.append(0x0b);
    QByteArray zero0;
    zero0.fill(0x00,4);
    cmdData1.append(zero0);

    cmdData1.append(0x02);
    QByteArray zero;
    zero.fill(0x00,3);
    cmdData1.append(zero);
    cmdData1.append(0x5a);
    return cmdData1;
}

QByteArray barcodePool::Get_CurrentArray(QString DeviceIP)
{
    QByteArray ByteArray;ByteArray.clear();
    for(int i=0;i<DeviceArrayList.length();i++){
        if(DeviceArrayList[i].DeviceIP==DeviceIP.mid(7,DeviceIP.size())){
            if(!DeviceArrayList[i].Send_ByteArrayList.isEmpty()){
                ByteArray=DeviceArrayList[i].Send_ByteArrayList.first();
                DeviceArrayList[i].Send_ByteArrayList.removeFirst();
            }
        }
    }
    foreach (DeviceArray DeviceArray1, DeviceArrayList) {
        if(DeviceArray1.DeviceIP==DeviceIP.mid(7,DeviceIP.size()) && ByteArray.isEmpty()){
            ByteArray=DeviceArray1.Query_ByteArray;
        }
    }
    return ByteArray;
}

QByteArray barcodePool::Get_JsonByteArray(QByteArray AnalysisArray)
{
    QJsonObject json_object2 = QJsonDocument::fromJson(AnalysisArray).object();
    QString json_yi_an=json_object2.value("json").toString();
    QString StartCP=json_object2.value("Cage_Number").toString();
    QString DeviceId=json_object2.value("DeviceId").toString();
    QString Success=json_object2.value("Success").toString();
    if(Success=="0"){Success="1";}

    QJsonObject json_object;
    json_object.insert("json",json_yi_an);//json  的标识符
    json_object.insert("Cage_Number",StartCP);//工位号
    json_object.insert("DeviceId",DeviceId);//工位号
    json_object.insert("Success",Success);

    // qDebug()<<json_yi_an<<StartCP<<DeviceId<<Success;
    emit barcodeTask(StartCP.mid(0,5),StartCP,"DP-BB","","CageID","TrackingGIGR",DeviceId);

    QByteArray udpbyte_array = QJsonDocument(json_object).toJson();
    return udpbyte_array;
}


void barcodePool::Socket_Disconnected(int descriptor)
{
    for(int i = 0; i < TcpSocketList.count(); i++){
        QTcpSocket *item = TcpSocketList.at(i);
        int temp = item->socketDescriptor();
        if(-1 == temp || temp == descriptor)//测试中发现，当disconnected()信号发出，item->socketDescriptor()返回值已经为-1了，不能通过item->socketDescriptor() == descriptor来进行判断了。。。所以删除返回值为-1的QTcpSocket对象
        {
            TcpSocketList.removeAt(i);//如果有客户端断开连接， 就将列表中的套接字删除
            item->deleteLater();
            qDebug()<< "[TcpSocket]-------------------------------Disconnect:" << descriptor << endl;
            return;
        }
    }
    return;
}

void barcodePool::ReceiveData_slot()
{
    TcpSocket *SocketTemp = (TcpSocket *)this->sender();
    QByteArray BoxByteArray;
    BoxByteArray = SocketTemp->readAll();
    int descriptor=SocketTemp->socketDescriptor();

    if(!BoxByteArray.isEmpty()){
        Scoket_Data_Processing(BoxByteArray,descriptor);
    }
}

void barcodePool::ClientDisconnected_slot()
{
    TcpSocket *SocketTemp = (TcpSocket *)this->sender();
    int descriptor=SocketTemp->socketDescriptor();
    Socket_Disconnected(descriptor);
}

void barcodePool::ON_ChargeIP_TCP(QString ChargeIP, QByteArray Query_ByteArray)
{
    for(int i=0;i<DeviceArrayList.length();i++){
        if(DeviceArrayList[i].DeviceIP==ChargeIP){
            qDebug()<<ChargeIP<<Query_ByteArray<<"barcodePool";
            DeviceArrayList[i].Send_ByteArrayList.append(Query_ByteArray);
        }
    }
}
