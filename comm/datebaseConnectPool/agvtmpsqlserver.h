#ifndef AGVTMPSQLSERVER_H
#define AGVTMPSQLSERVER_H


#include "comm/datebaseConnectPool/connectpool.h"

class AGVTmpSqlServer : public ConnectPool
{
public:
    AGVTmpSqlServer();
    void getDatebaseConnectPara();

    static AGVTmpSqlServer *getInstace();
    static AGVTmpSqlServer *pThis;

    // ConnectPool interface
public:
//    QSqlDatabase openConnection();
    QSqlDatabase createConnection(QString ConnectName);
};
#endif // AGVTMPSQLSERVER_H
