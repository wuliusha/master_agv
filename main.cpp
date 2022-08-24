#include "mainwindow.h"
#include <QApplication>

#include "comm/config/cfgsetting.h"
#include "qtsingleapplication.h"
#include "singleProject/single_project.h"

#define LOGFILEMAXSIZE 5*1024*1024
QString fileName = "./log/log.log";

void confSetting()
{
//    setting::pThis = CfgSetting::getInstance();
    CfgSetting::getInstance();
}

QString shortFunctionName(QString functionName)
{
    QString ret = functionName;
    int index = functionName.indexOf("::");
    if(index == -1)
    {
        ret = functionName.mid(functionName.indexOf(" ")+1, functionName.indexOf("(") -functionName.indexOf(" ")-1);
    }
    else
    {
        QString tmpStr = functionName.split("::").last();
        ret = tmpStr.split("(").first()+"()";//functionName.mid(functionName.indexOf("::")+2, functionName.indexOf("(")-functionName.indexOf("::")-2);
    }
    return ret;
}

QString QtMSgTypeToString(QtMsgType type)
{
    switch (type) {
    case QtDebugMsg:
        return "Debug";
        break;
    case QtWarningMsg:
        return "Warning";
        break;
    case QtCriticalMsg:
        return "Critical";
        break;
    case QtFatalMsg:
        return "Fatal";
        break;
    case QtInfoMsg:
        return "Info";
        break;
    default:
        return "Unknow";
        break;
    }
}

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    int logFileMaxSize;
    QByteArray localMsg = msg.toLocal8Bit();
    fprintf(stdout,"%s\n",localMsg.constData());
    fflush(stdout);


    QString functionName(context.function);
    functionName = shortFunctionName(functionName);

    QFile file(fileName);

    QVariant logFileSize;
    if(CfgSetting::getInstance()->getSettingValueInterface("LOGFILE/MAXSIZE",logFileSize))
    {
        bool ok;
        QString size = logFileSize.toString();
        QStringList sizeList = size.split("*");
        int sizeInt = 1;
        foreach (QString item, sizeList) {
            int sizeTmp = item.toInt(&ok);
            if(ok)
            {
                sizeInt *= sizeTmp;
            }
        }
        logFileMaxSize = sizeInt;
    }
    else
    {
        logFileMaxSize = LOGFILEMAXSIZE;
    }

    if(file.open(QFile::ReadWrite | QFile::Append))
    {
        if(file.size() > logFileMaxSize)
        {
            file.rename(QFileInfo(file).path()+ "/log_"+QDateTime::currentDateTime().toString("yyyy_MM_dd_hh_mm_ss_zzz")+".log");
            file.close();
            file.setFileName("./log/log.log");
            file.open((QFile::ReadWrite | QFile::Truncate));
        }
        if(!file.isOpen())
        {
            return;
        }
        QTextStream stream(&file);
        stream << "[" <<
                  QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz")
               << "]";
        QString printFileName(context.file);
        QFileInfo fileInfo(printFileName);
        QString filePath  = fileInfo.fileName();

        const QLatin1Char space(' ');
        stream << QtMSgTypeToString(type);
//        stream << " "  << functionName;
        stream << " " << msg  << " "  << functionName << " " << "[" << filePath << " "
               << QString::number(context.line)/*.leftJustified(5,space)*/ << "]" << "\r\n";

        QString logmsg="["+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz")+"] "
                +msg +" "  + functionName + " [" +filePath +" "
                     + QString::number(context.line) +"] \r\n" ;

        file.flush();
        file.close();

        log_single::GetInstance()->setqDebug_log(logmsg);
    }
    if(type == QtCriticalMsg || type == QtFatalMsg)
    {
//        abort();
        return ;
    }
}

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
//    CfgSetting::getInstance();
    confSetting();
    qInstallMessageHandler(myMessageOutput);
    QtSingleApplication a(QLatin1String("AGV_Master"), argc, argv);
    if (a.isRunning())
    {
        a.sendMessage("raise_window_noop");
        return EXIT_SUCCESS;
    }

    QFont ft1;
    ft1.setPointSize(26);
    QSplashScreen *splash=new QSplashScreen;
    QPixmap pix(":/image/startlogin.png");
    splash->setFont(ft1);   //设置字体
    splash->showMessage("");
    //splash->showMessage("欢迎登录先进AGV系统,正在载入，请稍等……", Qt::AlignBottom, Qt::white);
    splash->setPixmap(pix);
    splash->show();

    MainWindow w;
    a.setActivationWindow(&w);

    QTime dieTime = QTime::currentTime().addMSecs(800);
    while( QTime::currentTime() < dieTime )
    a.processEvents();//这样可以保证程序一直可以响应鼠标键盘上事件
    splash->finish(&w);//启动画面在窗口w创建完成以后结束
    w.show();
    return a.exec();
}
