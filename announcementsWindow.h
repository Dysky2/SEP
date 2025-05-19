#ifndef ANNOUNCEMENTSWINDOW_H
#define ANNOUNCEMENTSWINDOW_H

#include <QMainWindow>

namespace Ui {
class Announcements;
}

class Announcements : public QMainWindow
{
    Q_OBJECT

public:
    explicit Announcements(QWidget *parent = nullptr);
    ~Announcements();

private:
    Ui::Announcements *ui;
};

#endif // ANNOUNCEMENTSWINDOW_H
