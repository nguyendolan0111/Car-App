#include "translator.h"
#include <QTranslator>
#include <QDebug>
translator::translator(QCoreApplication* coreApp,QObject *parent)
    : QObject{parent}
{

    this->coreApp = coreApp;
}

QString translator::entryString() const
{
    return m_entryString;
}
void translator::changeLanguage(int index){
    static QTranslator translator;
    coreApp->removeTranslator(&translator);
    qDebug() << "start";
    qDebug() << index;

    QString languageFile;
    switch (index) {
    case 0:
        languageFile = ":/AppHome_en.qm";
        break;
    case 1:
        languageFile = ":/AppHome_vn.qm";
        break;
    default:
        languageFile = "";
        break;
    }

    if(!languageFile.isEmpty() && translator.load(languageFile)){
        qApp->installTranslator(&translator);
    }else{

        qDebug() << "Failed to load translation file.";
    }
    qDebug() << "end";
    emit entryStringChanged();

}

QString TranSla


void translator::setEntryString(const QString &newEntryString)
{
    if (m_entryString == newEntryString)
        return;
    m_entryString = newEntryString;
    emit entryStringChanged();
}
