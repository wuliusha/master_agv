#include "connectpool.h"
#include <QDebug>
#include <QThread>

#define LOGD(MSG) qDebug() << MSG

QMutex *ConnectPool::mutex = new QMutex(QMutex::Recursive);

ConnectPool::ConnectPool()
{
    threadConnectPoolMutex = new QMutex(QMutex::Recursive);
    testConnect = "SELECT 1";
    maxWaitTime  = 1000;
    waitInterval = 200;
    maxConnectionCount  = 1000;
    type = "base pool";
}

ConnectPool::threadConnectPool *ConnectPool::getThreadPoolFromList(QString threadIdStr)
{
    QMutexLocker locker(threadConnectPoolMutex);
    for(auto item:threadConnectPoolList)
    {
        if(item->threadId == threadIdStr)
        {
            return item;
        }
    }
    return nullptr;
}

bool ConnectPool::threadPoolListContains(QString threadIdStr)
{
    QMutexLocker locker(threadConnectPoolMutex);
//    qDebug() << "---------------------------";
//    for(auto item : threadConnectPoolList)
//    {
//        qDebug() << "thread connect pool list " << item->threadId;
//    }
//    qDebug() << "---------------------------";
    for(auto item:threadConnectPoolList)
    {
        if(item->threadId == threadIdStr)
        {
            return true;
        }
    }
    return false;
}

QSqlDatabase ConnectPool::openConnection()
{
    QString connectionName;

    QMutexLocker locker(mutex);

    QString threadIdStr = QStringLiteral("@0x%1").arg(quintptr(QThread::currentThreadId()), 16, 16, QLatin1Char('0'));
//    LOGD("current thread id is " + threadIdStr);

    if(!threadPoolListContains(threadIdStr))
    {
        threadConnectPool *item = new threadConnectPool();
        item->threadId = threadIdStr;
        item->unUseConnectNames.clear();
        item->usedConnectNames.clear();
        item->testConnect = "SELECT 1";
        item->maxWaitTime  = maxWaitTime;
        item->waitInterval = waitInterval;
        item->maxConnectionCount  = maxConnectionCount;

        threadConnectPoolList.append(item);
    }
    threadConnectPool *poolItem = getThreadPoolFromList(threadIdStr);
    if(poolItem == nullptr)
    {
        LOGD("thread Connect pool get " + threadIdStr + "is nullptr");
        return QSqlDatabase();
    }
    connectionName = poolItem->getConnectName(type);
    if(connectionName == "Max")
    {
        // 已经达到最大连接数
        qDebug() << "Cannot create more connections.";
        return QSqlDatabase();
    }

    // 创建连接
    QSqlDatabase db = createConnection(connectionName);

    // 有效的连接才放入 usedConnectionNames
    if (db.isOpen()) {
//        usedConnectNames.enqueue(connectionName);
        poolItem->pushUsedConnect(connectionName);
    }

    return db;
}

void ConnectPool::closeConnection(QSqlDatabase connection)
{
    QMutexLocker locker(mutex);
    QString threadIdStr = QStringLiteral("@0x%1").arg(quintptr(QThread::currentThreadId()), 16, 16, QLatin1Char('0'));

    if(!threadPoolListContains(threadIdStr))
    {
        connection.close();
        QSqlDatabase::removeDatabase(connection.connectionName());
        LOGD("close connect error, connect thread is no in pool");
       return;
    }
    threadConnectPool *poolItem = getThreadPoolFromList(threadIdStr);
    if(poolItem == nullptr)
    {
        LOGD("thread Connect pool get " + threadIdStr + "is nullptr");
        return;
    }
    poolItem->closeConnection(connection);
}

