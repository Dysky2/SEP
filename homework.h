#ifndef HOMEWORK_H
#define HOMEWORK_H

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

#endif // HOMEWORK_H
