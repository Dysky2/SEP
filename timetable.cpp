#include "timetable.h"

TimeTable::TimeTable(): weeklyCalendar(new WeeklyCalendar{}) {

}

TimeTable::TimeTable(QString id, QString day, QString hour, QString duration, QString text): weeklyCalendar(new WeeklyCalendar{}) {
    this->id = id;
    this->day = day;
    this->hour = hour;
    this->duration = duration;
    this->text = text;
}

TimeTable::~TimeTable() {
}

bool TimeTable::existActivitiesOnThisDate(QString day, QString hour, QString duration) {
    QSqlDatabase db = Database::getInstance().getConnection();
    if (!db.isOpen()) {
        qDebug() << "Błąd połączenia z bazą danych";
        return false;
    }

    QSqlQuery query(db);
    query.prepare("SELECT hour, duration FROM timeTable WHERE day = :day");
    query.bindValue(":day", day);

    if(!query.exec()) {
        qDebug() << "BŁAD: " << query.lastError().text();
        return false;
    }

    QStringList hours = weeklyCalendar->createListOfHours(8, 21);
    QStringList activitiesHours = weeklyCalendar->createListOfHours(0, 5);

    while(query.next()) {
        int indexOfCurrentHour = hours.indexOf(hour);
        int indexOfCurrentDuration = activitiesHours.indexOf(duration) + 1;
        int indexOfDataBaseHour =  hours.indexOf(query.value("hour").toString());
        int indexOfDataBaseDuration = activitiesHours.indexOf(query.value("duration").toString()) + 1;
        qDebug() << "CH: " << indexOfCurrentHour << " CD: " << indexOfCurrentDuration << " DBH: " << indexOfDataBaseHour << " DBD: " << indexOfDataBaseDuration;
        for(int i=indexOfDataBaseHour; i <= indexOfDataBaseHour + indexOfDataBaseDuration; i++) {
            if(i == indexOfCurrentHour || i == indexOfCurrentHour + indexOfCurrentDuration) {
                qDebug() << "NIE MOZNA";
                return true;
            }
        }
        if( ((indexOfCurrentHour >= (indexOfDataBaseHour + indexOfDataBaseDuration)) || ((indexOfCurrentHour + indexOfCurrentDuration) < indexOfDataBaseHour))
            || (indexOfCurrentHour < indexOfDataBaseHour)) {
            qDebug() << "NIE MOZNA";
            return true;
        }
    }

    return false;
}

QList<TimeTable> TimeTable::getActivities() {
    QSqlDatabase db = Database::getInstance().getConnection();
    QList<TimeTable> allActivities;

    if (!db.isOpen()) {
        qDebug() << "Błąd połączenia z bazą danych";
        return allActivities;
    }

    QSqlQuery query(db);
    query.prepare("SELECT * FROM timeTable");

    if(!query.exec()) {
        qDebug() << "BŁAD: " << query.lastError().text();
        return allActivities;
    }

    while(query.next()) {
        TimeTable tempTimeTable(query.value("id").toString(), query.value("day").toString(), query.value("hour").toString(),
                                query.value("duration").toString(), query.value("text").toString());

        allActivities.append(tempTimeTable);
    }

    return allActivities;
}

QString TimeTable::getDay() {
    return this->day;
}
