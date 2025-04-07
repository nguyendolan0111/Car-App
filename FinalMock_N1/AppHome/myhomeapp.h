#ifndef MYHOMEAPP_H
#define MYHOMEAPP_H

#include <QObject>

class MyHomeApp : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int Id READ Id WRITE setId NOTIFY IdChanged FINAL)
    Q_PROPERTY(QString nameApp READ nameApp WRITE setNameApp NOTIFY nameAppChanged FINAL)
    Q_PROPERTY(QString imagePath READ imagePath WRITE setImagePath NOTIFY imagePathChanged FINAL)
    Q_PROPERTY(QStringList currentInfor READ currentInfor WRITE setCurrentInfor NOTIFY currentInforChanged FINAL)

public:
    explicit MyHomeApp(int id, QString nameApp, QString imagePath, QStringList currentInfor, QObject *parent = nullptr);

    QString nameApp() const;
    void setNameApp(const QString &newNameApp);

    QString imagePath() const;
    void setImagePath(const QString &newImagePath);

    QStringList currentInfor() const;
    void setCurrentInfor(const QStringList &newCurrentInfor);

    int Id() const;
    void setId(int newId);

signals:
    void nameAppChanged();

    void imagePathChanged();

    void currentInforChanged();

    void IdChanged();

private:
    int m_Id;
    QString m_nameApp;
    QString m_imagePath;
    QStringList m_currentInfor;
};

#endif // MYHOMEAPP_H
