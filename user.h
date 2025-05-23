#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>

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
    User(const QString& name, const QString& surname, const QString& id,
         const QString& location, const Role& role,
         const QString& email, const QString& password, bool isActive);
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


    QString getName() const;
    QString getSurname() const;
    QString getId() const;
    QString getLocation() const;
    QString getRole() const;
    QString getEmail() const;
    QString getPassword() const;
    bool getIsActive() const;


};

#endif // USER_H
