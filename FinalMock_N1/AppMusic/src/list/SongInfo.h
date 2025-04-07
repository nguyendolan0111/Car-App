#ifndef SONGINFO_H
#define SONGINFO_H

#include <QObject>

class SongInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int songID READ songID WRITE setSongID NOTIFY songIDChanged FINAL)
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged FINAL)
    Q_PROPERTY(QString duration READ duration WRITE setDuration NOTIFY durationChanged FINAL)
    Q_PROPERTY(QString titleName READ titleName WRITE setTitleName NOTIFY titleNameChanged FINAL)
    Q_PROPERTY(QString artistName READ artistName WRITE setArtistName NOTIFY artistNameChanged FINAL)
    Q_PROPERTY(QString albumName READ albumName WRITE setAlbumName NOTIFY albumNameChanged FINAL)
    Q_PROPERTY(QString coverArt READ coverArt WRITE setCoverArt NOTIFY coverArtChanged FINAL)
public:
    explicit SongInfo(QObject *parent = nullptr);

    int songID() const;
    void setSongID(int newSongID);

    QString duration() const;
    void setDuration(const QString &newDuration);

    QString titleName() const;
    void setTitleName(const QString &newTitleName);

    QString artistName() const;
    void setArtistName(const QString &newArtistName);

    QString albumName() const;
    void setAlbumName(const QString &newAlbumName);

    QString coverArt() const;
    void setCoverArt(const QString &newCoverArt);

    QString fileName() const;
    void setFileName(const QString &newFileName);

signals:
    void songIDChanged();
    void durationChanged();

    void titleNameChanged();

    void artistNameChanged();

    void albumNameChanged();

    void coverArtChanged();

    void fileNameChanged();

private:
    int m_songID;
    QString m_duration;
    QString m_titleName;
    QString m_artistName;
    QString m_albumName;
    QString m_coverArt;
    QString m_fileName;
};

#endif // SONGINFO_H
