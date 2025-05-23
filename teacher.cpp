#include "teacher.h"

Teacher::Teacher() : User()
{
}
Teacher::Teacher(QString& name, QString& surname, QString& id, QString& location, Role& role, QString& email, QString& password, bool isActive) {

}
Mark Teacher::addMark(QString& description, double grade, int weight) {
    return Mark(description, grade, weight);
}

void Teacher::editMark(Mark& mark, QString& newDescription, double newGrade, int newWeight) {
    mark.setDescription(newDescription);
    mark.setGrade(newGrade);
    mark.setWeight(newWeight);
}

void Teacher::deleteMark(Mark& mark) {
    mark.~Mark();
}

Event Teacher::addEvent(Event& event, QString& title, QString& host, QString& date, QString& time, QString& description) {
    return Event(title, host, date, time, description);
}

void Teacher::editEvent(Event& event, QString& newTitle, QString& newHost, QString& newDate, QString& newTime, QString& newDescription) {
    event.setTitle(newTitle);
    event.setHost(newHost);
    event.setDate(newDate);
    event.setTime(newTime);
    event.setDescription(newDescription);
}

void Teacher::deleteEvent(Event& event) {
    event.~Event();
}

Lesson Teacher::addLesson(const QString& name, const QString& date, const QString& teacher, const Subject& subject) {
    return Lesson(name, date, teacher, subject);
}

void Teacher::editLesson(Lesson& lesson, QString& newName, QString& newDate, QString& newTeacher, Subject& newSubject) {
    lesson.setName(newName);
    lesson.setDate(newDate);
    lesson.setTeacher(newTeacher);
    lesson.setSubject(newSubject);
}

void Teacher::deleteLesson(Lesson& lesson) {
    lesson.~Lesson();
}

void Teacher::checkAttendance() {

}

void Teacher::editAttendance() {

}

Announcement Teacher::writeAnnouncement(QString& title, QString& content, QString& date) {
    return Announcement(title, content, date);
}

void Teacher::editAnnouncement(Announcement& announcement, QString& title, QString& content, QString& date) {
    announcement.setTitle(title);
    announcement.setContent(content);
    announcement.setDate(date);
}

void Teacher::deleteAnnouncement(Announcement& announcement) {
    announcement.~Announcement();
}

