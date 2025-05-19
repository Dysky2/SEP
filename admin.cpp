#include "admin.h"
#include "subject.h"
#include "mark.h"

Admin::Admin(QString &name, QString &surname, QString &id, QString &location,QString &role,
             QString &email, QString &password, QString &faculty):User(name, surname, id, location, role, email, password){
    this->faculty=faculty;
}

void Admin::setFaculty(QString &faculty){
    this->faculty=faculty;
}

Subject Admin::createSubject(const QString& subname,const QString& teacher){
    return Subject(subname,teacher);
}

void Admin::editSubject(const QString& newName, const QString& newTeacher) {

    // Wyświetl stare wartości
   // QDebug() << "Stare dane:";
    //QDebug() << "Nazwa:" << subject.getName();
    //QDebug() << "Nauczyciel:" << subject.getTeacher();

    // Zaktualizuj wartości
    //Subject.setName(newName);
   // Subject.setTeacher(newTeacher);

        // Wyświetl nowe wartości
    //QDebug() << "Nowe dane:";
   // QDebug() << "Nazwa:" << subject.getName();
    //QDebug() << "Nauczyciel:" << subject.getTeacher();

}

void Admin::deleteSubject(){

}

void Admin::addRole(){
    //potrzebne ui
}

void Admin::deleteRole(){

}

void Admin::acceptApplication(){

}

void Admin::rejectApplication(){

}

Mark Admin::addMark(QString& description, double grade, int weight){
    return Mark(description, grade, weight);
}

void Admin::editMark(){

}

void Admin::deleteMark(){

}

void Admin::addEvent(){

}

void Admin::editEvent(){

}

void Admin::deleteEvent(){

}

void Admin::addLesson(){

}

void Admin::editLesson(){

}

void Admin::deleteLesson(){

}

void Admin::checkAttendance(){

}

void Admin::editAttendance(){

}

void Admin::writeAnnouncement(){

}

void Admin::editAnnouncement(){

}

void Admin::deleteAnnouncement(){

}

QString Admin::getFaculty(){
    return faculty;
}


