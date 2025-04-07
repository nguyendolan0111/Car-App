#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTimer>
#include "videocontroller.h"
#include "Translation.h"
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

    VideoController* videoController = new VideoController();
    engine.rootContext()->setContextProperty("videoController", videoController);
    videoController->registerStatusBar(&engine);

    Translation myTranslation(&app);
    engine.rootContext()->setContextProperty("MyTranslation", &myTranslation);
    QObject::connect(videoController, &VideoController::currentLanguageChanged, &myTranslation, &Translation::changeLanguage);
    QObject::connect(&myTranslation, &Translation::entryStringChanged, &engine, &QQmlApplicationEngine::retranslate);

    QQmlEngine::setObjectOwnership(videoController, QQmlEngine::CppOwnership);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    emit videoController->runAppVideo();

    QTimer::singleShot(1, [&videoController]() {
        emit videoController->sourceMediaChanged();
        emit videoController->setInforVideo();
    });

    std::signal(SIGSEGV, &signalEvent);
    std::signal(SIGINT, &signalEvent);
    std::signal(SIGABRT, &signalEvent);
    std::signal(SIGFPE, &signalEvent);
    std::signal(SIGILL, &signalEvent);
    std::signal(SIGTERM, &signalEvent);

    return app.exec();
}
