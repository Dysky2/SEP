#ifndef HOMEWORK_H
#define HOMEWORK_H

#include "subject.h"
#include "teacher.h"
#include <QString>
#include <QDate>

class Homework
{
private:
    Subject subject;
    Teacher teacher;
    QString order;
    QDate pubDate;
    int numberOfStudents;
    int numberOfCompletedTask;
    QDate endDate;
    QString solution;

public:
    Homework(Subject& subject,Teacher& teacher, QString& order, QDate& pubDate, int& numberOfStudents, int& numberOfCompletedTask, QDate& endDate,QString& solution);

    void setSolution(const QString& solution);
    void setSubject(Subject& subject);
    void setTeacher(Teacher& teacher);
    void setOrder(const QString& order);
    void setPubDate(const QDate& pubDate);
    void setNumberOfStudents(int numberOfStudents);
    void setNumberOfCompletedTasks(int numberOfCompletedTask);
    void setEndDate(const QDate& endDate);

    QString getSolution() const;
    Subject getSubject() const;
    Teacher getTeacher() const;
    QString getOrder() const;
    QDate getPubDate() const;
    int getNumberOfStudents() const;
    int getNumberOfCompletedTask() const;
    QDate getEndDate() const;
};

#endif // HOMEWORK_H
