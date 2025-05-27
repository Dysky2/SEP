#include "mod.h"

Mod::Mod() : Teacher(){
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
