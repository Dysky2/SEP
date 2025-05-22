#include "event.h"

Event::Event(QString title,QString host, QString date, QString time, QString description) {
    this->title = title;
    this->host = host;
    this->date = date;
    this->time = time;
    this->description = description;
}

Event::~Event() {

}

void Event::setTitle(QString title) {
    this->title = title;
}

void Event::setHost(QString host) {
    this->host = host;
}

void Event::setDate(QString date) {
    this->date = date;
}

void Event::setTime(QString time) {
    this->time = time;
}

void Event::setDescription(QString description) {
    this->description = description;
}

QString Event::getTitle() {
    return this->title;
}

QString Event::getHost() {
    return this->host;
}

QString Event::getDate() {
    return this->date;
}

QString Event::getTime() {
    return this->time;
}

QString Event::getDescription() {
    return this->description;
}

