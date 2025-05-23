#include "mark.h"

Mark::Mark() {
    this->description = "";
    this->grade = 0;
    this->weight = 0;
}
Mark::Mark(QString mark_id, QString description, double grade, int weight) {
    this->mark_id = mark_id;
    this->description=description;
    this->grade=grade;
    this->weight=weight;
}

Mark::~Mark() {

}

void Mark::setDescription(const QString& description) {
    this->description = description;
}

void Mark::setGrade(double grade) {
    this->grade = grade;
}

void Mark::setWeight(int weight) {
    this->weight = weight;
}

QString Mark::getDescription() const {
    return description;
}

double Mark::getGrade() const {
    return grade;
}

int Mark::getWeight() const {
    return weight;
}

Mark* getAllMarksByUserIdAndBySubject(QString userId, QString subjectName, int& marksCount) {
    QSqlDatabase db = Database::getInstance().getConnection();

    marksCount = 0;
    QSqlQuery query(db);

    query.prepare("SELECT marks.mark_id, marks.grade, marks.weight, marks.description FROM users "
                  " INNER JOIN subject_list ON users.subject_list_id = subject_list.subject_list_id "
                  " INNER JOIN subjects ON subject_list.subject_id = subjects.subject_id "
                  " INNER JOIN mark_list ON subjects.mark_list_id = mark_list.mark_list_id "
                  " INNER JOIN marks ON mark_list.mark_id = marks.mark_id "
                  " WHERE users.id = :userId AND subjects.name = :subjectName");
    query.bindValue(":userId", userId);
    query.bindValue(":subjectName", subjectName);

    if(!query.exec()) {
        return nullptr;
    }

    Mark *marks = new Mark[query.record().count()];
    while(query.next()) {
        Mark tempMark(query.value("mark_id").toString(), query.value("description").toString(),
                      query.value("grade").toDouble(), query.value("weight").toInt());
        marks[marksCount] = tempMark;
        marksCount++;
    }

    return marks;
}
