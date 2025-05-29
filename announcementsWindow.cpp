#include "announcementswindow.h"


AnnouncementsWindow::AnnouncementsWindow(const QString& userId, QWidget *parent)
    : QMainWindow(parent), userId(userId)
{
    setupTable();
    setupToolbar();
    setWindowTitle("Ogłoszenia");
    resize(800, 600);
}

AnnouncementsWindow::~AnnouncementsWindow()
{
}

bool AnnouncementsWindow::isUserPrivileged() const
{
    QString role = getUserById(this->userId).getRole();
    return (role == "ADMIN" || role == "MOD" || role == "TEACHER");
}

void AnnouncementsWindow::setupToolbar()
{
    QToolBar *toolBar = addToolBar("Main Toolbar");

    addButton = new QPushButton("Dodaj ogłoszenie", this);
    addButton->setVisible(isUserPrivileged());
    connect(addButton, &QPushButton::clicked, this, &AnnouncementsWindow::onAddAnnouncementClicked);

    toolBar->addWidget(addButton);
}

void AnnouncementsWindow::setupTable()
{
    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(4);
    tableWidget->setHorizontalHeaderLabels({"Tytuł", "Autor", "Data", "Akcje"});

    tableWidget->setColumnWidth(0, 300);
    tableWidget->setColumnWidth(1, 200);
    tableWidget->setColumnWidth(2, 100);
    tableWidget->horizontalHeader()->setStretchLastSection(true);

    QList announcmentList = announcement->getAllAnnouncement();

    for(int i=0;i < announcmentList.length(); i++) {
        addAnnouncement(announcmentList[i]);
    }

    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->setAlternatingRowColors(true);

    tableWidget->setColumnHidden(3, !isUserPrivileged());

    setCentralWidget(tableWidget);
}

void AnnouncementsWindow::addAnnouncement(const Announcement &newAnnouncement)
{
    announcements.append(newAnnouncement);
    updateTable();
}

void AnnouncementsWindow::updateTable()
{
    const bool isPrivileged = isUserPrivileged();
    tableWidget->setRowCount(announcements.size() * 2);

    tableWidget->setColumnHidden(3, !isPrivileged);

    for (int i = 0; i < announcements.size(); ++i) {
        const Announcement &ann = announcements[i];
        int contentRow = i * 2 + 1;

        tableWidget->setItem(i * 2, 0, new QTableWidgetItem(ann.getTitle()));
        tableWidget->setItem(i * 2, 1, new QTableWidgetItem(ann.getAuthor()));
        tableWidget->setItem(i * 2, 2, new QTableWidgetItem(ann.getDate()));

        if (isPrivileged) {
            QWidget *actionWidget = new QWidget();
            QHBoxLayout *layout = new QHBoxLayout(actionWidget);
            layout->setContentsMargins(0, 0, 0, 0);
            layout->setSpacing(2);

            QPushButton *editBtn = new QPushButton("Edytuj");
            editBtn->setMaximumWidth(60);
            connect(editBtn, &QPushButton::clicked, [this, i]() {
                tableWidget->selectRow(i * 2);
                onEditAnnouncementClicked();
            });
            layout->addWidget(editBtn);

            QPushButton *deleteBtn = new QPushButton("Usuń");
            deleteBtn->setMaximumWidth(60);
            connect(deleteBtn, &QPushButton::clicked, [this, i]() {
                tableWidget->selectRow(i * 2);
                onDeleteAnnouncementClicked();
            });
            layout->addWidget(deleteBtn);

            tableWidget->setCellWidget(i * 2, 3, actionWidget);
        }

        tableWidget->setSpan(contentRow, 0, 1, 4);

        QTextEdit *contentEdit = new QTextEdit();
        contentEdit->setPlainText(ann.getContent());
        contentEdit->setReadOnly(true);
        contentEdit->setFrameStyle(QFrame::NoFrame);
        contentEdit->setStyleSheet(
            "background-color: #f8f8f8;"
            "padding: 8px;"
            "color: black;"
            "font-size: 12px;"
            );

        tableWidget->setCellWidget(contentRow, 0, contentEdit);
        tableWidget->setRowHeight(contentRow, 120);
    }
}

