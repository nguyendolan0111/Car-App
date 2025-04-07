#include "Translation.h"
#include <QTranslator>
#include <QDebug>
#include <QSettings>

Translation::Translation(QCoreApplication* coreApp,QObject*parent):QObject(parent)
{
    this->coreApp = coreApp;
    loadsetting();
    changeLanguage(m_currentLanguage);
}

Translation::~Translation()
{
    savesetting();
}

void Translation::changeLanguage(const QString& language)
{
    setCurrentLanguage(language);

    static QTranslator translator;
    coreApp->removeTranslator(&translator);

    qDebug() << "start";
    qDebug() << language;

    QString languageFile;

    if(language == "English"){
        languageFile = ":/AppVideo_en.qm";
    }
    else if(language == "Vietnamese"){
        languageFile = ":/AppVideo_vn.qm" ;
    }
    else{
        qDebug() << "Language not suported";
    }

    if (translator.load(languageFile) && !languageFile.isEmpty()) {
        coreApp->installTranslator(&translator);
    } else {
        qDebug() << "Failed to load language file" << languageFile;
    }

    qDebug() << "end";
    emit entryStringChanged();
    savesetting();
}

QString Translation::entryString() const{
    return QObject::tr("");
}

void Translation::setEntryString(const QString &newEnterString)
{
    if(m_entryString == newEnterString){
        return;
        m_entryString = newEnterString;
        emit entryStringChanged();
    }
}

QString Translation::currentLanguage() const
{
    return m_currentLanguage;
}

void Translation::setCurrentLanguage(const QString &newCurrentLanguage)
{
    if (m_currentLanguage == newCurrentLanguage)
        return;
    m_currentLanguage = newCurrentLanguage;
    emit currentLanguageChanged();
}

void Translation::loadsetting()
{
    QSettings settings("VUNV29", "AppVideo");
    m_currentLanguage = settings.value("currentLanguage", "English").toString();
}

void Translation::savesetting()
{
    QSettings settings = QSettings("VUNV29", "AppVideo");
    settings.setValue("currentLanguage", m_currentLanguage);
}





