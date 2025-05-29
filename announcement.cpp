#include "announcement.h"
#include <qsqldatabase.h>

Announcement::Announcement(QString id, QString title, QString content, QString date, QString author) {
    this->id = id;
    this->title = title;
    this->content = content;
    this->date = date;
    this->author=author;
}

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

QList<Announcement> Announcement::getAllAnnouncement() {
    QSqlDatabase db = Database::getInstance().getConnection();
    QList<Announcement> announcmentList;

    if (!db.isOpen()) {
        qDebug() << "Błąd: Połączenie z bazą danych nie jest aktywne!";
        return announcmentList;
    }

    QSqlQuery query(db);
    query.prepare("SELECT * FROM announcement");

    if(!query.exec()) {
        qDebug() << "Błąd wykonania zapytania:" << query.lastError().text();
        return announcmentList;
    }

    while(query.next()) {
        Announcement tempAnnouncement(query.value("id").toString(), query.value("title").toString(), query.value("content").toString(),
                                      query.value("date").toString(), query.value("author").toString());
        announcmentList.append(tempAnnouncement);
    }

    return announcmentList;
}

void Announcement::addAnnouncement(QString id,QString title,QString content,QString date,QString author) {
    QSqlDatabase db = Database::getInstance().getConnection();

    if (!db.isOpen()) {
        qDebug() << "Błąd: Połączenie z bazą danych nie jest aktywne!";
        return;
    }

    QUuid uuid = QUuid::createUuid();
    QString uuidString = uuid.toString().mid(1, 36);

    QSqlQuery query(db);
    query.prepare("INSERT INTO announcement (id,title,content,date,author) VALUES (:id, :title, :content, :date, :author)");
    query.bindValue(":id", uuidString);
    query.bindValue(":title", title);
    query.bindValue(":content", content);
    query.bindValue(":date", date);
    query.bindValue(":author", author);

    if(!query.exec()) {
        qDebug() << "Błąd wykonania zapytania:" << query.lastError().text();
        return ;
    }
}


