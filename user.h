#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>

class User : public QObject {
    Q_OBJECT

private:
    QString name;
    QString surname;
    QString id;
    QString location;
    QString role; // admin, user, mod, teacher, candidate,
    QString email;
    QString password;

public:
    User();
    User(const QString &name, const QString &surname, const QString &id,
         const QString &location, const QString &role,
         const QString &email, const QString &password);

    // setter
    void setName(const QString &name);
    void setSurname(const QString &surname);
    void setId(const QString &id);
    void setlocation(const QString &location);
    void setRole(const QString &role);
    void setEmail(const QString &email);
    void setPassword(const QString &password);

    // gettter
    QString getName() const;
    QString getSurname() const;
    QString getId() const;
    QString getLocation() const;
    QString getRole() const;
    QString getEmail() const;
    QString getPassword() const;
};

#endif // USER_H
