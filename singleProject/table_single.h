#ifndef TABLE_SINGLE_H
#define TABLE_SINGLE_H

#include <QObject>
#include <QtCore>
#include <QtGui>
#include<QToolButton>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#include<QMouseEvent>
#endif

#include "instance.h"

class table_single : public QObject
{
    Q_OBJECT
public:
    static QMutex mutex;
    static table_single* table_singleItiem;

    explicit table_single(QObject *parent = nullptr);
    static table_single *GetInstance();

    //TableWidget 初始化设置
    void TableWidgetInit(QTableWidget *table,int ftsize,QString HeaderStyle,int Header_Cel,int Header_Row);
    //QList<QString>comboxList,int combox 下拉框设置
    void UP_TableWidget(QTableWidget *table,QList<RW_Excel>RW_ExcelList,QStringList comBoxlist,int combox);

    void TableWidgetAnaly(QTableWidget *table, int row, int color,int color1,int color2,RW_Excel RW_ExcelItiem,
                          QStringList comBoxlist,int combox);

    void SetAnalyExcel(QTableWidget *table, int row,int cel, int color, int color1, int color2, QString ExcelCEL,
                       RW_Excel RW_ExcelItiem,QStringList comBoxlist,int combox);
    void SetAnalyExcel_(QTableWidget *table, int row,int cel, int color, int color1, int color2, QString ExcelCEL,RW_Excel RW_ExcelItiem
                       ,int color_);

    bool SetMessagebox(QString Messagetext);


public:



};

#endif // TABLE_SINGLE_H
