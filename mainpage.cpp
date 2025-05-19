#include "mainpage.h"
#include "ui_mainpage.h"
#include <QTimer>

MainPage::MainPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPage)
{
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(1, &_grades);
    ui->stackedWidget->insertWidget(2, &_attendance);
    ui->stackedWidget->insertWidget(3, &_schedule);
    ui->stackedWidget->insertWidget(4, &_announcements);
    ui->stackedWidget->insertWidget(5, &_homework);
    ui->stackedWidget->insertWidget(5, &_account);
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

void MainPage::on_pushButton_schedule_clicked() {
    ui->stackedWidget->setCurrentIndex(3);
}

void MainPage::on_pushButton_logOut_clicked()
{
    this->close();

    parentWidget()->findChild<QLineEdit*>("lineEdit_username")->setText("");
    parentWidget()->findChild<QLineEdit*>("lineEdit_password")->setText("");
    QTimer::singleShot(250, [this]() {
        parentWidget()->show();
    });


}

void MainPage::on_pushButton_announcement_clicked() {
    ui->stackedWidget->setCurrentIndex(4);
}


void MainPage::on_pushButton_homework_clicked() {
    ui->stackedWidget->setCurrentIndex(5);
}


void MainPage::on_pushButton_account_clicked(){
    ui->stackedWidget->setCurrentIndex(6);
}

