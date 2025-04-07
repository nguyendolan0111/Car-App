#include "Translation.h"
#include <QTranslator>
#include <QDebug>

Translation::Translation(QCoreApplication* coreApp,QObject*parent):QObject(parent)
{
    this->coreApp = coreApp;
}

void Translation::changeLanguage(const QString& language)
{
    static QTranslator translator;
    coreApp->removeTranslator(&translator);

    qDebug() << "start";
    qDebug() << language;

    QString languageFile;

    if(language == "English"){
        languageFile = ":/AppSetting_en.qm";
    }
    else if(language == "Vietnamese"){
        languageFile = ":/AppSetting_vn.qm" ;
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




