/****************************************************************************
** Meta object code from reading C++ file 'httprequest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../httpserver/httprequest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httprequest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HttpRequest_t {
    QByteArrayData data[12];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpRequest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpRequest_t qt_meta_stringdata_HttpRequest = {
    {
QT_MOC_LITERAL(0, 0, 11), // "HttpRequest"
QT_MOC_LITERAL(1, 12, 4), // "data"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 3), // "end"
QT_MOC_LITERAL(4, 22, 7), // "headers"
QT_MOC_LITERAL(5, 30, 10), // "HeaderHash"
QT_MOC_LITERAL(6, 41, 13), // "remoteAddress"
QT_MOC_LITERAL(7, 55, 10), // "remotePort"
QT_MOC_LITERAL(8, 66, 6), // "method"
QT_MOC_LITERAL(9, 73, 3), // "url"
QT_MOC_LITERAL(10, 77, 4), // "path"
QT_MOC_LITERAL(11, 82, 11) // "httpVersion"

    },
    "HttpRequest\0data\0\0end\0headers\0HeaderHash\0"
    "remoteAddress\0remotePort\0method\0url\0"
    "path\0httpVersion"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpRequest[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       7,   28, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       3,    0,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,

 // properties: name, type, flags
       4, 0x80000000 | 5, 0x00095009,
       6, QMetaType::QString, 0x00095001,
       7, QMetaType::UShort, 0x00095001,
       8, QMetaType::QString, 0x00095001,
       9, QMetaType::QUrl, 0x00095001,
      10, QMetaType::QString, 0x00095001,
      11, QMetaType::QString, 0x00095001,

       0        // eod
};

void HttpRequest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HttpRequest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->data((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->end(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HttpRequest::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpRequest::data)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HttpRequest::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpRequest::end)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<HttpRequest *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< HeaderHash*>(_v) = _t->headers(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->remoteAddress(); break;
        case 2: *reinterpret_cast< quint16*>(_v) = _t->remotePort(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->method(); break;
        case 4: *reinterpret_cast< QUrl*>(_v) = _t->url(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->path(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->httpVersion(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject HttpRequest::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_HttpRequest.data,
    qt_meta_data_HttpRequest,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HttpRequest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpRequest::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HttpRequest.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HttpRequest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void HttpRequest::data(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HttpRequest::end()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
