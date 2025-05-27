#include "announcement.h"


Announcement::Announcement(QString title, QString content, QString date,QString author) {
    this->title = title;
    this->content = content;
    this->date = date;
    this->author=author;
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

void Announcement::setAuthor(QString author){
    this->author=author;
}

QString Announcement::getTitle()const {
    return title;
}

QString Announcement::getContent()const {
    return content;
}

QString Announcement::getDate() const{
    return date;
}

QString Announcement::getAuthor()const{
    return author;
}
