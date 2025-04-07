#ifndef MUSICDBUSHANDLER_H
#define MUSICDBUSHANDLER_H
#include <QObject>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusMessage>
#include <QtDBus/QDBusReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include "fhome.h"
#include "fvideo.h"
#include "fsetting.h"


struct MusicHMIInfo
{
    MusicHMIInfo() {}
    QString ServiceInterface = "";
    QString ServiceName = "";
    QString Path = "";
};


class MusicDbusHandler : public QObject, public IFHomeServiceListener,
                         public IFVideoServiceListener, public IFSettingServiceListener
{
    Q_OBJECT

private:
    explicit MusicDbusHandler(QObject *parent = nullptr);


public:
    void registerDbus();
    void sendMessage(const QString &signalName, QString msg);
    void callMethod(const QString &nameMethod, const QList<QVariant> &listParam);
    static MusicDbusHandler* getInstance();

public slots:
    void onMessageRecevied(QString msg);
    void setShowApp(int idApp);
    void onMusicInfo();
    void onRunAppHome();
    void onRunAppVideo();
    void onRunAppSetting();


    // IFHomeServiceListener interface
public slots:
    void onOpenApp(int app) override;

    // IFVideoServiceListener interface
public slots:
    void requestPauseVideo(bool isPause) override;
    void inforVideo(const QString &infor) override;

    // IFSettingServiceListener interface
public slots:
    void volumeChanged(const int &volume) override;
    void languageChanged(const QString &idLanguage) override;
    void dateTimeChanged(const QString &time, const QString &date) override;

signals:
    void openApp(int app);
    void pauseApp(bool isPause);
    void volumeChangedSetting(int volume);
    void currentLanguage(const QString &idLanguage);

    void dateTimeChangedSetting(const QString &time, const QString &date);

private:
    static MusicDbusHandler* m_instance;
    QString m_service;
    QString m_path;
    QString m_interface;
    QList<MusicHMIInfo> listHMIListener;

};

#endif // MUSICDBUSHANDLER_H
