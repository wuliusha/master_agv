/********************************************************************************
** Form generated from reading UI file 'monitoring.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITORING_H
#define UI_MONITORING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_monitoring
{
public:
    QGridLayout *gridLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QGraphicsView *ImageGraphic;
    QWidget *page_2;
    QGridLayout *gridLayout_2;
    QGraphicsView *ImageGraphic_2;

    void setupUi(QWidget *monitoring)
    {
        if (monitoring->objectName().isEmpty())
            monitoring->setObjectName(QString::fromUtf8("monitoring"));
        monitoring->resize(1189, 688);
        monitoring->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(monitoring);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        stackedWidget = new QStackedWidget(monitoring);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout = new QGridLayout(page);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ImageGraphic = new QGraphicsView(page);
        ImageGraphic->setObjectName(QString::fromUtf8("ImageGraphic"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImageGraphic->sizePolicy().hasHeightForWidth());
        ImageGraphic->setSizePolicy(sizePolicy);
        ImageGraphic->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(ImageGraphic, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_2 = new QGridLayout(page_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        ImageGraphic_2 = new QGraphicsView(page_2);
        ImageGraphic_2->setObjectName(QString::fromUtf8("ImageGraphic_2"));
        ImageGraphic_2->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(ImageGraphic_2, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);

        gridLayout_3->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(monitoring);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(monitoring);
    } // setupUi

    void retranslateUi(QWidget *monitoring)
    {
        monitoring->setWindowTitle(QApplication::translate("monitoring", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class monitoring: public Ui_monitoring {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITORING_H
