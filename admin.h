#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"

class Admin:public User
{
private:
    QString faculty;
public:
    Admin(QString &name, QString &surname, QString &id, QString &location, QString &role, QString &email, QString &password, QString &faculty);

    void setFaculty(QString &faculty);

    QString getFaculty();
};

#endif // ADMIN_H
