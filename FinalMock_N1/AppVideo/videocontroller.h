#ifndef VIDEOCONTROLLER_H
#define VIDEOCONTROLLER_H

#include <QObject>
#include <QMediaPlayer>
#include <QVideoSink>
#include <QAudioOutput>
#include "videomodel.h"
#include "dbushandler.h"
#include "StatusBar_Interface.h"

class VideoController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVideoSink *videoSink READ videoSink WRITE setVideoSink NOTIFY videoSinkChanged FINAL)
    Q_PROPERTY(VideoModel *videoModel READ videoModel WRITE setVideoModel NOTIFY videoModelChanged FINAL)
    Q_PROPERTY(Video *currentVideo READ currentVideo WRITE setCurrentVideo NOTIFY currentVideoChanged FINAL)
    Q_PROPERTY(int position READ position WRITE setPosition NOTIFY positionChanged FINAL)
    Q_PROPERTY(int duration READ duration WRITE setDuration NOTIFY durationChanged FINAL)
    Q_PROPERTY(float volume READ volume WRITE setVolume NOTIFY volumeChanged FINAL)
    Q_PROPERTY(bool isPause READ isPause WRITE setIsPause NOTIFY isPauseChanged FINAL)
    Q_PROPERTY(int currentVideoIndex READ currentVideoIndex WRITE setCurrentVideoIndex NOTIFY currentVideoIndexChanged FINAL)
    Q_PROPERTY(bool loopPlay READ loopPlay WRITE setLoopPlay NOTIFY loopPlayChanged FINAL)
    Q_PROPERTY(bool randomPlay READ randomPlay WRITE setRandomPlay NOTIFY randomPlayChanged FINAL)
    Q_PROPERTY(bool showApp READ showApp WRITE setShowApp NOTIFY showAppChanged FINAL)

public:
    explicit VideoController(QObject *parent = nullptr);
    ~VideoController();

    QVideoSink *videoSink() const;

    VideoModel *videoModel() const;
    void setVideoModel(VideoModel *newVideoModel);

    Video *currentVideo() const;
    void setCurrentVideo(Video *newCurrentVideo);

    int position() const;
    void setPosition(int newPosition);

    int duration() const;
    void setDuration(int newDuration);

    float volume() const;
    void setVolume(float newVolume);

    bool isPause() const;
    void setIsPause(bool newIsPause);

    int currentVideoIndex() const;
    void setCurrentVideoIndex(int newCurrentVideoIndex);

    bool loopPlay() const;

    bool randomPlay() const;

    void loadSetting();
    void saveSetting();

    bool showApp() const;
    void setShowApp(bool newShowApp);

    void registerStatusBar(QQmlEngine* engine);

public slots:
    void setVideoSink(QVideoSink *newVideoSink);

    void playVideo();
    void pauseVideo();

    void nextVideo();
    void periousVideo();

    void playVideoWithIndex(int index);

    void searchVideo(const QString& str);

    void changePosition(int newPosiyion);

    void setRandomPlay(bool newRandomPlay);

    void setLoopPlay(bool newLoopPlay);

    void onOpenApp(int id);

    void onReturnHome();

    void onPause(bool isPause);

    void setDateStatusBar(const QString &date);
    void setTimeStatusBar(const QString &time);

private slots:
    void handleMediaStatusChanged(QMediaPlayer::MediaStatus status);
    void handlePositionChanged(qint64 position);

    void onSourceChangedSendClient();

signals:
    void videoSinkChanged();

    void videoModelChanged();

    void currentVideoChanged();

    void positionChanged();

    void durationChanged();

    void volumeChanged();

    void isPauseChanged();

    void currentVideoIndexChanged();

    void loopPlayChanged();

    void randomPlayChanged();

    void sourceMediaChanged();

    void setInforVideo();

    void showAppChanged();

    void runAppVideo();

    void currentLanguageChanged(const QString& idLang);

private:
    QMediaPlayer* m_mediaPlayer;
    QVideoSink* m_videoSink = nullptr;
    QAudioOutput* m_audioOutput;

    DbusHandler* m_dbusHandler;

    VideoModel* m_videoModel;
    Video* m_currentVideo;
    int m_currentVideoIndex;
    int m_position;
    int m_duration;
    float m_volume;
    bool m_isPause;
    bool m_loopPlay;
    bool m_randomPlay;
    bool m_showApp;

    MyStatusBarInterface* statusBar;
};

#endif // VIDEOCONTROLLER_H
