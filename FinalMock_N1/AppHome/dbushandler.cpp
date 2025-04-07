#include "dbushandler.h"
#include <QDebug>
#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusReply>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonObject>

DbusHandler::DbusHandler(QObject *parent)
{
    m_serviceName = "AppHome.service";
    m_pathName = "/AppHome";
    m_interface = "com.AppHome";
}

void DbusHandler::registerDbus()
{
    QDBusConnection connection = QDBusConnection::sessionBus();
    if(!connection.isConnected()){
        qDebug() << "Cannot connnect to session bus App Home";
        return;
    }

    //đăng ký dịch vụ dbus
    qDebug() << "Register Service Home: " << connection.registerService(m_serviceName);

    //đăng ký đối tượng với dbus
    qDebug() << "Register Object Home: " << connection.registerObject(m_pathName,  //path
                                                                      m_interface, //interface
                                                                      this,
                                                                      QDBusConnection::ExportAllSlots);

    // //đăng ký lắng nghe Video
    FVideo::getInstane()->setListener(this, m_serviceName, m_pathName, m_interface);

    // //đăng ký lắng nghe Setting
    FSetting::getInstane()->setListener(this, m_serviceName, m_pathName, m_interface);

    // //đăng ký lắng nghe Music
    FMusic::getInstane()->setListener(this, m_serviceName, m_pathName, m_interface);
}

void DbusHandler::onMessageRecevied(QString msg)
{
    qDebug() << "service msg: " << msg;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(msg.toUtf8());
    QString msgID = jsonDoc.object().value("msg").toString();
    QJsonObject jsonObj = jsonDoc.object().value("data").toObject();
    if(msgID == "addNew")
    {
        HomeHMIInfor newHMIApp;
        newHMIApp.ServiceName = jsonObj.value("ServiceName").toString();
        newHMIApp.ServiceInterface = jsonObj.value("ServiceInterface").toString();
        newHMIApp.Path = jsonObj.value("Path").toString();

        m_listListener.append(newHMIApp);
    }
}

void DbusHandler::sendMessage(const QString &message)
{
    callMethod("onMessageRecevied", {message});
}

void DbusHandler::callMethod(const QString &nameMethod, const QList<QVariant> &listParam)
{

    foreach (HomeHMIInfor appInfor, m_listListener) {
        qDebug() << "";
        qDebug() << appInfor.ServiceName;
        qDebug() << appInfor.ServiceInterface;
        qDebug() << appInfor.Path;

        QDBusMessage message = QDBusMessage::createMethodCall(
            appInfor.ServiceName,
            appInfor.Path,                 // Đường dẫn đối tượng
            appInfor.ServiceInterface,    // Interface chứa phương thức
            nameMethod                   // Tên phương thức
            );

        foreach (QVariant var, listParam) {
            message << var.toInt();
        }

        qDebug() << message;

        QDBusReply<void> reply = QDBusConnection::sessionBus().call(message, QDBus::NoBlock);
        qDebug() << "end call";

        if (!reply.isValid()) {
            qDebug() << "Error:" << reply.error().message();
        }
    }
}

void DbusHandler::onReturnHome()
{
    emit returnHome();
}

void DbusHandler::onRunAppVideo()
{
    qDebug() << "onRunAppVideo";
    FVideo::getInstane()->setListener(this, m_serviceName, m_pathName, m_interface);
}

void DbusHandler::onRunAppSetting()
{
    qDebug() << "onRunAppSetting";
    FSetting::getInstane()->setListener(this, m_serviceName, m_pathName, m_interface);
}

void DbusHandler::onRunAppMusic()
{
    qDebug() << "onRunAppMusic";
    FMusic::getInstane()->setListener(this, m_serviceName, m_pathName, m_interface);
}

void DbusHandler::requestPauseVideo(bool isPause)
{
    qDebug() << "App Home Handle Request Pause Video: " << isPause;
}

void DbusHandler::volumeChanged(const int &volume)
{
    qDebug() << float(float(volume)/10.0);
}

void DbusHandler::languageChanged(const QString &idLanguage)
{
    qDebug() << idLanguage;
    emit currentLanguage(idLanguage);
}

void DbusHandler::dateTimeChanged(const QString &time, const QString &date)
{
    qDebug() << time << " " << date;
    emit dateTimeChangedSetting(time, date);
}

void DbusHandler::inforVideo(const QString& infor)
{
    emit inforVideoChanged(infor);
}

void DbusHandler::inforMusic(const QString &infor)
{
    emit inforMusicChanged(infor);
}

void DbusHandler::requestPauseMusic(bool isPause)
{
    qDebug() << "requestPauseMusic" << isPause;
}



