#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainpage.h"
#include "app.h"
#include "user.h"
#include <QDebug>
#include <QFile>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Login_clicked();

    void on_commandLinkButton_comeBackToLogIn_clicked();

    void on_commandLinkButton_goToRegisterPage_clicked();

    void on_commandLinkButton_sendApplication_clicked();

private:
    Ui::MainWindow *ui;
    MainPage *mainPage;
    User *user;
};
\

#endif // MAINWINDOW_H
