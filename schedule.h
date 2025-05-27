#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QString>
#include <QDate>

class Schedule {
private:
    QString id;
    QString text;
    QString author_id;
    QDate date;

public:
    Schedule();
    Schedule(QString id, QString text, QString author_id, QDate date);
    QString getText();
    QDate getDate();
};

#endif // SCHEDULE_H
