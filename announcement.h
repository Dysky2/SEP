#ifndef ANNOUNCEMENT_H
#define ANNOUNCEMENT_H

#include <QString>

class Announcement {
private:
    QString title;
    QString content;
    QString date;
public:
    Announcement(QString title, QString content, QString date);
    ~Announcement();
    void setTitle(QString title);
    void setContent(QString content);
    void setDate(QString date);
    QString getTitle();
    QString getContent();
    QString getDate();
};


#endif // ANNOUNCEMENT_H
