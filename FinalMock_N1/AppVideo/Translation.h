#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <QObject>
#include <QCoreApplication>

class Translation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString entryString READ entryString WRITE setEntryString NOTIFY entryStringChanged FINAL)
    Q_PROPERTY(QString currentLanguage READ currentLanguage WRITE setCurrentLanguage NOTIFY currentLanguageChanged FINAL)

public:
    explicit Translation(QCoreApplication* coreApp,QObject *parent = nullptr);
    ~Translation();

    QString entryString() const;

    QString currentLanguage() const;
    void setCurrentLanguage(const QString &newCurrentLanguage);

    void loadsetting();
    void savesetting();

public slots:
    void changeLanguage(const QString& language);

signals:
    void entryStringChanged();

    void currentLanguageChanged();

private:
    void setEntryString(const QString& newEnterString);
    QString m_entryString;
    QCoreApplication *coreApp;
    QString m_currentLanguage;
};

#endif // TRANSLATION_H


