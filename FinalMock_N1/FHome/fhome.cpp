#include "fhome.h"
#include <QDebug>

#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusReply>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

FHome::FHome() {}

void FHome::setListener(IFHomeServiceListener *objListener, QString serviceName, QString pathName, QString interface)
{
    if(objListener)
    {
        // Tạo một QDBusMessage để gọi phương thức với tham số
        QDBusMessage message = QDBusMessage::createMethodCall(
            "AppHome.service",
            "/AppHome",                    // Đường dẫn đối tượng
            "com.AppHome",                  // Interface chứa phương thức
            "onMessageRecevied"              // Tên phương thức bạn muốn gọi
            );

        QJsonObject jsonObj;
        jsonObj.insert("msg", "addNew");

        QJsonObject jsonSubObj;
        jsonSubObj.insert("ServiceName", serviceName);
        jsonSubObj.insert("Path", pathName);
        jsonSubObj.insert("ServiceInterface", interface);

        jsonObj.insert("data", jsonSubObj);

        // Thêm tham số vào message
        message << QString(QJsonDocument(jsonObj).toJson(QJsonDocument::Compact));

        // Gửi tin nhắn và chờ nhận kết quả trả về
        QDBusReply<void> reply = QDBusConnection::sessionBus().call(message);

        // Kiểm tra kết quả trả về
        if (!reply.isValid()) {
            qDebug() << "Error:" << reply.error().message();
        }
    }
}

FHome *FHome::getInstane()
{
    static FHome *m_instance = new FHome();

    return m_instance;
}

void FHome::returnHome()
{
    QDBusMessage message = QDBusMessage::createMethodCall(
        "AppHome.service",
        "/AppHome",                    // Đường dẫn đối tượng
        "com.AppHome",// Interface chứa phương thức
        "onReturnHome"                 // Tên phương thức bạn muốn gọi
        );
    QDBusConnection::sessionBus().call(message);
}

void FHome::onRunAppVideo()
{
    QDBusMessage message = QDBusMessage::createMethodCall(
        "AppHome.service",
        "/AppHome",                    // Đường dẫn đối tượng
        "com.AppHome",// Interface chứa phương thức
        "onRunAppVideo"                 // Tên phương thức bạn muốn gọi
        );
    QDBusConnection::sessionBus().call(message, QDBus::NoBlock);
}

void FHome::onRunAppMusic()
{
    QDBusMessage message = QDBusMessage::createMethodCall(
        "AppHome.service",
        "/AppHome",                    // Đường dẫn đối tượng
        "com.AppHome",// Interface chứa phương thức
        "onRunAppMusic"                 // Tên phương thức bạn muốn gọi
        );
    QDBusConnection::sessionBus().call(message, QDBus::NoBlock);
}

void FHome::onRunAppSetting()
{
    QDBusMessage message = QDBusMessage::createMethodCall(
        "AppHome.service",
        "/AppHome",                    // Đường dẫn đối tượng
        "com.AppHome",// Interface chứa phương thức
        "onRunAppSetting"                 // Tên phương thức bạn muốn gọi
        );
    QDBusConnection::sessionBus().call(message, QDBus::NoBlock);
}
