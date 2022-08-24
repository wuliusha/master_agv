#include "wrexcelprocess.h"
#include "ui_wrexcelprocess.h"
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase0)

wrexcelprocess::wrexcelprocess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wrexcelprocess)
{
    ui->setupUi(this);
    TableWidgetInit(ui->tableWidget);
    IconHelper::Instance()->setIcon(ui->Btn_Edit,0xf0c9,20);
    IconHelper::Instance()->setIcon(ui->BtnReturn, 0xf015,20);
    IconHelper::Instance()->setIcon(ui->Btn_Close, 0xf00d,20);


    QVariant value;int DATETYPE=0;
    if(setting::getInstance()->getSettingValueInterface("DATETYPE/flag", value))
    {
        DATETYPE = value.toInt();
    }if(DATETYPE==1){
         RWExcelfileName="C:\\Users\\80016509\\Desktop\\ASM_AGVOPerater\\RWExcel\\";
    }
    RWExcelfileName = QDir::currentPath();
    RWExcelfileName = RWExcelfileName.replace("/","\\")+"\\RWExcel\\";

    wrexcelTimer = new QTimer(this);
    connect(wrexcelTimer, SIGNAL(timeout()), this, SLOT(slotswrexcelTimer()));//
    wrexcelTimer->start(1000);//
}

wrexcelprocess::~wrexcelprocess()
{
    delete ui;
}

void wrexcelprocess::TableWidgetInit(QTableWidget *table)
{
    QFont ft;
    ft.setPointSize(12);
    table->verticalHeader()->setVisible(false);
    table->horizontalHeader()->setVisible(true);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
    //table->setStyleSheet("*{outline:0px;color:#FEFEFE;}");
    table->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(193,205,205);font:20pt '宋体';color: black;};");
    QHeaderView *headerGoods = table->horizontalHeader();
    //SortIndicator为水平标题栏文字旁边的三角指示器   内容排序
    headerGoods->setSortIndicator(0, Qt::AscendingOrder);
    headerGoods->setSortIndicatorShown(true);
    headerGoods->setSectionsClickable(true);
    connect(headerGoods,SIGNAL(sectionClicked(int)),table,SLOT(sortByColumn(int)));

    table->horizontalHeader()->setMinimumHeight(45);//列  表头高度
    table->verticalHeader()->setDefaultSectionSize(40); //设置行高
}

void wrexcelprocess::UP_TableWidget(QTableWidget *table, QList<RW_Excel> RW_ExcelList)
{
    table->hide();
    table->clearContents();//清空表格中的内容（不包含表头）
    int rowcount=RW_ExcelList.size();
    table->setRowCount(rowcount); // 设置表格控件行数
    int row=0,  color=81, color1=81, color2=81;
    foreach (RW_Excel RW_ExcelItiem, RW_ExcelList){
        TableWidgetAnaly(ui->tableWidget,row,color,color1,color2,RW_ExcelItiem);
        row++;
    }
    table->show();
}

void wrexcelprocess::TableWidgetAnaly(QTableWidget *table, int row, int color, int color1, int color2, RW_Excel RW_ExcelItiem)
{
    SetAnalyExcel(table,row,0,color,color1,color2,RW_ExcelItiem.ExcelA);
    SetAnalyExcel(table,row,1,color,color1,color2,RW_ExcelItiem.ExcelB);
    SetAnalyExcel(table,row,2,color,color1,color2,RW_ExcelItiem.ExcelC);
    SetAnalyExcel(table,row,3,color,color1,color2,RW_ExcelItiem.ExcelD);
    SetAnalyExcel(table,row,4,color,color1,color2,RW_ExcelItiem.ExcelE);
    SetAnalyExcel(table,row,5,color,color1,color2,RW_ExcelItiem.ExcelF);
    SetAnalyExcel(table,row,6,color,color1,color2,RW_ExcelItiem.ExcelG);
    SetAnalyExcel(table,row,7,color,color1,color2,RW_ExcelItiem.ExcelH);
    SetAnalyExcel(table,row,8,color,color1,color2,RW_ExcelItiem.ExcelI);
    SetAnalyExcel(table,row,9,color,color1,color2,RW_ExcelItiem.ExcelJ);
    SetAnalyExcel(table,row,10,color,color1,color2,RW_ExcelItiem.ExcelK);
    SetAnalyExcel(table,row,11,color,color1,color2,RW_ExcelItiem.ExcelL);
    SetAnalyExcel(table,row,12,color,color1,color2,RW_ExcelItiem.ExcelM);
    SetAnalyExcel(table,row,13,color,color1,color2,RW_ExcelItiem.ExcelN);
    SetAnalyExcel(table,row,14,color,color1,color2,RW_ExcelItiem.ExcelO);
    SetAnalyExcel(table,row,15,color,color1,color2,RW_ExcelItiem.ExcelP);
    SetAnalyExcel(table,row,16,color,color1,color2,RW_ExcelItiem.ExcelQ);
}

