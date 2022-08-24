#include "tcpclient.h"

TcpClient::TcpClient(QObject *parent) : QObject(parent)
{
    ClientTimer = new QTimer(this);
    connect(ClientTimer,&QTimer::timeout,this,&TcpClient::ON_SendTimer);
    ClientTimer->start(1200);
}

TcpClient::~TcpClient()
{
    releaseTcpSocket();
    if(_tcpSocket){
        _tcpSocket->deleteLater();
    }
}

QByteArray TcpClient::getActionArray(QString taskType)
{
    QByteArray ActionArray;
    if(!deviceActionArray.isEmpty()){  //动作指令
        ActionArray=deviceActionArray.first();
        deviceActionArray.remove(ActionArray);
        qDebug()<<"send--> Action:"<<deviceActionArray.size();
        return ActionArray;
    }else{
         return deviceQueryArray;//查询指令
    }
}

void TcpClient::setTcpServer_deviceAction(QString deviceIP, QByteArray ActionArray)
{
    if(!deviceActionArray.contains(ActionArray)){
        deviceActionArray.insert(ActionArray,ActionArray);
        qDebug()<<"insert--> Action:"<<deviceIP<<" ActionArray:"<<ActionArray.toHex();
    }
}

void TcpClient::ON_SendTimer()
{
    if(_tcpSocket!=nullptr && _tcpSocket->state()==QAbstractSocket::ConnectedState){
        QByteArray ActionArray=getActionArray("client");
        if(!ActionArray.isEmpty()){
            _tcpSocket->write(ActionArray,ActionArray.size());
            _tcpSocket->flush();
            //qDebug()<<" _tcpSocket->write--->TcpServerIP:"<<TcpServerIP<<" ActionArray:"<<ActionArray.toHex();
        }
    }

    if(tcpSocketcount_Init<10){
        tcpSocketcount_Init++;
        if(tcpSocketcount_Init==3){
            tcpSocketcount_Init=100;
            qDebug()<<ClosingStatecount<<"connectHost-->初始化连接-->IP:"<<TcpServerIP<<" port:"<<Serverport;
            connectHost(TcpServerIP,Serverport);
            return;
        }
    }

    if(ClosingStatecount<3){
        if(!tcpSocket_bool && tcpSocketcount<=90){
            tcpSocketcount++;
            if(tcpSocketcount>=12){
                ClosingStatecount++;
                if(ClosingStatecount>=3){
                    emit sigclose();
                    return;
                }else{
                    tcpSocket_bool=false;
                    qDebug()<<" count:"<<ClosingStatecount<<"connectHost-->再次发起连接-->IP:"<<TcpServerIP<<" port:"<<Serverport;
                    connectHost(TcpServerIP,Serverport);
                }
            }
        }

        if(tcpSocket_bool && tcpSocketcount==100){
            ClosingStatecount=0;
            emit sigonline(1);
        }else {
            emit sigonline(0);
        }
    }

}


int TcpClient::connectHost(const QString&ip,quint16 port)
{
    int ret = 0;
    if(!_tcpSocket){
        _tcpSocket = new QTcpSocket(this);
        //禁用代理
        _tcpSocket->setProxy(QNetworkProxy::NoProxy);
        //连接槽
        connect(_tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveTcpReadyRead()));
        connect(_tcpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
                this, SLOT(stateChanged(QAbstractSocket::SocketState)));
        connect(_tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this->parent(),
                SLOT(receiveTcpError(QAbstractSocket::SocketError)));
    }
    if(_tcpSocket->isOpen() && (_tcpSocket->state()==QAbstractSocket::ConnectedState
                || _tcpSocket->state()==QAbstractSocket::ConnectingState)){
        _tcpSocket->abort();
        qDebug()<<"----close _tcpSocket----\n";
        ret = 1;
    }else{
        _tcpSocket->connectToHost(ip,port,QTcpSocket::ReadWrite,QTcpSocket::IPv4Protocol);
        _ip = ip;
        _port = port;
        ret = 0;
    }
    return ret;
}

QTcpSocket *TcpClient::tcpSocket() const
{
    return _tcpSocket;
}

