#include "subject.h"

Subject::Subject() {
    this->name = "Unknown";
    this->teacher = "Unknown";
    this->description = "No description available.";
}
Subject::Subject(QString name, QString teacher, QString description) {
    this->name = name;
    this->teacher = teacher;
    this->description = description;
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
