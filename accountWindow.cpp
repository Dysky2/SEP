#include "accountWindow.h"
#include "ui_accountWindow.h"

Account::Account(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Account)
{
    ui->setupUi(this);
    QSqlDatabase db = Database::getInstance().getConnection();

    QSqlQuery query(db);
    query.prepare("SELECT * FROM users LIMIT 1");

    if(!query.exec()) {
        QMessageBox::warning(this, "QUERY", "Błąd zapytania SQL: " + query.lastError().text());
        return;
    }
    QString name, surname, id, location, email;

    if(query.next()) {
        name = query.value("name").toString();
        surname = query.value("surname").toString();
        id = query.value("id").toString();
        location = query.value("location").toString();
        email = query.value("email").toString();
    }

    ui->label_name->setText(name);
    ui->label_surname->setText(surname);
    ui->label_id->setText(id);
    ui->label_location->setText(location);
    ui->label_email->setText(email);
}

Account::~Account()
{
    delete ui;
}

void Account::on_pushButton_changePassword_clicked() {
    QSqlDatabase db = Database::getInstance().getConnection();
}