void wrexcelprocess::SetAnalyExcel(QTableWidget *table, int row,int cel,
                                   int color, int color1, int color2, QString ExcelCEL)
{
    QTableWidgetItem *ExcelCEL_1 = new QTableWidgetItem(ExcelCEL);
    table->setItem(row, cel, ExcelCEL_1);
    table->item(row, cel)->setTextAlignment(Qt::AlignHCenter);
    table->item(row, cel)->setBackgroundColor(QColor(color,color1,color2));
}

QList<RW_Excel> wrexcelprocess::UPRead_Excel(QList<QList<QVariant> > m_datas)
{
    QList<RW_Excel> RW_Excellist;
    QList< QList<QVariant> >::iterator iter;
    iter = m_datas.begin();
    int count=0;
    for(; iter != m_datas.end() ; ++iter)
    {
        RW_Excel RW_ExcelItiem;
        RW_ExcelItiem.ExcelA=m_datas[count].at(0).toString();
        RW_ExcelItiem.ExcelB=m_datas[count].at(1).toString();
        RW_ExcelItiem.ExcelC=m_datas[count].at(2).toString();
        RW_ExcelItiem.ExcelD=m_datas[count].at(3).toString();
        RW_ExcelItiem.ExcelE=m_datas[count].at(4).toString();
        RW_ExcelItiem.ExcelF=m_datas[count].at(5).toString();
        RW_ExcelItiem.ExcelG=m_datas[count].at(6).toString();
        RW_ExcelItiem.ExcelH=m_datas[count].at(7).toString();
        RW_ExcelItiem.ExcelI=m_datas[count].at(8).toString();
        RW_ExcelItiem.ExcelJ=m_datas[count].at(9).toString();
        RW_ExcelItiem.ExcelK=m_datas[count].at(10).toString();
        RW_ExcelItiem.ExcelL=m_datas[count].at(11).toString();
        RW_ExcelItiem.ExcelM=m_datas[count].at(12).toString();
        RW_ExcelItiem.ExcelN=m_datas[count].at(13).toString();
        RW_ExcelItiem.ExcelO=m_datas[count].at(14).toString();
        RW_ExcelItiem.ExcelP=m_datas[count].at(15).toString();
        RW_ExcelItiem.ExcelQ=m_datas[count].at(16).toString();
        RW_ExcelItiem.ExcelR=m_datas[count].at(17).toString();
        RW_ExcelItiem.ExcelS=m_datas[count].at(18).toString();
        RW_ExcelItiem.ExcelT=m_datas[count].at(19).toString();
        RW_ExcelItiem.ExcelU=m_datas[count].at(20).toString();
        RW_ExcelItiem.ExcelV=m_datas[count].at(21).toString();
        RW_ExcelItiem.ExcelW=m_datas[count].at(22).toString();
        RW_ExcelItiem.ExcelX=m_datas[count].at(23).toString();
        RW_ExcelItiem.ExcelY=m_datas[count].at(24).toString();
        RW_ExcelItiem.ExcelZ=m_datas[count].at(25).toString();


        RW_ExcelItiem.ExcelAA=m_datas[count].at(26).toString();
        RW_ExcelItiem.ExcelAB=m_datas[count].at(27).toString();
        RW_ExcelItiem.ExcelAC=m_datas[count].at(28).toString();
        RW_ExcelItiem.ExcelAD=m_datas[count].at(29).toString();
        RW_ExcelItiem.ExcelAE=m_datas[count].at(30).toString();
        RW_ExcelItiem.ExcelAF=m_datas[count].at(31).toString();
        RW_ExcelItiem.ExcelAG=m_datas[count].at(32).toString();


        RW_Excellist.append(RW_ExcelItiem);
        count++;
    }

    return RW_Excellist;
}

bool wrexcelprocess::UPWrite_Excel(QList<RW_Excel> Write_ExcelList, QString xlsFile)
{
    QList<QVariant> AllRowsData;//保存所有行数据
    foreach (RW_Excel RW_Excel0, Write_ExcelList) {
        QList<QVariant> RowData;//保存一行数据
        RowData.append(QVariant(RW_Excel0.ExcelA));
        RowData.append(QVariant(RW_Excel0.ExcelB));
        RowData.append(QVariant(RW_Excel0.ExcelC));
        RowData.append(QVariant(RW_Excel0.ExcelD));
        RowData.append(QVariant(RW_Excel0.ExcelE));
        RowData.append(QVariant(RW_Excel0.ExcelF));
        RowData.append(QVariant(RW_Excel0.ExcelG));
        RowData.append(QVariant(RW_Excel0.ExcelH));
        RowData.append(QVariant(RW_Excel0.ExcelI));
        RowData.append(QVariant(RW_Excel0.ExcelJ));
        RowData.append(QVariant(RW_Excel0.ExcelK));
        RowData.append(QVariant(RW_Excel0.ExcelL));
        RowData.append(QVariant(RW_Excel0.ExcelM));
        RowData.append(QVariant(RW_Excel0.ExcelN));
        RowData.append(QVariant(RW_Excel0.ExcelO));
        RowData.append(QVariant(RW_Excel0.ExcelP));
        RowData.append(QVariant(RW_Excel0.ExcelQ));
        RowData.append(QVariant(RW_Excel0.ExcelR));
        RowData.append(QVariant(RW_Excel0.ExcelS));
        RowData.append(QVariant(RW_Excel0.ExcelT));
        RowData.append(QVariant(RW_Excel0.ExcelU));
        RowData.append(QVariant(RW_Excel0.ExcelV));
        RowData.append(QVariant(RW_Excel0.ExcelW));
        RowData.append(QVariant(RW_Excel0.ExcelX));
        RowData.append(QVariant(RW_Excel0.ExcelY));
        RowData.append(QVariant(RW_Excel0.ExcelZ));

        AllRowsData.append(QVariant(RowData));
    }

    if(!AllRowsData.isEmpty() && RW_ExcelActionCount>10){
        //QString timer0=QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
        //QString xlsFile =QFileDialog::getOpenFileName(this,QStringLiteral("选择Excel文件"),"",tr("Exel file(*.xls *.xlsx)"));

        //手动选择路径    取消这两行则默认是指定路径: RWExcelfileName = QDir::currentPath();
        QString xlsFile =QFileDialog::getSaveFileName(this,QStringLiteral("选择Excel文件"),"",tr("Exel file(*.xls *.xlsx)"));
        xlsFile = xlsFile.replace("/","\\");

        QElapsedTimer timer;
        qDebug()<<"open cost:"<<timer.elapsed()<<"ms"<<xlsFile;timer.restart();
        timer.start();
        if(m_xls.isNull())
            m_xls.reset(new CReadExcel);
        m_xls->open(xlsFile);
        qDebug()<<"open cost:"<<timer.elapsed()<<"ms"<<xlsFile;timer.restart();

        m_xls->write1(AllRowsData,xlsFile);
        qDebug()<<"write cost:"<<timer.elapsed()<<"ms";timer.restart();
        m_xls->closeExcel();
    }

    return true;
}


