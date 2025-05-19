#ifndef MARK_H
#define MARK_H

#include <QString>

class Mark {
private:
    QString description;
    double grade;
    int weight;
public:
    Mark(const QString& description, double grade, int weight);
    ~Mark();

    void setDescription(const QString& description);
    void setGrade(double grade);
    void setWeight(int weight);

    QString getDescription() const;
    double getGrade() const;
    int getWeight() const;
};

#endif // MARK_H
