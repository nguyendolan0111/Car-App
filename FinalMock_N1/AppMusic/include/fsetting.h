#ifndef FSETTING_H
#define FSETTING_H

#include <QtCore/qglobal.h>
#include <QObject>

#if defined(FSETTING_LIBRARY)
#define FSETTING_EXPORT Q_DECL_EXPORT
#else
#define FSETTING_EXPORT Q_DECL_IMPORT
#endif


class IFSettingServiceListener {

public:
    virtual void volumeChanged(const int& volume) = 0;
    virtual void languageChanged(const QString& idLanguage) = 0;
    virtual void dateTimeChanged(const QString& time, const QString& date) = 0;
};


class FSETTING_EXPORT FSetting : public QObject
{
public:
    FSetting();

    void setListener(IFSettingServiceListener * objListener, QString serviceName, QString pathName, QString interface);

    static FSetting* getInstane();

    void onRunAppHome();
};

#endif // FSETTING_H
