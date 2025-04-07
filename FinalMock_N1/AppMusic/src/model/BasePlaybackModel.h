#ifndef BASEPLAYBACKMODEL_H
#define BASEPLAYBACKMODEL_H

#include <QObject>
#include <QtMultimedia/QMediaPlayer>
class BasePlaybackModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int totalTime READ totalTime WRITE setTotalTime NOTIFY totalTimeChanged FINAL)
    Q_PROPERTY(int currentTime READ currentTime WRITE setCurrentTime NOTIFY currentTimeChanged FINAL)
    Q_PROPERTY(QMediaPlayer::PlaybackState status READ status WRITE setStatus NOTIFY statusChanged FINAL)
public:
    explicit BasePlaybackModel(QObject *parent = nullptr);

    int totalTime() const;
    void setTotalTime(int newTotalTime);

    int currentTime() const;
    void setCurrentTime(int newCurrentTime);

    QMediaPlayer::PlaybackState status() const;
    void setStatus(const QMediaPlayer::PlaybackState &newStatus);

signals:
    void totalTimeChanged();
    void currentTimeChanged();

    void statusChanged();

private:
    int m_totalTime;
    int m_currentTime;
    QMediaPlayer::PlaybackState m_status;
};

#endif // BASEPLAYBACKMODEL_H
