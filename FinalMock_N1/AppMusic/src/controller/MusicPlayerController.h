#ifndef MUSICPLAYERCONTROLLER_H
#define MUSICPLAYERCONTROLLER_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QQmlContext>
#include <QSettings>
#include "MusicListController.h"
#include "src/model/MusicPlaybackModel.h"
#include "MusicDbusHandler.h"
#include "src/StatusBar_Interface.h"

class MusicPlayerController : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-bus Interface", "com.music.MusicServiceInterface")
    Q_PROPERTY(MusicPlaybackModel* currentSong READ currentSong WRITE setCurrentSong NOTIFY currentSongChanged FINAL)
    Q_PROPERTY(int currentIndex READ curentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged FINAL)
    Q_PROPERTY(bool random READ random WRITE setRandom NOTIFY radomChanged FINAL)
    Q_PROPERTY(bool loop READ loop WRITE setLoop NOTIFY loopChanged FINAL)
    Q_PROPERTY(float volumn READ volumn WRITE setVolumn NOTIFY volumnChanged FINAL)
    Q_PROPERTY(bool pause READ pause WRITE setPause NOTIFY pauseChanged FINAL)
private:
    explicit MusicPlayerController(QObject *parent = nullptr);
public:

    ~MusicPlayerController();
    static MusicPlayerController* getInstance();
    void initialize(QQmlContext *context);

    MusicPlaybackModel *currentSong() const;
    void setCurrentSong(MusicPlaybackModel *newCurrentSong);
    QString convertString(int number);
    int curentIndex() const;
    void setCurrentIndex(int newCurrentIndex);
    bool random() const;
    void setRandom(bool newRadom);
    bool loop() const;
    void setLoop(bool newLoop);
    float volumn() const;
    Q_INVOKABLE void setVolumn(float newVolumn);

    bool pause() const;
    void setPause(bool newPause);

    void registerStatusBar(QQmlEngine* engine);

public slots:
    MusicListModel* getModel();
    void SearchSong(const QString &searchString);
    MusicListModel* getSearchModel();
    void requestPlay();
    void requestPause();
    void requestStop();
    void requestNext();
    void requestPrevious();
    void requestFastForward();
    void requestFastBackward();
    void setPosition(int position);

    void changePosition(qint64 position);
    void StatusChanged(QMediaPlayer::MediaStatus status);
    void StatusPlayChange(QMediaPlayer::PlaybackState status);
    void setPlaySong(int index);

    void sendMusicInfoToHome();
    void onPause(bool isPause);

    void setDateStatusBar(const QString &date);
    void setTimeStatusBar(const QString &time);

    void saveSetting();
signals:
    void currentSongChanged();
    void currentSongIndexChanged(int index);
    void currentIndexChanged();
    void radomChanged();
    void loopChanged();
    void volumnChanged();
    void pauseChanged();
    void setInforScreen();
    void currentLanguageChanged(const QString& idLang);

private:
    void iniSetting();
private:
    static MusicPlayerController* m_instance;
    QMediaPlayer* Player;
    QAudioOutput* m_audio;
    MusicListController* listController;
    MusicPlaybackModel *m_currentSong;
    MyStatusBarInterface* statusBar;
    int m_currentIndex;
    bool m_random;
    bool m_loop;
    bool m_pause;
    float m_volumn;
};

#endif // MUSICPLAYERCONTROLLER_H
