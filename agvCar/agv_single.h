#ifndef AGV_SINGLE_H
#define AGV_SINGLE_H

#include <QObject>
#include <QtCore>
#include <QTimer>
#include <QWidget>
#include <QtGui>
#include<QToolButton>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#include<QMouseEvent>
#endif

#include <QObject>
#include "queryServer/queryserver.h"
#include "singleProject/single_project.h"
#include "sqlConnect/sqlconnectionpool.h"


//AGV 变化参数
struct parameter
{
    bool waitFlag=false;                      //等待倒计时标识
    QDateTime waitTimer;                      //某个时间点停留时间计时
    int CurrentDestpoint=0;                   //当前目标二维码
    int ChargeAction = 0;                     //充电任务锁定(0.充电任务无锁定，1.充电任务锁定)
    int doorPoint=0;                          //自动门等待点
    bool  isAvoid = false;                    //是否执行避让任务(false.不执行避让，true.执行避让)
    QMap<int,int> RunPointList;               //正在执行的二维码 缓存链表  taskId-Point

};

struct agvState
{
    QString agvIp;                            //AGVIP
    bool FinishInit=false;                    //AGV已完成初始化
    bool freeInit=false;                      //AGV判断是否在运行中
    int FinishInitcount=5;                    //初始化复位计数

    int RunStatus=0;                          //当前运行状态  1 运行 2 停止
    int lastTimer=0;                          //距离上次通信时间
    bool isOnline=false;                      //AGV是否掉线
    int moveTaskState=-1;                     //AGV运行任务指令状态

    int RotaryHeightStatecount=0;             //举升指令计数
    QString commandState;                     //当前回复命令码
    QString communicationNumberState;         //当前通信贞编码
    QString commandNo ;                       //系统 通信贞编码
    QString commandNo_AGV ;                   //系统 通信贞编码


    QString FarInducedState="";               //障碍感应注释
    bool isFrontLaserFarInducedState = false; //AGV前面远距离激光感应
    bool isFrontLaserNearInducedState = false;//AGV前面近距离激光感应
    bool isRearLaserFarInducedState = false;  //AGV后面远距离激光感应
    bool isRearLaserNearInducedState = false; //AGV后面近距离激光感应
    bool isLeftLaserFarInducedState = false;  //AGV左面远距离激光感应
    bool isLeftLaserNearInducedState = false; //AGV左面近距离激光感应
    bool isRightLaserFarInducedState = false; //AGV右面远距离激光感应
    bool isRightLaserNearInducedState = false;//AGV右面近距离激光感应
    bool isFindQRCodeState = false;           //AGV在二维码上标志
    bool isRotaryLowState = false;            //AGV转盘下限位感应
    bool isRotaryHighState = false;           //AGV转盘上限位感应
    bool isRotaryOriginPointState = false;    //AGV转盘原点检测状态
    QString passPointState="0";               //AGV上次读到的二维码点
    QString currentPoint_X_OffsetState;       //AGV当前点X偏移
    QString currentPoint_Y_OffsetState;       //AGV当前点Y偏移
    QString currentPointAttitudeAngleState;   //AGV当前姿态角度
    QString currentPointRotaryAngleState;     //AGV当前转盘角度
    QString currentPointMoveAngleState;       //AGV当前移动角度
    QString currentTaskNumberState;           //AGV当前执行任务编号
    QString currentTaskCountState;            //AGV当前剩余任务数
    QString currentTaskCountState_last;       //发送指令时的  当前剩余任务数

    QString currentRotaryHeightState;         //AGV当前转盘高度
    QString currentLeftWheelSpeedState;       //AGV当前左轮速度/AGV当前前轮速度(mm/s)
    QString currentRightWheelSpeedState;      //AGV当前右轮速度/AGV当前后轮速度(mm/s)
    QString currentRotaryLiftSpeedState;      //AGV当前转盘举升速度(mm/s)
    QString currentRotaryRotateSpeedState;    //AGV当前转盘旋转速度(度/s)
    QString currentBatteryVoltageState;       //AGV当前电池电压值(mV)
    QString currentBatteryelectricity;        //AGV当前电池电量 %
    QString currentSystemCurrentState;        //AGV当前系统电流值(mA)
    QString currentErrorCodeState="0";        //AGV当前错误代码
    QString currentWarningCodeState;          //AGV当前警告代码
    QString currentLiftingPodNumberState;     //AGV当前举升货架编号
    QString currentCompletedTaskNumberState;  //AGV当前完成的任务编号
    QString allErrorMessagesState;            //AGV所有错误信息
    QString allWarningMessagesState;          //AGV所有警告信息
    bool isLaserTriggerStop = false;          //AGV激光触发停止
    bool isOpenChargingCircuit = false;       //AGV充电回路状态

