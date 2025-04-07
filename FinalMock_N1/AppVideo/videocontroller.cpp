#include "videocontroller.h"
#include <QRandomGenerator>
#include <QObject>
#include <QSettings>
#include <QDir>
#include <QPluginLoader>

VideoController::VideoController(QObject *parent)
    : QObject{parent}, m_currentVideoIndex(0), m_position(0), m_duration(0), m_volume(1), m_isPause(true),
    m_loopPlay(false), m_randomPlay(false), m_showApp(false)
{
    m_dbusHandler = new DbusHandler();
    m_dbusHandler->registerDbus();

    m_mediaPlayer = new QMediaPlayer(this);
    m_videoSink = new QVideoSink();
    m_audioOutput = new QAudioOutput(this);

    m_mediaPlayer->setVideoSink(m_videoSink);
    m_mediaPlayer->setAudioOutput(m_audioOutput);

    m_videoModel = new VideoModel();

    connect(m_dbusHandler, &DbusHandler::openApp, this, &VideoController::onOpenApp);
    connect(m_dbusHandler, &DbusHandler::pauseApp, this, &VideoController::onPause);
    connect(m_dbusHandler, &DbusHandler::currentLanguage, this, &VideoController::currentLanguageChanged);
    connect(m_dbusHandler, &DbusHandler::dateTimeChangedSetting, this, [&](QString time, QString date){
        setDateStatusBar(date);
        setTimeStatusBar(time);
    });

    connect(m_mediaPlayer, &QMediaPlayer::mediaStatusChanged, this, &VideoController::handleMediaStatusChanged);
    connect(m_mediaPlayer, &QMediaPlayer::positionChanged, this, &VideoController::handlePositionChanged);
    connect(m_mediaPlayer, &QMediaPlayer::sourceChanged, this, &VideoController::sourceMediaChanged);
    connect(m_mediaPlayer, &QMediaPlayer::mediaStatusChanged, this, &VideoController::onSourceChangedSendClient);
    connect(this, &VideoController::runAppVideo, this, [](){
        FHome::getInstane()->onRunAppVideo();
        FMusic::getInstane()->onRunAppVideo();
    });

    QDir pluginDir("/home/vtwo/FinalMock_N1/AppHome/plugin");
    foreach (QString fileName, pluginDir.entryList(QDir::Files)) {
        QPluginLoader loader(pluginDir.absoluteFilePath(fileName));
        QObject *plugin = loader.instance();
        if (plugin) {
            QString pluginName = plugin->metaObject()->className();
            if (pluginName == "MyPlugin") {
                statusBar= qobject_cast<MyStatusBarInterface*>(plugin);
                if (statusBar) {
                    qDebug() << "Dont create StatusBarInterface";
                }
            }
        }
    }

    connect(m_dbusHandler, &DbusHandler::volumeChangedSetting, this, [&](int volume){
        setVolume(float(float(volume)/10.0));
    });

    loadSetting();
}

VideoController::~VideoController()
{
    saveSetting();
}

QVideoSink *VideoController::videoSink() const
{
    return m_videoSink;
}

void VideoController::setVideoSink(QVideoSink *newVideoSink)
{
    if (m_videoSink == newVideoSink)
        return;
    m_videoSink = newVideoSink;
    m_mediaPlayer->setVideoSink(m_videoSink);
    emit videoSinkChanged();
}

VideoModel *VideoController::videoModel() const
{
    return m_videoModel;
}

void VideoController::setVideoModel(VideoModel *newVideoModel)
{
    if (m_videoModel == newVideoModel)
        return;
    m_videoModel = newVideoModel;
    emit videoModelChanged();
}

Video *VideoController::currentVideo() const
{
    return m_currentVideo;
}

void VideoController::setCurrentVideo(Video *newCurrentVideo)
{
    if (m_currentVideo == newCurrentVideo)
        return;
    m_currentVideo = newCurrentVideo;
    emit currentVideoChanged();
}

int VideoController::currentVideoIndex() const
{
    return m_currentVideoIndex;
}

