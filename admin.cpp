#include "admin.h"
#include "subject.h"

Admin::Admin(QString& name, QString& surname, QString& id, QString& location, QString& role,
             QString& email, QString& password, QString& faculty, bool& isActive) {
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