    parameter ActionItem;                     //AGV 变化参数

};




//待发送通信贞
struct agvRepairSubTask
{
    int actionType=0;                           //动作指令类型
    quint16 commandId;                          //待发送通信贞 贞编码
    QByteArray agvSubTaskArray;                 //待发送通信贞
};


//AGV移动基本任务
struct agvSubTask
{
    int Id;                                   //编号
    QString RouteName="";                     //路线名

    int TaskId=0;                             //路径内序号
    quint32 Point;                            //AGV基本任务 起始点
    quint32 NextPoint;                        //AGV基本任务 下一点
    quint16 NextPointDistance;                //AGV基本任务 下一点距离
    quint8 AGVSpeed;                          //AGV基本任务 速度
    quint8 RotaryLowBarrierInstruction;       //AGV基本任务 顶盘降下时 激光方案（无货架）
    quint8 RotaryHighBarrierInstruction;      //AGV基本任务 顶盘举升时 激光方案（有货架）
    quint16 postureAngle;                     //AGV基本任务 姿态角度
    quint16 AGVMoveAnage;                     //AGV基本任务 移动角度
    quint16 AGVRotaryAngle;                   //AGV基本任务 转盘角度

    int SubTaskType = 0;                      //AGV基本任务 基本任务类型  0正向  -1反向
    QString complete="0";                     //0 待执行， 1在执行 2 已经过
    int completecount=0;                      //0 待执行， 1在执行 2 已经过

    int agvRotateSign = 0;                    //执行动作计数  序号

    agvORderTask agvORderTaskI;               //夹抱 AGV 动作基本任务

    int checked=0;                  //1选择 0取消
    int row=0;                      //显示在第几行

};


//站点对应二维码数据
struct Stationmap
{
    QString StationName="";                //工位名称
    int StationPoint = 0;                  //工位二维码

    int StartPoint = 0;                    // StationPoint==StartPoint  出去  StationPoint！=StartPoint  进工位
    int PassPoint = 0;                     //经过二维码 0
    int PassPoint1 = 0;                    //经过二维码 1
    int PassPoint2 = 0;                    //经过二维码 2
    int PassPoint3 = 0;                    //经过二维码 3
    QMap<int,int>pointMap;                 //Point,Id

    int assistPoint = 0;                   //辅路线  对接点
    int SubTaskType = 0;                   //AGV基本任务 基本任务类型  0正向  -1反向
    QString assistRoute="";                //与工位连接的辅路线

    int checked=0;                  //1选择 0取消
    int row=0;                      //显示在第几行

};

struct mianRoute
{
    int Id=0;               //序号
    QString keyId="";       //路线编号
    int TaskId=0;           //路径内序号  按照从小到大 执行
    int Point_S = 0;        //起始二维码
    QString RouteName="";   //路线名称
    int Point_E = 0;        //离开二维码
    int SubTaskType = 0;    //AGV基本任务 基本任务类型  0正向  -1反向

    QString StationName=""; //工位名称

    int checked=0;                  //1选择 0取消
    int row=0;                      //显示在第几行

};

//起始点辅路线 与 目标点辅路线的 对应连接关系
struct assistRoute
{
    int Id;                                //序号
    QString keyId="";                      //路线编号
    QString assistRoute_S="";              //起始路线
    int assistPoint_S = 0;                 //起始路线 离开点

    int TaskId=0;
    QMap<QString,mianRoute>mianRouteMap;       //途径的子路线新增 缓存列表

    QString assistRoute_E="";              //目标路线
    int assistPoint_E = 0;                 //目标路线  进入点
};