void TcpClient::stateChanged(QAbstractSocket::SocketState state)
{
    QString info;
    switch (state) {
    case QAbstractSocket::UnconnectedState:
        info = "The socket is not connected";
        break;
    case QAbstractSocket::HostLookupState:
        info = "套接字正在执行主机名查找";
        break;
    case QAbstractSocket::ConnectingState:
        info = "套接字已开始建立连接";
        break;
    case QAbstractSocket::ConnectedState:
        info = "A connection is established--建立了连接";
        break;
    case QAbstractSocket::BoundState:
        info = "该套接字被绑定到一个地址和端口";
        break;
    case QAbstractSocket::ListeningState:
        info = "QAbstractSocket::ListeningState--仅供内部使用";
        break;
    case QAbstractSocket::ClosingState:
        info = "套接字即将关闭（数据可能仍在等待写入）";
        break;
    }

    if(state==QAbstractSocket::ClosingState || state==QAbstractSocket::UnconnectedState){
        tcpSocketcount=0;
        tcpSocket_bool=false;
    }if(state==QAbstractSocket::ConnectedState){
        tcpSocketcount=100;
        tcpSocket_bool=true;
    }

    qDebug() <<state<<"-->"<<info;

}

void TcpClient::releaseTcpSocket()
{
    if(_tcpSocket){
        //Aborts the current connection and resets the socket.
        //Unlike disconnectFromHost(), this function immediately closes the socket, discarding any pending data in the write buffer.
        _tcpSocket->abort();
    }
}

void TcpClient::receiveTcpReadyRead()
{
    //读取所有数据
    //返回的数据大小不定,需要使用_lastMessage成员变量存放多次触发槽读取的数据。
    QByteArray BoxByteArray = _tcpSocket->readAll();
    //qintptr descriptor=_tcpSocket->socketDescriptor();
    if(!BoxByteArray.isEmpty() && BoxByteArray.size()==18){
        //qDebug()<<"TcpClient----> TcpServerIP:"<<TcpServerIP<<" AnalysisArray:"<<BoxByteArray.toHex();
        emit sigLiftStatuschage(TcpServerIP,BoxByteArray);                     //实时更新电梯状态信息
        //TcpServerProcessing(BoxByteArray,descriptor);
    }
}

void TcpClient::TcpServerProcessing(QByteArray AnalysisArray, qintptr descriptor)
{
    QJsonArray Jsonarray;
    QJsonDocument JsonAnalyse; QJsonParseError JsonError;
    JsonAnalyse = QJsonDocument::fromJson(AnalysisArray,&JsonError);
    if(JsonError.error == QJsonParseError::NoError)
    {
        if(!(JsonAnalyse.isEmpty() || JsonAnalyse.isNull()))
        {
            QJsonObject ReJson;
            QJsonObject ReplyJson = JsonAnalyse.object();   //取得最外层这个大对象
            QJsonValue value = ReplyJson.value("ArrayType");//获取 QJsonObject 对象
            if (value.isObject()){                          //判断 ArrayType 第二级对象是否存在
                ReJson=value.toObject();
                qDebug() <<"ReJson 0-->"<<ReJson.value("taskType").toString()<<ReJson;
            }

            QString taskType= ReplyJson.value("taskType").toString();
            QJsonArray rootFruitList=ReplyJson.value("ArrayType").toArray();

//            qDebug()<<"ReplyJson "<<ReplyJson;
//            qDebug()<<"ReplyJson -->"<<ReplyJson.value("taskType").toString()<<value.isArray()<<rootFruitList.size();

            if(value.isArray() &&!rootFruitList.isEmpty() ){
                if(taskType=="UserInfo" || taskType=="sapPath" || taskType=="AGVTask"){//基础信息
                    if(taskType=="UserInfo"){
                        //transFormArray::GetInstance()->User_transFor_UserInfo(taskType,rootFruitList,value);
                    }if(taskType=="sapPath"){
                        //transFormArray::GetInstance()->Path_transFor_Array(taskType,rootFruitList,value);
                    }if(taskType=="AGVTask"){
                        //transFormArray::GetInstance()->AGVTask_transFor_Array(taskType,rootFruitList,value);
                    }
                }else{//任务类
                    //transFormArray::GetInstance()->SAP_transFor_SAPExcelInfo(taskType,rootFruitList,value);
                }
            }else{
//                qDebug()<<" JsonError.error:"<<JsonError.error<<" isArray:"<<value.isArray()
//                       <<" size:"<<rootFruitList.size();
            }
        }

    }else{
        qDebug()<<" JsonError.error:"<<JsonError.error;
    }
}

QString TcpClient::getCurrentDateTime()const
{
    return QDateTime::currentDateTime().toString("[yyyyMMdd|hh:mm:ss:zzz]:");
}



