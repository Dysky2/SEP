#ifndef MOD_H
#define MOD_H

#include "user.h"
#include "teacher.h"

class Mod : public Teacher
{
public:
    Mod();
    Mod(QString &id, QString &name,  QString &surname,  QString &location,
        QString &email, QString &password, Role& role,  bool isActive);
    void addRole(User& user, Role& role);
    void deleteRole(User& user);
    void acceptApplication(User& user);
    void rejectApplication(User& user);
};
#endif // MOD_H
