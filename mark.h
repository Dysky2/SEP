#ifndef MARK_H
#define MARK_H

#include <QString>

class Mark {
private:
    QString description;
    double grade;
    int weight;
public:
    Mark(QString description, double grade, int weight);
};

#endif // MARK_H
