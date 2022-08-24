#ifndef TASKMANAGERSERVER_H
#define TASKMANAGERSERVER_H

#include <QObject>
#include "taskmanager.h"

class taskManagerServer : public QObject
{
    Q_OBJECT
public:
    explicit taskManagerServer(QObject *parent = nullptr);

    void taskManagerServerInit();

    bool taskProcessTimer();                                    //实时判断任务状态 及处理

    bool ProcessMsgRecv();                                      //实时判断ESS 接口返回数据

    QMap<QString,int>taskId_AGVStatusMap;                       //SAP与AGV 任务状态绑定
    QString setAGVTCurrentTask(SAPExcelInfo SAPExcelInfoI,int Floor,QString sourcestation,QString destination);   //创建AGV配送任务

    //获取 允许放料的 电梯接驳台    action-->0空闲  1 锁定  2到达 3解锁
    bool getLiftCodeMap(QString codeDesc,int action, SAPExcelInfo SAPExcelInfoI);

    //获取 空闲的接驳台 状态信息
    deviceI getStationInfo_Empty(QString deviceDesc);

    //////////////////////////////////////////////////
    /// *函数名称:  getcurrentSAPExcelInfoTask
    /// 函数功能:   定时获取数据库，待执行任务 任务状态为:0
    /// 函数参数:   无参数
    /// 返回值:
    bool getcurrentSAPExcelInfoTask();

    bool newSAPExcelInfo_Empty();//创建返空料框任务

    //清除当前升降机任务信息
    void LiftCodeStatus_clear(int SAPTaskIndex);

    //AGV 充电动作指令函数
    bool setAGVCurrentTask_charge(AGVCurrentTask *AGVCurrentTaskI);

    //AGV 运送动作指令函数
    bool setAGVCurrentTask_task(AGVCurrentTask *AGVCurrentTaskI);

    //AGV 返回待机点动作指令函数
    bool setAGVCurrentTask_wait(AGVCurrentTask *AGVCurrentTaskI);

    //AGV 运送动作指令函数 返回
    bool setAGVCurrentTask_task_(AGVCurrentTask *AGVCurrentTaskI);

signals:
    //发布AGV任务
    void sigAGVMoveTask(QString AGVIP, quint32 StartQRPoint, quint32 EndQRPoint, int AGVAction,int chargetye,agvORderTask agvORderTaskI);

    void sigChargeTask(QString AGVIP,  quint16 opendcharge);//AGV 打开/关闭 充电指令

    //设备动作指令——————> DeviceIP：设备IP     deviceType：设备类型   orderType：动作指令   Action：动作标识
    void sigDeviceStatusAction(QString DeviceIP,QString deviceType, QString orderType, int Action);

    //升降机的动作指令---单个
    void sigsetLiftactionArray(LiftTask LiftTaskI,int startFloor,int destFloor);

    //根据任务状态实时 绑定解绑接驳台
    void sigDeviceStatus(QString deviceDesc,SAPExcelInfo SAPExcelInfoI);

    /************* 状态更新 显示 ************/
    void sigAGVCurrentTaskMap(QMap<QString,AGVCurrentTask*>AGVCurrentTaskMapI);

    void sigLiftCodeMap(QMap<QString,LiftCode>LiftCodeMap);            //更新升降机各个接驳台状态信息

public slots:
     //实时判断任务状态 及处理
     void taskManagerServerTimer();

     //创建 SAP 任务
     void ON_SAPExcelInfo_new(SAPExcelInfo SAPExcelInfoI);

     void ON_SAPExcelInfoList_new(QMap<QString, SAPExcelInfo>newSAPExcelInfoList_);

     //创建 AGV 搬运任务
     void ON_AGVMoveTask(QString AGVIP,QString taskType,AGVCurrentTask AGVCurrentTaskI);

     //AGV 状态信息
     void ON_AgvStateWidget(agvState agvStateItemI);

     //更新SAP 任务状态
     void ON_UPSAPExcelInfoTask(SAPExcelInfo seletSAPExcelInfoI);

     //手动更新AGV当前动作指令状态
     void ON_AGVCurrentTaskAction(QString AGVIP,QString Type, int Action);

     //删除 SAP 任务
     void ON_deleteSAPExcelInfoTask(SAPExcelInfo seletSAPExcelInfoI);

     //实时更新升降机状态信息
     void ON_LiftTaskStatus(LiftTask LiftTask0);

     //清除当前升降机任务信息
     void ON_LiftCodeStatus_clear(LiftCode LiftCodeItem);

     //清空库位
     void ON_containerCode_clear(QString shelfBindesc,QString containerCode,QString type);

     void ON_taskCodes_WW(QString iKey, WWYLPOST WWYLPOSTI, QString UserBadge, int pathId);  //通过接口创建出入库任务


public:
     bool countbool=true;
     int TableWidgetcount=0;
     QDateTime taskCountTimer;       //实时更新时间
     QString currentUserNuber="";

     LiftTask LiftTaskI;
     int LiftOccupy=0;                                  //电梯任务占用
     QMap<QString,LiftCode>LiftCodeMap;                 //更新升降机各个接驳台状态信息
     QMap<QString,LiftCode>LiftCodeMap_Info;                 //更新升降机各个接驳台状态信息
     QMap<QString,deviceI>stationInfoMap;               //当前站点状态信息

     QMap<QString,int>taskCodeInfoMap;                  //ESS 任务状态对应 SAP任务状态
     bool boolagvState=true;                            //槽函数 保护机制
     QMap<QString,AGVCurrentTask*>AGVCurrentTaskMap;    //当前AGV状态信息

     int SAPTaskIndex_send=0;                           //入库码头错位取货时  需先发容器离场，再发容器入场
     QMap<QString, SAPExcelInfo>newSAPExcelInfoList;    //new MES task
     QMap<int, SAPExcelInfo>currentSAPExcelInfoTask;    //MES run task
     QMap<int, SAPExcelInfo>slectSAPExcelInfoTask;      //new sql task

private:
     QTimer *StTimer;
     ServerInit ServerInitItem;      //基础信息
     ServerItem CurrentServerItem;   //需要实时更信息 链表表 整合

     ThreadInsert *ThreadInsertI;
     QThread *ThreadInsertItiem;

     threadQuery *threadQueryI;
     QThread *threadQueryItem;

     HttpServer *server;
     QThread *Threadserver;

     HttpServer *server_;           //ESS 专用
     QThread *Threadserver_;        //ESS 专用

};

#endif // TASKMANAGERSERVER_H
