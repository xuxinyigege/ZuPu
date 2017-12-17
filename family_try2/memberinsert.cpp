#include "memberinsert.h"
#include "ui_memberinsert.h"
#include "membersearch.h"
Tree *tr;
QString familyname;
MemberInsert::MemberInsert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemberInsert)
{
    ui->setupUi(this);


    //int generation;
    model=new QSqlTableModel(this);
    model->setTable("member");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->removeColumns(0,0);

    ui->nameline->setPlaceholderText("请输入name");
    ui->genderline->setPlaceholderText("请输入gender");
    ui->fathernameline->setPlaceholderText("请输入father name");
    ui->isliveline->setPlaceholderText("请输入islive");
    ui->telnumline->setPlaceholderText("请输入telnumbe/r");
    ui->addressline->setPlaceholderText("请输入address");
   // ui->generationline->setPlaceholderText("请输入generation");
    connect(ui->returnbtn,SIGNAL(clicked()),this,SLOT(returnbtnSlot()));
    connect(ui->confirmbtn,SIGNAL(clicked()),this,SLOT(confirmbtnSlot()));

}

MemberInsert::~MemberInsert()
{
    delete ui;
}
void MemberInsert::clearAll()
{
    ui->telnumline->clear();
    ui->nameline->clear();
    ui->genderline->clear();
    ui->isliveline->clear();
    ui->addressline->clear();
    ui->fathernameline->clear();
   // ui->generationline->clear();
}
bool MemberInsert::judgeEmpty()
{
    if(ui->telnumline->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","telnumber不能为空",QMessageBox::Yes);
        return false;
    }
    else if(ui->nameline->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","姓名不能为空",QMessageBox::Yes);
        return false;
    }
    else if(ui->isliveline->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","islive不能为空",QMessageBox::Yes);
        return false;
    }
    else if(ui->addressline->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","address不能为空",QMessageBox::Yes);
        return false;
    }
    /*else if(ui->generationline->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","generation不能为空",QMessageBox::Yes);
        return false;
    }*/
    else if(ui->genderline->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","gender不能为空",QMessageBox::Yes);
        return false;
    }
    else if(ui->fathernameline->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","fathername不能为空",QMessageBox::Yes);
        return false;
    }
    else
        return true;
}
void MemberInsert::returnbtnSlot()
{
    if(QMessageBox::question(this,"提示","尚未保存，是否退出",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        emit EmitToFamilyManage(tr1);
        this->hide();
    }
}
void MemberInsert::confirmbtnSlot()
{
        if(!this->judgeEmpty())
            return;
        model->setFilter( "familyname='"+familyname+"'");
        model->select();
        int i;
        for(i=0;i<model->rowCount();i++)
        {
            if(model->data(model->index(i,0)).toString()==ui->nameline->text())
            {
                break;
            }
        }
        if(i!=model->rowCount())
        {
            QMessageBox::information(this,"提示","用户已经存在",QMessageBox::Yes);
            this->clearAll();
            return;
        }


        Tree* tr1;
        tr1=new Tree;
        tr1=insert(tr);
        if(tr1==NULL)
        {
            QMessageBox::information(this,"提示","father not exist",QMessageBox::Yes);
            this->clearAll();
            return;
        }
        else
        {
            QSqlRecord record=model->record();
            record.setValue("familyname",familyname);
            record.setValue("gender",ui->genderline->text());
            record.setValue("name",ui->nameline->text());
            record.setValue("islive",ui->isliveline->text());
            record.setValue("telnum",ui->telnumline->text());
            record.setValue("address",ui->addressline->text());
            record.setValue("generation",generation);
            record.setValue("fathername",ui->fathernameline->text());
             model->insertRecord(-1,record);
            if(model->submitAll())
            {
                QMessageBox::information(this,"提示","信息添加成功",QMessageBox::Yes);
                this->clearAll();
            }
         }
}
void MemberInsert::comeFamilyManage(Tree *&tr_t,QString family)
{
    tr=new Tree;
    tr=tr_t;
    familyname=family;
}

Tree* MemberInsert::insert(Tree* tr) {
    Tree* t;
    Tree* insert;
    insert = new Tree;
    int generation;
    t = search(tr,ui->fathernameline->text());
    if (t != 0) {
    insert->selfname=ui->nameline->text();
    insert->gender=ui->genderline->text();
    insert->fathername=ui->fathernameline->text();
    insert->telnum=ui->telnumline->text();
    insert->address=ui->addressline->text();
    insert->islive=ui->isliveline->text();
    insert->generation=t->generation+1;
    insert->fatherone = t;
    generation=insert->generation;
    if(t->leftone == 0) {
        t->leftone = insert;
        insert->brotherone = t;

    }
    else {
        t = t->leftone;
        while ( t->rightone != 0)
            t = t->rightone;
        t->rightone=insert;
        insert->brotherone=t;
    }
     return tr;
    }
    return NULL;
}


