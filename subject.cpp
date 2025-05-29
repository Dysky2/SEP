#include "subject.h"

Subject::Subject() {
    this->id = "";
    this->name = "";
    this->description = "";
    this->teacher = "";
    this->mark_list_id = "";
}
Subject::Subject(QString id, QString name, QString description, QString teacher, QString mark_list_id) {
    this->id = id;
    this->name = name;
    this->description = description;
    this->teacher = teacher;
    this->mark_list_id = mark_list_id;
}
Subject::~Subject() {
}

void Subject::setName(QString name) {
    this->name = name;
}
void Subject::setTeacher(QString teacher) {
    this->teacher = teacher;
}
void Subject::setDescription(QString description) {
    this->description = description;
}

QString Subject::getId() {
    return id;
}

QString Subject::getName() {
    return name;
}
QString Subject::getTeacher() {
    return teacher;
}
QString Subject::getDescription() {
    return description;
}

QList<Subject> Subject::getAllSubjects() {
    QSqlDatabase db = Database::getInstance().getConnection();
    QList<Subject> subjectList;

    if (!db.isOpen()) {
        qDebug() << "Błąd: Połączenie z bazą danych nie jest aktywne!";
        return subjectList;
    }

    QSqlQuery query(db);
    query.prepare("SELECT * FROM subjects");

    if(!query.exec()) {
        qDebug() << "Błąd wykonania zapytania:" << query.lastError().text();
        return subjectList;
    }

    while(query.next()) {
        Subject tempSubject(query.value("subject_id").toString(), query.value("name").toString(), query.value("description").toString(),
                            query.value("teacher_id").toString(), query.value("mark_list_id").toString());
        subjectList.append(tempSubject);
    }

    return subjectList;
}

Subject Subject::getSubjectById(QString subjectId) {
    QSqlDatabase db = Database::getInstance().getConnection();

    if (!db.isOpen()) {
        qDebug() << "Błąd: Połączenie z bazą danych nie jest aktywne!";
        return Subject();
    }

    QSqlQuery query(db);
    query.prepare("SELECT * FROM subjects WHERE subject_id = :subjectId LIMIT 1");
    query.bindValue(":subjectId", subjectId);

    if(!query.exec()) {
        qDebug() << "Błąd wykonania zapytania:" << query.lastError().text();
        return Subject();
    }

    if(query.next()) {
        Subject tempSubject(query.value("subject_id").toString(), query.value("name").toString(), query.value("description").toString(),
                            query.value("teacher_id").toString(), query.value("mark_list_id").toString());
        return tempSubject;
    } else {
        qDebug() << "Nie znaleziono użytkownika o ID:" << subjectId;
        return Subject();
    }
}