//基本任务
struct basicTask
{
    quint32 StartPoint;                       //起始二维码点
    quint32 EndPoint;                         //终点二维码点
    int agvAction = 0;                        //执行动作(1.移动动作/2.避让动作/3.举升动作/4.降下动作/5.清除动作/6.停止动作)
    int agvRotateSign = 0;                    //执行动作计数  序号
};

//AGV路径
struct AGVPath
{
    QMap<QString ,QString > StationMap;                     //站点查询表
    QMap<QString ,QString > PathPointMap;                   //地图查询表
    QMap<QString ,QList<agvSubTask > > PathMap;             //路径地图
    QMap<QString ,QMap<QString ,int > > InStationPointMap;  //站点内部位置查询表
    QMap<QString ,QMap<QString ,int > > OutStationPointMap; //站点外部位置查询表
};


class AGV_Single : public QObject
{
    Q_OBJECT

public:
    explicit AGV_Single(QObject *parent = nullptr);

    //获取agvCarPool实例
    static AGV_Single *GetInstance();

    QMap<int,QString >StartQRPointMap;                  //路线以及起始点的缓存链表
    QMap<int,QString >EndQRPointMap;                    //路线以及终点的缓存链表
    QMap<QString,Stationmap >Stationmap_Map;            //站点对应二维码数据
    QMap<int,assistRoute > assistRoute_Map;             //起始点辅路线 与 目标点辅路线的 对应连接关系

    QMap<QString,agvSubTask > agvSubTaskListinit;       //AGV移动基初始化


    int CurrentTaskId=0;                                //当前执行 number
    QMap<int,agvSubTask > agvSubTaskmoveMap;            //当前运行路线 AGV二维码任务链表



    //设置参数初始化函数
    void setAGV_SingleInit();

    //获取当前运行路线 AGV二维码任务链表
    QMap<int,agvSubTask >getAgvSubTaskmoveMap();

    // new AGV子任务列表 当前 未执行 的二维码任务链表
    void agvSubTaskmoveList_add(QMap<int,agvSubTask > agvSubTaskMap_);

    //添加移动二维码
    bool addAgvSubTask(int TaskId,agvSubTask agvSubTaskI,int AGVAction,QString RouteName);





    void pathMapInit();//二维码数据初始化

    //获取当前站点内路线信息Type :0->s  -1 ->e
    QMap<int,agvSubTask > getMianRouteInfo_In(quint32 Point_S,quint32 Point_E,QString RouteName,int SubTaskType);

    //获取站点外: 任意两点 Point 的路线规划  Type--> 0 起点  1 终点
    QMap<int,agvSubTask > getRouteInfo_out(int StartQRPoint,int EndQRPoint,int Type);

    //获取站点内: Point 对应的 辅路线与对接点 Type--> 0 起点  1 终点
    mianRoute getRouteInfo_In(quint32 Point, int Type);


    QString  getMianRouteInfo_or(int StartQRPoint,QString RouteName_s, int EndQRPoint,QString RouteName_e);

    //获取路线  RouteName-->  Point_S 与 Point_E  二维码信息
    QMap<int,agvSubTask > getMianRouteInfo_out(quint32 Point_S,quint32 Point_E,QString RouteName);//站点外

    //获取起始路线  与目标路线之间的 路线信息                (执行链表  按照 Id 从小到大 执行)
    assistRoute getMianRouteMap(QString RouteName_S,QString RouteName_E,int StartQRPoint,int EndQRPoint);

    //获取起始路线 与目标路线之间的 所有二维码的基础信息
    QMap<int,agvSubTask >getMainagvSubTaskMap(QMap<QString,mianRoute> mianRouteMap);

    //起始路线  与目标路线 (执行顺序:-->  按照 Id 从小到大 执行)
    mianRoute getMianRoute_min(QMap<QString, mianRoute> mianRouteMap,QMap<int, mianRoute> RouteMap_);

signals:

public slots:

private:
    static AGV_Single *pThis;                             //获取实例
    static QMutex *getInstanceMutex;                      //获取实例锁

};

#endif // AGV_SINGLE_H
