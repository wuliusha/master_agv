#include "table_single.h"

table_single* table_single::table_singleItiem=0;
QMutex table_single::mutex;

table_single::table_single(QObject *parent)
{

}

table_single *table_single::GetInstance()
{
    if(table_singleItiem != nullptr){
        return table_singleItiem;
    }else{
        mutex.lock();
        table_singleItiem=new table_single;
        return table_singleItiem;
        mutex.unlock();
    }
}

void table_single::TableWidgetInit(QTableWidget *table, int ftsize, QString HeaderStyle, int Header_Cel, int Header_Row)
{
    QFont ft;
    ft.setPointSize(ftsize);
    table->verticalHeader()->setVisible(false);
    table->horizontalHeader()->setVisible(true);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
    //table->setStyleSheet("*{outline:0px;color:#FEFEFE;}");
    table->horizontalHeader()->setStyleSheet(HeaderStyle);

    table->setSelectionBehavior(QAbstractItemView::SelectItems);   // 单个选中
    table->setSelectionMode(QAbstractItemView::ExtendedSelection); //设置为可以选中多个目标

    //设置表头字体加粗
    QFont font =  table->horizontalHeader()->font();
    font.setBold(true);
    table->horizontalHeader()->setFont(font);

    QHeaderView *headerGoods = table->horizontalHeader();
    //SortIndicator为水平标题栏文字旁边的三角指示器   内容排序
    headerGoods->setSortIndicator(0, Qt::AscendingOrder);
    headerGoods->setSortIndicatorShown(true);
    headerGoods->setSectionsClickable(true);
    connect(headerGoods,SIGNAL(sectionClicked(int)),table,SLOT(sortByColumn(int)));

    table->horizontalHeader()->setMinimumHeight(Header_Cel);//列  表头高度
    table->verticalHeader()->setDefaultSectionSize(Header_Row); //设置行高

}

void table_single::UP_TableWidget(QTableWidget *table, QList<RW_Excel> RW_ExcelList,QStringList comBoxlist,int combox)
{

    table->clearContents();//清空表格中的内容（不包含表头）
    int rowcount=RW_ExcelList.size();
    table->setRowCount(rowcount); // 设置表格控件行数
    //-1 红色(异常)  0 默认颜色  1 绿色（到达且已扫描）  2 黄色()  100 浅灰(完成)
    int row=0,  color=161, color1=163, color2=166;
    foreach (RW_Excel RW_ExcelItiem, RW_ExcelList){
        if(RW_ExcelItiem.checked==1){RW_ExcelItiem.corlor=1;}
        if(RW_ExcelItiem.corlor==1){
            RW_ExcelItiem.fontclrlor=1;
            color=29; color1=149; color2=63;
        }
        if(RW_ExcelItiem.corlor==0){
            //color=161; color1=163; color2=166;
            //color=161; color1=163; color2=166;
            //background-color: rgb(246, 245, 236);
            color=255; color1=254; color2=249;
            if(row%2==0){color=246; color1=245; color2=236;}
        }
        TableWidgetAnaly(table,row,color,color1,color2,RW_ExcelItiem,comBoxlist,combox);
        row++;
    }
    if(!table->isVisible()){
        table->setVisible(true);
    }

}

void table_single::TableWidgetAnaly(QTableWidget *table,int row,int color,int color1,int color2,RW_Excel RW_ExcelItiem,QStringList comBoxlist,int combox)
{

    if(table->columnCount()<1){return;}
    SetAnalyExcel(table,row,0,color,color1,color2,RW_ExcelItiem.ExcelA,RW_ExcelItiem,comBoxlist,combox);
    if(table->columnCount()<2){return;}
    SetAnalyExcel(table,row,1,color,color1,color2,RW_ExcelItiem.ExcelB,RW_ExcelItiem,comBoxlist,combox);
    if(table->columnCount()<3){return;}
    SetAnalyExcel(table,row,2,color,color1,color2,RW_ExcelItiem.ExcelC,RW_ExcelItiem,comBoxlist,combox);
    if(table->columnCount()<4){return;}
    SetAnalyExcel(table,row,3,color,color1,color2,RW_ExcelItiem.ExcelD,RW_ExcelItiem,comBoxlist,combox);
    if(table->columnCount()<5){return;}
    SetAnalyExcel(table,row,4,color,color1,color2,RW_ExcelItiem.ExcelE,RW_ExcelItiem,comBoxlist,combox);
    if(table->columnCount()<6){return;}
    SetAnalyExcel(table,row,5,color,color1,color2,RW_ExcelItiem.ExcelF,RW_ExcelItiem,comBoxlist,combox);
    if(table->columnCount()<7){return;}
    SetAnalyExcel(table,row,6,color,color1,color2,RW_ExcelItiem.ExcelG,RW_ExcelItiem,comBoxlist,combox);
    if(table->columnCount()<8){return;}
    SetAnalyExcel(table,row,7,color,color1,color2,RW_ExcelItiem.ExcelH,RW_ExcelItiem,comBoxlist,combox);
    if(table->columnCount()<9){return;}
    SetAnalyExcel(table,row,8,color,color1,color2,RW_ExcelItiem.ExcelI,RW_ExcelItiem,comBoxlist,combox);
    if(table->columnCount()<10){return;}
    SetAnalyExcel(table,row,9,color,color1,color2,RW_ExcelItiem.ExcelJ,RW_ExcelItiem,comBoxlist,combox);
    if(table->columnCount()<11){return;}
    SetAnalyExcel(table,row,10,color,color1,color2,RW_ExcelItiem.ExcelK,RW_ExcelItiem,comBoxlist,combox);
    if(table->columnCount()<12){return;}
    SetAnalyExcel(table,row,11,color,color1,color2,RW_ExcelItiem.ExcelL,RW_ExcelItiem,comBoxlist,combox);
    if(table->columnCount()<13){return;}
    SetAnalyExcel(table,row,12,color,color1,color2,RW_ExcelItiem.ExcelM,RW_ExcelItiem,comBoxlist,combox);
    if(table->columnCount()<14){return;}
    SetAnalyExcel(table,row,13,color,color1,color2,RW_ExcelItiem.ExcelN,RW_ExcelItiem,comBoxlist,combox);
    if(table->columnCount()<15){return;}
    SetAnalyExcel(table,row,14,color,color1,color2,RW_ExcelItiem.ExcelO,RW_ExcelItiem,comBoxlist,combox);
    if(table->columnCount()<16){return;}
    SetAnalyExcel(table,row,15,color,color1,color2,RW_ExcelItiem.ExcelP,RW_ExcelItiem,comBoxlist,combox);
    if(table->columnCount()<17){return;}
    SetAnalyExcel(table,row,16,color,color1,color2,RW_ExcelItiem.ExcelQ,RW_ExcelItiem,comBoxlist,combox);
    if(table->columnCount()<18){return;}

}

