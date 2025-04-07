#include "fsetting.h"
#include <QDebug>

#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusReply>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>


FSetting::FSetting() {}

void FSetting::setListener(IFSettingServiceListener *objListener, QString serviceName, QString pathName, QString interface)
{
    if(objListener)
    {
        // Tạo một QDBusMessage để gọi phương thức với tham số
        QDBusMessage message = QDBusMessage::createMethodCall(
            "AppSetting.service",
            "/AppSetting",                    // Đường dẫn đối tượng
            "com.AppSetting",                  // Interface chứa phương thức
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

FSetting *FSetting::getInstane()
{
    static FSetting *m_instance = new FSetting();

    return m_instance;
}

void FSetting::onRunAppHome()
{
    QDBusMessage message = QDBusMessage::createMethodCall(
        "AppSetting.service",
        "/AppSetting",                    // Đường dẫn đối tượng
        "com.AppSetting",// Interface chứa phương thức
        "onRunAppHome"                 // Tên phương thức bạn muốn gọi
        );
    QDBusConnection::sessionBus().call(message, QDBus::NoBlock);
}
