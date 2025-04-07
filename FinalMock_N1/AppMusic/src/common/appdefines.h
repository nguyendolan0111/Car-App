#ifndef APPDEFINES_H
#define APPDEFINES_H

#include <QObject>
#include <QMap>

#define MAIN_QML "qrc:/qml/main.qml"

class AppEnums: public QObject
{
    Q_OBJECT
    Q_ENUMS()
public:
    enum SCREEN_ID : int
    {
        SCREEN_ID_MUSIC_PLAYER,
        SCREEN_ID_MUSIC_LIST,
        SCREEN_ID_MUSIC_SEARCH
    };
};

const QMap<int, QString> ScreenNameMap
    {
        {AppEnums::SCREEN_ID_MUSIC_PLAYER, "qrc:/qml/screen/MusicPlayerScreen.qml"},
        {AppEnums::SCREEN_ID_MUSIC_LIST, "qrc:/qml/screen/MusicListScreen.qml"},
        {AppEnums::SCREEN_ID_MUSIC_SEARCH, "qrc:/qml/screen/MusicSearchScreen.qml"}
    };

#endif // APPDEFINES_H
