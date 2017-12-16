#include <QApplication>
#include "mainmenu.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QPushButton>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    MainMenu w;
    w.show();

    return a.exec();
}
