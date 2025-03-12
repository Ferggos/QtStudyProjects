/****************************************************************************
** Meta object code from reading C++ file 'hungarianalgorithm.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../hungarianalgorithm.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hungarianalgorithm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSHungarianAlgorithmENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSHungarianAlgorithmENDCLASS = QtMocHelpers::stringData(
    "HungarianAlgorithm",
    "initialMatrixChanged",
    "",
    "resultMatrixChanged",
    "totalCostChanged",
    "initialMatrix",
    "QList<QList<double>>",
    "resultMatrix",
    "totalCost"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSHungarianAlgorithmENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       3,   35, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x06,    4 /* Public */,
       3,    0,   33,    2, 0x06,    5 /* Public */,
       4,    0,   34,    2, 0x06,    6 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags, notifyId, revision
       5, 0x80000000 | 6, 0x00015009, uint(0), 0,
       7, 0x80000000 | 6, 0x00015009, uint(1), 0,
       8, QMetaType::Double, 0x00015001, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject HungarianAlgorithm::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSHungarianAlgorithmENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSHungarianAlgorithmENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSHungarianAlgorithmENDCLASS_t,
        // property 'initialMatrix'
        QtPrivate::TypeAndForceComplete<QList<QList<double>>, std::true_type>,
        // property 'resultMatrix'
        QtPrivate::TypeAndForceComplete<QList<QList<double>>, std::true_type>,
        // property 'totalCost'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<HungarianAlgorithm, std::true_type>,
        // method 'initialMatrixChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resultMatrixChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'totalCostChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void HungarianAlgorithm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HungarianAlgorithm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->initialMatrixChanged(); break;
        case 1: _t->resultMatrixChanged(); break;
        case 2: _t->totalCostChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HungarianAlgorithm::*)();
            if (_t _q_method = &HungarianAlgorithm::initialMatrixChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HungarianAlgorithm::*)();
            if (_t _q_method = &HungarianAlgorithm::resultMatrixChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HungarianAlgorithm::*)();
            if (_t _q_method = &HungarianAlgorithm::totalCostChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<double>> >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<HungarianAlgorithm *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<QList<double>>*>(_v) = _t->getInitialMatrix(); break;
        case 1: *reinterpret_cast< QList<QList<double>>*>(_v) = _t->getResultMatrix(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->getTotalCost(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *HungarianAlgorithm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HungarianAlgorithm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSHungarianAlgorithmENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HungarianAlgorithm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void HungarianAlgorithm::initialMatrixChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void HungarianAlgorithm::resultMatrixChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void HungarianAlgorithm::totalCostChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
