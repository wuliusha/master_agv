/********************************************************************************
** Form generated from reading UI file 'system_door.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEM_DOOR_H
#define UI_SYSTEM_DOOR_H

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

class Ui_system_door
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QWidget *widget_10;
    QGridLayout *gridLayout_17;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_55;
    QSpacerItem *horizontalSpacer_30;
    QLabel *label_24;
    QSpacerItem *horizontalSpacer_31;
    QHBoxLayout *horizontalLayout_56;
    QHBoxLayout *horizontalLayout_44;
    QHBoxLayout *horizontalLayout_50;
    QLabel *label_68;
    QLineEdit *doorIP;
    QPushButton *query_door;
    QSpacerItem *horizontalSpacer_32;
    QHBoxLayout *horizontalLayout_59;
    QPushButton *add_door;
    QPushButton *delete_door;
    QTableWidget *tableWidget_door;
    QHBoxLayout *horizontalLayout_60;
    QSpacerItem *horizontalSpacer_33;
    QHBoxLayout *horizontalLayout_61;
    QPushButton *update_door;

    void setupUi(QWidget *system_door)
    {
        if (system_door->objectName().isEmpty())
            system_door->setObjectName(QString::fromUtf8("system_door"));
        system_door->resize(1277, 682);
        gridLayout = new QGridLayout(system_door);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(system_door);
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
        widget_10 = new QWidget(tab_2);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 209, 203);"));
        gridLayout_17 = new QGridLayout(widget_10);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(20);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        horizontalLayout_55 = new QHBoxLayout();
        horizontalLayout_55->setObjectName(QString::fromUtf8("horizontalLayout_55"));
        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_55->addItem(horizontalSpacer_30);

        label_24 = new QLabel(widget_10);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMaximumSize(QSize(16777215, 45));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        label_24->setFont(font1);
        label_24->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        horizontalLayout_55->addWidget(label_24);

        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_55->addItem(horizontalSpacer_31);


        verticalLayout_16->addLayout(horizontalLayout_55);

        horizontalLayout_56 = new QHBoxLayout();
        horizontalLayout_56->setObjectName(QString::fromUtf8("horizontalLayout_56"));
        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setSpacing(100);
        horizontalLayout_44->setObjectName(QString::fromUtf8("horizontalLayout_44"));
        horizontalLayout_50 = new QHBoxLayout();
        horizontalLayout_50->setSpacing(5);
        horizontalLayout_50->setObjectName(QString::fromUtf8("horizontalLayout_50"));
        label_68 = new QLabel(widget_10);
        label_68->setObjectName(QString::fromUtf8("label_68"));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        label_68->setFont(font2);
        label_68->setStyleSheet(QString::fromUtf8("color: white;  \n"
""));

        horizontalLayout_50->addWidget(label_68);

        doorIP = new QLineEdit(widget_10);
        doorIP->setObjectName(QString::fromUtf8("doorIP"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(doorIP->sizePolicy().hasHeightForWidth());
        doorIP->setSizePolicy(sizePolicy);
        doorIP->setMinimumSize(QSize(180, 30));
        doorIP->setMaximumSize(QSize(16777215, 40));
        QFont font3;
        font3.setPointSize(12);
        doorIP->setFont(font3);
        doorIP->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_50->addWidget(doorIP);


        horizontalLayout_44->addLayout(horizontalLayout_50);

        query_door = new QPushButton(widget_10);
        query_door->setObjectName(QString::fromUtf8("query_door"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(query_door->sizePolicy().hasHeightForWidth());
        query_door->setSizePolicy(sizePolicy1);
        query_door->setMinimumSize(QSize(120, 40));
        query_door->setMaximumSize(QSize(120, 40));
        QFont font4;
        font4.setPointSize(16);
        query_door->setFont(font4);
        query_door->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_44->addWidget(query_door);

        horizontalLayout_44->setStretch(0, 3);
        horizontalLayout_44->setStretch(1, 1);

        horizontalLayout_56->addLayout(horizontalLayout_44);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_56->addItem(horizontalSpacer_32);

        horizontalLayout_59 = new QHBoxLayout();
        horizontalLayout_59->setSpacing(20);
        horizontalLayout_59->setObjectName(QString::fromUtf8("horizontalLayout_59"));
        add_door = new QPushButton(widget_10);
        add_door->setObjectName(QString::fromUtf8("add_door"));
        sizePolicy1.setHeightForWidth(add_door->sizePolicy().hasHeightForWidth());
        add_door->setSizePolicy(sizePolicy1);
        add_door->setMinimumSize(QSize(120, 40));
        add_door->setMaximumSize(QSize(16777215, 45));
        add_door->setFont(font2);
        add_door->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_59->addWidget(add_door);

        delete_door = new QPushButton(widget_10);
        delete_door->setObjectName(QString::fromUtf8("delete_door"));
        sizePolicy1.setHeightForWidth(delete_door->sizePolicy().hasHeightForWidth());
        delete_door->setSizePolicy(sizePolicy1);
        delete_door->setMinimumSize(QSize(120, 0));
        delete_door->setMaximumSize(QSize(16777215, 45));
        delete_door->setFont(font2);
        delete_door->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_59->addWidget(delete_door);


        horizontalLayout_56->addLayout(horizontalLayout_59);


        verticalLayout_16->addLayout(horizontalLayout_56);

        tableWidget_door = new QTableWidget(widget_10);
        if (tableWidget_door->columnCount() < 11)
            tableWidget_door->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_door->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_door->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_door->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_door->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_door->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_door->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_door->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_door->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_door->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_door->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_door->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        if (tableWidget_door->rowCount() < 5)
            tableWidget_door->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_door->setVerticalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_door->setVerticalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_door->setVerticalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_door->setVerticalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_door->setVerticalHeaderItem(4, __qtablewidgetitem15);
        tableWidget_door->setObjectName(QString::fromUtf8("tableWidget_door"));
        tableWidget_door->setFont(font3);
        tableWidget_door->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        verticalLayout_16->addWidget(tableWidget_door);

        horizontalLayout_60 = new QHBoxLayout();
        horizontalLayout_60->setSpacing(10);
        horizontalLayout_60->setObjectName(QString::fromUtf8("horizontalLayout_60"));
        horizontalSpacer_33 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_60->addItem(horizontalSpacer_33);

        horizontalLayout_61 = new QHBoxLayout();
        horizontalLayout_61->setSpacing(20);
        horizontalLayout_61->setObjectName(QString::fromUtf8("horizontalLayout_61"));
        update_door = new QPushButton(widget_10);
        update_door->setObjectName(QString::fromUtf8("update_door"));
        sizePolicy1.setHeightForWidth(update_door->sizePolicy().hasHeightForWidth());
        update_door->setSizePolicy(sizePolicy1);
        update_door->setMinimumSize(QSize(160, 40));
        update_door->setMaximumSize(QSize(16777215, 45));
        update_door->setFont(font2);
        update_door->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_61->addWidget(update_door);


        horizontalLayout_60->addLayout(horizontalLayout_61);

        horizontalLayout_60->setStretch(0, 10);
        horizontalLayout_60->setStretch(1, 1);

        verticalLayout_16->addLayout(horizontalLayout_60);

        verticalLayout_16->setStretch(0, 1);
        verticalLayout_16->setStretch(1, 1);
        verticalLayout_16->setStretch(2, 10);
        verticalLayout_16->setStretch(3, 1);

        gridLayout_17->addLayout(verticalLayout_16, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget_10, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(system_door);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(system_door);
    } // setupUi

    void retranslateUi(QWidget *system_door)
    {
        system_door->setWindowTitle(QApplication::translate("system_door", "Form", nullptr));
        label_24->setText(QApplication::translate("system_door", "   \350\207\252\345\212\250\351\227\250\351\205\215\347\275\256\347\225\214\351\235\242   ", nullptr));
        label_68->setText(QApplication::translate("system_door", "\350\207\252\345\212\250\351\227\250IP:", nullptr));
        doorIP->setText(QString());
        doorIP->setPlaceholderText(QString());
        query_door->setText(QApplication::translate("system_door", "\346\237\245\350\257\242", nullptr));
        add_door->setText(QApplication::translate("system_door", "\346\267\273\345\212\240", nullptr));
        delete_door->setText(QApplication::translate("system_door", "\345\210\240\351\231\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_door->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("system_door", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_door->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("system_door", "\350\207\252\345\212\250\351\227\250IP", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_door->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("system_door", "\350\207\252\345\212\250\351\227\250\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_door->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("system_door", "\350\265\267\345\247\213\344\272\214\347\273\264\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_door->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("system_door", "\344\270\213\344\270\200\347\202\271\344\272\214\347\273\264\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_door->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("system_door", "\351\200\224\347\273\217\344\272\214\347\273\264\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_door->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("system_door", "\351\242\204\347\225\231", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_door->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("system_door", "\351\242\204\347\225\231", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_door->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("system_door", "\351\242\204\347\225\231", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_door->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("system_door", "\346\230\257\345\220\246\344\275\277\347\224\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_door->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("system_door", "\346\230\276\347\244\272\351\241\265\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_door->verticalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("system_door", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_door->verticalHeaderItem(1);
        ___qtablewidgetitem12->setText(QApplication::translate("system_door", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_door->verticalHeaderItem(2);
        ___qtablewidgetitem13->setText(QApplication::translate("system_door", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_door->verticalHeaderItem(3);
        ___qtablewidgetitem14->setText(QApplication::translate("system_door", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_door->verticalHeaderItem(4);
        ___qtablewidgetitem15->setText(QApplication::translate("system_door", "\346\226\260\345\273\272\350\241\214", nullptr));
#ifndef QT_NO_TOOLTIP
        tableWidget_door->setToolTip(QApplication::translate("system_door", "<html><head/><body><p>\345\275\223AGV\345\260\217\350\275\246\346\211\247\350\241\214\345\210\260 \350\265\267\345\247\213\344\272\214\347\273\264\347\240\201\344\270\216 \344\270\213\344\270\200\347\202\271\344\272\214\347\273\264\347\240\201\346\227\266\357\274\214\345\210\231\344\274\232\346\211\223\345\274\200\345\257\271\345\272\224\347\232\204\350\207\252\345\212\250\351\227\250\357\274\214\345\275\223AGV\345\260\217\350\275\246\347\246\273\345\274\200\351\200\224\347\273\217\344\272\214\347\273\264\347\240\201\346\227\266\357\274\214\345\210\231\344\274\232\345\205\263\351\227\255\350\207\252\345\212\250\351\227\250</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        update_door->setText(QApplication::translate("system_door", "\346\217\220\344\272\244\346\233\264\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QString());
    } // retranslateUi

};

namespace Ui {
    class system_door: public Ui_system_door {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEM_DOOR_H
