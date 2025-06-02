#ifndef ANNOUNCEMENT_H
#define ANNOUNCEMENT_H

#include <QString>
#include <QList>
#include "database.h"
#include <QSqlDatabase>
#include <QUuid>

class Announcement {
private:
    QString id;
    QString title;
    QString content;
    QString date;
    QString author;
public:
    Announcement(QString id, QString title, QString content, QString date,QString author);
    Announcement(QString title, QString content, QString date,QString author);
    ~Announcement();
    void setTitle(QString title);
    void setContent(QString content);
    void setDate(QString date);
    void setAuthor(QString author);
    QString getTitle()const;
    QString getContent()const;
    QString getDate()const;
    QString getAuthor()const;

    QList<Announcement> getAllAnnouncement();
    void addAnnouncement(QString id,QString title,QString content,QString date,QString author);
};


#endif
