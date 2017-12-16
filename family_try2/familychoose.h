#ifndef FAMILYCHOOSE_H
#define FAMILYCHOOSE_H
#include "familymanage.h"
#include "mainmenu.h"
#include <QDialog>
#include <QDebug>
#include <QPalette>
#include <QButtonGroup>
#include <QMessageBox>
namespace Ui {
class FamilyChoose;
}

class FamilyChoose : public QDialog
{
    Q_OBJECT

public:
    explicit FamilyChoose(QWidget *parent = 0);
    ~FamilyChoose();
    void clearAll();
    bool judgeEmpty();
private:
    Ui::FamilyChoose *ui;
    FamilyManage *familymanage;
signals:
    void toFamilyManage(QString);
    void toMainMenu();
private slots:
    void returnbtnSlot();
    void confirmbtnSlot();
    void exitbtnSlot();
};

#endif // FAMILYCHOOSE_H
