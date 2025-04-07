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
        languageFile = ":/AppMusic_en.qm";
    }
    else if(language == "Vietnamese"){
        languageFile = ":/AppMusic_vn.qm" ;
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

Translation *Translation::getIntance(QCoreApplication* coreApp)
{
    static Translation* intance = new Translation(coreApp);
    return intance;
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

void Translation::initialize(QQmlContext *context)
{
    context->setContextProperty("MyTranslation", this);
}

void Translation::loadsetting()
{
    QSettings settings("VUNV29", "AppMusic");
    m_currentLanguage = settings.value("currentLanguage", "English").toString();
}

void Translation::savesetting()
{
    QSettings settings = QSettings("VUNV29", "AppMusic");
    settings.setValue("currentLanguage", m_currentLanguage);
}




