#ifndef CALENDAR_H
#define CALENDAR_H

#include <QDate>
#include <QDebug>
#include <QString>
#include <QTextEdit>
#include <QGridLayout>
#include <QDialog>
#include <QLabel>
#include <QScrollArea>
#include <QScrollBar>
#include <QObject>
#include <QPushButton>
#include <QDate>
#include "database.h"
#include "schedule.h"
#include <QSqlRecord>
#include "user.h"
#include <QUuid>
#include <QLatin1Char>

class Calendar : QObject {
    Q_OBJECT
private:
    QString userId;
    QDate currentDate;
    QString test;
    QScrollArea *calendarWidget;
    int scheduleCount;

public:
    Calendar();
    explicit Calendar(QString &userId, QObject* parent = nullptr);
    ~Calendar();
    void nextMonth();
    void previousMonth();

    void createCalendar();
    void updateCalendar();

    int getScheduleCount();
    void incrementScheduleCount();
    void decrementScheduleCount();
    QString getUserId() const;
    QScrollArea* getWidget();
    QDate getCurrenDate() const;

    int getScheduleCountFromDatabase();

    Schedule* getSchedules();

    void addScheduleIntoDatabase(QString text, User author, QDate date);
};

QString insertSpacesEveryN(const QString& text, int n);

#endif // CALENDAR_H
