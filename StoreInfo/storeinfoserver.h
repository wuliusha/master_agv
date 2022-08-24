#ifndef STOREINFOSERVER_H
#define STOREINFOSERVER_H

#include <QObject>
#include "storeinfo.h"

class storeInfoServer : public QObject
{
    Q_OBJECT
public:
    explicit storeInfoServer(QObject *parent = nullptr);


signals:

public slots:
};

#endif // STOREINFOSERVER_H
