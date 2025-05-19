#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // data_base.setDatabaseName("login.db");

    // if (!data_base.open()) {
    //     qDebug() << "Błąd bazy danych:" << data_base.lastError().text();
    //     return -1;
    // }

    MainWindow w;
    w.show();
    return a.exec();
}
