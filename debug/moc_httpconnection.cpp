/****************************************************************************
** Meta object code from reading C++ file 'httpconnection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../httpserver/httpconnection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HttpConnection_t {
    QByteArrayData data[12];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpConnection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpConnection_t qt_meta_stringdata_HttpConnection = {
    {
QT_MOC_LITERAL(0, 0, 14), // "HttpConnection"
QT_MOC_LITERAL(1, 15, 10), // "newRequest"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "HttpRequest*"
QT_MOC_LITERAL(4, 40, 13), // "HttpResponse*"
QT_MOC_LITERAL(5, 54, 17), // "newReplyData_task"
QT_MOC_LITERAL(6, 72, 8), // "ClientIP"
QT_MOC_LITERAL(7, 81, 9), // "ReplyJson"
QT_MOC_LITERAL(8, 91, 10), // "ReplyJsonI"
QT_MOC_LITERAL(9, 102, 12), // "parseRequest"
QT_MOC_LITERAL(10, 115, 12), // "responseDone"
QT_MOC_LITERAL(11, 128, 22) // "ON_HttpConnectionTimer"

    },
    "HttpConnection\0newRequest\0\0HttpRequest*\0"
    "HttpResponse*\0newReplyData_task\0"
    "ClientIP\0ReplyJson\0ReplyJsonI\0"
    "parseRequest\0responseDone\0"
    "ON_HttpConnectionTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpConnection[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       5,    3,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   51,    2, 0x08 /* Private */,
      10,    0,   52,    2, 0x08 /* Private */,
      11,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7, QMetaType::QJsonObject,    6,    8,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HttpConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HttpConnection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newRequest((*reinterpret_cast< HttpRequest*(*)>(_a[1])),(*reinterpret_cast< HttpResponse*(*)>(_a[2]))); break;
        case 1: _t->newReplyData_task((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< ReplyJson(*)>(_a[2])),(*reinterpret_cast< QJsonObject(*)>(_a[3]))); break;
        case 2: _t->parseRequest(); break;
        case 3: _t->responseDone(); break;
        case 4: _t->ON_HttpConnectionTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HttpConnection::*)(HttpRequest * , HttpResponse * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpConnection::newRequest)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HttpConnection::*)(QString , ReplyJson , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpConnection::newReplyData_task)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HttpConnection::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_HttpConnection.data,
    qt_meta_data_HttpConnection,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HttpConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HttpConnection.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HttpConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void HttpConnection::newRequest(HttpRequest * _t1, HttpResponse * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HttpConnection::newReplyData_task(QString _t1, ReplyJson _t2, QJsonObject _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
