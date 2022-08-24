#ifndef ESS_SINGLE_H
#define ESS_SINGLE_H

#include <QObject>

#include "queryServer/getinstancedefine.h"
#include "sqlConnect/ConnectionPool.h"
#include "singleProject/single_project.h"
#include "httpserver/httpconnection.h"


#define agvStateItembool 1
#define agvStateItembool_ 0

#define remainder 10                /***计时器求余***/
#define freeStatus 0                 /***空闲状态***/
#define Actionagv_max 6              /***AGV 任务动作指令最大值***/
#define Actionagv_re 10              /***AGV 任务动作指令最大值***/

#define taskTake_ess 6               /***夹抱机器人入库完成取货时的任务状态***/
#define taskTake_send 8              /***入库码头错位取货时  需先发容器离场，再发容器入场***/
#define taskTake_send_ 10            /***夹抱机器人入库完成取货,等待入库***/

#define taskFnish_ess 9              /***夹抱机器人完成放货时的任务状态***/
#define tasklift_ess 14              /***前往目标楼层***/

#define taskStatus_delete 90         /***任务删除时的状态  解绑库位***/
#define taskStatus_delete_ 92        /***任务删除时的状态  解绑码头***/

#define taskFnish_not  99             /***总任务完成***/
#define taskFnish  100               /***总任务完成***/

//夹抱任务状态
#define PENDING "PENDING"
#define PROCESSING "PROCESSING"
#define SUSPEND "SUSPEND"
#define FINISHED "FINISHED"
#define CANCELLED "CANCELLED"
#define FAILED_ESS "FAILED"


class ESS_Single : public QObject
{
    Q_OBJECT

public:
    explicit ESS_Single(QObject *parent = nullptr);

    REGISTERGETINSTANCE(ESS_Single)//获取单例模式

    void setCurrentServerItem(ServerItem CServerItem,ServerInit CServerInit);

    //接驳台的任务信息
    QMap<QString,deviceI>stationInfoMap;
    void setStationInfoMap(QMap<QString,deviceI>stationInfoMapI);    //更新基础信息: 是否离线
    QMap<QString,deviceI> getstationInfoMap_Map();                   //获取当前设备信息

    //创建 MES 缓存列表
    QMap<QString, SAPExcelInfo>newSAPExcelInfoList;
    bool setNewSAPExcelInfoList(SAPExcelInfo SAPExcelInfoI);
    QMap<QString, SAPExcelInfo> getNewSAPExcelInfoList();

    QMap<int, SAPExcelInfo>seletSAPExcelInfoTask;
    void setCurrentSAPExcelInfoTask(QMap<int, SAPExcelInfo>seletSAPExcelInfoTask_);               //获取SAP任务链表
    QMap<int, SAPExcelInfo> getCurrentSAPExcelInfoTask();               //获取SAP任务链表

    QMap<QString,shelfBinInfo>shelfBinInfoMap;                          //实时更新 Bin 的状态信息
    QMap<QString,shelfBinInfo>getshelfBinInfoMap(QString taskType,QString queryLineEdit,QString containerCode);

    shelfBinInfo getshelfBinInfo_Empty(SAPExcelInfo SAPExcelInfoI);     //入库时获取空闲的 库位
    shelfBinInfo getcontainerCode_desc(QString containerCode);          //出库时获取当前胶箱库位

public:
    QMap<QString,ESSRobot>ESSRobotInfoMap;
    void setESSRobot(QString robotCode, ESSRobot ESSRobotI);            //实时更新海柔夹包机器人状态信息

    //提交单个 ESS 任务
    ESS_Request setESS_RequestI(SAPExcelInfo SAPExcelInfoI,ESS_Request ESS_RequestI,QString actionId);

    //批量提交 ESS 任务
    QMap<QString ,ESS_Request >setESS_RequestI_Map(QMap<int, SAPExcelInfo>SAPExcelInfoTask,ESS_Request ESS_RequestI,QString actionId);

    QMap<QString,QString> CurrentESS_RepostMap;
    bool setCurrentESS_Repost(QString taskId_ess,QString eventCodeDesc);      //实时监听并获取ESS_任务状态

    QString getCurrentESS_Repost(QString taskId_ess);                      //更新ESS_任务状态 到 task

    //实时更新 SAP 任务状态
    QMap<int, SAPExcelInfo>getSAPExcelInfoTask(QMap<int, SAPExcelInfo>SAPExcelInfoTask);

    //把SAP 任务状态 转换为post 并实时更新更新到 MES
    WWYLPOST MES_WWYLPOSTI(SAPExcelInfo SAPExcelInfoI,QString actionId);


public:

    ServerInit ServerInitItem;      //基础信息
    ServerItem CurrentServerItem;   //需要实时更信息 链表表 整合

    QString currentUserNuber="";
    QMap<int ,sapPath >sapPathMap;
};

#endif // ESS_SINGLE_H
