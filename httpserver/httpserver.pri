QT += core gui xml sql network script concurrent charts
QT +=axcontainer serialbus

HEADERS += \
    $$PWD/http_parser.h \
    $$PWD/httpconnection.h \
    $$PWD/httprequest.h \
    $$PWD/httpresponse.h \
    $$PWD/httpserver.h

SOURCES += \
    $$PWD/http_parser.cpp \
    $$PWD/httpconnection.cpp \
    $$PWD/httprequest.cpp \
    $$PWD/httpresponse.cpp \
    $$PWD/httpserver.cpp
