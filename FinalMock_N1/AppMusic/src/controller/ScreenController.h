#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

#include <QObject>
#include <QQmlContext>
#include "src/model/ScreenModel.h"
#include <QQmlApplicationEngine>
#include <QStack>
class ScreenController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isShowApp READ getIsShowApp WRITE setIsShowApp NOTIFY isShowAppChanged FINAL)
private:
    explicit ScreenController(QObject *parent = nullptr);
public:
    ~ScreenController();
    static ScreenController *getInstance();


    void initialize(QQmlContext *context);
    void initializeScreen(QQmlApplicationEngine *engine);
    void popToRoot();
    bool getIsShowApp() const;
    void setIsShowApp(bool newIsShowApp);

signals:

    void isShowAppChanged();
    void runAppMusic();
public slots:
    void pushScreen(int screenId);
    void popScreen();
    void reloadScreen();

    void onReturnHome();

private:
    static ScreenController *m_instance;
    bool m_initialize;
    ScreenModel m_model;
    QStack<int> m_screenStack;
    QQmlApplicationEngine *m_engine;
    bool isShowApp;

};

#endif // SCREENCONTROLLER_H
