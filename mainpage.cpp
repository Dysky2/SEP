#include "mainpage.h"
#include "ui_mainpage.h"
#include <QTimer>

MainPage::MainPage(QString& userId, QWidget *parent): QMainWindow(parent), ui(new Ui::MainPage) {
    ui->setupUi(this);

    ui->pushButton_attendance->setVisible(false);
    grade = new Grades(userId, this);
    homework = new HomeworkWindow(userId, this);
    account = new Account(userId, this);
    schedule = new ScheduleWindow(userId, this);
    announcements = new AnnouncementsWindow(userId,this);
    timeTableWindow = new TimeTableWindow(userId, this);
    ui->stackedWidget->insertWidget(1, grade);
    ui->stackedWidget->insertWidget(2, &_attendance);
    ui->stackedWidget->insertWidget(3, timeTableWindow);
    ui->stackedWidget->insertWidget(4, schedule);
    ui->stackedWidget->insertWidget(5, announcements);
    ui->stackedWidget->insertWidget(6, homework);
    ui->stackedWidget->insertWidget(7, account);
    ui->stackedWidget->insertWidget(8, &_adminPanel);

    ui->stackedWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    if(getUserById(userId).getRole() == "ADMIN") {
        ui->pushButton_adminPanel->setVisible(true);
    } else {
        ui->pushButton_adminPanel->setVisible(false);
    }
}

MainPage::MainPage(QWidget *parent): QMainWindow(parent), ui(new Ui::MainPage)
{
    ui->setupUi(this);
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_pushButton_grades_clicked() {
    ui->stackedWidget->setCurrentIndex(1);

}

void MainPage::on_pushButton_attendance_clicked() {
    ui->stackedWidget->setCurrentIndex(2);
}

void MainPage::on_pushButton_timeTable_clicked(){
    ui->stackedWidget->setCurrentIndex(3);
}

void MainPage::on_pushButton_schedule_clicked() {
    ui->stackedWidget->setCurrentIndex(4);
}

void MainPage::on_pushButton_logOut_clicked()
{
    this->close();
    QTimer::singleShot(250, [this]() {
        parentWidget()->show();
    });
}

void MainPage::on_pushButton_announcement_clicked() {
    ui->stackedWidget->setCurrentIndex(5);
}


void MainPage::on_pushButton_homework_clicked() {
    ui->stackedWidget->setCurrentIndex(6);
}


void MainPage::on_pushButton_account_clicked() {
    ui->stackedWidget->setCurrentIndex(7);
}


void MainPage::on_pushButton_adminPanel_clicked() {
    ui->stackedWidget->setCurrentIndex(8);
}



