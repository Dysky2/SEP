#include "addHomeworkDialog.h"

AddHomeworkDialog::AddHomeworkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddHomeworkDialog)
{
    ui->setupUi(this);


    ui->dateEdit_pubDate->setDate(QDate::currentDate());
    ui->dateEdit_endDate->setDate(QDate::currentDate().addDays(7));
    ui->dateEdit_pubDate->setDisplayFormat("dd.MM.yyyy");
    ui->dateEdit_endDate->setDisplayFormat("dd.MM.yyyy");
}

AddHomeworkDialog::~AddHomeworkDialog()
{
    delete ui;
}

QString AddHomeworkDialog::getSubject() const {
    return ui->lineEdit_subject->text();
}

QString AddHomeworkDialog::getTeacher() const {
    return ui->lineEdit_teacher->text();
}

QString AddHomeworkDialog::getOrder() const {
    return ui->lineEdit_order->text();
}

QDate AddHomeworkDialog::getPubDate() const {
    return ui->dateEdit_pubDate->date();
}

int AddHomeworkDialog::getNumberOfStudents() const {
    return ui->lineEdit_numberOfStudents->text().toInt();
}

int AddHomeworkDialog::getNumberOfCompletedTasks() const {
    return ui->lineEdit_numberOfCompletedTask->text().toInt();
}

QDate AddHomeworkDialog::getEndDate() const {
    return ui->dateEdit_endDate->date();
}

void AddHomeworkDialog::setSubject(const QString& subject) {
    ui->lineEdit_subject->setText(subject);
}

void AddHomeworkDialog::setTeacher(const QString& teacher) {
    ui->lineEdit_teacher->setText(teacher);
}

void AddHomeworkDialog::setOrder(const QString& order) {
    ui->lineEdit_order->setText(order);
}

void AddHomeworkDialog::setPubDate(const QDate& date) {
    ui->dateEdit_pubDate->setDate(date);
}

void AddHomeworkDialog::setNumberOfStudents(int count) {
    ui->lineEdit_numberOfStudents->setText(QString::number(count));
}

void AddHomeworkDialog::setNumberOfCompletedTasks(int count) {
    ui->lineEdit_numberOfCompletedTask->setText(QString::number(count));
}

void AddHomeworkDialog::setEndDate(const QDate& date) {
    ui->dateEdit_endDate->setDate(date);
}
