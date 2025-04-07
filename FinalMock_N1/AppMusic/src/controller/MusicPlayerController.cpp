#include "MusicPlayerController.h"
#include "src/common/loghelper.h"
#include <QMediaMetaData>
#include <QDir>
#include <QRandomGenerator>
#include <QPluginLoader>

QString sourceFolder;
#define dirPathSong "/home/vtwo/FinalMock_N1/Music"
MusicPlayerController* MusicPlayerController::m_instance = nullptr;
MusicPlayerController::MusicPlayerController(QObject *parent)
    : QObject{parent}
{
    Player = new QMediaPlayer();
    m_audio = new QAudioOutput();
    m_currentSong = new MusicPlaybackModel();
    Player->setAudioOutput(m_audio);

    QObject::connect(Player, &QMediaPlayer::positionChanged, this, &MusicPlayerController::changePosition);
    QObject::connect(Player, &QMediaPlayer::mediaStatusChanged, this, &MusicPlayerController::StatusChanged);
    QObject::connect(Player, &QMediaPlayer::playbackStateChanged, this, &MusicPlayerController::StatusPlayChange);
    QObject::connect(this, &MusicPlayerController::currentSongIndexChanged, this, &MusicPlayerController::setPlaySong);
    connect(this, &MusicPlayerController::loopChanged, this, &MusicPlayerController::setInforScreen);
    connect(this, &MusicPlayerController::radomChanged, this, &MusicPlayerController::setInforScreen);
    connect(this, &MusicPlayerController::pauseChanged, this, &MusicPlayerController::setInforScreen);

    listController = new MusicListController();
    listController->loadSong();
    SearchSong("");
    QDir dir(dirPathSong);
    sourceFolder = dir.absolutePath()+"/";
    qDebug() << sourceFolder;

    QDir pluginDir("/home/vtwo/FinalMock_N1/AppMusic/plugin");
    foreach (QString fileName, pluginDir.entryList(QDir::Files)) {
        QPluginLoader loader(pluginDir.absoluteFilePath(fileName));
        QObject *plugin = loader.instance();
        if (plugin) {
            QString pluginName = plugin->metaObject()->className();
            if (pluginName == "MyPlugin") {
                statusBar = qobject_cast<MyStatusBarInterface*>(plugin);
                if (statusBar) {
                    qDebug() << "Dont create StatusBarInterface";
                }
            }
        }
    }

    iniSetting();

    Player->setSource(sourceFolder + listController->getSongFromList(m_currentIndex)->fileName());

    if (!m_pause) {
        Player->play();
        setPosition(m_currentSong->currentTime());
    }
    else{
        Player->pause();
    }
    qDebug() << "current Time Init" << m_currentSong->currentTime();
}

MusicPlayerController::~MusicPlayerController()
{
    saveSetting();
    delete Player;
    delete m_audio;
    delete m_currentSong;
}

MusicPlayerController *MusicPlayerController::getInstance()
{
    if (m_instance == nullptr) {
        m_instance = new MusicPlayerController();
    }
    return m_instance;
}

void MusicPlayerController::initialize(QQmlContext *context)
{
    context->setContextProperty("PlayerControl", this);
    context->setContextProperty("MusicModel", m_instance->getModel());
    context->setContextProperty("SearchModel", m_instance->getSearchModel());
}

MusicListModel *MusicPlayerController::getModel()
{
    return listController->getModel();
}

void MusicPlayerController::SearchSong(const QString &searchString)
{
    listController->searchMusic(searchString);
}

MusicListModel *MusicPlayerController::getSearchModel()
{
    return listController->getSearchModel();
}

void MusicPlayerController::requestPlay()
{
    setPause(false);
    MusicDbusHandler::getInstance()->callMethod("requestPauseMusic", {true});
    Player->play();
    setPosition(m_currentSong->currentTime());
}

