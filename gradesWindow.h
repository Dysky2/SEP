#ifndef GRADESWINDOW_H
#define GRADESWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "mark.h"
#include <QSqlError>

namespace Ui {
class Grades;
}

class Grades : public QMainWindow
{
    Q_OBJECT

public:
    explicit Grades(QString userId, QWidget *parent = nullptr);
    explicit Grades(QWidget *parent = nullptr);
    ~Grades();

private:
    Ui::Grades *ui;
};

#endif // GRADESWINDOW_H
