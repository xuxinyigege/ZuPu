#include "familychoose.h"
#include "ui_familychoose.h"
#include <QVBoxLayout>
#include <QTextStream>
#include <QFile>
#include <QLineEdit>
familychoose::familychoose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::familychoose)
{
    ui->setupUi(this);
    //model=new QSqlTableModel(this);
    //model->setEditStrategy(QSqlTableModel::OnManualSubmit);

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

familychoose::~familychoose()
{
    delete ui;
}
void familychoose::comeMainMenu()
{

}

void familychoose::confirmbtnSlot()
{
    if(!this->judgeEmpty())
    {
        ui->familynameline->clear();
        return;
    }
    QString s;
     ui->familynameline->text();

    s="/home/xuxinyigege/文档/family_again/"+s+".txt";
    QFile file("/home/xuxinyigege/文档/family_again/a.txt");
    if(file.exists())
    {
        Tree *tr;
        tr=new Tree;
        _familymanage=new familymanage(this);
        _familymanage->exec();
        connect(this,SIGNAL(toFamilyManage(Tree *&,QString)),_familymanage,SLOT(comefamilychoose(Tree *&,QString)));

        emit toFamilyManage(tr,ui->familynameline->text());
        ui->familynameline->clear();
        done(Accepted);
       // this->hide();
        return;
    }
    else
    {
        QMessageBox::information(this,"提示","No This Family",QMessageBox::Yes);
        ui->familynameline->clear();
        return;
    }
}
void familychoose::returnbtnSlot()
{

     emit toMainMenu();
     delete this;

}
void familychoose::exitbtnSlot()
{
    if(QMessageBox::question(this,"提示","是否退出系统?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        this->close();
        delete this;
    }
}
bool familychoose::judgeEmpty()
{
    if(ui->familynameline->text().isEmpty()){
        QMessageBox::warning(this,"警告","名不能为空");
        return false;
    }
    else
        return true;
}
