#include "mod.h"

Mod::Mod() : Teacher(){
}
Mod::Mod(QString& name, QString& surname, QString& id, QString& location, Role& role, QString& email, QString& password, bool isActive) {

}
void Mod::addRole(User& user, Role& role) {
    user.setRole(role);
}

void Mod::deleteRole(User& user) {
    user.setRole(Role::USER);
}

void Mod::acceptApplication(User& user) {
    user.setActive();
}

void Mod::rejectApplication(User& user) {
    user.setInactive();
}
