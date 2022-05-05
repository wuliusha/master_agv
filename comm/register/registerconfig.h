#ifndef REGISTERCONFIG_H
#define REGISTERCONFIG_H

#include "comm/config/cfgsetting.h"

//注册获取config 文件的中数据
#define CONFIGGETVALUE(key, value)  \
    CfgSetting::getInstance()->getSettingValueInterface(key, value)

#endif // REGISTERCONFIG_H
