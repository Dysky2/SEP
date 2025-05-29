#ifndef ADDHOMEWORKDIALOG_H
#define ADDHOMEWORKDIALOG_H

#include <QDialog>
#include "homework.h"

namespace Ui {
class AddHomeworkDialog;
}

class AddHomeworkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddHomeworkDialog(QWidget *parent = nullptr);
    ~AddHomeworkDialog();

    QString getSubject() const;
    QString getTeacher() const;
    QString getOrder() const;
    QDate getPubDate() const;
    int getNumberOfStudents() const;
    int getNumberOfCompletedTasks() const;
    QDate getEndDate() const;

    void setSubject(const QString& subject);
    void setTeacher(const QString& teacher);
    void setOrder(const QString& order);
    void setPubDate(const QDate& date);
    void setEndDate(const QDate& date);
    void setNumberOfStudents(int count);
    void setNumberOfCompletedTasks(int count);

private:
    Ui::AddHomeworkDialog *ui;
};

#endif // ADDHOMEWORKDIALOG_H
