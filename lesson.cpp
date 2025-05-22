#include "lesson.h"

Lesson::Lesson(QString name, QString date, QString teacher, Subject subject) {
    this->name = name;
    this->date = date;
    this->teacher = teacher;
    this->subject = subject;

}
Lesson::~Lesson() {
}
void Lesson::setName(QString name) {
    this->name = name;
}
void Lesson::setDate(QString date) {
    this->date = date;
}
void Lesson::setTeacher(QString teacher) {
    this->teacher = teacher;
}
void Lesson::setSubject(Subject subject) {
    this->subject = subject;
}

QString Lesson::getName() const {
    return name;
}
QString Lesson::getDate() const {
    return date;
}
QString Lesson::getTeacher()const{
    return teacher;
}
Subject Lesson::getSubject() const {
    return subject;
}
//
//void Lesson::excuseAbsence(int studentIndex, const QString& reason) {
//    if (studentIndex >= 0 && studentIndex < attendance.size()) {
//        if (attendance[studentIndex] == AttendanceStatus::ABSENT) {
//            attendance[studentIndex] = AttendanceStatus::EXCUSED;
//            excuses[studentIndex] = reason;
//        }
//        else {
//            cout << "Uwaga: Tylko nieobecności można usprawiedliwić!" << endl;
//        }
//    }
//    else {
//        cout << "Nieprawidłowy indeks studenta!" << endl;
//    }
//}
//
//void Lesson::removeExcuse(int studentIndex) {
//    if (excuses.count(studentIndex)) {
//        if (attendance[studentIndex] == AttendanceStatus::EXCUSED) {
//            attendance[studentIndex] = AttendanceStatus::ABSENT;
//        }
//        excuses.erase(studentIndex);
//    }
//}
//
//void Lesson::displayAttendance() const {
//    cout << "Frekwencja dla lekcji: " << name << " (" << date << ")" << endl;
//    for (size_t i = 0; i < attendance.size(); ++i) {
//        cout << "Student " << i + 1 << ": ";
//        switch (attendance[i]) {
//        case AttendanceStatus::PRESENT:
//            cout << "Obecny";
//            break;
//        case AttendanceStatus::ABSENT:
//            cout << "Nieobecny";
//            break;
//        case AttendanceStatus::LATE:
//            cout << "Spóźniony";
//            break;
//        case AttendanceStatus::EXCUSED:
//            cout << "Usprawiedliwiony (powód: " << excuses.at(i) << ")";
//            break;
//        }
//        cout << endl;
//    }
//}
//
//QString Lesson::getExcuse(int studentIndex) const {
//    if (excuses.count(studentIndex)) {
//        return excuses.at(studentIndex);
//    }
//    return "";
//}
//
//bool Lesson::isExcused(int studentIndex) const {
//    return (studentIndex >= 0 && studentIndex < attendance.size()) &&
//        (attendance[studentIndex] == AttendanceStatus::EXCUSED);
//}
//
//size_t Lesson::getAttendanceCount() const {
//	return attendance.size();
//}
