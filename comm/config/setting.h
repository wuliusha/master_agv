#ifndef SETTING_H
#define SETTING_H

#include <QObject>
#include <QVariant>
#include <QList>
#include <QMutex>
#include <QMutexLocker>

typedef enum
{
    configSetting,
    jsonSetting,
}SettingsTyped;

class setting : public QObject
{
    Q_OBJECT
public:
    explicit setting(QObject *parent = 0);
    ~setting();

    virtual bool getSettingValueInterface(QString key, QVariant &value){qDebug("call parent func");}
    virtual bool initSettingInterface(){}
    virtual bool setSettingValueInerface(QString group, QString key, QVariant &value){qDebug("call parent func");}

    static setting *getInstance();

    static QMutex *mutex;

protected:
    static setting *pThis;

signals:

public slots:

private:
    SettingsTyped settingsType;

};

#endif // SETTING_H
