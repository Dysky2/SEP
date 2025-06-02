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

void MainWindow::on_pushButton_Login_clicked() {
    QSqlDatabase db = Database::getInstance().getConnection();

    QString email = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "email i hasło są wymagane!");
        return;
    }

    if (db.open()) {
        QSqlQuery query(db);
        query.prepare("SELECT * FROM users WHERE email = :email AND password = :password");
        query.bindValue(":email", email);
        query.bindValue(":password", password);

        if (query.exec()) {
            if (query.next()) {
                QString userId = query.value("id").toString();
                QString userEmail = query.value("email").toString();
                    hide();
                    mainPage = new MainPage(userId, this);
                    mainPage->show();
                    ui->lineEdit_username->setText("");
                    ui->lineEdit_password->setText("");
            } else {
                QMessageBox::warning(this, "Błąd", "Nieprawidłowy login lub hasło!");
            }
        }
        else {
            QMessageBox::warning(this, "Błąd", "Login failed (database error).!");
        }

    }else {
        // Handle database connection error
        QMessageBox::warning(this, "Błąd", "Nie można połączyć z bazą danych!");
    }

    db.close();
}

void MainWindow::on_commandLinkButton_comeBackToLogIn_clicked() {
    int nextIndex = (ui->stackedWidget->currentIndex() + 1) % ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(nextIndex);
}


void MainWindow::on_commandLinkButton_goToRegisterPage_clicked() {
    int nextIndex = (ui->stackedWidget->currentIndex() + 1) % ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(nextIndex);
}


void MainWindow::on_commandLinkButton_sendApplication_clicked() {
    QString name = ui->lineEdit_name->text();
    QString surname = ui->lineEdit_surname->text();
    QString id = ui->lineEdit_id->text();
    QString location = ui->lineEdit_location->text();
    QString email = ui->lineEdit_email->text();
    QString password1 = ui->lineEdit_password_1->text();
    QString password2 = ui->lineEdit_password_2->text();

    QSqlDatabase db = Database::getInstance().getConnection();

    if(name.isEmpty() || surname.isEmpty() || id.isEmpty() || location.isEmpty() || email.isEmpty() || password1.isEmpty() || password2.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wszystkie pola są wymagane!");
        return;
    }

    if(password1 != password2) {
        QMessageBox::warning(this, "Błąd", "Hasła nie są identyczne!");
        return;
    }

    QSqlQuery query(db);
    query.prepare("SELECT * FROM users WHERE id = :id");
    query.bindValue(":id", id);

    if(!query.exec())  {
        QMessageBox::warning(this, "Błąd", "Błąd zapytania SQL: " + query.lastError().text());
        db.close();
        return;
    }

    if (query.next()) {
        QMessageBox::warning(this, "Błąd", "Użytkownik o podanym ID już istnieje w bazie");
        db.close();
        return;
    }

    QSqlQuery insert_query(db);
    insert_query.prepare("INSERT INTO applications (id, name, surname, location, email, password, role) VALUES (:id, :name, :surname, :location, :email, :password, 'USER')");
    insert_query.bindValue(":id", id);
    insert_query.bindValue(":name", name);
    insert_query.bindValue(":surname", surname);
    insert_query.bindValue(":location", location);
    insert_query.bindValue(":email", email);
    insert_query.bindValue(":password", password1);

    if(insert_query.exec()) {
        QMessageBox::warning(this, "DZIAŁA", "POMYSLNIE DODANO UZYTKOWNIKA");
        ui->lineEdit_id->setText("");
        ui->lineEdit_name->setText("");
        ui->lineEdit_surname->setText("");
        ui->lineEdit_location->setText("");
        ui->lineEdit_email->setText("");
        ui->lineEdit_password_1->setText("");
        ui->lineEdit_password_2->setText("");
    } else {
        QMessageBox::warning(this, "NIE DZIAŁA", "NIE DODANO UZYTKOWNIKA)" + insert_query.lastError().text());
    }

    db.close();
}

