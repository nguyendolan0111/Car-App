#include "MusicDbusHandler.h"
#include "src/common/loghelper.h"
#include "MusicPlayerController.h"
#include "ScreenController.h"
MusicDbusHandler* MusicDbusHandler::m_instance = nullptr;
MusicDbusHandler::MusicDbusHandler(QObject *parent)
    :QObject{parent}
{
    m_service = "AppMusic.service";
    m_path = "/AppMusic";
    m_interface = "com.AppMusic";
    registerDbus();
    QObject::connect(MusicPlayerController::getInstance(), &MusicPlayerController::currentSongChanged, this, &MusicDbusHandler::onMusicInfo);
    QObject::connect(this, &MusicDbusHandler::openApp, this, &MusicDbusHandler::setShowApp);
    QObject::connect(this, &MusicDbusHandler::pauseApp, MusicPlayerController::getInstance(), &MusicPlayerController::onPause);
    connect(this, &MusicDbusHandler::volumeChangedSetting, MusicPlayerController::getInstance(), [&](int volume){
        MusicPlayerController::getInstance()->setVolumn(float(float(volume)/10.0));
    });

    connect(this, &MusicDbusHandler::currentLanguage, MusicPlayerController::getInstance(), &MusicPlayerController::currentLanguageChanged);
    connect(this, &MusicDbusHandler::dateTimeChangedSetting, MusicPlayerController::getInstance(), [&](QString time, QString date){
        MusicPlayerController::getInstance()->setTimeStatusBar(time);
        MusicPlayerController::getInstance()->setDateStatusBar(date);
    });
}

void MusicDbusHandler::registerDbus()
{
    QDBusConnection connection = QDBusConnection::sessionBus();
    connection.registerService(m_service);
    connection.registerObject(m_path, m_interface, this, QDBusConnection::ExportAllSlots);

    qDebug() << "registerDbus";
    FHome::getInstane()->setListener(this, m_service, m_path, m_interface);
    FVideo::getInstane()->setListener(this, m_service, m_path, m_interface);
    FSetting::getInstane()->setListener(this, m_service, m_path, m_interface);
}

void MusicDbusHandler::sendMessage(const QString &signalName, QString msg)
{
    foreach (MusicHMIInfo musicHMi, listHMIListener) {
        QDBusMessage signal = QDBusMessage::createSignal(musicHMi.Path, musicHMi.ServiceInterface, signalName);
        signal << msg;
        qDebug() << "send message" << QDBusConnection::sessionBus().send(signal);
    }
}

void MusicDbusHandler::callMethod(const QString &nameMethod, const QList<QVariant> &listParam)
{
    foreach (MusicHMIInfo appInfor, listHMIListener) {
        qDebug() << "";
        qDebug() << appInfor.ServiceName;
        qDebug() << appInfor.ServiceInterface;
        qDebug() << appInfor.Path;

        QDBusMessage message = QDBusMessage::createMethodCall(
            appInfor.ServiceName,
            appInfor.Path,                // Đường dẫn đối tượng
            appInfor.ServiceInterface,    // Interface chứa phương thức
            nameMethod                   // Tên phương thức
            );

        foreach (QVariant var, listParam) {
            message << var;
        }

        qDebug() << message;

        QDBusReply<void> reply = QDBusConnection::sessionBus().call(message, QDBus::NoBlock);
        qDebug() << "end call";

        if (!reply.isValid()) {
            qDebug() << "Error:" << reply.error().message();
        }
    }
}

MusicDbusHandler *MusicDbusHandler::getInstance()
{
    if (m_instance == nullptr){
        m_instance = new MusicDbusHandler();
    }
    return m_instance;
}

void MusicDbusHandler::onMessageRecevied(QString msg)
{
    qDebug() << "service msg: " << msg;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(msg.toUtf8());
    QString msgID = jsonDoc.object().value("msg").toString();
    QJsonObject jsonObj = jsonDoc.object().value("data").toObject();
    if(msgID == "addNew")
    {
        MusicHMIInfo newHMIApp;
        newHMIApp.ServiceName = jsonObj.value("ServiceName").toString();
        newHMIApp.ServiceInterface = jsonObj.value("ServiceInterface").toString();
        newHMIApp.Path = jsonObj.value("Path").toString();

        qDebug() << newHMIApp.ServiceName;
        qDebug() << newHMIApp.ServiceInterface;
        qDebug() << newHMIApp.Path;

        listHMIListener.append(newHMIApp);
    }
}

void MusicDbusHandler::setShowApp(int idApp)
{
    if (idApp == 0) {
        ScreenController::getInstance()->setIsShowApp(true);
    }
}

void MusicDbusHandler::onMusicInfo()
{
    LOG_INFO;
    QString titleName = MusicPlayerController::getInstance()->currentSong()->currentSongTitle();
    QString artistName = MusicPlayerController::getInstance()->currentSong()->currentArtistName();
    QString coverArt = MusicPlayerController::getInstance()->currentSong()->coverArt();
    QMediaPlayer::PlaybackState status = MusicPlayerController::getInstance()->currentSong()->status();
    QJsonObject jsonObj;
    QJsonObject subObj;
    subObj.insert("Status", status);
    subObj.insert("Title", titleName);
    subObj.insert("Artist", artistName);
    subObj.insert("CoverArt", coverArt);
    jsonObj.insert("data", subObj);
    sendMessage("MusicInfoSignal", QString(QJsonDocument(jsonObj).toJson(QJsonDocument::Compact)));
}

void MusicDbusHandler::onRunAppHome()
{
    qDebug() << "onRunAppHome";
    FHome::getInstane()->setListener(this, m_service, m_path, m_interface);
}

void MusicDbusHandler::onRunAppVideo()
{
    FVideo::getInstane()->setListener(this, m_service, m_path, m_interface);
}

void MusicDbusHandler::onRunAppSetting()
{
    FSetting::getInstane()->setListener(this, m_service, m_path, m_interface);
}

void MusicDbusHandler::onOpenApp(int app)
{
    emit openApp(app);
}

void MusicDbusHandler::requestPauseVideo(bool isPause)
{
    emit pauseApp(isPause);
}

void MusicDbusHandler::inforVideo(const QString &infor)
{
    qDebug() << infor;
}

void MusicDbusHandler::volumeChanged(const int &volume)
{
    qDebug() << volume;
    volumeChangedSetting(volume);
}

void MusicDbusHandler::languageChanged(const QString &idLanguage)
{
    qDebug() << idLanguage;
    emit currentLanguage(idLanguage);
}

void MusicDbusHandler::dateTimeChanged(const QString &time, const QString &date)
{
    emit dateTimeChangedSetting(time, date);
}
