#include "weeklycalendar.h"

WeeklyCalendar::WeeklyCalendar(QObject *parent)
    : QObject{parent}
{

}

WeeklyCalendar::~WeeklyCalendar() {

}

QStringList WeeklyCalendar::getDayOfWeek() {
    return {"Poniedziałek", "Wtorek", "Środa", "Czwartek", "Piątek", "Sobota", "Niedziela"};
}

QStringList WeeklyCalendar::createListOfHours(int startHour, int endHour) {
    QStringList hours;
    for(int h=startHour; h <= endHour; h++) {
        if(h != 0) hours.append(QString::number(h) + ":00");
        if(h != endHour) hours.append(QString::number(h) + ":30");
    }

    return hours;
}

void WeeklyCalendar::createWeekCalendar(QTableWidget *&table) {
    QStringList daysOfWeek = getDayOfWeek();

    table->setColumnCount(daysOfWeek.length());
    table->setHorizontalHeaderLabels(daysOfWeek);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QStringList hours = createListOfHours(8, 21);

    table->setRowCount(hours.length());
    table->setVerticalHeaderLabels(hours);

    // QList<TimeTable> allActivities = timeTable.getActivities();

    // for(int i=0; i < allActivities.length(); i++) {
    //     qDebug() << allActivities[i].getDay();
    // }

    for(int col = 0; col < daysOfWeek.length();col++) {
        for(int row=0; row < hours.length(); row++) {
            QLabel *label = new QLabel();
            table->setCellWidget(row, col, label);
        }
    }

    table->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    table->resizeRowsToContents();

    // scalanie komurek
    // table->setSpan(1, 0, 3, 1); // setSpan(wiersz_start, kolumna_start, liczba_wierszy, liczba_kolumn)

    table->viewport()->update();
}

void WeeklyCalendar::insertIntoWeekCalendar(QTableWidget *&table, QString day, QString time, QString duration, QString text) {
    QStringList daysOfWeek = getDayOfWeek();
    QStringList hours = createListOfHours(8, 21);
    QStringList activitiesHours = createListOfHours(0, 5);

    int dayIndex = daysOfWeek.indexOf(day);
    int timeIndex = hours.indexOf(time);
    int durationIndex = activitiesHours.indexOf(duration);

    if (dayIndex == -1 || timeIndex == -1 || durationIndex == -1) {
        qDebug() << "Nieprawidłowy dzień lub godzina lub czas trwania";
        return;
    }

    for(int col = 0; col < daysOfWeek.length(); col++) {
        for(int row=0; row < hours.length(); row++) {
            if(col == dayIndex && row == timeIndex) {
                QString insertText = insertSpacesEveryN(text, 26);
                QLabel *label = new QLabel(insertText);
                table->setCellWidget(row, col, label);
            }
        }
    }

    table->setSpan(timeIndex, dayIndex, durationIndex + 1, 1);
    table->viewport()->update();
}
