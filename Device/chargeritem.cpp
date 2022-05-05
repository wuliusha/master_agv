#include "chargeritem.h"
#include "ui_chargeritem.h"

chargerItem::chargerItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chargerItem)
{
    ui->setupUi(this);
}

chargerItem::~chargerItem()
{
    delete ui;
}
