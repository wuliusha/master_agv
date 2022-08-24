#include "sqlitedata.h"

SqliteData::SqliteData()
{

    qRegisterMetaType<RoboshopState >("RoboshopState");
    qRegisterMetaType<QList<RobotProtocol >>("QList<RobotProtocol >");
    qRegisterMetaType<QList<lmstation >>("QList<lmstation >");
    qRegisterMetaType<QList<description >>("QList<description >");
    qRegisterMetaType<QList<RoboshopAction >>("QList<RoboshopAction >");

    //   agv.db 等文件必须放在 与 .pro 同等目录下的 assets:/database 文件夹  (备注：assets 不能变 ;database 可以存在不同)
    //  (assets:/base/agv.db    assets:/database/agv.db : android存放的相对路径  )
    //  (./agv.db  android软件运行的当前路径 )
    Singleton<ConnectionPool>::getInstance().copyQrcFile("assets:/database/agv.db","./agv.db");

}

SqliteData::~SqliteData()
{

}

QString SqliteData::getRobotIP()
{
    QMap<int,lmstation>lmstationMap;
    QSqlDatabase db = Singleton<ConnectionPool>::getInstance().getConnection();
    if(!db.connectionName().isEmpty()){
        QSqlQuery query(db);
        query.exec("select * from robotInfo");
        while(query.next()){
            RobotIP=query.value("robotIP").toString();
            qDebug()<<"RobotIP:"<<RobotIP;
        }
    }
    Singleton<ConnectionPool>::getInstance().releaseConnection(db);
    return RobotIP;
}

bool SqliteData::insertLmstation(lmstation lmstationI)
{
    qDebug()<<lmstationI.LM_Name<<lmstationI.navigation;
    qDebug()<<lmstationI.relocation;
    QSqlDatabase db = Singleton<ConnectionPool>::getInstance().getConnection();
    if(!db.connectionName().isEmpty()){
        QSqlQuery query(db);
        query.prepare( "INSERT INTO  lmstation([taskId], [LM_Name], [navigation],"
                          " [relocation], [time]) "
                          "VALUES (:taskId, :LM_Name, :navigation,"
                          ":relocation, :time);");
        query.addBindValue(lmstationI.taskId);
        query.addBindValue(lmstationI.LM_Name);
        query.addBindValue(lmstationI.navigation);
        query.addBindValue(lmstationI.relocation);
        query.addBindValue(QDateTime::currentDateTime());
        if(!query.exec())
        {
             qDebug()<<"lmstationI.navigation";
            Singleton<ConnectionPool>::getInstance().releaseConnection(db);
            return false;
        }
    }
    Singleton<ConnectionPool>::getInstance().releaseConnection(db);
    return true;
}

bool SqliteData::deleteLmstation(lmstation lmstationI)
{
    QSqlDatabase db = Singleton<ConnectionPool>::getInstance().getConnection();
    if(!db.connectionName().isEmpty()){
        QSqlQuery query(db);
        query.prepare(QString("DELETE FROM lmstation WHERE [LM_Name]=:LM_Name "));
        query.addBindValue(lmstationI.LM_Name);
        if(!query.exec())
        {
            qDebug()<<"删除失败"<<lmstationI.LM_Name;
            Singleton<ConnectionPool>::getInstance().releaseConnection(db);
            return false;
        }
    }
    Singleton<ConnectionPool>::getInstance().releaseConnection(db);
    return true;
}

bool SqliteData::updataLmstation(lmstation lmstationI)
{
    QSqlDatabase db = Singleton<ConnectionPool>::getInstance().getConnection();
    if(!db.connectionName().isEmpty()){
        QSqlQuery query(db);
        query.prepare("UPDATE lmstation SET [time]=:time "
                         "WHERE ([LM_Name]=:LM_Name);");
        query.addBindValue(QDateTime::currentDateTime());
        query.addBindValue(lmstationI.LM_Name);
        if(!query.exec()){
              qDebug()<<"更新失败"<<QDateTime::currentDateTime();
              Singleton<ConnectionPool>::getInstance().releaseConnection(db);
              return false;
        }
    }
    Singleton<ConnectionPool>::getInstance().releaseConnection(db);
    return true;
}

