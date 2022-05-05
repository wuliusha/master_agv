#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "queryServer/queryserver.h"
#include "singleProject/single_project.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    QTimer *LoginTimer;
    bool DATETYPEbool=false;//为 true 才可登录
    QList<User_Info>UserInfoList;

    void setLastLoginUserName(QString name);

signals:
    void UserLogin(QString UserNuber,QString UserName,QString Type);

private slots:
    void on_loginButton_clicked();
    void ON_LoginTimer();

    void on_PassWord_returnPressed();

private:
    Ui::Login *ui;
    QString lastLoginUserName = "";
};

#endif // LOGIN_H
