#include "log_single.h"

log_single* log_single::log_singleItiem=0;
QMutex log_single::mutex;

log_single::log_single(QObject *parent)
{

}

log_single *log_single::GetInstance()
{
    if(log_singleItiem != nullptr)
        return log_singleItiem;
    else
    {
        mutex.lock();
        if(log_singleItiem == nullptr){
            log_singleItiem=new log_single;
        }
        mutex.unlock();
        return log_singleItiem;
    }
}

void log_single::setqDebug_log(QString logtext)
{
    currentlogtext=currentlogtext+logtext;
}

QString log_single::getqDebug_log()
{
    QString logtext=currentlogtext;
    currentlogtext="";
    return logtext;
}
