#include "gradesWindow.h"
#include "ui_gradesWindow.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>

Grades::Grades(QString userId, QString userEmail, QWidget *parent): QMainWindow(parent), ui(new Ui::Grades)  {
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

    // QStringList subjects = {"Matma", "Polski", "Angieslki", "Niemiecki", "Biologia", "ASID", "ASO"};
    // QStringList marks = {"1","3","5","3","2","1","6","5","6","3","5","3","3.5","2"};

    QVector<QStringList> allMarks = {
        {"5", "4", "3"},
        {"4", "5", "2", "3"},
        {"5", "5"}
    };

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

    // table->setColumnCount(4);
    // table->setRowCount(subjects.size());

    // for(int i=0; i < table->rowCount(); i++) {
    //     QTableWidgetItem *item;
    //     for(int j=0; j < table->columnCount();j++) {
    //         item = new QTableWidgetItem;

    //         if(j==0) {
    //             item->setText(subjects[i]);
    //         }
    //         if(j==1) {
    //             QWidget * window = new QWidget;

    //             QPushButton *mark1 = new QPushButton("4");
    //             QHBoxLayout *layout = new QHBoxLayout(window);
    //             layout->addWidget(mark1);

    //             item->setText();
    //             QString marksView;
    //             for(int k=0; k < marks.size(); k++) {
    //                 marksView = marksView + QString(marks[k]);
    //                 marksView = marksView + ' ';
    //             }

    //             item->setToolTip("Kliknij aby zobaczyć");
    //             item->setText(marksView);
    //         }
    //         if(j==2) {
    //             item->setText("Test3" + QString::number(i));
    //         }
    //         if(j==3) {
    //             item->setText("Test4" + QString::number(i));
    //         }
    //         table->setItem(i,j,item);
    //     }
    // }
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
