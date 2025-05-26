// homeworkWindow.cpp
#include "homeworkWindow.h"
#include "ui_homeworkWindow.h"
#include "addHomeworkDialog.h"
#include <QHBoxLayout>
#include <QToolButton>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QToolBar>
#include <QTextEdit>
#include "homeworkWindow.h"
#include "homework.h"
#include "teacher.h"
#include "subject.h"
#include <QDebug>
#include "database.h"

HomeworkWindow::HomeworkWindow(QString& userId,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeworkWindow)
{
    ui->setupUi(this);
    this->userId=userId;

    QString role = getUserById(this->userId).getRole();
    const bool isPrivileged = (role == "ADMIN" || role =="MOD" || role =="TEACHER");
    //const bool isPrivileged =1;

    QPushButton *addButton = new QPushButton(tr("Dodaj zadanie"), this);
    addButton->setVisible(isPrivileged);
    connect(addButton, &QPushButton::clicked, this, &HomeworkWindow::onAddHomeworkClicked);
    QToolBar *toolBar = addToolBar(tr("Main Toolbar"));
    toolBar->addWidget(addButton);

    QTableWidget *table = new QTableWidget(this);
    table->setColumnCount(8);
    table->setHorizontalHeaderLabels({
        tr("Przedmiot"), tr("Nauczyciel"), tr("Polecenie"),
        tr("Data dodania"), tr("Liczba uczniów"), tr("Ukończone"),
        tr("Termin"), tr("Akcja")
    });

    table->setStyleSheet("QTableWidget { font-size: 12px; }");
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setAlternatingRowColors(true);

    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    table->setColumnWidth(0, 120);  // Przedmiot
    table->setColumnWidth(1, 150);  // Nauczyciel
    table->setColumnWidth(2, 250);  // Polecenie
    table->setColumnWidth(3, 100);  // Data dodania
    table->setColumnWidth(4, 100);  // Liczba uczniów
    table->setColumnWidth(5,  80);  // Ukończone
    table->setColumnWidth(6, 100);  // Termin

    table->horizontalHeader()->setStretchLastSection(true);

    table->verticalHeader()->setVisible(false);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    setCentralWidget(table);
}

HomeworkWindow::~HomeworkWindow()
{
    delete ui;
}

void HomeworkWindow::addHomework(const Homework &newHomework)
{
    homeworks.append(newHomework);
    updateTable();
}

void HomeworkWindow::updateTable()
{
     QSqlDatabase db = Database::getInstance().getConnection();
     QTableWidget *table = qobject_cast<QTableWidget*>(centralWidget());
     table->setRowCount(homeworks.size());


     const QString role = getUserById(this->userId).getRole();
     const bool isPrivileged = (role == "ADMIN" || role =="MOD" || role =="TEACHER");

     //const bool isPrivileged =1;
     for (int row = 0; row < homeworks.size(); ++row) {
         const Homework &hw = homeworks[row];

         table->setItem(row, 0, new QTableWidgetItem(hw.getSubject().getName()));
         table->setItem(row, 1, new QTableWidgetItem(hw.getTeacher().getFullName()));
         table->setItem(row, 2, new QTableWidgetItem(hw.getOrder()));
         table->setItem(row, 3, new QTableWidgetItem(hw.getPubDate().toString("dd.MM.yyyy")));
         table->setItem(row, 4, new QTableWidgetItem(QString::number(hw.getNumberOfStudents())));
         table->setItem(row, 5, new QTableWidgetItem(QString::number(hw.getNumberOfCompletedTask())));
         table->setItem(row, 6, new QTableWidgetItem(hw.getEndDate().toString("dd.MM.yyyy")));
         QWidget *actionWidget = new QWidget(this);
         auto *layout = new QHBoxLayout(actionWidget);
         layout->setContentsMargins(0,0,0,0);
         layout->setSpacing(4);

         QToolButton *editBtn = new QToolButton(this);
         editBtn->setText(tr("Edytuj"));
         editBtn->setVisible(isPrivileged);
         connect(editBtn, &QToolButton::clicked, this, [this, row]() {
             qobject_cast<QTableWidget*>(centralWidget())->selectRow(row);
             onEditHomeworkClicked();
        });
         layout->addWidget(editBtn);

         QToolButton *delBtn = new QToolButton(this);
         delBtn->setText(tr("Usuń"));
         delBtn->setVisible(isPrivileged);
         connect(delBtn, &QToolButton::clicked, this, [this, row]() {
             qobject_cast<QTableWidget*>(centralWidget())->selectRow(row);
             onDeleteHomeworkClicked();
         });
         layout->addWidget(delBtn);

         QToolButton *submitBtn = new QToolButton(this);
         submitBtn->setText(tr("Oddaj"));
         submitBtn->setVisible(!isPrivileged);
         connect(submitBtn, &QToolButton::clicked, this, [this, row]() {
             qobject_cast<QTableWidget*>(centralWidget())->selectRow(row);
             onAddSolutionClicked();
         });
         layout->addWidget(submitBtn);

         QToolButton *previewBtn = new QToolButton(this);
         previewBtn->setText(tr("Podgląd"));
         connect(previewBtn, &QToolButton::clicked, this, [this, row]() {
             onPreviewHomeworkClicked(row);
         });
         layout->addWidget(previewBtn);

         table->setCellWidget(row, 7, actionWidget);
     }
}

