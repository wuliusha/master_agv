#include "systemserver.h"

systemServer::systemServer(QObject *parent) : QObject(parent)
{
    systemManageI =new systemManage;
}
