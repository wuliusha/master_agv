/********************************************************************************
** Form generated from reading UI file 'wrexcelprocess.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WREXCELPROCESS_H
#define UI_WREXCELPROCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wrexcelprocess
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *BtnReturn;
    QLabel *labTitle;
    QPushButton *Btn_Edit;
    QPushButton *Btn_Close;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit;
    QPushButton *readexcel;
    QPushButton *writeexcel;

    void setupUi(QWidget *wrexcelprocess)
    {
        if (wrexcelprocess->objectName().isEmpty())
            wrexcelprocess->setObjectName(QString::fromUtf8("wrexcelprocess"));
        wrexcelprocess->resize(1202, 675);
        wrexcelprocess->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(81, 81, 81);"));
        gridLayout_2 = new QGridLayout(wrexcelprocess);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(wrexcelprocess);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        BtnReturn = new QPushButton(widget);
        BtnReturn->setObjectName(QString::fromUtf8("BtnReturn"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BtnReturn->sizePolicy().hasHeightForWidth());
        BtnReturn->setSizePolicy(sizePolicy);
        BtnReturn->setStyleSheet(QString::fromUtf8("color:#FEFEFE;\n"
"background-color: rgb(81, 81, 81);"));

        horizontalLayout->addWidget(BtnReturn);

        labTitle = new QLabel(widget);
        labTitle->setObjectName(QString::fromUtf8("labTitle"));
        sizePolicy.setHeightForWidth(labTitle->sizePolicy().hasHeightForWidth());
        labTitle->setSizePolicy(sizePolicy);
        labTitle->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        labTitle->setFont(font);
        labTitle->setStyleSheet(QString::fromUtf8("color:#FEFEFE;\n"
"background-color: rgb(81, 81, 81);"));
        labTitle->setTextFormat(Qt::PlainText);
        labTitle->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labTitle);

        Btn_Edit = new QPushButton(widget);
        Btn_Edit->setObjectName(QString::fromUtf8("Btn_Edit"));
        sizePolicy.setHeightForWidth(Btn_Edit->sizePolicy().hasHeightForWidth());
        Btn_Edit->setSizePolicy(sizePolicy);
        Btn_Edit->setStyleSheet(QString::fromUtf8("color:#FEFEFE;\n"
"background-color: rgb(81, 81, 81);"));

        horizontalLayout->addWidget(Btn_Edit);

        Btn_Close = new QPushButton(widget);
        Btn_Close->setObjectName(QString::fromUtf8("Btn_Close"));
        sizePolicy.setHeightForWidth(Btn_Close->sizePolicy().hasHeightForWidth());
        Btn_Close->setSizePolicy(sizePolicy);
        Btn_Close->setStyleSheet(QString::fromUtf8("color:#FEFEFE;\n"
"background-color: rgb(81, 81, 81);"));

        horizontalLayout->addWidget(Btn_Close);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 10);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout->addWidget(widget);

        tableWidget = new QTableWidget(wrexcelprocess);
        if (tableWidget->columnCount() < 17)
            tableWidget->setColumnCount(17);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        lineEdit = new QLineEdit(wrexcelprocess);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(16);
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(81, 81, 81);"));

        horizontalLayout_2->addWidget(lineEdit);

        readexcel = new QPushButton(wrexcelprocess);
        readexcel->setObjectName(QString::fromUtf8("readexcel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(readexcel->sizePolicy().hasHeightForWidth());
        readexcel->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setPointSize(20);
        readexcel->setFont(font2);

        horizontalLayout_2->addWidget(readexcel);

        writeexcel = new QPushButton(wrexcelprocess);
        writeexcel->setObjectName(QString::fromUtf8("writeexcel"));
        sizePolicy2.setHeightForWidth(writeexcel->sizePolicy().hasHeightForWidth());
        writeexcel->setSizePolicy(sizePolicy2);
        writeexcel->setFont(font2);

        horizontalLayout_2->addWidget(writeexcel);

        horizontalLayout_2->setStretch(0, 8);
        horizontalLayout_2->setStretch(1, 5);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 20);
        verticalLayout->setStretch(2, 1);

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(wrexcelprocess);

        QMetaObject::connectSlotsByName(wrexcelprocess);
    } // setupUi

    void retranslateUi(QWidget *wrexcelprocess)
    {
        wrexcelprocess->setWindowTitle(QApplication::translate("wrexcelprocess", "Form", nullptr));
        BtnReturn->setText(QString());
        labTitle->setText(QApplication::translate("wrexcelprocess", "RW_Excel", nullptr));
        Btn_Edit->setText(QString());
        Btn_Close->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("wrexcelprocess", "A", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("wrexcelprocess", "B", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("wrexcelprocess", "C", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("wrexcelprocess", "D", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("wrexcelprocess", "E", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("wrexcelprocess", "F", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("wrexcelprocess", "G", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("wrexcelprocess", "H", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("wrexcelprocess", "I", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("wrexcelprocess", "J", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("wrexcelprocess", "K", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("wrexcelprocess", "L", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("wrexcelprocess", "M", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("wrexcelprocess", "N", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("wrexcelprocess", "O", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("wrexcelprocess", "P", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->horizontalHeaderItem(16);
        ___qtablewidgetitem16->setText(QApplication::translate("wrexcelprocess", "Q", nullptr));
        lineEdit->setText(QString());
        readexcel->setText(QApplication::translate("wrexcelprocess", "Read", nullptr));
        writeexcel->setText(QApplication::translate("wrexcelprocess", "Write", nullptr));
    } // retranslateUi

};

namespace Ui {
    class wrexcelprocess: public Ui_wrexcelprocess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WREXCELPROCESS_H
