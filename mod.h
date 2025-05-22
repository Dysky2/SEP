#ifndef MOD_H
#define MOD_H

#include "user.h"
#include "teacher.h"

class Mod : public Teacher
{
public:
    Mod();
    Mod(QString& name, QString& surname, QString& id, QString& location, QString& role, QString& email, QString& password,bool isActive);
    void addRole(User& user, QString& role);
    void deleteRole(User& user, QString role);
    void acceptApplication(User& user, bool& isActive);
    void rejectApplication(User& user, bool& isActive);
};
#endif // MOD_H
