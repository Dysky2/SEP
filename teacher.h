#ifndef TEACHER_H
#define TEACHER_H

#include "user.h"
class Teacher: public User
{
public:
    Teacher(QString &name, QString &surname, QString &id, QString &location, QString &role, QString &email, QString &password);
};

#endif // TEACHER_H
