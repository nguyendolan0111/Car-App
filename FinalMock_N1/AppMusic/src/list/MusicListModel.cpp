#include "MusicListModel.h"

MusicListModel::MusicListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int MusicListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_listSong.count();
}

QVariant MusicListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() ||index.row() >=m_listSong.count()) {
        return QVariant();
    }
    const SongInfo* song = m_listSong[index.row()];
    if (role == SONG_ID) {
        return song->songID();
    } else if (role == FILE_NAME) {
        return song->fileName();
    } else if (role == DURATION) {
        return song->duration();
    } else if (role == TITLE_NAME) {
        return song->titleName();
    } else if (role == ARTIST_NAME) {
        return song->artistName();
    } else if (role == ALBUM_NAME) {
        return song->albumName();
    } else if (role == COVER_ART) {
        return song->coverArt();
    }
    else {
        return QVariant();
    }
}

bool MusicListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() ||index.row() >=m_listSong.count()) {
        return false;
    }

    SongInfo* song = m_listSong[index.row()];
    bool somgthingChanged = false;
    if (role == SONG_ID) {
        song->setSongID(value.toInt());
        somgthingChanged = true;
    } else if (role == FILE_NAME) {
        song->setFileName(value.toString());
        somgthingChanged = true;
    } else if (role == DURATION) {
        song->setDuration(value.toString());
        somgthingChanged = true;
    } else if (role == TITLE_NAME) {
        song->setTitleName(value.toString());
        somgthingChanged = true;
    } else if (role == ARTIST_NAME) {
        song->setArtistName(value.toString());
        somgthingChanged = true;
    } else if (role == ALBUM_NAME) {
        song->setAlbumName(value.toString());
        somgthingChanged = true;
    } else if (role == COVER_ART) {
        song->setCoverArt(value.toString());
        somgthingChanged = true;
    }

    if (somgthingChanged) {
        // emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

QHash<int, QByteArray> MusicListModel::roleNames() const
{
    QHash<int, QByteArray> roleMap;
    roleMap[SONG_ID] = "songID";
    roleMap[FILE_NAME] = "fileName";
    roleMap[DURATION] = "duration";
    roleMap[TITLE_NAME] = "titleName";
    roleMap[ARTIST_NAME] = "artistName";
    roleMap[ALBUM_NAME] = "albumName";
    roleMap[COVER_ART] = "coverArt";
    return roleMap;
}

void MusicListModel::addSong(SongInfo *song)
{
    beginInsertRows(QModelIndex(), rowCount(QModelIndex()), rowCount(QModelIndex()));
    // qDebug() << "add song";
    m_listSong.append(song);
    endInsertRows();
}

void MusicListModel::clearList()
{
    beginResetModel();
    m_listSong.clear();
    endResetModel();
}

SongInfo *MusicListModel::getSongFromList(int index)
{
    return m_listSong[index];
}
