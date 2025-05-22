#include "mark.h"

Mark::Mark() {
    this->description = "Brak obecnosci";
    this->grade = 0.0;
    this->weight = 0;
}
Mark::Mark(QString& description, double grade, int weight) {
    this->description = description;
    this->grade = grade;
    this->weight = weight;
}
Mark::~Mark() {

}
void Mark::setDescription(const QString& description) {
    this->description = description;
}

void Mark::setGrade(double grade) {
    this->grade = grade;
}

void Mark::setWeight(int weight) {
    this->weight = weight;
}

void Mark::setSubject(Subject subject){
    this->subject = subject;
}

QString Mark::getDescription() const {
    return description;
}

double Mark::getGrade() const {
    return grade;
}

int Mark::getWeight() const {
    return weight;
}

Subject Mark::getSubject() const
{
    return Subject();
}
