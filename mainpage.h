#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include "grades.h"
#include "attendance.h"
#include "schedule.h"
#include "announcements.h"
#include "homework.h"
#include "account.h"

namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();

private slots:
    void on_pushButton_grades_clicked();

    void on_pushButton_attendance_clicked();

    void on_pushButton_schedule_clicked();

    void on_pushButton_logOut_clicked();

    void on_pushButton_announcement_clicked();

    void on_pushButton_homework_clicked();

    void on_pushButton_account_clicked();

private:
    Ui::MainPage *ui;
    Grades _grades;
    Attendance _attendance;
    Schedule _schedule;
    Announcements _announcements;
    Homework _homework;
    Account _account;
};

#endif // MAINPAGE_H
