#include "connectpoolfactory.h"
#include "comm/config/cfgsetting.h"
#include "comm/datebaseConnectPool/shanghaisearisqlserver.h"
#include "comm/datebaseConnectPool/sqlitedatebasepool.h"
#include "comm/datebaseConnectPool/agvtmpsqlserver.h"
#include "comm/datebaseConnectPool/asmorderdb.h"
#include "comm/datebaseConnectPool/asmorderdb0.h"


ConnectPoolFactory* ConnectPoolFactory::pThis = nullptr;
QMutex *ConnectPoolFactory::getInstanceMutex = new QMutex(QMutex::Recursive);

ConnectPoolFactory::ConnectPoolFactory()
{
    pThis = this;
    QVariant value;
    if(setting::getInstance()->getSettingValueInterface("DATETYPE/flag", value))
    {
        DATETYPE = value.toInt();
    }
}

//ConnectPool *ConnectPoolFactory::getConnectPool(QString databaseType)
//{
//    if(databaseType == "shangHaiSqlServer")
//    {
//        return shangHaiSeariSqlServer::getInstace();
//    }
//    if(databaseType == "sqliteDatebase")
//    {

//    }
//    else
//    {
//        return nullptr;
//    }
//}

ConnectPool *ConnectPoolFactory::getConnectPool(ConnectPoolFactory::connectPoolType type)
{
    switch (type) {
    case shangHaiSqlServer:
    {
        return shangHaiSeariSqlServer::getInstace();
    }
        break;
    case sqliteDatabase:
    {
        return sqliteDatebasePool::getInstace();
    }
        break;
    case agvTmpSqlServer:           //agv中间表
    {
        return AGVTmpSqlServer::getInstace();
    }
        break;
    case AsmOrderDataBase:           //agv中间表
    {
        if(DATETYPE==0){//测试版本
            return ASMOrderDB0::getInstance();
        }
        if(DATETYPE==1){//正式版本
            return ASMOrderDB::getInstance();
        }
        return ASMOrderDB0::getInstance();
    }
        break;
    case AsmOrderDataBase0:           //agv中间表  测试版
    {
        if(DATETYPE==0){//测试版本
            return ASMOrderDB0::getInstance();
        }
        if(DATETYPE==1){//正式版本
            return ASMOrderDB::getInstance();
        }
        return ASMOrderDB0::getInstance();
    }
        break;
    default:
        return nullptr;
        break;
    }
}

ConnectPoolFactory *ConnectPoolFactory::getInstance()
{
//    if(pThis == nullptr)
//    {
//        pThis = new ConnectPoolFactory();
//    }
//    return pThis;
    if(nullptr == pThis)
    {
        QMutexLocker locker(getInstanceMutex);
        if(pThis == nullptr)
        {
            pThis = new ConnectPoolFactory();
        }
    }
    return pThis;
}


connectBuilder::connectBuilder(ConnectPool *poolPtr)
{
    this->poolPtr = poolPtr;

    if(poolPtr != nullptr)
    {
        db = poolPtr->openConnection();
    }
}

connectBuilder::~connectBuilder()
{
    poolPtr->closeConnection(db);
}

QSqlDatabase connectBuilder::getOpenDatabase()
{
    return db;
}

