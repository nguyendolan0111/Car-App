#ifndef FVIDEO_H
#define FVIDEO_H

#include <QtCore/qglobal.h>
#include <QObject>

#if defined(FVIDEO_LIBRARY)
#define FVIDEO_EXPORT Q_DECL_EXPORT
#else
#define FVIDEO_EXPORT Q_DECL_IMPORT
#endif

class IFVideoServiceListener{

public:
    virtual void inforVideo(const QString& infor) = 0;
    virtual void requestPauseVideo(bool isPause) = 0;

};

class FVIDEO_EXPORT FVideo : public QObject
{
public:
    FVideo();

    void setListener(IFVideoServiceListener * objListener, QString serviceName, QString pathName, QString interface);

    static FVideo* getInstane();

    void onRunAppHome();
    void onRunAppMusic();
    void onRunAppSetting();
};

#endif // FVIDEO_H
