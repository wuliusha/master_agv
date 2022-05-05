#ifndef DOORITEM_H
#define DOORITEM_H

#include <QWidget>

namespace Ui {
class doorItem;
}

class doorItem : public QWidget
{
    Q_OBJECT

public:
    explicit doorItem(QWidget *parent = nullptr);
    ~doorItem();

private:
    Ui::doorItem *ui;
};

#endif // DOORITEM_H
