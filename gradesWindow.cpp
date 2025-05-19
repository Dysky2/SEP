#include "gradesWindow.h"
#include "ui_gradesWindow.h"

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
