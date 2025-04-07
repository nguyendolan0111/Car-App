#include "SettingController.h"
#include <QString>
#include <QDebug>
#include <QVariant>
#include "fvideo.h"
#include "fmusic.h"
#include <QSettings>
#include <QDir>
#include <QPluginLoader>

SettingController::SettingController(QObject *parent)
    : QObject(parent), m_showApp(false)
{
    m_dbushandler = new DbusHandler();
    m_dbushandler->registerDbus();

    m_language = new LanguageModel();
    m_time = new TimeSettingModel();
    emit timeChanged();
    m_volume = new VolumeModel();

    connect(m_dbushandler, &DbusHandler::openApp, this, &SettingController::onOpenApp);
    connect(this, &SettingController::runAppSetting, this, [](){
        FHome::getInstane()->onRunAppSetting();
    });

    connect(m_language, &LanguageModel::languageChanged, this, [&](){
        qDebug() << "languageChanged";
        m_dbushandler->callMethod("languageChanged", {QVariant(m_language->currentLanguage())});
    });

    connect(m_volume, &VolumeModel::volumeChanged, this, [&](){
        qDebug() << "volumeChanged";
        m_dbushandler->callMethod("volumeChanged", {m_volume->volume()});
    });

    connect(m_language, &LanguageModel::languageChanged, this, &SettingController::currentLanguageChanged);

    connect(m_time, &TimeSettingModel::inforDateTime, this, [&](QString time, QString date){
        qDebug() << "dateTimeChanged";
        setDateStatusBar(date);
        setTimeStatusBar(time);
        m_dbushandler->callMethod("dateTimeChanged", {time, date});
    });

    connect(m_time, &TimeSettingModel::is24hFormatChanged, this, [&](){
        qDebug() << "isFormat24hChanged";
        m_dbushandler->callMethod("isFormat24hChanged", {QVariant(m_time->is24hFormat())});
    });

    connect(m_time, &TimeSettingModel::secondChanged, this, &SettingController::timeChanged);

    connect(this, &SettingController::runAppSetting, this, [](){
        FHome::getInstane()->onRunAppSetting();
        FMusic::getInstane()->onRunAppSetting();
        FVideo::getInstane()->onRunAppSetting();
    });

    QDir pluginDir("/home/vtwo/FinalMock_N1/AppSetting/plugin");
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

SettingController::~SettingController()
{
    saveSetting();
}

QString SettingController::getCurrentLanguage(){
    return m_language->currentLanguage();
}

void SettingController::setLanguage(QString newLanguage){
    m_language->setCurrentLanguage(newLanguage);
    m_time->setLanguage(newLanguage);
}


void SettingController :: increaseVolume(){
    if(m_volume->volume() < 10){
        m_volume->setVolume(m_volume->volume() + 1);
    }
}

void SettingController::decreaseVolume(){
    if(m_volume->volume() > 0){
        m_volume->setVolume(m_volume->volume() - 1);
    }
}

void SettingController::setCurrentVolume(int newVolume){
    m_volume->setVolume(newVolume);
}

int SettingController::getCurrentVolume() const{
    return m_volume->volume();
}

bool SettingController::is24hFormat() {
    return m_time->is24hFormat();
}

bool SettingController::isCustomFormat() {
    return m_time->isCustomFormat();
}

void SettingController::toggle24hFormat(bool is24h){
    m_time->setIs24hFormat(is24h);
}

void SettingController::toggleCustomFormat(bool isCustom){
    m_time->setIsCustomFormat(isCustom);
}

void SettingController::updateTime(int hour, int minute,int second, int  day, int month, int year){

    m_time->setHour(hour);
    m_time->setMinute(minute);
    m_time->setSecond(second);
    m_time->setDay(day);
    m_time->setMonth(month);
    m_time->setYear(year);
}

int SettingController::getHour(){
    return m_time->hour();
}

void SettingController::setHour(int newHour){
    m_time->setHour(newHour);
}

int SettingController::getMinute(){
    return m_time->minute();
}

void SettingController::setMinute(int newMinute){
    m_time->setMinute(newMinute);
}

int SettingController::getSecond(){
    return m_time->second();
}

void SettingController::setSecond(int newSecond){
    m_time->setSecond(newSecond);
}

int SettingController::getDay(){
    return m_time->day();
}

void SettingController::setDay(int newDay){
    m_time->setDay(newDay);
}

int SettingController::getMonth(){
    return m_time->month();
}

void SettingController::setMonth(int newMonth){
    m_time->setMonth(newMonth);
}

int SettingController::getYear(){
    return m_time->year();
}

void SettingController::setYear(int newYear){
    m_time->setYear(newYear);
}

bool SettingController::showApp() const
{
    return m_showApp;
}

void SettingController::setShowApp(bool newShowApp)
{
    if (m_showApp == newShowApp)
        return;
    m_showApp = newShowApp;
    emit showAppChanged();
}

void SettingController::loadSetting()
{
    QSettings setting("LanLD1", "SettingApp");

    m_language->setCurrentLanguage(setting.value("language", "English").toString());
    m_volume->setVolume(setting.value("volume", 1).toFloat());
    // m_time->setIs24hFormat();
    // m_time->setIsCustomFormat();
}

void SettingController::saveSetting()
{
    QSettings setting = QSettings("LanLD1", "SettingApp");

    setting.setValue("language", m_language->currentLanguage());
    setting.setValue("is24hFormat", m_time->is24hFormat());
    setting.setValue("isCustomFormat", m_time->isCustomFormat());
    setting.setValue("volume", m_volume->volume());
}

void SettingController::registerStatusBar(QQmlEngine *engine)
{
    statusBar->registerObject(engine);
}

void SettingController::onOpenApp(int id)
{
    if(id == 2){
        setShowApp(true);
    }
}

void SettingController::onReturnHome()
{
    setShowApp(false);
    FHome::getInstane()->returnHome();
}

void SettingController::setDateStatusBar(const QString &date)
{
    statusBar->setDate(date);
}

void SettingController::setTimeStatusBar(const QString &time)
{
    statusBar->setTime(time);
}

