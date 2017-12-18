#ifndef MAINMENU_H
#define MAINMENU_H
#include <QDebug>
#include <QWidget>
#include <QPalette>
#include <QButtonGroup>
#include <QMessageBox>
#include "creatfamily.h"
#include "familychoose.h"
namespace Ui {
class mainmenu;
}

class mainmenu : public QDialog
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = 0);
    ~mainmenu();

signals:
    void  toCreatFamily();

    void  toFamilyChoose();

private slots:
    void on_exitbtn_clicked();

    void on_creatbtn_clicked();

    void on_managebtn_clicked();

private:
    Ui::mainmenu *ui;
    creatfamily *creat;

};

#endif // MAINMENU_H
