/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../test2/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "keyPressEvent"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "QKeyEvent*"
QT_MOC_LITERAL(4, 37, 1), // "e"
QT_MOC_LITERAL(5, 39, 10), // "longPressB"
QT_MOC_LITERAL(6, 50, 11), // "eventFilter"
QT_MOC_LITERAL(7, 62, 3), // "obj"
QT_MOC_LITERAL(8, 66, 7), // "QEvent*"
QT_MOC_LITERAL(9, 74, 5), // "event"
QT_MOC_LITERAL(10, 80, 11), // "enemyAppear"
QT_MOC_LITERAL(11, 92, 19), // "isCollisionToPlayer"
QT_MOC_LITERAL(12, 112, 20), // "QGraphicsPixmapItem*"
QT_MOC_LITERAL(13, 133, 1), // "p"
QT_MOC_LITERAL(14, 135, 14), // "mapToCollision"
QT_MOC_LITERAL(15, 150, 5), // "enemy"
QT_MOC_LITERAL(16, 156, 20) // "isCollisionToBullets"

    },
    "MainWindow\0keyPressEvent\0\0QKeyEvent*\0"
    "e\0longPressB\0eventFilter\0obj\0QEvent*\0"
    "event\0enemyAppear\0isCollisionToPlayer\0"
    "QGraphicsPixmapItem*\0p\0mapToCollision\0"
    "enemy\0isCollisionToBullets"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    2,   53,    2, 0x0a /* Public */,
      10,    0,   58,    2, 0x0a /* Public */,
      11,    2,   59,    2, 0x0a /* Public */,
      14,    1,   64,    2, 0x0a /* Public */,
      16,    1,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 8,    7,    9,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 12, 0x80000000 | 12,    4,   13,
    QMetaType::Void, QMetaType::QObjectStar,   15,
    QMetaType::Bool, 0x80000000 | 12,    4,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 1: _t->longPressB(); break;
        case 2: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->enemyAppear(); break;
        case 4: { bool _r = _t->isCollisionToPlayer((*reinterpret_cast< QGraphicsPixmapItem*(*)>(_a[1])),(*reinterpret_cast< QGraphicsPixmapItem*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->mapToCollision((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 6: { bool _r = _t->isCollisionToBullets((*reinterpret_cast< QGraphicsPixmapItem*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
