#ifndef ADMIN_H
#define ADMIN_H

#include "mod.h"
#include "subject.h"

class Admin :public Mod
{
private:
    QString faculty;
public:
    Admin(QString& name, QString& surname, QString& id, QString& location, QString& role, QString& email, QString& password, QString& faculty, bool& isActive);
    void setFaculty(QString& faculty);
    Subject createSubject(const QString& subname, const QString& teacher, const QString& description);
    void editSubject(Subject& subject,const QString& newName, const QString& newTeacher, const QString& newDescription);
    void deleteSubject(Subject& subject);

    QString getFaculty();
};

#endif // ADMIN_H
