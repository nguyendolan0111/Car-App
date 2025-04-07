#ifndef FMUSIC_H
#define FMUSIC_H

#include <QtCore/qglobal.h>
#include <QObject>

#if defined(FMUSIC_LIBRARY)
#define FMUSIC_EXPORT Q_DECL_EXPORT
#else
#define FMUSIC_EXPORT Q_DECL_IMPORT
#endif

class IFMusicServiceListener{

public:
    virtual void inforMusic(const QString& infor) = 0;
    virtual void requestPauseMusic(bool isPause) = 0;

};

class FMUSIC_EXPORT FMusic : public QObject
{
public:
    FMusic();

    void setListener(IFMusicServiceListener * objListener, QString serviceName, QString pathName, QString interface);

    static FMusic* getInstane();

    void onRunAppHome();
    void onRunAppVideo();
    void onRunAppSetting();
};

#endif // FMUSIC_H
