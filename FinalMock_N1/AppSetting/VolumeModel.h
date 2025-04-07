#ifndef VOLUMEMODEL_H
#define VOLUMEMODEL_H

#include <QObject>

class VolumeModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY volumeChanged)

public:
    explicit VolumeModel(QObject *parent = nullptr);

    int volume() const;
    void setVolume(int newVolume);

signals:
    void volumeChanged();

private:
    int m_volume;
};

#endif // VOLUMEMODEL_H

