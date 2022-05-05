#include "anomaly.h"
#include "ui_anomaly.h"

Anomaly::Anomaly(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Anomaly)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    pix = new QPixmap(size());

    pix->fill(QColor(66,66,66));
    setMinimumSize(300,390);
    updateGram();
    AnomalyInit();

    StTimer = new QTimer(this);
    connect(StTimer,&QTimer::timeout,this,&Anomaly::AnomalyTimer);
    StTimer->start(5000);

}

Anomaly::~Anomaly()
{
    delete ui;
}


void Anomaly::AnomalyTimer()
{
    AnomalyTimercount++;
    if(AnomalyTimercount>10000){
        AnomalyTimercount=0;

    }
    if(AnomalyTimercount%2==0 && AnomalyTimerbool){
        AnomalyTimerbool=false;
        currentSysErrorMap=queryServer::getInstance()->getsyserror_message();//获取 未处理的系统异常信息
        tableWidget_Show();//tableWidget 更新显示
        AnomalyTimerbool=true;
    }

}

void Anomaly::AnomalyInit()
{
    table_single::GetInstance()->TableWidgetInit(ui->tableWidget,10,"QHeaderView::section{background-color:rgb(193,205,205);font:10pt '宋体';color: black;};",20,20);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    connect(ui->tableWidget,&QTableWidget::cellClicked,this,&Anomaly::SlotsetCurrentItem);
}

void Anomaly::slecetCurrentItem(QString errorMassege, int add, int row, int column)
{
    errorMassege=errorMassege.trimmed();//删除首尾空格
    QMap<int, email_message>::iterator iter= currentSysErrorMap.begin();
    while (iter !=currentSysErrorMap.end()) {
        if(iter.value().message==errorMassege){
            if(ui->tableWidget ->item(row, column)->checkState() == Qt::Checked){
                queryServer::getInstance()->setsyserror_message(iter.value());//设置 已处理的系统异常信息状态
                qDebug()<<"当前异常信息已处理"<<iter.key()<<iter.value().taskId<<errorMassege<<QDateTime::currentDateTime().toString();
                currentSysErrorMap.remove(iter.key());
                //tableWidget_Show();//tableWidget 更新显示
                //return;
            }
        }
        iter++;
    }
    //tableWidget_Show();//tableWidget 更新显示
}

QList<RW_Excel> Anomaly::TableWidget(QMap<int, email_message> sysErrorMap)
{
    QList<RW_Excel> ExcelList;
    QList<RW_Excel> ExcelList0;
    QList<RW_Excel> ExcelList1;
    if(!sysErrorMap.isEmpty()){
        QMap<int, email_message>::iterator iter= sysErrorMap.begin();
        while (iter!=sysErrorMap.end()) {
            RW_Excel RW_ExcelItem;
            RW_ExcelItem.checked=0;
            RW_ExcelItem.ExcelB=iter.value().message;
            ExcelList0.append(RW_ExcelItem);
            //qDebug()<<iter.value().taskId<<iter.value().message;
            iter++;
        }
    }

    ExcelList=ExcelList0+ExcelList1;
    for (int i=0;i<ExcelList.length();i++) {
         ExcelList[i].ExcelA=QString::number(i+1);
    }

    return ExcelList;
}

void Anomaly::SlotsetCurrentItem(int row, int column)
{
    if(ui->tableWidget ->item(row, column)->checkState() == Qt::Checked){
        slecetCurrentItem(ui->tableWidget->item(row,1)->text(),1,row, column);
        //ui->tableWidget->item(row, column)->setBackgroundColor(QColor(81,81,81));
    }

    if(ui->tableWidget ->item(row, column)->checkState() != Qt::Checked){
        slecetCurrentItem(ui->tableWidget->item(row,1)->text(),0,row, column);
        //ui->tableWidget->item(row, column)->setBackgroundColor(QColor(81,81,81));
    }

    tableWidget_Show();//tableWidget 更新显示
}

void Anomaly::tableWidget_Show()
{
    QStringList comBoxlist;
    table_single::GetInstance()->UP_TableWidget(ui->tableWidget,TableWidget(currentSysErrorMap),comBoxlist,0);
    if(currentSysErrorMap.isEmpty()){
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
        return;
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
}

void Anomaly::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(QPoint(0,0),*pix);
}

bool Anomaly::SetValue(QString TimerID,QString message,QString Action)
{
    bool Valuebool=false;
    if(Action=="0"){//未处理
        foreach (Anoma Anoma0, AnomaStringlist) {
            if(Anoma0.TimerID==TimerID){return false;}
        }
        Anoma Anoma1;Valuebool=true;
        Anoma1.TimerID=TimerID;Anoma1.message=message;
        AnomaStringlist.append(Anoma1);
    }
    if(Action=="1"){//已处理
        for(int i=0;i<AnomaStringlist.length();i++){
            if(AnomaStringlist[i].TimerID==TimerID){
                Valuebool=true;
                AnomaStringlist.removeAt(i);i--;
            }
        }
    }
    updateGram();
    return Valuebool;

}

QString Anomaly::GetValue(int ID)
{
    if(AnomaStringlist.size()>=ID){
        qDebug()<<ID<<AnomaStringlist[ID-1].message;
         return AnomaStringlist[ID-1].message;
    }
    qDebug()<<ID;
   return "";
}

void Anomaly::updateGram()
{
    QPixmap *pix0=new QPixmap(size());
    pix0->fill(QColor(66,66,66));
    this->setMinimumSize(310,300);
    pix=pix0;
    QPainter *painter = new QPainter;
    QPen pen;
    //pen.setColor(Qt::white);
    painter->begin(pix);

    color="#FEFEFE";
    // 画一个圆角矩形
    painter->setBrush(color);
    painter->setPen(color);
    pen.setColor(QColor(255,245,255));//设置  图形字体  颜色
    //pen.setWidth(5);

    painter->setPen(pen);

    int length=6;
    if(AnomaStringlist.size()<6){length=AnomaStringlist.size();}
    for(int i=1;i<=length;i++){
        int X0=0;

        color="#ffffff";
        // 画一个圆角矩形
        painter->setBrush(color);
        painter->setPen(color);
        pen.setColor(QColor(255,255,255));//设置  图形字体  颜色
        painter->drawLine(X0,i*40,600,i*40);

        color="#ffff7f";
        // 画一个圆角矩形
        painter->setBrush(color);
        painter->setPen(color);
        pen.setColor(QColor(255,255,127));//设置  图形字体  颜色
        QString Value= GetValue(i);
        painter->setFont(QFont("Arial",12));
        if(Value.size()<8){X0=X0+(8-Value.size())*40;}
        painter->drawText(X0,i*40-10,Value);
    }

}






