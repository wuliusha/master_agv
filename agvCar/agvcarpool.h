#ifndef AGVCARPOOL_H
#define AGVCARPOOL_H

#include <QObject>
#include <QTcpServer>
#include <QThread>
#include <QTimer>
#include <QMutex>

#include "agvcar.h"
#include "agvcarsocket.h"
#include "queryServer/queryserver.h"


class agvCarPool : public QTcpServer
{
    Q_OBJECT

public:
    agvCarPool();

    ~agvCarPool();

    //获取agvCarPool实例
    static agvCarPool *getInstance();

    const QMap<agvCar *,QString> &getAgvCarMap(){return agvCarMap;}

    //读取每个楼层的AGV并创建
    void initAgvFloorMap();

signals:

    //发送所有AGV状态
    void allAGVState(QList<agvState> );

    //发布AGV任务
    void AGVMoveTask(QString AGVIP, quint32 StartQRPoint, quint32 EndQRPoint,int AGVAction,int tye,agvORderTask agvORderTaskI);

    void AgvStateWidget(agvState agvStateItem1);//显示AGV 详细状态信息

    void sigDoorSubTaskAction(QString doorIP,int doorAction,QString AGVIP);

public slots:

    //释放已掉线的AGV的通信Socket
    void onAgvCarSocketDeleteLater();

    //发布AGV任务
    void onAGVMoveTask(QString AGVIP, quint32 StartQRPoint, quint32 EndQRPoint,int AGVAction,int tye,agvORderTask agvORderTaskI);

    void ON_AGVChargeTask(QString AGVIP,  quint16 opendcharge);//AGV充电回路 指令

    void ON_TaskmoveListProcess(QString AGVIP, QMap<int,agvSubTask> TaskmoveList,agvState agvStateItem,int Initaction);

    //online 0掉线  在线开门    DeviceStatus 0关门  1开门
    void ON_Device_door_Status(QString DeviceIP,int online,int DeviceStatus);

public:
    doorSubTask getdoorSubTask(QString AGVIP,QMap<int,agvSubTask> TaskmoveList,agvState agvStateItem);

protected:
    //获取新的Socket连接
    void incomingConnection(qintptr newAgvCar);

private:
    static agvCarPool *pThis;                             //获取实例
    static QMutex *getInstanceMutex;                      //获取实例锁

    QTimer addAGVTaskTimer;                               //AGV任务编译定时器
    QTimer repairAGVTaskTimer;                            //AGV任务重新发送定时器
    QTimer sendAGVTaskTimer;                              //发送AGV任务定时器
    QTimer readAGVTaskTimer;                              //接收AGV任务定时器

public:

    QMap <agvCar *,QString >agvCarMap;                    //agvIP与AGV对照表
    QMap <QThread *,QString >agvThreadMap;                //agvIP与线程对照表
    QMap <agvCarSocket *,agvCar *>agvCarSocketMap;        //agvSocket与AGV对照表

    bool doorSubTaskbool=true;
    QString doorSubTask_task="";                          //
    int doorSubTask_task_count=0;                          //
    QMap <int,doorSubTask>doorSubTaskMap;                 //自动门开门信号

};

#endif // AGVCARPOOL_H
