#include "dailyrecord.h"
#include "ui_dailyrecord.h"

dailyRecord::dailyRecord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dailyRecord)
{
    ui->setupUi(this);
    dailyRecordInit();

    recordTimer = new QTimer(this);
    connect(recordTimer,&QTimer::timeout,this,&dailyRecord::ON_recordTimer);
    recordTimer->start(800);

}

dailyRecord::~dailyRecord()
{
    delete ui;
}

void dailyRecord::dailyRecordInit()
{

}

void dailyRecord::ON_recordTimer()
{
    if(qdebug_logstop){
        QString logtext=log_single::GetInstance()->getqDebug_log();
        if(logtext!=""){
            qdebug_logstopcount++;
            ui->qdebug_log->append(logtext);
        }
    }
    if(qdebug_logstopcount>100){
        qdebug_logstopcount=0;
        ui->qdebug_log->clear();
    }
}

void dailyRecord::on_stop_Button_clicked()
{
    if(qdebug_logstop){
        qdebug_logstop=false;
        ui->stop_Button->setText("暂停");
    }else{
        qdebug_logstop=true;
        ui->stop_Button->setText("启动");
    }
}

void dailyRecord::on_clear_Button_clicked()
{
    ui->qdebug_log->clear();
}
