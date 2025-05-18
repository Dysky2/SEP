#ifndef ANNOUNCEMENTS_H
#define ANNOUNCEMENTS_H

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

#endif // ANNOUNCEMENTS_H
