#ifndef SINGLE_PROJECT_H
#define SINGLE_PROJECT_H

#include <QObject>
#include "instance.h"
#include "log_single.h"
#include "table_single.h"
#include "button_single.h"
#include "iconhelper/iconhelper.h"

#include "queryServer/queryserver.h"
#include "httpserver/httpconnection.h"

class single_project : public QObject
{
    Q_OBJECT
public:
    explicit single_project(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SINGLE_PROJECT_H
