#ifndef TEACHER_H
#define TEACHER_H

#include "user.h"
#include "mark.h"
#include "event.h"
#include "lesson.h"
#include "announcement.h"

class Teacher : public User
{
public:
    Teacher();
    Teacher(QString &id, QString &name,  QString &surname,  QString &location, QString &email, QString &password, Role& role,  bool isActive);
    Mark addMark(QString mark_id, QString description, double grade, int weight);
    void editMark(Mark& mark, QString& newDescription, double newGrade, int newWeight);
    void deleteMark(Mark& mark);

    Event addEvent(Event& event, QString& title, QString& host, QString& date, QString& time, QString& description);
    void editEvent(Event& event, QString& newTitle, QString& newHost, QString& newDate, QString& newTime, QString& newDescription);
    void deleteEvent(Event& event);

    Lesson addLesson(const QString& name, const QString& date, const QString& teacher, const Subject& subject);
    void editLesson(Lesson& lesson, QString& newName, QString& newDate, QString& newTeacher, Subject& newSubject);
    void deleteLesson(Lesson& lesson);
    void checkAttendance();//tablica obecnosci w lesson
    void editAttendance();
    Announcement writeAnnouncement(QString& title, QString& content, QString& date);
    void editAnnouncement(Announcement& announcement, QString& title, QString& content, QString& date);
    void deleteAnnouncement(Announcement& announcement);

};

#endif // TEACHER_H
