#ifndef HOMEWORKWINDOW_H
#define HOMEWORKWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPushButton>
#include <QDebug>
#include <QHBoxLayout>
#include <QToolButton>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QToolBar>
#include <QTextEdit>
#include "homework.h"
#include "teacher.h"
#include "subject.h"
#include "database.h"
#include <QList>
#include "addHomeworkDialog.h"
#include <QComboBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QMessageBox>
#include "user.h"

namespace Ui {
class HomeworkWindow;
}

class HomeworkWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomeworkWindow(QString& userId, QWidget *parent = nullptr);
    ~HomeworkWindow();

    void addHomework(const Homework& newHomework);
    void on_addButton_clicked();
    QPushButton *addButton = new QPushButton("Dodaj zadanie", this);
    void updateTable();


private slots:
    void onAddHomeworkClicked(QString userId);
    void onEditHomeworkClicked();
    void onDeleteHomeworkClicked();
    void onAddSolutionClicked();
    void onPreviewHomeworkClicked(int row);

private:
    QString userId;
    Ui::HomeworkWindow *ui;
    Homework *homework;
    Subject *subject;
    QVector<Homework> homeworks;
    QList<Homework> homeworkList;

};

#endif // HOMEWORKWINDOW_H
