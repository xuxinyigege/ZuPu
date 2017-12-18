#ifndef familymanage_H
#define familymanage_H
#include <QDebug>
#include <QPalette>
#include <QWidget>
#include <QDialog>
#include <QDateTime>
#include <QTimer>
#include "tree.h"
//#include "membersearch.h"
//#include "memberdelete.h"
//#include "memberinsert.h"
//#include "changeinfo.h"
//#include "bloodview.h"
//#include "familyview.h"

namespace Ui {
class familymanage;
}

class familymanage : public QDialog
{
    Q_OBJECT

public:
    explicit familymanage(QWidget *parent = 0);
    ~familymanage();
    void btnsettrue();
    void btnsetfalse();
private:
    Ui::familymanage *ui;
    //MemberDelete *memberdelete;
    //MemberInsert *memberinsert;
    //MemberSearch *membersearch;
    //ChangeInfo *changeinfo;
    //BloodView *bloodview;
    //FamilyView *familyview;
private slots:
    void comeFamilyChoose(Tree *&,QString);
    /*void exitbtnSlot();
    void returnbtnSlot();
    void deletebtnSlot();
    void insertbtnSlot();
    void searchbtnSlot();
    void changebtnSlot();
    void bloodbtnSlot();
    void viewbtnSlot();
    void tosetStack();
    void setbtnEnableSlot();

signals:
    void toMainmenu();
    //void toMemberSearch(Tree*);
    //void toMemberDelete(Tree*);
    //void toMemberInsert(Tree*);
    //void toChangeInfo(Tree*);
    //void toBloodView(Tree*);
    //void toFamilyView(Tree*);*/
};

#endif // familymanage_H
