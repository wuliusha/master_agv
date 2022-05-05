#include "setting.h"

setting* setting::pThis = nullptr;
QMutex *setting::mutex = new QMutex(QMutex::Recursive);
setting::setting(QObject *parent) : QObject(parent)
{
    pThis = this;
    initSettingInterface();
}

setting::~setting()
{
}

setting *setting::getInstance()
{
    if(nullptr == pThis)
    {
        QMutexLocker locker(mutex);
        if(pThis == nullptr)
        {
            qDebug("cannot get setting instance without Inherited");
            pThis = new setting();
        }
    }
    return pThis;
}

