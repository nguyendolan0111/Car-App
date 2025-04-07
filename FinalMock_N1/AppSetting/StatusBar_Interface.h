#ifndef STATUSBAR_INTERFACE_H
#define STATUSBAR_INTERFACE_H

#include <QQmlComponent>
#include <QQmlEngine>
class MyStatusBarInterface
{
public:
    virtual ~MyStatusBarInterface() {}
    virtual void registerObject(QQmlEngine *engine) = 0;
    virtual void setDate(const QString &newDate) = 0;
    virtual void setTime(const QString &newTime) = 0;
};

#define MyStatusBarInterface_iid "com.mock.MyStatusBarInterface"

Q_DECLARE_INTERFACE(MyStatusBarInterface, MyStatusBarInterface_iid)

#endif // STATUSBAR_INTERFACE_H
