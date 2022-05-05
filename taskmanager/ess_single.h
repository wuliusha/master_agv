#ifndef ESS_SINGLE_H
#define ESS_SINGLE_H

#include <QObject>
#include <QtCore>
#include <QtGui>
#include<QToolButton>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#include<QMouseEvent>
#endif

#include "sqlConnect/ConnectionPool.h"
#include "singleProject/single_project.h"
#include "httpserver/httpconnection.h"


class ESS_Single : public QObject
{
    Q_OBJECT

public:
    static QMutex mutex;
    static ESS_Single* ESS_SingleItiem;

    static ESS_Single *GetInstance();
    explicit ESS_Single(QObject *parent = nullptr);

    void setCurrentServerItem(ServerItem CServerItem,ServerInit CServerInit);

    ServerItem getCurrentServerItem();

    //创建 MES 缓存列表
    QMap<QString, SAPExcelInfo>newSAPExcelInfoList;
    bool setNewSAPExcelInfoList(SAPExcelInfo SAPExcelInfoI);
    QMap<QString, SAPExcelInfo> getNewSAPExcelInfoList();

    QMap<int, SAPExcelInfo> getCurrentSAPExcelInfoTask();               //获取SAP任务链表

    QMap<QString,shelfBinInfo>shelfBinInfoMap;                          //实时更新 Bin 的状态信息
    void setshelfBinInfoMap(QMap<QString,shelfBinInfo>shelfBinInfoMap_); //实时更新 Bin 的实时状态信息链表
    QMap<QString,shelfBinInfo>getshelfBinInfoMap();                     //获取 Bin 的实时状态信息链表

    shelfBinInfo getshelfBinInfo_Empty(SAPExcelInfo SAPExcelInfoI);     //入库时获取空闲的 库位
    shelfBinInfo getcontainerCode_desc(QString containerCode);          //出库时获取当前胶箱库位

    QMap<QString,StationInfo>StationInfoMap;                            //实时更新站点的状态信息
    void UP_StationInfoMap(QMap<QString,StationInfo>StationInfoMap_);   //更新 站点 的实时状态信息链表
    QMap<QString,StationInfo>getStationInfoMap();                       //获取 站点 的实时状态信息链表

    QMap<QString,LiftCode>LiftCodeMap;
    void setLiftCodeMap(QMap<QString,LiftCode>LiftCodeMap_);            //更新升降机各个接驳台状态信息
    QMap<QString,LiftCode> getLiftCodeMap();

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
    WWYLPOST getWWYLPOSTI(SAPExcelInfo SAPExcelInfoI,QString actionId);


public:

    ServerInit ServerInitItem;      //基础信息
    ServerItem CurrentServerItem;   //需要实时更信息 链表表 整合

    int ServerItemcount=100;
    QString currentUserNuber="";
    QMap<int ,sapPath >sapPathMap;


    void getAGVInfo();

};

#endif // ESS_SINGLE_H
