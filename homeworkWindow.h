#ifndef HOMEWORKWINDOW_H
#define HOMEWORKWINDOW_H

#include <QMainWindow>

namespace Ui {
class Homework;
}

class Homework : public QMainWindow
{
    Q_OBJECT

public:
    explicit Homework(QWidget *parent = nullptr);
    ~Homework();

private:
    Ui::Homework *ui;
};

#endif // HOMEWORKWINDOW_H
