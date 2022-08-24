#include "system_station.h"
#include "ui_system_station.h"

system_station::system_station(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::system_station)
{
    ui->setupUi(this);
    system_stationInit();          //站点类 初始化函数
}

system_station::~system_station()
{
    delete ui;
}

void system_station::system_stationInit()
{

    Actionbtns<<ui->query_station<<ui->add_station<<ui->delete_station<<ui->update_station;

    table_single::GetInstance()->TableWidgetInit(ui->tableWidget_station,12,"QHeaderView::section{background-color:rgb(193,205,205);font:12pt '宋体';color: black;};",35,35);
    connect(ui->tableWidget_station,&QTableWidget::cellClicked,this,&system_station::SlotsetCurrentItem_station);   //站点信息

}

void system_station::TableWidget_show_station()
{
    ui->tableWidget_station->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    QList<RW_Excel> ExcelList=TableWidget_station(Stationmap_Map);
    QStringList comBoxlist;//comBoxlist<<"0"<<"-1";
    table_single::GetInstance()->UP_TableWidget(ui->tableWidget_station,ExcelList,comBoxlist,0);
    if(ExcelList.isEmpty()){
        ui->tableWidget_station->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
        return;
    }
    ui->tableWidget_station->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
    //ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);

}

QList<RW_Excel> system_station::TableWidget_station(QMap<QString, Stationmap> Stationmap_)
{
    QList<RW_Excel> ExcelList;
    Stationmap StationmapI;
    currentStationmap=StationmapI;
    QMap<QString, Stationmap>::const_iterator iter= Stationmap_.begin();
    while (iter!=Stationmap_.end()) {
        int incount=0;
        RW_Excel RW_ExcelItem;
        RW_ExcelItem.ExcelA=QString::number(ExcelList.size()+1);
        RW_ExcelItem.ExcelB=iter.value().StationName;                   //工位名称
        RW_ExcelItem.ExcelC=QString::number(iter.value().StationPoint); //工位二维码
        RW_ExcelItem.ExcelD=QString::number(iter.value().StartPoint);   // StationPoint==StartPoint  出去  StationPoint！=StartPoint  进工位
        RW_ExcelItem.ExcelE=QString::number(iter.value().PassPoint);    //经过二维码 0
        RW_ExcelItem.ExcelF=QString::number(iter.value().PassPoint1);   //经过二维码 1
        RW_ExcelItem.ExcelG=QString::number(iter.value().PassPoint2);   //经过二维码 2
        RW_ExcelItem.ExcelH=QString::number(iter.value().PassPoint3);   //经过二维码 3
        RW_ExcelItem.ExcelI=QString::number(iter.value().assistPoint);  //辅路线  对接点
        RW_ExcelItem.ExcelJ=iter.value().assistRoute;                   //与工位连接的辅路线
        RW_ExcelItem.ExcelK=QString::number(iter.value().SubTaskType); //AGV基本任务 基本任务类型  0正向  -1反向

        RW_ExcelItem.checked=iter.value().checked;
        if(iter.value().checked==1){
            currentStationmap=iter.value();
            currentStationmap.row=ExcelList.size();
        }
        if(incount==0){
            incount=1;
            RW_ExcelItem.corlor=0;       // 0
            ExcelList.append(RW_ExcelItem);
        }
        ++iter;
    }

    return ExcelList;
}

//站点信息
void system_station::SlotsetCurrentItem_station(int row, int column)
{
    if(!Stationmap_Map.isEmpty()){
        QString StationName=ui->tableWidget_station->item(row,1)->text().trimmed();
        QMap<QString,Stationmap>::iterator iter= Stationmap_Map.begin();
        while (iter!=Stationmap_Map.end()) {
            if(iter.value().StationName!=nullptr){
                if(StationName==iter.value().StationName){
                    iter.value().checked=1;
                }else {
                    iter.value().checked=0;
                }
            }else{
                return;
            }
            ++iter;
        }
        if(column<2){
            TableWidget_show_station();
        }
    }

}

void system_station::on_query_station_clicked()
{
    QString StationName=ui->StationName->text().trimmed();
    Stationmap_Map=query_Single::GetInstance()->query_Stationmap(StationName);
    TableWidget_show_station();
}

void system_station::on_add_station_clicked()
{
    if(ui->StationName->text()!=""){
        Stationmap StationmapI;
        QMap<QString,Stationmap >Stationmap_Map;
        StationmapI.StationName=ui->StationName->text().trimmed();
        Stationmap_Map.insert(currentStationmap.StationName,StationmapI);
        query_Single::GetInstance()->Stationmap_insert(Stationmap_Map);    //添加 站点路线信息 到数据库
        on_query_station_clicked();//查询站点绑定信息
        ui->StationName->setText("");
    }else{

    }
}

void system_station::on_delete_station_clicked()
{
    if(!Stationmap_Map.isEmpty()){
        if(currentStationmap.StationName!=""){
            query_Single::GetInstance()->Stationmap_Delete(currentStationmap.StationName); //删除 站点路线信息
            on_query_station_clicked();//查询站点绑定信息
        }
    }
}

void system_station::on_update_station_clicked()
{
    if(!Stationmap_Map.isEmpty()){
        if(currentStationmap.StationName==ui->tableWidget_station->item(currentStationmap.row,1)->text().trimmed()){
            currentStationmap.StationPoint=ui->tableWidget_station->item(currentStationmap.row,2)->text().trimmed().toInt();                  //工位二维码
            currentStationmap.StartPoint = ui->tableWidget_station->item(currentStationmap.row,3)->text().trimmed().toInt();                    // StationPoint==StartPoint  出去  StationPoint！=StartPoint  进工位
            currentStationmap.PassPoint = ui->tableWidget_station->item(currentStationmap.row,4)->text().trimmed().toInt();                     //经过二维码 0
            currentStationmap.PassPoint1 = ui->tableWidget_station->item(currentStationmap.row,5)->text().trimmed().toInt();                    //经过二维码 1
            currentStationmap.PassPoint2 = ui->tableWidget_station->item(currentStationmap.row,6)->text().trimmed().toInt();                    //经过二维码 2
            currentStationmap.PassPoint3 = ui->tableWidget_station->item(currentStationmap.row,7)->text().trimmed().toInt();                    //经过二维码 3
            currentStationmap.assistPoint = ui->tableWidget_station->item(currentStationmap.row,8)->text().trimmed().toInt();                   //辅路线  对接点
            currentStationmap.assistRoute=ui->tableWidget_station->item(currentStationmap.row,9)->text().trimmed();                //与工位连接的辅路线
            currentStationmap.SubTaskType = ui->tableWidget_station->item(currentStationmap.row,10)->text().trimmed().toInt();                   //AGV基本任务 基本任务类型  0正向  -1反向
            QMap<QString,Stationmap> Stationmap_Map;
            Stationmap_Map.insert(currentStationmap.StationName,currentStationmap);
            query_Single::GetInstance()->Stationmap_update(Stationmap_Map);    //更新 站点路线信息
        }
        on_query_station_clicked();//查询站点绑定信息
    }
}


void system_station::ON_Pressed()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    Instance::GetInstance()->SetButton_pressed(Button,"background-color: rgb(85,255,127);color:#ffffff;color: white;  border: 2px groove gray;\
                                               border-radius:15px;border-style: outset");
}

void system_station::ON_Released()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    Instance::GetInstance()->SetButton_released(Button,"color: white;border: 2px groove gray;border-radius:15px;border:none;background-color: rgb(0, 166, 172);");
}
