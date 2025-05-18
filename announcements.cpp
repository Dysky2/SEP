#include "announcements.h"
#include "ui_announcements.h"

Announcements::Announcements(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Announcements)
{
    ui->setupUi(this);
}

Announcements::~Announcements()
{
    delete ui;
}
