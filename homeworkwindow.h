#ifndef HOMEWORKWINDOW_H
#define HOMEWORKWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPushButton>
#include "homework.h"


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
    void onAddHomeworkClicked();
    void onEditHomeworkClicked();
    void onDeleteHomeworkClicked();
    void onAddSolutionClicked();
    void onPreviewHomeworkClicked(int row);

private:
    QString userId;
    Ui::HomeworkWindow *ui;
    QVector<Homework> homeworks; //Baza?


};

#endif // HOMEWORKWINDOW_H
