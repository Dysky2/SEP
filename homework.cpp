#include "homework.h"
#include "ui_homework.h"

Homework::Homework(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Homework)
{
    ui->setupUi(this);
}

Homework::~Homework()
{
    delete ui;
}
