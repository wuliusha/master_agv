#ifndef DEVICESERVER_H
#define DEVICESERVER_H

#include <QObject>
#include "devicemanage.h"

class deviceServer : public QObject
{
    Q_OBJECT
public:
    explicit deviceServer(QObject *parent = nullptr);
    DeviceManage *DeviceManageItem;         //设备管理

signals:

public slots:
};

#endif // DEVICESERVER_H
