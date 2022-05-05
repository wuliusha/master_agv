#include "dooritem.h"
#include "ui_dooritem.h"

doorItem::doorItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::doorItem)
{
    ui->setupUi(this);
}

doorItem::~doorItem()
{
    delete ui;
}