//上转Excel任务
QMap<QString, SAPExcelInfo> wrexcelprocess::UPRead_SAPExcelInfo(QString Priority, int taskLeadType)
{
    QMap<QString, SAPExcelInfo>Read_List;m_datas.clear();
    QString xlsFile = QFileDialog::getOpenFileName(this,QStringLiteral("选择Excel文件"),"",tr("Exel file(*.xls *.xlsx)"));
    //QString xlsFile="E:/ASM_two/ASM_ALG/RWExcel/20190428165922asm.xlsx";

    CurrentxlsFile="";
    if(!xlsFile.isEmpty()&& RW_ExcelActionCount>=5){
        Write_Excelbool=false;Read_Excelbool=true;
        //Instance::GetInstance()->setLblMovieStatus(1);//0 隐藏后台正在处理中 1 显示后台正在处理中
        this->setCursor(Qt::BusyCursor);//后台运行状态
        QElapsedTimer timer;
        timer.start();
        if(m_xls.isNull())
            m_xls.reset(new CReadExcel);
        m_xls->open(xlsFile);
        qDebug()<<"open cost:"<<timer.elapsed()<<"ms";timer.restart();
        m_xls->setCurrentSheet(1);
        m_xls->readAll(m_datas);


        if(taskLeadType==1){//任务导入类型  1正常导入  2 DN类型导入  3 其他类型如 261
            Read_List=ReturnSAPExcelInfo(m_datas,Priority);
        }if(taskLeadType==2){
            //Read_List=ReturnSAPExcelInfo_DN(m_datas,Priority);
        }if(taskLeadType==3){
            Read_List=ReturnSAPExcelInfo_other(m_datas,Priority);
        }

        qDebug()<<"read data cost:"<<timer.elapsed()<<"ms"<<"Read_List="<<Read_List.size();timer.restart();

        m_xls->closeExcel();
        CurrentxlsFile=xlsFile;
        qDebug()<<"路径: "<<CurrentxlsFile<<xlsFile;
    }

    this->setCursor(Qt::ArrowCursor);//正常状态

    return Read_List;

}

QString wrexcelprocess::GETxlsFile()
{
    return CurrentxlsFile;
}

QMap<QString, SAPExcelInfo> wrexcelprocess::ReturnSAPExcelInfo(QList<QList<QVariant> > m_datas,QString Priority)
{
    QMap<QString, SAPExcelInfo> RW_Excellist;
    QList< QList<QVariant> >::iterator iter;
    iter = m_datas.begin();
    int count=0;
    for(; iter != m_datas.end() ; ++iter)
    {
        if(m_datas[count].at(0).toString().trimmed().isEmpty())
        {
            continue;
        }
        SAPExcelInfo RW_ExcelItiem;
//        RW_ExcelItiem.Picture=m_datas[count].at(0).toString();     //贴纸对应模板          A
        RW_ExcelItiem.Priority=Priority.toInt();    //优先级               B
//        RW_ExcelItiem.IssueType=m_datas[count].at(2).toString();   //发料类型             C
//        RW_ExcelItiem.LabelType=m_datas[count].at(3).toString();   //贴纸类型             D
        RW_ExcelItiem.LabelNo=m_datas[count].at(0).toString();       //贴纸凭证号           E
        qDebug()<<"AV RW_ExcelItiem.LabelNo"<<RW_ExcelItiem.LabelNo;
        RW_ExcelItiem.creatTimer=QDateTime::currentDateTime();


        if(count>=1 && RW_ExcelItiem.LabelNo!=""){
            RW_Excellist.insert(RW_ExcelItiem.LabelNo,RW_ExcelItiem);
        }

        count++;
    }

    if(!RW_Excellist.isEmpty()){RW_Excellist.remove("LabelNoLabelItem");}
    return RW_Excellist;
}

