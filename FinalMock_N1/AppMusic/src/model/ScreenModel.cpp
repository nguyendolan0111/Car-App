#include "ScreenModel.h"

ScreenModel::ScreenModel(QObject *parent)
    : QObject{parent}
{}

ScreenModel::~ScreenModel()
{
}

QString ScreenModel::currentScreen() const
{
    return m_currentScreen;
}

void ScreenModel::setCurrentScreen(const QString &newCurrentScreen)
{
    if (m_currentScreen == newCurrentScreen)
        return;
    m_currentScreen = newCurrentScreen;
    emit currentScreenChanged();
}
