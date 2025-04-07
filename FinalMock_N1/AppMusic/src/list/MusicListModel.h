#ifndef MUSICLISTMODEL_H
#define MUSICLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "SongInfo.h"
class MusicListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit MusicListModel(QObject *parent = nullptr);

public:
    enum SongRoles {
        SONG_ID = Qt::UserRole +1,
        FILE_NAME,
        DURATION,
        TITLE_NAME,
        ARTIST_NAME,
        ALBUM_NAME,
        COVER_ART
    };

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QHash<int, QByteArray> roleNames() const;
    void addSong(SongInfo* song);
    void clearList();

    SongInfo* getSongFromList(int index);
private:
    QList<SongInfo*> m_listSong;

};

#endif // MUSICLISTMODEL_H
