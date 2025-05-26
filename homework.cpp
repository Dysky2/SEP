#include "homework.h"



Homework::Homework(Subject& subject,Teacher& teacher, QString& order, QDate& pubDate, int& numberOfStudents, int& numberOfCompletedTask, QDate& endDate,QString& solution){
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

void Homework::setPubDate(const QDate& pubDate){
    this->pubDate=pubDate;
}

void Homework::setNumberOfStudents(int numberOfStudents){
    this->numberOfStudents=numberOfStudents;
}

void Homework::setNumberOfCompletedTasks(int numberOfCompletedTask){
    this->numberOfCompletedTask=numberOfCompletedTask;
}

void Homework::setEndDate(const QDate& endDate){
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

QDate Homework::getPubDate() const{
    return pubDate;
}

int Homework::getNumberOfStudents() const{
    return numberOfStudents;
}

int Homework::getNumberOfCompletedTask() const{
    return numberOfCompletedTask;
}

QDate Homework::getEndDate() const{
    return endDate;
}
