#include "sqlconnectionpool_2.h"
#include <QDebug>

QMutex SqlConnectionPool_2::mutex_2;
QWaitCondition SqlConnectionPool_2::waitSqlConnection_2;
SqlConnectionPool_2 *SqlConnectionPool_2::instance_2 = nullptr;

SqlConnectionPool_2::SqlConnectionPool_2()
{
    testOnBorrow_2 = true;
    maxWaitTime_2 = 1000;
    waitInterval_2 = 200;
    maxConnectionCount_2 = 1000;
}

SqlConnectionPool_2::~SqlConnectionPool_2()
{
    foreach(QString connectionName,usedConnectionName_2)
    {
        QSqlDatabase::removeDatabase(connectionName);
    }

    foreach(QString connectionName,unusedConnectionName_2)
    {
        QSqlDatabase::removeDatabase(connectionName);
    }
}

QSqlDatabase SqlConnectionPool_2::openSqlConnection_2()
{
    SqlConnectionPool_2 &connection = getInstance_2();
    QString connectionName;
    QMutexLocker locker(&mutex_2);
    int connectionCount = connection.usedConnectionName_2.count() + connection.unusedConnectionName_2.count();

    for(int i=0;i<connection.maxWaitTime_2&&
        connection.unusedConnectionName_2.count()==0&&
        connectionCount==connection.maxConnectionCount_2;i+=connection.waitInterval_2)
    {
        waitSqlConnection_2.wait(&mutex_2,connection.waitInterval_2);
        connectionCount = connection.usedConnectionName_2.count() + connection.unusedConnectionName_2.count();
    }

    if(connection.unusedConnectionName_2.count()>0)
    {
        connectionName = connection.unusedConnectionName_2.dequeue();
    }
    else if(connectionCount<connection.maxConnectionCount_2)
    {
        connectionName = QString("Connect_2-%1").arg(connectionCount + 1);
    }
    else
    {
        return QSqlDatabase();
    }

    QSqlDatabase sqlDatabase = connection.createSqlConnection_2(connectionName);

    if(sqlDatabase.open())
    {
        connection.usedConnectionName_2.enqueue(connectionName);
    }

    return sqlDatabase;
}

void SqlConnectionPool_2::closeSqlConnection_2(QSqlDatabase sqlConnection)
{
    SqlConnectionPool_2 &connection = getInstance_2();
    QString connectionName = sqlConnection.connectionName();

    if(connection.usedConnectionName_2.contains(connectionName))
    {
        QMutexLocker locker(&mutex_2);
        connection.usedConnectionName_2.removeOne(connectionName);
        connection.unusedConnectionName_2.enqueue(connectionName);
        waitSqlConnection_2.wakeOne();
    }
}

void SqlConnectionPool_2::release_2()
{
    QMutexLocker locker(&mutex_2);
    delete instance_2;
    instance_2 = nullptr;
}

SqlConnectionPool_2 &SqlConnectionPool_2::getInstance_2()
{
    if(instance_2 == nullptr)
    {
        QMutexLocker locker(&mutex_2);
        if(instance_2 == nullptr)
        {
            instance_2 = new SqlConnectionPool_2();
        }
    }

    return *instance_2;
}

QSqlDatabase SqlConnectionPool_2::createSqlConnection_2(QString &connectionName)
{
    if(QSqlDatabase::contains(connectionName))
    {
        QSqlDatabase sqlDatbaseOld = QSqlDatabase::database(connectionName);
        if(testOnBorrow_2)
        {
            QSqlQuery sqlQuery("select 1;",sqlDatbaseOld);
            if(sqlQuery.lastError().type()!=QSqlError::NoError&&
                    !sqlDatbaseOld.isOpen())
            {
                return QSqlDatabase();
            }
        }
        return sqlDatbaseOld;
    }

//    QSqlDatabase sqlDatbase = QSqlDatabase::addDatabase("QSQLITE",connectionName);
//    sqlDatbase.setDatabaseName("agv.db");

//    QSqlDatabase sqlDatbase = QSqlDatabase::addDatabase("QODBC",connectionName);
//    sqlDatbase.setDatabaseName(QString("DRIVER={SQL SERVER};"
//                                      "SERVER=%1;"
//                                      "DATABASE=%2;"
//                                      "UID=%3;"
//                                      "PWD=%4;").arg("10.16.208.101")
//                              .arg("TEMP")
//                              .arg("sa")
//                              .arg("123456"));

//    QSqlDatabase sqlDatbase = QSqlDatabase::addDatabase("QMYSQL",connectionName);
//    sqlDatbase.setDatabaseName("AGV");
//    sqlDatbase.setHostName("127.0.0.1");
//    sqlDatbase.setPort(3306);
//    sqlDatbase.setUserName("root");
//    sqlDatbase.setPassword("123456");

//    QSqlDatabase sqlDatbase = QSqlDatabase::addDatabase("QODBC",connectionName);
//    sqlDatbase.setDatabaseName(QString("DRIVER={SQL SERVER};"
//                                      "SERVER=%1;"
//                                      "DATABASE=%2;"
//                                      "UID=%3;"
//                                      "PWD=%4;").arg("ahknts26dev.ahkex.asmpt.com")
//                              .arg("custom")
//                              .arg("custom_agv_read")
//                              .arg("readcustomagv"));

    QSqlDatabase sqlDatbase = QSqlDatabase::addDatabase("QODBC",connectionName);
    sqlDatbase.setDatabaseName(QString("DRIVER={SQL SERVER};"
                                      "SERVER=%1;"
                                      "DATABASE=%2;"
                                      "UID=%3;"
                                      "PWD=%4;").arg("algnts125.algex.asmpt.com")
                              .arg("custom")
                              .arg("custom_agv_read")
                              .arg("customagvr"));

     if(sqlDatbase.open())
    {
        return sqlDatbase;
    }
    else
    {
        return QSqlDatabase();
    }
}
