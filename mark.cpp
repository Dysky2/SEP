#include "mark.h"

Mark::Mark(const QString& description, double grade, int weight) {
    this->description=description;
    this->grade=grade;
    this->weight=weight;
}

void Mark::setDescription(const QString& description){
    this->description=description;
}

void Mark::setGrade(double grade){
    this->grade=grade;
}

void Mark::setWeight(int weight){
    this->weight=weight;
}

QString Mark:: getDescription() const{
    return description;
}

double Mark:: getGrade() const{
    return grade;
}

int Mark::getWeight() const{
    return weight;
}
