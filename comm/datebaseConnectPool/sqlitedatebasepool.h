#ifndef SQLITEDATEBASEPOOL_H
#define SQLITEDATEBASEPOOL_H

#include "comm/datebaseConnectPool/connectpool.h"

class sqliteDatebasePool : public ConnectPool
{
public:
    sqliteDatebasePool();

    void getDatebaseConnectPara();

    static sqliteDatebasePool *getInstace();
    static sqliteDatebasePool *pThis;

    // ConnectPool interface
public:
    QSqlDatabase createConnection(QString ConnectName);
};

#endif // SQLITEDATEBASEPOOL_H
