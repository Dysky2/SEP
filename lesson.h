#ifndef LESSON_H
#define LESSON_H

#include <QString>
#include "subject.h"
//#include <vector>
//#include <map>

enum class AttendanceStatus {
    PRESENT,      // Obecny
    ABSENT,       // Nieobecny
    LATE,         // Spóźniony
    EXCUSED       // Usprawiedliwiony
};

class Lesson : public Subject {
private:
    QString name;
    QString date;
    QString teacher;
    Subject subject;
    //vector<AttendanceStatus> attendance;
    //map<int, QString> excuses;

public:
    Lesson(QString name, QString date, QString teacher, Subject subject);
    ~Lesson();
    void setName(QString name);
    void setDate(QString date);
    void setTeacher(QString teacher);
    void setSubject(Subject subject);
    QString getName() const;
    QString getDate() const;
    QString getTeacher() const;
    Subject getSubject() const;
    /*void excuseAbsence(int studentIndex, const QString& reason);
    void removeExcuse(int studentIndex);
    void displayAttendance() const;
    QString getExcuse(int studentIndex) const;
    bool isExcused(int studentIndex) const;
    size_t getAttendanceCount() const;*/
};

#endif // LESSON_H
