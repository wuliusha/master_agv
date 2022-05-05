/****************************************************************************
** Meta object code from reading C++ file 'httpresponse.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../httpserver/httpresponse.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpresponse.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HttpResponse_t {
    QByteArrayData data[18];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpResponse_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpResponse_t qt_meta_stringdata_HttpResponse = {
    {
QT_MOC_LITERAL(0, 0, 12), // "HttpResponse"
QT_MOC_LITERAL(1, 13, 4), // "done"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 5), // "write"
QT_MOC_LITERAL(4, 25, 4), // "data"
QT_MOC_LITERAL(5, 30, 3), // "end"
QT_MOC_LITERAL(6, 34, 7), // "jswrite"
QT_MOC_LITERAL(7, 42, 5), // "jsend"
QT_MOC_LITERAL(8, 48, 8), // "jswrite_"
QT_MOC_LITERAL(9, 57, 8), // "postJson"
QT_MOC_LITERAL(10, 66, 6), // "jsend_"
QT_MOC_LITERAL(11, 73, 9), // "setHeader"
QT_MOC_LITERAL(12, 83, 5), // "field"
QT_MOC_LITERAL(13, 89, 5), // "value"
QT_MOC_LITERAL(14, 95, 20), // "setHeaderContentType"
QT_MOC_LITERAL(15, 116, 10), // "fileSuffix"
QT_MOC_LITERAL(16, 127, 9), // "setStatus"
QT_MOC_LITERAL(17, 137, 6) // "status"

    },
    "HttpResponse\0done\0\0write\0data\0end\0"
    "jswrite\0jsend\0jswrite_\0postJson\0jsend_\0"
    "setHeader\0field\0value\0setHeaderContentType\0"
    "fileSuffix\0setStatus\0status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpResponse[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   80,    2, 0x0a /* Public */,
       3,    1,   83,    2, 0x0a /* Public */,
       5,    1,   86,    2, 0x0a /* Public */,
       5,    0,   89,    2, 0x2a /* Public | MethodCloned */,
       5,    1,   90,    2, 0x0a /* Public */,
       6,    1,   93,    2, 0x0a /* Public */,
       7,    1,   96,    2, 0x0a /* Public */,
       8,    1,   99,    2, 0x0a /* Public */,
      10,    1,  102,    2, 0x0a /* Public */,
      11,    2,  105,    2, 0x0a /* Public */,
      14,    1,  110,    2, 0x0a /* Public */,
      16,    1,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void, QMetaType::QJsonArray,    4,
    QMetaType::Void, QMetaType::QJsonArray,    4,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   12,   13,
    QMetaType::Bool, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void HttpResponse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HttpResponse *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->done(); break;
        case 1: _t->write((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 2: _t->write((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->end((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->end(); break;
        case 5: _t->end((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 6: _t->jswrite((*reinterpret_cast< const QJsonArray(*)>(_a[1]))); break;
        case 7: _t->jsend((*reinterpret_cast< const QJsonArray(*)>(_a[1]))); break;
        case 8: _t->jswrite_((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 9: _t->jsend_((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 10: _t->setHeader((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: { bool _r = _t->setHeaderContentType((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->setStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HttpResponse::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpResponse::done)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HttpResponse::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_HttpResponse.data,
    qt_meta_data_HttpResponse,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HttpResponse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpResponse::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HttpResponse.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HttpResponse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void HttpResponse::done()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
