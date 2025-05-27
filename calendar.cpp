 #include "calendar.h"

Calendar::Calendar() {

}

Calendar::Calendar(QString &userId, QObject* parent): QObject(parent),
    currentDate(QDate::currentDate()),
    calendarWidget(nullptr),
    userId(userId),
    scheduleCount(0)
{
    this->scheduleCount = getScheduleCountFromDatabase();
    createCalendar();
}

Calendar::~Calendar() {
    if (calendarWidget) {
        delete calendarWidget->takeWidget();
        delete calendarWidget;
    }
}

void Calendar::updateCalendar() {
    if (calendarWidget) {
        QWidget* oldWidget = calendarWidget->takeWidget();
        delete oldWidget;
    }
    createCalendar();
}

int Calendar::getScheduleCount() {
    return scheduleCount;
}

void Calendar::incrementScheduleCount() {
    scheduleCount++;
}

void Calendar::decrementScheduleCount() {
    scheduleCount--;
}

QString Calendar::getUserId() const{
    return userId;
}

void Calendar::nextMonth() {
    currentDate = currentDate.addMonths(1);
    updateCalendar();
}

void Calendar::previousMonth() {
    currentDate = currentDate.addMonths(-1);
    updateCalendar();
}

void Calendar::createCalendar() {
    QGridLayout* gridLayout = new QGridLayout();

    gridLayout->setHorizontalSpacing(2);
    gridLayout->setVerticalSpacing(2);

    Schedule* schedules = getSchedules();

    QDate firstOfMonth(currentDate.year(), currentDate.month(), 1);

    int startDay = firstOfMonth.dayOfWeek() - 1;
    int daysInMonth = currentDate.daysInMonth();

    for (int i = 0; i < startDay; i++) {
        QLabel *emptyLabel = new QLabel();
        emptyLabel->setMinimumSize(40, 40);
        gridLayout->addWidget(emptyLabel, 0, i);
    }

    for (int day = 1, row = 0, col = startDay; day <= daysInMonth; day++, col++) {
        if (col > 6) {
            col = 0;
            row++;
        }

        QWidget *dayWidget = new QWidget();
        dayWidget->setStyleSheet(
            "QWidget {"
            "   border: 1px solid #ccc;"     // obramowanie kontenera
            "   background-color: white;"
            "   margin: 1px;"               // odstęp między komórkami
            "}"
            "QPushButton:hover {"
            "   border: 1px solid #999;"    // efekt hover
            "}"
            );

        QVBoxLayout *dayLayout = new QVBoxLayout(dayWidget);
        dayLayout->setAlignment(Qt::AlignTop);

        QLabel *dayNumber = new QLabel(QString::number(day));
        dayNumber->setAlignment(Qt::AlignTop | Qt::AlignRight);
        dayNumber->setStyleSheet("border: none; background: transparent;");

        QPushButton *btn = new QPushButton("+");
        btn->setFixedSize(20, 20);

        QHBoxLayout *topRowLayout = new QHBoxLayout();
        topRowLayout->addWidget(btn, 0, Qt::AlignLeft | Qt::AlignTop);
        topRowLayout->addSpacing(110);
        topRowLayout->addWidget(dayNumber);
        topRowLayout->addStretch();
        topRowLayout->setSpacing(0);

        QVBoxLayout *labelConainerLayout = new QVBoxLayout();
        labelConainerLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

        for(int i=0; i < getScheduleCount(); i++) {
            if(day == schedules[i].getDate().day() && currentDate.month() == schedules[i].getDate().month() && currentDate.year() == schedules[i].getDate().year()) {
                QString formattedText = insertSpacesEveryN(schedules[i].getText(), 36);
                QLabel *eventLabel = new QLabel(formattedText);
                eventLabel->setWordWrap(true);
                eventLabel->setMaximumWidth(145);
                eventLabel->setStyleSheet("padding: 4px; border-radius: 5px");
                eventLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
                labelConainerLayout->addWidget(eventLabel);
            }
        }

        connect(btn, &QPushButton::clicked, [this, day, dayWidget,labelConainerLayout ]() {
            QDialog *dialog = new QDialog(dayWidget);
            dialog->setWindowTitle("Dodaj wydarzenie");

            QVBoxLayout *layout = new QVBoxLayout(dialog);
            QTextEdit *textEdit = new QTextEdit();
            textEdit->setPlaceholderText("Wpisz wydarzenia...");
            textEdit->setWordWrapMode(QTextOption::WrapAnywhere);

            QPushButton* saveButton = new QPushButton("Zapisz", dialog);

            layout->addWidget(textEdit);
            layout->addWidget(saveButton);

            connect(saveButton, &QPushButton::clicked, dialog, [this, day, dialog, textEdit, dayWidget,labelConainerLayout]() {
                QString eventText = textEdit->toPlainText();
                if(!eventText.isEmpty()) {
                    QString formattedText = insertSpacesEveryN(eventText, 36);
                    QLabel *eventLabel = new QLabel(formattedText);
                    eventLabel->setWordWrap(true);
                    eventLabel->setMaximumWidth(145);
                    eventLabel->setStyleSheet("padding: 4px; border-radius: 5px");
                    eventLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);

                    User author = getUserById(getUserId());

                    QDate stringDate = QDate(getCurrenDate().year(), getCurrenDate().month(), day);
                    addScheduleIntoDatabase(eventText, author, stringDate);

                    labelConainerLayout->addWidget(eventLabel);
                    dayWidget->adjustSize();
                }
                dialog->close();
                dialog->deleteLater();
            });
            dialog->exec();
        });

        dayLayout->addLayout(topRowLayout);
        dayLayout->addLayout(labelConainerLayout);
        dayLayout->setSpacing(2);

        gridLayout->addWidget(dayWidget, row, col);
    }

    QWidget *calendarContainer = new QWidget();
    calendarContainer->setLayout(gridLayout);
    calendarContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    calendarWidget = new QScrollArea();
    calendarWidget->setWidgetResizable(true);
    calendarWidget->setWidget(calendarContainer);
    calendarWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    calendarWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    calendarWidget->setStyleSheet(
        "QScrollArea { border: none; }"
        "QScrollBar:vertical { width: 12px; background: transparent;}"
        "QScrollBar::handle:vertical { background: #ccc; border-radius: 6px; min-height: 20px;}"
        "border: none; background: transparent;"
    );
}

