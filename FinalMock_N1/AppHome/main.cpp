#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "mycontroller.h"
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

    MyController MyController;
    MyController.registerStatusBar(&engine);
    engine.rootContext()->setContextProperty("MyController", &MyController);

    Translation myTranslation(&app);
    engine.rootContext()->setContextProperty("MyTranslation", &myTranslation);

    QObject::connect(&MyController, &MyController::currentLanguageChanged, &myTranslation, &Translation::changeLanguage);
    QObject::connect(&myTranslation, &Translation::entryStringChanged, &engine, &QQmlApplicationEngine::retranslate);

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

    emit MyController.runAppHome();

    std::signal(SIGSEGV, &signalEvent);
    std::signal(SIGINT, &signalEvent);
    std::signal(SIGABRT, &signalEvent);
    std::signal(SIGFPE, &signalEvent);
    std::signal(SIGILL, &signalEvent);
    std::signal(SIGTERM, &signalEvent);

    return app.exec();
}
