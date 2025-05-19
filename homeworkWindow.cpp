#include "homeworkWindow.h"
#include "ui_homeworkWindow.h"

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
