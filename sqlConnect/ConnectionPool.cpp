#include "ConnectionPool.h"

class ConnectionPoolPrivate{
public:
    ConnectionPoolPrivate();
    ~ConnectionPoolPrivate();
    QStack<QString> usedConnectionNames;  //已使用的数据库连接
    QStack<QString> unUsedConnectionNames;  //未使用的数据库连接
    QString hostName;
    QString databaseName;
    QString dataType;
    int port;
    bool testOnBorrow;
    QString testOnBorrowSql;
    int maxWaitTime;
    int maxConnectionCount;
    QSemaphore *semaphore;
    static QMutex mutex;
    static int lastKey;
    static QMutex releaseMutex;
};

QMutex ConnectionPoolPrivate::mutex;
QMutex ConnectionPoolPrivate::releaseMutex;
int ConnectionPoolPrivate::lastKey = 0;
ConnectionPoolPrivate::ConnectionPoolPrivate(){
    hostName = "127.0.0.1";
    //databaseName ="assets/database/agv.db";
    databaseName ="agv.db";
    dataType = "QSQLITE";
    port = 3306;
    testOnBorrow = true;
    testOnBorrowSql = "select 1";
    maxWaitTime = 3000;
    maxConnectionCount = 5;
    semaphore = new QSemaphore(maxConnectionCount);
    qDebug()<<"最大连接数 "<<maxConnectionCount<< " 最大等待时长 "<<maxWaitTime;
    semaphore = new QSemaphore(maxConnectionCount);
    qDebug()<<"最大连接数 "<<maxConnectionCount<< " 最大等待时长 "<<maxWaitTime;
}

ConnectionPoolPrivate::~ConnectionPoolPrivate()
{
    foreach (QString connenctName, usedConnectionNames) {
        QSqlDatabase::removeDatabase(connenctName);
    }
    foreach (QString connenctName, unUsedConnectionNames) {
        QSqlDatabase::removeDatabase(connenctName);
    }
    delete semaphore;
}

ConnectionPool::ConnectionPool():data(new ConnectionPoolPrivate)
{

}

ConnectionPool::~ConnectionPool()
{
//    delete data;
}

QSqlDatabase ConnectionPool::createConnection(const QString &connectName)
{
    Q_ASSERT(nullptr != data);
    if(QSqlDatabase::contains(connectName)){
        QSqlDatabase existDb = QSqlDatabase::database(connectName);
        if(data->testOnBorrow){
//            qDebug() << QString("Test connection on borrow, execute: %1, for connection %2")
//                        .arg(data->testOnBorrowSql).arg(connectName);
            QSqlQuery query(data->testOnBorrowSql,existDb);
            if(query.lastError().type() != QSqlError::NoError && !existDb.open()){
                qDebug() << "Open datatabase error:" <<existDb.lastError().text();
                return QSqlDatabase();
            }
        }
        return existDb;
    }else
    qDebug()<<"###不包含连接### "<<connectName;
    QSqlDatabase newDb = QSqlDatabase::addDatabase(data->dataType,connectName);
    newDb.setDatabaseName(data->databaseName);
    newDb.setConnectOptions("QSQLITE_BUSY_TIMEOUT=1000");
    if (!newDb.open()) {
        qDebug() << "Open datatabase error:" << newDb.lastError().text();
        return QSqlDatabase();
    }
    qDebug()<<"new create connnection "<<connectName;
    return newDb;
}

bool ConnectionPool::copyQrcFile(const QString &from, const QString &to)
{
    QFile fileFrom(from);
    QFile fileTo(to);
    if(!fileFrom.open(QIODevice::ReadOnly)){
        qDebug()<<"read failed: from:"<<from;
        return false;
    }

    if(!fileTo.open(QIODevice::WriteOnly)){
        qDebug()<<"write failed: to:"<<to;
        return false;
    }
    fileTo.write(fileFrom.readAll());
    return true;
}

QSqlDatabase ConnectionPool::getConnection()
{
    Q_ASSERT(nullptr != data);
//    qDebug()<<"剩余信号量： "<<data->semaphore->available();
    if(data->semaphore->tryAcquire(1,data->maxWaitTime)){
        // 有已经回收的连接，复用它们
        // 没有已经回收的连接，则创建新的连接
        ConnectionPoolPrivate::mutex.lock();
        QString connectionName = data->unUsedConnectionNames.size() > 0  \
                ? data->unUsedConnectionNames.pop() \
                : QString("C%1").arg(++ConnectionPoolPrivate::lastKey);
        data->usedConnectionNames.push(connectionName);
        ConnectionPoolPrivate::mutex.unlock();

        //创建连接比较耗时，不放在lock范围内以提高并发效率
        QSqlDatabase db = createConnection(connectionName);
        if(!db.isOpen()){
            ConnectionPoolPrivate::mutex.lock();
            qDebug()<<connectionName<<" Connection is unused";
            data->usedConnectionNames.removeOne(connectionName);
            data->unUsedConnectionNames.push(connectionName);
            ConnectionPoolPrivate::mutex.unlock();
            return QSqlDatabase();
        }
        data->semaphore->release(1);
//        ConnectionPoolPrivate::mutex.unlock();
        return db;
    }
    // 创建连接超时，返回一个无效连接
    qDebug() << "Time out to create connection.";
//    ConnectionPoolPrivate::mutex.unlock();
    return QSqlDatabase();

}

void ConnectionPool::releaseConnection(const QSqlDatabase &connection)
{
    ConnectionPoolPrivate::mutex.lock();
    Q_ASSERT(nullptr != data);
//    qDebug()<<connection.connectionName()<<"连接释放，剩余信号量： "<<data->semaphore->available();
    QString connectName = connection.connectionName();
    if(data->usedConnectionNames.contains(connectName)){
        data->usedConnectionNames.removeOne(connectName);
        data->unUsedConnectionNames.push(connectName);
    }
//    qDebug()<<"已经使用的连接有： "<<data->usedConnectionNames;
//    qDebug()<<"未使用的连接有： "<<data->unUsedConnectionNames;
    ConnectionPoolPrivate::mutex.unlock();

}

void ConnectionPool::destoryConnectionPool()
{
    Q_ASSERT(nullptr != data);
    if(nullptr != data){
        ConnectionPoolPrivate::mutex.lock();
        delete data;
        data = nullptr;
        ConnectionPoolPrivate::mutex.unlock();
    }
}

//void ConnectionPool::addLock()
//{
//    ConnectionPoolPrivate::mutex.lock();
//}

//void ConnectionPool::unLock()
//{
//    ConnectionPoolPrivate::mutex.unlock();
//}

QSqlQuery ConnectionPool::queryByString(QString querySql)
{
    //sqlite 可以多读1写，因此select等查询可以不同上锁
    QSqlDatabase db = getConnection();
    if(db.connectionName().isEmpty()){
        qDebug()<<"获取数据库连接失败";
    }
    QSqlQuery query(db);
    query.exec(querySql);
    return query;
}

bool ConnectionPool::updataByString(QString updata)
{
    //更新数据需要对数据库进行写，需要加锁
    ConnectionPoolPrivate::mutex.lock();
    QSqlDatabase db = getConnection();
    if(db.connectionName().isEmpty()){
        qDebug()<<"获取数据库连接失败";
    }
    QSqlQuery query(db);
    bool status = query.exec(updata);
    ConnectionPoolPrivate::mutex.unlock();
    return status;
}







