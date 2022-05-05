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
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_10;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *UserNuber;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *PassWord;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_13;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *loginButton;
    QPushButton *Return_Button;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(998, 501);
        Login->setMaximumSize(QSize(167885, 167885));
        Login->setStyleSheet(QString::fromUtf8("border-image: url(:/image/login.jpg);"));
        gridLayout = new QGridLayout(Login);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Login);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background-image: url(:/image/login.jpg);"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_10);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(400, 260));
        widget_2->setMaximumSize(QSize(500, 400));
        widget_2->setStyleSheet(QString::fromUtf8("border-image: url(:/image/login1.png);\n"
"background-image: url(:/image/login1.png);\n"
"border-radius:15px"));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(7);
        gridLayout_3->setContentsMargins(0, 0, 0, 3);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(15);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 0));
        label->setMaximumSize(QSize(120, 40));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"\n"
"border-radius:15px"));

        horizontalLayout_6->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        horizontalLayout_6->setStretch(0, 5);
        horizontalLayout_6->setStretch(1, 2);
        horizontalLayout_6->setStretch(2, 5);

        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 35));
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"border-radius:15px"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 1);

        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        UserNuber = new QLineEdit(widget_2);
        UserNuber->setObjectName(QString::fromUtf8("UserNuber"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UserNuber->sizePolicy().hasHeightForWidth());
        UserNuber->setSizePolicy(sizePolicy);
        UserNuber->setMaximumSize(QSize(16777215, 50));
        QFont font1;
        font1.setPointSize(16);
        UserNuber->setFont(font1);
        UserNuber->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"border-radius:5px;\n"
"border-image: url(:/image/logine1.png);\n"
"\n"
"\n"
""));

        horizontalLayout_8->addWidget(UserNuber);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(40, 40));
        pushButton->setMaximumSize(QSize(40, 40));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(61, 61, 61);\n"
"color:#ffffff;\n"
"border-radius:1px"));

        horizontalLayout_8->addWidget(pushButton);


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
        PassWord->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"border-radius:5px;\n"
"border-image: url(:/image/logine1.png);"));

        horizontalLayout_3->addWidget(PassWord);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(40, 40));
        pushButton_2->setMaximumSize(QSize(40, 40));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(61, 61, 61);\n"
"color:#ffffff;\n"
"border-radius:1px;"));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_13);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout_5->addLayout(horizontalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        loginButton = new QPushButton(widget_2);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        sizePolicy.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
        loginButton->setSizePolicy(sizePolicy);
        loginButton->setMaximumSize(QSize(16777215, 40));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        loginButton->setFont(font2);
        loginButton->setStyleSheet(QString::fromUtf8("background-color: rgb(61, 61, 61);\n"
"color:#ffffff;\n"
"border-radius:10px"));

        horizontalLayout_9->addWidget(loginButton);

        Return_Button = new QPushButton(widget_2);
        Return_Button->setObjectName(QString::fromUtf8("Return_Button"));
        sizePolicy.setHeightForWidth(Return_Button->sizePolicy().hasHeightForWidth());
        Return_Button->setSizePolicy(sizePolicy);
        Return_Button->setMaximumSize(QSize(16777215, 40));
        Return_Button->setFont(font2);
        Return_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(61, 61, 61);\n"
"color:#ffffff;\n"
"border-radius:10px"));

        horizontalLayout_9->addWidget(Return_Button);


        horizontalLayout_4->addLayout(horizontalLayout_9);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 5);
        horizontalLayout_4->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalLayout_3->setStretch(0, 2);

        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_5->setStretch(0, 2);
        verticalLayout_5->setStretch(1, 2);
        verticalLayout_5->setStretch(2, 1);

        gridLayout_3->addLayout(verticalLayout_5, 0, 0, 1, 1);


        horizontalLayout_7->addWidget(widget_2);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);


        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        QWidget::setTabOrder(UserNuber, PassWord);
        QWidget::setTabOrder(PassWord, loginButton);
        QWidget::setTabOrder(loginButton, Return_Button);
        QWidget::setTabOrder(Return_Button, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", nullptr));
        label->setText(QApplication::translate("Login", " \345\276\256\347\275\221", nullptr));
        label_2->setText(QApplication::translate("Login", "    \346\231\272\350\203\275\344\273\223\345\202\250\347\263\273\347\273\237", nullptr));
        UserNuber->setText(QString());
        pushButton->setText(QString());
        PassWord->setText(QString());
        pushButton_2->setText(QString());
        loginButton->setText(QApplication::translate("Login", "\347\231\273\351\231\206", nullptr));
        Return_Button->setText(QApplication::translate("Login", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