QMap<QString, lmstation> SqliteData::getLmstation()
{
    QMap<QString,lmstation>lmstationMap;
    QSqlDatabase db = Singleton<ConnectionPool>::getInstance().getConnection();
    if(!db.connectionName().isEmpty()){
        QSqlQuery query(db);
        query.exec("select * from lmstation");
        while(query.next()){
            lmstation lmstationI;
            lmstationI.taskId=query.value("taskId").toInt();
            lmstationI.LM_Name=query.value("LM_Name").toString();        //地图站点
            lmstationI.navigation=query.value("navigation").toString();  //导航
            lmstationI.relocation=query.value("relocation").toString();  //重定位
            lmstationI.time=QDateTime::currentDateTime();
            lmstationI.time=query.value("time").toDateTime();
            lmstationMap.insert(lmstationI.LM_Name,lmstationI);
        }
    }
    Singleton<ConnectionPool>::getInstance().releaseConnection(db);
    return lmstationMap;
}

bool SqliteData::insertLmstationMap(QMap<QString, lmstation> lmstationMap)
{
    QSqlDatabase db = Singleton<ConnectionPool>::getInstance().getConnection();
    if(!db.connectionName().isEmpty()){
        QSqlQuery query(db);
        QMap<QString, lmstation>::iterator iter= lmstationMap.begin();
        while(iter!=lmstationMap.end()){

            query.clear();
            query.prepare(QString("DELETE FROM lmstation WHERE [LM_Name]=:LM_Name "));
            query.addBindValue(iter.value().LM_Name);
            if(!query.exec())
            {
                qDebug()<<"删除失败"<<iter.value().LM_Name;
                Singleton<ConnectionPool>::getInstance().releaseConnection(db);
                return false;
            }

            query.clear();
            query.prepare( "INSERT INTO  lmstation([taskId], [LM_Name], [navigation],"
                              " [relocation], [time]) "
                              "VALUES (:taskId, :LM_Name, :navigation,"
                              ":relocation, :time);");
            query.addBindValue(iter.value().taskId);
            query.addBindValue(iter.value().LM_Name);
            query.addBindValue(iter.value().navigation);
            query.addBindValue(iter.value().relocation);
            query.addBindValue(QDateTime::currentDateTime());
            if(!query.exec())
            {
                qDebug()<<"143 lmstationI.navigation";
                Singleton<ConnectionPool>::getInstance().releaseConnection(db);
                return false;
            }

            ++iter;
        }
    }
    Singleton<ConnectionPool>::getInstance().releaseConnection(db);
    return true;
}

bool SqliteData::insertmoveTask(moveTask moveTaskI)
{
    QSqlDatabase db = Singleton<ConnectionPool>::getInstance().getConnection();
    if(!db.connectionName().isEmpty()){
        QSqlQuery query(db);
        query.prepare( "INSERT INTO  moveTask([taskId],[navigation],[time]) "
                          "VALUES (:taskId,:navigation,:time);");
        query.addBindValue(moveTaskI.taskId);
        query.addBindValue(moveTaskI.navigation);
        query.addBindValue(QDateTime::currentDateTime());
        if(!query.exec())
        {
            qDebug()<<" 添加失败 moveTaskI.navigation";
            Singleton<ConnectionPool>::getInstance().releaseConnection(db);
            return false;
        }
    }
    Singleton<ConnectionPool>::getInstance().releaseConnection(db);
    return true;
}

bool SqliteData::deletemoveTask(moveTask moveTaskI)
{
    QSqlDatabase db = Singleton<ConnectionPool>::getInstance().getConnection();
    if(!db.connectionName().isEmpty()){
        QSqlQuery query(db);
        QString updata = QString("DELETE FROM moveTask WHERE [taskId]=:taskId ")
                           .arg(moveTaskI.taskId);
        if(!query.exec(updata))
        {
            qDebug()<<"删除失败 moveTask"<<moveTaskI.taskId;
            Singleton<ConnectionPool>::getInstance().releaseConnection(db);
            return false;
        }
    }
    Singleton<ConnectionPool>::getInstance().releaseConnection(db);
    return true;
}

