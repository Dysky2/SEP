#ifndef WEEKLYCALENDAR_H
#define WEEKLYCALENDAR_H

#include <QObject>
#include <QDate>
#include <QDebug>
#include <QString>
#include <QTextEdit>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include "database.h"
#include <QSqlRecord>
#include <QLatin1Char>
#include <QHeaderView>

class WeeklyCalendar : public QObject
{
    Q_OBJECT

public:
    explicit WeeklyCalendar(QObject *parent = nullptr);
    ~WeeklyCalendar();

    QStringList getDayOfWeek();
    QStringList createListOfHours(int startHour,int endHour);

    void createWeekCalendar(QTableWidget*& table);
    void insertIntoWeekCalendar(QTableWidget*& table, QString day, QString time, QString duration, QString text);
};

QString insertSpacesEveryN(const QString& text, int n);

#endif // WEEKLYCALENDAR_H
