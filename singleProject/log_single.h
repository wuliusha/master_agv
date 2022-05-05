#ifndef LOG_SINGLE_H
#define LOG_SINGLE_H

#include <QObject>
#include <QtCore>
#include <QTimer>
#include <QWidget>
#include <QtGui>
#include<QToolButton>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#include<QMouseEvent>
#endif

#include <QObject>
#include "instance.h"
#include "table_single.h"
#include "button_single.h"
#include "iconhelper/iconhelper.h"

#include "queryServer/queryserver.h"
#include "httpserver/httpconnection.h"
class log_single : public QObject
{
    Q_OBJECT

public:
    static log_single *GetInstance();

    explicit log_single(QObject *parent = 0);

    QString currentlogtext="";
    void setqDebug_log(QString logtext);
    QString getqDebug_log();

public:
    static QMutex mutex;
    static log_single* log_singleItiem;

};

#endif // LOG_SINGLE_H
