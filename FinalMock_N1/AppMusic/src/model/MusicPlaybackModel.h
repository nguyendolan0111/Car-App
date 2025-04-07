#ifndef MUSICPLAYBACKMODEL_H
#define MUSICPLAYBACKMODEL_H

#include <QObject>
#include "BasePlaybackModel.h"

class MusicPlaybackModel : public BasePlaybackModel
{
    Q_OBJECT
    Q_PROPERTY(QString currentSongTitle READ currentSongTitle WRITE setCurrentSongTitle NOTIFY currentSongTitleChanged FINAL)
    Q_PROPERTY(QString currentSongAlbum READ currentSongAlbum WRITE setCurrentSongAlbum NOTIFY currentSongAlbumChanged FINAL)
    Q_PROPERTY(QString currentArtistName READ currentArtistName WRITE setCurrentArtistName NOTIFY currentArtistNameChanged FINAL)
    Q_PROPERTY(QString coverArt READ coverArt WRITE setCoverArt NOTIFY coverArtChanged FINAL)
public:
    explicit MusicPlaybackModel(QObject* parent = nullptr);
    QString currentSongTitle() const;
    void setCurrentSongTitle(const QString &newCurrentSongTitle);
    QString currentSongAlbum() const;
    void setCurrentSongAlbum(const QString &newCurrentSongAlbum);

    QString currentArtistName() const;
    void setCurrentArtistName(const QString &newCurrentArtistName);

    QString coverArt() const;
    void setCoverArt(const QString &newCoverArt);

signals:
    void currentSongTitleChanged();
    void currentSongAlbumChanged();

    void currentArtistNameChanged();

    void coverArtChanged();

private:
    QString m_currentSongTitle;
    QString m_currentSongAlbum;
    QString m_currentArtistName;
    QString m_coverArt;
};

#endif // MUSICPLAYBACKMODEL_H
