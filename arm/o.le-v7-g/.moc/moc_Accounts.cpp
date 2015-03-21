/****************************************************************************
** Meta object code from reading C++ file 'Accounts.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Accounts.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Accounts.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Accounts[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       2,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,    9,    9,    9, 0x0a,
      67,   57,    9,    9, 0x0a,
      99,    9,    9,    9, 0x0a,
     113,    9,    9,    9, 0x0a,
     129,    9,    9,    9, 0x0a,

 // properties: name, type, flags
     175,  145, 0x00095409,
     196,  181, 0x00095409,

       0        // eod
};

static const char qt_meta_stringdata_Accounts[] = {
    "Accounts\0\0code,message\0error(int,QString)\0"
    "loadAccounts()\0indexPath\0"
    "setCurrentAccount(QVariantList)\0"
    "viewAccount()\0deleteAccount()\0"
    "updateAccount()\0bb::cascades::GroupDataModel*\0"
    "model\0AccountViewer*\0accountViewer\0"
};

void Accounts::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Accounts *_t = static_cast<Accounts *>(_o);
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->loadAccounts(); break;
        case 2: _t->setCurrentAccount((*reinterpret_cast< const QVariantList(*)>(_a[1]))); break;
        case 3: _t->viewAccount(); break;
        case 4: _t->deleteAccount(); break;
        case 5: _t->updateAccount(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Accounts::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Accounts::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Accounts,
      qt_meta_data_Accounts, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Accounts::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Accounts::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Accounts::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Accounts))
        return static_cast<void*>(const_cast< Accounts*>(this));
    return QObject::qt_metacast(_clname);
}

int Accounts::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bb::cascades::GroupDataModel**>(_v) = model(); break;
        case 1: *reinterpret_cast< AccountViewer**>(_v) = accountViewer(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Accounts::error(int _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
