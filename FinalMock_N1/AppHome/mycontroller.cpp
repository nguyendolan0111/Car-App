#include "mycontroller.h"
#include "fvideo.h"
#include <QSettings>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDir>
#include <QPluginLoader>

MyController::MyController(QObject *parent)
    : QObject{parent}
{
    setShowApp(true);
    m_myModelApp = new MyModelHomeApp();
    m_dBusHandler = new DbusHandler(this);
    m_dBusHandler->registerDbus();
    connect(m_dBusHandler, &DbusHandler::returnHome, this, &MyController::onReturnHome);
    connect(m_dBusHandler, &DbusHandler::inforVideoChanged, this, &MyController::onInforVideoChanged);
    connect(m_dBusHandler, &DbusHandler::inforMusicChanged, this, &MyController::onInforMusicChanged);
    connect(m_dBusHandler, &DbusHandler::currentLanguage, this, &MyController::currentLanguageChanged);

    connect(m_dBusHandler, &DbusHandler::dateTimeChangedSetting, this, [&](QString time, QString date){
        setDateStatusBar(date);
        setTimeStatusBar(time);
    });

    connect(this, &MyController::runAppHome, this, [](){
        qDebug() << "lambda Home Run";
        FVideo::getInstane()->onRunAppHome();
        FSetting::getInstane()->onRunAppHome();
        FMusic::getInstane()->onRunAppHome();
    });

    QDir pluginDir("/home/vtwo/FinalMock_N1/AppHome/plugin");
    foreach (QString fileName, pluginDir.entryList(QDir::Files)) {
        QPluginLoader loader(pluginDir.absoluteFilePath(fileName));
        QObject *plugin = loader.instance();
        if (plugin) {
            QString pluginName = plugin->metaObject()->className();
            if (pluginName == "MyPlugin") {
                statusBar= qobject_cast<MyStatusBarInterface*>(plugin);
                if (statusBar) {
                    qDebug() << "Dont create StatusBarInterface";
                }
            }
        }
    }

    loadSetting();
}

MyController::~MyController()
{
    qDebug() <<  "HUy HOme";
    saveSetting();
}

MyModelHomeApp *MyController::myModelApp() const
{
    return m_myModelApp;
}

void MyController::setMyModelApp(MyModelHomeApp *newMyModelApp)
{
    if (m_myModelApp == newMyModelApp)
        return;
    m_myModelApp = newMyModelApp;
    emit myModelAppChanged();
}

void MyController::callApp(int idApp)
{
    m_dBusHandler->callMethod("onOpenApp", {idApp});
    setShowApp(false);
}

void MyController::onReturnHome()
{
    setShowApp(true);
}


void MyController::setDateStatusBar(const QString &date)
{
    statusBar->setDate(date);
}

void MyController::setTimeStatusBar(const QString &time)
{
    statusBar->setTime(time);
}


void MyController::onInforVideoChanged(const QString& infor)
{
    qDebug() << infor;
    m_myModelApp->changeInforVideo(infor);
    emit inforVideoChanged();
    saveSetting();
}

void MyController::onInforMusicChanged(const QString &infor)
{
    qDebug() << infor;
    m_myModelApp->changeInforMusic(infor);
    emit inforMusicChanged();
    saveSetting();
}

bool MyController::showApp() const
{
    return m_showApp;
}

void MyController::setShowApp(bool newShowApp)
{
    if (m_showApp == newShowApp)
        return;
    m_showApp = newShowApp;
    emit showAppChanged();
}

void MyController::registerStatusBar(QQmlEngine *engine)
{
    statusBar->registerObject(engine);
}

void MyController::loadSetting()
{
    QSettings settings("VUNV29", "AppHome");

    QString title = settings.value("MusicTop", "Unknown").toString();
    QString artistName = settings.value("MusicBottom", "Unknown").toString();
    QString coverArt = settings.value("MusicImage", "Unknown").toString();
    QJsonObject jsonObj;
    QJsonObject subObj;
    subObj.insert("Title", title);
    subObj.insert("Artist", artistName);
    subObj.insert("CoverArt", coverArt);
    subObj.insert("Status", "Unknown");
    jsonObj.insert("msg", "MusicInfo");
    jsonObj.insert("data", subObj);
    QString mess = QString(QJsonDocument(jsonObj).toJson(QJsonDocument::Compact));

    m_myModelApp->changeInforMusic(mess);

    m_myModelApp->changeInforVideo(settings.value("VideoTop", "Unknown").toString());
}

void MyController::saveSetting()
{
    QSettings settings = QSettings("VUNV29", "AppHome");

    foreach (const MyHomeApp* app, m_myModelApp->listAppPage1()) {
        qDebug() << "aaaa";
        settings.setValue(app->nameApp() + "Top", app->currentInfor()[0]);
        qDebug() << app->currentInfor()[0];
        settings.setValue(app->nameApp() + "Bottom", app->currentInfor()[1]);
        qDebug() << app->currentInfor()[1];
        settings.setValue(app->nameApp() + "Image", app->imagePath());
        qDebug() << app->imagePath();
    }
}
