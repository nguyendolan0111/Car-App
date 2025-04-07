/****************************************************************************
** Meta object code from reading C++ file 'TimeSettingModel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TimeSettingModel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TimeSettingModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
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
struct qt_meta_stringdata_CLASSTimeSettingModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSTimeSettingModelENDCLASS = QtMocHelpers::stringData(
    "TimeSettingModel",
    "is24hFormatChanged",
    "",
    "isCustomFormatChanged",
    "hourChanged",
    "minuteChanged",
    "secondChanged",
    "dayChanged",
    "monthChanged",
    "yearChanged",
    "inforDateTime",
    "time",
    "date",
    "languageChanged",
    "updateDateTime",
    "is24hFormat",
    "isCustomFormat",
    "hour",
    "minute",
    "second",
    "day",
    "month",
    "year",
    "language"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTimeSettingModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       9,   95, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,   10 /* Public */,
       3,    0,   81,    2, 0x06,   11 /* Public */,
       4,    0,   82,    2, 0x06,   12 /* Public */,
       5,    0,   83,    2, 0x06,   13 /* Public */,
       6,    0,   84,    2, 0x06,   14 /* Public */,
       7,    0,   85,    2, 0x06,   15 /* Public */,
       8,    0,   86,    2, 0x06,   16 /* Public */,
       9,    0,   87,    2, 0x06,   17 /* Public */,
      10,    2,   88,    2, 0x06,   18 /* Public */,
      13,    0,   93,    2, 0x06,   21 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      14,    0,   94,    2, 0x0a,   22 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
      15, QMetaType::Bool, 0x00015103, uint(0), 0,
      16, QMetaType::Bool, 0x00015103, uint(1), 0,
      17, QMetaType::Int, 0x00015103, uint(2), 0,
      18, QMetaType::Int, 0x00015103, uint(3), 0,
      19, QMetaType::Int, 0x00015103, uint(4), 0,
      20, QMetaType::Int, 0x00015103, uint(5), 0,
      21, QMetaType::Int, 0x00015103, uint(6), 0,
      22, QMetaType::Int, 0x00015103, uint(7), 0,
      23, QMetaType::QString, 0x00015903, uint(9), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject TimeSettingModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSTimeSettingModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTimeSettingModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTimeSettingModelENDCLASS_t,
        // property 'is24hFormat'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'isCustomFormat'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'hour'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'minute'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'second'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'day'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'month'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'year'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'language'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TimeSettingModel, std::true_type>,
        // method 'is24hFormatChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'isCustomFormatChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'hourChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'minuteChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'secondChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dayChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'monthChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'yearChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'inforDateTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'languageChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateDateTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TimeSettingModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TimeSettingModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->is24hFormatChanged(); break;
        case 1: _t->isCustomFormatChanged(); break;
        case 2: _t->hourChanged(); break;
        case 3: _t->minuteChanged(); break;
        case 4: _t->secondChanged(); break;
        case 5: _t->dayChanged(); break;
        case 6: _t->monthChanged(); break;
        case 7: _t->yearChanged(); break;
        case 8: _t->inforDateTime((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 9: _t->languageChanged(); break;
        case 10: _t->updateDateTime(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TimeSettingModel::*)();
            if (_t _q_method = &TimeSettingModel::is24hFormatChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TimeSettingModel::*)();
            if (_t _q_method = &TimeSettingModel::isCustomFormatChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TimeSettingModel::*)();
            if (_t _q_method = &TimeSettingModel::hourChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TimeSettingModel::*)();
            if (_t _q_method = &TimeSettingModel::minuteChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TimeSettingModel::*)();
            if (_t _q_method = &TimeSettingModel::secondChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TimeSettingModel::*)();
            if (_t _q_method = &TimeSettingModel::dayChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TimeSettingModel::*)();
            if (_t _q_method = &TimeSettingModel::monthChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (TimeSettingModel::*)();
            if (_t _q_method = &TimeSettingModel::yearChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (TimeSettingModel::*)(QString , QString );
            if (_t _q_method = &TimeSettingModel::inforDateTime; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (TimeSettingModel::*)();
            if (_t _q_method = &TimeSettingModel::languageChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<TimeSettingModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->is24hFormat(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->isCustomFormat(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->hour(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->minute(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->second(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->day(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->month(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->year(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->language(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<TimeSettingModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setIs24hFormat(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setIsCustomFormat(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setHour(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setMinute(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setSecond(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setDay(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->setMonth(*reinterpret_cast< int*>(_v)); break;
        case 7: _t->setYear(*reinterpret_cast< int*>(_v)); break;
        case 8: _t->setLanguage(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *TimeSettingModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimeSettingModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTimeSettingModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TimeSettingModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void TimeSettingModel::is24hFormatChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TimeSettingModel::isCustomFormatChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TimeSettingModel::hourChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TimeSettingModel::minuteChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void TimeSettingModel::secondChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void TimeSettingModel::dayChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void TimeSettingModel::monthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void TimeSettingModel::yearChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void TimeSettingModel::inforDateTime(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void TimeSettingModel::languageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
