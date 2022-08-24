#ifndef MANAGERSERVER_H
#define MANAGERSERVER_H

#include <QObject>
#include "devicemanage.h"

class managerServer : public QObject
{
    Q_OBJECT
public:
    explicit managerServer(QObject *parent = nullptr);

    DeviceManage *DeviceManageItem;         //设备管理


signals:

public slots:
};

#endif // MANAGERSERVER_H
