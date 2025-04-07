#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

class AppEngine : public QObject
{
    Q_OBJECT
private:
    explicit AppEngine(QObject *parent = nullptr);
public:
    ~AppEngine();

    static AppEngine *getInstance();

    void initialize(QGuiApplication *app);
private:
    void registerQmlObject();
    void createController();
    void initController();
    void initScreen();

private:
    static AppEngine* m_instance;
    bool m_initialize;
    QGuiApplication* m_app;
    QQmlApplicationEngine m_engine;
};

#endif // APPENGINE_H
