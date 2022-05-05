#include "sqlconnectionpool.h"
#include <QDebug>

QMutex SqlConnectionPool::mutex;
QWaitCondition SqlConnectionPool::waitSqlConnection;
SqlConnectionPool *SqlConnectionPool::instance = nullptr;

SqlConnectionPool::SqlConnectionPool()
{
    testOnBorrow = true;
    maxWaitTime = 1000;
    waitInterval = 200;
    maxConnectionCount = 1000;
}

SqlConnectionPool::~SqlConnectionPool()
{
    foreach(QString connectionName,usedConnectionName)
    {
        QSqlDatabase::removeDatabase(connectionName);
    }

    foreach(QString connectionName,unusedConnectionName)
    {
        QSqlDatabase::removeDatabase(connectionName);
    }
}

QSqlDatabase SqlConnectionPool::openSqlConnection()
{
    SqlConnectionPool &connection = getInstance();
    QString connectionName;
    QMutexLocker locker(&mutex);
    int connectionCount = connection.usedConnectionName.count() + connection.unusedConnectionName.count();

    for(int i=0;i<connection.maxWaitTime&&
        connection.unusedConnectionName.count()==0&&
        connectionCount==connection.maxConnectionCount;i+=connection.waitInterval)
    {
        waitSqlConnection.wait(&mutex,connection.waitInterval);
        connectionCount = connection.usedConnectionName.count() + connection.unusedConnectionName.count();
    }

    if(connection.unusedConnectionName.count()>0)
    {
        connectionName = connection.unusedConnectionName.dequeue();
    }
    else if(connectionCount<connection.maxConnectionCount)
    {
        connectionName = QString("Connect-%1").arg(connectionCount + 1);
    }
    else
    {
        return QSqlDatabase();
    }

    QSqlDatabase sqlDatabase = connection.createSqlConnection(connectionName);

    if(sqlDatabase.open())
    {
        connection.usedConnectionName.enqueue(connectionName);
    }

    return sqlDatabase;
}

void SqlConnectionPool::closeSqlConnection(QSqlDatabase sqlConnection)
{
    SqlConnectionPool &connection = getInstance();
    QString connectionName = sqlConnection.connectionName();

    if(connection.usedConnectionName.contains(connectionName))
    {
        QMutexLocker locker(&mutex);
        connection.usedConnectionName.removeOne(connectionName);
        connection.unusedConnectionName.enqueue(connectionName);
        waitSqlConnection.wakeOne();
    }
}

void SqlConnectionPool::release()
{
    QMutexLocker locker(&mutex);
    delete instance;
    instance = nullptr;
}

SqlConnectionPool &SqlConnectionPool::getInstance()
{
    if(instance == nullptr)
    {
        QMutexLocker locker(&mutex);
        if(instance == nullptr)
        {
            instance = new SqlConnectionPool();
        }
    }

    return *instance;
}

QSqlDatabase SqlConnectionPool::createSqlConnection(QString &connectionName)
{
    if(QSqlDatabase::contains(connectionName))
    {
        QSqlDatabase sqlDatbaseOld = QSqlDatabase::database(connectionName);
        if(testOnBorrow)
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
//    sqlDatbase.setDatabaseName("NewAGV.db");

    //SQL server oracle  QORACLE QODBC BULK
    //QSQLITE QMYSQL QMYSQL3 QODBC QODBC3 QPSQL QPSQL7
    QSqlDatabase sqlDatbase = QSqlDatabase::addDatabase("QODBC",connectionName);
    sqlDatbase.setDatabaseName(QString("DRIVER={SQL SERVER};"
                                      "SERVER=%1;"
                                      "DATABASE=%2;"
                                      "UID=%3;"
                                      "PWD=%4;").arg("10.16.208.148")
                              .arg("ASM_AGV")
                              .arg("sa")
                              .arg("123456"));

      //QMYSQL
//    QSqlDatabase sqlDatbase = QSqlDatabase::addDatabase("QMYSQL",connectionName);
//    sqlDatbase.setDatabaseName("ASM_AGV");
//    sqlDatbase.setHostName("127.0.0.1");
//    sqlDatbase.setPort(3306);
//    sqlDatbase.setUserName("root");
//    sqlDatbase.setPassword("123456");

    if(sqlDatbase.open())
    {
        return sqlDatbase;
    }
    else
    {
        return QSqlDatabase();
    }
}
