#ifndef GETINSTANCEDEFINE_H
#define GETINSTANCEDEFINE_H

#include <QMutex>

///////////////////////////////////////////////注册
#define REGISTERGETINSTANCE(CLASS_NAME)     \
    private:                                \
    static CLASS_NAME *pThis;               \
    static QMutex *getInstaceMutex;         \
    public:                                 \
    static CLASS_NAME *getInstance(){       \
        QMutexLocker locker(getInstaceMutex);  \
        if(pThis == nullptr){                   \
            pThis = new CLASS_NAME();           \
            }                                   \
        return pThis;                           \
    }


///////////////////////////////////////////////在.cpp 文件中声明

#define STATEMENTINSTANCE(CLASS_NAME)           \
    CLASS_NAME *CLASS_NAME::pThis = nullptr;    \
    QMutex *CLASS_NAME::getInstaceMutex = new QMutex(QMutex::Recursive);    \


#define PTHISSETTHIS           \
    pThis = this;



#endif // GETINSTANCEDEFINE_H
