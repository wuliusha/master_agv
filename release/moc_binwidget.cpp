/****************************************************************************
** Meta object code from reading C++ file 'binwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../StoreInfo/project/binwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'binwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_binwidget_t {
    QByteArrayData data[23];
    char stringdata0[383];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_binwidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_binwidget_t qt_meta_stringdata_binwidget = {
    {
QT_MOC_LITERAL(0, 0, 9), // "binwidget"
QT_MOC_LITERAL(1, 10, 20), // "sig_SAPExcelInfo_new"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 12), // "SAPExcelInfo"
QT_MOC_LITERAL(4, 45, 13), // "SAPExcelInfoI"
QT_MOC_LITERAL(5, 59, 23), // "sig_containerCode_clear"
QT_MOC_LITERAL(6, 83, 12), // "shelfBindesc"
QT_MOC_LITERAL(7, 96, 13), // "containerCode"
QT_MOC_LITERAL(8, 110, 17), // "ON_binwidgetTimer"
QT_MOC_LITERAL(9, 128, 18), // "SlotsetCurrentItem"
QT_MOC_LITERAL(10, 147, 3), // "row"
QT_MOC_LITERAL(11, 151, 6), // "column"
QT_MOC_LITERAL(12, 158, 10), // "ON_Pressed"
QT_MOC_LITERAL(13, 169, 11), // "ON_Released"
QT_MOC_LITERAL(14, 181, 21), // "on_NextButton_clicked"
QT_MOC_LITERAL(15, 203, 21), // "on_LastButton_clicked"
QT_MOC_LITERAL(16, 225, 22), // "on_AlterButton_clicked"
QT_MOC_LITERAL(17, 248, 21), // "on_AgvExecute_clicked"
QT_MOC_LITERAL(18, 270, 23), // "on_enableButton_clicked"
QT_MOC_LITERAL(19, 294, 28), // "on_enableButton_show_clicked"
QT_MOC_LITERAL(20, 323, 30), // "on_taskType_currentTextChanged"
QT_MOC_LITERAL(21, 354, 4), // "arg1"
QT_MOC_LITERAL(22, 359, 23) // "on_clear_Button_clicked"

    },
    "binwidget\0sig_SAPExcelInfo_new\0\0"
    "SAPExcelInfo\0SAPExcelInfoI\0"
    "sig_containerCode_clear\0shelfBindesc\0"
    "containerCode\0ON_binwidgetTimer\0"
    "SlotsetCurrentItem\0row\0column\0ON_Pressed\0"
    "ON_Released\0on_NextButton_clicked\0"
    "on_LastButton_clicked\0on_AlterButton_clicked\0"
    "on_AgvExecute_clicked\0on_enableButton_clicked\0"
    "on_enableButton_show_clicked\0"
    "on_taskType_currentTextChanged\0arg1\0"
    "on_clear_Button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_binwidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       5,    2,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   92,    2, 0x0a /* Public */,
       9,    2,   93,    2, 0x0a /* Public */,
      12,    0,   98,    2, 0x0a /* Public */,
      13,    0,   99,    2, 0x0a /* Public */,
      14,    0,  100,    2, 0x08 /* Private */,
      15,    0,  101,    2, 0x08 /* Private */,
      16,    0,  102,    2, 0x08 /* Private */,
      17,    0,  103,    2, 0x08 /* Private */,
      18,    0,  104,    2, 0x08 /* Private */,
      19,    0,  105,    2, 0x08 /* Private */,
      20,    1,  106,    2, 0x08 /* Private */,
      22,    0,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void,

       0        // eod
};

void binwidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<binwidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_SAPExcelInfo_new((*reinterpret_cast< SAPExcelInfo(*)>(_a[1]))); break;
        case 1: _t->sig_containerCode_clear((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->ON_binwidgetTimer(); break;
        case 3: _t->SlotsetCurrentItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->ON_Pressed(); break;
        case 5: _t->ON_Released(); break;
        case 6: _t->on_NextButton_clicked(); break;
        case 7: _t->on_LastButton_clicked(); break;
        case 8: _t->on_AlterButton_clicked(); break;
        case 9: _t->on_AgvExecute_clicked(); break;
        case 10: _t->on_enableButton_clicked(); break;
        case 11: _t->on_enableButton_show_clicked(); break;
        case 12: _t->on_taskType_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->on_clear_Button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (binwidget::*)(SAPExcelInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&binwidget::sig_SAPExcelInfo_new)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (binwidget::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&binwidget::sig_containerCode_clear)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject binwidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_binwidget.data,
    qt_meta_data_binwidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *binwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *binwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_binwidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int binwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void binwidget::sig_SAPExcelInfo_new(SAPExcelInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void binwidget::sig_containerCode_clear(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
