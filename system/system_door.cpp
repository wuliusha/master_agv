#include "system_door.h"
#include "ui_system_door.h"

system_door::system_door(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::system_door)
{
    ui->setupUi(this);
    system_doorInit();      //自动门类  初始化函数
}

system_door::~system_door()
{
    delete ui;
}

void system_door::system_doorInit()
{
    Actionbtns<<ui->query_door<<ui->add_door<<ui->delete_door<<ui->update_door;

    table_single::GetInstance()->TableWidgetInit(ui->tableWidget_door,12,"QHeaderView::section{background-color:rgb(193,205,205);font:12pt '宋体';color: black;};",35,35);
    connect(ui->tableWidget_door,&QTableWidget::cellClicked,this,&system_door::SlotsetCurrentItem_door);

}

void system_door::TableWidget_show_door()
{
    ui->tableWidget_door->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    QList<RW_Excel> ExcelList=TableWidget_door(doorSubTaskMap);
    QStringList comBoxlist;//comBoxlist<<"0"<<"-1";
    table_single::GetInstance()->UP_TableWidget(ui->tableWidget_door,ExcelList,comBoxlist,0);
    if(ExcelList.isEmpty()){
        ui->tableWidget_door->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
        return;
    }
    ui->tableWidget_door->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
    ui->tableWidget_door->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    ui->tableWidget_door->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->tableWidget_door->horizontalHeader()->setSectionResizeMode(5,QHeaderView::ResizeToContents);
}

QList<RW_Excel> system_door::TableWidget_door(QMap<int, doorSubTask> doorSubTaskMap_)
{
    QList<RW_Excel> ExcelList;
    doorSubTask doorSubTask_;
    doorSubTaskI=doorSubTask_;
    QMap<int, doorSubTask>::const_iterator iter= doorSubTaskMap_.begin();
    while (iter!=doorSubTaskMap_.end()) {
        int incount=0;
        RW_Excel RW_ExcelItem;
        RW_ExcelItem.ExcelA=QString::number(iter.value().doorId);
        RW_ExcelItem.ExcelB=iter.value().doorIP;
        RW_ExcelItem.ExcelC=iter.value().doorDesc;
        RW_ExcelItem.ExcelD=QString::number(iter.value().Point);
        RW_ExcelItem.ExcelE=QString::number(iter.value().NextPoint);
        RW_ExcelItem.ExcelF=iter.value().NextPointdesc;
        RW_ExcelItem.ExcelG="---";
        RW_ExcelItem.ExcelH="---";
        RW_ExcelItem.ExcelI="---";
        RW_ExcelItem.ExcelJ=QString::number(iter.value().enable);
        RW_ExcelItem.ExcelK=QString::number(iter.value().page);

        RW_ExcelItem.checked=iter.value().checked;
        if(iter.value().checked==1){
            doorSubTaskI=iter.value();
            doorSubTaskI.row=ExcelList.size();
        }if(incount==0){
            incount=1;
            RW_ExcelItem.corlor=0;       // 0
            ExcelList.append(RW_ExcelItem);
        }
        ++iter;
    }

    return ExcelList;
}

void system_door::SlotsetCurrentItem_door(int row, int column)
{
    if(!doorSubTaskMap.isEmpty()){
        int doorId=ui->tableWidget_door->item(row,0)->text().trimmed().toInt();
        QMap<int,doorSubTask>::iterator iter= doorSubTaskMap.begin();
        while (iter!=doorSubTaskMap.end()) {
            if(iter.value().doorIP!=nullptr){
                if(doorId==iter.value().doorId){
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
            TableWidget_show_door();
        }
    }

}

//查询自动门信息
void system_door::on_query_door_clicked()
{
    QString doorIP=ui->doorIP->text().trimmed();
    doorSubTaskMap=query_Single::GetInstance()->query_doorSubTaskMap(doorIP,0);//查找当前自动门信息
    TableWidget_show_door();
}

//添加自动门
void system_door::on_add_door_clicked()
{
    if(ui->doorIP->text().trimmed()!=""){
        doorSubTask doorSubTask_;
        doorSubTask_.doorIP=ui->doorIP->text().trimmed();
        if(doorSubTask_.doorIP!=""){
            QMap<int,doorSubTask>doorSubTaskMap;
            doorSubTaskMap.insert(doorSubTask_.doorId,doorSubTask_);
            query_Single::GetInstance()->doorSubTaskMap_insert(doorSubTaskMap);    //添加 自动门信息 到数据库
            ui->doorIP->setText("");
            on_query_door_clicked();//查询自动门信息
        }else{

        }
    }

}

void system_door::on_delete_door_clicked()
{
    if(!doorSubTaskMap.isEmpty()){
        if(doorSubTaskI.doorIP!="" && doorSubTaskI.doorId>0){
            query_Single::GetInstance()->doorSubTask_Delete(doorSubTaskI.doorId); //删除 站点路线信息
            on_query_door_clicked();        //查询自动门信息
        }
    }
}

void system_door::on_update_door_clicked()
{
    if(!doorSubTaskMap.isEmpty() && doorSubTaskI.doorIP!=""){
        int doorId=ui->tableWidget_door->item(doorSubTaskI.row,0)->text().trimmed().toInt();
        if(doorSubTaskI.doorIP!="" && doorSubTaskI.doorId==doorId){
            doorSubTaskI.doorDesc=ui->tableWidget_door->item(doorSubTaskI.row,2)->text().trimmed();
            doorSubTaskI.Point=ui->tableWidget_door->item(doorSubTaskI.row,3)->text().trimmed().toInt();
            doorSubTaskI.NextPoint=ui->tableWidget_door->item(doorSubTaskI.row,4)->text().trimmed().toInt();
            doorSubTaskI.NextPointdesc=ui->tableWidget_door->item(doorSubTaskI.row,5)->text().trimmed();
            doorSubTaskI.enable=ui->tableWidget_door->item(doorSubTaskI.row,9)->text().trimmed().toInt();
            doorSubTaskI.page=ui->tableWidget_door->item(doorSubTaskI.row,10)->text().trimmed().toInt();

            QMap<int,doorSubTask>doorSubTaskMap_;
            doorSubTaskMap_.insert(doorSubTaskI.doorId,doorSubTaskI);
            query_Single::GetInstance()->doorSubTask_update(doorSubTaskMap_);       //更新 自动门信息
            on_query_door_clicked(); //查找当前自动门信息
        }
    }
}


void system_door::ON_Pressed()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    Instance::GetInstance()->SetButton_pressed(Button,"background-color: rgb(85,255,127);color:#ffffff;color: white;  border: 2px groove gray;\
                                               border-radius:15px;border-style: outset");
}

void system_door::ON_Released()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    Instance::GetInstance()->SetButton_released(Button,"color: white;border: 2px groove gray;border-radius:15px;border:none;background-color: rgb(0, 166, 172);");
}
