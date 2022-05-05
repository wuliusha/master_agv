#ifndef ASMORDERDB_H
#define ASMORDERDB_H

#include <QObject>
#include "connectpool.h"
#include "comm/getinstancedefine/getinstancedefine.h"

class ASMOrderDB : public ConnectPool
{
private:
    ASMOrderDB();
public:
    REGISTERGETINSTANCE(ASMOrderDB)
    void getDatebaseConnectPara();

//    static ASMOrderDB *getInstace();
//    static ASMOrderDB *pThis;

    // ConnectPool interface
public:
//    QSqlDatabase openConnection();
    QSqlDatabase createConnection(QString ConnectName);
};

#endif // ASMORDERDB_H
