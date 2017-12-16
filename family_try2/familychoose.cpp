#include "familychoose.h"
#include "ui_familychoose.h"
#include <QVBoxLayout>
#include <QTextStream>
#include <QFile>
FamilyChoose::FamilyChoose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FamilyChoose)
{
    ui->setupUi(this);
    model=new QSqlTableModel(this);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
   
    this->setWindowTitle("Family Choose");
   
    //设置登录对话框大小固定为399*252
    this->setMaximumSize(399,252);
    this->setMinimumSize(399,252);
    
    ui->familynameline->setPlaceholderText("请输入family name");
    //connect(ui->familynameline,SIGNAL(clicked()),this,SLOT(familynamebtnSlot()));
    connect(ui->returnbtn,SIGNAL(clicked()),this,SLOT(returnbtnSlot()));
    connect(ui->confirmbtn,SIGNAL(clicked()),this,SLOT(confirmbtnSlot()));
    connect(ui->exitbtn,SIGNAL(clicked()),this,SLOT(exitbtnSlot()));
}

FamilyChoose::~FamilyChoose()
{
    delete ui;
}

void FamilyChoose::confirmbtnSlot()
{
    if(!this->judgeEmpty())
    {
        ui->familynameline->clear();
        return;
    }
    QString s;
    s=ui->familynameline->text();
    s+=".txt";
    QFile file(s);
    if(file.exists())
    {
        this->clearAll();
        familymanage=new FamilyManage;
        familymanage->show();
        connect(this,SIGNAL(toFamilyManage(ui->familynameline->text()),familymanage,SLOT(comeMainMenu()));
        connect(familymanage,SIGNAL(toMainMenu()),this,SLOT(showNormal()));
        emit toFamilyManage(ui->familynameline->text());
        this->clearAll();
        this->hide();
        return;
    } 
    else
    {
        QMessageBox::information(this,"提示","No This Family",QMessageBox::Yes);
        this->clearAll();
        return;
    }
}
void FamilyChoose::returnbtnSlot()
{
    
     emit toMainMenu();
     delete this;
       
}
void FamilyChoose::exitbtnSlot()
{
    if(QMessageBox::question(this,"提示","是否退出系统?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        this->close();
        delete this;
    }
}
bool FamilyChoose::judgeEmpty()
{
    if(ui->familynameline->text().isEmpty()){
        QMessageBox::warning(this,"警告","名不能为空");
        return false;
    }
    else 
        return true;
}
