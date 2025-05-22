#include "announcement.h"


Announcement::Announcement(QString title, QString content, QString date) {
    this->title = title;
    this->content = content;
    this->date = date;
}

Announcement::~Announcement() {
}

void Announcement::setTitle(QString title) {
    this->title = title;
}

void Announcement::setContent(QString content) {
    this->content = content;
}

void Announcement::setDate(QString date) {
    this->date = date;
}

QString Announcement::getTitle() {
    return title;
}

QString Announcement::getContent() {
    return content;
}

QString Announcement::getDate() {
    return date;
}

