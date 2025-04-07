#ifndef FVIDEO_H
#define FVIDEO_H

#include <QtCore/qglobal.h>
#include <QObject>

#if defined(FVIDEO_LIBRARY)
#define FVIDEO_EXPORT Q_DECL_EXPORT
#else
#define FVIDEO_EXPORT Q_DECL_IMPORT
#endif

class IFVideoServiceListener {

    // Q_OBJECT
public:
    // IFVideoServiceListener(QObject* parent) : QObject{parent} {}
    virtual void inforVideo(const QString& infor) = 0;
    virtual void requestPauseVideo(bool isPause) = 0;

};

class FVIDEO_EXPORT FVideo
{
public:
    FVideo();

    void setListener(QObject * objListener, QString serviceName, QString pathName, QString interface);

    static FVideo* getInstane();

    void onRunAppHome();
    void onRunAppMusic();
    void onRunAppSetting();
};

#endif // FVIDEO_H
