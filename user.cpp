#include "user.h"

User::User() {
    this->name = "";
    this->surname = "";
    this->id = "";
    this->location = "";
    this->role = Role::USER;
    this->email = "";
    this->password = "";
    this->isActive = 0;
}

User::User(const QString &id, const QString &name, const QString &surname, const QString &location,
           const QString &email, const QString &password, const Role& role,  bool isActive) {
    this->id = id;
    this->name = name;
    this->surname = surname;
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

void User::setRole(const Role& role) {
    this->role = role;
}

void User::setEmail(const QString& email) {
    this->email = email;
}

void User::setPassword(const QString& password) {
    this->password = password;
}

void User::setActive() {
    this->isActive = 1;
}

void User::setInactive() {
    this->isActive = 0;
}

Role User::stringToRole(QString role) {
    if (role == "USER") {
        return Role::USER;
    }
    else if (role == "TEACHER") {
        return Role::TEACHER;
    }
    else if (role == "MOD") {
        return Role::MOD;
    }
    else if (role == "ADMIN") {
        return Role::ADMIN;
    }
    else {
        return Role::USER; // wartość domyślna
    }
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
    switch(role) {
    case Role::USER:    return "USER";
    case Role::TEACHER: return "TEACHER";
    case Role::MOD:     return "MOD";
    case Role::ADMIN:   return "ADMIN";
    default:            return "USER";
    }
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

User getUserById(const QString &userId) {
    QSqlDatabase db = Database::getInstance().getConnection();
    if (!db.isOpen()) {
        qDebug() << "Błąd: Połączenie z bazą danych nie jest aktywne!";
        return User();
    }

    QSqlQuery query(db);
    query.prepare("SELECT * FROM users WHERE id = :userId LIMIT 1");
    query.bindValue(":userId", userId);

    if(!query.exec()) {
        qDebug() << "Błąd wykonania zapytania:" << query.lastError().text();
        db.close();
        return User();
    }

    if(query.next()) {
        User tempUser(query.value("id").toString(), query.value("name").toString(), query.value("surname").toString(),
                    query.value("location").toString(), query.value("email").toString(), query.value("password").toString(),
                    User::stringToRole(query.value("role").toString()), query.value("isActive").toInt());
        db.close();
        return tempUser;
    } else {
        qDebug() << "Nie znaleziono użytkownika o ID:" << userId;
        db.close();
        return User();
    }
}

User* getAllUsers(int& userCount) {
    QSqlDatabase db = Database::getInstance().getConnection();

    userCount = 0;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM applications");

    if(!query.exec()) {
        qDebug() << "SQL Error:" << query.lastError().text();
        return nullptr;
    }

    User *users = new User[query.record().count()];
    while(query.next()) {
        User tempUser(query.value("id").toString(), query.value("name").toString(), query.value("surname").toString(),
                        query.value("location").toString(), query.value("email").toString(), query.value("password").toString(),
                        User::stringToRole(query.value("role").toString()), query.value("isActive").toInt());
        users[userCount] = tempUser;
        userCount++;
    }
    return users;
}

Subject* getAllSubjects(QString userId, int &subjectsCount) {

    QSqlDatabase db = Database::getInstance().getConnection();
    subjectsCount = 0;
    QSqlQuery query(db);

    // LISTA PRZEDMIOTÓW DLA DANEGO UŻYKOWNIKA
    query.prepare("SELECT subjects.subject_id, subjects.name, subjects.description, subjects.teacher_id, subjects.mark_list_id FROM users "
                  " INNER JOIN subject_list ON users.subject_list_id = subject_list.subject_list_id "
                  " INNER JOIN subjects ON subject_list.subject_id = subjects.subject_id WHERE users.id = :id");
    query.bindValue(":id", userId);

    if(!query.exec()) {
        return nullptr;
    }

    Subject* subjects = new Subject[query.record().count()];
    while(query.next()) {
        Subject tempSubject(query.value("subject_id").toString(), query.value("name").toString(), query.value("description").toString(),
                            query.value("teacher_id").toString(), query.value("mark_list_id").toString());
        subjects[subjectsCount] = tempSubject;
        subjectsCount++;
    }

    return subjects;
}
