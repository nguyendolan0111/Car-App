#ifndef DBUSHANDLER_H
#define DBUSHANDLER_H

#include <QObject>
#include "fvideo.h"
#include "fsetting.h"
#include "fmusic.h"

struct HomeHMIInfor
{
    HomeHMIInfor() {}
    QString ServiceInterface = "";
    QString ServiceName = "";
    QString Path = "";
};

class DbusHandler : public QObject, public IFVideoServiceListener,
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

    //hiển thị app Home
    void onReturnHome();

    //Check App Video Run
    void onRunAppVideo();

    //Check App Setting Run
    void onRunAppSetting();

    //check App Music Run
    void onRunAppMusic();

signals:
    void returnHome();
    void inforVideoChanged(const QString& infor);
    void inforMusicChanged(const QString &infor);
    void currentLanguage(const QString &idLanguage);
    void dateTimeChangedSetting(const QString &time, const QString &date);

    // IFVideoServiceListener interface
public slots:
    void inforVideo(const QString& infor) override;
    void requestPauseVideo(bool isPause) override;


    // IFSettingServiceListener interface
public slots:
    void volumeChanged(const int &volume) override;
    void languageChanged(const QString &idLanguage) override;
    void dateTimeChanged(const QString &time, const QString &date) override;


    // IFMusicServiceListener interface
public slots:
    void inforMusic(const QString &infor) override;
    void requestPauseMusic(bool isPause) override;

private:
    QString m_serviceName;
    QString m_pathName;
    QString m_interface;
    QList<HomeHMIInfor> m_listListener;

};

#endif // DBUSHANDLER_H
