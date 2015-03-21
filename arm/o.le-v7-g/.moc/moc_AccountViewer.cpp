/****************************************************************************
** Meta object code from reading C++ file 'AccountViewer.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/AccountViewer.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AccountViewer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AccountViewer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   19, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   15,   14,   14, 0x08,

 // properties: name, type, flags
      99,   74, 0x00095409,

       0        // eod
};

static const char qt_meta_stringdata_AccountViewer[] = {
    "AccountViewer\0\0changed\0"
    "accountsChanged(bb::pim::account::AccountsChanged)\0"
    "bb::cascades::DataModel*\0fields\0"
};

void AccountViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AccountViewer *_t = static_cast<AccountViewer *>(_o);
        switch (_id) {
        case 0: _t->accountsChanged((*reinterpret_cast< const bb::pim::account::AccountsChanged(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AccountViewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AccountViewer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AccountViewer,
      qt_meta_data_AccountViewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AccountViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AccountViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AccountViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AccountViewer))
        return static_cast<void*>(const_cast< AccountViewer*>(this));
    return QObject::qt_metacast(_clname);
}

int AccountViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bb::cascades::DataModel**>(_v) = fields(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
