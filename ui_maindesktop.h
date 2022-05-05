/********************************************************************************
** Form generated from reading UI file 'maindesktop.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDESKTOP_H
#define UI_MAINDESKTOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainDesktop
{
public:
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_4;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_4;
    QPushButton *refreshButton;
    QHBoxLayout *horizontalLayout_4;
    QStackedWidget *stackedWidget_2;
    QWidget *page_3;
    QWidget *page_4;
    QStackedWidget *stackedWidget_3;
    QWidget *page_5;
    QWidget *page_6;
    QStackedWidget *stackedWidget_4;
    QWidget *page_7;
    QWidget *page_8;
    QTableWidget *tableWidget;
    QWidget *page_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_5;
    QStackedWidget *stackedWidget_6;
    QWidget *page_12;
    QStackedWidget *stackedWidget_5;
    QWidget *page_9;
    QGridLayout *gridLayout_6;
    QTableWidget *tableWidget_2;
    QWidget *page_10;

    void setupUi(QWidget *MainDesktop)
    {
        if (MainDesktop->objectName().isEmpty())
            MainDesktop->setObjectName(QString::fromUtf8("MainDesktop"));
        MainDesktop->resize(1089, 620);
        MainDesktop->setStyleSheet(QString::fromUtf8(""));
        gridLayout_5 = new QGridLayout(MainDesktop);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        gridLayout_5->addLayout(verticalLayout_2, 0, 0, 1, 1);

        widget_3 = new QWidget(MainDesktop);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(11, 0, 0, 0);

        gridLayout_5->addWidget(widget_3, 1, 1, 1, 1);

        stackedWidget = new QStackedWidget(MainDesktop);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_3 = new QGridLayout(page);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_4 = new QWidget(page);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_4 = new QGridLayout(widget_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 10, -1);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(16);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color:#00ffff;"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: #EE7621;"));

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: #CDB38B;"));

        horizontalLayout_2->addWidget(label_4);

        refreshButton = new QPushButton(widget_4);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(refreshButton->sizePolicy().hasHeightForWidth());
        refreshButton->setSizePolicy(sizePolicy);
        refreshButton->setMinimumSize(QSize(80, 0));
        refreshButton->setMaximumSize(QSize(100, 35));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        refreshButton->setFont(font1);
        refreshButton->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"border-style: outset;\n"
"border: 2px groove gray; \n"
"background-color: rgb(81,81,81);\n"
""));

        horizontalLayout_2->addWidget(refreshButton);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 4);
        horizontalLayout_2->setStretch(3, 1);
        horizontalLayout_2->setStretch(4, 3);
        horizontalLayout_2->setStretch(5, 1);
        horizontalLayout_2->setStretch(6, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);

        verticalLayout_3->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        stackedWidget_2 = new QStackedWidget(widget_4);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        stackedWidget_2->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget_2->addWidget(page_4);

        horizontalLayout_4->addWidget(stackedWidget_2);

        stackedWidget_3 = new QStackedWidget(widget_4);
        stackedWidget_3->setObjectName(QString::fromUtf8("stackedWidget_3"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        stackedWidget_3->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        stackedWidget_3->addWidget(page_6);

        horizontalLayout_4->addWidget(stackedWidget_3);

        stackedWidget_4 = new QStackedWidget(widget_4);
        stackedWidget_4->setObjectName(QString::fromUtf8("stackedWidget_4"));
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        stackedWidget_4->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        stackedWidget_4->addWidget(page_8);

        horizontalLayout_4->addWidget(stackedWidget_4);


        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 10);

        gridLayout_4->addLayout(verticalLayout_3, 0, 0, 1, 1);


        verticalLayout_4->addWidget(widget_4);

        tableWidget = new QTableWidget(page);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
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
        if (tableWidget->rowCount() < 7)
            tableWidget->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem15);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        tableWidget->setFont(font2);

        verticalLayout_4->addWidget(tableWidget);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 1);

        gridLayout_3->addLayout(verticalLayout_4, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_2 = new QGridLayout(page_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(10);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        stackedWidget_6 = new QStackedWidget(page_2);
        stackedWidget_6->setObjectName(QString::fromUtf8("stackedWidget_6"));
        stackedWidget_6->setStyleSheet(QString::fromUtf8(""));
        page_12 = new QWidget();
        page_12->setObjectName(QString::fromUtf8("page_12"));
        stackedWidget_6->addWidget(page_12);

        verticalLayout_5->addWidget(stackedWidget_6);

        stackedWidget_5 = new QStackedWidget(page_2);
        stackedWidget_5->setObjectName(QString::fromUtf8("stackedWidget_5"));
        page_9 = new QWidget();
        page_9->setObjectName(QString::fromUtf8("page_9"));
        gridLayout_6 = new QGridLayout(page_9);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        tableWidget_2 = new QTableWidget(page_9);
        if (tableWidget_2->columnCount() < 8)
            tableWidget_2->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(7, __qtablewidgetitem23);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        QFont font3;
        font3.setPointSize(14);
        tableWidget_2->setFont(font3);
        tableWidget_2->setFocusPolicy(Qt::NoFocus);
        tableWidget_2->setStyleSheet(QString::fromUtf8(""));
        tableWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_2->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_2->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget_2->setGridStyle(Qt::NoPen);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget_2->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget_2->verticalHeader()->setMinimumSectionSize(30);
        tableWidget_2->verticalHeader()->setHighlightSections(true);
        tableWidget_2->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_2->verticalHeader()->setStretchLastSection(false);

        gridLayout_6->addWidget(tableWidget_2, 0, 0, 1, 1);

        stackedWidget_5->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName(QString::fromUtf8("page_10"));
        stackedWidget_5->addWidget(page_10);

        verticalLayout_5->addWidget(stackedWidget_5);

        verticalLayout_5->setStretch(0, 5);
        verticalLayout_5->setStretch(1, 2);

        gridLayout_2->addLayout(verticalLayout_5, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);

        gridLayout_5->addWidget(stackedWidget, 2, 1, 1, 1);


        retranslateUi(MainDesktop);

        stackedWidget->setCurrentIndex(1);
        stackedWidget_4->setCurrentIndex(1);
        stackedWidget_5->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainDesktop);
    } // setupUi

    void retranslateUi(QWidget *MainDesktop)
    {
        MainDesktop->setWindowTitle(QApplication::translate("MainDesktop", "Form", nullptr));
        label_2->setText(QApplication::translate("MainDesktop", "\344\273\212\346\227\245\345\217\221\346\226\231\345\256\214\346\210\220\346\257\224\344\276\213", nullptr));
        label_3->setText(QApplication::translate("MainDesktop", "\345\220\204\345\267\245\344\275\234\345\217\260\345\267\262\345\256\214\346\210\220\345\267\245\344\275\234", nullptr));
        label_4->setText(QApplication::translate("MainDesktop", "\345\274\202\345\270\270\344\277\241\346\201\257\346\217\220\347\244\272", nullptr));
        refreshButton->setText(QApplication::translate("MainDesktop", "\345\210\267\346\226\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainDesktop", "\345\267\245\344\275\234\345\217\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainDesktop", "\345\275\223\345\211\215\345\267\245\344\275\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainDesktop", "\345\201\234\346\255\242\346\227\266\351\227\264(Min)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainDesktop", "\350\277\233\350\241\214\346\227\266\351\227\264(Hour)", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainDesktop", "\345\256\214\346\210\220\346\225\260\351\207\217(Item)", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainDesktop", "\345\256\214\346\210\220\346\225\210\347\216\207(Item/H)", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainDesktop", "KPI(Item/H)", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainDesktop", "\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainDesktop", "\346\223\215\344\275\234\345\221\230", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainDesktop", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("MainDesktop", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem11->setText(QApplication::translate("MainDesktop", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem12->setText(QApplication::translate("MainDesktop", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem13->setText(QApplication::translate("MainDesktop", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem14->setText(QApplication::translate("MainDesktop", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem15->setText(QApplication::translate("MainDesktop", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem16->setText(QApplication::translate("MainDesktop", "\344\273\273\345\212\241\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem17->setText(QApplication::translate("MainDesktop", "\344\273\273\345\212\241\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem18->setText(QApplication::translate("MainDesktop", "\350\203\266\347\256\261\347\274\226\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem19->setText(QApplication::translate("MainDesktop", "\347\211\251\346\226\231\347\274\226\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem20->setText(QApplication::translate("MainDesktop", "\350\265\267\345\247\213\347\253\231\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem21->setText(QApplication::translate("MainDesktop", "\347\233\256\346\240\207\347\253\231\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem22->setText(QApplication::translate("MainDesktop", "\344\273\273\345\212\241\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_2->horizontalHeaderItem(7);
        ___qtablewidgetitem23->setText(QApplication::translate("MainDesktop", "\345\210\233\345\273\272\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainDesktop: public Ui_MainDesktop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDESKTOP_H
