#ifndef EVENT_H
#define EVENT_H

#include <QString>

class Event {
private:
    QString title;
    QString host;
    QString date;
    QString time;
    QString description;
public:
    Event(QString title,QString host, QString date, QString time, QString description);
    ~Event();
    void setTitle(QString title);
    void setHost(QString host);
    void setDate(QString date);
    void setTime(QString time);
    void setDescription(QString description);
    QString getTitle();
    QString getHost();
    QString getDate();
    QString getTime();
    QString getDescription();
};

#endif
