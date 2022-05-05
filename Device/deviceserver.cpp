#include "deviceserver.h"

deviceServer::deviceServer(QObject *parent) : QObject(parent)
{
    DeviceManageItem =new DeviceManage;
}
