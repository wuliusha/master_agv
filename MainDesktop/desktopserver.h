#ifndef DESKTOPSERVER_H
#define DESKTOPSERVER_H

#include <QObject>
#include "maindesktop.h"

class desktopServer : public QObject
{
    Q_OBJECT
public:
    explicit desktopServer(QObject *parent = nullptr);
    MainDesktop *MainDesktopItiem;   //主页

signals:

public slots:
};

#endif // DESKTOPSERVER_H
