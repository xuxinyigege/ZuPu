#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "creatfamily.h"
#include "familychoose.h"

mainmenu::mainmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainmenu)
{
    ui->setupUi(this);
    this->setMaximumSize(822,583);
    this->setMinimumSize(822,583);
    this->setWindowTitle("Family Geneology System");

    //连接学生成绩管理窗口和登录对话框信号与槽
    connect(ui->creatbtn,SIGNAL(clicked()),this,SLOT(on_creatbtn_clicked()));
   // connect(ui->managebtn,SIGNAL(clicked()),this,SLOT(on_managebtn_clicked()));

}

mainmenu::~mainmenu()
{
    delete ui;
}

void mainmenu::on_exitbtn_clicked()
{
    close();
}

void mainmenu::on_creatbtn_clicked()
{
   creat = new creatfamily(this);
   creat->exec();

   connect(this,SIGNAL(toCreatFamily()),creat,SLOT(comeMainMenu()));
   emit toCreatFamily();

   return;
}


void mainmenu::on_managebtn_clicked()
{
    familychoose *choosefamily = new familychoose(this);
    choosefamily->exec();
    connect(this,SIGNAL(toFamilyChoose()),choosefamily,SLOT(comeMainMenu()));
    emit toFamilyChoose();
    return;
}
