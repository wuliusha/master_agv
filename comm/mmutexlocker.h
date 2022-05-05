#ifndef MMUTEXLOCKER_H
#define MMUTEXLOCKER_H

#include <QObject>
#include <QMutex>

class mMutexLocker
{
public:
    mMutexLocker();
    mMutexLocker(QMutex *mutex);
    ~mMutexLocker();

    void setMutex(QMutex *mutex);

    void lock();

    void unlock();

private:

    QMutex *mutex;
    bool locked;
};

#endif // MMUTEXLOCKER_H
