#include "managerserver.h"

managerServer::managerServer(QObject *parent) : QObject(parent)
{
    DeviceManageItem =new DeviceManage;
}
