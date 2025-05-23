#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QMainWindow>
#include "database.h"
#include <QSqlDatabase>
#include "user.h"


namespace Ui {
class AdminPanel;
}

class AdminPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    ~AdminPanel();

private:
    Ui::AdminPanel *ui;
};

#endif // ADMINPANEL_H
