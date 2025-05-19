#include "subject.h"

Subject::Subject(const QString& name,const QString& teacher){
    this->name=name;
    this->teacher=teacher;
}

Subject::~Subject(){

}

void Subject::setName(const QString& name){
    this->name=name;
}

void Subject::setTeacher(const QString& teacher){
    this->teacher=teacher;
}

QString Subject:: getName()const{
    return name;
}
QString Subject::getTeacher()const{
    return teacher;
}
