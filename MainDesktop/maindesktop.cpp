#include "maindesktop.h"
#include "ui_maindesktop.h"

MainDesktop::MainDesktop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainDesktop)
{
    ui->setupUi(this);
    MainDesktopInit();

    DesktopTimer = new QTimer(this);
    connect(DesktopTimer,&QTimer::timeout,this,&MainDesktop::ON_MainDesktopTimer);
    DesktopTimer->start(3000);

}

MainDesktop::~MainDesktop()
{
    delete ui;
}

void MainDesktop::MainDesktopInit()
{

    monitoringServerI=new monitoringServer;        //监控
    threadmonitoringServer=new QThread();
    monitoringServerI->moveToThread(threadmonitoringServer);
    threadmonitoringServer->start();

    ui->stackedWidget_6->insertWidget(0,monitoringServerI->monitoringI);
    ui->stackedWidget_6->setCurrentIndex(0);

    ChartViewItiem=new ChartView;//饼形图
    ui->stackedWidget_2->insertWidget(0,ChartViewItiem);
    ui->stackedWidget_2->setCurrentIndex(0);

//    HistogramiIt0=new Histogram;//柱状图
//    ui->stackedWidget_3->insertWidget(0,HistogramiIt0);
//    ui->stackedWidget_3->setCurrentIndex(0);

    AnomalyItiem=new Anomaly;//异常信息
    ui->stackedWidget_4->insertWidget(0,AnomalyItiem);
    ui->stackedWidget_4->setCurrentIndex(0);

    ui->stackedWidget->widget(0)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget->widget(1)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget_5->widget(0)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget_6->widget(0)->layout()->setContentsMargins(0,0,0,0);

    table_single::GetInstance()->TableWidgetInit(ui->tableWidget,14,"QHeaderView::section{background-color:rgb(77,135,165);font:14pt '宋体';color: white;};",50,55);
    table_single::GetInstance()->TableWidgetInit(ui->tableWidget_2,14,"QHeaderView::section{background-color:rgb(211, 215, 212);font:12pt '宋体';color:#3e4145;};",30,30);
    //connect(ui->tableWidget_2,&QTableWidget::cellClicked,this,&MainDesktop::SlotsetCurrentItem_2);

    //ui->tableWidget_2->setVisible(false);

}

void MainDesktop::SetstackedWidget(int Page)
{
    ui->stackedWidget->setCurrentIndex(Page);
}

void MainDesktop::UPTableWidgetShow()
{
    countpick countpickI;countpickItem=countpickI;
    //currentRecord_logMap=queryServer::getInstance()->queryRecord_log_nowDate();

    QMap<int, record_log>::iterator iter=currentRecord_logMap.begin();//今天创建的所有任务
    while (iter!=currentRecord_logMap.end()) {//任务类型  1出库  2入库 3盘点 4查仓 5改位入库
        if(iter.value().TypeId<10){// >10 的类型为数据员删除
            if(iter.value().TypeId!=2 && iter.value().TypeId!=5){
                countpickItem.finishcount++;
            }
        }
        iter++;
    }

    int finishcount=int(countpickItem.finishcount);    //已完成数量
    int unfinishcount=int(countpickItem.unfinishcount);//未完成数量
    int DN_count=int(countpickItem.DN_count);          //待发DN
    int SL_count=int(countpickItem.SL_count);          //待发SL
    int LM_count=int(countpickItem.LM_count);          //待发LM
    int Other_count=int(countpickItem.Other_count);    //待发Other

    ChartViewItiem->SetChartPercent(finishcount,unfinishcount,DN_count,SL_count,LM_count,Other_count);//实时更新饼形图形百分比分布

//    email_messageMap=queryServer::getInstance()->getemail_message();
//    QMapIterator<int, email_message> itero(email_messageMap);
//    while (itero.hasNext()) {
//        itero.next();
//        AnomalyItiem->SetValue(itero.value().creatTime.toString(),itero.value().message,QString::number(itero.value().status));//Action 1 添加 0删除
//    }

}

void MainDesktop::tableWidget_Show()
{
    seletSAPExcelInfoTask=ESS_Single::GetInstance()->getCurrentSAPExcelInfoTask();
    //解决显示卡顿问题:  https://blog.csdn.net/u014746838/article/details/102642083
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    QStringList comBoxlist;
    QList<RW_Excel> ExcelList=TableWidget();
    table_single::GetInstance()->UP_TableWidget(ui->tableWidget_2,ExcelList,comBoxlist,0);
    if(ExcelList.isEmpty()){
        ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
        return;
    }
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);

}

