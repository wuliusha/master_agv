#include "storeinfoserver.h"

storeInfoServer::storeInfoServer(QObject *parent) : QObject(parent)
{
    StoreInfoItem=new StoreInfo;
}
