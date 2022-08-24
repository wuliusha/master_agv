/********************************************************************************
** Form generated from reading UI file 'system_station.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEM_STATION_H
#define UI_SYSTEM_STATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_system_station
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QWidget *widget_8;
    QGridLayout *gridLayout_12;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_41;
    QSpacerItem *horizontalSpacer_23;
    QLabel *label_22;
    QSpacerItem *horizontalSpacer_24;
    QHBoxLayout *horizontalLayout_42;
    QHBoxLayout *horizontalLayout_39;
    QHBoxLayout *horizontalLayout_43;
    QLabel *label_67;
    QLineEdit *StationName;
    QPushButton *query_station;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_45;
    QPushButton *add_station;
    QPushButton *delete_station;
    QTableWidget *tableWidget_station;
    QHBoxLayout *horizontalLayout_46;
    QSpacerItem *horizontalSpacer_25;
    QHBoxLayout *horizontalLayout_47;
    QPushButton *update_station;

    void setupUi(QWidget *system_station)
    {
        if (system_station->objectName().isEmpty())
            system_station->setObjectName(QString::fromUtf8("system_station"));
        system_station->resize(1271, 683);
        gridLayout = new QGridLayout(system_station);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(system_station);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 300));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane{\n"
"	border-width:5px;\n"
"	border-color:rgb(112, 161, 159);\n"
"	border-style: outset;\n"
"	background-color: rgb(132, 171, 208);\n"
"	background: transparent;\n"
"} \n"
"\n"
"QTabBar::tab{\n"
"	border-color:rgb(48, 104, 151);\n"
"	border-bottom-color: #00aa7f;\n"
"	border-top-left-radius: 10px;\n"
"	border-top-right-radius: 10px;\n"
"	max-width:30ex;\n"
"    min-width:30ex; \n"
"	min-height:15px;\n"
"	font:18px Times New Roman;\n"
"	padding: 0px;\n"
"}\n"
"QTabBar::tab:hover{\n"
"	background:rgb(198, 197, 146);\n"
"    color:black;\n"
"}\n"
"QTabBar::tab:selected{\n"
"	border-color: black;\n"
"	background:green;\n"
"	color:white;\n"
"}\n"
"QTabWidget::tab-bar {\n"
"	border-top: 2px solid #E5E5E5;\n"
"	border-bottom: 2px solid #E5E5E5;\n"
"	border-left:1px solid #E5E5E5;\n"
"	alignment: left;\n"
"	font-size: 14px;\n"
"	background-color:#FFFFFF;\n"
"}"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_8 = new QWidget(tab_2);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 212, 169);"));
        gridLayout_12 = new QGridLayout(widget_8);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(20);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setObjectName(QString::fromUtf8("horizontalLayout_41"));
        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_41->addItem(horizontalSpacer_23);

        label_22 = new QLabel(widget_8);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMaximumSize(QSize(16777215, 45));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        label_22->setFont(font1);
        label_22->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        horizontalLayout_41->addWidget(label_22);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_41->addItem(horizontalSpacer_24);


        verticalLayout_14->addLayout(horizontalLayout_41);

        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setObjectName(QString::fromUtf8("horizontalLayout_42"));
        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setSpacing(100);
        horizontalLayout_39->setObjectName(QString::fromUtf8("horizontalLayout_39"));
        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setSpacing(5);
        horizontalLayout_43->setObjectName(QString::fromUtf8("horizontalLayout_43"));
        label_67 = new QLabel(widget_8);
        label_67->setObjectName(QString::fromUtf8("label_67"));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        label_67->setFont(font2);
        label_67->setStyleSheet(QString::fromUtf8("color: white;  \n"
""));

        horizontalLayout_43->addWidget(label_67);

        StationName = new QLineEdit(widget_8);
        StationName->setObjectName(QString::fromUtf8("StationName"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StationName->sizePolicy().hasHeightForWidth());
        StationName->setSizePolicy(sizePolicy);
        StationName->setMinimumSize(QSize(180, 30));
        StationName->setMaximumSize(QSize(16777215, 40));
        QFont font3;
        font3.setPointSize(12);
        StationName->setFont(font3);
        StationName->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_43->addWidget(StationName);


        horizontalLayout_39->addLayout(horizontalLayout_43);

        query_station = new QPushButton(widget_8);
        query_station->setObjectName(QString::fromUtf8("query_station"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(query_station->sizePolicy().hasHeightForWidth());
        query_station->setSizePolicy(sizePolicy1);
        query_station->setMinimumSize(QSize(120, 40));
        query_station->setMaximumSize(QSize(120, 40));
        QFont font4;
        font4.setPointSize(16);
        query_station->setFont(font4);
        query_station->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_39->addWidget(query_station);

        horizontalLayout_39->setStretch(0, 3);
        horizontalLayout_39->setStretch(1, 1);

        horizontalLayout_42->addLayout(horizontalLayout_39);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_42->addItem(horizontalSpacer_10);

        horizontalLayout_45 = new QHBoxLayout();
        horizontalLayout_45->setSpacing(20);
        horizontalLayout_45->setObjectName(QString::fromUtf8("horizontalLayout_45"));
        add_station = new QPushButton(widget_8);
        add_station->setObjectName(QString::fromUtf8("add_station"));
        sizePolicy1.setHeightForWidth(add_station->sizePolicy().hasHeightForWidth());
        add_station->setSizePolicy(sizePolicy1);
        add_station->setMinimumSize(QSize(120, 40));
        add_station->setMaximumSize(QSize(16777215, 45));
        add_station->setFont(font2);
        add_station->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_45->addWidget(add_station);

        delete_station = new QPushButton(widget_8);
        delete_station->setObjectName(QString::fromUtf8("delete_station"));
        sizePolicy1.setHeightForWidth(delete_station->sizePolicy().hasHeightForWidth());
        delete_station->setSizePolicy(sizePolicy1);
        delete_station->setMinimumSize(QSize(120, 0));
        delete_station->setMaximumSize(QSize(16777215, 45));
        delete_station->setFont(font2);
        delete_station->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_45->addWidget(delete_station);


        horizontalLayout_42->addLayout(horizontalLayout_45);


        verticalLayout_14->addLayout(horizontalLayout_42);

        tableWidget_station = new QTableWidget(widget_8);
        if (tableWidget_station->columnCount() < 11)
            tableWidget_station->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_station->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_station->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_station->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_station->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_station->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_station->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_station->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_station->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_station->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_station->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_station->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        if (tableWidget_station->rowCount() < 5)
            tableWidget_station->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_station->setVerticalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_station->setVerticalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_station->setVerticalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_station->setVerticalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_station->setVerticalHeaderItem(4, __qtablewidgetitem15);
        tableWidget_station->setObjectName(QString::fromUtf8("tableWidget_station"));
        tableWidget_station->setFont(font3);
        tableWidget_station->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        verticalLayout_14->addWidget(tableWidget_station);

        horizontalLayout_46 = new QHBoxLayout();
        horizontalLayout_46->setSpacing(10);
        horizontalLayout_46->setObjectName(QString::fromUtf8("horizontalLayout_46"));
        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_46->addItem(horizontalSpacer_25);

        horizontalLayout_47 = new QHBoxLayout();
        horizontalLayout_47->setSpacing(20);
        horizontalLayout_47->setObjectName(QString::fromUtf8("horizontalLayout_47"));
        update_station = new QPushButton(widget_8);
        update_station->setObjectName(QString::fromUtf8("update_station"));
        sizePolicy1.setHeightForWidth(update_station->sizePolicy().hasHeightForWidth());
        update_station->setSizePolicy(sizePolicy1);
        update_station->setMinimumSize(QSize(160, 40));
        update_station->setMaximumSize(QSize(16777215, 45));
        update_station->setFont(font2);
        update_station->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_47->addWidget(update_station);


        horizontalLayout_46->addLayout(horizontalLayout_47);

        horizontalLayout_46->setStretch(0, 10);
        horizontalLayout_46->setStretch(1, 1);

        verticalLayout_14->addLayout(horizontalLayout_46);

        verticalLayout_14->setStretch(0, 1);
        verticalLayout_14->setStretch(1, 1);
        verticalLayout_14->setStretch(2, 10);
        verticalLayout_14->setStretch(3, 1);

        gridLayout_12->addLayout(verticalLayout_14, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget_8, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(system_station);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(system_station);
    } // setupUi

    void retranslateUi(QWidget *system_station)
    {
        system_station->setWindowTitle(QApplication::translate("system_station", "Form", nullptr));
        label_22->setText(QApplication::translate("system_station", "   \347\253\231\347\202\271\344\272\214\347\273\264\347\240\201\347\273\221\345\256\232\347\225\214\351\235\242   ", nullptr));
        label_67->setText(QApplication::translate("system_station", "\345\275\223\345\211\215\347\253\231\347\202\271:", nullptr));
        StationName->setText(QString());
        StationName->setPlaceholderText(QApplication::translate("system_station", "StationName", nullptr));
        query_station->setText(QApplication::translate("system_station", "\346\237\245\350\257\242", nullptr));
        add_station->setText(QApplication::translate("system_station", "\346\267\273\345\212\240", nullptr));
        delete_station->setText(QApplication::translate("system_station", "\345\210\240\351\231\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_station->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("system_station", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_station->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("system_station", "\347\253\231\347\202\271\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_station->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("system_station", "\347\253\231\347\202\271\344\272\214\347\273\264\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_station->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("system_station", "\350\265\267\345\247\213\344\272\214\347\273\264\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_station->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("system_station", "\351\200\224\347\273\217\344\272\214\347\273\264\347\240\2010", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_station->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("system_station", "\351\200\224\347\273\217\344\272\214\347\273\264\347\240\2011", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_station->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("system_station", "\351\200\224\347\273\217\344\272\214\347\273\264\347\240\2012", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_station->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("system_station", "\351\200\224\347\273\217\344\272\214\347\273\264\347\240\2013", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_station->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("system_station", "\345\257\271\346\216\245\344\272\214\347\273\264\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_station->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("system_station", "\345\257\271\346\216\245\350\267\257\347\272\277\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_station->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("system_station", "\346\226\271\345\220\221", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_station->verticalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("system_station", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_station->verticalHeaderItem(1);
        ___qtablewidgetitem12->setText(QApplication::translate("system_station", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_station->verticalHeaderItem(2);
        ___qtablewidgetitem13->setText(QApplication::translate("system_station", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_station->verticalHeaderItem(3);
        ___qtablewidgetitem14->setText(QApplication::translate("system_station", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_station->verticalHeaderItem(4);
        ___qtablewidgetitem15->setText(QApplication::translate("system_station", "\346\226\260\345\273\272\350\241\214", nullptr));
        update_station->setText(QApplication::translate("system_station", "\346\217\220\344\272\244\346\233\264\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QString());
    } // retranslateUi

};

namespace Ui {
    class system_station: public Ui_system_station {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEM_STATION_H
