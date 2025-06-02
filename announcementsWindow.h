#ifndef ANNOUNCEMENTSWINDOW_H
#define ANNOUNCEMENTSWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "announcement.h"
#include <QTableWidget>
#include <QToolBar>
#include <QHeaderView>
#include <QMessageBox>
#include <QDialog>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QDialogButtonBox>
#include <QLabel>
#include <QDate>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDateTime>
#include <QFrame>
#include "user.h"
#include <QUuid>

class QTableWidget;
class QPushButton;

class AnnouncementsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AnnouncementsWindow(const QString& userId, QWidget *parent = nullptr);
    ~AnnouncementsWindow();

    void addAnnouncement(const Announcement &newAnnouncement);
    void updateTable();

private slots:
    void onAddAnnouncementClicked();
    void onEditAnnouncementClicked();
    void onDeleteAnnouncementClicked();

private:
    QString userId;
    QVector<Announcement> announcements;
    Announcement *announcement;
    QTableWidget *tableWidget;
    QPushButton *addButton;

    bool isUserPrivileged() const;
    void setupToolbar();
    void setupTable();
};
#endif
