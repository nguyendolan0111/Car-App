#ifndef FHOME_H
#define FHOME_H

#include <QtCore/qglobal.h>
#include <QObject>

#if defined(FHOME_LIBRARY)
#define FHOME_EXPORT Q_DECL_EXPORT
#else
#define FHOME_EXPORT Q_DECL_IMPORT
#endif

class IFHomeServiceListener{

    // Q_OBJECT
public:
    // IFHomeServiceListener(QObject* parent = nullptr) :QObject{parent} {}
    virtual void onOpenApp(int app) = 0;

};

class FHOME_EXPORT FHome : public QObject
{
public:
    FHome();

    void setListener(IFHomeServiceListener * objListener, QString serviceName, QString pathName, QString interface);

    static FHome* getInstane();

    void returnHome();

    void onRunAppVideo();
    void onRunAppMusic();
    void onRunAppSetting();
};

#endif // FHOME_H
