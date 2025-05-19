#ifndef SUBJECT_H
#define SUBJECT_H

#include "mark.h"

class Subject
{
private:
    QString name;
    QString teacher;
    Mark *mark;


public:
    Subject(const QString& name,const QString& teacher);
    ~Subject();
    void setName(const QString& name);
    void setTeacher(const QString& teacher);

    QString getName() const;
    QString getTeacher() const;
};

#endif // SUBJECT_H
