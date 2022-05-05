#ifndef SHANGHAISEARISQLSERVER_H
#define SHANGHAISEARISQLSERVER_H

#include "comm/datebaseConnectPool/connectpool.h"

class shangHaiSeariSqlServer : public ConnectPool
{
public:
    shangHaiSeariSqlServer();
    void getDatebaseConnectPara();

    static shangHaiSeariSqlServer *getInstace();
    static shangHaiSeariSqlServer *pThis;

    // ConnectPool interface
public:
//    QSqlDatabase openConnection();
    QSqlDatabase createConnection(QString ConnectName);
//    void closeConnection(QSqlDatabase connection);
};

#endif // SHANGHAISEARISQLSERVER_H
