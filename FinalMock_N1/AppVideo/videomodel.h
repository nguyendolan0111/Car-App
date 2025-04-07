#ifndef VIDEOMODEL_H
#define VIDEOMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QList>
#include <QMutex>
#include "video.h"

class VideoModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(bool userSearchList READ userSearchList WRITE setUserSearchList NOTIFY userSearchListChanged FINAL)

public:
    enum VideoRoles {
        FilePathRole = Qt::UserRole + 1,
        FileNameRole
    };

    explicit VideoModel(QObject *parent = nullptr);
    ~VideoModel();

    bool userSearchList() const;
    void setUserSearchList(bool newUserSearchList);

    void addVideo(Video *video);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void loadDataFromFile();
    Video* currentVideo(int index);
    int currentVideo(const QString& str);
    int totalVideo();
    void searchVideo(const QString &str);

signals:
    void userSearchListChanged();

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<Video* > m_listVideo;
    QList<Video* > m_listVideoSearch;
    bool m_userSearchList;
};

#endif // VIDEOMODEL_H
