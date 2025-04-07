#include "LanguageModel.h"

LanguageModel::LanguageModel(QObject *parent)
    : QObject(parent), m_currentLanguage("English")  // Giá trị mặc định là "English"
{
}

QString LanguageModel::currentLanguage() const
{
    return m_currentLanguage;
}

void LanguageModel::setCurrentLanguage(const QString &language)
{
    if (m_currentLanguage != language) {
        m_currentLanguage = language;
        emit languageChanged(language);  // Phát tín hiệu khi ngôn ngữ thay đổi
    }
}
