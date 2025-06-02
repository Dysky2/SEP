#ifndef SUBJECT_H
#define SUBJECT_H

#include <QString>
#include "mark.h"

class Subject {
private:
    QString id;
    QString name;
    QString teacher;
    QString description;
    QString mark_list_id;

public:
    Subject();
    Subject(QString id, QString name, QString description, QString teacher, QString mark_list_id);
    ~Subject();

    void setName(QString name);
    void setTeacher(QString teacher);
    void setDescription(QString description);

    QString getId();
    QString getName();
    QString getTeacher();
    QString getDescription();

    QList<Subject> getAllSubjects();
    Subject getSubjectById(QString subjectId);
};


#endif
