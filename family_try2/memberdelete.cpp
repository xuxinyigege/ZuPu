#include "memberdelete.h"
#include "ui_memberdelete.h"
#include "membersearch.h"
Tree* tr;
QString familyname;
MemberDelete::MemberDelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemberDelete)
{
    ui->setupUi(this);
    Tree *tr;
    tr=new Tree;
    model=new QSqlTableModel(this);
    model->setTable("member");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->removeColumns(0,0);
    model->setHeaderData(1,Qt::Horizontal,"name");
    model->setHeaderData(2,Qt::Horizontal,"gender");
    model->setHeaderData(3,Qt::Horizontal,"fathername");
    model->setHeaderData(4,Qt::Horizontal,"islive");
    model->setHeaderData(5,Qt::Horizontal,"address");
    model->setHeaderData(6,Qt::Horizontal,"telnumber");
    model->setHeaderData(7,Qt::Horizontal,"generation");
    ui->memberdeleteview->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->memberdeleteview->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->delline->setPlaceholderText("请输入name");
       //连接按钮的信号和槽
    connect(ui->delbtn,SIGNAL(clicked()),this,SLOT(delbtnSlot()));
    connect(ui->returnbtn,SIGNAL(clicked()),this,SLOT(returnbtnSlot()));
}
void MemberDelete::delbtnSlot()
{

  if(ui->delline->text().isEmpty())
  {
      QMessageBox::warning(this,"警告","删除输入框不能为空");
      return;
  }
  model->setFilter( "familyname='"+familyname+"'");
  model->select();
  int i;
  for(i=0;i<model->rowCount();i++)
  {
      if((model->data(model->index(i,1)).toString()==ui->delline->text())&&(model->data(model->index(i,0)).toString()==familyname))
      {
          if(QMessageBox::question(this,"提示","确定要删除吗？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
          {
              model->removeRow(i);
              model->submitAll();
              deletemember(tr,ui->delline);
              ui->delline->clear();
              ui->memberdeleteview->setModel(model);
              return;
          }
          else
              return;
      }
  }
  QMessageBox::information(this,"提示","用户不存在，删除失败!");
  ui->delline->clear();

}
void MemberDelete::returnbtnSlot()
{
    ui->delline->clear();
    emit EmitToFamilyManage(tr);
    this->hide();
}
void MemberDelete::comeStudentManage(Tree* &tr_t,QString family)
{
    tr=new tr_t;
    familyname=family;


}
MemberDelete::~MemberDelete()
{
    delete ui;
}
void MemberDelete:: deletemember(Tree* &tr,QString name) {

        Tree* t;
        t=search(tr,name);
        if (t != 0) {
            if ( t->fatherone == t->brotherone ) {
                t->fatherone->leftone = t->rightone;

                if (t->rightone != 0) {
                  t->rightone->brotherone = t->fatherone;
                }
            }
            else {
                if ( t->rightone != 0) {
                    t->brotherone->rightone = t->rightone;
                    t->rightone->brotherone = t->brotherone;
                }
                else
                    t->brotherone->rightone = NULL;
            }

             return ;
        }
        return;
    }