QMap<QString, SAPExcelInfo> wrexcelprocess::ReturnSAPExcelInfo_other(QList<QList<QVariant> > m_datas, QString Priority)
{
    QMap<QString, SAPExcelInfo> RW_Excellist;
    QList< QList<QVariant> >::iterator iter;
    iter = m_datas.begin();
    int count=0;
    for(; iter != m_datas.end() ; ++iter)
    {
        /************其他类型 新增部分参数定义   数据库不用新增列***************/

        SAPExcelInfo RW_ExcelItiem;
        RW_ExcelItiem.Priority=Priority.toInt();    //优先级
        RW_ExcelItiem.LabelNo=m_datas[count].at(0).toString().trimmed();     //A 贴纸凭证号
        //RW_ExcelItiem.LabelItem=m_datas[count].at(1).toString().trimmed();   //B 贴纸项目      （当LabelItem>基数上浮%20，分为两个工作，并分给不同工作台）

        if(RW_ExcelItiem.LabelNo!="" && RW_ExcelItiem.LabelNo.right(5).left(3)!="/00"){
            //RW_ExcelItiem.LabelNo=RW_ExcelItiem.LabelNo+"/000"+RW_ExcelItiem.LabelItem.trimmed();
        }
        if(count>=1 && RW_ExcelItiem.LabelNo!=""){
            RW_ExcelItiem.creatTimer=QDateTime::currentDateTime();
            RW_Excellist.insert(RW_ExcelItiem.LabelNo,RW_ExcelItiem);
        }
        qDebug()<<"other RW_ExcelItiem.LabelNo"<<RW_ExcelItiem.LabelNo<<count<<RW_Excellist.size();
        qDebug()<<"other LabelNo:"<<RW_ExcelItiem.LabelNo;

        count++;
    }

    if(!RW_Excellist.isEmpty()){RW_Excellist.remove("LabelNoLabelItem");}
    return RW_Excellist;
}

QMap<QString,agvSubTask > wrexcelprocess::ON_read_movepointmap()
{
    QMap<QString,agvSubTask >Read_List;m_datas.clear();
    QString xlsFile = QFileDialog::getOpenFileName(this,QStringLiteral("选择Excel文件"),"",tr("Exel file(*.xls *.xlsx)"));
    //QString xlsFile="E:/ASM_two/ASM_ALG/RWExcel/20190428165922asm.xlsx";

    qDebug()<<"路径0: "<<CurrentxlsFile<<xlsFile;
    CurrentxlsFile="";
    if(!xlsFile.isEmpty()){
        //Instance::GetInstance()->setLblMovieStatus(1);//0 隐藏后台正在处理中 1 显示后台正在处理中
        this->setCursor(Qt::BusyCursor);//后台运行状态
        QElapsedTimer timer;
        timer.start();
        if(m_xls.isNull())
            m_xls.reset(new CReadExcel);
        m_xls->open(xlsFile);
        qDebug()<<"open cost:"<<timer.elapsed()<<"ms";timer.restart();
        m_xls->setCurrentSheet(1);
        m_xls->readAll(m_datas);

        Read_List=read_movepointmap(m_datas,"0");

        qDebug()<<"read data cost:"<<timer.elapsed()<<"ms"<<"Read_List="<<Read_List.size();timer.restart();

        m_xls->closeExcel();
        CurrentxlsFile=xlsFile;
        qDebug()<<"路径: "<<CurrentxlsFile<<xlsFile;
    }

    this->setCursor(Qt::ArrowCursor);//正常状态

    return Read_List;
}

