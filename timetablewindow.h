#ifndef TIMETABLEWINDOW_H
#define TIMETABLEWINDOW_H

#include <QMainWindow>
#include "calendar.h"
#include "weeklycalendar.h"
#include <QLineEdit>
#include <QMessageBox>
#include <QDateEdit>
#include <QComboBox>
#include "timetable.h"

namespace Ui {
class TimeTableWindow;
}

class TimeTableWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TimeTableWindow(QString userID, QWidget *parent = nullptr);
    explicit TimeTableWindow(QWidget *parent = nullptr);
    ~TimeTableWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TimeTableWindow *ui;
    WeeklyCalendar weeklyCalendar;
    TimeTable timeTable;
};

#endif // TIMETABLEWINDOW_H
