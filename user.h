#ifndef USER_H
#define USER_H

#include <QString>
#include <QSqlError>
#include <QSqlRecord>
#include "database.h"
#include "subject.h"

enum class Role{
    USER,
    TEACHER,
    MOD,
    ADMIN,
};

class User{


private:
    QString name;
    QString surname;
    QString id;
    QString location;
    Role role;
    QString email;
    QString password;
    bool isActive;


public:
    User();
    User(const QString &id, const QString &name, const QString &surname, const QString &location,
         const QString &email, const QString &password,const Role& role, bool isActive);
    ~User();

    void setName(const QString& name);
    void setSurname(const QString& surname);
    void setId(const QString& id);
    void setlocation(const QString& location);
    void setRole(const Role& role);
    void setEmail(const QString& email);
    void setPassword(const QString& password);
    void setActive();
    void setInactive();

    static Role stringToRole(QString role);

    QString getName() const;
    QString getSurname() const;
    QString getFullName() const;
    QString getId() const;
    QString getLocation() const;
    QString getRole() const;
    QString getEmail() const;
    QString getPassword() const;
    bool getIsActive() const;
};

User getUserById(const QString &userId);

User* getAllUsers(int& userCount);

Subject* getAllSubjects(QString userId, int& subjectsCount);

#endif // USER_H
