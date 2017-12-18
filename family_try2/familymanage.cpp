#include "familymanage.h"
#include "ui_familymanage.h"
#include "fileoperate.h"
#include "tree.h"
#include<QDialog>
//#include "memberdelete.h"
familymanage::familymanage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::familymanage)
{
    ui->setupUi(this);
    Tree *tr;
    tr=new Tree;
    this->setMaximumSize(822,583);
    this->setMinimumSize(822,583);

    this->setWindowTitle("Family Management");
/*
    connect(ui->exitbtn,SIGNAL(clicked()),this,SLOT(exitbtnSlot()));
    connect(ui->returnbtn,SIGNAL(clicked()),this,SLOT(returnbtnSlot()));
    //membersearch=new MemberSearch;
    ui->memberstack->addWidget(membersearch);
    connect(this,SIGNAL(toMemberSearch(tr),membersearch,SLOT(comeFamilyManage));
    connect(ui->searchbtn,SIGNAL(clicked()),this,SLOT(searchbtnSlot()));
    //memberdelete=new MemberDelete;
    ui->memberstack->addWidget(memberdelete);
    connect(this,SIGNAL(toMemberDelete(tr),memberdelete,SLOT(comeFamilyManage));
    connect(ui->deletebtn,SIGNAL(clicked()),this,SLOT(deletebtnSlot()));
    //memberinsert=new MemberInsert;
    ui->memberstack->addWidget(memberinsert);
    connect(this,SIGNAL(toMemberInsert(tr),memberinsert,SLOT(comeFamilyManage));
    connect(ui->insertbtn,SIGNAL(clicked()),this,SLOT(insertbtnSlot()));
    //changeinfo=new ChangeInfo;
    ui->memberstack->addWidget(changeinfo);
    connect(this,SIGNAL(toChangeInfo(tr),changeinfo,SLOT(comeFamilyManage));
    connect(ui->changebtn,SIGNAL(clicked()),this,SLOT(changebtnSlot()));
    //familyview=new FamilyView;
    ui->memberstack->addWidget(familyview);
    connect(this,SIGNAL(toFamilyView(tr),familyview,SLOT(comeFamilyManage));
    connect(ui->viewbtn,SIGNAL(clicked()),this,SLOT(viewbtnSlot()));
    //bloodview=new BloodView;
    ui->memberstack->addWidget(bloodview);
    connect(this,SIGNAL(toBloodView(tr),bloodview,SLOT(comeFamilyManage));
    connect(ui->bloodbtn,SIGNAL(clicked()),this,SLOT(bloodbtnSlot()));

    connect(memberdelete,SIGNAL(EmitToFamilyManage()),this,SLOT(setbtnEnableSlot()));
    connect(memberinsert,SIGNAL(EmitToTeacherManage()),this,SLOT(setbtnEnableSlot()));
    connect(membersearch,SIGNAL(EmitToTeacherManage()),this,SLOT(setbtnEnableSlot()));
    connect(changeinfo,SIGNAL(EmitToTeacherManage()),this,SLOT(setbtnEnableSlot()));
    connect(familyview,SIGNAL(EmitToTeacherManage()),this,SLOT(setbtnEnableSlot()));
    connect(bloodview,SIGNAL(EmitToFamilyManage()),this,SLOT(setbtnEnableSlot()));
    connect(membersearch,SIGNAL(EmitToFamilyManageToChangeStack()),this,SLOT(tosetStack()));
    connect(changeinfo,SIGNAL(EmitToFamilyManageToChangeStack()),this,SLOT(tosetStack()));
    connect(familyview,SIGNAL(EmitToFamilyManageToChangeStack()),this,SLOT(tosetStack()));
    connect(bloodview,SIGNAL(EmitToFamilyManageToChangeStack()),this,SLOT(tosetStack()));*/
}
familymanage::~familymanage()
{
    delete ui;
}

void familymanage::comeFamilyChoose(Tree *&tr,QString filename)
{
    //ui->familynameline->text()=filename;
    FileOperate f;
    f.FileRead(tr,filename);
}/*
void familymanage::exitbtnSlot()
{//remember to add the delete subTree
    if(QMessageBox::question(this,"提示","是否退出系统?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {

    this->close();
    delete this;
    }
}
void familymanage::returnbtnSlot()
{
    if(QMessageBox::question(this,"提示","return to main menu?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
    emit toMainMenu();
    delete this;
    }
}
void familymanage::setbtnfalse()
{
    ui->searchbtn->setEnabled(false);
    ui->changebtn->setEnabled(false);
    ui->insertbtn->setEnabled(false);
    ui->deletebtn->setEnabled(false);
    ui->viewbtn->setEnabled(false);
    ui->returnbtn->setEnabled(false);
    ui->exitbtn->setEnabled(false);
    ui->bloodbtn->setEnabled(false);
}
void familymanage::setbtntrue()
{
    ui->searchbtn->setEnabled(true);
    ui->changebtn->setEnabled(true);
    ui->insertbtn->setEnabled(true);
    ui->deletebtn->setEnabled(true);
    ui->viewbtn->setEnabled(true);
    ui->returnbtn->setEnabled(true);
    ui->exitbtn->setEnabled(true);
    ui->bloodbtn->setEnabled(true);
}
void familymanage::setbtnEnableSlot()
{
    this->setbtntrue();
}
void familymanage::tosetStack()
{
    //memberinsert->show();
    //ui->memberstack->setCurrentIndex(3);
}
void familymanage::searchbtnSlot()
{
    this->setbtnfalse();
    //membersearch->show();
    //ui->memberstack->setCurrentIndex(0);
    emit toMemberSearch(tr);
}
void familymanage::deletebtnSlot()
{
    this->setbtnfalse();
    //memberdelete->show();
    //ui->memberstack->setCurrentIndex(1);
    emit toMemberDelete(tr);
}

void familymanage::insertbtnSlot()
{
    this->setbtnfalse();
    //memberinsert->show();
    //ui->memberstack->setCurrentIndex(2);
    emit toMemberInsert(tr);
}
void familymanage::changebtnSlot()
{
    this->setbtnfalse();
    //changeinfo->show();
    //ui->memberstack->setCurrentIndex(3);
    emit toChangeInfo(tr);
}
void familymanage::viewbtnSlot()
{
    this->setbtnfalse();
    //familyview->show();
    //ui->memberstack->setCurrentIndex(4);
    emit toFamilyView(tr);
}
void familymanage::bloodbtnSlot()
{
    this->setbtnfalse();
    //bloodview->show();
   // ui->memberstack->setCurrentIndex(5);
    emit toBloodView(tr);.
}*/
