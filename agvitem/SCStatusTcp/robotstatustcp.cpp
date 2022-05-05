#include "robotstatustcp.h"
#include <QNetworkProxy>

RobotStatusTcp::RobotStatusTcp(QObject *parent) : QObject(parent)
{

}
RobotStatusTcp::~RobotStatusTcp()
{
    releaseTcpSocket();
    if(_tcpSocket){
        _tcpSocket->deleteLater();
    }
}

void RobotStatusTcp::releaseTcpSocket()
{
    if(_tcpSocket){
        //Aborts the current connection and resets the socket.
        //Unlike disconnectFromHost(), this function immediately closes the socket, discarding any pending data in the write buffer.
        _tcpSocket->abort();
    }
}

int RobotStatusTcp::connectHost(const QString&ip,quint16 port)
{
    int ret = 0;
    if(!_tcpSocket){
        _tcpSocket = new QTcpSocket(this);
        //禁用代理
        _tcpSocket->setProxy(QNetworkProxy::NoProxy);
        //连接槽
        connect(_tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveTcpReadyRead()));
        connect(_tcpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
                this->parent(), SLOT(stateChanged(QAbstractSocket::SocketState)));
        connect(_tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this->parent(),
                SLOT(receiveTcpError(QAbstractSocket::SocketError)));
    }
    if(_tcpSocket->isOpen()
            && (_tcpSocket->state()==QAbstractSocket::ConnectedState
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
//sendCommand - 报文类型  sendData - 数据区数据  number - 序号
bool RobotStatusTcp::writeTcpData(uint16_t sendCommand,const QByteArray &sendData,uint16_t &number)

{
    //数据区长度
    int size = 0;
    //报文头部数据
    uint8_t* headBuf = Q_NULLPTR;
    int headSize = 0;
    //发送的全部数据
    SeerData* seerData = Q_NULLPTR;
    if (sendData.isEmpty()){
        headBuf=new uint8_t(headSize);
        headSize = sizeof(SeerHeader);
        headBuf = new uint8_t[headSize];
        seerData = (SeerData*)headBuf;
        size = seerData->setData(sendCommand, Q_NULLPTR, 0, number);
    }else{
        std::string json_str = sendData.toStdString();
        headSize = sizeof(SeerHeader) + json_str.length();
        headBuf = new uint8_t[headSize];
        seerData = (SeerData*)headBuf;
        size = seerData->setData(sendCommand, (uint8_t*)json_str.data(), json_str.length(), number);
    }
    //---------------------------------------
    //发送的所有数据
    QByteArray tempA = QByteArray::fromRawData((char*)seerData, size);
    if(_tcpSocket->state() == QTcpSocket::ConnectedState)
    {
        _tcpSocket->write((char*)seerData, size);
        delete[] headBuf;
        emit returnwriteTcpData(tempA);//返回显示
 //       qDebug()<<sendCommand<<sendData<<number<<" 发送数据 110";
        return true;
    }
    qDebug()<<seerData<<number<<" 发送数据失败"<<tempA.toHex();
    emit returnwriteTcpData(tempA);//返回显示
    return false;
}
//receiveheadB
void RobotStatusTcp::receiveTcpReadyRead()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    QByteArray RecvData = socket->readAll();
    RecvData= Recv_AllData+RecvData;//防止分段包丢失
    QHostAddress peerAddress(socket->peerAddress().toIPv4Address());//IP
    quint16 peerPort=socket->peerPort();//端口

    while(RecvData.size() > 0){
        char a0 = RecvData.at(0);
        if (uint8_t(a0) == 0x5A && peerPort==19204){//检测第一位是否为0x5A
            if (RecvData.size() >= 16) {//返回的数据最小长度为16位,如果大小小于16则数据不完整等待再次读取
                SeerHeader* header = new SeerHeader;
                memcpy(header, RecvData.data(), 16);

                uint32_t data_size;//返回所有数据总长值
                uint16_t revCommand;
                uint16_t number;//返回序号
                qToBigEndian(header->m_length,(uint8_t*)&(data_size));
                qToBigEndian(header->m_type, (uint8_t*)&(revCommand));
                qToBigEndian(header->m_number, (uint8_t*)&(number));
                delete header;
                int remaining_size = RecvData.size() - 16;//所有数据总长度 - 头部总长度16 = 数据区长度
                //如果返回数据长度值 大于 已读取数据长度 表示数据还未读取完整，跳出循环等待再次读取.
                if (data_size > remaining_size) {
                    Recv_AllData = RecvData;
                    break;
                }else{//返回数据长度值 大于等于 已读取数据，开始解析
                    QByteArray headB = RecvData.left(16);
                    //截取报头16位后面的数据区数据
                    QByteArray json_data = RecvData.mid(16, RecvData.size());
                    QJsonObject json_object = QJsonDocument::fromJson(json_data).object();

                    RoboshopStateItem.isOnline=true;
                    RoboshopStateItem.controller_temp=json_object.value("controller_temp").toDouble();//控制器温度, 单位 ℃
                    RoboshopStateItem.controller_humi=json_object.value("controller_humi").toDouble();//控制器湿度, 单位 %
                    RoboshopStateItem.controller_voltage=json_object.value("controller_voltage").toDouble();//控制器电压, 单位 V
                    RoboshopStateItem.x=json_object.value("x").toDouble();              //	机器人的 x 坐标, 单位 m
                    RoboshopStateItem.y=json_object.value("y").toDouble();//机器人的 y 坐标, 单位 m
                    RoboshopStateItem.angle=json_object.value("angle").toDouble();//机器人的 angle 坐标, 单位 rad
                    RoboshopStateItem.confidence=json_object.value("confidence").toDouble();//机器人的定位置信度, 范围 [0, 1]

                    RoboshopStateItem.current_station=json_object.value("current_station").toString();//机器人当前所在站点的 ID（该判断比较严格，机器人必须很靠近某一个站点(<50cm)，否则为空字符，即不处于任何站点）
                    RoboshopStateItem.last_station=json_object.value("last_station").toString();//机器人上一个所在站点的 ID
                    RoboshopStateItem.vx=json_object.value("vx").toDouble();//机器人在机器人坐标系的 x 方向速度, 单位 m/s
                    RoboshopStateItem.vy=json_object.value("vy").toDouble();//机器人在机器人坐标系的 y 方向速度, 单位 m/s
                    RoboshopStateItem.blocked=json_object.value("blocked").toBool();//机器人是否被阻挡
                    RoboshopStateItem.block_reason=json_object.value("block_reason").toDouble();//******
                    RoboshopStateItem.block_x=json_object.value("block_x").toDouble();//最近障碍物位置的 x 坐标, 单位 m
                    RoboshopStateItem.block_y=json_object.value("block_y").toDouble();//最近障碍物位置的 y 坐标, 单位 m

                    RoboshopStateItem.slowed=json_object.value("slowed").toBool();//机器人是否减速
                    RoboshopStateItem.slow_reason=json_object.value("slow_reason").toDouble();//********
                    RoboshopStateItem.slow_x=json_object.value("slow_x").toDouble();//最近的导致减速的障碍物位置的 x 坐标, 单位 m
                    RoboshopStateItem.slow_y=json_object.value("slow_y").toDouble();//最近的导致减速的障碍物位置的 y 坐标, 单位 m

                    RoboshopStateItem.charging=json_object.value("charging").toBool();//电池是否正在充电
                    RoboshopStateItem.voltage=json_object.value("voltage").toDouble();//电压, 单位 V
                    RoboshopStateItem.current=json_object.value("current").toDouble();//电流, 单位 A
                    RoboshopStateItem.emergency=json_object.value("emergency").toBool();//true 表示急停按钮处于激活状态(按下), false 表示急停按钮处于非激活状态(拔起)
                    RoboshopStateItem.driver_emc=json_object.value("driver_emc").toBool();//true 表示驱动器发生急停, false 驱动器发生未急停

                    RoboshopStateItem.task_status=json_object.value("task_status").toDouble(); //0 = NONE, 1 = WAITING, 2 = RUNNING, 3 = SUSPENDED, 4 = COMPLETED, 5 = FAILED, 6 = CANCELED
                    RoboshopStateItem.task_type=json_object.value("task_type").toDouble();//导航类型, 0 = 没有导航, 1 = 自由导航到任意点, 2 = 自由导航到站点, 3 = 路径导航到站点, 5 = 钻货架, 6 = 跟随, 7 = 平动转动, 8 = 磁条导航, 100 = 其他
                    RoboshopStateItem.target_id=json_object.value("target_id").toString();//	当前导航要去的站点, 仅当 task_type 为 2 或 3 时该字段有效, task_status 为 RUNNING 时说明正在去这个站点, task_status 为 COMPLETED 时说明已经到达这个站点, task_status 为 FAILED 时说明去这个站点失败, task_status 为 SUSPENDED 说明去这个站点的导航暂停
                    RoboshopStateItem.roboroute_target=json_object.value("roboroute_target").toString();//	调度系统 RoboRoute 让机器人去的最终目标站点 ID
                    RoboshopStateItem.reloc_status=json_object.value("reloc_status").toInt();

                    //qDebug()<<RoboshopStateItem.voltage<<RoboshopStateItem.current<<RoboshopStateItem.task_type;
                    if(json_object.value("path").isArray())
                    {
                        QJsonArray pathList = json_object.value("path").toArray();
                        QList<double> getPath;
                        for(auto listItem : pathList)
                        {
                            getPath.append(listItem.toDouble());
                        }
                        RoboshopStateItem.path.append(getPath);//机器人所在区域 id 的数组(由于地图上的区域是可以重叠的, 所以机器人可能同时在多个区域)，数组可能为空
                    }

                    QJsonArray finished_pathList = json_object.value("finished_path").toArray();
                    for(auto listItem : finished_pathList)
                    {
                        RoboshopStateItem.finished_path.append(listItem.toString());//当前导航路径上已经经过的站点, 为站点的数组, 仅当 task_type 为 3 或 4 时该字段有效点。如果是路径导航， 这里会列出所有已经经过的中间点
                    }
                    QJsonArray unfinished_pathList = json_object.value("unfinished_path").toArray();
                    for(auto listItem : unfinished_pathList)
                    {
                        RoboshopStateItem.unfinished_path.append(listItem.toString());//当前导航路径上尚未经过的站点, 为站点的数组, 仅当 task_type 为 3 或 4 时该字段有效。如果是路径导航， 这里会列出所有尚未经过的中间点;
                    }
                    RoboshopStateItem.warnings= json_object.value("warnings").toObject();//报警码 Warning 的数组, 所有出现的 Warning 报警都会出现在数据中
                    RoboshopStateItem.errors= json_object.value("errors").toObject();//报警码 Error 的数组, 所有出现的 Error 报警都会出现在数据中
                    RoboshopStateItem.ret_code=json_object.value("ret_code").toInt();//API 错误码
                    RoboshopStateItem.err_msg=json_object.value("err_msg").toString();//错误信息
                    Recv_AllData.clear();
                    return;
                }

            }
        }
        else if (uint8_t(a0) == 0x5A && peerPort!=19204) {
            emit Roboshop_ret_code(RecvData);
        }
        RecvData.clear();
    }

}

QTcpSocket *RobotStatusTcp::tcpSocket() const
{
    return _tcpSocket;
}

QString RobotStatusTcp::getCurrentDateTime()const
{
    return QDateTime::currentDateTime().toString("[yyyyMMdd|hh:mm:ss:zzz]:");
}

QString RobotStatusTcp::hexToQString(const QByteArray &b)
{
    QString str;
    for(int i=0;i<b.size();++i){
        ////        //每2位加入 空格0x
        ////        if((!(i%2)&&i/2)||0==i){
        ////            str+= QString(" 0x");
        ////        }
        str +=QString("%1").arg(b.at(i));
    }
    str = str.toUpper();
    return str;
}

