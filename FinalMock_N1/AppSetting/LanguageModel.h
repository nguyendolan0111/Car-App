#ifndef LANGUAGEMODEL_H
#define LANGUAGEMODEL_H

#include <QObject>

class LanguageModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentLanguage READ currentLanguage WRITE setCurrentLanguage NOTIFY languageChanged)

public:
    explicit LanguageModel(QObject *parent = nullptr);

    QString currentLanguage() const;
    void setCurrentLanguage(const QString &language);

signals:
    void languageChanged(const QString& idLanguage);

private:
    QString m_currentLanguage;
};

#endif // LANGUAGEMODEL_H

