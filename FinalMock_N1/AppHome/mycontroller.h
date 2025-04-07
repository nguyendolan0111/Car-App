#ifndef MYCONTROLLER_H
#define MYCONTROLLER_H

#include <QObject>
#include "mymodelhomeapp.h"
#include "dbushandler.h"
#include "StatusBar_Interface.h"

class MyController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(MyModelHomeApp *myModelApp READ myModelApp WRITE setMyModelApp NOTIFY myModelAppChanged FINAL)
    Q_PROPERTY(bool showApp READ showApp WRITE setShowApp NOTIFY showAppChanged FINAL)

public:
    explicit MyController(QObject *parent = nullptr);
    ~MyController();

    MyModelHomeApp *myModelApp() const;
    void setMyModelApp(MyModelHomeApp *newMyModelApp);

    bool showApp() const;
    void setShowApp(bool newShowApp);

    void loadSetting();

    void saveSetting();

    void registerStatusBar(QQmlEngine* engine);

public slots:
    void callApp(int idApp);

    void onReturnHome();

    void setDateStatusBar(const QString &date);
    void setTimeStatusBar(const QString &time);

signals:
    void myModelAppChanged();

    void showAppChanged();

    void inforVideoChanged();

    void inforMusicChanged();

    void runAppHome();

    void currentLanguageChanged(const QString& idLang);

public slots:
    void onInforVideoChanged(const QString& infor);
    void onInforMusicChanged(const QString& infor);

private:
    MyModelHomeApp* m_myModelApp;
    DbusHandler *m_dBusHandler;
    bool m_showApp;
    MyStatusBarInterface* statusBar;
};

#endif // MYCONTROLLER_H
