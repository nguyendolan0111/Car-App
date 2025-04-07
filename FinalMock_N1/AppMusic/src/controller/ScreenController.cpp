#include "ScreenController.h"
#include "src/common/appdefines.h"
#include "src/common/loghelper.h"
#include "fhome.h"
#include "fvideo.h"
ScreenController* ScreenController::m_instance = nullptr;

ScreenController::ScreenController(QObject *parent)
    : QObject{parent}, m_initialize(false), m_engine(nullptr), isShowApp(false)
{
    QObject::connect(this, &ScreenController::runAppMusic, [](){
        qDebug() << "runAppMusic";
        FHome::getInstane()->onRunAppMusic();
        FVideo::getInstane()->onRunAppMusic();
    });
}

ScreenController::~ScreenController()
{

}

ScreenController *ScreenController::getInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new ScreenController();
    }
    return m_instance;
}

void ScreenController::initialize(QQmlContext *context)
{
    LOG_INFO << m_initialize;
    if (!m_initialize) {
        m_initialize = true;
        context->setContextProperty("SCREEN_CTRL", this);
        context->setContextProperty("SCREEN_MODEL", &m_model);
    }
}

void ScreenController::initializeScreen(QQmlApplicationEngine *engine)
{
    LOG_INFO;
    if (m_engine == nullptr)
    {
        m_engine = engine;
        m_engine->load(QUrl(QStringLiteral(MAIN_QML)));
        emit runAppMusic();
        pushScreen(AppEnums::SCREEN_ID_MUSIC_PLAYER);
    }
}

void ScreenController::pushScreen(int screenId)
{
    LOG_INFO << screenId;
    m_screenStack.push(screenId);
    reloadScreen();
}

void ScreenController::popScreen()
{
    LOG_INFO << m_screenStack.count();
    if (m_screenStack.count() >1) {
        m_screenStack.pop();
        reloadScreen();
    }
}

void ScreenController::popToRoot()
{
    LOG_INFO << m_screenStack.count();
    while (m_screenStack.count() > 1) {
        m_screenStack.pop();
    }
    reloadScreen();
}

void ScreenController::reloadScreen()
{
    if (!m_screenStack.isEmpty())
    {
        QString screenName = ScreenNameMap.value(m_screenStack.top());
        m_model.setCurrentScreen(screenName);
        if ((m_engine != nullptr) && (m_engine->rootObjects().count() >0)) {
            QMetaObject::invokeMethod(m_engine->rootObjects().at(0),"reloadScreen", QVariant::fromValue(screenName));
        }
    }
}

bool ScreenController::getIsShowApp() const
{
    return isShowApp;
}

void ScreenController::setIsShowApp(bool newIsShowApp)
{
    if (isShowApp == newIsShowApp)
        return;
    isShowApp = newIsShowApp;
    emit isShowAppChanged();
}

void ScreenController::onReturnHome()
{
    setIsShowApp(false);
    FHome::getInstane()->returnHome();
}
