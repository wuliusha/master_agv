#ifndef BUTTON_SINGLE_H
#define BUTTON_SINGLE_H

#include <QObject>
#include <QtCore>
#include <QtGui>
#include<QToolButton>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#include<QMouseEvent>
#endif

#include "log_single.h"

class button_single : public QObject
{
    Q_OBJECT
public:
    explicit button_single(QObject *parent = nullptr);

    static button_single *GetInstance();

    //buttonStyle 函数初始化
    void iconhelperinit(helperInfo helperInfoI);

    //实时更新显示状态
    void ButtonChageiconhelper(helperInfo helperInfoI,QString Buttontext);

public:
    static QMutex mutex;
    static button_single* button_singleItiem;

};

#endif // BUTTON_SINGLE_H
