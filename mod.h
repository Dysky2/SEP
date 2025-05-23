#ifndef MOD_H
#define MOD_H

#include "user.h"
#include "teacher.h"

class Mod : public Teacher
{
public:
    Mod();
    Mod(QString& name, QString& surname, QString& id, QString& location, Role& role, QString& email, QString& password,bool isActive);
    void addRole(User& user, Role& role);
    void deleteRole(User& user);
    void acceptApplication(User& user);
    void rejectApplication(User& user);
};
#endif // MOD_H
