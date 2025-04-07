#include "TimeSettingModel.h"
#include <QObject>
#include <QDate>

TimeSettingModel::TimeSettingModel(QObject *parent)
    : QObject(parent), m_is24hFormat(true), m_isCustomFormat(false)
{
    updateDateTime();
    connect(&m_timer, &QTimer::timeout, this, &TimeSettingModel::updateDateTime);
    m_timer.start(1000);
}

bool TimeSettingModel::is24hFormat() const { return m_is24hFormat; }
void TimeSettingModel::setIs24hFormat(bool value) {
    if (m_is24hFormat != value) {
        m_is24hFormat = value;
        emit is24hFormatChanged();
    }
}

bool TimeSettingModel::isCustomFormat() const { return m_isCustomFormat; }
void TimeSettingModel::setIsCustomFormat(bool value) {
    if (m_isCustomFormat != value) {
        m_isCustomFormat = value;
        emit isCustomFormatChanged();
    }
}

int TimeSettingModel::hour() const { return m_hour; }
void TimeSettingModel::setHour(int value) {
    if (m_hour != value) {
        m_hour = value;
        emit hourChanged();
    }
}

int TimeSettingModel::minute() const { return m_minute; }
void TimeSettingModel::setMinute(int value) {
    if (m_minute != value) {
        m_minute = value;
        emit minuteChanged();
    }
}

int TimeSettingModel::second() const { return m_second; }
void TimeSettingModel::setSecond(int value) {
    if (m_second != value) {
        m_second = value;
        emit secondChanged();
    }
}

int TimeSettingModel::day() const { return m_day; }
void TimeSettingModel::setDay(int value) {
    if (m_day != value) {
        m_day = value;
        emit dayChanged();
    }
}

int TimeSettingModel::month() const { return m_month; }
void TimeSettingModel::setMonth(int value) {
    if (m_month != value) {
        m_month = value;
        emit monthChanged();
    }
}

int TimeSettingModel::year() const { return m_year; }
void TimeSettingModel::setYear(int value) {
    if (m_year != value) {
        m_year = value;
        emit yearChanged();
    }
}

void TimeSettingModel::updateDateTime()
{
    if(m_isCustomFormat == false){
        m_currentDateTime = QDateTime::currentDateTime();

        setHour(m_currentDateTime.time().hour());
        setMinute(m_currentDateTime.time().minute());
        setSecond(m_currentDateTime.time().second());
        setDay(m_currentDateTime.date().day());
        setMonth(m_currentDateTime.date().month());
        setYear(m_currentDateTime.date().year());
    }
    else{
        setSecond(m_second + 1);
        if (m_second > 59) {
            setSecond(0);
            setMinute(m_minute + 1);
        }

        if (m_minute > 59) {
            setMinute(0);
            setHour(m_hour + 1);
        }

        if (m_hour > 23) {
            setHour(0);
            setDay(m_day + 1);
        }

        // Kiểm tra số ngày trong tháng
        QDate date(m_year, m_month, 1);
        int daysInMonth = date.daysInMonth();
        qDebug() << daysInMonth;

        if (m_day > daysInMonth) {
            setDay(1);
            setMonth(m_month + 1);
        }

        if (m_month > 12) {
            setMonth(1);
            setYear(m_year + 1);
        }
    }

    QString date = QString("%1/%2/%3")
                       .arg(m_day, 2, 10, QChar('0'))
                       .arg(m_month, 2, 10, QChar('0'))
                       .arg(m_year);
    QString time;
    if(m_is24hFormat == true){
        time = QString("%1:%2:%3")
        .arg(m_hour, 2, 10, QChar('0'))
            .arg(m_minute, 2, 10, QChar('0'))
            .arg(m_second, 2, 10, QChar('0'));
    }
    else{
        int tempHour = m_hour; // Sử dụng biến tạm thời để lưu giá trị giờ
        QString period = "AM";

        if (tempHour >= 12) {
            period = "PM";
            if (tempHour > 12) {
                tempHour -= 12;
            }
        }

        if (tempHour == 0) {
            tempHour = 12;
        }
        qDebug() <<  "asdfasdf: " << period;

        if(m_language == "Vietnamese"){
            period = (period == "AM" ? "SA" : "CH");
        }
        qDebug() <<  "asdfasdf: " << period;

        time = QString("%1:%2:%3 %4")
                   .arg(tempHour, 2, 10, QChar('0'))
                   .arg(m_minute, 2, 10, QChar('0'))
                   .arg(m_second, 2, 10, QChar('0'))
                   .arg(period);
    }

    emit inforDateTime(time, date);
}


QString TimeSettingModel::language() const
{
    return m_language;
}

void TimeSettingModel::setLanguage(const QString &newLanguage)
{
    if (m_language == newLanguage)
        return;
    m_language = newLanguage;
    emit languageChanged();
}

