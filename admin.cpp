#include "admin.h"
#include "subject.h"

Admin::Admin(QString& name, QString& surname, QString& id, QString& location, QString& role,
             QString& email, QString& password, QString& faculty, bool& isActive)// :Mod(name, surname, id, location, role, email, password, isActive) {
{
    this->faculty = faculty;
}

void Admin::setFaculty(QString& faculty) {
    this->faculty = faculty;
}

Subject Admin::createSubject(const QString& subname, const QString& teacher, const QString& description) {
    return Subject(subname, teacher,description);
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



