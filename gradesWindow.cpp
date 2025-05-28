#include "gradesWindow.h"
#include "ui_gradesWindow.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>

Grades::Grades(QString userId, QWidget *parent): QMainWindow(parent), ui(new Ui::Grades)  {
    ui->setupUi(this);

    int subjectCount;
    Subject *subjects_names = getAllSubjects(userId, subjectCount);

    QList<QStringList> marksList;
    QStringList subjects;
    for(int i=0;i < subjectCount; i++) {
        subjects.append(subjects_names[i].getName());

        int marksCount;
        Mark* marks = getAllMarksByUserIdAndBySubject(userId, subjects_names[i].getName(), marksCount);

        QStringList tempMarkList;
        for(int j=0; j < marksCount; j++) {
            tempMarkList.append(QString::number(marks[j].getGrade()));
        }
        marksList.append(tempMarkList);
    }

    QTableWidget *table = new QTableWidget(this);
    table->setColumnCount(4);

    QStringList hlabels;
    hlabels << "Przedmioty" << "Oceny" << "Średnia" << "Ocena końcowa";
    table->setHorizontalHeaderLabels(hlabels);

    table->setRowCount(subjects.size());

    for (int row = 0; row < subjects.size(); ++row) {
        // Kolumna z przedmiotem
        table->setItem(row, 0, new QTableWidgetItem(subjects[row]));

        // Kolumna z ocenami
        QWidget *cell = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(cell);
        layout->setSpacing(3);

        for (const QString &mark : marksList[row]) {
            QPushButton *btn = new QPushButton(mark);
            btn->setStyleSheet(
                "QPushButton {"
                "   min-width: 25px; max-width: 25px;"
                "   min-height: 25px; max-height: 25px;"
                "   border: 1px solid #ccc;"
                "   border-radius: 3px;"
                "   background: #f8f8f8;"
                "}"
                "QPushButton:hover {"
                "   background: #e0e0e0;"
                "}"
            );

            layout->addWidget(btn);
        }

        layout->addStretch();
        table->setCellWidget(row, 1, cell);
    }

    this->setCentralWidget(table);
}

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