void table_single::SetAnalyExcel(QTableWidget *table, int row, int cel, int color, int color1, int color2, QString ExcelCEL,
                                 RW_Excel RW_ExcelItiem,QStringList comBoxlist,int combox)
{
    if(cel!=0){ExcelCEL=" "+ExcelCEL+" ";}
    QTableWidgetItem *ExcelCEL_1 = new QTableWidgetItem(ExcelCEL);

    //if(cel>2){ExcelCEL_1->setFlags(Qt::NoItemFlags);}
    ExcelCEL_1->setTextColor(QColor(30,30,30));
    if(RW_ExcelItiem.fontclrlor==1){
        ExcelCEL_1->setTextColor(QColor(255,250,250));
    }

    if(!comBoxlist.isEmpty() && cel==combox){
        QComboBox *comBox = new QComboBox();
        comBox->addItems(comBoxlist);
        comBox->setStyleSheet("QComboBox{color:#FEFEFE; background-color: rgb(0, 166, 172);font:16pt;border-left-width:20px;}"
                              "QComboBox:hover{border: 1px solid #C0C4CC;}"
                              "QComboBox::drop-down{width: 0px;}");

        //connect(comBox,&QComboBox::currentTextChanged,this,&Instance::sigTextChanged);
        table->setCellWidget(row,cel,comBox);
    }else{
        table->setItem(row, cel, ExcelCEL_1);
        table->item(row, cel)->setTextAlignment(Qt::AlignCenter);
        table->item(row, cel)->setBackgroundColor(QColor(color,color1,color2));
    }

}

void table_single::SetAnalyExcel_(QTableWidget *table, int row, int cel, int color, int color1, int color2, QString ExcelCEL, RW_Excel RW_ExcelItiem, int color_)
{
    if(cel!=0){ExcelCEL=" "+ExcelCEL+" ";}
    QTableWidgetItem *ExcelCEL_1 = new QTableWidgetItem(ExcelCEL);

    if(cel>2){ExcelCEL_1->setFlags(Qt::NoItemFlags);}
    ExcelCEL_1->setTextColor(QColor(30,30,30));
    if(RW_ExcelItiem.fontclrlor==1){
        ExcelCEL_1->setTextColor(QColor(255,250,250));
    }

    QComboBox *comBox = new QComboBox();
    QStringList comBoxlist;comBoxlist<<"二维码方式"<<"磁条方式"<<"自然导航";
    comBox->addItems(comBoxlist);
    comBox->setStyleSheet("QComboBox{color:#FEFEFE; background-color: rgb(0, 166, 172);border: 0px solid #FFFFFF;border-radius: 3px;}"
                          "QComboBox:hover{border: 1px solid #C0C4CC;}"
                          "QComboBox::drop-down{width: 0px;border-style:none;}");

    //connect(comBox,&QComboBox::currentTextChanged,this,&Instance::sigTextChanged);

    table->setCellWidget(row,cel,comBox);

//    table->setItem(row, cel, ExcelCEL_1);
//    table->item(row, cel)->setTextAlignment(Qt::AlignCenter);
//    table->item(row, cel)->setBackgroundColor(QColor(color,color1,color2));
}

bool table_single::SetMessagebox(QString Messagetext)
{
    QFont ft;ft.setPointSize(12);
    QMessageBox message(QMessageBox::NoIcon, "建议: ", Messagetext, QMessageBox::Yes | QMessageBox::No, NULL);
    message.setIconPixmap(QPixmap(":/image/call.jpg"));
    message.resize(300,200);
    message.setFont(ft);
    if(message.exec() == QMessageBox::Yes)
    {
        message.close();return true;
    }
    message.close();return false;

}

