/****************************************************************************
** Meta object code from reading C++ file 'network_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../record/Network/network_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'network_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Network_Widget_t {
    QByteArrayData data[13];
    char stringdata0[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Network_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Network_Widget_t qt_meta_stringdata_Network_Widget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Network_Widget"
QT_MOC_LITERAL(1, 15, 22), // "on_Post_Button_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 23), // "on_Clear_Button_clicked"
QT_MOC_LITERAL(4, 63, 30), // "on_comboBox_currentTextChanged"
QT_MOC_LITERAL(5, 94, 4), // "arg1"
QT_MOC_LITERAL(6, 99, 32), // "on_comboBox_2_currentTextChanged"
QT_MOC_LITERAL(7, 132, 23), // "on_stop_Button_released"
QT_MOC_LITERAL(8, 156, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(9, 178, 30), // "on_taskType_currentTextChanged"
QT_MOC_LITERAL(10, 209, 19), // "Network_WidgetTimer"
QT_MOC_LITERAL(11, 229, 10), // "ON_Pressed"
QT_MOC_LITERAL(12, 240, 11) // "ON_Released"

    },
    "Network_Widget\0on_Post_Button_clicked\0"
    "\0on_Clear_Button_clicked\0"
    "on_comboBox_currentTextChanged\0arg1\0"
    "on_comboBox_2_currentTextChanged\0"
    "on_stop_Button_released\0on_pushButton_clicked\0"
    "on_taskType_currentTextChanged\0"
    "Network_WidgetTimer\0ON_Pressed\0"
    "ON_Released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Network_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    1,   66,    2, 0x08 /* Private */,
       6,    1,   69,    2, 0x08 /* Private */,
       7,    0,   72,    2, 0x08 /* Private */,
       8,    0,   73,    2, 0x08 /* Private */,
       9,    1,   74,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Network_Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Network_Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Post_Button_clicked(); break;
        case 1: _t->on_Clear_Button_clicked(); break;
        case 2: _t->on_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_comboBox_2_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_stop_Button_released(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_taskType_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->Network_WidgetTimer(); break;
        case 8: _t->ON_Pressed(); break;
        case 9: _t->ON_Released(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Network_Widget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Network_Widget.data,
    qt_meta_data_Network_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Network_Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Network_Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Network_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Network_Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
