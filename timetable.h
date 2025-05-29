#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <QString>
#include "database.h"
#include <QSqlRecord>
#include <QList>
#include "weeklyCalendar.h"

class TimeTable {
private:
    QString id;
    QString day;
    QString hour;
    QString duration;
    QString text;
    WeeklyCalendar* weeklyCalendar;

public:
    TimeTable();
    TimeTable(QString id, QString day, QString hour, QString duration, QString text);
    ~TimeTable();
    bool existActivitiesOnThisDate(QString day, QString hour, QString duration);
    QList<TimeTable> getActivities();

    QString getDay();

};

#endif // TIMETABLE_H
