#include "membersearch.h"
#include "ui_membersearch.h"
Tree *tr;
QString familyname;
MemberSearch::MemberSearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemberSearch)
{
    ui->setupUi(this);
    Tree* tr;
    tr=new Tree;
    Tree* tr1;
    tr1=new Tree;
    connect(ui->returnbtn,SIGNAL(clicked()),this,SLOT(returnbtnSlot()));
    connect(ui->searchbtn,SIGNAL(clicked()),this,SLOT(searchbtnSlot()));
    ui->membersearchview->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->membersearchview->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->inputline->setPlaceholderText("please input the member name");

    buttongroup=new QButtonGroup(this);
    buttongroup->addButton(ui->selfradio,0);
    buttongroup->addButton(ui->brotherradio,1);
    buttongroup->addButton(ui->chidrenradio,2);
    connect(ui->inputline,SIGNAL(textChanged(QString)),this,SLOT(inputeditSlot(QString)));
    connect(buttongroup,SIGNAL(buttonClicked(int)),this,SLOT(buttongroupSlot(int)));

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
    //创建_model实现查询功能
    _model=new QSqlTableModel(this);
    _model->setTable("member");
    _model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    _model->removeColumns(0,0);
    _model->setHeaderData(1,Qt::Horizontal,"name");
    _model->setHeaderData(2,Qt::Horizontal,"gender");
    _model->setHeaderData(3,Qt::Horizontal,"fathername");
    _model->setHeaderData(4,Qt::Horizontal,"islive");
    _model->setHeaderData(5,Qt::Horizontal,"address");
    _model->setHeaderData(6,Qt::Horizontal,"telnumber");
    _model->setHeaderData(7,Qt::Horizontal,"generation");
}

MemberSearch::~MemberSearch()
{
    delete ui;
}
void MemberSearch::searchbtnSlot()
{
    if(ui->inputline->text().isEmpty())
    {
           QMessageBox::warning(this,"警告","查询输入框不能为空!");
           return;
    }
    if(buttongroup->checkedId()==0)
    {
        _model->setFilter( "familyname='"+familyname+"'");
        _model->setFilter( "name='"+ui->inputline->text()+"'");
        _model->select();
        if(_model->data(model->index(0,0)).toString().isEmpty())
        {
             QMessageBox::warning(this,"警告","用户不存在");
             ui->membersearchview->setModel(model);
             ui->inputline->clear();
             return;
         }
        ui->membersearchview->setModel(_model);
        /*MemberSearch f1;
        tr1=f1.search(tr);
        ui->membersearchview->setModel(tr);*/
    }
    else if(buttongroup->checkedId()==1)
        searchbrother(tr,ui->inputline->text());

    else if(buttongroup->checkedId()==2)
        searchchidren(tr,ui->inputline->text());

    else
        QMessageBox::warning(this,"警告","请选择");
}
void MemberSearch:: searchbrother(Tree* tr2, QString name) {
    Tree* t1;
    Tree* r;
    int i=0;
    t=search(tr2, name);
     if(t==NULL){
         QMessageBox::warning(this,"警告","用户不存在");
         ui->membersearchview->setModel(model);
         ui->inputline->clear();
         return;
    }
    if (t != 0) {
        r=t;
        while(t->brotherone != t->fatherone) {
            t=t->brotherone;
            _model->setFilter( "familyname='"+familyname+"'");
            _model->setFilter( "name='"+t->selfname+"'");
            _model->select();
            ui->membersearchview->setModel(_model);
            i++;
        }

        r=r->rightone;
        while (r != 0) {
            _model->setFilter( "familyname='"+familyname+"'");
            _model->setFilter( "name='"+t->selfname+"'");
            _model->select();
            ui->membersearchview->setModel(_model);
            r=r->rightone;
            i++;
        }

        return;
    }
    QMessageBox::warning(this,"warnning","no brothers of sisters!");
    return;
}
void MemberSearch::comeFamilyManage(Tree* &tr_t,QString familyname)
{
     tr=new Tree;
     tr=tr_t;
     familyname=family;

}
void MemberSearch::returnbtnSlot()
{
    ui->inputline->clear();
    emit EmitToFamilyManage();
    this->hide();
}
void MemberSearch::inputeditSlot(QString)
{
    if(ui->inputline->text().isEmpty())
    {
        ui->membersearchview->setModel(model);
    }
}
void MemberSearch::buttongroupSlot(int)
{
    ui->membersearchview->setModel(model);
    ui->inputline->clear();
}
Tree* MemberSearch::search(Tree *tr3, QString name) {
    queue<Tree* > q;
    if (tr3 != 0) {
        if (tr3->selfname == name)
            return tr3;
        q.push(tr);
        while (q.empty() == false ) {
            if(q.front() -> left != 0) {
                if (q.front()->leftone->selfname == name)
                    return q.front()->leftone;
                else
                    q.push(q.front()->leftone);
            }
            if(q.front() -> rightone != 0) {
                if (q.front()->rightone->selfname == name)
                    return q.front()->rightone;
                else
                    q.push(q.front()->rightone);
            }
            q.pop();
        }
    }
    return NULL;
}
void MemberSearch:: searchchidren(Tree* tr4, QString name) {
    Tree* t2;
    t2=search(tr4, name);
    if(t==NULL){
        QMessageBox::warning(this,"warning","NO this member!");
        return;
    }
    if (t->leftone != 0) {
        t2=t2->leftone;
        int i=0;
        while (t2 != 0) {
            _model->setFilter( "familyname='"+familyname+"'");
            _model->setFilter( "name='"+t2->selfname+"'");
            _model->select();
            ui->membersearchview->setModel(_model);
            i++;
            t2=t2->rightone;
        }

        return ;
    }
    else {
        QMessageBox::warning(this,"warnning","no children!");
        return;
    }
}
