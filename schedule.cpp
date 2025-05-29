#include "schedule.h"

Schedule::Schedule(QString id, QString text, QString author_id, QDate date) {
    this->id = id;
    this->text = text;
    this->author_id = author_id;
    this->date = date;
}

QString Schedule::getText() {
    return this->text;
}

QDate Schedule::getDate() {
    return this->date;
}

Schedule::Schedule() {}
