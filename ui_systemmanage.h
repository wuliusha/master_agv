/********************************************************************************
** Form generated from reading UI file 'systemmanage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMMANAGE_H
#define UI_SYSTEMMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_systemManage
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;

    void setupUi(QWidget *systemManage)
    {
        if (systemManage->objectName().isEmpty())
            systemManage->setObjectName(QString::fromUtf8("systemManage"));
        systemManage->resize(1163, 514);
        systemManage->setStyleSheet(QString::fromUtf8("background-color: rgb(73, 67, 103);"));
        gridLayout = new QGridLayout(systemManage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(systemManage);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 300));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        tabWidget->setFont(font);
        tabWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
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
"	max-width:30ex;\n"
"    min-width:30ex; \n"
"	min-height:15px;\n"
"	font:18px Times New Roman;\n"
"	padding: 0px;\n"
"	background-color: rgb(241, 242, 229);\n"
"\n"
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
"\n"
"QTabWidget::tab-bar {\n"
"	border-top: 2px solid #E5E5E5;\n"
"	border-bottom: 2px solid #E5E5E5;\n"
"	border-left:1px solid #E5E5E5;\n"
"	alignment: left;\n"
"	font-size: 14px;\n"
"	background-color:#FFFFFF;\n"
"\n"
"}"));
        tabWidget->setTabShape(QTabWidget::Rounded);

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(systemManage);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(systemManage);
    } // setupUi

    void retranslateUi(QWidget *systemManage)
    {
        systemManage->setWindowTitle(QApplication::translate("systemManage", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class systemManage: public Ui_systemManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMMANAGE_H
