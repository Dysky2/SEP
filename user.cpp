#include "User.h"

User::User() {
    this->name = "";
    this->surname = "";
    this->id = "";
    this->location = "";
    this->role = "USER";
    this->email = "";
    this->password = "";
    this->isActive = 0;
}

User::User(const QString& name, const QString& surname, const QString& id, const QString& location,
           const QString& role, const QString& email, const QString& password,bool isActive)
{
    this->name = name;
    this->surname = surname;
    this->id = id;
    this->location = location;
    this->role = role;
    this->email = email;
    this->password = password;
    this->isActive = 1;
}

User::~User() {

}

void User::setName(const QString& name) {
    this->name = name;
}

void User::setSurname(const QString& surname) {
    this->surname = surname;
}

void User::setId(const QString& id) {
    this->id = id;
}

void User::setlocation(const QString& location) {
    this->location = location;
}

void User::setRole(const QString& role) {
    this->role = role;
}

void User::setEmail(const QString& email) {
    this->email = email;
}

void User::setPassword(const QString& password) {
    this->password = password;
}

void User::Active(bool& isActive) {
    this->isActive = 1;
}

void User::Inactive(bool& isActive) {
    this->isActive = 0;
}


QString User::getName() const {
    return name;
}

QString User::getSurname() const {
    return surname;
}

QString User::getId() const {
    return id;
}

QString User::getLocation() const {
    return location;
}

QString User::getRole() const {
    return role;
}

QString User::getEmail() const {
    return email;
}

QString User::getPassword() const {
    return password;
}

bool User::getIsActive() const {
    return isActive;
}

