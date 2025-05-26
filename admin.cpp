#include "admin.h"
#include "subject.h"

Admin::Admin(QString &id, QString &name,  QString &surname,  QString &location,
              QString &email, QString &password, Role& role,  bool isActive,QString &faculty)
             :Mod(id,name,surname,location,email,password,role,isActive) {
    this->faculty = faculty;
}

void Admin::setFaculty(QString& faculty) {
    this->faculty = faculty;
}

Subject Admin::createSubject(QString id, QString name, QString description, QString teacher, QString mark_list_id) {
    return Subject(id, name, description, teacher, mark_list_id);
}

void Admin::editSubject(Subject& subject, const QString& newName, const QString& newTeacher, const QString& newDescription) {
    subject.setName(newName);
    subject.setTeacher(newTeacher);
    subject.setDescription(newDescription);
}

void Admin::deleteSubject(Subject& subject) {
    subject.~Subject();
}

QString Admin::getFaculty() {
    return faculty;
}



