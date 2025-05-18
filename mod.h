#ifndef MOD_H
#define MOD_H

#include "user.h"

class Mod: public User
{
public:
    Mod(QString &name, QString &surname, QString &id, QString &location, QString &role, QString &email, QString &password);
};

#endif // MOD_H
