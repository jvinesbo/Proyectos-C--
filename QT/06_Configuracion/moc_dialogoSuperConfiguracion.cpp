/****************************************************************************
** Meta object code from reading C++ file 'dialogoSuperConfiguracion.h'
**
** Created: Tue Jan 28 19:04:03 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dialogoSuperConfiguracion.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogoSuperConfiguracion.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogoSuperConfiguracion[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   26,   26,   26, 0x0a,
      44,   26,   26,   26, 0x0a,
      66,   26,   26,   26, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DialogoSuperConfiguracion[] = {
    "DialogoSuperConfiguracion\0\0cambiarSolidez()\0"
    "controlarClickRaton()\0cambiarIntervalo()\0"
};

void DialogoSuperConfiguracion::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DialogoSuperConfiguracion *_t = static_cast<DialogoSuperConfiguracion *>(_o);
        switch (_id) {
        case 0: _t->cambiarSolidez(); break;
        case 1: _t->controlarClickRaton(); break;
        case 2: _t->cambiarIntervalo(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DialogoSuperConfiguracion::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DialogoSuperConfiguracion::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogoSuperConfiguracion,
      qt_meta_data_DialogoSuperConfiguracion, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogoSuperConfiguracion::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogoSuperConfiguracion::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogoSuperConfiguracion::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogoSuperConfiguracion))
        return static_cast<void*>(const_cast< DialogoSuperConfiguracion*>(this));
    if (!strcmp(_clname, "Ui::DialogoSuperConfiguracion"))
        return static_cast< Ui::DialogoSuperConfiguracion*>(const_cast< DialogoSuperConfiguracion*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogoSuperConfiguracion::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
