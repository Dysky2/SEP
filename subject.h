#ifndef SUBJECT_H
#define SUBJECT_H

#include <QString>
//#include "mark.h"

class Subject {
private:
    QString name;
    QString teacher;
    QString description;
    //Mark mark;//Jak to zrobic?

public:
    Subject();
    Subject(QString name, QString teacher, QString description);
    ~Subject();
    void setName(QString name);
    void setTeacher(QString teacher);
    void setDescription(QString description);
    QString getName();
    QString getTeacher();
    QString getDescription();
};


#endif // SUBJECT_H
