#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "SettingController.h"
#include "Translation.h"
#include <csignal>

void signalEvent(int signal_num)
{
    qDebug() << signal_num;
    QCoreApplication::exit();
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    SettingController setting;
    engine.rootContext()->setContextProperty("setting",&setting);
    setting.registerStatusBar(&engine);

    Translation myTranslation(&app);
    engine.rootContext()->setContextProperty("MyTranslation", &myTranslation);

    QObject::connect(&setting, &SettingController::currentLanguageChanged, &myTranslation, &Translation::changeLanguage);
    QObject::connect(&myTranslation, &Translation::entryStringChanged, &engine, &QQmlApplicationEngine::retranslate);

    engine.load(url);

    emit setting.runAppSetting();
    myTranslation.changeLanguage(setting.getCurrentLanguage());

    std::signal(SIGSEGV, &signalEvent);
    std::signal(SIGINT, &signalEvent);
    std::signal(SIGABRT, &signalEvent);
    std::signal(SIGFPE, &signalEvent);
    std::signal(SIGILL, &signalEvent);
    std::signal(SIGTERM, &signalEvent);

    return app.exec();
}
