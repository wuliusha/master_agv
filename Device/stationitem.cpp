#include "stationitem.h"
#include "ui_stationitem.h"

stationItem::stationItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stationItem)
{
    ui->setupUi(this);
}

stationItem::~stationItem()
{
    delete ui;
}
