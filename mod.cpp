#include "mod.h"

Mod::Mod() : Teacher(){
}
Mod::Mod(QString &id, QString &name,  QString &surname,  QString &location,
          QString &email, QString &password, Role& role,  bool isActive)
          :Teacher(id,name,surname,location,email,password,role,isActive) {

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