void VideoController::setCurrentVideoIndex(int newCurrentVideoIndex)
{
    if (m_currentVideoIndex == newCurrentVideoIndex)
        return;
    m_currentVideoIndex = newCurrentVideoIndex;
    saveSetting();
    emit currentVideoIndexChanged();
}

bool VideoController::isPause() const
{
    return m_isPause;
}

void VideoController::setIsPause(bool newIsPause)
{
    if (m_isPause == newIsPause)
        return;
    m_isPause = newIsPause;
    saveSetting();
    emit isPauseChanged();
}

float VideoController::volume() const
{
    return m_volume;
}

void VideoController::setVolume(float newVolume)
{
    if (qFuzzyCompare(m_volume, newVolume))
        return;
    m_volume = newVolume;
    if(m_audioOutput) m_audioOutput->setVolume(m_volume);
    saveSetting();
    emit volumeChanged();
}

int VideoController::duration() const
{
    return m_duration;
}

void VideoController::setDuration(int newDuration)
{
    if (m_duration == newDuration)
        return;
    m_duration = newDuration;
    saveSetting();
    emit durationChanged();
}

int VideoController::position() const
{
    return m_position;
}

void VideoController::setPosition(int newPosition)
{
    if (m_position == newPosition)
        return;
    m_position = newPosition;
    saveSetting();
    emit positionChanged();
}

void VideoController::playVideo()
{
    setIsPause(false);
    m_dbusHandler->callMethod("requestPauseVideo", {true});
    m_mediaPlayer->play();
}

void VideoController::pauseVideo()
{
    setIsPause(true);
    m_mediaPlayer->pause();
}

void VideoController::nextVideo()
{
    if(m_currentVideoIndex == m_videoModel->totalVideo() - 1){
        setCurrentVideoIndex(0);
    }
    else{
        setCurrentVideoIndex(m_currentVideoIndex + 1);
    }

    m_currentVideo = m_videoModel->currentVideo(m_currentVideoIndex);
    m_mediaPlayer->setSource(QUrl("file://" + m_currentVideo->filePath()));
    playVideo();
}

void VideoController::periousVideo()
{
    if(m_currentVideoIndex == 0){
        setCurrentVideoIndex(m_videoModel->totalVideo() - 1);
    }
    else{
        setCurrentVideoIndex(m_currentVideoIndex - 1);
    }

    m_currentVideo = m_videoModel->currentVideo(m_currentVideoIndex);
    m_mediaPlayer->setSource(QUrl("file://" + m_currentVideo->filePath()));
    playVideo();
}

void VideoController::playVideoWithIndex(int index)
{
    setCurrentVideoIndex(index);
    m_currentVideo = m_videoModel->currentVideo(m_currentVideoIndex);
    m_mediaPlayer->setSource(QUrl("file://" + m_currentVideo->filePath()));
    playVideo();
}

void VideoController::searchVideo(const QString &str)
{
    m_videoModel->searchVideo(str);
    setCurrentVideoIndex(m_videoModel->currentVideo(m_currentVideo->fileName()));
}

void VideoController::changePosition(int newPosition)
{
    setPosition(newPosition);
    m_mediaPlayer->setPosition(m_position*1000);
}

void VideoController::handleMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::LoadedMedia) {
        setDuration(m_mediaPlayer->duration() / 1000);
        m_mediaPlayer->setPosition(m_position*1000);
        emit positionChanged();
    }

    if(status == QMediaPlayer::EndOfMedia){
        if(m_loopPlay == true){
            qDebug() << "Loop Video";
            playVideo();
        }
        else if(m_randomPlay == true){
            qDebug() << "Random Video";
            int randomNumber = -1;
            do{
                randomNumber = QRandomGenerator::global()->bounded(0, m_videoModel->totalVideo());
            }
            while(randomNumber == m_currentVideoIndex || randomNumber == -1);
            setCurrentVideoIndex(randomNumber);
            m_currentVideo = m_videoModel->currentVideo(m_currentVideoIndex);
            m_mediaPlayer->setSource(QUrl("file://" + m_currentVideo->filePath()));
            playVideo();
        }
        else{
            qDebug() << "Next Video";
            nextVideo();
        }
    }
}

