/****************************************************************************
** Meta object code from reading C++ file 'taskmanagerserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../taskmanager/taskmanagerserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'taskmanagerserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_taskManagerServer_t {
    QByteArrayData data[64];
    char stringdata0[925];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_taskManagerServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_taskManagerServer_t qt_meta_stringdata_taskManagerServer = {
    {
QT_MOC_LITERAL(0, 0, 17), // "taskManagerServer"
QT_MOC_LITERAL(1, 18, 14), // "sigAGVMoveTask"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 5), // "AGVIP"
QT_MOC_LITERAL(4, 40, 12), // "StartQRPoint"
QT_MOC_LITERAL(5, 53, 10), // "EndQRPoint"
QT_MOC_LITERAL(6, 64, 9), // "AGVAction"
QT_MOC_LITERAL(7, 74, 9), // "chargetye"
QT_MOC_LITERAL(8, 84, 12), // "agvORderTask"
QT_MOC_LITERAL(9, 97, 13), // "agvORderTaskI"
QT_MOC_LITERAL(10, 111, 13), // "sigChargeTask"
QT_MOC_LITERAL(11, 125, 11), // "opendcharge"
QT_MOC_LITERAL(12, 137, 21), // "sigDeviceStatusAction"
QT_MOC_LITERAL(13, 159, 8), // "DeviceIP"
QT_MOC_LITERAL(14, 168, 10), // "deviceType"
QT_MOC_LITERAL(15, 179, 9), // "orderType"
QT_MOC_LITERAL(16, 189, 6), // "Action"
QT_MOC_LITERAL(17, 196, 21), // "sigsetLiftactionArray"
QT_MOC_LITERAL(18, 218, 8), // "LiftTask"
QT_MOC_LITERAL(19, 227, 9), // "LiftTaskI"
QT_MOC_LITERAL(20, 237, 10), // "startFloor"
QT_MOC_LITERAL(21, 248, 9), // "destFloor"
QT_MOC_LITERAL(22, 258, 15), // "sigDeviceStatus"
QT_MOC_LITERAL(23, 274, 10), // "deviceDesc"
QT_MOC_LITERAL(24, 285, 12), // "SAPExcelInfo"
QT_MOC_LITERAL(25, 298, 13), // "SAPExcelInfoI"
QT_MOC_LITERAL(26, 312, 20), // "sigAGVCurrentTaskMap"
QT_MOC_LITERAL(27, 333, 29), // "QMap<QString,AGVCurrentTask*>"
QT_MOC_LITERAL(28, 363, 18), // "AGVCurrentTaskMapI"
QT_MOC_LITERAL(29, 382, 14), // "sigLiftCodeMap"
QT_MOC_LITERAL(30, 397, 22), // "QMap<QString,LiftCode>"
QT_MOC_LITERAL(31, 420, 11), // "LiftCodeMap"
QT_MOC_LITERAL(32, 432, 22), // "taskManagerServerTimer"
QT_MOC_LITERAL(33, 455, 19), // "ON_SAPExcelInfo_new"
QT_MOC_LITERAL(34, 475, 23), // "ON_SAPExcelInfoList_new"
QT_MOC_LITERAL(35, 499, 26), // "QMap<QString,SAPExcelInfo>"
QT_MOC_LITERAL(36, 526, 20), // "newSAPExcelInfoList_"
QT_MOC_LITERAL(37, 547, 14), // "ON_AGVMoveTask"
QT_MOC_LITERAL(38, 562, 8), // "taskType"
QT_MOC_LITERAL(39, 571, 14), // "AGVCurrentTask"
QT_MOC_LITERAL(40, 586, 15), // "AGVCurrentTaskI"
QT_MOC_LITERAL(41, 602, 17), // "ON_AgvStateWidget"
QT_MOC_LITERAL(42, 620, 8), // "agvState"
QT_MOC_LITERAL(43, 629, 13), // "agvStateItemI"
QT_MOC_LITERAL(44, 643, 21), // "ON_UPSAPExcelInfoTask"
QT_MOC_LITERAL(45, 665, 18), // "seletSAPExcelInfoI"
QT_MOC_LITERAL(46, 684, 23), // "ON_AGVCurrentTaskAction"
QT_MOC_LITERAL(47, 708, 4), // "Type"
QT_MOC_LITERAL(48, 713, 25), // "ON_deleteSAPExcelInfoTask"
QT_MOC_LITERAL(49, 739, 17), // "ON_LiftTaskStatus"
QT_MOC_LITERAL(50, 757, 9), // "LiftTask0"
QT_MOC_LITERAL(51, 767, 23), // "ON_LiftCodeStatus_clear"
QT_MOC_LITERAL(52, 791, 8), // "LiftCode"
QT_MOC_LITERAL(53, 800, 12), // "LiftCodeItem"
QT_MOC_LITERAL(54, 813, 22), // "ON_containerCode_clear"
QT_MOC_LITERAL(55, 836, 12), // "shelfBindesc"
QT_MOC_LITERAL(56, 849, 13), // "containerCode"
QT_MOC_LITERAL(57, 863, 4), // "type"
QT_MOC_LITERAL(58, 868, 15), // "ON_taskCodes_WW"
QT_MOC_LITERAL(59, 884, 4), // "iKey"
QT_MOC_LITERAL(60, 889, 8), // "WWYLPOST"
QT_MOC_LITERAL(61, 898, 9), // "WWYLPOSTI"
QT_MOC_LITERAL(62, 908, 9), // "UserBadge"
QT_MOC_LITERAL(63, 918, 6) // "pathId"

    },
    "taskManagerServer\0sigAGVMoveTask\0\0"
    "AGVIP\0StartQRPoint\0EndQRPoint\0AGVAction\0"
    "chargetye\0agvORderTask\0agvORderTaskI\0"
    "sigChargeTask\0opendcharge\0"
    "sigDeviceStatusAction\0DeviceIP\0"
    "deviceType\0orderType\0Action\0"
    "sigsetLiftactionArray\0LiftTask\0LiftTaskI\0"
    "startFloor\0destFloor\0sigDeviceStatus\0"
    "deviceDesc\0SAPExcelInfo\0SAPExcelInfoI\0"
    "sigAGVCurrentTaskMap\0QMap<QString,AGVCurrentTask*>\0"
    "AGVCurrentTaskMapI\0sigLiftCodeMap\0"
    "QMap<QString,LiftCode>\0LiftCodeMap\0"
    "taskManagerServerTimer\0ON_SAPExcelInfo_new\0"
    "ON_SAPExcelInfoList_new\0"
    "QMap<QString,SAPExcelInfo>\0"
    "newSAPExcelInfoList_\0ON_AGVMoveTask\0"
    "taskType\0AGVCurrentTask\0AGVCurrentTaskI\0"
    "ON_AgvStateWidget\0agvState\0agvStateItemI\0"
    "ON_UPSAPExcelInfoTask\0seletSAPExcelInfoI\0"
    "ON_AGVCurrentTaskAction\0Type\0"
    "ON_deleteSAPExcelInfoTask\0ON_LiftTaskStatus\0"
    "LiftTask0\0ON_LiftCodeStatus_clear\0"
    "LiftCode\0LiftCodeItem\0ON_containerCode_clear\0"
    "shelfBindesc\0containerCode\0type\0"
    "ON_taskCodes_WW\0iKey\0WWYLPOST\0WWYLPOSTI\0"
    "UserBadge\0pathId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_taskManagerServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,  109,    2, 0x06 /* Public */,
      10,    2,  122,    2, 0x06 /* Public */,
      12,    4,  127,    2, 0x06 /* Public */,
      17,    3,  136,    2, 0x06 /* Public */,
      22,    2,  143,    2, 0x06 /* Public */,
      26,    1,  148,    2, 0x06 /* Public */,
      29,    1,  151,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      32,    0,  154,    2, 0x0a /* Public */,
      33,    1,  155,    2, 0x0a /* Public */,
      34,    1,  158,    2, 0x0a /* Public */,
      37,    3,  161,    2, 0x0a /* Public */,
      41,    1,  168,    2, 0x0a /* Public */,
      44,    1,  171,    2, 0x0a /* Public */,
      46,    3,  174,    2, 0x0a /* Public */,
      48,    1,  181,    2, 0x0a /* Public */,
      49,    1,  184,    2, 0x0a /* Public */,
      51,    1,  187,    2, 0x0a /* Public */,
      54,    3,  190,    2, 0x0a /* Public */,
      58,    4,  197,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::UInt, QMetaType::Int, QMetaType::Int, 0x80000000 | 8,    3,    4,    5,    6,    7,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    3,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,   13,   14,   15,   16,
    QMetaType::Void, 0x80000000 | 18, QMetaType::Int, QMetaType::Int,   19,   20,   21,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 24,   23,   25,
    QMetaType::Void, 0x80000000 | 27,   28,
    QMetaType::Void, 0x80000000 | 30,   31,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 39,    3,   38,   40,
    QMetaType::Void, 0x80000000 | 42,   43,
    QMetaType::Void, 0x80000000 | 24,   45,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    3,   47,   16,
    QMetaType::Void, 0x80000000 | 24,   45,
    QMetaType::Void, 0x80000000 | 18,   50,
    QMetaType::Void, 0x80000000 | 52,   53,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   55,   56,   57,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 60, QMetaType::QString, QMetaType::Int,   59,   61,   62,   63,

       0        // eod
};

void taskManagerServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<taskManagerServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigAGVMoveTask((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< agvORderTask(*)>(_a[6]))); break;
        case 1: _t->sigChargeTask((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 2: _t->sigDeviceStatusAction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->sigsetLiftactionArray((*reinterpret_cast< LiftTask(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->sigDeviceStatus((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< SAPExcelInfo(*)>(_a[2]))); break;
        case 5: _t->sigAGVCurrentTaskMap((*reinterpret_cast< QMap<QString,AGVCurrentTask*>(*)>(_a[1]))); break;
        case 6: _t->sigLiftCodeMap((*reinterpret_cast< QMap<QString,LiftCode>(*)>(_a[1]))); break;
        case 7: _t->taskManagerServerTimer(); break;
        case 8: _t->ON_SAPExcelInfo_new((*reinterpret_cast< SAPExcelInfo(*)>(_a[1]))); break;
        case 9: _t->ON_SAPExcelInfoList_new((*reinterpret_cast< QMap<QString,SAPExcelInfo>(*)>(_a[1]))); break;
        case 10: _t->ON_AGVMoveTask((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< AGVCurrentTask(*)>(_a[3]))); break;
        case 11: _t->ON_AgvStateWidget((*reinterpret_cast< agvState(*)>(_a[1]))); break;
        case 12: _t->ON_UPSAPExcelInfoTask((*reinterpret_cast< SAPExcelInfo(*)>(_a[1]))); break;
        case 13: _t->ON_AGVCurrentTaskAction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 14: _t->ON_deleteSAPExcelInfoTask((*reinterpret_cast< SAPExcelInfo(*)>(_a[1]))); break;
        case 15: _t->ON_LiftTaskStatus((*reinterpret_cast< LiftTask(*)>(_a[1]))); break;
        case 16: _t->ON_LiftCodeStatus_clear((*reinterpret_cast< LiftCode(*)>(_a[1]))); break;
        case 17: _t->ON_containerCode_clear((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 18: _t->ON_taskCodes_WW((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< WWYLPOST(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (taskManagerServer::*)(QString , quint32 , quint32 , int , int , agvORderTask );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&taskManagerServer::sigAGVMoveTask)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (taskManagerServer::*)(QString , quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&taskManagerServer::sigChargeTask)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (taskManagerServer::*)(QString , QString , QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&taskManagerServer::sigDeviceStatusAction)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (taskManagerServer::*)(LiftTask , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&taskManagerServer::sigsetLiftactionArray)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (taskManagerServer::*)(QString , SAPExcelInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&taskManagerServer::sigDeviceStatus)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (taskManagerServer::*)(QMap<QString,AGVCurrentTask*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&taskManagerServer::sigAGVCurrentTaskMap)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (taskManagerServer::*)(QMap<QString,LiftCode> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&taskManagerServer::sigLiftCodeMap)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject taskManagerServer::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_taskManagerServer.data,
    qt_meta_data_taskManagerServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *taskManagerServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *taskManagerServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_taskManagerServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int taskManagerServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void taskManagerServer::sigAGVMoveTask(QString _t1, quint32 _t2, quint32 _t3, int _t4, int _t5, agvORderTask _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void taskManagerServer::sigChargeTask(QString _t1, quint16 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void taskManagerServer::sigDeviceStatusAction(QString _t1, QString _t2, QString _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void taskManagerServer::sigsetLiftactionArray(LiftTask _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void taskManagerServer::sigDeviceStatus(QString _t1, SAPExcelInfo _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void taskManagerServer::sigAGVCurrentTaskMap(QMap<QString,AGVCurrentTask*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void taskManagerServer::sigLiftCodeMap(QMap<QString,LiftCode> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
