#ifndef MAINMENU_H
#define MAINMENU_H
#include <QDebug>
#include <QWidget>
#include <QPalette>
#include <QButtonGroup>
#include <QMessageBox>
#include "familychoose.h"
#include "creatfamily.h"
namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MainMenu(QWidget *parent=0);
    ~MainMenu();
private:
    Ui::MainMenu  *ui;
   // QButtonGroup  *radiogroup;
    CreatFamily   *familycreat;
    FamilyChoose  *familychoose;
signals:
    void  toCreatFamily();
    void  toFamilyChoose();
private slots:
    void creatbtnSlot();
    void managebtnSlot();
    void exitbtnSLot();
};

#endif // MAINMENU_H
