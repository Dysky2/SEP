#ifndef MARK_H
#define MARK_H

#include <QString>
#include "subject.h"
#include "database.h"
#include <QSqlRecord>

class Mark {
private:
    QString mark_id;
    QString description;
    double grade;
    int weight;

public:
    Mark();
    Mark(QString mark_id, QString description, double grade, int weight);
    ~Mark();

    void setDescription(const QString& description);
    void setGrade(double grade);
    void setWeight(int weight);

    QString getDescription() const;
    double getGrade() const;
    int getWeight() const;
};

Mark* getAllMarksByUserIdAndBySubject(QString userId, QString subjectName, int& marksCount);

#endif // MARK_H
