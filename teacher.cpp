#include "teacher.h"

Teacher::Teacher() : User()
{
}
Teacher::Teacher(QString id, QString name,  QString surname,  QString location,
                 QString email, QString password, Role role,  bool isActive)
    :User(id,name,surname,location,email,password,role,isActive) {
}
Mark Teacher::addMark(QString mark_id, QString description, double grade, int weight) {
    return Mark(mark_id, description, grade, weight);
}

void Teacher::editMark(Mark& mark, QString& newDescription, double newGrade, int newWeight) {
    mark.setDescription(newDescription);
    mark.setGrade(newGrade);
    mark.setWeight(newWeight);
}

void Teacher::deleteMark(Mark& mark) {
    mark.~Mark();
}

Event Teacher::addEvent(Event& event, QString& title, QString& host, QString& date, QString& time, QString& description) {
    return Event(title, host, date, time, description);
}

void Teacher::editEvent(Event& event, QString& newTitle, QString& newHost, QString& newDate, QString& newTime, QString& newDescription) {
    event.setTitle(newTitle);
    event.setHost(newHost);
    event.setDate(newDate);
    event.setTime(newTime);
    event.setDescription(newDescription);
}

void Teacher::deleteEvent(Event& event) {
    event.~Event();
}

Lesson Teacher::addLesson(const QString& name, const QString& date, const QString& teacher, const Subject& subject) {
    return Lesson(name, date, teacher, subject);
}

void Teacher::editLesson(Lesson& lesson, QString& newName, QString& newDate, QString& newTeacher, Subject& newSubject) {
    lesson.setName(newName);
    lesson.setDate(newDate);
    lesson.setTeacher(newTeacher);
    lesson.setSubject(newSubject);
}

void Teacher::deleteLesson(Lesson& lesson) {
    lesson.~Lesson();
}

void Teacher::checkAttendance() {

}

void Teacher::editAttendance() {

}

Announcement Teacher::writeAnnouncement(QString& title, QString& content, QString& date,QString& author) {
    return Announcement(title, content, date,author);
}

void Teacher::editAnnouncement(Announcement& announcement, QString& title, QString& content, QString& date) {
    announcement.setTitle(title);
    announcement.setContent(content);
    announcement.setDate(date);
}

void Teacher::deleteAnnouncement(Announcement& announcement) {
    announcement.~Announcement();
}

Teacher Teacher::getTeacherById(QString teacherId) {
    QSqlDatabase db = Database::getInstance().getConnection();

    if (!db.isOpen()) {
        qDebug() << "Błąd: Połączenie z bazą danych nie jest aktywne!";
        return Teacher();
    }

    QSqlQuery query(db);
    query.prepare("SELECT * FROM users WHERE id = :teacherId LIMIT 1");
    query.bindValue(":teacherId", teacherId);

    if(!query.exec()) {
        qDebug() << "Błąd wykonania zapytania:" << query.lastError().text();
        return Teacher();
    }

    if(query.next()) {
        Teacher tempTeacher(query.value("id").toString(), query.value("name").toString(), query.value("surname").toString(),
                      query.value("location").toString(), query.value("email").toString(), query.value("password").toString(),
                      User::stringToRole(query.value("role").toString()), query.value("isActive").toInt());
        return tempTeacher;
    } else {
        qDebug() << "Nie znaleziono użytkownika o ID:" << teacherId;
        return Teacher();
    }
}