bool SqliteData::updatamoveTask(moveTask moveTaskI)
{
    QSqlDatabase db = Singleton<ConnectionPool>::getInstance().getConnection();
    if(!db.connectionName().isEmpty()){
        QSqlQuery query(db);
        query.prepare("UPDATE moveTask SET [navigation]=:navigation,"
                      "[time]=:time "
                      "WHERE ([taskId]=:taskId);");
        query.addBindValue(moveTaskI.navigation);
        query.addBindValue(QDateTime::currentDateTime());
        query.addBindValue(moveTaskI.taskId);
        if(!query.exec()){
              qDebug()<<"更新失败 moveTask"<<QDateTime::currentDateTime();
              Singleton<ConnectionPool>::getInstance().releaseConnection(db);
              return false;
        }
    }
    Singleton<ConnectionPool>::getInstance().releaseConnection(db);
    return true;
}

QMap<int, moveTask> SqliteData::getmoveTaskMap()
{
    QMap<int,moveTask>moveTaskMap;
    QSqlDatabase db = Singleton<ConnectionPool>::getInstance().getConnection();
    if(!db.connectionName().isEmpty()){
        QSqlQuery query(db);
        query.exec("select * from moveTask");
        while(query.next()){
            moveTask moveTaskI;
            moveTaskI.taskId=query.value("taskId").toInt();
            moveTaskI.navigation=query.value("navigation").toString();
            moveTaskI.time=query.value("time").toDateTime();
            moveTaskI.LMNamelist=getLMNamelist(moveTaskI);
            moveTaskMap.insert(moveTaskI.taskId,moveTaskI);
        }
    }
    Singleton<ConnectionPool>::getInstance().releaseConnection(db);
    return moveTaskMap;
}

QList<QString> SqliteData::getLMNamelist(moveTask moveTaskI)
{
    QList<QString> LMNamelist;
    QJsonDocument JsonAnalyse = QJsonDocument::fromJson(moveTaskI.navigation.toLocal8Bit().data());
    QJsonObject ReplyJson = JsonAnalyse.object();//取得最外层这个大对象
    if(ReplyJson.contains("move_task_list"))//第一级对象
    {
        QJsonValue value = ReplyJson.value("move_task_list");//第一级对象 的值
        if (value.isObject()){  //判读第二级对象是否存在
            ReplyJson=value.toObject();
        }

        if(value.isArray()){//判读第二级对象是以数组形式存在
            QJsonArray pathList = ReplyJson.value("move_task_list").toArray();
            for(auto listItem : pathList)
            {
                LMNamelist.append(listItem.toObject().value("id").toString());
            }
        }

    }
    return  LMNamelist;
}

