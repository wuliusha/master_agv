QT += core gui xml sql network script concurrent charts
QT +=axcontainer serialbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = AGV_Master
TEMPLATE = app
RC_FILE = "resource/appico.rc"

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

DEFINES += QT_MESSAGELOGCONTEXT

CONFIG += QT_WARNING_OUTPUT
CONFIG += QT_DEBUG_OUTPUT
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui


include(login/login.pri)
include(Device/device.pri)
include(MainDesktop/MainDesktop.pri)
include(managerinfo/managerinfo.pri)
include(Monitoring/monitoring.pri)
include(taskmanager/taskmanager.pri)
include(StoreInfo/StoreInfo.pri)
include(TcpServer/tcpserver.pri)

include (sqlConnect/sqlConnect.pri)
include(queryServer/queryServer.pri)
include(singleProject/singleProject.pri)
include(wrexcelprocess/wrexcelprocess.pri)

include(httpserver/httpserver.pri)
include (agvCar/agvCar.pri)
include(comm/comm.pri)
include (crc/crc.pri)

include(qtsingleapplication\src\qtsingleapplication.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc



