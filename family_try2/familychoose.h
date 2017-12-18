#ifndef familychoose_H
#define familychoose_H
#include "familymanage.h"
#include "mainmenu.h"
#include <QDialog>
#include <QDebug>
#include <QWidget>
#include <QPalette>
#include <QButtonGroup>
#include <QMessageBox>
#include "tree.h"
namespace Ui {
class familychoose;
}

class familychoose : public QDialog
{
    Q_OBJECT

public:
    explicit familychoose(QWidget *parent = 0);
    ~familychoose();
    void clearAll();
    bool judgeEmpty();
private:
    Ui::familychoose *ui;
    familymanage *_familymanage;
signals:
    void toFamilyManage(Tree *&,QString);
    void toMainMenu();
private slots:
    void returnbtnSlot();
    void confirmbtnSlot();
    void exitbtnSlot();
public slots:
    void comeMainMenu();
};

#endif // familychoose_H
