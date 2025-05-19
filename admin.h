#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "subject.h"

class Admin:public User
{
private:
    QString faculty;
public:
    Admin(QString &name, QString &surname, QString &id, QString &location, QString &role, QString &email, QString &password, QString &faculty);

    void setFaculty(QString &faculty);
    Subject createSubject(const QString& name,const QString& teacher);
    void editSubject(const QString& newName, const QString& newTeacher);
    void deleteSubject();
    void addRole();
    void deleteRole();
    void acceptApplication();
    void rejectApplication();
    Mark addMark(QString& description, double grade, int weight);
    void editMark();
    void deleteMark();
    void addEvent(); //dodanie do termniarza
    void editEvent();//terminarz
    void deleteEvent();//terminarz
    void addLesson();//plan lekcji
    void editLesson();
    void deleteLesson();
    void checkAttendance();
    void editAttendance();
    void writeAnnouncement();
    void editAnnouncement();
    void deleteAnnouncement();
    //void divisonUserIntoGroups();

    QString getFaculty();
};

#endif // ADMIN_H