QMap<QString,agvSubTask > wrexcelprocess::read_movepointmap(QList<QList<QVariant> > m_datas,QString Priority)
{

    QMap<QString,agvSubTask > RW_Excellist;
    QList< QList<QVariant> >::iterator iter;
    iter = m_datas.begin();
    int count=0;int TaskId_=1000;
    for(; iter != m_datas.end() ; ++iter)
    {
        agvSubTask agvSubTaskItiem;
        agvSubTaskItiem.Id=m_datas[count].at(0).toInt();                                 //编号
        agvSubTaskItiem.RouteName=m_datas[count].at(1).toString().trimmed();             //路线名
        agvSubTaskItiem.TaskId=m_datas[count].at(2).toInt();                             //路径内序号
        agvSubTaskItiem.Point=quint32(m_datas[count].at(3).toInt());                     //AGV基本任务 起始点
        agvSubTaskItiem.NextPoint=quint32(m_datas[count].at(4).toInt());                 //AGV基本任务 下一点
        agvSubTaskItiem.NextPointDistance=quint16(m_datas[count].at(5).toInt());         //AGV基本任务 下一点距离
        agvSubTaskItiem.AGVSpeed=quint8(m_datas[count].at(6).toInt());                   //AGV基本任务 速度
        agvSubTaskItiem.RotaryLowBarrierInstruction=quint8(m_datas[count].at(7).toInt());//AGV基本任务 顶盘降下时 激光方案（无货架）
        agvSubTaskItiem.RotaryHighBarrierInstruction=quint8(m_datas[count].at(8).toInt());//AGV基本任务 顶盘举升时 激光方案（有货架）
        agvSubTaskItiem.postureAngle=quint16(m_datas[count].at(9).toInt());               //AGV基本任务 姿态角度
        agvSubTaskItiem.AGVMoveAnage=quint16(m_datas[count].at(10).toInt());              //AGV基本任务 移动角度
        agvSubTaskItiem.AGVRotaryAngle=quint16(m_datas[count].at(11).toInt());            //AGV基本任务 转盘角度

        QString SubTaskType = m_datas[count].at(12).toString();//AGV基本任务 基本任务类型  0正向  -1反向
        agvSubTaskItiem.SubTaskType=0;
        QString ikey=QString::number(agvSubTaskItiem.Point)+"_"+QString::number(agvSubTaskItiem.NextPoint);
        if(count>=1 && !RW_Excellist.contains(ikey)){
            agvSubTaskItiem.Id=RW_Excellist.size()+1;
            RW_Excellist.insert(ikey,agvSubTaskItiem);
        }
        qDebug()<<" agvSubTaskItiem--"<<agvSubTaskItiem.Id<<ikey<<count<<RW_Excellist.size();

        if(SubTaskType=="是"){
            agvSubTaskItiem.TaskId=--TaskId_;
            agvSubTaskItiem.SubTaskType=-1;
            quint32 Point=agvSubTaskItiem.NextPoint;
            quint32 NextPoint=agvSubTaskItiem.Point;
            agvSubTaskItiem.Point=Point;
            agvSubTaskItiem.NextPoint=NextPoint;
            if(agvSubTaskItiem.AGVMoveAnage<180){
                agvSubTaskItiem.AGVMoveAnage=agvSubTaskItiem.AGVMoveAnage+180;
            }else{
                agvSubTaskItiem.AGVMoveAnage=agvSubTaskItiem.AGVMoveAnage-180;
            }
            QString ikey=QString::number(agvSubTaskItiem.Point)+"_"+QString::number(agvSubTaskItiem.NextPoint);
            if(count>=1 && !RW_Excellist.contains(ikey)){
                agvSubTaskItiem.Id=RW_Excellist.size()+1;
                RW_Excellist.insert(ikey,agvSubTaskItiem);
            }
            qDebug()<<" agvSubTaskItiem-- 是"<<agvSubTaskItiem.Id<<ikey<<count<<RW_Excellist.size();

        }
        count++;
    }

    TaskId_=TaskId_-1;
    QMap<QString ,agvSubTask >::iterator iter_=RW_Excellist.begin();
    while (iter_!=RW_Excellist.end()) {
        if(iter_.value().SubTaskType==-1){
            iter_.value().TaskId=iter_.value().TaskId-TaskId_;
            RW_Excellist.insert(iter_.key(),iter_.value());
        }
        iter_++;
    }

    if(!RW_Excellist.isEmpty()){RW_Excellist.remove("LabelNoLabelItem");}
    return RW_Excellist;
}

void wrexcelprocess::on_readexcel_clicked()
{
    QString xlsFile = QFileDialog::getOpenFileName(this,QStringLiteral("选择Excel文件"),"",tr("Exel file(*.xls *.xlsx)"));
//    QString xlsFile="E:/ASM_two/ASM_ALG/RWExcel/20190428165922asm.xlsx";
//    qDebug()<<"路径: "<<xlsFile;
    if(RW_ExcelActionCount<15){return;}
    Write_Excelbool=false;Read_Excelbool=true;
    QElapsedTimer timer;
    timer.start();
    if(m_xls.isNull())
        m_xls.reset(new CReadExcel);
    m_xls->open(xlsFile);
    qDebug()<<"open cost:"<<timer.elapsed()<<"ms";timer.restart();
    m_xls->setCurrentSheet(1);
    m_xls->readAll(m_datas);
    qDebug()<<"read data cost:"<<timer.elapsed()<<"ms";timer.restart();

    QList<RW_Excel>Read_List=UPRead_Excel(m_datas);
    if(!Read_List.isEmpty()){
        Read_ExcelItiemList.clear();Read_ExcelItiemList=Read_List;
    }
    m_xls->closeExcel();

}

