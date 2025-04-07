#ifndef DBUSHANDLER_H
#define DBUSHANDLER_H

#include <QObject>
#include "fhome.h"

struct SettingHMIInfor
{
    SettingHMIInfor() {}
    QString ServiceInterface = "";
    QString ServiceName = "";
    QString Path = "";
};


class DbusHandler : public QObject, public IFHomeServiceListener
{
    Q_OBJECT
public:
    explicit DbusHandler(QObject *parent = nullptr);

    void registerDbus();

    void sendMessage(const QString& message);

public slots:
    void onMessageRecevied(QString msg);

    void callMethod(const QString& nameMethod, const QList<QVariant> &listParam);

    //Check App Video Run
    void onRunAppHome();


    // IFHomeServiceListener interface
public slots:
    void onOpenApp(int app) override;


signals:
    //kết nối với app home
    void openApp(int app);

private:
    QString m_serviceName;
    QString m_pathName;
    QString m_interface;
    QList<SettingHMIInfor> m_listListener;
};

#endif // DBUSHANDLER_H
