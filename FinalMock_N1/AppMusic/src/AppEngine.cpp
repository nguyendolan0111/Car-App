#include "AppEngine.h"
#include "common/appdefines.h"
#include "common/loghelper.h"
#include "controller/MusicPlayerController.h"
#include "controller/ScreenController.h"
#include "controller/MusicDbusHandler.h"
#include <QQmlEngine>
#include "Translation.h"
AppEngine* AppEngine::m_instance = nullptr;
AppEngine::AppEngine(QObject *parent)
    : QObject{parent},m_initialize(false), m_app(nullptr)
{}

AppEngine::~AppEngine()
{

}

AppEngine *AppEngine::getInstance()
{
    if (m_instance == nullptr) {
        m_instance = new AppEngine();
    }
    return m_instance;
}

void AppEngine::initialize(QGuiApplication *app)
{
    LOG_INFO << m_initialize;
    if (!m_initialize) {
        m_initialize = true;
        m_app = app;

        registerQmlObject();
        createController();
        initController();
        initScreen();
    }
}

void AppEngine::registerQmlObject()
{
    LOG_INFO << " => Start";
    qmlRegisterType<AppEnums>("AppEnums", 1, 0, "AppEnums");
    LOG_INFO << " => End";
}

void AppEngine::createController()
{
    ScreenController::getInstance();
    MusicPlayerController::getInstance();
    MusicDbusHandler::getInstance();
}

void AppEngine::initController()
{
    ScreenController::getInstance()->initialize(m_engine.rootContext());
    MusicPlayerController::getInstance()->initialize(m_engine.rootContext());
    MusicPlayerController::getInstance()->registerStatusBar(&m_engine);
    Translation::getIntance(m_app)->initialize(m_engine.rootContext());
}

void AppEngine::initScreen()
{
    ScreenController::getInstance()->initializeScreen(&m_engine);
}
