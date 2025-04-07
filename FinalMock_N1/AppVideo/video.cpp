#include "video.h"

Video::Video(const QString &filePath, const QString &fileName, QObject *parent)
    : QObject{parent}, m_filePath(filePath), m_fileName(fileName)
{}

QString Video::filePath() const
{
    return m_filePath;
}

void Video::setFilePath(const QString &newFilePath)
{
    if (m_filePath == newFilePath)
        return;
    m_filePath = newFilePath;
    emit filePathChanged();
}

QString Video::fileName() const
{
    return m_fileName;
}

void Video::setFileName(const QString &newFileName)
{
    if (m_fileName == newFileName)
        return;
    m_fileName = newFileName;
    emit fileNameChanged();
}
