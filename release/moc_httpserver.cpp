/****************************************************************************
** Meta object code from reading C++ file 'httpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../httpserver/httpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HttpServer_t {
    QByteArrayData data[17];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpServer_t qt_meta_stringdata_HttpServer = {
    {
QT_MOC_LITERAL(0, 0, 10), // "HttpServer"
QT_MOC_LITERAL(1, 11, 20), // "sig_SAPExcelInfo_new"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 12), // "SAPExcelInfo"
QT_MOC_LITERAL(4, 46, 13), // "SAPExcelInfoI"
QT_MOC_LITERAL(5, 60, 24), // "sig_SAPExcelInfoList_new"
QT_MOC_LITERAL(6, 85, 26), // "QMap<QString,SAPExcelInfo>"
QT_MOC_LITERAL(7, 112, 19), // "newSAPExcelInfoList"
QT_MOC_LITERAL(8, 132, 13), // "newConnection"
QT_MOC_LITERAL(9, 146, 20), // "ON_newReplyData_task"
QT_MOC_LITERAL(10, 167, 8), // "ClientIP"
QT_MOC_LITERAL(11, 176, 9), // "ReplyJson"
QT_MOC_LITERAL(12, 186, 10), // "ReplyJsonI"
QT_MOC_LITERAL(13, 197, 9), // "onRequest"
QT_MOC_LITERAL(14, 207, 12), // "HttpRequest*"
QT_MOC_LITERAL(15, 220, 13), // "HttpResponse*"
QT_MOC_LITERAL(16, 234, 18) // "ON_HttpServerTimer"

    },
    "HttpServer\0sig_SAPExcelInfo_new\0\0"
    "SAPExcelInfo\0SAPExcelInfoI\0"
    "sig_SAPExcelInfoList_new\0"
    "QMap<QString,SAPExcelInfo>\0"
    "newSAPExcelInfoList\0newConnection\0"
    "ON_newReplyData_task\0ClientIP\0ReplyJson\0"
    "ReplyJsonI\0onRequest\0HttpRequest*\0"
    "HttpResponse*\0ON_HttpServerTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   50,    2, 0x08 /* Private */,
       9,    3,   51,    2, 0x08 /* Private */,
      13,    2,   58,    2, 0x08 /* Private */,
      16,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 11, QMetaType::QJsonObject,   10,   12,   11,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 15,    2,    2,
    QMetaType::Void,

       0        // eod
};

void HttpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HttpServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_SAPExcelInfo_new((*reinterpret_cast< SAPExcelInfo(*)>(_a[1]))); break;
        case 1: _t->sig_SAPExcelInfoList_new((*reinterpret_cast< QMap<QString,SAPExcelInfo>(*)>(_a[1]))); break;
        case 2: _t->newConnection(); break;
        case 3: _t->ON_newReplyData_task((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< ReplyJson(*)>(_a[2])),(*reinterpret_cast< QJsonObject(*)>(_a[3]))); break;
        case 4: _t->onRequest((*reinterpret_cast< HttpRequest*(*)>(_a[1])),(*reinterpret_cast< HttpResponse*(*)>(_a[2]))); break;
        case 5: _t->ON_HttpServerTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< HttpRequest* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< HttpResponse* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HttpServer::*)(SAPExcelInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpServer::sig_SAPExcelInfo_new)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HttpServer::*)(QMap<QString,SAPExcelInfo> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpServer::sig_SAPExcelInfoList_new)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HttpServer::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_HttpServer.data,
    qt_meta_data_HttpServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HttpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HttpServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HttpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void HttpServer::sig_SAPExcelInfo_new(SAPExcelInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HttpServer::sig_SAPExcelInfoList_new(QMap<QString,SAPExcelInfo> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
