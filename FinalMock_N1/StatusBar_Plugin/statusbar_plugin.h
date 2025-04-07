#ifndef STATUSBAR_PLUGIN_H
#define STATUSBAR_PLUGIN_H

#include "StatusBar_Interface.h"
#include <QObject>
#include <QQmlApplicationEngine>

class MyPlugin : public QObject, public MyStatusBarInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID MyStatusBarInterface_iid)
    Q_INTERFACES(MyStatusBarInterface)
    Q_PROPERTY(QString time READ time WRITE setTime NOTIFY timeChanged FINAL)
    Q_PROPERTY(QString date READ date WRITE setDate NOTIFY dateChanged FINAL)
public:
    MyPlugin();

public:
    void registerObject(QQmlEngine *engine);
    QString date() const;
    void setDate(const QString &newDate) override;
    QString time() const;
    void setTime(const QString &newTime) override;

signals:
    void dateChanged();
    void timeChanged();
private:
    QString m_date;
    QString m_time;
};

#endif // STATUSBAR_PLUGIN_H
