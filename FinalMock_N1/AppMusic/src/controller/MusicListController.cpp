#include "MusicListController.h"
#include <QDir>
#include <QFileInfo>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QImage>
#include <QEventLoop>
#include <QImageReader>
#include "src/common/loghelper.h"

#define dirPathSong "/home/vtwo/FinalMock_N1/Music"

MusicListController* MusicListController::m_instance = nullptr;
MusicListController::MusicListController(QObject *parent)
    : QObject{parent}
{
    m_musicList = new MusicListModel();
    m_musicSearch = new MusicListModel();
}

MusicListController *MusicListController::getInstance()
{
    if (m_instance == nullptr) {
        m_instance = new MusicListController();
    }
    return m_instance;
}

void MusicListController::loadSong()
{
    QDir dir(dirPathSong);
    QStringList filters;
    filters << "*.mp3";
    QStringList fileList = dir.entryList(filters, QDir::Files);

    int i=0;
    foreach (QString fileName, fileList) {

        QString fullPath = dir.absoluteFilePath(fileName);

        QMediaPlayer mediaPlayer;
        QEventLoop loop;

        QObject::connect(&mediaPlayer, &QMediaPlayer::mediaStatusChanged, this, [&](QMediaPlayer::MediaStatus status) {
            if (status == QMediaPlayer::LoadedMedia) {
                loop.quit();
            }
        });

        mediaPlayer.setSource(QUrl::fromLocalFile(fullPath));
        mediaPlayer.play();
        loop.exec();

        QVariant title = mediaPlayer.metaData().value(QMediaMetaData::Title);
        QVariant albumTitle = mediaPlayer.metaData().value(QMediaMetaData::AlbumTitle);
        QVariant namesinger = mediaPlayer.metaData().value(QMediaMetaData::ContributingArtist);
        QVariant albumArt = mediaPlayer.metaData().value(QMediaMetaData::CoverArtImage);
        QVariant duration = mediaPlayer.metaData().value(QMediaMetaData::Duration);

        QString artPath;
        if (!albumArt.isNull()) {
            QImage coverImage = albumArt.value<QImage>();
            QString coverFilePath = fullPath.chopped(4) + ".jpg";
            qDebug() << coverFilePath;
            coverImage.save(coverFilePath);
            artPath = coverFilePath;
        }
        else{
            albumArt = mediaPlayer.metaData().value(QMediaMetaData::ThumbnailImage);
            qDebug() << albumArt;

            QImage coverImage = albumArt.value<QImage>();
            QString coverFilePath = fullPath.chopped(4) + ".jpg";
            qDebug() << coverFilePath;

            coverImage.save(coverFilePath);
            artPath = coverFilePath;
        }

        QImageReader reader(artPath);
        if (!reader.canRead()) artPath = "Unknown";
        if(title.toString() == "") title = "Unknown";
        if(albumTitle.toString() == "") albumTitle = "Unknown";
        if(namesinger.toString() == "") namesinger = "Unknown";

        qDebug() << "fullPath:" << fullPath;
        qDebug() << "Title:" << title.toString();
        qDebug() << "AlbumTitle:" << albumTitle.toString();
        qDebug() << "Singer:" << namesinger.toString();
        qDebug() << "Cover Art Path:" << artPath;


        SongInfo* song = new SongInfo();
        song->setSongID(i);
        song->setFileName(fileName);
        song->setTitleName(title.toString());
        song->setArtistName(namesinger.toString());
        song->setAlbumName(albumTitle.toString());
        song->setDuration(duration.toString());
        song->setCoverArt(artPath);

        m_musicList->addSong(song);
        i++;

        mediaPlayer.stop();
    }
}

MusicListModel* MusicListController::getModel()
{
    return m_musicList;
}

SongInfo *MusicListController::getSongFromList(int index)
{
    return m_musicList->getSongFromList(index);
}

void MusicListController::searchMusic(const QString &name)
{

    m_musicSearch->clearList();
    LOG_INFO;
    for(int i=0; i<m_musicList->rowCount(QModelIndex()); i++) {
        bool match1 = m_musicList->getSongFromList(i)->fileName().contains(name, Qt::CaseInsensitive);
        bool match2 = m_musicList->getSongFromList(i)->titleName().contains(name, Qt::CaseInsensitive);
        bool match3 = m_musicList->getSongFromList(i)->artistName().contains(name, Qt::CaseInsensitive);
        if (match1|| match2 || match3) {
            m_musicSearch->addSong(m_musicList->getSongFromList(i));
        }
    }
}

MusicListModel *MusicListController::getSearchModel()
{
    return m_musicSearch;
}

int MusicListController::listCount()
{
    return m_musicList->rowCount(QModelIndex());
}
