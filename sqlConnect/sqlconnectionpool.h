#ifndef SQLCONNECTIONPOOL_H
#define SQLCONNECTIONPOOL_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QQueue>
#include <QString>
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>

struct DeviceArray
{
    QString DeviceIP;//设备IP
    QByteArray Query_ByteArray;
    QList<QByteArray>Send_ByteArrayList;//当前需要发送
};


class SqlConnectionPool
{
public:
    SqlConnectionPool();

    ~SqlConnectionPool();

    static QSqlDatabase openSqlConnection();

    static void closeSqlConnection(QSqlDatabase sqlConnection);

    static void release();

private:
    static SqlConnectionPool &getInstance();

    QSqlDatabase createSqlConnection(QString &);

    QQueue<QString > usedConnectionName;
    QQueue<QString > unusedConnectionName;

    bool testOnBorrow;

    int maxWaitTime;
    int waitInterval;
    int maxConnectionCount;

    static QMutex mutex;
    static QWaitCondition waitSqlConnection;
    static SqlConnectionPool *instance;
};

#endif // SQLCONNECTIONPOOL_H
