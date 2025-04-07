#include "SongInfo.h"

SongInfo::SongInfo(QObject *parent)
    : QObject{parent}
{}

int SongInfo::songID() const
{
    return m_songID;
}

void SongInfo::setSongID(int newSongID)
{
    if (m_songID == newSongID)
        return;
    m_songID = newSongID;
    emit songIDChanged();
}

QString SongInfo::duration() const
{
    return m_duration;
}

void SongInfo::setDuration(const QString &newDuration)
{
    if (m_duration == newDuration)
        return;
    m_duration = newDuration;
    emit durationChanged();
}

QString SongInfo::titleName() const
{
    return m_titleName;
}

void SongInfo::setTitleName(const QString &newTitleName)
{
    if (m_titleName == newTitleName)
        return;
    m_titleName = newTitleName;
    emit titleNameChanged();
}

QString SongInfo::artistName() const
{
    return m_artistName;
}

void SongInfo::setArtistName(const QString &newArtistName)
{
    if (m_artistName == newArtistName)
        return;
    m_artistName = newArtistName;
    emit artistNameChanged();
}

QString SongInfo::albumName() const
{
    return m_albumName;
}

void SongInfo::setAlbumName(const QString &newAlbumName)
{
    if (m_albumName == newAlbumName)
        return;
    m_albumName = newAlbumName;
    emit albumNameChanged();
}

QString SongInfo::coverArt() const
{
    return m_coverArt;
}

void SongInfo::setCoverArt(const QString &newCoverArt)
{
    if (m_coverArt == newCoverArt)
        return;
    m_coverArt = newCoverArt;
    emit coverArtChanged();
}

QString SongInfo::fileName() const
{
    return m_fileName;
}

void SongInfo::setFileName(const QString &newFileName)
{
    if (m_fileName == newFileName)
        return;
    m_fileName = newFileName;
    emit fileNameChanged();
}