void wrexcelprocess::on_writeexcel_clicked()
{
    Write_ExcelItiemList=Read_ExcelItiemList;
    Write_Excelbool=true;Read_Excelbool=false;
    QList<QVariant> AllRowsData;//保存所有行数据
    foreach (RW_Excel RW_Excel0, Write_ExcelItiemList) {
        QList<QVariant> RowData;//保存一行数据
        RowData.append(QVariant(RW_Excel0.ExcelA));
        RowData.append(QVariant(RW_Excel0.ExcelB));
        RowData.append(QVariant(RW_Excel0.ExcelC));
        RowData.append(QVariant(RW_Excel0.ExcelD));
        RowData.append(QVariant(RW_Excel0.ExcelE));
        RowData.append(QVariant(RW_Excel0.ExcelF));
        RowData.append(QVariant(RW_Excel0.ExcelG));
        RowData.append(QVariant(RW_Excel0.ExcelH));
        RowData.append(QVariant(RW_Excel0.ExcelI));
        RowData.append(QVariant(RW_Excel0.ExcelJ));
        RowData.append(QVariant(RW_Excel0.ExcelK));
        RowData.append(QVariant(RW_Excel0.ExcelL));
        RowData.append(QVariant(RW_Excel0.ExcelM));
        RowData.append(QVariant(RW_Excel0.ExcelN));
        RowData.append(QVariant(RW_Excel0.ExcelO));
        RowData.append(QVariant(RW_Excel0.ExcelP));
        RowData.append(QVariant(RW_Excel0.ExcelQ));
        AllRowsData.append(QVariant(RowData));
    }

    if(!AllRowsData.isEmpty() && RW_ExcelActionCount>10){
        QString timer0=QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
        QString xlsFile =timer0+"asm.xlsx";//= QFileDialog::getOpenFileName(this,QStringLiteral("选择Excel文件"),"",tr("Exel file(*.xls *.xlsx)"));
        QElapsedTimer timer;
        qDebug()<<"open cost:"<<timer.elapsed()<<"ms"<<xlsFile;timer.restart();
        timer.start();
        if(m_xls.isNull())
            m_xls.reset(new CReadExcel);
        m_xls->open(xlsFile);
        qDebug()<<"open cost:"<<timer.elapsed()<<"ms"<<xlsFile;timer.restart();

        m_xls->write(AllRowsData);
        qDebug()<<"write cost:"<<timer.elapsed()<<"ms";timer.restart();
        m_xls->closeExcel();
    }

}

void wrexcelprocess::slotswrexcelTimer()
{
    if(RW_ExcelActionCount<15){RW_ExcelActionCount++;}
    if(Read_Excelbool){
        UP_TableWidget(ui->tableWidget,Read_ExcelItiemList);
    }
    if(Write_Excelbool){
        UP_TableWidget(ui->tableWidget,Write_ExcelItiemList);
    }
    //int timercount=QDateTime::currentDateTime().toString("hhmm").toInt();
}

void wrexcelprocess::on_Btn_Close_clicked()
{
    this->hide();
}

//导出 WS01
void wrexcelprocess::on_EXCEL_WS01_clicked(QDateTime QDateTimeS, QDateTime QDateTimeE)
{
    QList<RW_Excel> Write_ExcelList;
    RW_Excel RW_ExcelItiem;
    RW_ExcelItiem.ExcelA="labelNo";
    RW_ExcelItiem.ExcelB="base_qty";
    RW_ExcelItiem.ExcelC="base_unit";
    RW_ExcelItiem.ExcelD="batch";
    RW_ExcelItiem.ExcelE="bin";
    RW_ExcelItiem.ExcelF="customsType";
    RW_ExcelItiem.ExcelG="desc";
    RW_ExcelItiem.ExcelH="issueBin";
    RW_ExcelItiem.ExcelI="issueStore";
    RW_ExcelItiem.ExcelJ="IssueType";
    RW_ExcelItiem.ExcelK="material";
    RW_ExcelItiem.ExcelL="message";
    RW_ExcelItiem.ExcelM="plant";
    RW_ExcelItiem.ExcelN="qty";
    RW_ExcelItiem.ExcelO="result";
    RW_ExcelItiem.ExcelP="store";
    RW_ExcelItiem.ExcelQ="unit";
    RW_ExcelItiem.ExcelR="unitOfWeigh";
    RW_ExcelItiem.ExcelS="weighUnit";
    RW_ExcelItiem.ExcelT="timer";

    Write_ExcelList.append(RW_ExcelItiem);

    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    sqlQuery.setForwardOnly(true);
    sqlQuery.prepare("select * from record_ws01 "
                     "where timer >=:timer and timer <=:timer;");
    sqlQuery.addBindValue(QDateTimeS);
    sqlQuery.addBindValue(QDateTimeE);

    SAPExcelInfo SAPExcelInfoI;
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            RW_Excel RW_ExcelItiem;
            RW_ExcelItiem.ExcelA=sqlQuery.value("labelNo").toString();
            RW_ExcelItiem.ExcelB=sqlQuery.value("base_qty").toString();
            RW_ExcelItiem.ExcelC=sqlQuery.value("base_unit").toString();
            RW_ExcelItiem.ExcelD=sqlQuery.value("batch").toString();
            RW_ExcelItiem.ExcelE=sqlQuery.value("bin").toString();
            RW_ExcelItiem.ExcelF=sqlQuery.value("customsType").toString();
            RW_ExcelItiem.ExcelG=sqlQuery.value("describe").toString();
            RW_ExcelItiem.ExcelH=sqlQuery.value("issueBin").toString();
            RW_ExcelItiem.ExcelI=sqlQuery.value("issueStore").toString();
            RW_ExcelItiem.ExcelJ=sqlQuery.value("IssueType").toString();
            RW_ExcelItiem.ExcelK=sqlQuery.value("material").toString();
            RW_ExcelItiem.ExcelL=sqlQuery.value("message").toString();
            RW_ExcelItiem.ExcelM=sqlQuery.value("plant").toString();
            RW_ExcelItiem.ExcelN=sqlQuery.value("qty").toString();
            RW_ExcelItiem.ExcelO=sqlQuery.value("result").toString();
            RW_ExcelItiem.ExcelP=sqlQuery.value("store").toString();
            RW_ExcelItiem.ExcelQ=sqlQuery.value("unit").toString();
            RW_ExcelItiem.ExcelR=sqlQuery.value("unitOfWeigh").toString();
            RW_ExcelItiem.ExcelS=sqlQuery.value("weighUnit").toString();
            RW_ExcelItiem.ExcelT=sqlQuery.value("timer").toString().mid(0,16);

            Write_ExcelList.append(RW_ExcelItiem);

        }
    }else {
        qDebug()<<"weighUnitMap"<<sqlQuery.record();
    }

    QString timer=QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm");
    QString xlsFile=RWExcelfileName+timer+"WS01接口数据.xlsx";
    UPWrite_Excel(Write_ExcelList,xlsFile);
}

