/****************************************************************************
** Meta object code from reading C++ file 'maindesktop.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MainDesktop/maindesktop.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maindesktop.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainDesktop_t {
    QByteArrayData data[9];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainDesktop_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainDesktop_t qt_meta_stringdata_MainDesktop = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MainDesktop"
QT_MOC_LITERAL(1, 12, 19), // "ON_MainDesktopTimer"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 20), // "SlotsetCurrentItem_2"
QT_MOC_LITERAL(4, 54, 3), // "row"
QT_MOC_LITERAL(5, 58, 6), // "column"
QT_MOC_LITERAL(6, 65, 24), // "on_refreshButton_clicked"
QT_MOC_LITERAL(7, 90, 24), // "on_refreshButton_pressed"
QT_MOC_LITERAL(8, 115, 25) // "on_refreshButton_released"

    },
    "MainDesktop\0ON_MainDesktopTimer\0\0"
    "SlotsetCurrentItem_2\0row\0column\0"
    "on_refreshButton_clicked\0"
    "on_refreshButton_pressed\0"
    "on_refreshButton_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainDesktop[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    2,   40,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x08 /* Private */,
       7,    0,   46,    2, 0x08 /* Private */,
       8,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainDesktop::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainDesktop *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ON_MainDesktopTimer(); break;
        case 1: _t->SlotsetCurrentItem_2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->on_refreshButton_clicked(); break;
        case 3: _t->on_refreshButton_pressed(); break;
        case 4: _t->on_refreshButton_released(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainDesktop::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_MainDesktop.data,
    qt_meta_data_MainDesktop,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainDesktop::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainDesktop::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainDesktop.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainDesktop::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
