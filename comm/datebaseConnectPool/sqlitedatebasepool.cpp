#include "sqlitedatebasepool.h"
#include "comm/config/cfgsetting.h"
#include <QSqlQuery>
#include <QSqlError>

#define LOGD(MSG) qDebug() << MSG

sqliteDatebasePool * sqliteDatebasePool::pThis = nullptr;

sqliteDatebasePool::sqliteDatebasePool()
{
    pThis = this;
    getDatebaseConnectPara();
    type = "sqliteDatebasePool";
}

void sqliteDatebasePool::getDatebaseConnectPara()
{
    QVariant datebasePath;
    if(setting::getInstance()->getSettingValueInterface("DataBase/DataBaseName", datebasePath))
    {
        datebaseName = datebasePath.toString();
    }
    else
    {
        LOGD("error: get database name for defalutSetting");
//        return false;
    }
}

sqliteDatebasePool *sqliteDatebasePool::getInstace()
{
    if (nullptr == pThis) {
        QMutexLocker locker(mutex);
        if (pThis == nullptr) {
            pThis = new sqliteDatebasePool();
        }
    }
    return pThis;
}

QSqlDatabase sqliteDatebasePool::createConnection(QString ConnectName)
{
    QSqlDatabase db;
    if(QSqlDatabase::contains(ConnectName))
    {
        db =  QSqlDatabase::database(ConnectName);


        // 返回连接前访问数据库，如果连接断开，重新建立连接
        QSqlQuery query(testConnect, db);

        if (query.lastError().type() != QSqlError::NoError && db.open()) {
            qDebug() << "Open datatabase error:" << db.lastError().text();
            return QSqlDatabase();
        }
        return db;
    }

//    db = QSqlDatabase::addDatabase("QODBC", ConnectName);
//    db.setDatabaseName(QString("DRIVER={SQL SERVER};"
//                               "SERVER=%1;"
//                               "DATABASE=%2;"
//                               "UID=%3;"
//                               "PWD=%4;").arg(hostName)
//                       .arg(datebaseName)
//                       .arg(userName)
//                       .arg(password));

    db = QSqlDatabase::addDatabase("QSQLITE", ConnectName);
    db.setDatabaseName(datebaseName);

    if (!db.open()) {
        qDebug() << "Open datatabase error:" << db.lastError().text();
        return QSqlDatabase();
    }
    return db;
}
