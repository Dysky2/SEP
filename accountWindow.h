#ifndef ACCOUNTWINDOW_H
#define ACCOUNTWINDOW_H

#include <QMainWindow>
#include "database.h"
#include<QMessageBox>

namespace Ui {
class Account;
}

class Account : public QMainWindow
{
    Q_OBJECT

public:
    explicit Account(QWidget *parent = nullptr);
    ~Account();

private slots:
    void on_pushButton_changePassword_clicked();

private:
    Ui::Account *ui;
};

#endif // ACCOUNTWINDOW_H
