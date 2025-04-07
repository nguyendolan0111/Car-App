#ifndef SETTINGCONTROLLER_H
#define SETTINGCONTROLLER_H

#include <QObject>
#include "TimeSettingModel.h"
#include "VolumeModel.h"
#include "LanguageModel.h"
#include "dbushandler.h"
#include "StatusBar_Interface.h"

class SettingController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool showApp READ showApp WRITE setShowApp NOTIFY showAppChanged FINAL)

public:
    explicit SettingController(QObject *parent = nullptr);

    ~SettingController();

    Q_INVOKABLE QString getCurrentLanguage();
    Q_INVOKABLE void setLanguage(QString newLanguage);
    Q_INVOKABLE void increaseVolume();
    Q_INVOKABLE void decreaseVolume();
    Q_INVOKABLE void setCurrentVolume(int newVolume);
    Q_INVOKABLE int getCurrentVolume() const;
    Q_INVOKABLE bool is24hFormat();
    Q_INVOKABLE bool isCustomFormat();
    Q_INVOKABLE void toggle24hFormat(bool is24h);
    Q_INVOKABLE void toggleCustomFormat(bool isCustom);
    Q_INVOKABLE void updateTime(int hour, int minute, int second, int day, int month, int year);
    Q_INVOKABLE int getHour();
    Q_INVOKABLE void setHour(int hour);
    Q_INVOKABLE int getMinute();
    Q_INVOKABLE void setMinute(int minute);
    Q_INVOKABLE int getSecond();
    Q_INVOKABLE void setSecond(int second);
    Q_INVOKABLE int getDay();
    Q_INVOKABLE void setDay(int day);
    Q_INVOKABLE int getMonth();
    Q_INVOKABLE void setMonth(int month);
    Q_INVOKABLE int getYear();
    Q_INVOKABLE void setYear(int year);

    bool showApp() const;
    void setShowApp(bool newShowApp);

    void loadSetting();

    void saveSetting();

    void registerStatusBar(QQmlEngine* engine);

public slots:
    void onOpenApp(int id);

    void onReturnHome();

    void setDateStatusBar(const QString &date);
    void setTimeStatusBar(const QString &time);

signals:
    void showAppChanged();

    void runAppSetting();

    void timeChanged();

    void currentLanguageChanged(const QString& idLang);

private:
    LanguageModel* m_language;
    VolumeModel* m_volume;
    TimeSettingModel* m_time;
    DbusHandler* m_dbushandler;
    bool m_showApp;
    MyStatusBarInterface* statusBar;
};

#endif // SETTINGCONTROLLER_H
