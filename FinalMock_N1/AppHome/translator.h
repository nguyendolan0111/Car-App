#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <QObject>
#include <QCoreApplication>

class Translation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString entryString READ entryString WRITE setEntryString NOTIFY entryStringChanged FINAL)
public:
    explicit Translation(QCoreApplication* coreApp,QObject *parent = nullptr);

    QString entryString() const;

public slots:
    void changeLanguage(int index);
signals:

    void entryStringChanged();

private:
    void setEntryString(const QString& newEnterString);
    QString m_entryString;
    QCoreApplication *coreApp;

};

#endif // TRANSLATION_H
