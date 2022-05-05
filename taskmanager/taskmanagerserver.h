#ifndef TASKMANAGERSERVER_H
#define TASKMANAGERSERVER_H

#include <QObject>
#include "taskmanager.h"

class taskManagerServer : public QObject
{
    Q_OBJECT
public:
    explicit taskManagerServer(QObject *parent = nullptr);

    taskManager *taskmanagerItem;                               //任务管理
    void taskManagerServerInit();

    QMap<int, SAPExcelInfo> taskProcessTimer(QMap<int, SAPExcelInfo>currentSAPExcelInfoTask);                                    //实时判断任务状态 及处理

    QMap<int, SAPExcelInfo> ProcessMsgRecv(QMap<int, SAPExcelInfo>currentSAPExcelInfoTask);                                      //实时判断ESS 接口返回数据

    QMap<QString,int>taskId_AGVStatusMap;                       //SAP与AGV 任务状态绑定
    QString setAGVTCurrentTask(SAPExcelInfo SAPExcelInfoI,int Floor,QString sourcestation,QString destination);   //创建AGV配送任务

    void InsertISAPAction();                                            //实时sql数据库写入状态

    StationInfo getStationInfoMap(QString Station_Type);                //获取当前任务数最少的 接驳台
    StationInfo getStationInfo(QString StationDesc);                    //获取当前站点信息

    //设置并更新接驳台状态信息   //orderStatus=  0空闲  1占用  2正在执行  3执行完成  0空闲
    void setStationInfoMap(QString StationDesc,QString containerCode,int orderStatus,QString orderType);

    //获取 允许放料的 电梯接驳台    action-->0空闲  1 锁定  2到达 3解锁
    bool getLiftCodeMap(QString codeDesc,int action, SAPExcelInfo SAPExcelInfoI);

    QMap<int,SAPExcelInfo>getcurrentSAPExcelInfoTask(QMap<int, SAPExcelInfo>SAPExcelInfoTask);

    bool newSAPExcelInfo_Empty(QString tasktype,StationInfo StationInfoI);//创建返空料框任务

signals:
    //发布AGV任务
    void sigAGVMoveTask(QString AGVIP, quint32 StartQRPoint, quint32 EndQRPoint, int AGVAction,int chargetye,agvORderTask agvORderTaskI);

    void sigChargeTask(QString AGVIP,  quint16 opendcharge);//AGV 打开/关闭 充电指令

    //设备动作指令——————> DeviceIP：设备IP     deviceType：设备类型   orderType：动作指令   Action：动作标识
    void sigDeviceStatusAction(QString DeviceIP,QString deviceType, QString orderType, int Action);

    //升降机的动作指令---单个
    void sigsetLiftactionArray(LiftTask LiftTaskI,int startFloor,int destFloor);

    //定时往 MES 更新 任务状态信息
    void sigUP_SAPExcelInfo(SAPExcelInfo SAPExcelInfoI);


public slots:
     //实时判断任务状态 及处理
     void taskManagerServerTimer();

     //创建 SAP 任务
     void ON_SAPExcelInfo_new(SAPExcelInfo SAPExcelInfoI);

     //创建 AGV 搬运任务
     void ON_AGVMoveTask(QString AGVIP,QString taskType,AGVCurrentTask AGVCurrentTaskI);

     //AGV 状态信息
     void ON_AgvStateWidget(agvState agvStateItemI);

     //更新SAP 任务状态
     void ON_UPSAPExcelInfoTask(QMap<int, SAPExcelInfo>seletSAPExcelInfoTask,ESS_Request ESS_RequestI,QString taskType);

     //删除 SAP 任务
     void ON_deleteSAPExcelInfoTask(QMap<int, SAPExcelInfo>seletSAPExcelInfoTask);

     //实时更新升降机状态信息
     void ON_LiftTaskStatus(LiftTask LiftTask0);

     //更新各设备状态信息  控制盒-接驳台类型
     void ON_DeviceStatus_station(QString DeviceIP,int online,int DeviceStatus,controlbox controlboxI);

     //清空库位
     void ON_containerCode_clear(QString shelfBindesc,QString containerCode);


public:
     bool countbool=true;
     int TableWidgetcount=0;
     QString currentUserNuber="";

     LiftTask LiftTaskI;
     QMap<QString,LiftCode>LiftCodeMap;                 //更新升降机各个接驳台状态信息
     QMap<QString,StationInfo>currentStationInfoMap;    //当前站点状态信息

     QMap<QString,AGVCurrentTask>AGVCurrentTaskMap;     //当前AGV状态信息
     QMap<QString, SAPExcelInfo>newSAPExcelInfoList;    //new MES task
     QMap<int, SAPExcelInfo>currentSAPExcelInfoTask;    //MES run task

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

     HttpServer *server_;   //ESS 专用
     QThread *Threadserver_;//ESS 专用

};

#endif // TASKMANAGERSERVER_H
