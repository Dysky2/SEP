#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include "gradesWindow.h"
#include "attendanceWindow.h"
#include "schedulewindow.h"
#include "announcementsWindow.h"
#include "homeworkWindow.h"
#include "accountWindow.h"
#include "adminpanel.h"
#include <QLineEdit>
#include "database.h"
#include <QSizePolicy>

namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QString userId, QString userEmail, QWidget *parent = nullptr);
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

    void on_pushButton_adminPanel_clicked();

private:
    Ui::MainPage *ui;
    Grades *grade;
    Attendance _attendance;
    ScheduleWindow *schedule;
    Announcements _announcements;
    Homework _homework;
    Account *account;
    AdminPanel _adminPanel;
};

#endif // MAINPAGE_H
