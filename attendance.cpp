#include "attendance.h"
#include "ui_attendance.h"

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
