#include "videomodel.h"
#include <QDir>
#include <QDebug>
#include <QImageReader>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QEventLoop>

#define dirPathVideo "/home/vtwo/FinalMock_N1/Video"

VideoModel::VideoModel(QObject* parent )
    : QAbstractListModel(parent), m_userSearchList(false)
{
    loadDataFromFile();
}

VideoModel::~VideoModel()
{
    qDeleteAll(m_listVideo);
    qDeleteAll(m_listVideoSearch);
}

void VideoModel::addVideo(Video* video)
{
    if(m_userSearchList){
        beginInsertRows(QModelIndex(), m_listVideoSearch.size(), m_listVideoSearch.size());
        m_listVideoSearch.append(video);
        endInsertRows();
    }
    else{
        beginInsertRows(QModelIndex(), m_listVideo.size(), m_listVideo.size());
        m_listVideo.append(video);
        endInsertRows();
    }
}

int VideoModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    if(parent.isValid()) return 0;

    if(m_userSearchList){
        return m_listVideoSearch.size();
    }
    else{
        return m_listVideo.size();
    }
    return 0;
}

QVariant VideoModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const QList<Video*> * list = m_userSearchList ? &m_listVideoSearch : &m_listVideo;

    Video* video = list->at(index.row());

    if (role == FilePathRole)
        return video->filePath();
    else if (role == FileNameRole)
        return video->fileName();
    return QVariant();
}

QHash<int, QByteArray> VideoModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[FilePathRole] = "TheFilePath";
    roles[FileNameRole] = "TheFileName";

    return roles;
}

bool VideoModel::userSearchList() const
{
    return m_userSearchList;
}

void VideoModel::setUserSearchList(bool newUserSearchList)
{
    if (m_userSearchList == newUserSearchList)
        return;
    beginResetModel();
    m_userSearchList = newUserSearchList;
    qDebug() << m_userSearchList;
    endResetModel();
    emit userSearchListChanged();
}

void VideoModel::loadDataFromFile()
{
    QDir dir(dirPathVideo);
    if (!dir.exists()) {
        qWarning() << "Directory does not exist:" << dirPathVideo;
        return;
    }

    QStringList filters;
    filters << "*.mp4";
    QStringList files = dir.entryList(filters, QDir::Files | QDir::NoDotAndDotDot);
    QString fullpath, filename;

    for (const QString &file : files) {
        QFileInfo fileInfo(dir.absoluteFilePath(file));

        fullpath = fileInfo.absoluteFilePath();
        filename = fileInfo.fileName();

        qDebug() << "Full path: " << fullpath;
        qDebug() << "File Name:" << filename;

        m_listVideo.append(new Video(fullpath, filename));
    }
}

Video *VideoModel::currentVideo(int index)
{
    if(m_userSearchList){
        return m_listVideoSearch[index];
    }
    else{
        return m_listVideo[index];
    }
}

int VideoModel::currentVideo(const QString &str)
{
    int count = 0;
    if(m_userSearchList){
        foreach (Video* video, m_listVideoSearch) {
            if(video->fileName() == str){
                return count;
            }
            count++;
        }
    }
    else{
        foreach (Video* video, m_listVideo) {
            if(video->fileName() == str){
                return count;
            }
            count++;
        }
    }
    return -1;
}

int VideoModel::totalVideo()
{
    if(m_userSearchList){
        return m_listVideoSearch.size();
    }
    else {
        return m_listVideo.size();
    }
}

void VideoModel::searchVideo(const QString &str)
{
    beginResetModel();
    m_listVideoSearch.clear();
    if(str.isEmpty()) {
        setUserSearchList(false);
    } else {
        for(Video* video : m_listVideo) {
            if(video->fileName().contains(str, Qt::CaseInsensitive) ||
                video->filePath().contains(str, Qt::CaseInsensitive)) {
                addVideo(video);
            }
        }
    }
    endResetModel();
}
