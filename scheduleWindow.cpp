#include "scheduleWindow.h"
#include "ui_scheduleWindow.h"

Schedule::Schedule(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Schedule)
{
    ui->setupUi(this);
}

Schedule::~Schedule()
{
    delete ui;
}
