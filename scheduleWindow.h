#ifndef SCHEDULEWINDOW_H
#define SCHEDULEWINDOW_H

#include <QMainWindow>

namespace Ui {
class Schedule;
}

class Schedule : public QMainWindow
{
    Q_OBJECT

public:
    explicit Schedule(QWidget *parent = nullptr);
    ~Schedule();

private:
    Ui::Schedule *ui;
};

#endif // SCHEDULEWINDOW_H