//导出 WS05
void wrexcelprocess::on_EXCEL_WS05_clicked(QDateTime QDateTimeS, QDateTime QDateTimeE)
{
    QList<RW_Excel> Write_ExcelList;
    RW_Excel RW_ExcelItiem;
    RW_ExcelItiem.ExcelA="AV_Lable";
    RW_ExcelItiem.ExcelB="AssyNO";
    RW_ExcelItiem.ExcelC="Component";
    RW_ExcelItiem.ExcelD="LABELTYP";
    RW_ExcelItiem.ExcelE="LBL_TYPE";
    RW_ExcelItiem.ExcelF="OBJNR";
    RW_ExcelItiem.ExcelG="ORDERN";
    RW_ExcelItiem.ExcelH="Order";
    RW_ExcelItiem.ExcelI="OrderQty";
    RW_ExcelItiem.ExcelJ="PROD_SCHLR";
    RW_ExcelItiem.ExcelK="Qty";
    RW_ExcelItiem.ExcelL="START_DATE";
    RW_ExcelItiem.ExcelM="plant";
    RW_ExcelItiem.ExcelN="returnMsg";
    RW_ExcelItiem.ExcelO="customsType";
    RW_ExcelItiem.ExcelP="issueType";
    RW_ExcelItiem.ExcelQ="newTimer";

    Write_ExcelList.append(RW_ExcelItiem);

    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();

    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.setForwardOnly(true);
    sqlQuery.prepare("select * from record_ws05a "
                     "where timer >=:timer and timer <=:timer;");
    sqlQuery.addBindValue(QDateTimeS);
    sqlQuery.addBindValue(QDateTimeE);


    SAPExcelInfo SAPExcelInfoI;
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            RW_Excel RW_ExcelItiem;
            RW_ExcelItiem.ExcelA=sqlQuery.value("AV_Lable").toString();
            RW_ExcelItiem.ExcelB=sqlQuery.value("AssyNO").toString();
            RW_ExcelItiem.ExcelC=sqlQuery.value("Component").toString();
            RW_ExcelItiem.ExcelD=sqlQuery.value("LABELTYP").toString();
            RW_ExcelItiem.ExcelE=sqlQuery.value("LBL_TYPE").toString();
            RW_ExcelItiem.ExcelF=sqlQuery.value("OBJNR").toString();
            RW_ExcelItiem.ExcelG=sqlQuery.value("ORDERN").toString();
            RW_ExcelItiem.ExcelH=sqlQuery.value("Order").toString();
            RW_ExcelItiem.ExcelI=sqlQuery.value("OrderQty").toString();
            RW_ExcelItiem.ExcelJ=sqlQuery.value("PROD_SCHLR").toString();
            RW_ExcelItiem.ExcelK=sqlQuery.value("Qty").toString();
            RW_ExcelItiem.ExcelL=sqlQuery.value("START_DATE").toString();
            RW_ExcelItiem.ExcelM=sqlQuery.value("plant").toString();
            RW_ExcelItiem.ExcelN=sqlQuery.value("returnMsg").toString();
            RW_ExcelItiem.ExcelO=sqlQuery.value("customsType").toString();
            RW_ExcelItiem.ExcelP=sqlQuery.value("issueType").toString();
            RW_ExcelItiem.ExcelQ=sqlQuery.value("newTimer").toString();
            Write_ExcelList.append(RW_ExcelItiem);

        }
    }else {
        qDebug()<<"weighUnitMap"<<sqlQuery.record();
    }

    QString timer=QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm");
    QString xlsFile=RWExcelfileName+timer+"WS05_A接口数据.xlsx";
    UPWrite_Excel(Write_ExcelList,xlsFile);
}

