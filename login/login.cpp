#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("AGV系统"));
    LoginTimer = new QTimer(this);
    connect(LoginTimer,&QTimer::timeout,this,&Login::ON_LoginTimer);
    LoginTimer->start(1000);

    IconHelper::Instance()->setIcon(ui->pushButton, 0xf007, 20);
    IconHelper::Instance()->setIcon(ui->pushButton_2, 0xf111, 20);
    ui->widget_2->setWindowOpacity(0.3);
    //ui->widget_2->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
    ui->label->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
    ui->label_2->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
    ui->PassWord->setEchoMode(QLineEdit::Password);

    QVariant value;int DATETYPE=0;
    if(setting::getInstance()->getSettingValueInterface("DATETYPE/flag", value))
    {
        DATETYPE = value.toInt();
    }if(DATETYPE==1){
        DATETYPEbool=true;
        ui->UserNuber->setText("okagv");
        ui->PassWord->setText("okagv123");
    }if(DATETYPE==0){
        ui->UserNuber->setText("okagv");
        ui->PassWord->setText("okagv123");
    }

    QVariant value1;
    if(setting::getInstance()->getSettingValueInterface("operaterIndex/lastLoginName", value1))
    {
        lastLoginUserName = value1.toString();
    }

    //2020年9月16日14:22:17 郑少石 修改 增加记录上次登陆者的账号  启动默认触发焦点到用户账号输入框，如果用户账号输入框不为空，默认焦点到密码
    ui->UserNuber->setText(lastLoginUserName);
    if(!ui->UserNuber->text().trimmed().isEmpty())
    {
        ui->PassWord->setFocus();
    }
    else
    {
        ui->UserNuber->setFocus();
    }

}

Login::~Login()
{
    delete ui;
}


/// 保存上次登录者名称
void Login::setLastLoginUserName(QString name)
{
    lastLoginUserName = name;
    QVariant saveName(lastLoginUserName);
    if(!setting::getInstance()->setSettingValueInerface("operaterIndex", "lastLoginName", saveName))
    {
        qDebug() << "cannot save lastUserNumber";
    }
}


void Login::on_loginButton_clicked()
{
    foreach (User_Info UserInfoItiem, UserInfoList) {
        if(UserInfoItiem.UserNuber == ui->UserNuber->text() && DATETYPEbool
                && ui->PassWord->text().compare(UserInfoItiem.PassWord, Qt::CaseInsensitive) == 0){
             setLastLoginUserName(UserInfoItiem.UserNuber);
             emit UserLogin(UserInfoItiem.UserNuber,UserInfoItiem.UserName,"0");return;
        }
    }
    if(!DATETYPEbool){
        DATETYPEbool=Instance::GetInstance()->SetMessagebox("是否 确定数据库类型为: 测试\n");
        return;
    }

    bool loginok=  Instance::GetInstance()->SetMessagebox("工号或密码不匹配\n请重新输入");
    if(loginok){
        ui->PassWord->clear();
    }
    return;
}

void Login::ON_LoginTimer()
{
    if(UserInfoList.isEmpty()){
        UserInfoList=queryServer::getInstance()->getUserInfoList();
    }
}

void Login::on_PassWord_returnPressed()
{
    on_loginButton_clicked();
}
