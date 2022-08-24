#include "storeinfo.h"
#include "ui_storeinfo.h"
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase0)

StoreInfo::StoreInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StoreInfo)
{
    ui->setupUi(this);
    StoreInfoInit();
    StoreInfoTimer = new QTimer(this);
    connect(StoreInfoTimer,&QTimer::timeout,this,&StoreInfo::upStoreInfoTimer);
    StoreInfoTimer->start(500);

}

StoreInfo::~StoreInfo()
{
    delete ui;
}


void StoreInfo::upStoreInfoTimer()
{
    StoreTimercount++;
    if(StoreTimercount<=60){
        if(storeTimerbool && StoreTimercount%20==0){
            storeTimerbool=false;
            on_query_Button_clicked();
            storeTimerbool=true;
        }
    }
    if(StoreTimercount>100000){StoreTimercount=0;}

}

void StoreInfo::StoreInfoInit()
{
    ThreadInsertI=new ThreadInsert;
    ThreadInsertItiem=new QThread();
    ThreadInsertI->moveToThread(ThreadInsertItiem);
    ThreadInsertItiem->start();

//    QMap<QString, shelfBinInfo> newshelfBinInfoMap=newshelfBinInfo();//创建库位
//    ThreadInsertI->insertIntoshelfBinInfoInfo(newshelfBinInfoMap);

    threadQueryI=new threadQuery;
    threadQueryItem=new QThread();
    threadQueryI->moveToThread(threadQueryItem);
    threadQueryItem->start();

    ui->stackedWidget->widget(0)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget->widget(1)->layout()->setContentsMargins(0,0,0,0);

    binwidgetItem =new binwidget;
    binwidgetItem->setVisible(true);
    ui->stackedWidget_3->insertWidget(0,binwidgetItem);
    ui->stackedWidget_3->widget(0)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget_3->setCurrentIndex(0);

    connect(binwidgetItem,&binwidget::sig_SAPExcelInfo_new,this,&StoreInfo::ON_SAPExcelInfo_new);
    connect(binwidgetItem,&binwidget::sig_containerCode_clear,this,&StoreInfo::ON_containerCode_clear);

}


void StoreInfo::newWidgetBin()
{
    int sWidth=160;int height=145;
    QMap<QString ,shelfBinInfo >::const_iterator iter=currentBinInfoMap.begin();
    while(iter!=currentBinInfoMap.end()){
        if(iter!=nullptr){
            WidgetBin *WidgetBinI=new WidgetBin(ui->widget,iter.value().shelfBinIndex);

            WidgetBinI->shelfBinInfoItem=iter.value();

            WidgetBinI->sWidth=100;WidgetBinI->sHeight=100;
            WidgetBinI->podId=iter.value().podId;

            WidgetBinI->layer=iter.value().layer;
            WidgetBinI->side=iter.value().side;
            WidgetBinI->color="#6a6da9";        //默认颜色

            WidgetBinI->showY=iter.value().layer*height-140;
            if(iter.value().podIdDesc.size()>=10){
                WidgetBinI->BinIndexdesc=iter.value().podIdDesc.right(6);//所属架位显示索引
                int Width=iter.value().podIdDesc.right(1).toInt();
                WidgetBinI->showX=10+sWidth*(Width-1);
            }
            WidgetBinI->move(WidgetBinI->showX,WidgetBinI->showY);
            WidgetBinI->setCursor(Qt::SizeAllCursor);//鼠标形状对应的枚举值：
            WidgetBinI->setVisible(true);
            WidgetBinI->resize(125,125);
            WidgetBinI->SetValue(100);//实时更新柱状图 数据以及图形分布
            connect(WidgetBinI,&WidgetBin::signalshelfBinInfo,this,&StoreInfo::ON_shelfBinInfo);

            if(!WidgetBinQMap.contains(WidgetBinI->BinIndexdesc)){
                WidgetBinQMap.insert(WidgetBinI->BinIndexdesc,WidgetBinI);
            }

        }else{
            return;
        }
        ++iter;
    }
}

void StoreInfo::UPdateWidgetBin()
{
    QMap<QString ,shelfBinInfo >::const_iterator iter=currentBinInfoMap.begin();
    while(iter!=currentBinInfoMap.end()){
        if(iter!=nullptr){
             if(iter.value().podIdDesc.size()>=10){
                 QString BinIndexdesc=iter.value().podIdDesc.right(6);   //所属架位显示索引
                 if(WidgetBinQMap.contains(BinIndexdesc)){
                     WidgetBinQMap.find(BinIndexdesc).value()->shelfBinInfoItem=iter.value();
                     WidgetBinQMap.find(BinIndexdesc).value()->SetValue(100);
                 }
             }
        }else{
            return;
        }
        ++iter;
    }
}

void StoreInfo::ON_shelfBinInfo(shelfBinInfo shelfBinInfoItem)
{
    binwidgetItem->shelfBinInfoItem=shelfBinInfoItem;
    binwidgetItem->UPShelfNuberInfoShow(shelfBinInfoItem,"action",currentUserNuber);//更新显示此货架上物料信息
}

