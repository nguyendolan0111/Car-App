#ifndef MUSICLISTCONTROLLER_H
#define MUSICLISTCONTROLLER_H

#include <QObject>
#include "src/list/MusicListModel.h"
#include "src/list/SongInfo.h"

class MusicListController : public QObject
{
    Q_OBJECT

public:
    explicit MusicListController(QObject *parent = nullptr);

    static MusicListController *getInstance();

    void loadSong();
    MusicListModel* getModel();
    SongInfo* getSongFromList(int index);
    void searchMusic(const QString &name);
    MusicListModel* getSearchModel();
    int listCount();
signals:

private:
    static MusicListController* m_instance;
    MusicListModel* m_musicList;
    MusicListModel* m_musicSearch;
};

#endif // MUSICLISTCONTROLLER_H
