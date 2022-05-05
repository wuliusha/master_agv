#ifndef WREXCELPROCESS_H
#define WREXCELPROCESS_H

#include <QWidget>
#include <QWidget>
#include <QtGui>
#include <QAxObject>
#include <QAxWidget>
#include <QTextStream>
#include<QLabel>
#include <QFile>
#include<QLineEdit>
#include<QTableWidget>
#include "readexcel.h"
#include "agvCar/agvcarpool.h"
#include "singleProject/single_project.h"
#include "queryServer/queryserver.h"
#include "comm/config/cfgsetting.h"
#include "comm/datebaseConnectPool/connectpoolfactory.h"


namespace Ui {
class wrexcelprocess;
}

class wrexcelprocess : public QWidget
{
    Q_OBJECT

public:
    explicit wrexcelprocess(QWidget *parent = 0);
    ~wrexcelprocess();
    //QString RWExcelfileName="C:\\Users\\80016509\\Desktop\\ASM_AGVOPerater\\RWExcel\\";
    QString RWExcelfileName="E:\\ASM_two\\ASM_Client\\RWExcel\\";
    QTimer *wrexcelTimer;
    QString CurrentxlsFile="";
    bool Write_Excelbool=false;bool Read_Excelbool=false;
    int RW_ExcelActionCount=10; int timercount0=2000;

    QScopedPointer<CReadExcel> m_xls;
    QList<QList<QVariant> > m_datas;

    QList<RW_Excel>Read_ExcelItiemList; //读取 Excel 的数据缓存列表
    QList<RW_Excel>Write_ExcelItiemList;//写入 Excel 的数据缓存列表


    void TableWidgetInit(QTableWidget *table);
    void UP_TableWidget(QTableWidget *table,QList<RW_Excel>RW_ExcelList);
    void TableWidgetAnaly(QTableWidget *table, int row, int color,
                              int color1,int color2,RW_Excel RW_ExcelItiem);
    void SetAnalyExcel(QTableWidget *table, int row,int cel, int color, int color1, int color2, QString ExcelCEL);

    //读取 Excel 的数据 转为 Read_ExcelItiemList 缓存
    QList<RW_Excel>UPRead_Excel(QList<QList<QVariant> > m_datas);
    bool UPWrite_Excel(QList<RW_Excel>Write_ExcelList,QString xlsFile);


    QMap<QString, SAPExcelInfo>UPRead_SAPExcelInfo(QString Priority,int taskLeadType);
    QString GETxlsFile();
    QMap<QString, SAPExcelInfo>ReturnSAPExcelInfo(QList<QList<QVariant> > m_datas,QString Priority);
    QMap<QString, SAPExcelInfo>ReturnSAPExcelInfo_other(QList<QList<QVariant> > m_datas,QString Priority);


    QMap<QString,agvSubTask > ON_read_movepointmap();
    QMap<QString,agvSubTask > read_movepointmap(QList<QList<QVariant> > m_datas,QString Priority);

    void on_EXCEL_WS01_clicked(QDateTime QDateTimeS, QDateTime QDateTimeE);

    void on_EXCEL_WS05_clicked(QDateTime QDateTimeS, QDateTime QDateTimeE);

    bool on_EXCEL_Log_clicked(QMap<int, record_log>Record_logMap);

    bool on_EXCEL_store_clicked(QMap<QString,materialShelfbin >Record_checkMap);//导出盘点数据



public slots:
    void slotswrexcelTimer();


private slots:
    void on_writeexcel_clicked();

    void on_readexcel_clicked();

    void on_Btn_Close_clicked();

private:
    Ui::wrexcelprocess *ui;
};

#endif // WREXCELPROCESS_H