void MusicPlayerController::requestPause()
{
    setPause(true);
    Player->pause();
}

void MusicPlayerController::requestStop()
{
    Player->stop();
}

void MusicPlayerController::requestNext()
{
    LOG_INFO;
    if (m_random) {
        m_currentIndex = QRandomGenerator::global()->bounded(0, listController->listCount()-1);
        qDebug() << m_currentIndex;
        emit currentIndexChanged();
        emit currentSongIndexChanged(m_currentIndex);
    } else {
        if (m_currentIndex < listController->listCount() - 1){
            m_currentIndex++;
            emit currentIndexChanged();
            emit currentSongIndexChanged(m_currentIndex);
        } else {
            m_currentIndex=0;
            emit currentIndexChanged();
            emit currentSongIndexChanged(0);
        }
    }
}

void MusicPlayerController::requestPrevious()
{
    LOG_INFO;
    if (m_random) {
        m_currentIndex = QRandomGenerator::global()->bounded(0, listController->listCount()-1);
        qDebug() << m_currentIndex;
        emit currentIndexChanged();
        emit currentSongIndexChanged(m_currentIndex);
    } else {
        if (m_currentIndex > 0) {
            m_currentIndex--;
            emit currentIndexChanged();
            emit currentSongIndexChanged(m_currentIndex);
        } else {
            m_currentIndex = listController->listCount()-1;
            emit currentIndexChanged();
            emit currentSongIndexChanged(listController->listCount()-1);
        }
    }
}

void MusicPlayerController::requestFastForward()
{
    Player->setPosition(m_currentSong->currentTime()+10000);
    LOG_INFO;
}

void MusicPlayerController::requestFastBackward()
{

    Player->setPosition(m_currentSong->currentTime()-10000);
    LOG_INFO;
}

void MusicPlayerController::setPosition(int position)
{
    Player->stop();
    Player->play();
    Player->setPosition(position);
}

void MusicPlayerController::changePosition(qint64 position)
{
    m_currentSong->setCurrentTime(position);
}

void MusicPlayerController::StatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::MediaStatus::LoadedMedia) {

        m_currentSong->setTotalTime(listController->getSongFromList(m_currentIndex)->duration().toInt());
        m_currentSong->setCurrentSongAlbum(listController->getSongFromList(m_currentIndex)->albumName());
        m_currentSong->setCurrentSongTitle(listController->getSongFromList(m_currentIndex)->titleName());
        m_currentSong->setCurrentArtistName(listController->getSongFromList(m_currentIndex)->artistName());
        m_currentSong->setCoverArt(listController->getSongFromList(m_currentIndex)->coverArt());
        LOG_INFO;
        emit currentSongChanged();

    } else if (status == QMediaPlayer::MediaStatus::EndOfMedia) {
        if (m_loop) {
            setPlaySong(m_currentIndex);
        } else {
            requestNext();
        }
    }

}

void MusicPlayerController::StatusPlayChange(QMediaPlayer::PlaybackState status)
{
    LOG_INFO;
    sendMusicInfoToHome();
    m_currentSong->setStatus(status);
    emit currentSongChanged();
}

void MusicPlayerController::setPlaySong(int index)
{
    if (m_currentIndex != index) {
        m_currentIndex = index;
        emit currentIndexChanged();
    }
    Player->stop();
    setPause(false);
    Player->setSource(sourceFolder+listController->getSongFromList(m_currentIndex)->fileName());
    MusicDbusHandler::getInstance()->callMethod("requestPauseMusic", {true});
    Player->play();
}

