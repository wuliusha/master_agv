#ifndef CONNECTPOOL_H
#define CONNECTPOOL_H

#include <QSqlDatabase>
#include <QQueue>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>

class ConnectPool
{
public:
    ConnectPool();

    typedef struct threadConnectPoolTmp
    {
      QString threadId;
      QQueue<QString> usedConnectNames;
      QQueue<QString> unUseConnectNames;
      QMutex mutex;
      QWaitCondition waitConnection;
      int maxWaitTime;  // 获取连接最大等待时间
      int waitInterval; // 尝试获取连接时等待间隔时间
      int maxConnectionCount; // 最大连接数
      QString testConnect;

      bool operator ==(struct threadConnectPoolTmp &item) const
      {
          return threadId == item.threadId;
      }

      QString getConnectName(QString type)
      {
          QString connectionName;
          // 已创建连接数
          int connectionCount = unUseConnectNames.size() + usedConnectNames.size();

          // 如果连接已经用完，等待 waitInterval 毫秒看看是否有可用连接，最长等待 maxWaitTime 毫秒
          for (int i = 0;
               i < maxWaitTime
               && unUseConnectNames.size() == 0 && connectionCount == maxConnectionCount;
               i += waitInterval) {
              QMutexLocker locker(&mutex);
              waitConnection.wait(&mutex, waitInterval);

              // 重新计算已创建连接数
              connectionCount = unUseConnectNames.size() + usedConnectNames.size();
          }

          if (unUseConnectNames.size() > 0) {
              // 有已经回收的连接，复用它们
              connectionName = unUseConnectNames.dequeue();
          } else if (connectionCount < maxConnectionCount) {
              // 没有已经回收的连接，但是没有达到最大连接数，则创建新的连接
              connectionName = type + "_" + threadId + QString("_Connection-%1").arg(connectionCount + 1);
          } else {
              // 已经达到最大连接数
              qDebug() << "Cannot create more connections.";
              return QString("Max");
          }
          return connectionName;
      }

      void closeConnection(QSqlDatabase connection)
      {
          QString connectionName = connection.connectionName();
          // 如果是我们创建的连接，从 used 里删除，放入 unused 里
          if (usedConnectNames.contains(connectionName)) {
              QMutexLocker locker(&mutex);
              usedConnectNames.removeOne(connectionName);
              unUseConnectNames.enqueue(connectionName);
              waitConnection.wakeOne();
          }
          else
          {
              qDebug() << "connect name is no in this connectQueue"
                       << usedConnectNames
                       << unUseConnectNames
                       << connectionName
                       << "thread id is "
                       << threadId;
          }
      }

      void pushUsedConnect(QString connectName)
      {
          usedConnectNames.enqueue(connectName);
      }
    }threadConnectPool;

    threadConnectPool *getThreadPoolFromList(QString threadIdStr);
    bool threadPoolListContains(QString threadIdStr);

    virtual QSqlDatabase openConnection();
    virtual QSqlDatabase createConnection(QString ConnectName) = 0;
    virtual void closeConnection(QSqlDatabase connection);

protected :
    QQueue<QString> usedConnectNames;
    QQueue<QString> unUseConnectNames;
    QList<threadConnectPool *> threadConnectPoolList;
    QString testConnect;
    QString datebaseName;
    QString hostName;
    QString password;
    quint16 port;
    QString userName;
    static QMutex *mutex;
    QMutex *threadConnectPoolMutex;
    QWaitCondition waitConnection;
    int maxWaitTime;  // 获取连接最大等待时间
    int waitInterval; // 尝试获取连接时等待间隔时间
    int maxConnectionCount; // 最大连接数
    QString type;
};

#endif // CONNECTPOOL_H
