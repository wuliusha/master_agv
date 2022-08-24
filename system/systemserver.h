#ifndef SYSTEMSERVER_H
#define SYSTEMSERVER_H

#include <QObject>
#include "systemmanage.h"

class systemServer : public QObject
{
    Q_OBJECT
public:
    explicit systemServer(QObject *parent = nullptr);

    systemManage *systemManageI;         //系统管理

signals:

public slots:
};

#endif // SYSTEMSERVER_H
