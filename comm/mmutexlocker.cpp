#include "mmutexlocker.h"

mMutexLocker::mMutexLocker()
{
    mutex = nullptr;
    locked = false;
}

mMutexLocker::mMutexLocker(QMutex *mutex)
{
    this->mutex = mutex;
    locked = false;
}

mMutexLocker::~mMutexLocker()
{
//    if(mutex->try_lock())
//    {
//        mutex->unlock();
//    }
//    delete mutex;
    if(locked)
        mutex->unlock();
}

void mMutexLocker::setMutex(QMutex *mutex)
{
    if(this->mutex != nullptr)
    {
//        if(this->mutex->try_lock())
//        {
//            this->mutex->unlock();
//        }
//        delete this->mutex;
        this->mutex = nullptr;
    }
    this->mutex = mutex;

}

void mMutexLocker::lock()
{
    if(mutex == nullptr)
        return;
    locked = true;
    mutex->lock();
}

void mMutexLocker::unlock()
{
    if(mutex == nullptr)
        return;
    mutex->unlock();
    locked = false;
}
