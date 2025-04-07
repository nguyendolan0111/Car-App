#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>
#include "src/controller/MusicPlayerController.h"
#include "src/AppEngine.h"
#include "src/Translation.h"
#include <csignal>

void signalEvent(int signal_num)
{
    qDebug() << signal_num;
    QCoreApplication::exit();
}

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));

    engine.load(url);
    AppEngine::getInstance()->initialize(&app);
    emit MusicPlayerController::getInstance()->setInforScreen();

    QObject::connect(MusicPlayerController::getInstance(), &MusicPlayerController::currentLanguageChanged, Translation::getIntance(&app), &Translation::changeLanguage);
    QObject::connect(Translation::getIntance(&app), &Translation::entryStringChanged, &engine, &QQmlApplicationEngine::retranslate);
    QObject::connect(&app, &QGuiApplication::aboutToQuit, MusicPlayerController::getInstance(), &MusicPlayerController::saveSetting);

    std::signal(SIGSEGV, &signalEvent);
    std::signal(SIGINT, &signalEvent);
    std::signal(SIGABRT, &signalEvent);
    std::signal(SIGFPE, &signalEvent);
    std::signal(SIGILL, &signalEvent);
    std::signal(SIGTERM, &signalEvent);


    return app.exec();
}
