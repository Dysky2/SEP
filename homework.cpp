#include "homework.h"

Homework::Homework(QString id, Subject subject, Teacher teacher,
                   QString order, QString pubDate, int numberOfStudents,
                   int numberOfCompletedTask, QString endDate, QString solution) :
    id(id),
    subject(subject),
    teacher(teacher),
    order(order),
    pubDate(pubDate),
    numberOfStudents(numberOfStudents),
    numberOfCompletedTask(numberOfCompletedTask),
    endDate(endDate),
    solution(solution)
{}

Homework::Homework(Subject &subject, Teacher &teacher, QString &order, QString &pubDate, int &numberOfStudents, int &numberOfCompletedTask, QString &endDate, QString &solution) {
    this->subject=subject;
    this->teacher=teacher;
    this->order=order;
    this->pubDate=pubDate;
    this->numberOfStudents=numberOfStudents;
    this->numberOfCompletedTask=numberOfCompletedTask;
    this->endDate=endDate;
    this->solution=solution;
}

Homework::Homework(Subject subject, Teacher teacher, QString order, QString pubDate, int numberOfStudents, int numberOfCompletedTask, QString endDate, QString solution){
    this->subject=subject;
    this->teacher=teacher;
    this->order=order;
    this->pubDate=pubDate;
    this->numberOfStudents=numberOfStudents;
    this->numberOfCompletedTask=numberOfCompletedTask;
    this->endDate=endDate;
    this->solution=solution;

}

void Homework::setSolution(const QString& solution) {
    this->solution = solution;
}

QString Homework::getSolution() const {
    return solution;
}

void Homework::setSubject(Subject& subject){
    this->subject=subject;
}

void Homework::setTeacher(Teacher& teacher){
    this->teacher=teacher;
}

void Homework::setOrder(const QString& order){
    this->order=order;
}

void Homework::setPubDate(const QString& pubDate){
    this->pubDate=pubDate;
}

void Homework::setNumberOfStudents(int numberOfStudents){
    this->numberOfStudents=numberOfStudents;
}

void Homework::setNumberOfCompletedTasks(int numberOfCompletedTask){
    this->numberOfCompletedTask=numberOfCompletedTask;
}

void Homework::setEndDate(const QString& endDate){
    this->endDate=endDate;
}

Subject Homework::getSubject() const{
    return subject;
}

Teacher Homework::getTeacher() const{
    return teacher;
}

QString Homework::getOrder() const{
    return order;
}

QString Homework::getPubDate() const{
    return pubDate;
}

int Homework::getNumberOfStudents() const{
    return numberOfStudents;
}

int Homework::getNumberOfCompletedTask() const{
    return numberOfCompletedTask;
}

QString Homework::getEndDate() const{
    return endDate;
}

QList<Homework> Homework::getAllHomework() {
    QList<Homework> homeworkList;
    QSqlDatabase db = Database::getInstance().getConnection();

    if (!db.isOpen()) {
        qCritical() << "Błąd połączenia z bazą danych";
        return homeworkList;
    }

    QSqlQuery query(db);
    if(!query.exec("SELECT * FROM homeWork")) {
        qCritical() << "Błąd zapytania:" << query.lastError().text();
        return homeworkList;
    }

    while(query.next()) {
        Subject sub = subject.getSubjectById(query.value("subject_id").toString());
        qDebug() << sub.getId();
        Teacher tea = teacher.getTeacherById(query.value("teacher_id").toString());
        qDebug() << tea.getId();

        homeworkList.append(Homework{
            query.value("id").toString(),
            subject.getSubjectById(query.value("subject_id").toString()),
            teacher.getTeacherById(query.value("teacher_id").toString()),
            query.value("text").toString(),
            query.value("pubDate").toString(),
            query.value("numberOfStudents").toInt(),
            query.value("numberOfCompletedTask").toInt(),
            query.value("endDate").toString(),
            query.value("solution").toString()
        });
    }

    return homeworkList;
}

// QList<Homework> Homework::getAllHomework() {
//     QSqlDatabase db = Database::getInstance().getConnection();
//     QList<Homework> homeworkList;

//     if (!db.isOpen()) {
//         qDebug() << "Błąd: Połączenie z bazą danych nie jest aktywne!";
//         return homeworkList;
//     }

//     QSqlQuery query("SELECT * FROM homeWork", db);
//     if(!query.exec()) {
//         qCritical() << "Błąd zapytania:" << query.lastError().text();
//         return homeworkList;
//     }

//     while(query.next()) {
//         QString pubDateStr = query.value("pubDate").toString();
//         QString endDateStr = query.value("endDate").toString();

//         QDate pubDate = QDate::fromString(pubDateStr, "dd.MM.yyyy");
//         QDate endDate = QDate::fromString(endDateStr, "dd.MM.yyyy");

//         // Pobierz subject i teacher
//         Subject s = subject.getSubjectById(query.value("subject_id").toString());
//         Teacher t = teacher.getTeacherById(query.value("teacher_id").toString());

//         Homework tempHomework(
//             query.value("id").toString(),
//             s,
//             t,
//             query.value("order").toString(),
//             pubDate,
//             query.value("numberOfStudents").toInt(),
//             query.value("numberOfCompletedTask").toInt(),
//             endDate,
//             query.value("solution").toString()
//             );
//         homeworkList.append(tempHomework);
//     }

//     return homeworkList;
// }

void Homework::addHomework(Subject subject, Teacher teacher, QString order, QString pubDate, int numberOfStudents,
                           int numberOfCompletedTask, QString endDate, QString solution) {
    QSqlDatabase db = Database::getInstance().getConnection();

    if (!db.isOpen()) {
        qDebug() << "Błąd: Połączenie z bazą danych nie jest aktywne!";
        return;
    }

    QUuid uuid = QUuid::createUuid();
    QString uuidString = uuid.toString().mid(1, 36);

    QSqlQuery query(db);
    query.prepare("INSERT INTO homeWork VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");

    query.addBindValue(uuidString);
    query.addBindValue(subject.getId());
    query.addBindValue(teacher.getId());
    query.addBindValue(order);
    query.addBindValue(pubDate);
    query.addBindValue(numberOfStudents);
    query.addBindValue(numberOfCompletedTask);
    query.addBindValue(endDate);
    query.addBindValue(solution);

    if(!query.exec()) {
        qDebug() << "Błąd wykonania zapytania:" << query.lastError().text();
        return ;
    }

}
