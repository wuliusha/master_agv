/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *UserNuber;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *PassWord;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(1058, 639);
        Login->setMaximumSize(QSize(167885, 167885));
        Login->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(251,102,102, 200), stop:1 rgba(20,196,188, 210));\n"
""));
        gridLayout_3 = new QGridLayout(Login);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget = new QWidget(Login);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(251,102,102, 200), stop:1 rgba(20,196,188, 210));\n"
""));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(450, 500));
        widget_2->setMaximumSize(QSize(450, 500));
        widget_2->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"border-radius:15px;\n"
"background-color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(30);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 80, -1, 50);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 100));
        label->setMaximumSize(QSize(160, 160));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"border-radius:15px;\n"
"border-image: url(:/image/login.png);"));

        horizontalLayout_6->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        horizontalLayout_6->setStretch(0, 5);
        horizontalLayout_6->setStretch(1, 2);
        horizontalLayout_6->setStretch(2, 5);

        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(0, 40));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{font: 25 14pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"color: rgb(255,255,255);\n"
"background-color: rgb(20,196,188);                               \n"
"border: none;border-radius:15px;}\n"
"                                \n"
"QPushButton:hover{background-color: rgb(22,218,208);}\n"
"                                \n"
"QPushButton:pressed{background-color: rgb(17,171,164);};"));

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 10);
        horizontalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(7);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        UserNuber = new QLineEdit(widget_2);
        UserNuber->setObjectName(QString::fromUtf8("UserNuber"));
        sizePolicy.setHeightForWidth(UserNuber->sizePolicy().hasHeightForWidth());
        UserNuber->setSizePolicy(sizePolicy);
        UserNuber->setMaximumSize(QSize(16777215, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(3);
        UserNuber->setFont(font1);
        UserNuber->setStyleSheet(QString::fromUtf8("font: 25 14pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light'; \n"
"color: rgb(31,31,31);\n"
"padding-left:20px;\n"
"background-color: rgb(255, 255, 255);\n"
"border:2px solid rgb(20,196,188);border-radius:15px;\n"
""));

        horizontalLayout_8->addWidget(UserNuber);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        PassWord = new QLineEdit(widget_2);
        PassWord->setObjectName(QString::fromUtf8("PassWord"));
        sizePolicy.setHeightForWidth(PassWord->sizePolicy().hasHeightForWidth());
        PassWord->setSizePolicy(sizePolicy);
        PassWord->setMaximumSize(QSize(16777215, 50));
        PassWord->setFont(font1);
        PassWord->setStyleSheet(QString::fromUtf8("font: 25 14pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light'; \n"
"color: rgb(31,31,31);\n"
"padding-left:20px;\n"
"background-color: rgb(255, 255, 255);\n"
"border:2px solid rgb(20,196,188);border-radius:15px;\n"
""));

        horizontalLayout_3->addWidget(PassWord);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_13);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 10);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(7);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        loginButton = new QPushButton(widget_2);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        sizePolicy.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
        loginButton->setSizePolicy(sizePolicy);
        loginButton->setMinimumSize(QSize(0, 40));
        loginButton->setMaximumSize(QSize(16777215, 40));
        loginButton->setFont(font1);
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton{font: 25 14pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"color: rgb(255,255,255);\n"
"background-color: rgb(20,196,188);                               \n"
"border: none;border-radius:15px;}\n"
"                                \n"
"QPushButton:hover{background-color: rgb(22,218,208);}\n"
"                                \n"
"QPushButton:pressed{background-color: rgb(17,171,164);};\n"
""));

        horizontalLayout_9->addWidget(loginButton);


        horizontalLayout_4->addLayout(horizontalLayout_9);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 10);
        horizontalLayout_4->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        horizontalLayout_5->addWidget(widget_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        gridLayout_2->addLayout(verticalLayout_4, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget, 0, 0, 1, 1);

        QWidget::setTabOrder(UserNuber, PassWord);
        QWidget::setTabOrder(PassWord, loginButton);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", nullptr));
        label->setText(QString());
        pushButton_3->setText(QApplication::translate("Login", "  \346\254\242\350\277\216\347\231\273\345\275\225\346\231\272\350\203\275\344\273\223\345\202\250\347\263\273\347\273\237  ", nullptr));
        UserNuber->setText(QString());
        PassWord->setText(QString());
        loginButton->setText(QApplication::translate("Login", "\347\231\273\351\231\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
