#include "myhomeapp.h"

MyHomeApp::MyHomeApp(int id, QString nameApp, QString imagePath, QStringList currentInfor, QObject *parent)
    : QObject{parent}, m_Id(id), m_nameApp(nameApp), m_imagePath(imagePath), m_currentInfor(currentInfor)
{}

QString MyHomeApp::nameApp() const
{
    return m_nameApp;
}

void MyHomeApp::setNameApp(const QString &newNameApp)
{
    if (m_nameApp == newNameApp)
        return;
    m_nameApp = newNameApp;
    emit nameAppChanged();
}

QString MyHomeApp::imagePath() const
{
    return m_imagePath;
}

void MyHomeApp::setImagePath(const QString &newImagePath)
{
    if (m_imagePath == newImagePath)
        return;
    m_imagePath = newImagePath;
    emit imagePathChanged();
}

QStringList MyHomeApp::currentInfor() const
{
    return m_currentInfor;
}

void MyHomeApp::setCurrentInfor(const QStringList &newCurrentInfor)
{
    if (m_currentInfor == newCurrentInfor)
        return;
    m_currentInfor = newCurrentInfor;
    emit currentInforChanged();
}

int MyHomeApp::Id() const
{
    return m_Id;
}

void MyHomeApp::setId(int newId)
{
    if (m_Id == newId)
        return;
    m_Id = newId;
    emit IdChanged();
}
