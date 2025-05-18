#ifndef GRADES_H
#define GRADES_H

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

#endif // GRADES_H
