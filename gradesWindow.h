#ifndef GRADESWINDOW_H
#define GRADESWINDOW_H

#include <QMainWindow>

namespace Ui {
class Grades;
}

class Grades : public QMainWindow
{
    Q_OBJECT

public:
    explicit Grades(QWidget *parent = nullptr);
    ~Grades();

private:
    Ui::Grades *ui;
};

#endif // GRADESWINDOW_H
