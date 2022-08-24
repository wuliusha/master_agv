#ifndef MONITORINGSERVER_H
#define MONITORINGSERVER_H

#include <QObject>
#include "monitoring.h"

class monitoringServer : public QObject
{
    Q_OBJECT
public:
    explicit monitoringServer(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MONITORINGSERVER_H