QMap<QString, description> SqliteData::getdescription()
{
    QMap<QString,SCProtocol>SCProtocolMap;
    QMap<QString,RobotProtocol>RobotProtocolMap;
    QMap<QString,description>descriptionMap;
    QSqlDatabase db = Singleton<ConnectionPool>::getInstance().getConnection();
    if(!db.connectionName().isEmpty()){
        QSqlQuery query(db);
        query.exec("select * from RobotProtocol");
        while(query.next()){
            RobotProtocol RobotProtocolI;
            RobotProtocolI.robotEnum=query.value("robotEnum").toString();//类型名
            RobotProtocolI.type=query.value("type").toString();
            RobotProtocolI.port=quint16(query.value("port").toInt());
            RobotProtocolMap.insert(RobotProtocolI.type,RobotProtocolI);
        }

        query.clear();
        query.exec("select * from SCProtocol");
        while(query.next()){
            SCProtocol SCProtocolI;
            SCProtocolI.req=query.value("req").toString();
            SCProtocolI.reqValue=quint16(query.value("reqValue").toInt());
            SCProtocolI.type=query.value("type").toString();
            SCProtocolI.isDelelte=quint16(query.value("isDelelte").toInt());
            SCProtocolI.reqDescription=query.value("reqDescription").toString();
            SCProtocolI.res=quint16(query.value("res").toInt());
            SCProtocolI.resValue=quint16(query.value("resValue").toInt());
            SCProtocolI.resDescription=query.value("resDescription").toString();

            if(!SCProtocolMap.contains(SCProtocolI.reqDescription)){
                SCProtocolMap.insert(SCProtocolI.reqDescription,SCProtocolI);
                if(RobotProtocolMap.contains(SCProtocolI.type)){
                    description descriptionI;
                    descriptionI.Type=SCProtocolI.type;                             //类型
                    descriptionI.resDescription=SCProtocolI.reqDescription;         //动作命令解析
                    descriptionI.port=RobotProtocolMap.value(SCProtocolI.type).port;//TCP端口
                    descriptionI.reqValue=SCProtocolI.reqValue;                     //报文类型
                    //descriptionMap.insert(descriptionI.resDescription,descriptionI);
                }

            }

        }

        query.clear();
        query.exec("select * from description");
        while(query.next()){
            description descriptionI;
            descriptionI.Type=query.value("Type").toString();                             //类型
            descriptionI.resDescription=query.value("resDescription").toString();         //动作命令解析
            descriptionI.port=quint16(query.value("port").toInt());//TCP端口
            descriptionI.reqValue=quint16(query.value("reqValue").toInt());                     //报文类型
            descriptionMap.insert(descriptionI.resDescription,descriptionI);
        }

    }

    Singleton<ConnectionPool>::getInstance().releaseConnection(db);
    return descriptionMap;
}

QMap<QString, ActionBtn> SqliteData::getActionBtn()
{
    QMap<QString,ActionBtn>ActionBtnMap;
    QSqlDatabase db = Singleton<ConnectionPool>::getInstance().getConnection();
    if(!db.connectionName().isEmpty()){
        QSqlQuery query(db);
        query.exec("select * from ActionBtn");
        while(query.next()){
            ActionBtn ActionBtnI;
            ActionBtnI.objectName=query.value("objectName").toString();
            ActionBtnI.descrip=query.value("descrip").toString();
            ActionBtnI.Action=query.value("Action").toString();
            ActionBtnI.status=query.value("status").toString();
            ActionBtnI.image=query.value("image").toString();
            ActionBtnI.image1=query.value("image1").toString();
            ActionBtnMap.insert(ActionBtnI.objectName,ActionBtnI);
        }
    }

    Singleton<ConnectionPool>::getInstance().releaseConnection(db);
    return ActionBtnMap;
}

bool SqliteData::setRobotIp(QString robotIP)
{
    QSqlDatabase db = Singleton<ConnectionPool>::getInstance().getConnection();
    if(!db.connectionName().isEmpty()){
        QSqlQuery query(db);
        query.prepare("UPDATE robotInfo SET [robotIP]=:robotIP "
                      "WHERE ([Id]=:Id);");
        query.addBindValue(robotIP);
        query.addBindValue(1);
        if(!query.exec()){
              qDebug()<<"更新失败 robotInfo"<<query.record()<<QDateTime::currentDateTime();
              Singleton<ConnectionPool>::getInstance().releaseConnection(db);
              return false;
        }else{

        }
    }
    Singleton<ConnectionPool>::getInstance().releaseConnection(db);
    return true;
}

QString SqliteData::getRobotIp()
{
    QString robotIP="";
    QSqlDatabase db = Singleton<ConnectionPool>::getInstance().getConnection();
    if(!db.connectionName().isEmpty()){
        QSqlQuery query(db);
        query.exec("select * from robotInfo");
        while(query.next()){
            robotIP=query.value("robotIP").toString();
        }
    }
    Singleton<ConnectionPool>::getInstance().releaseConnection(db);
    return robotIP;

}

