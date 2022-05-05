#ifndef CONNECTPOOLFACTORY_H
#define CONNECTPOOLFACTORY_H

#include "comm/datebaseConnectPool/connectpool.h"


class ConnectPoolFactory
{
public:
    ConnectPoolFactory();
    int DATETYPE=0;
    typedef enum
    {
        shangHaiSqlServer,
        agvTmpSqlServer,            //agv中间表
        sqliteDatabase,
        AsmOrderDataBase,         //龙岗先进数据库   正式版
        AsmOrderDataBase0,         //龙岗先进数据库  测试版
    }connectPoolType;
//  ConnectPool *getConnectPool(QString databaseType);
    ConnectPool *getConnectPool(connectPoolType type);


private:
    static ConnectPoolFactory *pThis;
    static QMutex *getInstanceMutex;
public:
    static ConnectPoolFactory *getInstance();
};


class connectBuilder{
public:
    connectBuilder(ConnectPool *poolPtr);
    ~connectBuilder();

    QSqlDatabase getOpenDatabase();
private:
    QSqlDatabase db;
    ConnectPool *poolPtr;

};

#endif // CONNECTPOOLFACTORY_H
