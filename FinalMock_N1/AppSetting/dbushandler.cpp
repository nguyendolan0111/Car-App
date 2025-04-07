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
    m_serviceName = "AppSetting.service";
    m_pathName = "/AppSetting";
    m_interface = "com.AppSetting";
}

void DbusHandler::registerDbus()
{
    QDBusConnection connection = QDBusConnection::sessionBus();
    if(!connection.isConnected()){
        qDebug() << "Cannot connnect to session bus App Setting";
        return;
    }

    //đăng ký dịch vụ dbus
    qDebug() << "Register Service Setting: " << connection.registerService(m_serviceName);

    //đăng ký đối tượng với dbus
    qDebug() << "Register Object Setting: " << connection.registerObject(m_pathName,  //path
                                                                         m_interface, //interface
                                                                         this,
                                                                         QDBusConnection::ExportAllSlots);

    // //đăng ký lắng nghe Home
    FHome::getInstane()->setListener(this, m_serviceName, m_pathName, m_interface);
}

void DbusHandler::onMessageRecevied(QString msg)
{
    qDebug() << "service msg: " << msg;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(msg.toUtf8());
    QString msgID = jsonDoc.object().value("msg").toString();
    QJsonObject jsonObj = jsonDoc.object().value("data").toObject();
    if(msgID == "addNew")
    {
        SettingHMIInfor newHMIApp;
        newHMIApp.ServiceName = jsonObj.value("ServiceName").toString();
        newHMIApp.ServiceInterface = jsonObj.value("ServiceInterface").toString();
        newHMIApp.Path = jsonObj.value("Path").toString();

        qDebug() << newHMIApp.ServiceName;
        qDebug() << newHMIApp.ServiceInterface;
        qDebug() << newHMIApp.Path;

        m_listListener.append(newHMIApp);
    }
}

void DbusHandler::sendMessage(const QString &message)
{
    callMethod("onMessageRecevied", {message});
}

void DbusHandler::callMethod(const QString &nameMethod, const QList<QVariant> &listParam)
{
    foreach (SettingHMIInfor appInfor, m_listListener) {
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

void DbusHandler::onRunAppHome()
{
    qDebug() << "onRunAppHome";
    FHome::getInstane()->setListener(this, m_serviceName, m_pathName, m_interface);
}

//slots để mở app Setting
void DbusHandler::onOpenApp(int app){
        qDebug() << "afasdfasdfasdfasdfads" << app;
    emit openApp(app);
}
