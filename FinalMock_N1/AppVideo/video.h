#ifndef VIDEO_H
#define VIDEO_H

#include <QObject>

class Video : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged FINAL)
    Q_PROPERTY(QString filePath READ filePath WRITE setFilePath NOTIFY filePathChanged FINAL)

public:
    explicit Video(const QString &filePath, const QString &fileName, QObject *parent = nullptr);

    QString filePath() const;
    void setFilePath(const QString &newFilePath);

    QString fileName() const;
    void setFileName(const QString &newFileName);

signals:
    void filePathChanged();

    void fileNameChanged();

private:
    QString m_filePath;
    QString m_fileName;
};

#endif // VIDEO_H