QList<RW_Excel> MainDesktop::TableWidget()
{
    QList<RW_Excel> ExcelList;
    QList<RW_Excel> ExcelList0;
    QList<RW_Excel> ExcelList1;
    QList<RW_Excel> ExcelList2;
    QList<RW_Excel> ExcelList3;
    QMap<int, SAPExcelInfo>::const_iterator iter= seletSAPExcelInfoTask.begin();
    while (iter!=seletSAPExcelInfoTask.end()) {
        if(iter!=nullptr){
            if(iter.value().taskError==0 && iter.value().taskStatus<100){
                int incount=0;
                RW_Excel RW_ExcelItem;
                RW_ExcelItem.ExcelA=QString::number(iter.value().SAPTaskIndex);
                RW_ExcelItem.ExcelB=iter.value().taskTypeDesc;                          //操作 OUT-出库  IN-入库
                RW_ExcelItem.ExcelC=iter.value().containerCode;                         //容器编码 (即胶箱编码) ->唯一
                RW_ExcelItem.ExcelD=iter.value().Material;                              //物料号
                if(iter.value().taskType=="IN"){
                    RW_ExcelItem.ExcelE=iter.value().destination;                       //起始站点
                    RW_ExcelItem.ExcelF=iter.value().sourcestation;                     //线体名称  入库时对接 输送线对接码头   出库时对应放箱码头
                }if(iter.value().taskType=="OUT"){
                    RW_ExcelItem.ExcelE=iter.value().sourcestation;                     //起始站点
                    RW_ExcelItem.ExcelF=iter.value().destination;                       //线体名称  入库时对接 输送线对接码头   出库时对应放箱码头
                }if(iter.value().taskType=="Empty"){
                    RW_ExcelItem.ExcelE="---";                                          //起始站点
                    RW_ExcelItem.ExcelF=iter.value().sourcestation;                     //线体名称  入库时对接 输送线对接码头   出库时对应放箱码头
                }

                RW_ExcelItem.ExcelG=iter.value().taskStatusDesc+"-"+QString::number(iter.value().taskStatus);                        //任务状态注释
                RW_ExcelItem.ExcelH=iter.value().creatTimer.toString("MM-dd hh:mm:ss"); //创建时间
                RW_ExcelItem.checked=iter.value().checked;

                //二楼正在运行
                if(incount==0 && (iter.value().taskStatus>0 && iter.value().taskStatus<9)){
                    incount=1;
                    RW_ExcelItem.corlor=0;       // 0
                    ExcelList0.append(RW_ExcelItem);
                }

                if(incount==0 && (iter.value().taskStatus>9 && iter.value().taskStatus<15)){
                    incount=1;
                    RW_ExcelItem.corlor=0;       // 0
                    ExcelList1.append(RW_ExcelItem);
                }

                if(incount==0 && iter.value().taskStatus==0){
                    incount=1;
                    RW_ExcelItem.corlor=0;       // 0
                    ExcelList2.append(RW_ExcelItem);
                }

                if(incount==0){
                    incount=1;
                    RW_ExcelItem.corlor=0;       // 0
                    ExcelList3.append(RW_ExcelItem);
                }

            }

        }else{
            return ExcelList;
        }


        iter++;
    }

    ExcelList=ExcelList0+ExcelList1+ExcelList2+ExcelList3;
    return ExcelList;
}




void MainDesktop::ON_MainDesktopTimer()
{
    tableWidget_Show();                          //tableWidget 更新显示
}

void MainDesktop::SlotsetCurrentItem_2(int row, int column)
{

}


void MainDesktop::on_refreshButton_clicked()
{
    UPTableWidgetShow();
}

void MainDesktop::on_refreshButton_pressed()
{
    Instance::GetInstance()->SetButton_pressed(ui->refreshButton,"background-color: rgb(85,255,127);color:#ffffff;color: white;  border: 2px groove gray;\
                                               border-style: outset");
}

void MainDesktop::on_refreshButton_released()
{
    Instance::GetInstance()->SetButton_released(ui->refreshButton,"background-color: rgb(81,81,81);color:#ffffff;color: white;  border: 2px groove gray;\
                                                        border-style: outset");
}
