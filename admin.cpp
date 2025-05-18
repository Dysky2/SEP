#include "admin.h"

Admin::Admin(QString &name, QString &surname, QString &id, QString &location,QString &role, QString &email, QString &password, QString &faculty):User(name, surname, id, location, role, email, password){
    this->faculty=faculty;
}

void Admin::setFaculty(QString &faculty){
    this->faculty=faculty;
}

QString Admin::getFaculty(){
    return faculty;
}
