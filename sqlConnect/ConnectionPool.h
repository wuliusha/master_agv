#ifndef CONNECTIONPOOL_H
#define CONNECTIONPOOL_H

#include <QStack>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMutex>
#include <QSemaphore>
#include <QDebug>
#include <QtWidgets/QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include<QFile>
#include <QTime>
#include "Singleton.h"
class ConnectionPoolPrivate;

class ConnectionPool
{
    SINGLETON(ConnectionPool)

public:

        /** 拷贝qrc中的文件
         * @brief SCTcpToolWidget::copyQrcFile
         */
    bool copyQrcFile(const QString &from, const QString &to);

    QSqlDatabase getConnection();  //获取连接
    void releaseConnection(const QSqlDatabase &connection); //释放连接
    void destoryConnectionPool(); //关闭连接
//    void addLock();               //添加锁，通过加锁避免不同线程同时操作数据库
//    void unLock();                //解锁
    QSqlQuery queryByString(QString querySql);    //多线程限制，将所有的query查询放到与QSqlDatabase同一线程中
    bool updataByString(QString updata);     //更新数据
private:
    QSqlDatabase createConnection(const QString &connectName);
    ConnectionPoolPrivate *data;

};

#endif // CONNECTIONPOOL_H
