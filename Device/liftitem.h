#ifndef LIFTITEM_H
#define LIFTITEM_H

#include <QWidget>

namespace Ui {
class liftItem;
}

class liftItem : public QWidget
{
    Q_OBJECT

public:
    explicit liftItem(QWidget *parent = nullptr);
    ~liftItem();

private:
    Ui::liftItem *ui;
};

#endif // LIFTITEM_H
