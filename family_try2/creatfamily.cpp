#include "creatfamily.h"
#include "ui_creatfamily.h"
#include "fileoperate.h"
#include "tree.h"
#include <QMessageBox>
#include <QButtonGroup>
CreatFamily::CreatFamily(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::CreatFamily)
{
    ui->setupUi(this);
    
    this->setWindowTitle("Creat A Family");
  
    this->setMaximumSize(822,583);
    this->setMinimumSize(822,583);
    
    ui->nameline->setPlaceholderText("name");
    ui->geneline->setPlaceholderText("generation");
    ui->telnumline->setPlaceholderText("telephone");
    ui->addressline->setPlaceholderText("address");
    ui->genderline->setPlaceholderText("gender");
    ui->isliveline->setPlaceholderText("islive");
   // ui->confirmbtn->setIcon(QIcon(":/student/img/m10.png"));
    //ui->confirmbtn->setFlat(true);
   // ui->returnbtn->setIcon(QIcon(":/student/img/m11.png"));
   // ui->returnbtn->setFlat(true);

    buttongroup=new QButtonGroup(this);
    buttongroup->addButton(ui->maleradio,0);
    buttongroup->addButton(ui->femaleradio,1);
    buttongroup->addButton(ui->liveradio,2);
    buttongroup->addButton(ui->deadradio,3);
    connect(ui->returnbtn,SIGNAL(clicked()),this,SLOT(returnbtnSlot()));
    connect(ui->confirmbtn,SIGNAL(clicked()),this,SLOT(confirmbtnSlot()));
    connect(buttongroup,SIGNAL(buttonClicked(int)),this,SLOT(buttongroupSlot(int)));
}

CreatFamily::~CreatFamily()
{
    delete ui;
}

void CreatFamily::clearAll()
{
    ui->nameline->clear();
    ui->geneline->clear();
    ui->telnumline->clear();
    ui->addressline->clear();
    ui->confirmbtn->clear();
    ui->returnbtn->clear();

}

bool CreatFamily::judgeEmpty()
{
    if(ui->nameline->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","name不能为空",QMessageBox::Yes);
        return false;
    }
    else if(ui->geneline->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","generation不能为空",QMessageBox::Yes);
        return false;
    }
    else if(ui->telnumline->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","telephonenumber不能为空",QMessageBox::Yes);
        return false;
    }
    else if(ui->addressline->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","address不能为空",QMessageBox::Yes);
        return false;
    }

    else
        return true;
}
void CreatFamily::returnbtnSlot()
{
    if(ui->nameline->text().isEmpty()&&ui->geneline->text().isEmpty()&&
       ui->telnumline->text().isEmpty()&&ui->addressline->text().isEmpty())
    {
        emit EmitToMenu();
        this->hide();
        return;
    }
}
void CreatFamily::confirmbtnSlot()
{
    if(!this->judgeEmpty())
        return;
    Tree *tr;
    tr = new Tree;

    tr->selfname = ui->nameline->text();
    tr->generation = 1;
    if(buttongroup->checkId()==0)
        tr->gender="male";
    else if(buttongroup->checkId()==1)
        tr->gender="female";
    if(buttongroup->checkId()==2)
        tr->islive="live";
    else if(buttongroup->checkId()==3)
        tr->islive="dead";
    tr->telnum=ui->telnumline->text();
    tr->address=ui->addressline->text();
    tr->fathername="no";
    FileOperate f;
    f.FileSave(tr);
    }
