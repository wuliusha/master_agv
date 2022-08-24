/********************************************************************************
** Form generated from reading UI file 'managerinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERINFO_H
#define UI_MANAGERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagerInfo
{
public:
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab_2;

    void setupUi(QWidget *ManagerInfo)
    {
        if (ManagerInfo->objectName().isEmpty())
            ManagerInfo->setObjectName(QString::fromUtf8("ManagerInfo"));
        ManagerInfo->resize(1112, 483);
        ManagerInfo->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(ManagerInfo);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget = new QTabWidget(ManagerInfo);
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
"	border-color:rgb(48, 104, 151);\n"
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
""));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(ManagerInfo);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ManagerInfo);
    } // setupUi

    void retranslateUi(QWidget *ManagerInfo)
    {
        ManagerInfo->setWindowTitle(QApplication::translate("ManagerInfo", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QString());
    } // retranslateUi

};

namespace Ui {
    class ManagerInfo: public Ui_ManagerInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERINFO_H
