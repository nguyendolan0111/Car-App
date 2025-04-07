/****************************************************************************
** Meta object code from reading C++ file 'SongInfo.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/list/SongInfo.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SongInfo.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSongInfoENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSongInfoENDCLASS = QtMocHelpers::stringData(
    "SongInfo",
    "songIDChanged",
    "",
    "durationChanged",
    "titleNameChanged",
    "artistNameChanged",
    "albumNameChanged",
    "coverArtChanged",
    "fileNameChanged",
    "songID",
    "fileName",
    "duration",
    "titleName",
    "artistName",
    "albumName",
    "coverArt"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSongInfoENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       7,   63, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    8 /* Public */,
       3,    0,   57,    2, 0x06,    9 /* Public */,
       4,    0,   58,    2, 0x06,   10 /* Public */,
       5,    0,   59,    2, 0x06,   11 /* Public */,
       6,    0,   60,    2, 0x06,   12 /* Public */,
       7,    0,   61,    2, 0x06,   13 /* Public */,
       8,    0,   62,    2, 0x06,   14 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       9, QMetaType::Int, 0x00015903, uint(0), 0,
      10, QMetaType::QString, 0x00015903, uint(6), 0,
      11, QMetaType::QString, 0x00015903, uint(1), 0,
      12, QMetaType::QString, 0x00015903, uint(2), 0,
      13, QMetaType::QString, 0x00015903, uint(3), 0,
      14, QMetaType::QString, 0x00015903, uint(4), 0,
      15, QMetaType::QString, 0x00015903, uint(5), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject SongInfo::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSSongInfoENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSongInfoENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSongInfoENDCLASS_t,
        // property 'songID'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'fileName'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'duration'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'titleName'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'artistName'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'albumName'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'coverArt'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SongInfo, std::true_type>,
        // method 'songIDChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'durationChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'titleNameChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'artistNameChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'albumNameChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'coverArtChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'fileNameChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SongInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SongInfo *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->songIDChanged(); break;
        case 1: _t->durationChanged(); break;
        case 2: _t->titleNameChanged(); break;
        case 3: _t->artistNameChanged(); break;
        case 4: _t->albumNameChanged(); break;
        case 5: _t->coverArtChanged(); break;
        case 6: _t->fileNameChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SongInfo::*)();
            if (_t _q_method = &SongInfo::songIDChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SongInfo::*)();
            if (_t _q_method = &SongInfo::durationChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SongInfo::*)();
            if (_t _q_method = &SongInfo::titleNameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SongInfo::*)();
            if (_t _q_method = &SongInfo::artistNameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SongInfo::*)();
            if (_t _q_method = &SongInfo::albumNameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SongInfo::*)();
            if (_t _q_method = &SongInfo::coverArtChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SongInfo::*)();
            if (_t _q_method = &SongInfo::fileNameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SongInfo *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->songID(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->fileName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->duration(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->titleName(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->artistName(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->albumName(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->coverArt(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SongInfo *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSongID(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setFileName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setDuration(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setTitleName(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setArtistName(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setAlbumName(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setCoverArt(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *SongInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SongInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSongInfoENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SongInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void SongInfo::songIDChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SongInfo::durationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SongInfo::titleNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SongInfo::artistNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SongInfo::albumNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SongInfo::coverArtChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void SongInfo::fileNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
