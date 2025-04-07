#include "VolumeModel.h"

VolumeModel::VolumeModel(QObject *parent) : QObject(parent), m_volume(5) // Default volume is set to 5
{
}

int VolumeModel::volume() const
{
    return m_volume;
}

void VolumeModel::setVolume(int newVolume)
{
    if (m_volume != newVolume) {
        m_volume = newVolume;
        emit volumeChanged();
    }
}

