#include "buttonstyle.h"
buttonStyle* buttonStyle::buttonStyleItiem=0;
QMutex buttonStyle::mutex;

buttonStyle::buttonStyle(QObject *parent) : QObject(parent)
{

}

buttonStyle *buttonStyle::GetInstance()
{
    if(buttonStyleItiem != nullptr)
        return buttonStyleItiem;
    else
    {
        mutex.lock();
        buttonStyleItiem=new buttonStyle;
        return buttonStyleItiem;
        mutex.unlock();
    }
}

void buttonStyle::iconhelperinit(helperInfo helperInfoI)
{
    helperInfoI.font=helperInfoI.font*helperInfoI.fontScale;
    helperInfoI.iconSize=helperInfoI.iconSize*helperInfoI.sizeScale;
    helperInfoI.iconWidth=helperInfoI.iconWidth*helperInfoI.sizeScale;
    helperInfoI.iconHeight=helperInfoI.iconHeight*helperInfoI.sizeScale;
    for(int i = 0; i < helperInfoI.btns.size(); i++){
        QToolButton *btn = helperInfoI.btns.at(i);
        if(helperInfoI.Iconstatus==0){
            btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        }else{
            btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        }
        btn->setIconSize(QSize(helperInfoI.iconWidth*1.1, helperInfoI.iconHeight));
        QPixmap pix = IconHelper::Instance()->getPixmap(helperInfoI.listColorText.at(i), helperInfoI.listChar.at(i), helperInfoI.iconSize, helperInfoI.iconWidth, helperInfoI.iconHeight);
        btn->setIcon(QIcon(pix));
        btn->setText(helperInfoI.listText.at(i));
        QStringList list;
        list.append(QString("QToolButton{font:%1px;color:#ffffff;background:%2;}").arg(helperInfoI.font).arg(helperInfoI.listColorBg.at(i)));
        list.append(QString("QToolButton{border:none;border: 0px groove white;border-radius:10px;padding:1px;}"));
        list.append(QString("QToolButton:pressed{background:%1;}").arg("#737A97"));
        btn->setStyleSheet(list.join(""));
    }

    //qDebug()<<"helperInfoItem:"<<helperInfoI.font<<helperInfoI.iconSize<<helperInfoI.iconWidth<<helperInfoI.iconHeight;

}

void buttonStyle::ButtonChageiconhelper(helperInfo helperInfoI, QString Buttontext)
{
    helperInfoI.listColorBg=helperInfoI.listColorBg1;
    for(int i=0;i<helperInfoI.listText.length();i++){
        if(helperInfoI.listText[i]==Buttontext){
            helperInfoI.listColorBg[i]="#55ff7f";
        }
    }
    iconhelperinit(helperInfoI);
}
