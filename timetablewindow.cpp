#include "timetablewindow.h"
#include "ui_timetablewindow.h"

TimeTableWindow::TimeTableWindow(QString userID, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TimeTableWindow)
    , weeklyCalendar(nullptr)
{
    ui->setupUi(this);

    QTableWidget *tableWidget = ui->tableWidget;
    weeklyCalendar.createWeekCalendar(tableWidget);
}

TimeTableWindow::TimeTableWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TimeTableWindow)
    , weeklyCalendar(nullptr)
{
    ui->setupUi(this);
}

TimeTableWindow::~TimeTableWindow()
{
    delete ui;
}

void TimeTableWindow::on_pushButton_clicked() {
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Dodaj zajecia do planu");

    QStringList daysOfWeek = weeklyCalendar.getDayOfWeek();
    QStringList hours = weeklyCalendar.createListOfHours(8, 21);

    QVBoxLayout *layout = new QVBoxLayout(dialog);

    QLabel *label_day = new QLabel("Podaj dzien");
    QComboBox* dayCombo = new QComboBox(this);
    for(int i=0; i< daysOfWeek.length(); i++) {
        dayCombo->addItem(daysOfWeek[i]);
    }

    QLabel *label_hour = new QLabel("Podaj godzine");
    QComboBox* timeCombo = new QComboBox(this);
    for(int i=0; i< hours.length(); i++) {
        timeCombo->addItem(hours[i]);
    }

    QLabel *label_time_activities = new QLabel("Podaj ile będą trwały zajęcia");
    QComboBox* timeActivitiesCombo = new QComboBox(this);

    QStringList activitiesHours = weeklyCalendar.createListOfHours(0, 5);
    for(int i=0; i < activitiesHours.length();i++) {
        timeActivitiesCombo->addItem(activitiesHours[i]);
    }

    QLabel *label_lessonText = new QLabel("Podaj nazwe zajęć");
    QTextEdit *textEdit = new QTextEdit();

    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    QPushButton *saveBtn = new QPushButton("Zapisz", dialog);
    QPushButton *cancelBtn = new QPushButton("Anuluj", dialog);
    

    buttonsLayout->addWidget(saveBtn);
    buttonsLayout->addWidget(cancelBtn);

    layout->addWidget(label_day);
    layout->addWidget(dayCombo);
    layout->addWidget(label_hour);
    layout->addWidget(timeCombo);
    layout->addWidget(label_time_activities);
    layout->addWidget(timeActivitiesCombo);
    layout->addWidget(label_lessonText);
    layout->addWidget(textEdit);
    layout->addLayout(buttonsLayout);

    connect(saveBtn, &QPushButton::clicked, [this, dialog, dayCombo, timeCombo, timeActivitiesCombo, textEdit] {
        if(textEdit->toPlainText().isEmpty()) {
            QMessageBox::information(this, "Puste Pole", "Pole nie może być puste");
        } else {
            bool exists = timeTable.existActivitiesOnThisDate(dayCombo->currentText(), timeCombo->currentText(), timeActivitiesCombo->currentText());

            if(!exists) {
                weeklyCalendar.insertIntoWeekCalendar(ui->tableWidget, dayCombo->currentText(), timeCombo->currentText(),
                                                      timeActivitiesCombo->currentText(), textEdit->toPlainText() );
                timeTable.addTimeTable("", dayCombo->currentText(), timeCombo->currentText(),
                                       timeActivitiesCombo->currentText(), textEdit->toPlainText());

                QMessageBox::information(this, "Dodanie zajęć", "Pomyślnie dodano zajęcia");
                dialog->close();
            } else {
                QMessageBox::information(this, "Dodanie zajęć niemożliwe", "Podana data jest już zajęta");
            }
        }
    });

    connect(cancelBtn, &QPushButton::clicked, [dialog] {
        dialog->close();
    });

    dialog->exec();
}


