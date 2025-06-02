#ifndef LESSON_H
#define LESSON_H

#include <QString>
#include "subject.h"
//#include <vector>
//#include <map>

enum class AttendanceStatus {
    PRESENT,
    ABSENT,
    LATE,
    EXCUSED
};

class Lesson : public Subject {
private:
    QString name;
    QString date;
    QString teacher;
    Subject subject;

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
};

#endif // LESSON_H
