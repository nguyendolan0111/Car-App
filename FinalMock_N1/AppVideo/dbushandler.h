#ifndef DBUSHANDLER_H
#define DBUSHANDLER_H

#include <QObject>
#include "fhome.h"
#include "fsetting.h"
#include "fmusic.h"

struct VideoHMIInfor
{
    VideoHMIInfor() {}
    QString ServiceInterface = "";
    QString ServiceName = "";
    QString Path = "";
};

class DbusHandler :  public QObject, public IFHomeServiceListener,
                    public IFSettingServiceListener, public IFMusicServiceListener
{
    Q_OBJECT
public:
    explicit DbusHandler(QObject *parent = nullptr);

    void registerDbus();

    void sendMessage(const QString& message);

public slots:
    void onMessageRecevied(QString msg);

    void callMethod(const QString& nameMethod, const QList<QVariant> &listParam);

    //Check App Home Run
    void onRunAppHome();

    //Check App Setting Run
    void onRunAppSetting();

    //Check App Music Run
    void onRunAppMusic();

    // IFHomeServiceListener interface
public slots:
    void onOpenApp(int app) override;


    // IFSettingServiceListener interface
public slots:
    void volumeChanged(const int &volume) override;
    void languageChanged(const QString &idLanguage) override;
    void dateTimeChanged(const QString &time, const QString &date) override;

    // IFMusicServiceListener interface
public slots:
    void inforMusic(const QString &infor) override;
    void requestPauseMusic(bool isPause) override;


signals:
    //kết nối với app home
    void openApp(int app);

    //changed Volume
    void volumeChangedSetting(int volume);

    //pause App Music
    void pauseApp(bool isPause);

    //changed Language
    void currentLanguage(const QString &idLanguage);

    //changed DateTIme
    void dateTimeChangedSetting(QString time, QString date);

private:
    QString m_serviceName;
    QString m_pathName;
    QString m_interface;
    QList<VideoHMIInfor> m_listListener;

};

#endif // DBUSHANDLER_H
