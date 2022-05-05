#ifndef TRANSFORMARRAY_H
#define TRANSFORMARRAY_H

#include <QObject>
#include <QtCore>
#include <QtGui>
#include<QToolButton>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#include<QMouseEvent>
#endif


#include "queryServer/queryserver.h"
#include "httpserver/httpconnection.h"
#include "singleProject/single_project.h"


class transFormArray : public QObject
{
    Q_OBJECT
public:
    static QMutex mutex;
    static transFormArray* transFormArrayItiem;

    static transFormArray *GetInstance();
    explicit transFormArray(QObject *parent = 0);

public:
    QMap<QString,QString>analysDescMap;        //类型定义注释

    int ServerItemcount=100;
    ServerItem CurrentServerItem;
    QMap<int, SAPExcelInfo>AdvaceSAPExcelInfoTask;     //待出库任务  任务状态==15可提前出库
    QMap<int, SAPExcelInfo>deleteSAPExcelInfoTask;     //待删除任务  任务状态==0可删除
    QMap<int, SAPExcelInfo>AGVRunSAPExcelInfoTask;     //放行
    QMap<int, SAPExcelInfo>changeSAPExcelInfoTask;     //更改任务库位信息

    QMap<int, SAPExcelInfo>newSAPExcelInfoTask;
    QMap<int, shelfBinInfo> shelfBinInfoMap_clesr;

    QMap<int ,shelfBinInfo >currentShelfBinInfoMap;  //实时获取 Bin 的基础信息

    void setServerItemcount(int Itemcount);

    void setCurrentServerItem(ServerItem CServerItem);

    ServerItem getCurrentServerItem();

    void setShelfBinInfoMapInit(QMap<int ,shelfBinInfo >shelfBinInfoMap);

    QByteArray AGVCurrentAnalysisArray;
    //void setAGVCurrentTaskInfo(QMap<QString,AGVCurrentTask>AGVCurrentTaskMap_1,int AGVChargeAction_all);
    QByteArray getAGVCurrentTaskInfo();

    //获取当前库位空闲位置
    shelfBinInfo getShelfBin_Emty(QString keyId,QString storage_Site,QString storage_Area);

    //判断当前库位是否存在并可用
    shelfBinInfo getShelfBin_Emty_(QString storage_Site,QString storage_Area);


    void setShelfBin_Info(QMap<int, shelfBinInfo>shelfBinInfoMap);

    bool getTaskType_Emty(SAPExcelInfo SAPExcelInfoI);//判断当前空料框任务是否重复


    /*************  Client 平板返回的数据 或指令   *******************/
    ReplyJson newSAPExcelInfoTask_Process(QString ClientIP,QByteArray AnalysisArray,ReplyJson ReplyJsonI);// new SAP

    QMap<int, SAPExcelInfo>getNewSAPExcelInfoTask();

    QMap<int, SAPExcelInfo>getdeleteSAPExcelInfoTask();

    QMap<int, SAPExcelInfo>getAdvaceSAPExcelInfoTask();

    QMap<int, SAPExcelInfo>getAGVRunSAPExcelInfoTask();

    QMap<int, shelfBinInfo> getshelfBinInfoMap_clesr();

    QMap<int, SAPExcelInfo>getchangeSAPExcelInfoTask();


    int getSAPTaskIndex();


    /************* User_transFor ************/
    QByteArray User_transFor_Array(QString taskType,QMap<QString,User_Info>UserInfoListMap);

    /************* sapPath ************/
    QByteArray sapPath_transFor_Array(QString taskType,QMap<int ,sapPath >sapPathMap);


    /************* shelfBinInfo ************/
    QByteArray shelfBin_transFor_Array(QString taskType,QMap<int ,shelfBinInfo >shelfBinInfoMap);

    /************* SAP_transFor ************/
    QByteArray SAP_transFor_Array(QString taskType,QMap<int, SAPExcelInfo> currentSAPExcelInfoTask);

    ReplyJson SAP_transFor_SAPExcelInfo(QString taskType,QJsonArray rootFruitList,QJsonValue value,ReplyJson ReplyJsonI);

    ReplyJson AdvaceSAP_transFor(QString taskType,QJsonArray rootFruitList,QJsonValue value,ReplyJson ReplyJsonI);

    ReplyJson deleteSAP_transFor(QString taskType,QJsonArray rootFruitList,QJsonValue value,ReplyJson ReplyJsonI);

    //放行
    ReplyJson AGVRunSAP_transFor(QString taskType,QJsonArray rootFruitList,QJsonValue value,ReplyJson ReplyJsonI);

    //清除当前库位信息
    ReplyJson AreaClearSAP_transFor(QString taskType,QJsonArray rootFruitList,QJsonValue value,ReplyJson ReplyJsonI);


    ReplyJson changeSAP_transFor(QString taskType,QJsonArray rootFruitList,QJsonValue value,ReplyJson ReplyJsonI);



signals:

public slots:


};

#endif // TRANSFORMARRAY_H
