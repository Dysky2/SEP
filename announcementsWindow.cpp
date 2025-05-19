#include "announcementsWindow.h"
#include "ui_announcementsWindow.h"

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
