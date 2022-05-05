/****************************************************************************
** Meta object code from reading C++ file 'storeinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../StoreInfo/storeinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'storeinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StoreInfo_t {
    QByteArrayData data[14];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StoreInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StoreInfo_t qt_meta_stringdata_StoreInfo = {
    {
QT_MOC_LITERAL(0, 0, 9), // "StoreInfo"
QT_MOC_LITERAL(1, 10, 15), // "sinalStoreCheck"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 4), // "ikey"
QT_MOC_LITERAL(4, 32, 7), // "LableNO"
QT_MOC_LITERAL(5, 40, 16), // "upStoreInfoTimer"
QT_MOC_LITERAL(6, 57, 23), // "on_query_Button_clicked"
QT_MOC_LITERAL(7, 81, 20), // "on_UP_Button_clicked"
QT_MOC_LITERAL(8, 102, 30), // "on_queryMaterial_returnPressed"
QT_MOC_LITERAL(9, 133, 15), // "ON_shelfBinInfo"
QT_MOC_LITERAL(10, 149, 12), // "shelfBinInfo"
QT_MOC_LITERAL(11, 162, 16), // "shelfBinInfoItem"
QT_MOC_LITERAL(12, 179, 10), // "ON_Pressed"
QT_MOC_LITERAL(13, 190, 11) // "ON_Released"

    },
    "StoreInfo\0sinalStoreCheck\0\0ikey\0LableNO\0"
    "upStoreInfoTimer\0on_query_Button_clicked\0"
    "on_UP_Button_clicked\0"
    "on_queryMaterial_returnPressed\0"
    "ON_shelfBinInfo\0shelfBinInfo\0"
    "shelfBinInfoItem\0ON_Pressed\0ON_Released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StoreInfo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   59,    2, 0x0a /* Public */,
       6,    0,   60,    2, 0x08 /* Private */,
       7,    0,   61,    2, 0x08 /* Private */,
       8,    0,   62,    2, 0x08 /* Private */,
       9,    1,   63,    2, 0x0a /* Public */,
      12,    0,   66,    2, 0x0a /* Public */,
      13,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StoreInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StoreInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sinalStoreCheck((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->upStoreInfoTimer(); break;
        case 2: _t->on_query_Button_clicked(); break;
        case 3: _t->on_UP_Button_clicked(); break;
        case 4: _t->on_queryMaterial_returnPressed(); break;
        case 5: _t->ON_shelfBinInfo((*reinterpret_cast< shelfBinInfo(*)>(_a[1]))); break;
        case 6: _t->ON_Pressed(); break;
        case 7: _t->ON_Released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StoreInfo::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StoreInfo::sinalStoreCheck)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject StoreInfo::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_StoreInfo.data,
    qt_meta_data_StoreInfo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *StoreInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StoreInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StoreInfo.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int StoreInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void StoreInfo::sinalStoreCheck(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
