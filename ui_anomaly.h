/********************************************************************************
** Form generated from reading UI file 'anomaly.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANOMALY_H
#define UI_ANOMALY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Anomaly
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Anomaly)
    {
        if (Anomaly->objectName().isEmpty())
            Anomaly->setObjectName(QString::fromUtf8("Anomaly"));
        Anomaly->resize(507, 300);
        gridLayout = new QGridLayout(Anomaly);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, -1);
        tableWidget = new QTableWidget(Anomaly);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        tableWidget->setFont(font);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget::indicator {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"}QTableWidget::indicator:unchecked {\n"
"    image: url(:/image/unchecked.png);\n"
"}\n"
"QTableWidget::indicator:checked {\n"
"    image: url(:/image/checked.png);\n"
"}\n"
""));

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);


        retranslateUi(Anomaly);

        QMetaObject::connectSlotsByName(Anomaly);
    } // setupUi

    void retranslateUi(QWidget *Anomaly)
    {
        Anomaly->setWindowTitle(QApplication::translate("Anomaly", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Anomaly", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Anomaly", "\345\274\202\345\270\270\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Anomaly: public Ui_Anomaly {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANOMALY_H
