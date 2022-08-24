#ifndef UDP_DEVICE_H
#define UDP_DEVICE_H

#include <QObject>
#include <QObject>
#include <QTcpServer>
#include <QThread>
#include <QTimer>
#include <QUdpSocket>

#include "Device/array_single.h"
#include "singleProject/single_project.h"


class Udp_Device : public QObject
{
    Q_OBJECT

public:
    explicit Udp_Device(QObject *parent = nullptr);
      ~Udp_Device();

    void setListen(quint16 port);

    QByteArray getActionArray(QString DeviceIP);

signals:
    void sigDeviceStatuschage(QString DeviceIP,QByteArray ActionArray);      //实时更新设备状态信息

public slots:

     void ON_SendTimer();

     void slotReadySocketReadDatagrams();                                   //读取数据 udp
public:
     void TcpServerProcessing(QByteArray AnalysisArray,QString DeviceIP);   //处理数据

     void setDeviceStatuschage(QString DeviceIP,controlbox controlboxI);    //实时更新设备状态信息

public:
     QTimer *SendTimer;
     QUdpSocket *UDPSocket;

     int SendTimercount=0;
     bool TcpSocketbool=true;

     QMap<QString,QByteArray>SocketqueryMap;
     QMap<QString,TcpServer_device>TcpServer_deviceMap;

     //设备信息初始化
     void setDeviceInit(QString DeviceIP,QByteArray queryArray);

public slots:

     //DeviceIP：设备IP     deviceType：设备类型   orderType：动作指令   Action：动作标识
     void ON_DeviceStatusAction(QString DeviceIP,QString deviceType, QString orderType, int Action);

};

#endif // UDP_DEVICE_H
