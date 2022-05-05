#include "monitoringserver.h"

monitoringServer::monitoringServer(QObject *parent) : QObject(parent)
{
    monitoringI = new monitoring;
}
