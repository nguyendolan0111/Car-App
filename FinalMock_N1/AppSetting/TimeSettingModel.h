// TimeSettingModel.h
#ifndef TIMESETTINGMODEL_H
#define TIMESETTINGMODEL_H

#include <QObject>
#include <QDateTime>
#include <QTimer>

class TimeSettingModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool is24hFormat READ is24hFormat WRITE setIs24hFormat NOTIFY is24hFormatChanged)
    Q_PROPERTY(bool isCustomFormat READ isCustomFormat WRITE setIsCustomFormat NOTIFY isCustomFormatChanged)
    Q_PROPERTY(int hour READ hour WRITE setHour NOTIFY hourChanged)
    Q_PROPERTY(int minute READ minute WRITE setMinute NOTIFY minuteChanged)
    Q_PROPERTY(int second READ second WRITE setSecond NOTIFY secondChanged)
    Q_PROPERTY(int day READ day WRITE setDay NOTIFY dayChanged)
    Q_PROPERTY(int month READ month WRITE setMonth NOTIFY monthChanged)
    Q_PROPERTY(int year READ year WRITE setYear NOTIFY yearChanged)
    Q_PROPERTY(QString language READ language WRITE setLanguage NOTIFY languageChanged FINAL)

public:
    explicit TimeSettingModel(QObject *parent = nullptr);

    bool is24hFormat() const;
    void setIs24hFormat(bool value);

    bool isCustomFormat() const;
    void setIsCustomFormat(bool value);

    int hour() const;
    void setHour(int value);

    int minute() const;
    void setMinute(int value);

    int second() const;
    void setSecond(int value);

    int day() const;
    void setDay(int value);

    int month() const;
    void setMonth(int value);

    int year() const;
    void setYear(int value);

    QString language() const;
    void setLanguage(const QString &newLanguage);

public slots:
    void updateDateTime();

signals:
    void is24hFormatChanged();
    void isCustomFormatChanged(); // Thêm signal cho isCustomFormat
    void hourChanged();
    void minuteChanged();
    void secondChanged();
    void dayChanged();
    void monthChanged();
    void yearChanged();

    void inforDateTime(QString time, QString date);

    void languageChanged();

private:
    bool m_is24hFormat;
    bool m_isCustomFormat; // Thuộc tính xác định Custom
    int m_hour;
    int m_minute;
    int m_second;
    int m_day;
    int m_month;
    int m_year;
    QString m_language;
    QDateTime m_currentDateTime;
    QTimer m_timer;
};

#endif // TIMESETTINGMODEL_H


