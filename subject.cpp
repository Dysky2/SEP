#include "subject.h"

Subject::Subject() {
    this->name = "";
    this->teacher = "";
    this->description = "";
}
Subject::Subject(QString id, QString name, QString description, QString teacher, QString mark_list_id) {
    this->id = id;
    this->name = name;
    this->description = description;
    this->teacher = teacher;
    this->mark_list_id = mark_list_id;
}
Subject::~Subject() {
}

void Subject::setName(QString name) {
    this->name = name;
}
void Subject::setTeacher(QString teacher) {
    this->teacher = teacher;
}
void Subject::setDescription(QString description) {
    this->description = description;
}

QString Subject::getName() {
    return name;
}
QString Subject::getTeacher() {
    return teacher;
}
QString Subject::getDescription() {
    return description;
}
