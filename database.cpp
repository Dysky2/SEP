#include "database.h"

Database &Database::getInstance() {
    static Database instance;
    return instance;
}

QSqlDatabase &Database::getConnection() {
    return db;
}

Database::Database(): db(QSqlDatabase::addDatabase("QSQLITE")) {
    db.setDatabaseName("../../login.db");
    if (!db.open()) {
        qCritical() << "Błąd połączenia z bazą:" << db.lastError().text();
    }
}

Database::~Database() {
    if(db.open()) {
        db.close();
    }
}

bool Database::isOpen() const {
    return db.isOpen();
}
