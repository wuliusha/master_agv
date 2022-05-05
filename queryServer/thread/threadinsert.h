#ifndef THREADINSERT_H
#define THREADINSERT_H

#include <QObject>
#include "queryServer/queryserver.h"
#include "comm/config/cfgsetting.h"
#include "sqlConnect/ConnectionPool.h"
#include "comm/datebaseConnectPool/connectpoolfactory.h"

struct InsertAction{
    //SAPAction 为 1 ，newStroageTaskMapList为空时，把taskStatus由-1更新为0 进入AGV流程
    int SAPAction=0;      //0 无状态 1 执行更新 2 更新完成  3 执行取消  4取消完成
    int pickStation=-1;   //拣选台ID  (0客户端)
    QMap<QString,SAPExcelInfo> StroageTaskMap;
};


class ThreadInsert : public QObject
{
    Q_OBJECT

public:
    explicit ThreadInsert(QObject *parent = nullptr);

    /**********************往数据库 写入 新的 SAPExcelInfo 任务  **********************/
    InsertAction ActionItiem;
    bool insetSAPExcel=true; int upSAPExcelcount=0;
    QMap<QString, SAPExcelInfo> newStroageTaskMap;
    QList<QMap<QString, SAPExcelInfo>>newStroageTaskMapList;
    void setSAPAction(int Action,QMap<QString, SAPExcelInfo>StroageTaskMap,int pickStation);

    bool addSAPExcelInfoTask(SAPExcelInfo SAPExcelInfoI,QString Ikey,int type); //type 1 入库 2 出库

    bool newSAPExcelInfoTask(QMap<QString, SAPExcelInfo> newStroageTaskMap);    //(把创建成功的任务 存入数据库)

    //往本地数据库，添加新的容器信息
    bool insertMaterialShelfbinInfo=true;
    QMap<QString ,materialShelfbin >newMaterialShelfbinMap;                 //物料件号-仓号-批次 作为唯一键值
    QList<QMap<QString, materialShelfbin>>newMaterialShelfbinMapList;
    bool addNewmaterialShelfbinInfo(materialShelfbin materialShelfbinI,int status);//new  胶箱号与物料绑定信息 作为唯一键值
    bool insertIntoNewmaterialShelfbinInfo(QMap<QString ,materialShelfbin >newMaterialShelfbinMap);

    bool insertIntoshelfBinInfoInfo(QMap<QString ,shelfBinInfo >newshelfBinInfoMap);


    /*********************往数据库 写入 出入库公用部分******************/

    //往数据库 写入 每次WS01 SAP 反馈的数据  记录
    bool insertlabelMsgStruct=true;
    QMap<QString ,labelMsgStruct >insertrecord_sapMap;
    QList<QMap<QString, labelMsgStruct>>insertrecord_sapMapList;
    void insertrecord_sap(labelMsgStruct labelMsgStructI);
    void insertIntorecord_sap(QMap<QString ,labelMsgStruct >insertrecord_sapMap);

    //出入库，查仓，记录 数据员改仓
    void insertrecord_log(QMap<QString, record_log>record_logMap,int TypeId);

    //往数据库 写入 异常邮件记录
    void  insertemail_message(email_message email_messageI);


signals:

public slots:
    void ON_threadTimer();

public:
    QTimer *threadTimer;

};

#endif // THREADINSERT_H
