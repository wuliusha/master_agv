#ifndef SQLCONNECTIONPOOL_2_H
#define SQLCONNECTIONPOOL_2_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QQueue>
#include <QString>
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>

class SqlConnectionPool_2
{
public:
    SqlConnectionPool_2();

    ~SqlConnectionPool_2();

    static QSqlDatabase openSqlConnection_2();

    static void closeSqlConnection_2(QSqlDatabase sqlConnection);

    static void release_2();

private:
    static SqlConnectionPool_2 &getInstance_2();

    QSqlDatabase createSqlConnection_2(QString &);

    QQueue<QString > usedConnectionName_2;
    QQueue<QString > unusedConnectionName_2;

    bool testOnBorrow_2;

    int maxWaitTime_2;
    int waitInterval_2;
    int maxConnectionCount_2;

    static QMutex mutex_2;
    static QWaitCondition waitSqlConnection_2;
    static SqlConnectionPool_2 *instance_2;
};

#endif // SQLCONNECTIONPOOL_2_H
