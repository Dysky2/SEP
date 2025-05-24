#include "adminpanel.h"
#include "ui_adminpanel.h"

AdminPanel::AdminPanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminPanel)
{
    ui->setupUi(this);

    QSqlDatabase db = Database::getInstance().getConnection();

    // zrzuca bład połaczmia z baza
    int userCount = 0;
    User* users = getAllUsers(userCount);

    QString applicationList;
    for(int i=0; i < userCount; i++) {
        applicationList += QString("%1. %2 %3\n")
            .arg(i+1)
            .arg(users[i].getName())
            .arg(users[i].getSurname());
    }

    ui->label_activeApplications->setText("Aktywne zgłoszenia (" + QString::number(userCount) + ")");
    ui->textBrowser_applicationList->setText(applicationList);
    delete[] users;
}

AdminPanel::~AdminPanel()
{
    delete ui;
}
