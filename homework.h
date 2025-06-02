#ifndef HOMEWORK_H
#define HOMEWORK_H

#include "subject.h"
#include "teacher.h"
#include <QString>
#include <QDate>

class Homework
{
private:
    QString id;
    Subject subject;
    Teacher teacher;
    QString order;
    QString pubDate;
    int numberOfStudents;
    int numberOfCompletedTask;
    QString endDate;
    QString solution;

public:
    Homework(QString id, Subject subject, Teacher teacher,
             QString order, QString pubDate, int numberOfStudents,
             int numberOfCompletedTask, QString endDate, QString solution);


    Homework(Subject& subject,Teacher& teacher, QString& order, QString& pubDate, int& numberOfStudents, int& numberOfCompletedTask, QString& endDate,QString& solution);
    Homework(Subject subject,Teacher teacher, QString order, QString pubDate, int numberOfStudents, int numberOfCompletedTask, QString endDate,QString solution);

    void setSolution(const QString& solution);
    void setSubject(Subject& subject);
    void setTeacher(Teacher& teacher);
    void setOrder(const QString& order);
    void setPubDate(const QString& pubDate);
    void setNumberOfStudents(int numberOfStudents);
    void setNumberOfCompletedTasks(int numberOfCompletedTask);
    void setEndDate(const QString& endDate);

    QString getSolution() const;
    Subject getSubject() const;
    Teacher getTeacher() const;
    QString getOrder() const;
    QString getPubDate() const;
    int getNumberOfStudents() const;
    int getNumberOfCompletedTask() const;
    QString getEndDate() const;

    QList<Homework> getAllHomework();
    void addHomework(Subject subject,Teacher teacher, QString order, QString pubDate,
                         int numberOfStudents, int numberOfCompletedTask, QString endDate,QString solution);
};

#endif
