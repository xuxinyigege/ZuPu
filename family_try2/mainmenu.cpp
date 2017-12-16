#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "creatfamily.h"
#include "familychoose.h"
#include <QVBoxLayout>

MainMenu::MainMenu(QWidget *parent):
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    
    this->setMaximumSize(822,583);
    this->setMinimumSize(822,583);

    this->setWindowTitle("Family Geneology System");
   /* radiogroup=new QButtonGroup(this);
    radiogroup->addButton((ui->creatradio,0));
    radiogroup->addButton((ui->manageradio,1));*/
    
    connect(ui->creatbtn,SIGNAL(clicked()),this,SLOT(creatbtnSlot()));
    connect(ui->managebtn,SIGNAL(clicked()),this,SLOT(managebtnSlot()));
    
}
MainMenu::~MainMenu()
{
    delete ui;
}
void MainMenu::creatbtnSlot()
{
    familycreat=new CreatFamily;
    connect(familycreat,SIGNAL(toCreatFamily),this,SLOT(showNormal());
    familycreat->show();
    emit toCreatFamily();
    this->hide();
    return;
}
void MainMenu::managebtnSlot()
{
    familymanage=new FamilyChoose;
    connect(familymanage,SIGNAL(toFamilyChoose),this,SLOT(showNormal());
    familymanage->show();
    emit toFamilyChoose();
    this->hide();
    return;
}
void MainMenu::exitbtnSlot()
{
    this->close();
}
