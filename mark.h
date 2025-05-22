#ifndef MARK_H
#define MARK_H

#include <QString>
#include "subject.h"

class Mark {
private:
    QString description;
    double grade;
    int weight;
    Subject subject;

public:
    Mark();
    Mark(QString& description, double grade, int weight);
    ~Mark();

    void setDescription(const QString& description);
    void setGrade(double grade);
    void setWeight(int weight);
    void setSubject(Subject subject);

    QString getDescription() const;
    double getGrade() const;
    int getWeight() const;
    Subject getSubject() const;
};


#endif // MARK_H
