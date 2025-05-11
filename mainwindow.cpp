#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Login_clicked()
{
    User user1 = User("Maciek", "Wielki", "418241242", "TUTAJ", "USER", "maciekwielki@g2.com", "maciek123");



    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "admin" && password == "admin") {
        // QMessageBox::information(this, "Login", "Username and password is correct");
        QMessageBox::information(this, "User", user1.getName());
        hide();
        mainPage = new MainPage(this);
        mainPage->show();
    } else {
        QMessageBox::warning(this, "Login", "username and password is not correct");
    }
}

