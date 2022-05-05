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
    StoreInfoTimer->start(600);

}

StoreInfo::~StoreInfo()
{
    delete ui;
}


void StoreInfo::upStoreInfoTimer()
{
    if(ThreadInsertI->ActionItiem.SAPAction > 1){//0 无状态 1 执行更新 2 更新完成  3 执行取消  4取消完成
        if(ThreadInsertI->ActionItiem.SAPAction==2){
            ThreadInsertI->ActionItiem.SAPAction=0;
        }if(ThreadInsertI->ActionItiem.SAPAction==4){
            ThreadInsertI->ActionItiem.SAPAction=0;
        }
    }
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

    Actionbtns<<ui->query_Button;
    for(int i=0;i<Actionbtns.length();i++){
        connect(Actionbtns[i],&QPushButton::pressed,this,&StoreInfo::ON_Pressed);
        connect(Actionbtns[i],&QPushButton::released,this,&StoreInfo::ON_Released);
    }

}

void StoreInfo::setCurrentBinInfo(int podId)
{
    currentBinInfoMap.clear();
    currentBinInfoMap=shelfBinInfoMap_query(podId);           //获取 Bin 的基础信息
    if(!currentBinInfoMap.isEmpty()){
        if(WidgetBinQMap.isEmpty()){
            newWidgetBin();     //创建显示Item
        }else{
            UPdateWidgetBin();  //更新显示 Item
        }
    }
}

void StoreInfo::newWidgetBin()
{
    int sWidth=160;int height=150;
    QMap<QString ,shelfBinInfo >::const_iterator iter=currentBinInfoMap.begin();
    while(iter!=currentBinInfoMap.end()){
        if(iter!=nullptr){
            WidgetBin *WidgetBinI=new WidgetBin(ui->widget,iter.value().shelfBinIndex);

            WidgetBinI->BinIndexdesc=iter.value().podIdDesc.right(6);//所属架位显示索引
            WidgetBinI->shelfBinInfoItem=iter.value();

            WidgetBinI->sWidth=100;WidgetBinI->sHeight=100;
            WidgetBinI->podId=iter.value().podId;

            WidgetBinI->layer=iter.value().layer;
            WidgetBinI->side=iter.value().side;
            WidgetBinI->color="#6a6da9";        //默认颜色

            WidgetBinI->showY=iter.value().layer*height-140;
            int Width=iter.value().podIdDesc.right(1).toInt();
            WidgetBinI->showX=10+sWidth*(Width-1);

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
        iter++;
    }

}

void StoreInfo::UPdateWidgetBin()
{
    QMap<QString ,shelfBinInfo >::const_iterator iter=currentBinInfoMap.begin();
    while(iter!=currentBinInfoMap.end()){
        if(iter!=nullptr){
            QString BinIndexdesc=iter.value().podIdDesc.right(6);   //所属架位显示索引
            if(WidgetBinQMap.contains(BinIndexdesc)){
                WidgetBinQMap.find(BinIndexdesc).value()->shelfBinInfoItem=iter.value();
                WidgetBinQMap.find(BinIndexdesc).value()->SetValue(100);
            }
        }else{
            return;
        }
        iter++;
    }

}

QMap<QString, shelfBinInfo> StoreInfo::shelfBinInfoMap_query(int podId)
{
    QMap<QString ,shelfBinInfo>currentBinInfoMap_;

    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    sqlQuery.setForwardOnly(true);

    sqlQuery.prepare("select * from shelfInfo where podId=:podId ;");
    sqlQuery.addBindValue(podId);

    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            shelfBinInfo shelfBinInfoI;
            shelfBinInfoI.shelfBinIndex=sqlQuery.value("shelfBinIndex").toInt();        //所属架位索引
            shelfBinInfoI.shelfBindesc=sqlQuery.value("shelfBindesc").toString();       //所属架位注释
            shelfBinInfoI.podId=sqlQuery.value("podId").toInt();                        //货架编号
            shelfBinInfoI.podIdDesc=sqlQuery.value("podIdDesc").toString();             //货架注释

            shelfBinInfoI.containerIndex=sqlQuery.value("containerIndex").toInt();      //容器编码索引 ->唯一
            shelfBinInfoI.containerCode=sqlQuery.value("containerCode").toString();     //容器编码 (即胶箱编码) ->唯一
            shelfBinInfoI.LabelNo=sqlQuery.value("LabelNo").toString();                 //工单凭证号

            shelfBinInfoI.storeCode=sqlQuery.value("storeCode").toString();             //仓号属性

            shelfBinInfoI.binEnable=sqlQuery.value("binEnable").toInt();                //使用/禁用
            shelfBinInfoI.showEnable=sqlQuery.value("showEnable").toInt();              //是否显示
            shelfBinInfoI.setFull=sqlQuery.value("setFull").toInt();                    //0未满  1已满
            shelfBinInfoI.status=sqlQuery.value("status").toInt();                      //0 空闲  1任务占用中

            shelfBinInfoI.layer=sqlQuery.value("layer").toInt();                        //第几层
            shelfBinInfoI.side=sqlQuery.value("side").toInt();                          //A,B 面

            shelfBinInfoI.volume=sqlQuery.value("volume").toDouble();                   //Bin的体积 14升
            shelfBinInfoI.allvolume=sqlQuery.value("allvolume").toDouble();             //总体积

            shelfBinInfoI.percent=sqlQuery.value("percent").toDouble();                 //占用 %
            shelfBinInfoI.realqty=sqlQuery.value("realqty").toDouble();                 //实际存放数量

            shelfBinInfoI.weight=sqlQuery.value("weight").toDouble();                   //实际存放重量
            shelfBinInfoI.maxweight=sqlQuery.value("maxweight").toDouble();             //最大存放重量

            if(!currentBinInfoMap_.contains(shelfBinInfoI.shelfBindesc)){
                currentBinInfoMap_.insert(shelfBinInfoI.shelfBindesc,shelfBinInfoI);
                //qDebug()<<shelfBinInfoI.shelfBinIndex<<shelfBinInfoI.shelfBindesc<<shelfBinInfoI.podId<<shelfBinInfoI.podIdDesc;
            }
        }
    }

    return currentBinInfoMap_;
}


