#include "schedulewindow.h"
#include "ui_schedulewindow.h"

QString months[12] = {"Styczeń", "Luty", "Marzec", "Kwiecień", "Maj", "Czerwiec", "Lipiec", "Sierpień", "Wrzesień", "Październik", "Listopad", "Grudzień"};


ScheduleWindow::ScheduleWindow(QString& userId, QWidget *parent): QMainWindow(parent), ui(new Ui::ScheduleWindow) {
    ui->setupUi(this);

    calendar = new Calendar(userId, this);

    ui->label_monthName->setText(months[calendar->getCurrenDate().month() - 1]);
    ui->label_year->setText(QString::number(calendar->getCurrenDate().year()));
    ui->gridLayout_calendar->addWidget(calendar->getWidget(), 0, 0);
}

ScheduleWindow::ScheduleWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ScheduleWindow)
{
    ui->setupUi(this);
}

ScheduleWindow::~ScheduleWindow()
{
    delete ui;
}

void ScheduleWindow::on_pushButton_nextMonth_clicked() {
    calendar->nextMonth();
    ui->label_monthName->setText(months[calendar->getCurrenDate().month() - 1]);
    ui->label_year->setText(QString::number(calendar->getCurrenDate().year()));
    ui->gridLayout_calendar->addWidget(calendar->getWidget(), 0, 0);
}


void ScheduleWindow::on_pushButton_previousMonth_clicked() {
    if(calendar->getCurrenDate().month() > QDate::currentDate().month() || calendar->getCurrenDate().year() > QDate::currentDate().year()) {
        calendar->previousMonth();
        ui->label_monthName->setText(months[calendar->getCurrenDate().month() - 1]);
        ui->label_year->setText(QString::number(calendar->getCurrenDate().year()));
        ui->gridLayout_calendar->addWidget(calendar->getWidget(), 0, 0);
    }
}