void StoreInfo::ON_SAPExcelInfo_new(SAPExcelInfo SAPExcelInfoI)
{
    if(StoreTimercount<12){return;}
    StoreTimercount=0;
    emit sig_SAPExcelInfo_new(SAPExcelInfoI);  //创建MES任务
}

void StoreInfo::ON_containerCode_clear(QString shelfBindesc, QString containerCode,QString type)
{
    if(StoreTimercount<12){return;}
    StoreTimercount=0;
    emit sig_containerCode_clear(shelfBindesc,containerCode,type);
}

void StoreInfo::on_query_Button_clicked()
{
    if(!ui->queryLineEdit->text().isEmpty()){
        QString taskType="";
        if(ui->queryTypeBox->currentText().trimmed()=="货架编号"){
            taskType="podId";
        }if(ui->queryTypeBox->currentText().trimmed()=="胶箱编码"){
            taskType="containerCode";
        }
        currentBinInfoMap= ESS_Single::getInstance()->getshelfBinInfoMap(taskType,ui->queryLineEdit->text().trimmed(),"");//获取 Bin 的实时状态信息链表
        if(!currentBinInfoMap.isEmpty()){
            if(WidgetBinQMap.isEmpty()){
                newWidgetBin();     //创建显示Item
            }else{
                UPdateWidgetBin();  //更新显示 Item
            }
        }
    }else{
        queryServer::getInstance()->SetMessagebox("暂无满足查询条件的选项.");
    }
}

void StoreInfo::on_queryLineEdit_returnPressed()
{
    on_query_Button_clicked();
}


//WXYL05-010-04  备注: 第五排 第十列 第四层
//A01-01-004     备注: A排01号货架 第一层第四列
QMap<QString, shelfBinInfo> StoreInfo::newshelfBinInfo()
{
    QStringList podesc;podesc<<"A"<<"B"<<"C"<<"D"<<"E"<<"F";
    QMap<QString, shelfBinInfo> newshelfBinInfoMap;

    int cel=1;
    int podId=1;
    for (int b=1;b<16;b++) {

        for (int a=1;a<7;a++){

            for (int j=1;j<6;j++){

                cel=4*(b-1)+1;
                for (int i=1;i<=4;i++){

                    shelfBinInfo shelfBinInfoI;
                    shelfBinInfoI.layer=j;               //货架位层数

                    QString podIdDesc=QString("%1").arg(b,2, 10, QLatin1Char('0'));//前
                    QString Bindesc=QString("%1").arg(a,2, 10, QLatin1Char('0'));//前补 0

                    QString celesc=QString("%1").arg(cel,3, 10, QLatin1Char('0'));//前补 0;
                    QString wodesc=QString("%1").arg(j,2, 10, QLatin1Char('0'));//前补 0;

                    shelfBinInfoI.podId=podesc[a-1]+podIdDesc;               //货架编号
                    shelfBinInfoI.podIdDesc=podesc[a-1]+podIdDesc+"-"+wodesc+"-"+QString("%1").arg(i,3, 10, QLatin1Char('0'));  //货架注释

                    QString celesc_=QString("%1").arg(cel+2,3, 10, QLatin1Char('0'));//前补 0;
                    shelfBinInfoI.shelfBinIndex=newshelfBinInfoMap.size()+1;       //所属架位索引
                    shelfBinInfoI.shelfBindesc="WWYL"+Bindesc+"-"+celesc_+"-"+wodesc;   //所属架位注释

                    if(!newshelfBinInfoMap.contains(shelfBinInfoI.shelfBindesc)){
                        newshelfBinInfoMap.insert(shelfBinInfoI.shelfBindesc,shelfBinInfoI);

                        qDebug()<<shelfBinInfoI.shelfBinIndex<<shelfBinInfoI.shelfBindesc
                               <<shelfBinInfoI.podId<<shelfBinInfoI.podIdDesc<<" layer:"<<shelfBinInfoI.layer;

                    }

                    cel++;
                }

            }

            podId++;
        }


    }

    return newshelfBinInfoMap;
}

void StoreInfo::on_pushButton_clicked()
{
    currentBinInfoMap= ESS_Single::getInstance()->getshelfBinInfoMap("","","");//获取 Bin 的实时状态信息链表
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    QMap<QString,shelfBinInfo>::const_iterator iter=currentBinInfoMap.begin();
    while (iter!=currentBinInfoMap.end()) {
        if(iter!=nullptr){
            sqlQuery.prepare("UPDATE [dbo].[shelfInfo] SET [podId]=:podId "
                             "WHERE ([shelfBindesc]=:shelfBindesc);");
            sqlQuery.addBindValue(iter.value().podIdDesc.split("-").at(0));
            sqlQuery.addBindValue(iter.value().shelfBindesc);
            if(sqlQuery.exec()){

            }
        }else{
            return ;
        }
        ++iter;
    }

}