void MusicPlayerController::sendMusicInfoToHome()
{
    LOG_INFO;
    QString title = m_currentSong->currentSongTitle();
    QString artistName = m_currentSong->currentArtistName();
    QString coverArt = m_currentSong->coverArt();
    QMediaPlayer::PlaybackState status = m_currentSong->status();
    QJsonObject jsonObj;
    QJsonObject subObj;
    subObj.insert("Title", title);
    subObj.insert("Artist", artistName);
    subObj.insert("CoverArt", coverArt);
    subObj.insert("Status", status);
    jsonObj.insert("msg", "MusicInfo");
    jsonObj.insert("data", subObj);
    QString mess = QString(QJsonDocument(jsonObj).toJson(QJsonDocument::Compact));
    MusicDbusHandler::getInstance()->callMethod("inforMusic", {mess});
}

void MusicPlayerController::onPause(bool isPause)
{
    if (isPause) {
        requestPause();
    }
}

void MusicPlayerController::setDateStatusBar(const QString &date)
{
    statusBar->setDate(date);
}

void MusicPlayerController::setTimeStatusBar(const QString &time)
{
    statusBar->setTime(time);
}

void MusicPlayerController::saveSetting()
{
    QSettings mySetting("LinhTQ23", "AppMusic");
    mySetting.setValue("currentIndexSong", m_currentIndex);
    mySetting.setValue("position", m_currentSong->currentTime());
    mySetting.setValue("volumn", m_volumn);
    mySetting.setValue("isPause", true);
    mySetting.setValue("random", m_random);
    mySetting.setValue("loop", m_loop);
    LOG_INFO;
}

void MusicPlayerController::iniSetting()
{
    QSettings mySetting("LinhTQ23", "AppMusic");
    int index = mySetting.value("currentIndexSong").toInt();
    m_currentIndex = index;

    int position = mySetting.value("position").toInt();
    m_currentSong->setCurrentTime(position);
    qDebug() << "setting" << position;

    float volumn = mySetting.value("volumn").toFloat();
    qDebug() << "volume" << volumn;
    setVolumn(volumn);

    bool random = mySetting.value("random").toBool();
    qDebug() << "random" << random;
    setRandom(random);

    bool loop = mySetting.value("loop").toBool();
    qDebug() << "loop" << loop;
    setLoop(loop);

    bool isPause = mySetting.value("isPause").toBool();
    setPause(isPause);
    qDebug() << isPause;
}

bool MusicPlayerController::pause() const
{
    return m_pause;
}

void MusicPlayerController::setPause(bool newPause)
{
    if (m_pause == newPause)
        return;
    m_pause = newPause;
    emit pauseChanged();
}

void MusicPlayerController::registerStatusBar(QQmlEngine *engine)
{
    statusBar->registerObject(engine);
}


MusicPlaybackModel *MusicPlayerController::currentSong() const
{
    return m_currentSong;
}

void MusicPlayerController::setCurrentSong(MusicPlaybackModel *newCurrentSong)
{
    if (m_currentSong == newCurrentSong)
        return;
    m_currentSong = newCurrentSong;
    emit currentSongChanged();

}

int MusicPlayerController::curentIndex() const
{
    return m_currentIndex;
}

void MusicPlayerController::setCurrentIndex(int newCurrentIndex)
{
    if (m_currentIndex == newCurrentIndex)
        return;
    m_currentIndex = newCurrentIndex;
    emit currentIndexChanged();
}

bool MusicPlayerController::random() const
{
    return m_random;
}

void MusicPlayerController::setRandom(bool newRadom)
{
    if (m_random == newRadom)
        return;
    m_random = newRadom;
    emit radomChanged();
}

bool MusicPlayerController::loop() const
{
    return m_loop;
}

void MusicPlayerController::setLoop(bool newLoop)
{
    if (m_loop == newLoop)
        return;
    m_loop = newLoop;
    emit loopChanged();
}

float MusicPlayerController::volumn() const
{
    return m_volumn;
}

void MusicPlayerController::setVolumn(float newVolumn)
{
    if (qFuzzyCompare(m_volumn, newVolumn))
        return;
    m_audio->setVolume(newVolumn);
    m_volumn = newVolumn;
    emit volumnChanged();
}
