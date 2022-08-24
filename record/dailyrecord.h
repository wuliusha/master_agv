#ifndef DAILYRECORD_H
#define DAILYRECORD_H

#include <QWidget>
#include "queryServer/queryserver.h"
#include "singleProject/iconhelper/iconhelper.h"

namespace Ui {
class dailyRecord;
}

class dailyRecord : public QWidget
{
    Q_OBJECT

public:
    explicit dailyRecord(QWidget *parent = nullptr);
    ~dailyRecord();

    bool booltable=true;
    bool qdebug_logstop=true;   //日志显示
    int qdebug_logstopcount=0;

    void dailyRecordInit();     //日志类初始化

public slots:
    void ON_recordTimer();

private slots:

    void on_stop_Button_clicked();

    void on_clear_Button_clicked();

private:
    Ui::dailyRecord *ui;
    QTimer *recordTimer;

};

#endif // DAILYRECORD_H
