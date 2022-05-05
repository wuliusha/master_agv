#include "desktopserver.h"

desktopServer::desktopServer(QObject *parent) : QObject(parent)
{
    MainDesktopItiem=new MainDesktop;
}