void HomeworkWindow::onAddHomeworkClicked()
{
    AddHomeworkDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        // Tworzenie obiektów Subject i Teacher
        Subject subject("TEMP_ID", dialog.getSubject(), "", "TEMP_TEACHER_ID", "TEMP_MARK_LIST");


        QString name = dialog.getTeacher().split(" ")[0];
        QString surname = dialog.getTeacher().split(" ").size() > 1? dialog.getTeacher().split(" ")[1] : "";
        QString id = "TEMP_ID";
        QString location = "";
        Role role = Role::TEACHER;
        QString email = "";
        QString password = "";

        //tymczasowe - usunac po zrobieniu bazy
        Teacher teacher(
            id,
            name,
            surname,
            location,
            email,
            password,
            role,
            true
            );


        QString orderText = dialog.getOrder();
        QDate pubDate = dialog.getPubDate();
        int studentCount = dialog.getNumberOfStudents();
        int completedCount = 0;
        QDate endDate = dialog.getEndDate();
        QString solution = "";

        Homework newHomework(
            subject,
            teacher,
            orderText,
            pubDate,
            studentCount,
            completedCount,
            endDate,
            solution
            );

        addHomework(newHomework);
    }
}

void HomeworkWindow::onEditHomeworkClicked()
{
    QTableWidget *table = qobject_cast<QTableWidget*>(centralWidget());
    int row = table->currentRow();
    if (row < 0) return;

    AddHomeworkDialog dialog(this);
    Homework& hw = homeworks[row];

    // Wypełniamy dialog bieżącymi danymi
    dialog.setSubject(hw.getSubject().getName());
    dialog.setTeacher(hw.getTeacher().getFullName());
    dialog.setOrder(hw.getOrder());
    dialog.setPubDate(hw.getPubDate());
    dialog.setNumberOfStudents(hw.getNumberOfStudents());
    dialog.setEndDate(hw.getEndDate());

    if (dialog.exec() == QDialog::Accepted) {

        Subject newSubject("TEMP_ID",
                           dialog.getSubject(),
                           "",
                           "TEMP_TEACHER_ID",
                           "TEMP_MARK_LIST");

        // Nowy nauczyciel
        QString name = dialog.getTeacher().split(" ")[0];
        QString surname = dialog.getTeacher().split(" ").size() > 1? dialog.getTeacher().split(" ")[1] : "";
        QString id = "TEMP_ID";
        QString location = "";
        Role role = Role::TEACHER;
        QString email = "";
        QString password = "";

        //tymczasowe - usunac po zrobieniu bazy
        Teacher teacher(
            id,
            name,
            surname,
            location,
            email,
            password,
            role,
            true
            );

        hw.setSubject(newSubject);
        hw.setTeacher(teacher);
        hw.setOrder(dialog.getOrder());
        hw.setPubDate(dialog.getPubDate());
        hw.setNumberOfStudents(dialog.getNumberOfStudents());
        hw.setEndDate(dialog.getEndDate());

        updateTable();
    }
}

void HomeworkWindow::onDeleteHomeworkClicked()
{
    QTableWidget *table = qobject_cast<QTableWidget*>(centralWidget());
    int row = table->currentRow();
    if (row < 0) return;

    if (QMessageBox::question(this, tr("Potwierdzenie"),
                              tr("Czy na pewno usunąć zadanie?"),
                              QMessageBox::Yes | QMessageBox::No)
        == QMessageBox::Yes) {
        homeworks.removeAt(row);
        updateTable();
    }
}

void HomeworkWindow::onAddSolutionClicked()
{
    QTableWidget *table = qobject_cast<QTableWidget*>(centralWidget());
    int row = table->currentRow();
    if (row < 0) return;

    const QString oldSol = homeworks[row].getSolution();
    bool ok;
    QString sol = QInputDialog::getMultiLineText(this,
                                                 tr("Rozwiązanie zadania"),
                                                 tr("Wpisz rozwiązanie:"),
                                                 oldSol,
                                                 &ok);
    if (ok && !sol.isEmpty()) {
        homeworks[row].setSolution(sol);
        if (oldSol.isEmpty())
            homeworks[row].setNumberOfCompletedTasks(homeworks[row].getNumberOfCompletedTask() + 1);
        updateTable();
    }
}

void HomeworkWindow::onPreviewHomeworkClicked(int row)
{
    if (row < 0 || row >= homeworks.size()) return;

    const Homework& hw = homeworks[row];
    const QString& sol = hw.getSolution();

    QDialog previewDialog(this);
    previewDialog.setWindowTitle(tr("Rozwiązanie zadania - %1").arg(hw.getTeacher().getFullName()));

    QVBoxLayout *layout = new QVBoxLayout(&previewDialog);

    QLabel *infoLabel = new QLabel(
        tr("<b>Przedmiot:</b> %1<br>"
           "<b>Nauczyciel:</b> %2<br>"
           "<b>Termin:</b> %3")
            .arg(hw.getSubject().getName())
            .arg(hw.getTeacher().getFullName())
            .arg(hw.getEndDate().toString("dd.MM.yyyy")));
    layout->addWidget(infoLabel);

    QTextEdit *solutionEdit = new QTextEdit();
    solutionEdit->setPlainText(sol);
    solutionEdit->setReadOnly(true);
    layout->addWidget(solutionEdit);

    QPushButton *closeButton = new QPushButton(tr("Zamknij"));
    connect(closeButton, &QPushButton::clicked, &previewDialog, &QDialog::accept);
    layout->addWidget(closeButton);

    previewDialog.exec();
}

