#ifndef THREADQUERY_H
#define THREADQUERY_H

#include <QObject>
#include "queryServer/queryserver.h"
#include "sqlConnect/ConnectionPool.h"
#include "comm/datebaseConnectPool/connectpoolfactory.h"

class threadQuery : public QObject
{
    Q_OBJECT
public:
    explicit threadQuery(QObject *parent = nullptr);
public:
    QTimer *threadTimer;
    int threadServercount=0;
    bool Servercountbool=true;
    ServerItem CurrentServerItem;

public slots:
    void threadQueryTimer();

public:


//******************************* SAPExcelInfo  任务状态更新部分*****************************//

    bool setshelfBinInfo_Status(QMap<QString,shelfBinInfo>shelfBinInfoMap);     //更新库位状态信息

    bool setStationInfo_Status(QMap<int,StationInfo>StationInfoMap);            //更新接驳台状态信息

    bool setmaterialShelfbinMap(materialShelfbin materialShelfbinI,QString  actionType);    //更新或删除 绑定信息

    bool setLiftCodeMap_Status(QMap<QString,LiftCode>LiftCodeMap);                          //更新接升降机状态信息

    bool setAGVCurrentTaskMap_Status(QMap<QString,AGVCurrentTask>AGVCurrentTaskMap);        //更新AGV状态信息


//*******************************出入库，查仓日志部分*****************************//

    QMap<int, record_log> queryRecord_log(slecetSAP_Log slecetSAP_LogI);


//**********************************任务查询********************************//

    QMap<int, SAPExcelInfo>querySAPExcelInfoList(slecetSAP_Log slecetSAP_LogI);

    void UP_SAPExcelInfotaskCode(QMap<int, SAPExcelInfo> slecetSAPExcelInfoList);   //更新 ESS-P 当前任务号

    bool UP_SetPrioritySAP(QMap<int, SAPExcelInfo> slecetSAPExcelInfoList);         //设置任务优先级

    bool UP_cancelTaskSAP(QMap<int, SAPExcelInfo> slecetSAPExcelInfoList);          //取消任务

//**********************************库存管理********************************//

    //更新库存盘点信息 如 状态 时间 盘点人
    void upMaterialshelfBinMap_Check(QMap<QString,materialShelfbin>materialShelfbinMap,int type);

    void up_ShelfBinInfo(QMap<int ,shelfBinInfo >shelfBinInfoMap);//更新架位信息表的 仓号 报关类型


public:


};

#endif // THREADQUERY_H
