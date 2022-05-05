/********************************************************************************
** Form generated from reading UI file 'agvdesktop.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGVDESKTOP_H
#define UI_AGVDESKTOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_agvdesktop
{
public:

    void setupUi(QWidget *agvdesktop)
    {
        if (agvdesktop->objectName().isEmpty())
            agvdesktop->setObjectName(QString::fromUtf8("agvdesktop"));
        agvdesktop->resize(1072, 634);

        retranslateUi(agvdesktop);

        QMetaObject::connectSlotsByName(agvdesktop);
    } // setupUi

    void retranslateUi(QWidget *agvdesktop)
    {
        agvdesktop->setWindowTitle(QApplication::translate("agvdesktop", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class agvdesktop: public Ui_agvdesktop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGVDESKTOP_H
