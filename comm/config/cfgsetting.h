#ifndef CFGSETTING_H
#define CFGSETTING_H

#include <QObject>
#include <QSettings>
#include "comm/config/setting.h"
#define defaultCfgfileName "./cfg/config.ini"

class CfgSetting : public setting
{
    Q_OBJECT
public:
    explicit CfgSetting(setting *parent = 0);

    void *setSettings(QSettings *setting);
    QSettings *getSettings();

signals:

public slots:

    // setting interface
//public:
//    bool initSettingInterface();
//    bool getSettingValueInterface(QString key, QVariant &value);

private:
    QSettings *settings;

    // setting interface
public:
    bool getSettingValueInterface(QString key, QVariant &value)override;
    bool initSettingInterface() override;
    bool setSettingValueInerface(QString group, QString key, QVariant &value)override;



    static CfgSetting *getInstance();
};

#endif // CFGSETTING_H
