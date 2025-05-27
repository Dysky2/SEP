#ifndef ANNOUNCEMENT_H
#define ANNOUNCEMENT_H

#include <QString>

class Announcement {
private:
    QString title;
    QString content;
    QString date;
    QString author;
public:
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
};


#endif // ANNOUNCEMENT_H
