#include "statusbar_plugin.h"
#include "QQmlContext"
#include <QUrl>
MyPlugin::MyPlugin() {}

void MyPlugin::registerObject(QQmlEngine *engine)
{
    if (engine) {
        engine->rootContext()->setContextProperty("MyStatusTime", this);
    }
    qmlRegisterType(QUrl("qrc:/MyStatusBar.qml"), "MyStatusBarPlugin", 1, 0, "MyStatusBar");
}

QString MyPlugin::time() const
{
    return m_time;
}

void MyPlugin::setTime(const QString &newTime)
{
    if (m_time == newTime)
        return;
    m_time = newTime;
    emit timeChanged();
}

QString MyPlugin::date() const
{
    return m_date;
}

void MyPlugin::setDate(const QString &newDate)
{
    if (m_date == newDate)
        return;
    m_date = newDate;
    emit dateChanged();
}

