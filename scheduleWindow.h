#ifndef SCHEDULEWINDOW_H
#define SCHEDULEWINDOW_H

#include <QMainWindow>
#include "calendar.h"

namespace Ui {
class ScheduleWindow;
}

class ScheduleWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ScheduleWindow(QString& userId, QWidget *parent = nullptr);
    explicit ScheduleWindow(QWidget *parent = nullptr);
    ~ScheduleWindow();

private slots:
    void on_pushButton_nextMonth_clicked();

    void on_pushButton_previousMonth_clicked();

private:
    Ui::ScheduleWindow *ui;
    Calendar* calendar;
};

#endif // SCHEDULEWINDOW_H
