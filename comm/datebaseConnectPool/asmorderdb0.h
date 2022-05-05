#ifndef ASMORDERDB0_H
#define ASMORDERDB0_H


#include <QObject>
#include "connectpool.h"
#include "comm/getinstancedefine/getinstancedefine.h"

class ASMOrderDB0 : public ConnectPool
{
private:
    ASMOrderDB0();
public:
    REGISTERGETINSTANCE(ASMOrderDB0)
    void getDatebaseConnectPara();

//    static ASMOrderDB *getInstace();
//    static ASMOrderDB *pThis;

    // ConnectPool interface
public:
//    QSqlDatabase openConnection();
    QSqlDatabase createConnection(QString ConnectName);
};


#endif // ASMORDERDB0_H
