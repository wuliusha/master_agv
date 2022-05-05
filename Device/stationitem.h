#ifndef STATIONITEM_H
#define STATIONITEM_H

#include <QWidget>

namespace Ui {
class stationItem;
}

class stationItem : public QWidget
{
    Q_OBJECT

public:
    explicit stationItem(QWidget *parent = nullptr);
    ~stationItem();

private:
    Ui::stationItem *ui;
};

#endif // STATIONITEM_H
