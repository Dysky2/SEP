    #ifndef TIMETABLE_H
    #define TIMETABLE_H

    #include <QString>
    #include "database.h"
    #include <QSqlRecord>
    #include <QList>
    #include "weeklyCalendar.h"
    #include <QUuid>
    #include <QLatin1Char>

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
        void addTimeTable(QString id, QString day, QString hour, QString duration, QString text);
        QString getDay();
        QString getHour();
        QString getDuration();
        QString getText();

    };

    QList<TimeTable> getActivities();
    #endif