QScrollArea* Calendar::getWidget() {
    return calendarWidget;
}

QDate Calendar::getCurrenDate() const{
    return currentDate;
}

int Calendar::getScheduleCountFromDatabase() {
    QSqlDatabase db = Database::getInstance().getConnection();
    if (!db.isOpen()) {
        qDebug() << "Błąd połączenia z bazą danych";
        return 0;
    }

    QSqlQuery countQuery(db);
    if(!countQuery.exec("SELECT COUNT(*) FROM schedule")) {
        qDebug() << "Błąd wykonania zapytania:" << countQuery.lastError().text();
        return 0;
    }

    if(countQuery.next()) {
        return countQuery.value(0).toInt();
    }
    return 0;
}

QString insertSpacesEveryN(const QString &text, int n) {
    QString result;
    for (int i = 0; i < text.length(); ++i) {
        if (i > 0 && i % n == 0)
            result += ' ';
        result += text[i];
    }
    return result;
}

void Calendar::addScheduleIntoDatabase(QString text, User author, QDate date) {
    QSqlDatabase db = Database::getInstance().getConnection();
    if (!db.isOpen()) {
        qDebug() << "Błąd połączenia z bazą danych";
        return;
    }

    QUuid uuid = QUuid::createUuid();
    QString uuidString = uuid.toString().mid(1, 36);

    QSqlQuery query(db);
    query.prepare("INSERT INTO schedule (id,text,author_id,date) VALUES (:id, :text, :author_id, :date)");
    query.bindValue(":id", uuidString);
    query.bindValue(":text", text);
    query.bindValue(":author_id", author.getId());
    query.bindValue(":date", date.toString("dd.MM.yyyy"));

    if(!query.exec()) {
        qDebug() << "Blad: " << query.lastError().text();
    } else {
        qDebug() << "Pomyslnie dodano wydarzenie w terminarzu";
    }
}

Schedule* Calendar::getSchedules() {
    QSqlDatabase db = Database::getInstance().getConnection();

    QSqlQuery query(db);
    query.prepare("SELECT * FROM schedule");

    if(!query.exec()) {
        qDebug() << "BŁAD: " << query.lastError().text();
        return nullptr;
    }

    Schedule* schedules = new Schedule[getScheduleCount()];
    int index = 0;
    while(query.next() && index < getScheduleCount()) {
        Schedule tempSchedule(query.value("id").toString(), query.value("text").toString(),
                              query.value("author_id").toString(), QDate::fromString(query.value("date").toString(), "dd.MM.yyyy"));
        schedules[index++] = tempSchedule;
        incrementScheduleCount();
    }
    return schedules;
}
