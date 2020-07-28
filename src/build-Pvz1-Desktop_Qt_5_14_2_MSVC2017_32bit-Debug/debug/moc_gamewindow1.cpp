/****************************************************************************
** Meta object code from reading C++ file 'gamewindow1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Pvz1/viewmodel/gamewindow1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewindow1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameWindow1_t {
    QByteArrayData data[20];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameWindow1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameWindow1_t qt_meta_stringdata_GameWindow1 = {
    {
QT_MOC_LITERAL(0, 0, 11), // "GameWindow1"
QT_MOC_LITERAL(1, 12, 6), // "myslot"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "again"
QT_MOC_LITERAL(4, 26, 10), // "backtomenu"
QT_MOC_LITERAL(5, 37, 8), // "putplant"
QT_MOC_LITERAL(6, 46, 5), // "place"
QT_MOC_LITERAL(7, 52, 15), // "seedbox_clicked"
QT_MOC_LITERAL(8, 68, 9), // "planttype"
QT_MOC_LITERAL(9, 78, 11), // "move_zombie"
QT_MOC_LITERAL(10, 90, 15), // "generate_zombie"
QT_MOC_LITERAL(11, 106, 9), // "win1again"
QT_MOC_LITERAL(12, 116, 14), // "win1backtomenu"
QT_MOC_LITERAL(13, 131, 8), // "sun_move"
QT_MOC_LITERAL(14, 140, 8), // "sun_down"
QT_MOC_LITERAL(15, 149, 11), // "zombie_hide"
QT_MOC_LITERAL(16, 161, 11), // "plant_death"
QT_MOC_LITERAL(17, 173, 9), // "sun_click"
QT_MOC_LITERAL(18, 183, 11), // "set_sun_num"
QT_MOC_LITERAL(19, 195, 9) // "act_plant"

    },
    "GameWindow1\0myslot\0\0again\0backtomenu\0"
    "putplant\0place\0seedbox_clicked\0planttype\0"
    "move_zombie\0generate_zombie\0win1again\0"
    "win1backtomenu\0sun_move\0sun_down\0"
    "zombie_hide\0plant_death\0sun_click\0"
    "set_sun_num\0act_plant"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameWindow1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,
       4,    0,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   97,    2, 0x0a /* Public */,
       7,    1,  100,    2, 0x0a /* Public */,
       9,    0,  103,    2, 0x0a /* Public */,
      10,    0,  104,    2, 0x0a /* Public */,
      11,    0,  105,    2, 0x0a /* Public */,
      12,    0,  106,    2, 0x0a /* Public */,
      13,    0,  107,    2, 0x0a /* Public */,
      14,    0,  108,    2, 0x0a /* Public */,
      15,    0,  109,    2, 0x0a /* Public */,
      16,    0,  110,    2, 0x0a /* Public */,
      17,    1,  111,    2, 0x0a /* Public */,
      18,    0,  114,    2, 0x0a /* Public */,
      19,    0,  115,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameWindow1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameWindow1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->myslot(); break;
        case 1: _t->again(); break;
        case 2: _t->backtomenu(); break;
        case 3: _t->putplant((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->seedbox_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->move_zombie(); break;
        case 6: _t->generate_zombie(); break;
        case 7: _t->win1again(); break;
        case 8: _t->win1backtomenu(); break;
        case 9: _t->sun_move(); break;
        case 10: _t->sun_down(); break;
        case 11: _t->zombie_hide(); break;
        case 12: _t->plant_death(); break;
        case 13: _t->sun_click((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->set_sun_num(); break;
        case 15: _t->act_plant(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameWindow1::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameWindow1::myslot)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameWindow1::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameWindow1::again)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GameWindow1::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameWindow1::backtomenu)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GameWindow1::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GameWindow1.data,
    qt_meta_data_GameWindow1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GameWindow1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameWindow1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameWindow1.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GameWindow1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void GameWindow1::myslot()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GameWindow1::again()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GameWindow1::backtomenu()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
