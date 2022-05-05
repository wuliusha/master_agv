#ifndef BUTTONSTYLE_H
#define BUTTONSTYLE_H

#include <QObject>
#include <QObject>
#include <QtCore>
#include <QtGui>
#include<QToolButton>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#include<QMouseEvent>
#endif


class buttonStyle : public QObject
{
    Q_OBJECT

public:
    static buttonStyle *GetInstance();
    explicit buttonStyle(QObject *parent = 0);

    //buttonStyle 函数初始化
    void iconhelperinit(helperInfo helperInfoI);

    //实时更新显示状态
    void ButtonChageiconhelper(helperInfo helperInfoI,QString Buttontext);

public:
    static QMutex mutex;
    static buttonStyle* buttonStyleItiem;

signals:

public slots:

};

#endif // BUTTONSTYLE_H
