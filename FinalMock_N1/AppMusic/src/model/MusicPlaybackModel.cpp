#include "MusicPlaybackModel.h"

MusicPlaybackModel::MusicPlaybackModel(QObject *parent)
    :BasePlaybackModel{parent}
{

}

QString MusicPlaybackModel::currentSongTitle() const
{
    return m_currentSongTitle;
}

void MusicPlaybackModel::setCurrentSongTitle(const QString &newCurrentSongTitle)
{
    if (m_currentSongTitle == newCurrentSongTitle)
        return;
    m_currentSongTitle = newCurrentSongTitle;
    emit currentSongTitleChanged();
}

QString MusicPlaybackModel::currentSongAlbum() const
{
    return m_currentSongAlbum;
}

void MusicPlaybackModel::setCurrentSongAlbum(const QString &newCurrentSongAlbum)
{
    if (m_currentSongAlbum == newCurrentSongAlbum)
        return;
    m_currentSongAlbum = newCurrentSongAlbum;
    emit currentSongAlbumChanged();
}

QString MusicPlaybackModel::currentArtistName() const
{
    return m_currentArtistName;
}

void MusicPlaybackModel::setCurrentArtistName(const QString &newCurrentArtistName)
{
    if (m_currentArtistName == newCurrentArtistName)
        return;
    m_currentArtistName = newCurrentArtistName;
    emit currentArtistNameChanged();
}

QString MusicPlaybackModel::coverArt() const
{
    return m_coverArt;
}

void MusicPlaybackModel::setCoverArt(const QString &newCoverArt)
{
    if (m_coverArt == newCoverArt)
        return;
    m_coverArt = newCoverArt;
    emit coverArtChanged();
}
