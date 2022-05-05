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
    QByteArrayData data[14];
    char stringdata0[181];
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
QT_MOC_LITERAL(5, 60, 13), // "newConnection"
QT_MOC_LITERAL(6, 74, 20), // "ON_newReplyData_task"
QT_MOC_LITERAL(7, 95, 8), // "ClientIP"
QT_MOC_LITERAL(8, 104, 9), // "ReplyJson"
QT_MOC_LITERAL(9, 114, 10), // "ReplyJsonI"
QT_MOC_LITERAL(10, 125, 9), // "onRequest"
QT_MOC_LITERAL(11, 135, 12), // "HttpRequest*"
QT_MOC_LITERAL(12, 148, 13), // "HttpResponse*"
QT_MOC_LITERAL(13, 162, 18) // "ON_HttpServerTimer"

    },
    "HttpServer\0sig_SAPExcelInfo_new\0\0"
    "SAPExcelInfo\0SAPExcelInfoI\0newConnection\0"
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
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   42,    2, 0x08 /* Private */,
       6,    3,   43,    2, 0x08 /* Private */,
      10,    2,   50,    2, 0x08 /* Private */,
      13,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8, QMetaType::QJsonObject,    7,    9,    8,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 12,    2,    2,
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
        case 1: _t->newConnection(); break;
        case 2: _t->ON_newReplyData_task((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< ReplyJson(*)>(_a[2])),(*reinterpret_cast< QJsonObject(*)>(_a[3]))); break;
        case 3: _t->onRequest((*reinterpret_cast< HttpRequest*(*)>(_a[1])),(*reinterpret_cast< HttpResponse*(*)>(_a[2]))); break;
        case 4: _t->ON_HttpServerTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void HttpServer::sig_SAPExcelInfo_new(SAPExcelInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
