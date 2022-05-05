/********************************************************************************
** Form generated from reading UI file 'deviceitem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEITEM_H
#define UI_DEVICEITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceItem
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *cageId;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_Info;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_22;
    QLabel *sensor_1;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_24;
    QLabel *sensor_2;
    QHBoxLayout *horizontalLayout_29;
    QPushButton *action_Button1;
    QPushButton *action_Button2;
    QHBoxLayout *horizontalLayout_30;
    QPushButton *enable_Button;
    QPushButton *reset_Button;

    void setupUi(QWidget *DeviceItem)
    {
        if (DeviceItem->objectName().isEmpty())
            DeviceItem->setObjectName(QString::fromUtf8("DeviceItem"));
        DeviceItem->setEnabled(true);
        DeviceItem->resize(272, 260);
        DeviceItem->setMinimumSize(QSize(260, 260));
        DeviceItem->setMaximumSize(QSize(272, 263));
        DeviceItem->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);\n"
""));
        gridLayout = new QGridLayout(DeviceItem);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cageId = new QLabel(DeviceItem);
        cageId->setObjectName(QString::fromUtf8("cageId"));
        cageId->setMinimumSize(QSize(100, 70));
        cageId->setMaximumSize(QSize(100, 126));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        cageId->setFont(font);
        cageId->setStyleSheet(QString::fromUtf8("background-color: rgb(151, 170, 166);"));
        cageId->setScaledContents(true);
        cageId->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(cageId);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        label_Info = new QLabel(DeviceItem);
        label_Info->setObjectName(QString::fromUtf8("label_Info"));
        label_Info->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_Info->setFont(font1);
        label_Info->setStyleSheet(QString::fromUtf8("border-radius:5px;background-color: rgb(170, 255, 127);\n"
""));
        label_Info->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_Info);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(20);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(-1, -1, 5, -1);
        label_22 = new QLabel(DeviceItem);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMinimumSize(QSize(70, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(11);
        label_22->setFont(font2);
        label_22->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_19->addWidget(label_22);

        sensor_1 = new QLabel(DeviceItem);
        sensor_1->setObjectName(QString::fromUtf8("sensor_1"));
        sensor_1->setMinimumSize(QSize(30, 30));
        sensor_1->setMaximumSize(QSize(30, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font3.setPointSize(12);
        sensor_1->setFont(font3);
        sensor_1->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 150, 150);\n"
"border-radius:15px;padding:15px 30px;"));
        sensor_1->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(sensor_1);


        horizontalLayout_16->addLayout(horizontalLayout_19);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        horizontalLayout_28->setContentsMargins(-1, -1, 5, -1);
        label_24 = new QLabel(DeviceItem);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMinimumSize(QSize(70, 0));
        label_24->setFont(font2);
        label_24->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_28->addWidget(label_24);

        sensor_2 = new QLabel(DeviceItem);
        sensor_2->setObjectName(QString::fromUtf8("sensor_2"));
        sensor_2->setMinimumSize(QSize(30, 30));
        sensor_2->setMaximumSize(QSize(30, 30));
        sensor_2->setFont(font3);
        sensor_2->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 150, 150);\n"
"border-radius:15px;padding:15px 30px;"));
        sensor_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_28->addWidget(sensor_2);


        horizontalLayout_16->addLayout(horizontalLayout_28);

        horizontalLayout_16->setStretch(0, 1);
        horizontalLayout_16->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(20);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        action_Button1 = new QPushButton(DeviceItem);
        action_Button1->setObjectName(QString::fromUtf8("action_Button1"));
        action_Button1->setFont(font3);
        action_Button1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 127);\n"
"border-radius:5px;padding:5px 10px;"));

        horizontalLayout_29->addWidget(action_Button1);

        action_Button2 = new QPushButton(DeviceItem);
        action_Button2->setObjectName(QString::fromUtf8("action_Button2"));
        action_Button2->setEnabled(true);
        action_Button2->setFont(font3);
        action_Button2->setStyleSheet(QString::fromUtf8("background-color: rgb(92, 122, 41);\n"
"background-color: rgb(255, 170, 127);\n"
"border-radius:5px;padding:5px 10px;"));

        horizontalLayout_29->addWidget(action_Button2);

        horizontalLayout_29->setStretch(0, 1);
        horizontalLayout_29->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_29);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(20);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        enable_Button = new QPushButton(DeviceItem);
        enable_Button->setObjectName(QString::fromUtf8("enable_Button"));
        enable_Button->setFont(font3);
        enable_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 127);\n"
"border-radius:5px;padding:5px 10px;"));

        horizontalLayout_30->addWidget(enable_Button);

        reset_Button = new QPushButton(DeviceItem);
        reset_Button->setObjectName(QString::fromUtf8("reset_Button"));
        reset_Button->setFont(font3);
        reset_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(92, 122, 41);\n"
"background-color: rgb(255, 170, 127);\n"
"border-radius:5px;padding:5px 10px;"));

        horizontalLayout_30->addWidget(reset_Button);

        horizontalLayout_30->setStretch(0, 1);
        horizontalLayout_30->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_30);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 1);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(DeviceItem);

        QMetaObject::connectSlotsByName(DeviceItem);
    } // setupUi

    void retranslateUi(QWidget *DeviceItem)
    {
        DeviceItem->setWindowTitle(QApplication::translate("DeviceItem", "Form", nullptr));
        cageId->setText(QString());
        label_Info->setText(QString());
        label_22->setText(QApplication::translate("DeviceItem", " \344\274\240\346\204\237\345\231\2501", nullptr));
        sensor_1->setText(QString());
        label_24->setText(QApplication::translate("DeviceItem", " \344\274\240\346\204\237\345\231\2502", nullptr));
        sensor_2->setText(QString());
        action_Button1->setText(QString());
        action_Button2->setText(QString());
        enable_Button->setText(QString());
        reset_Button->setText(QApplication::translate("DeviceItem", "\345\244\215\344\275\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceItem: public Ui_DeviceItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEITEM_H
