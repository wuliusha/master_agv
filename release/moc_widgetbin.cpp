/****************************************************************************
** Meta object code from reading C++ file 'widgetbin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../StoreInfo/project/widgetbin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetbin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetBin_t {
    QByteArrayData data[6];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetBin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetBin_t qt_meta_stringdata_WidgetBin = {
    {
QT_MOC_LITERAL(0, 0, 9), // "WidgetBin"
QT_MOC_LITERAL(1, 10, 18), // "signalshelfBinInfo"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "shelfBinInfo"
QT_MOC_LITERAL(4, 43, 13), // "shelfBinInfoI"
QT_MOC_LITERAL(5, 57, 14) // "AgvItemTimeout"

    },
    "WidgetBin\0signalshelfBinInfo\0\0"
    "shelfBinInfo\0shelfBinInfoI\0AgvItemTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetBin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void WidgetBin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetBin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalshelfBinInfo((*reinterpret_cast< shelfBinInfo(*)>(_a[1]))); break;
        case 1: _t->AgvItemTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WidgetBin::*)(shelfBinInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetBin::signalshelfBinInfo)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WidgetBin::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_WidgetBin.data,
    qt_meta_data_WidgetBin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WidgetBin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetBin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetBin.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetBin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void WidgetBin::signalshelfBinInfo(shelfBinInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
