#ifndef ATTENDANCEWINDOW_H
#define ATTENDANCEWINDOW_H

#include <QMainWindow>

namespace Ui {
class Attendance;
}

class Attendance : public QMainWindow
{
    Q_OBJECT

public:
    explicit Attendance(QWidget *parent = nullptr);
    ~Attendance();

private:
    Ui::Attendance *ui;
};

#endif // ATTENDANCEWINDOW_H