void AnnouncementsWindow::onAddAnnouncementClicked()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Dodaj nowe ogłoszenie");
    dialog.setMinimumWidth(400);

    QVBoxLayout *mainLayout = new QVBoxLayout(&dialog);

    QFormLayout *formLayout = new QFormLayout();
    QLineEdit *titleEdit = new QLineEdit();
    QTextEdit *contentEdit = new QTextEdit();
    QLineEdit *authorEdit = new QLineEdit();

    formLayout->addRow("Tytuł:", titleEdit);
    formLayout->addRow("Autor:", authorEdit);
    formLayout->addRow("Treść:", contentEdit);

    mainLayout->addLayout(formLayout);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);
    mainLayout->addWidget(buttonBox);

    if (dialog.exec() == QDialog::Accepted) {
        if(titleEdit->text().isEmpty() || authorEdit->text().isEmpty()) {
            QMessageBox::warning(this, "Błąd", "Tytuł i autor są wymagane!");
            return;
        }

        Announcement newAnnouncement(
            titleEdit->text(),
            contentEdit->toPlainText(),
            QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm"),
            authorEdit->text()
            );

        QUuid uuid = QUuid::createUuid();
        QString uuidString = uuid.toString().mid(1, 36);

        announcement->addAnnouncement(uuidString, titleEdit->text(), contentEdit->toPlainText(), QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm"), authorEdit->text());
        addAnnouncement(newAnnouncement);
    }
}

void AnnouncementsWindow::onEditAnnouncementClicked()
{
    int row = tableWidget->currentRow();
    if (row < 0 || row >= announcements.size() * 2) return;

    if (row % 2 != 0) row--;

    int announcementIndex = row / 2;
    if (announcementIndex >= announcements.size()) return;

    QDialog dialog(this);
    dialog.setWindowTitle("Edytuj ogłoszenie");
    dialog.setMinimumWidth(400);

    QVBoxLayout *mainLayout = new QVBoxLayout(&dialog);

    QFormLayout *formLayout = new QFormLayout();
    QLineEdit *titleEdit = new QLineEdit(announcements[announcementIndex].getTitle());
    QLineEdit *authorEdit = new QLineEdit(announcements[announcementIndex].getAuthor());
    QTextEdit *contentEdit = new QTextEdit(announcements[announcementIndex].getContent());

    formLayout->addRow("Tytuł:", titleEdit);
    formLayout->addRow("Autor:", authorEdit);
    formLayout->addRow("Treść:", contentEdit);

    mainLayout->addLayout(formLayout);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);
    mainLayout->addWidget(buttonBox);

    if (dialog.exec() == QDialog::Accepted) {
        if(titleEdit->text().isEmpty() || authorEdit->text().isEmpty()) {
            QMessageBox::warning(this, "Błąd", "Tytuł i autor są wymagane!");
            return;
        }

        announcements[announcementIndex].setTitle(titleEdit->text());
        announcements[announcementIndex].setAuthor(authorEdit->text());
        announcements[announcementIndex].setContent(contentEdit->toPlainText());
        announcements[announcementIndex].setDate(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm"));
        updateTable();
    }
}

void AnnouncementsWindow::onDeleteAnnouncementClicked()
{
    int row = tableWidget->currentRow();
    if (row < 0 || row >= announcements.size() * 2) return;

    if (row % 2 != 0) row--;

    int announcementIndex = row / 2;
    if (announcementIndex >= announcements.size()) return;

    if (QMessageBox::question(this, "Potwierdzenie",
                              "Czy na pewno chcesz usunąć to ogłoszenie?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        announcements.removeAt(announcementIndex);
        updateTable();
    }
}
