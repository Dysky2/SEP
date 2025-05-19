#include "attendanceWindow.h"
#include "ui_attendanceWindow.h"

Attendance::Attendance(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Attendance)
{
    ui->setupUi(this);
}

Attendance::~Attendance()
{
    delete ui;
}