//导出 出入库及查仓日志
bool wrexcelprocess::on_EXCEL_Log_clicked(QMap<int, record_log> Record_logMap)
{
    QList<RW_Excel> Write_ExcelList;
    RW_Excel RW_ExcelItiem;
    RW_ExcelItiem.ExcelA="任务类型";
    RW_ExcelItiem.ExcelB="标签条码";
    RW_ExcelItiem.ExcelC="物料件号";
    RW_ExcelItiem.ExcelD="仓号";
    RW_ExcelItiem.ExcelE="批次";
    RW_ExcelItiem.ExcelF="单位";
    RW_ExcelItiem.ExcelG="SAP数量";
    RW_ExcelItiem.ExcelH="实取数量";
    RW_ExcelItiem.ExcelI="SAP单个重量(kg)";
    RW_ExcelItiem.ExcelJ="称出单个重量";
    RW_ExcelItiem.ExcelK="称出总重";
    RW_ExcelItiem.ExcelL="计数的数量";
    RW_ExcelItiem.ExcelM="称重类型 ";
    RW_ExcelItiem.ExcelN="任务类型";
    RW_ExcelItiem.ExcelO="架位号Bin";
    RW_ExcelItiem.ExcelP="操作员";
    RW_ExcelItiem.ExcelQ="操作台编号";
    RW_ExcelItiem.ExcelR="批次Id";
    RW_ExcelItiem.ExcelS="创建时间";
    RW_ExcelItiem.ExcelT="完成时间";
    Write_ExcelList.append(RW_ExcelItiem);

    QMap<int, record_log>::Iterator iter= Record_logMap.begin();
    while (iter!=Record_logMap.end()) {
        RW_ExcelItiem.ExcelA=iter.value().IssueDesc;
        RW_ExcelItiem.ExcelB=iter.value().LabelNo;
        RW_ExcelItiem.ExcelC=iter.value().Material;
        RW_ExcelItiem.ExcelD=iter.value().store;
        RW_ExcelItiem.ExcelE=iter.value().batch;
        RW_ExcelItiem.ExcelF=iter.value().Unit;
        RW_ExcelItiem.ExcelG=QString::number(iter.value().sapQty);//SAP 数量
        RW_ExcelItiem.ExcelH=QString::number(iter.value().readlQty);//实际取数量
        RW_ExcelItiem.ExcelI=QString::number(iter.value().base_weigh*1000);//SAP单个重
        RW_ExcelItiem.ExcelJ=QString::number(iter.value().weigh_base*1000);//称出单个重量
        RW_ExcelItiem.ExcelK=QString::number(iter.value().allWeigh*1000);//称出总重   (kg)
        RW_ExcelItiem.ExcelL=QString::number(iter.value().weigh_pcs);
        RW_ExcelItiem.ExcelM=iter.value().WeighType;
        RW_ExcelItiem.ExcelN=iter.value().taskType;
        RW_ExcelItiem.ExcelO=iter.value().shelfBindesc;
        RW_ExcelItiem.ExcelP=iter.value().UserNumber;
        RW_ExcelItiem.ExcelQ=QString::number(iter.value().operaterIndex);
        RW_ExcelItiem.ExcelR=iter.value().pickType;
        RW_ExcelItiem.ExcelS=iter.value().creatTime;
        RW_ExcelItiem.ExcelT=iter.value().Time.toString();

        Write_ExcelList.append(RW_ExcelItiem);
        ++iter;
    }

    QString timer=QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm");
    QString xlsFile=RWExcelfileName+timer+"出入库日志.xlsx";
    UPWrite_Excel(Write_ExcelList,xlsFile);

    return true;
}

//导出库存数据
bool wrexcelprocess::on_EXCEL_store_clicked(QMap<QString, materialShelfbin> Record_checkMap)
{
    QList<RW_Excel> Write_ExcelList;
    RW_Excel RW_ExcelItiem;
    RW_ExcelItiem.ExcelA="序号";
    RW_ExcelItiem.ExcelB="物料件号";
    RW_ExcelItiem.ExcelC="仓号";
    RW_ExcelItiem.ExcelD="批次";
    RW_ExcelItiem.ExcelE="单位";
    RW_ExcelItiem.ExcelF="库存数量";
    RW_ExcelItiem.ExcelG="复核数量";
    RW_ExcelItiem.ExcelH="架位编号";
    RW_ExcelItiem.ExcelI="盘点人";
    RW_ExcelItiem.ExcelJ="盘点时间";
    Write_ExcelList.append(RW_ExcelItiem);

    QMap<QString, materialShelfbin>::Iterator iter= Record_checkMap.begin();
    while (iter!=Record_checkMap.end()) {
        RW_ExcelItiem.ExcelA=QString::number(Write_ExcelList.size());
        RW_ExcelItiem.ExcelB=iter.value().materialNumber;
        RW_ExcelItiem.ExcelC=iter.value().storeCode;
        RW_ExcelItiem.ExcelD=iter.value().customsType;
        RW_ExcelItiem.ExcelE=iter.value().base_unit;
        RW_ExcelItiem.ExcelF=QString::number(iter.value().realqty);
        RW_ExcelItiem.ExcelG="--";
        RW_ExcelItiem.ExcelH=iter.value().shelfBindesc;
        RW_ExcelItiem.ExcelI=iter.value().lastuser;
        RW_ExcelItiem.ExcelJ=iter.value().lastCheckTimer.toString("yyyy-MM-dd hh:mm:ss");
        Write_ExcelList.append(RW_ExcelItiem);
        ++iter;
    }

    QString timer=QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm");
    QString xlsFile=RWExcelfileName+timer+"AGV盘点数据.xlsx";
    UPWrite_Excel(Write_ExcelList,xlsFile);

    return true;
}

