#include "readexcel.h"
#include <QElapsedTimer>
#include <qdebug.h>

//参考博客：http://blog.sina.com.cn/s/blog_a6fb6cc90101gv2p.html
CReadExcel::CReadExcel()
{
}


void CReadExcel::open(QString fileName)
{
    excel = new QAxObject();
    excel->setControl("Excel.Application");//连接Excel控件
    excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
    excel->setProperty("DisplayAlerts", true);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示

    workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
    QFile file(fileName);
    if(file.exists()){//判断 excel 是否存在
        pWorkBook = workbooks->querySubObject("Open(const QString &)", fileName);
    }
    else{
        workbooks->dynamicCall("Add");
        pWorkBook = excel->querySubObject("ActiveWorkBook");
    }
    //pSheets = pWorkBook->querySubObject("ActiveWorkBook");//获取当前工作簿
    pSheets = pWorkBook->querySubObject("Sheets");//获取工作表集合
    sheet = pSheets->querySubObject("Item(int)", 1);
}
void CReadExcel::setCurrentSheet(int index)
{
    sheet = pSheets->querySubObject("Item(int)",index);//获取工作表集合的工作表1，即sheet1
}


QVariant  CReadExcel::readAll(QList<QList<QVariant> > &res)
{
    QVariant var;
    if (this->sheet != NULL && ! this->sheet->isNull())
    {
        QAxObject *usedRange = this->sheet->querySubObject("UsedRange");
        if(NULL == usedRange || usedRange->isNull())
        {
            return var;
        }
        var = usedRange->dynamicCall("Value");
        delete usedRange;
    }

    castVariant2ListListVariant(var ,res);

    return var;
}
void CReadExcel::castVariant2ListListVariant(const QVariant &var, QList<QList<QVariant> > &res)
{
    QVariantList varRows = var.toList();
    if(varRows.isEmpty())
    {
        return;
    }
    const int rowCount = varRows.size();
    QVariantList rowData;
    for(int i=0;i<rowCount;++i)
    {
        rowData = varRows[i].toList();
        res.push_back(rowData);
    }
}

void CReadExcel::closeExcel()
{
    pWorkBook->dynamicCall("Close()");
    excel->dynamicCall("Quit()");
    delete excel;
    excel = NULL;
}
    //创建一个新的 excel 并导出
void CReadExcel::write(QList<QVariant> allRowsData)
{
    QString rowname="A1:O"+QString::number(allRowsData.size());
    QAxObject *range = sheet->querySubObject("Range(const QString )", rowname);
    range->dynamicCall("SetValue(const QVariant&)",QVariant(allRowsData));//存储所有数据到 excel 中,批量操作,速度极快
    range->querySubObject("Font")->setProperty("Size", 12);//设置字号
//    range->setProperty("RowHeight", 50);  //设置单元格行高

    range->setProperty("ColumnWidth",20);  //设置单元格列宽
    range->setProperty("HorizontalAlignment", -4108); //左对齐（xlLeft）：-4131  居中（xlCenter）：-4108  右对齐（xlRight）：-4152
//    range->setProperty("VerticalAlignment", -4108);  //上对齐（xlTop）-4160 居中（xlCenter）：-4108  下对齐（xlBottom）：-4107
//    range->setProperty("WrapText", true);  //内容过多，自动换行

//    QAxObject* interior = range->querySubObject("Interior");
//    interior->setProperty("Color", QColor(0, 255, 0));   //设置单元格背景色（绿色）

//    QAxObject* border = range->querySubObject("Borders");
//    border->setProperty("Color", QColor(0, 0, 255));   //设置单元格边框色（蓝色）
    QString timer=QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    QString fileName0="E:\\ASM_two\\ASM_Client\\RWExcel\\"+timer+"alg.xlsx";
    pWorkBook->dynamicCall("SaveAs(const QString&)",fileName0);  //另存为另一个文件

}

void CReadExcel::write1(QList<QVariant> allRowsData, QString xlsFile)
{
    QString rowname="A1:AA"+QString::number(allRowsData.size());
    QAxObject *range = sheet->querySubObject("Range(const QString )", rowname);
    range->dynamicCall("SetValue(const QVariant&)",QVariant(allRowsData));//存储所有数据到 excel 中,批量操作,速度极快
    range->querySubObject("Font")->setProperty("Size", 12);//设置字号
//    range->setProperty("RowHeight", 50);  //设置单元格行高

    range->setProperty("ColumnWidth",20);  //设置单元格列宽
    range->setProperty("HorizontalAlignment", -4108); //左对齐（xlLeft）：-4131  居中（xlCenter）：-4108  右对齐（xlRight）：-4152
//    range->setProperty("VerticalAlignment", -4108);  //上对齐（xlTop）-4160 居中（xlCenter）：-4108  下对齐（xlBottom）：-4107
//    range->setProperty("WrapText", true);  //内容过多，自动换行

//    QAxObject* interior = range->querySubObject("Interior");
//    interior->setProperty("Color", QColor(0, 255, 0));   //设置单元格背景色（绿色）

//    QAxObject* border = range->querySubObject("Borders");
//    border->setProperty("Color", QColor(0, 0, 255));   //设置单元格边框色（蓝色）
    QString timer=QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm");
    //C:\Users\80016509\Desktop\ASM_AGVClient
    //
    //QString fileName0="C:\\Users\\80016509\\Desktop\\ASM_AGVOPerater\\RWExcel\\"+timer+"alg.xlsx";
    pWorkBook->dynamicCall("SaveAs(const QString&)",xlsFile);  //另存为另一个文件
}
//手动导到 指定 的excel
void CReadExcel::write2(QList<QVariant> allRowsData)
{
    QAxObject *range = sheet->querySubObject("Range(const QString )", "A1:F10");
    range->dynamicCall("SetValue(const QVariant&)",QVariant(allRowsData));//存储所有数据到 excel 中,批量操作,速度极快
    range->querySubObject("Font")->setProperty("Size", 18);//设置字号
    range->setProperty("RowHeight", 50);  //设置单元格行高
    range->setProperty("ColumnWidth", 30);  //设置单元格列宽
    range->setProperty("HorizontalAlignment", -4108); //左对齐（xlLeft）：-4131  居中（xlCenter）：-4108  右对齐（xlRight）：-4152
    range->setProperty("VerticalAlignment", -4108);  //上对齐（xlTop）-4160 居中（xlCenter）：-4108  下对齐（xlBottom）：-4107
    range->setProperty("WrapText", true);  //内容过多，自动换行

//    QAxObject* interior = range->querySubObject("Interior");
//    interior->setProperty("Color", QColor(0, 255, 0));   //设置单元格背景色（绿色）

    QAxObject* border = range->querySubObject("Borders");
    border->setProperty("Color", QColor(0, 0, 255));   //设置单元格边框色（蓝色）

    //pWorkBook->dynamicCall("SaveAs(const QString&)", "E:\\test2.xlsx");  //另存为另一个文件
}
