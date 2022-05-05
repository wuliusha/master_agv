#include "liftitem.h"
#include "ui_liftitem.h"

liftItem::liftItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::liftItem)
{
    ui->setupUi(this);
}

liftItem::~liftItem()
{
    delete ui;
}
