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
    QByteArrayData data[21];
    char stringdata0[327];
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
QT_MOC_LITERAL(5, 40, 20), // "sig_SAPExcelInfo_new"
QT_MOC_LITERAL(6, 61, 12), // "SAPExcelInfo"
QT_MOC_LITERAL(7, 74, 13), // "SAPExcelInfoI"
QT_MOC_LITERAL(8, 88, 23), // "sig_containerCode_clear"
QT_MOC_LITERAL(9, 112, 12), // "shelfBindesc"
QT_MOC_LITERAL(10, 125, 13), // "containerCode"
QT_MOC_LITERAL(11, 139, 4), // "type"
QT_MOC_LITERAL(12, 144, 16), // "upStoreInfoTimer"
QT_MOC_LITERAL(13, 161, 23), // "on_query_Button_clicked"
QT_MOC_LITERAL(14, 185, 30), // "on_queryLineEdit_returnPressed"
QT_MOC_LITERAL(15, 216, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(16, 238, 15), // "ON_shelfBinInfo"
QT_MOC_LITERAL(17, 254, 12), // "shelfBinInfo"
QT_MOC_LITERAL(18, 267, 16), // "shelfBinInfoItem"
QT_MOC_LITERAL(19, 284, 19), // "ON_SAPExcelInfo_new"
QT_MOC_LITERAL(20, 304, 22) // "ON_containerCode_clear"

    },
    "StoreInfo\0sinalStoreCheck\0\0ikey\0LableNO\0"
    "sig_SAPExcelInfo_new\0SAPExcelInfo\0"
    "SAPExcelInfoI\0sig_containerCode_clear\0"
    "shelfBindesc\0containerCode\0type\0"
    "upStoreInfoTimer\0on_query_Button_clicked\0"
    "on_queryLineEdit_returnPressed\0"
    "on_pushButton_clicked\0ON_shelfBinInfo\0"
    "shelfBinInfo\0shelfBinInfoItem\0"
    "ON_SAPExcelInfo_new\0ON_containerCode_clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StoreInfo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       5,    1,   69,    2, 0x06 /* Public */,
       8,    3,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   79,    2, 0x0a /* Public */,
      13,    0,   80,    2, 0x08 /* Private */,
      14,    0,   81,    2, 0x08 /* Private */,
      15,    0,   82,    2, 0x08 /* Private */,
      16,    1,   83,    2, 0x0a /* Public */,
      19,    1,   86,    2, 0x0a /* Public */,
      20,    3,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,

       0        // eod
};

void StoreInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StoreInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sinalStoreCheck((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->sig_SAPExcelInfo_new((*reinterpret_cast< SAPExcelInfo(*)>(_a[1]))); break;
        case 2: _t->sig_containerCode_clear((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->upStoreInfoTimer(); break;
        case 4: _t->on_query_Button_clicked(); break;
        case 5: _t->on_queryLineEdit_returnPressed(); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->ON_shelfBinInfo((*reinterpret_cast< shelfBinInfo(*)>(_a[1]))); break;
        case 8: _t->ON_SAPExcelInfo_new((*reinterpret_cast< SAPExcelInfo(*)>(_a[1]))); break;
        case 9: _t->ON_containerCode_clear((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
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
        {
            using _t = void (StoreInfo::*)(SAPExcelInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StoreInfo::sig_SAPExcelInfo_new)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (StoreInfo::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StoreInfo::sig_containerCode_clear)) {
                *result = 2;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void StoreInfo::sinalStoreCheck(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StoreInfo::sig_SAPExcelInfo_new(SAPExcelInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void StoreInfo::sig_containerCode_clear(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
