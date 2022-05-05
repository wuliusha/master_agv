#ifndef CREADEXCEL_H
#define CREADEXCEL_H
#include <QObject>
#include <QAxObject>
#include<QDateTime>
#include<QTimer>
#include <QList>
#include<qfile.h>
#include<qdebug.h>
#include<qelapsedtimer.h>
#include <QFileDialog>

class CReadExcel
{
public:
    CReadExcel();
public:
    //快速读取表格数据
    QVariant  readAll(QList<QList<QVariant> > &res);

    void open(QString strFile);

    void setCurrentSheet(int index);

    void castVariant2ListListVariant(const QVariant &var, QList<QList<QVariant> > &res);

    void closeExcel();

    //创建一个新的 excel 并导出
    void write(QList<QVariant> allRowsData);

    //创建一个新的 excel 并导出
    void write1(QList<QVariant> allRowsData,QString xlsFile);


    //手动导到 指定 的excel
    void write2(QList<QVariant> allRowsData);
private:

    QAxObject * sheet;

    QAxObject *pSheets;
    QAxObject *pSheet;

    QAxObject *excel;

    QAxObject* pWorkBook;

    QAxObject *workbooks;


};

#endif // CREADEXCEL_H