void VideoController::handlePositionChanged(qint64 position)
{
    setPosition(static_cast<int>(position)/1000);
}

void VideoController::onSourceChangedSendClient()
{
    qDebug() << "onSourceChangedSendClient";
    m_dbusHandler->callMethod("inforVideo", {m_currentVideo->fileName()});
}

void VideoController::onOpenApp(int id)
{
    if(id == 1){
        setShowApp(true);
    }
}

void VideoController::onReturnHome()
{
    setShowApp(false);
    FHome::getInstane()->returnHome();
}

void VideoController::onPause(bool isPause)
{
    if (m_isPause !=isPause) {
        pauseVideo();
    }
}

void VideoController::setDateStatusBar(const QString &date)
{
    statusBar->setDate(date);
}

void VideoController::setTimeStatusBar(const QString &time)
{
    statusBar->setTime(time);
}

bool VideoController::showApp() const
{
    return m_showApp;
}

void VideoController::setShowApp(bool newShowApp)
{
    if (m_showApp == newShowApp)
        return;
    m_showApp = newShowApp;
    emit showAppChanged();
}

void VideoController::registerStatusBar(QQmlEngine *engine)
{
    statusBar->registerObject(engine);
}

bool VideoController::randomPlay() const
{
    return m_randomPlay;
}

void VideoController::loadSetting()
{
    QSettings settings("VUNV29", "AppVideo");

    m_currentVideoIndex = settings.value("currentVideoIndex", 0).toInt();
    m_duration = settings.value("duration", 0).toInt();
    m_position = settings.value("position", 0).toInt();
    m_volume = settings.value("volume", 0.5).toFloat();
    m_randomPlay = settings.value("randomPlay", false).toBool();
    m_loopPlay = settings.value("loopPlay", false).toBool();
    m_isPause = settings.value("isPause", false).toBool();

    qDebug() << "Loaded Settings:"
             << "Current Song Index:" << m_currentVideoIndex
             << "Duration:" << m_duration
             << "Position:" << m_position
             << "Volume:" << m_volume
             << "Random Play:" << m_randomPlay
             << "Loop Play:" << m_loopPlay
             << "Is Pause:" << m_isPause;

    emit currentVideoIndexChanged();
    emit volumeChanged();
    emit durationChanged();
    emit positionChanged();
    emit isPauseChanged();
    emit randomPlayChanged();
    emit loopPlayChanged();

    m_currentVideo = m_videoModel->currentVideo(m_currentVideoIndex);
    m_mediaPlayer->setSource(QUrl("file://" + m_currentVideo->filePath()));
    m_mediaPlayer->setPosition(m_position*1000);
    m_audioOutput->setVolume(m_volume);

    emit setInforVideo();

    if(m_isPause == false){
        playVideo();
    }
}

void VideoController::saveSetting()
{
    QSettings settings = QSettings("VUNV29", "AppVideo");

    settings.setValue("currentVideoIndex", m_currentVideoIndex);
    settings.setValue("duration", m_duration);
    settings.setValue("position", m_position);
    settings.setValue("volume", m_volume);
    settings.setValue("randomPlay", m_randomPlay);
    settings.setValue("loopPlay", m_loopPlay);
    settings.setValue("isPause", m_isPause);
}

void VideoController::setRandomPlay(bool newRandomPlay)
{
    if (m_randomPlay == newRandomPlay)
        return;
    m_randomPlay = newRandomPlay;
    saveSetting();
    emit randomPlayChanged();
}

bool VideoController::loopPlay() const
{
    return m_loopPlay;
}

void VideoController::setLoopPlay(bool newLoopPlay)
{
    if (m_loopPlay == newLoopPlay)
        return;
    m_loopPlay = newLoopPlay;
    saveSetting();
    emit loopPlayChanged();
}
