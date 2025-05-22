#include "mod.h"

Mod::Mod() : Teacher()
{
}
Mod::Mod(QString& name, QString& surname, QString& id, QString& location, QString& role, QString& email, QString& password, bool isActive)
    //:Teacher(name, surname, id, location, role, email, password,1)
{

}
void Mod::addRole(User& user, QString& role) {
    user.setRole(role);
}

void Mod::deleteRole(User& user, QString role = "USER") {
    user.setRole(role);
}

void Mod::acceptApplication(User& user, bool& isActive) {
    user.Active(isActive);
}

void Mod::rejectApplication(User& user, bool& isActive) {
    user.Inactive(isActive);
}
