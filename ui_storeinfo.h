/********************************************************************************
** Form generated from reading UI file 'storeinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOREINFO_H
#define UI_STOREINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StoreInfo
{
public:
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QStackedWidget *stackedWidget_2;
    QWidget *page_3;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QComboBox *queryTypeBox;
    QLineEdit *queryMaterial;
    QLineEdit *lineEdit_count;
    QSpacerItem *horizontalSpacer;
    QWidget *page_4;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QLineEdit *queryMaterial_2;
    QPushButton *lead_Button;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *query_Button;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QWidget *page_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QStackedWidget *stackedWidget_3;
    QWidget *page_5;
    QWidget *page_6;
    QWidget *widget;

    void setupUi(QWidget *StoreInfo)
    {
        if (StoreInfo->objectName().isEmpty())
            StoreInfo->setObjectName(QString::fromUtf8("StoreInfo"));
        StoreInfo->resize(1343, 629);
        StoreInfo->setStyleSheet(QString::fromUtf8("color: rgb(33, 33, 33);"));
        gridLayout_6 = new QGridLayout(StoreInfo);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, -1, 0, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(StoreInfo);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: rgb(148, 214, 218);"));
        gridLayout_5 = new QGridLayout(widget_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, -1, 10, -1);
        stackedWidget_2 = new QStackedWidget(widget_2);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setMaximumSize(QSize(16777215, 60));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_3 = new QGridLayout(page_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(15);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        queryTypeBox = new QComboBox(page_3);
        queryTypeBox->addItem(QString());
        queryTypeBox->addItem(QString());
        queryTypeBox->addItem(QString());
        queryTypeBox->setObjectName(QString::fromUtf8("queryTypeBox"));
        queryTypeBox->setMinimumSize(QSize(160, 37));
        queryTypeBox->setMaximumSize(QSize(160, 37));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        queryTypeBox->setFont(font);
        queryTypeBox->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(0, 166, 172);\n"
"QComboBox::drop-down {\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid; \n"
"	border-left-color: gray;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}"));

        horizontalLayout->addWidget(queryTypeBox);

        queryMaterial = new QLineEdit(page_3);
        queryMaterial->setObjectName(QString::fromUtf8("queryMaterial"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(queryMaterial->sizePolicy().hasHeightForWidth());
        queryMaterial->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        queryMaterial->setFont(font1);
        queryMaterial->setStyleSheet(QString::fromUtf8("color: rgb(45, 45, 45);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(queryMaterial);


        horizontalLayout_4->addLayout(horizontalLayout);

        lineEdit_count = new QLineEdit(page_3);
        lineEdit_count->setObjectName(QString::fromUtf8("lineEdit_count"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_count->sizePolicy().hasHeightForWidth());
        lineEdit_count->setSizePolicy(sizePolicy1);
        lineEdit_count->setMinimumSize(QSize(100, 35));
        lineEdit_count->setMaximumSize(QSize(120, 35));
        lineEdit_count->setFont(font);
        lineEdit_count->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(lineEdit_count);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        gridLayout_3->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        stackedWidget_2->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        gridLayout_4 = new QGridLayout(page_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_9 = new QLabel(page_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"border: 0px groove gray;"));

        horizontalLayout_5->addWidget(label_9);

        queryMaterial_2 = new QLineEdit(page_4);
        queryMaterial_2->setObjectName(QString::fromUtf8("queryMaterial_2"));
        sizePolicy.setHeightForWidth(queryMaterial_2->sizePolicy().hasHeightForWidth());
        queryMaterial_2->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(16);
        queryMaterial_2->setFont(font2);
        queryMaterial_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(queryMaterial_2);


        horizontalLayout_2->addLayout(horizontalLayout_5);

        lead_Button = new QPushButton(page_4);
        lead_Button->setObjectName(QString::fromUtf8("lead_Button"));
        sizePolicy1.setHeightForWidth(lead_Button->sizePolicy().hasHeightForWidth());
        lead_Button->setSizePolicy(sizePolicy1);
        lead_Button->setMinimumSize(QSize(160, 35));
        lead_Button->setFont(font);
        lead_Button->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"border-style: outset;\n"
"border: 2px groove gray; \n"
"border-radius:10px;\n"
"background-color: rgb(81,81,81);"));

        horizontalLayout_2->addWidget(lead_Button);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        gridLayout_4->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        stackedWidget_2->addWidget(page_4);

        horizontalLayout_8->addWidget(stackedWidget_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        query_Button = new QPushButton(widget_2);
        query_Button->setObjectName(QString::fromUtf8("query_Button"));
        sizePolicy1.setHeightForWidth(query_Button->sizePolicy().hasHeightForWidth());
        query_Button->setSizePolicy(sizePolicy1);
        query_Button->setMinimumSize(QSize(160, 45));
        query_Button->setMaximumSize(QSize(160, 45));
        QFont font3;
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        query_Button->setFont(font3);
        query_Button->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"border-radius:15px;\n"
"border-style: outset;\n"
"border: 2px groove gray; \n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_3->addWidget(query_Button);

        horizontalLayout_3->setStretch(0, 1);

        horizontalLayout_8->addLayout(horizontalLayout_3);

        horizontalLayout_8->setStretch(0, 3);
        horizontalLayout_8->setStretch(1, 1);

        gridLayout_5->addLayout(horizontalLayout_8, 0, 0, 1, 1);


        verticalLayout->addWidget(widget_2);

        stackedWidget = new QStackedWidget(StoreInfo);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout = new QGridLayout(page);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget = new QTableWidget(page);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setFont(font2);
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(66, 66, 66);\n"
"color: rgb(33, 33, 33);"));

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_2 = new QGridLayout(page_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        stackedWidget_3 = new QStackedWidget(page_2);
        stackedWidget_3->setObjectName(QString::fromUtf8("stackedWidget_3"));
        stackedWidget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(189, 189, 186);"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        stackedWidget_3->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        stackedWidget_3->addWidget(page_6);

        horizontalLayout_6->addWidget(stackedWidget_3);

        widget = new QWidget(page_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 102, 102);\n"
"background-color: rgb(141, 131, 130);"));

        horizontalLayout_6->addWidget(widget);

        horizontalLayout_6->setStretch(0, 2);
        horizontalLayout_6->setStretch(1, 1);

        gridLayout_2->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);

        gridLayout_6->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(StoreInfo);

        stackedWidget_2->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(StoreInfo);
    } // setupUi

    void retranslateUi(QWidget *StoreInfo)
    {
        StoreInfo->setWindowTitle(QApplication::translate("StoreInfo", "Form", nullptr));
        queryTypeBox->setItemText(0, QApplication::translate("StoreInfo", "\350\264\247\346\236\266\347\274\226\345\217\267", nullptr));
        queryTypeBox->setItemText(1, QApplication::translate("StoreInfo", "\345\267\245\345\215\225\347\274\226\347\240\201", nullptr));
        queryTypeBox->setItemText(2, QApplication::translate("StoreInfo", "\350\203\266\347\256\261\347\274\226\347\240\201", nullptr));

        queryMaterial->setText(QApplication::translate("StoreInfo", "A01", nullptr));
        label_9->setText(QApplication::translate("StoreInfo", "\350\267\257\345\276\204:", nullptr));
        lead_Button->setText(QApplication::translate("StoreInfo", "\345\257\274\345\205\245\346\224\271\344\273\223EXcel", nullptr));
        query_Button->setText(QApplication::translate("StoreInfo", "\346\237\245\350\257\242", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("StoreInfo", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("StoreInfo", "\347\211\251\346\226\231\344\273\266\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("StoreInfo", "\344\273\223\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("StoreInfo", "Bin", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("StoreInfo", "\346\211\271\346\254\241", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("StoreInfo", "\346\225\260\351\207\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("StoreInfo", "\345\237\272\347\241\200\345\215\225\344\275\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StoreInfo: public Ui_StoreInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOREINFO_H
