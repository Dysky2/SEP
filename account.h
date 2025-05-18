#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QMainWindow>

namespace Ui {
class Account;
}

class Account : public QMainWindow
{
    Q_OBJECT

public:
    explicit Account(QWidget *parent = nullptr);
    ~Account();

private:
    Ui::Account *ui;
};

#endif // ACCOUNT_H
