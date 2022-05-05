#include "shanghaisearisqlserver.h"
#include <QVariant>
#include "comm/config/cfgsetting.h"
#include "comm/codeDecode/simplecrypt.h"
#include <QSqlError>
#include <QMutex>
#include <QMutexLocker>
#include <QSqlQuery>
#include <QThread>

#define LOGD(MSG) qDebug() << MSG

shangHaiSeariSqlServer *shangHaiSeariSqlServer::pThis = nullptr;

shangHaiSeariSqlServer::shangHaiSeariSqlServer()
{
    pThis = this;
    getDatebaseConnectPara();
    testConnect = "SELECT 1";
    maxWaitTime  = 1000;
    waitInterval = 200;
    maxConnectionCount  = 1000;
    type = "shangHaiSeariSqlserver";
}

shangHaiSeariSqlServer *shangHaiSeariSqlServer::getInstace()
{
    if (nullptr == pThis) {
        QMutexLocker locker(mutex);
        if (pThis == nullptr) {
            pThis = new shangHaiSeariSqlServer();
        }
    }
    return pThis;
}

void shangHaiSeariSqlServer::getDatebaseConnectPara()
{
    bool isOk = false;
    QVariant value;
    //hostName
    if(setting::getInstance()->getSettingValueInterface("TaskDataBase/DataBaseHost", value))
    {
        hostName = value.toString();
    }
    else
    {
        LOGD("get TaskDataBase DataBaseHost error");
        hostName = "127.0.0.1";
    }
    //dbName
    if(setting::getInstance()->getSettingValueInterface("TaskDataBase/DataBaseName", value))
    {
        datebaseName = value.toString();
    }
    else
    {
        LOGD("get TaskDataBase DataBaseName error");
        datebaseName = "AGV_RCS";
    }
    //uid
    if(setting::getInstance()->getSettingValueInterface("TaskDataBase/DataBaseUseName", value))
    {
        userName = value.toString();
        SimpleCrypt crypt(decodeKey);
        userName = crypt.decryptToString(userName);
    }
    else
    {
        LOGD("get TaskDataBase DataBaseUseName error");
        userName = "sa";
    }
    //pwd
    if(setting::getInstance()->getSettingValueInterface("TaskDataBase/DataBasePassword", value))
    {
        password = value.toString();
        SimpleCrypt crypt(decodeKey);
        password = crypt.decryptToString(password);
    }
    else
    {
        LOGD("get TaskDataBase DataBasePassword error");
        password = "123456";
    }
}

//QSqlDatabase shangHaiSeariSqlServer::openConnection()
//{
//    QString connectionName;

//    QMutexLocker locker(&mutex);

//    // 已创建连接数
//    int connectionCount = unUseConnectNames.size() + usedConnectNames.size();

//    // 如果连接已经用完，等待 waitInterval 毫秒看看是否有可用连接，最长等待 maxWaitTime 毫秒
//    for (int i = 0;
//         i < maxWaitTime
//         && unUseConnectNames.size() == 0 && connectionCount == maxConnectionCount;
//         i += waitInterval) {
//        waitConnection.wait(&mutex, waitInterval);

//        // 重新计算已创建连接数
//        connectionCount = unUseConnectNames.size() + usedConnectNames.size();
//    }

//    if (unUseConnectName.size() > 0) {
//        // 有已经回收的连接，复用它们
//        connectionName = unUseConnectNames.dequeue();
//    } else if (connectionCount < maxConnectionCount) {
//        // 没有已经回收的连接，但是没有达到最大连接数，则创建新的连接
//        connectionName = QString("Connection-%1").arg(connectionCount + 1);
//    } else {
//        // 已经达到最大连接数
//        qDebug() << "Cannot create more connections.";
//        return QSqlDatabase();
//    }

//    // 创建连接
//    QSqlDatabase db = createConnection(connectionName);

//    // 有效的连接才放入 usedConnectionNames
//    if (db.isOpen()) {
//        usedConnectNames.enqueue(connectionName);
//    }

//    return db;
//}

QSqlDatabase shangHaiSeariSqlServer::createConnection(QString ConnectName)
{
//    qDebug() << "shangHaiSeariSqlServer thread id is " << QStringLiteral("@0x%1").arg(quintptr(QThread::currentThreadId()), 16, 16, QLatin1Char('0'));
//    qDebug() << "sql connection is build " << type << threadConnectPoolList.size();
//    for(int i = 0; i < threadConnectPoolList.size(); i++)
//    {
//        qDebug() << "threadConnectPoolList regist size " << threadConnectPoolList.at(i)->threadId
//                 << threadConnectPoolList.at(i)->unUseConnectNames.size()
//                    + threadConnectPoolList.at(i)->usedConnectNames.size();
//    }
    if(QSqlDatabase::contains(ConnectName))
    {
        QSqlDatabase db =  QSqlDatabase::database(ConnectName);

        // 返回连接前访问数据库，如果连接断开，重新建立连接
        QSqlQuery query(db);
        query.exec(testConnect);

        if (query.lastError().type() != QSqlError::NoError && db.open()) {
            qDebug() << "Open datatabase error:" << db.lastError().text();
            return QSqlDatabase();
        }
        return db;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", ConnectName);
    db.setDatabaseName(QString("DRIVER={SQL SERVER};"
                               "SERVER=%1;"
                               "DATABASE=%2;"
                               "UID=%3;"
                               "PWD=%4;").arg(hostName)
                       .arg(datebaseName)
                       .arg(userName)
                       .arg(password));

    if (!db.open()) {
        qDebug() << "Open datatabase error:" << db.lastError().text();
        return QSqlDatabase();
    }
    return db;
}

//void shangHaiSeariSqlServer::closeConnection(QSqlDatabase connection)
//{
//    QString connectionName = connection.connectionName();

//    // 如果是我们创建的连接，从 used 里删除，放入 unused 里
//    if (usedConnectNames.contains(connectionName)) {
//        QMutexLocker locker(&mutex);
//        usedConnectNames.removeOne(connectionName);
//        unUseConnectNames.enqueue(connectionName);
//        waitConnection.wakeOne();
//    }
//}
