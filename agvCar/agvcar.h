#ifndef AGVCAR_H
#define AGVCAR_H

#include <QObject>
#include <QThread>
#include<QTimer>
#include "crc/crcdatacale.h"
#include "agvcarsocket.h"
#include <QMutex>
#include <QMutexLocker>

#include "agv_single.h"

class agvCar : public QObject
{
    Q_OBJECT

public:
    agvCar();

    ~agvCar();

    //发送 AGV移动任务 任务表(二维码导航方式)

    /*taskType任务类型; StartPoint起始二维码; EndPoint目标二维码; Distance移动距离;Speed移动速度;
     BarrierInstruction障碍指令; AttitudeAngle姿态角度;  MoveAnage移动角度; RotaryAngle转盘角度*/
    QByteArray assignment_move(quint8 taskType, quint32 StartPoint,quint32 EndPoint, quint16 Distance,quint8 Speed,
                               quint8 BarrierInstruction,quint16 AttitudeAngle, quint16 MoveAnage,quint16 RotaryAngle);

    //发送 AGV举升降下托盘任务 任务表() taskType任务标识; ExecutePoint执行二维码
    QByteArray assignment_tray(quint8 taskType, quint32 ExecutePoint);

    //发送 指定姿态角度/高度 AGV举升降下托盘任务 任务表() taskType任务标识; ExecutePoint执行二维码
    QByteArray assignment_Rotary(quint8 taskType, quint32 ExecutePoint,quint16 AttitudeAngle, quint16 RotaryHeight);

    //发送 AGV 夹抱机器人取放货 动作 指令  assignmentId
    QByteArray assignment_control(quint8 taskType, quint32 ExecutePoint,agvORderTask agvORderTaskI);


    //发送 AGV任务命令表
    QByteArray command_order(quint8 commandId, QList<QByteArray > assignmentList);

    //发送 AGV其他命令表
    QByteArray command(quint16 commandId);

    //发送 AGV其他命令表
    QByteArray command_other(quint16 commandId);

    //发送 AGV通信贞
    QByteArray communication(quint16 targetAddress, quint16 sourceAddress, QByteArray commandArray);

    //控制数据范围
    quint32 controlRange(quint32 initialData, quint32 minData ,quint32 maxData);

    //解析AGV状态数据
    void analysis(QByteArray AnalysisArray);

    //AGV原地旋转
    agvSubTask agvPivotTask(quint32 PivotPoint, quint16 moveAnage);

    //AGV举升顶盘
    QList<agvSubTask > agvRotateUpTask(quint32 UpPoint);

    //AGV降下顶盘
    QList<agvSubTask > agvRotateDownTask(quint32 DownPoint);

    //夹抱 AGV 动作基本任务
    QList<agvSubTask > agvORderTaskTask(quint32 DownPoint,agvORderTask agvORderTaskI);

    //任务路径转换为任务通信贞
    QByteArray setAgvSubTask(agvSubTask agvSubTaskI);

    //把子任务链表 转换为待发数据
    void setAgvSendRepairSubTaskList();

    //设置 AGV动态参数初始化
    void setAGVMoveinit();

    //AGV 异常时参数初始化
    void setAGVORderInit();

    //发送 AGV (初始化命令/同步帧编码) 函数
    void sendAGVORderCommand(int AGVAction);

    bool Taskmove_Processbool=true;
    void TaskmoveList_Process_(QMap<int,agvSubTask> TaskmoveList,int passTaskId);//前二维码移动指令可以执行

    void setTaskmoveList_Process(int passPointState,int currentTaskCount);              //实时触发 移动任务指令  判断当前二维码移动指令是否可以执行


signals:

    //分配AGV任务 信号
    void AGVMoveTask(quint32 StartQRPoint, quint32 EndQRPoint,int AGVAction,int tye,agvORderTask agvORderTaskI);

    void AgvStateWidget(agvState agvStateItem1);//显示AGV 详细状态信息

    void AGVChargeTask(QString AGVIP,  quint16 opendcharge);//AGV 打开/关闭 充电指令

    void sigDoorSubTaskAction(QString doorIP,int doorAction,QString AGVIP);//自动门开关信号

    void TaskmoveListProcess(QString AGVIP, QMap<int,agvSubTask> TaskmoveList, agvState agvStateItem,int Initaction);


public slots:
    //从AGV接收数据 槽函数
    void onReadyRead();

    //定时编译AGV任务
    void onAddAGVTaskTimerOut();

    //定时发送给AGV任务
    void onSendAGVTaskTimerOut();

    //定时读取从AGV接收任务
    void onReadAGVTaskTimerOut();

    //分配AGV任务 槽函数
    void onAGVMoveTask(quint32 StartQRPoint, quint32 EndQRPoint, int AGVAction,int chargetye,agvORderTask agvORderTaskI);


    void ONUPdataTimer_Widget();

    void ON_AGVChargeTask(QString AGVIP,  quint16 opendcharge);//AGV指令


public:

    quint16 agvTargetAddress = 0;                       //AGV目标地址
    quint16 assignmentNo = 1;                           //AGV任务序号
    quint16 commandNo = 1;                              //AGV贞编码

private:
    QTimer *UPdataTimer;
    int unusualcount=3;                                 //AGV异常 开始同步帧编码
    int SendSubTaskcount=0;                             //发送动作指令,  0允许发送
    int agvSendSubTaskcount=0;
    QByteArray agvSendSubTask_query;                    //AGV查询帧
    QMap<quint16,agvRepairSubTask>agvSendSubTask_action;//当前正在发送给AGV任务列表

    QList<QByteArray > agvReadAllTaskList;              //从AGV接收任务列表

public:
    int agvId=0;
    QString agvIp;                                      //AGVIP
    int agvFloor = 0;                                   //AGV楼层
    int currentRotaryHeightState=4;                     //记录举升 最新命令状态 确保AGV重启后 保持原来状态   4 降下    3举升

    agvState agvStateItem;                              //AGV状态
    QMap<agvCarSocket *,bool >agvCarSocketItemMap;      //AGV可用通信Socket表


    QMap<int,agvSubTask > agvSubTaskList_Map;           //当前执行 AGV子任务列表
    QMap<int,agvSubTask > agvSubTaskmoveMap;            //当前运行路线 AGV二维码任务链表

};

#endif // AGVCAR_H
