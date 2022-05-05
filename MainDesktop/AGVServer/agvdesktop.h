#ifndef AGVDESKTOP_H
#define AGVDESKTOP_H

#include <QWidget>
#include "agvserver.h"

namespace Ui {
class agvdesktop;
}

class agvdesktop : public QWidget
{
    Q_OBJECT

public:
    explicit agvdesktop(QWidget *parent = 0);
    ~agvdesktop();
    QTimer *AGVTimer;
    void AGVDesktopInit();


public slots:
    void ON_AGVTimer();

private:
    Ui::agvdesktop *ui;
    AGVServer *AGVServerItiem;
    QThread *ThreadAGVServer;
};

#endif // AGVDESKTOP_H
