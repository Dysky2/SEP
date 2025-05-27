#include "database.h"

Database &Database::getInstance() {
    static Database instance;
    return instance;
}

QSqlDatabase Database::getConnection() {
    return QSqlDatabase::database(db.connectionName());
}

Database::Database(): db(QSqlDatabase::addDatabase("QSQLITE")) {
    db.setDatabaseName("../../login.db");

    QFileInfo dbFile("../../login.db");
    if (!dbFile.exists()) {
        qCritical() << "Plik bazy danych nie istnieje!";
        return;
    }

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
