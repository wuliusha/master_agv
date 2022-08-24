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

//********************************** MES 业务任务状态 信息更新********************************//

    bool UP_SAPExcelInfotaskCode(QMap<int, SAPExcelInfo> slecetSAPExcelInfoList);   //更新 ESS-P 当前任务号

    bool UP_cancelTaskSAP(QMap<int, SAPExcelInfo> slecetSAPExcelInfoList);          //取消任务

//**********************************库存管理********************************//

    bool setshelfBinInfo_Status(QMap<QString,shelfBinInfo>shelfBinInfoMap,QString type);     //更新库位状态信息



};

#endif // THREADQUERY_H