void StoreInfo::ON_shelfBinInfo(shelfBinInfo shelfBinInfoItem)
{
    shelfBinInfoItem.materialShelfbinMap=queryServer::getInstance()->querymaterialshelfBinMap(shelfBinInfoItem);
    binwidgetItem->shelfBinInfoItem=shelfBinInfoItem;
    binwidgetItem->UPShelfNuberInfoShow(shelfBinInfoItem,"action",currentUserNuber);//更新显示此货架上物料信息
}


void StoreInfo::on_query_Button_clicked()
{
    shelfBinInfoMap= ESS_Single::GetInstance()->getshelfBinInfoMap();//获取 Bin 的实时状态信息链表
    if(!ui->queryMaterial->text().isEmpty()){
        shelfBinInfo shelfBinInfoI;
        QString queryType=ui->queryTypeBox->currentText().trimmed();
        QString queryMaterial=ui->queryMaterial->text().trimmed();
        QMap<QString ,shelfBinInfo >::const_iterator iter=shelfBinInfoMap.begin();
        while(iter!=shelfBinInfoMap.end()){
            if(iter!=nullptr){
                if(queryType=="货架编号" && iter.value().podIdDesc.left(3)==queryMaterial){
                    shelfBinInfoI=iter.value();
                }if(queryType=="胶箱编码" && iter.value().containerCode==queryMaterial){
                    shelfBinInfoI=iter.value();
                }if(queryType=="工单编码" && iter.value().LabelNo==queryMaterial){
                    shelfBinInfoI=iter.value();
                }
            }else{
                return;
            }
            iter++;
        }

        if(shelfBinInfoI.shelfBinIndex!=0){
            setCurrentBinInfo(shelfBinInfoI.podId);       //设置当前显示的货架
            //qDebug()<<shelfBinInfoI.shelfBinIndex<<shelfBinInfoI.shelfBindesc<<shelfBinInfoI.podId<<shelfBinInfoI.podIdDesc<<shelfBinInfoI.containerCode;
        }else{
            queryServer::getInstance()->SetMessagebox("暂无满足查询条件的选项.");
        }

    }else{
        queryServer::getInstance()->SetMessagebox("请输入查询条件");
    }
}

void StoreInfo::on_queryMaterial_returnPressed()
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

                    shelfBinInfoI.podId=podId;               //货架编号
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

void StoreInfo::ON_Pressed()
{
    QPushButton *Button = (QPushButton *)this->sender();
    Instance::GetInstance()->SetButton_pressed(Button,"background-color: rgb(85,255,127);border-radius:5px;color:#ffffff;color: white;  border: 2px groove gray;\
                                               border-style: outset");
}

void StoreInfo::ON_Released()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    if(Button->objectName()=="query_Button"|| Button->objectName()=="UP_Button"){
        Instance::GetInstance()->SetButton_pressed(Button,"background-color: rgb(0, 166, 172);color:#ffffff;color: white;  border: 2px groove gray;\
                                                         border-radius:15px;border-style: outset");
    }else{
        Instance::GetInstance()->SetButton_pressed(Button,"color:#ffffff;color: white;  border: 2px groove gray;\
                                                             border-radius:15px;border-style: outset");
    }
}



