#include "lesson.h"

Lesson::Lesson(QString name, QString date, QString teacher, Subject subject) {
    this->name = name;
    this->date = date;
    this->teacher = teacher;
    this->subject = subject;

}
Lesson::~Lesson() {
}
void Lesson::setName(QString name) {
    this->name = name;
}
void Lesson::setDate(QString date) {
    this->date = date;
}
void Lesson::setTeacher(QString teacher) {
    this->teacher = teacher;
}
void Lesson::setSubject(Subject subject) {
    this->subject = subject;
}

QString Lesson::getName() const {
    return name;
}
QString Lesson::getDate() const {
    return date;
}
QString Lesson::getTeacher()const{
    return teacher;
}
Subject Lesson::getSubject() const {
    return subject;
}

