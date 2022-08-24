#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QThread>
#include <QTimer>
#include "tcpsocket.h"

#include "Device/array_single.h"
#include "singleProject/single_project.h"

struct TcpServer_Client
{
    QString ClientIP="";                            //平板客户端 IP
    QMap<QString,QByteArray>AnalysisArrayMap;       //平板客户端返回 数据 待处理缓存链表
    int Infocount=0;
    int Infocount_agv=0;
    int Infocount_task=0;

    QMap<int,QByteArray>ConfigureArray_wait;        //完成入库的任务
    QMap<int,QByteArray>ConfigureArray_run;         //正在运行的任务
};


class TcpServer :  public QTcpServer
{
    Q_OBJECT
public:
   TcpServer();
   ~TcpServer();

protected:    //函数重载    //获取新的Socket连接
    void incomingConnection(qintptr Descriptor);

public slots:

    void ON_SendTimer();

    void ON_ReceiveData();                                                 //读取数据

    void TcpServerProcessing(QString ClientIP,QByteArray AnalysisArray,qintptr descriptor); //处理数据

    void ON_ClientDisconnected();                                          //客户端断开连接触发disconnected信号

public:
    QTimer *SendTimer;
    int SendTimercount=0;
    bool TcpSocketbool=true;
    int currentTaskcount=0;
    QList<QString>deleteSocketList;
    QMap<QString,QTcpSocket*>TcpSocketList;
    QMap<QString,deviceServer>deviceServerMap;             //平板客户端链接缓存

    QMap<int, SAPExcelInfo>currentSAPExcelInfoTask;                //SAP 正在执行或未完成的任务

    void setdeviceServerInfo(deviceServer deviceServerI);          //设置客户端基础信息

    void setdeviceServerAction(QString deviceIP,QByteArray ActionArray);   //设置客户端动作指令信息

    QByteArray getActionArray(QString ClientIP);

signals:
    void sigLiftStatuschage(QString DeviceIP,QByteArray ActionArray);      //实时更新电梯状态信息

    void sigDeviceStatuschage(QString DeviceIP,QByteArray ActionArray);      //实时更新设备状态信息


public slots:



};

#endif // TCPSERVER_H
