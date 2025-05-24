#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

class Database {
private:
    QSqlDatabase db;

    Database();
    ~Database();

public:
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    bool isOpen() const;

    static Database& getInstance();
    QSqlDatabase& getConnection();
};

#endif // DATABASE_H
