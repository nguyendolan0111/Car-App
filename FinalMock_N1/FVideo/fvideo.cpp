#include "fvideo.h"
#include <QDebug>

#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusReply>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

FVideo::FVideo() {}

void FVideo::setListener(IFVideoServiceListener *objListener, QString serviceName, QString pathName, QString interface)
{
    if(objListener){
        // Tạo một QDBusMessage để gọi phương thức với tham số
        QDBusMessage message = QDBusMessage::createMethodCall(
            "AppVideo.service",
            "/AppVideo",                    // Đường dẫn đối tượng
            "com.AppVideo",                  // Interface chứa phương thức
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

FVideo *FVideo::getInstane()
{
    static FVideo *m_instance = new FVideo();

    return m_instance;
}

void FVideo::onRunAppHome()
{
    QDBusMessage message = QDBusMessage::createMethodCall(
        "AppVideo.service",
        "/AppVideo",                    // Đường dẫn đối tượng
        "com.AppVideo",// Interface chứa phương thức
        "onRunAppHome"                 // Tên phương thức bạn muốn gọi
        );
    QDBusConnection::sessionBus().call(message, QDBus::NoBlock);
}

void FVideo::onRunAppMusic()
{
    QDBusMessage message = QDBusMessage::createMethodCall(
        "AppVideo.service",
        "/AppVideo",                    // Đường dẫn đối tượng
        "com.AppVideo",// Interface chứa phương thức
        "onRunAppMusic"                 // Tên phương thức bạn muốn gọi
        );
    QDBusConnection::sessionBus().call(message, QDBus::NoBlock);
}

void FVideo::onRunAppSetting()
{
    QDBusMessage message = QDBusMessage::createMethodCall(
        "AppVideo.service",
        "/AppVideo",                    // Đường dẫn đối tượng
        "com.AppVideo",// Interface chứa phương thức
        "onRunAppSetting"                 // Tên phương thức bạn muốn gọi
        );
    QDBusConnection::sessionBus().call(message, QDBus::NoBlock);
}
