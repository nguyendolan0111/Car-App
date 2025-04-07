/****************************************************************************
** Meta object code from reading C++ file 'MusicPlaybackModel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/model/MusicPlaybackModel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MusicPlaybackModel.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMusicPlaybackModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMusicPlaybackModelENDCLASS = QtMocHelpers::stringData(
    "MusicPlaybackModel",
    "currentSongTitleChanged",
    "",
    "currentSongAlbumChanged",
    "currentArtistNameChanged",
    "coverArtChanged",
    "currentSongTitle",
    "currentSongAlbum",
    "currentArtistName",
    "coverArt"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMusicPlaybackModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       4,   42, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    5 /* Public */,
       3,    0,   39,    2, 0x06,    6 /* Public */,
       4,    0,   40,    2, 0x06,    7 /* Public */,
       5,    0,   41,    2, 0x06,    8 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::QString, 0x00015903, uint(0), 0,
       7, QMetaType::QString, 0x00015903, uint(1), 0,
       8, QMetaType::QString, 0x00015903, uint(2), 0,
       9, QMetaType::QString, 0x00015903, uint(3), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject MusicPlaybackModel::staticMetaObject = { {
    QMetaObject::SuperData::link<BasePlaybackModel::staticMetaObject>(),
    qt_meta_stringdata_CLASSMusicPlaybackModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMusicPlaybackModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMusicPlaybackModelENDCLASS_t,
        // property 'currentSongTitle'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'currentSongAlbum'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'currentArtistName'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'coverArt'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MusicPlaybackModel, std::true_type>,
        // method 'currentSongTitleChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentSongAlbumChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentArtistNameChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'coverArtChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MusicPlaybackModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MusicPlaybackModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->currentSongTitleChanged(); break;
        case 1: _t->currentSongAlbumChanged(); break;
        case 2: _t->currentArtistNameChanged(); break;
        case 3: _t->coverArtChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MusicPlaybackModel::*)();
            if (_t _q_method = &MusicPlaybackModel::currentSongTitleChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MusicPlaybackModel::*)();
            if (_t _q_method = &MusicPlaybackModel::currentSongAlbumChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MusicPlaybackModel::*)();
            if (_t _q_method = &MusicPlaybackModel::currentArtistNameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MusicPlaybackModel::*)();
            if (_t _q_method = &MusicPlaybackModel::coverArtChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MusicPlaybackModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->currentSongTitle(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->currentSongAlbum(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->currentArtistName(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->coverArt(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MusicPlaybackModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentSongTitle(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setCurrentSongAlbum(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setCurrentArtistName(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setCoverArt(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *MusicPlaybackModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicPlaybackModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMusicPlaybackModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return BasePlaybackModel::qt_metacast(_clname);
}

int MusicPlaybackModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BasePlaybackModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MusicPlaybackModel::currentSongTitleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MusicPlaybackModel::currentSongAlbumChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MusicPlaybackModel::currentArtistNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MusicPlaybackModel::coverArtChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
