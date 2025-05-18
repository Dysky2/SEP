#include "grades.h"
#include "ui_grades.h"

Grades::Grades(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Grades)
{
    ui->setupUi(this);
}

Grades::~Grades()
{
    delete ui;
}
