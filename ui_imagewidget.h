/********************************************************************************
** Form generated from reading UI file 'imagewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEWIDGET_H
#define UI_IMAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imagewidget
{
public:

    void setupUi(QWidget *imagewidget)
    {
        if (imagewidget->objectName().isEmpty())
            imagewidget->setObjectName(QString::fromUtf8("imagewidget"));
        imagewidget->resize(1018, 567);

        retranslateUi(imagewidget);

        QMetaObject::connectSlotsByName(imagewidget);
    } // setupUi

    void retranslateUi(QWidget *imagewidget)
    {
        imagewidget->setWindowTitle(QApplication::translate("imagewidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class imagewidget: public Ui_imagewidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEWIDGET_H
