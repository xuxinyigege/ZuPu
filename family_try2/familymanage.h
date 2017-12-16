#ifndef FAMILYMANAGE_H
#define FAMILYMANAGE_H
#include <QDebug>
#include <QPalette>
#include <QWidget>
#include <QDateTime>
#include <QTimer>
#include "membersearch.h"
#include "memberdelete.h"
#include "memberinsert.h"
#include "changeinfo.h"
#include "bloodview.h"
#include "familyview.h"

namespace Ui {
class FamilyManage;
}

class FamilyManage : public QWidget
{
    Q_OBJECT

public:
    explicit FamilyManage(QWidget *parent = 0);
    ~FamilyManage();
    void btnsettrue();
    void btnsetfalse();
private:
    Ui::FamilyManage *ui;
    MemberDelete *memberdelete;
    MemberInsert *memberinsert;
    MemberSearch *membersearch;
    ChangeInfo *changeinfo;
    BloodView *bloodview;
    FamilyView *familyview;
private slots:
    void comeFamilyChoose(QString);
    void exitbtnSlot();
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
    void toMemberSearch(Tree*);
    void toMemberDelete(Tree*);
    void toMemberInsert(Tree*);
    void toChangeInfo(Tree*);
    void toBloodView(Tree*);
    void toFamilyView(Tree*);
};

#endif // FAMILYMANAGE_H
