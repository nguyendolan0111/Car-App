#include "BasePlaybackModel.h"

BasePlaybackModel::BasePlaybackModel(QObject *parent)
    : QObject{parent}
{}

int BasePlaybackModel::totalTime() const
{
    return m_totalTime;
}

void BasePlaybackModel::setTotalTime(int newTotalTime)
{
    if (m_totalTime == newTotalTime)
        return;
    m_totalTime = newTotalTime;
    emit totalTimeChanged();
}

int BasePlaybackModel::currentTime() const
{
    return m_currentTime;
}

void BasePlaybackModel::setCurrentTime(int newCurrentTime)
{
    if (m_currentTime == newCurrentTime)
        return;
    m_currentTime = newCurrentTime;
    emit currentTimeChanged();
}

QMediaPlayer::PlaybackState BasePlaybackModel::status() const
{
    return m_status;
}

void BasePlaybackModel::setStatus(const QMediaPlayer::PlaybackState &newStatus)
{
    if (m_status == newStatus)
        return;
    m_status = newStatus;
    emit statusChanged();
}
