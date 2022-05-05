#ifndef CHARGERITEM_H
#define CHARGERITEM_H

#include <QWidget>

namespace Ui {
class chargerItem;
}

class chargerItem : public QWidget
{
    Q_OBJECT

public:
    explicit chargerItem(QWidget *parent = nullptr);
    ~chargerItem();

private:
    Ui::chargerItem *ui;
};

#endif // CHARGERITEM_H
