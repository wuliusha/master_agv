#include "cfgsetting.h"
#include <QDebug>

CfgSetting::CfgSetting(setting *parent) : setting(parent)
  ,settings(nullptr)
{
    pThis = this;
    initSettingInterface();
}

void *CfgSetting::setSettings(QSettings *setting)
{
    this->settings = setting;
}


//bool CfgSetting::initSettingInterface()
//{
//    settings = new QSettings(defaultCfgfileName, QSettings::IniFormat);
//}

bool CfgSetting::getSettingValueInterface(QString key, QVariant &value)
{
//    qDebug() << "setting get data" << key;
//    qDebug() << settings->value(key);
    if(settings->contains(key))
    {
        value = settings->value(key);
        return true;
    }
    else
    {
        return false;
    }
}

bool CfgSetting::initSettingInterface()
{
    qDebug() << "cfgSetting setting data";
    settings = new QSettings(defaultCfgfileName, QSettings::IniFormat);
//    settings->setValue("datatest", 9);
    bool isOk;
    qDebug() << settings->value("carData/carLength").toDouble(&isOk) << isOk;
    return isOk;
}

bool CfgSetting::setSettingValueInerface(QString group, QString key, QVariant &value)
{
   if(settings == nullptr)
       return false;
   settings->beginGroup(group);
   settings->setValue(key, value);
   settings->endGroup();
   return true;
}

QSettings *CfgSetting::getSettings()
{
    return settings;
}

CfgSetting *CfgSetting::getInstance()
{
    if(!pThis)
    {
        pThis = new CfgSetting();
    }
    return dynamic_cast<CfgSetting*>(pThis);
}
