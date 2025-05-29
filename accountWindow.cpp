#include "accountWindow.h"
#include "ui_accountWindow.h"

Account::Account(QString userId, QWidget *parent): QMainWindow(parent), ui(new Ui::Account) {
    ui->setupUi(this);

    User loggedUser = getUserById(userId);

    ui->label_name->setText(loggedUser.getName());
    ui->label_surname->setText(loggedUser.getSurname());
    ui->label_id->setText(loggedUser.getId());
    ui->label_status->setText(loggedUser.getRole());
    ui->label_location->setText(loggedUser.getLocation());
    ui->label_email->setText(loggedUser.getEmail());
}

Account::Account(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Account)
{
    ui->setupUi(this);
}

Account::~Account()
{
    delete ui;
}

void Account::on_pushButton_changePassword_clicked() {
    QSqlDatabase db = Database::getInstance().getConnection();
}

