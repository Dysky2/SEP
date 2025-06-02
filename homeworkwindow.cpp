#include "homeworkWindow.h"
#include "ui_homeworkWindow.h"


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

    connect(addButton, &QPushButton::clicked, this, [this, userId] {
        this->onAddHomeworkClicked(userId);
    });

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

    QList homeworkList = homework->getAllHomework();

    for(int i=0;i < homeworkList.length(); i++) {
        addHomework(homeworkList[i]);
    }

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
         table->setItem(row, 3, new QTableWidgetItem(hw.getPubDate()));
         table->setItem(row, 4, new QTableWidgetItem(QString::number(hw.getNumberOfStudents())));
         table->setItem(row, 5, new QTableWidgetItem(QString::number(hw.getNumberOfCompletedTask())));
         table->setItem(row, 6, new QTableWidgetItem(hw.getEndDate()));
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

void HomeworkWindow::onAddHomeworkClicked(QString userId) {

    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Dodaj zadanie");

    QVBoxLayout *layout = new QVBoxLayout(dialog);

    QLabel *label_day = new QLabel("Przedmiot");
    QComboBox* dayCombo = new QComboBox(this);
    QList subjectList = subject->getAllSubjects();
    for(int i=0; i < subjectList.length(); i++) {
        dayCombo->addItem(subjectList[i].getName());
    }

    QLabel *label_teacher = new QLabel("Nauczyciel");
    QLineEdit *lineEdit_teacher = new QLineEdit();

    QLabel *label_order = new QLabel("Polecenie");
    QLineEdit *lineEdit_order = new QLineEdit();

    QLabel *label_pubDate = new QLabel("Data udostepniona zadania");
    QDateEdit *dateEdit_pubDate = new QDateEdit(this);
    dateEdit_pubDate->setDisplayFormat("dd.MM.yyyy");
    dateEdit_pubDate->setDate(QDate::currentDate());
    dateEdit_pubDate->setCalendarPopup(true);

    QLabel *label_numberOfS = new QLabel("Liczba uczniów");
    QLineEdit *lineEdit_numberOfS = new QLineEdit();

    QLabel *label_endDate = new QLabel("Data udostepniona zadania");
    QDateEdit *dateEdit_endDate = new QDateEdit(this);
    dateEdit_endDate->setDisplayFormat("dd.MM.yyyy");
    dateEdit_endDate->setDate(QDate::currentDate());
    dateEdit_endDate->setCalendarPopup(true);

    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    QPushButton *saveBtn = new QPushButton("Zapisz", dialog);
    QPushButton *cancelBtn = new QPushButton("Anuluj", dialog);

    buttonsLayout->addWidget(saveBtn);
    buttonsLayout->addWidget(cancelBtn);

    layout->addWidget(label_day);
    layout->addWidget(dayCombo);
    layout->addWidget(label_teacher);
    layout->addWidget(lineEdit_teacher);
    layout->addWidget(label_order);
    layout->addWidget(lineEdit_order);
    layout->addWidget(label_pubDate);
    layout->addWidget(dateEdit_pubDate);
    layout->addWidget(label_numberOfS);
    layout->addWidget(lineEdit_numberOfS);
    layout->addWidget(label_endDate);
    layout->addWidget(dateEdit_endDate);
    layout->addLayout(buttonsLayout);

    connect(saveBtn, &QPushButton::clicked, [this, dialog, dayCombo, lineEdit_order, dateEdit_pubDate,lineEdit_numberOfS,
                                            dateEdit_endDate, subjectList, userId] {

        QString orderText = lineEdit_order->text();
        QString numberOfStudetnsText = lineEdit_numberOfS->text();
        QDate pubDate = dateEdit_pubDate->date();
        QDate endDate = dateEdit_endDate->date();

        if(orderText.isEmpty() || numberOfStudetnsText.isEmpty()) {
            QMessageBox::information(this, "Puste Pole", "Pole nie może być puste");
        } else {
            int selectedIndex = dayCombo->currentIndex();

            if(selectedIndex < 0 || selectedIndex >= subjectList.size()) {
                QMessageBox::critical(this, "Błąd", "Nie wybrano przedmiotu");
                return;
            }

            Subject selectedSubject = subjectList.at(selectedIndex);
            User tempUser = getUserById(userId);
            Teacher teacher(userId, tempUser.getName(), tempUser.getSurname(),
                            tempUser.getLocation(), tempUser.getEmail(),
                            tempUser.getPassword(), Role::TEACHER, 1);

            homework->addHomework(selectedSubject, teacher, orderText,pubDate.toString("dd.MM.yyyy"), numberOfStudetnsText.toInt(),0,endDate.toString("dd.MM.yyyy"), "abc");

            Homework newHomework(selectedSubject, teacher, orderText,pubDate.toString("dd.MM.yyyy"), numberOfStudetnsText.toInt(),0,endDate.toString("dd.MM.yyyy"), "abc");

            addHomework(newHomework);
            dialog->close();
        }
    });
    dialog->exec();
}

void HomeworkWindow::onEditHomeworkClicked()
{
    QTableWidget *table = qobject_cast<QTableWidget*>(centralWidget());
    int row = table->currentRow();
    if (row < 0) return;

    AddHomeworkDialog dialog(this);
    Homework& hw = homeworks[row];

    QDate pubDate = QDate::fromString(hw.getPubDate(), "dd.MM.yyyy");
    QDate endDate = QDate::fromString(hw.getEndDate(), "dd.MM.yyyy");

    dialog.setSubject(hw.getSubject().getName());
    dialog.setTeacher(hw.getTeacher().getFullName());
    dialog.setOrder(hw.getOrder());
    dialog.setPubDate(pubDate);
    dialog.setNumberOfStudents(hw.getNumberOfStudents());
    dialog.setEndDate(endDate);

    if (dialog.exec() == QDialog::Accepted) {

        Subject newSubject("TEMP_ID",
                           dialog.getSubject(),
                           "",
                           "TEMP_TEACHER_ID",
                           "TEMP_MARK_LIST");

        QString name = dialog.getTeacher().split(" ")[0];
        QString surname = dialog.getTeacher().split(" ").size() > 1? dialog.getTeacher().split(" ")[1] : "";
        QString id = "TEMP_ID";
        QString location = "";
        Role role = Role::TEACHER;
        QString email = "";
        QString password = "";

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
        hw.setPubDate(dialog.getPubDate().toString("dd.MM.yyyy"));
        hw.setNumberOfStudents(dialog.getNumberOfStudents());
        hw.setEndDate(dialog.getEndDate().toString("dd.MM.yyyy"));

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
            .arg(hw.getEndDate()));
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

