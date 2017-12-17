#include<QTextStream>
#include<QFile>
#include<queue>
#include "fileoperate.h"
#include "tree.h"
#include<sstream>
using namespace std;
void FileOperate :: FileSave(Tree *tr){
        if(tr!=NULL){
            QFile file(tr->selfname+".txt");
            file.open(QFile::WriteOnly);
            QTextStream ts(&file);
            ts.setCodec("utf-8");

        ts<<(tr->father_name)<<endl;
        ts<<(tr->selfname)<<endl;
        ts<<(tr->Sex)<<endl;
        ts<<(tr->IsLife)<<endl;
        ts<<(tr->generation)<<endl;
        ts<<(tr->telnum)<<endl;
        ts<<(tr->saddress)<<endl;
        ts.flush();
        file.close();

        FileSave(tr->leftone);
        FileSave(tr->rightone);


        }

}

void FileOperate :: FileClean(Tree* &tr,QString filename){
    QFile file(filename+".txt");
    file.open(QFile::Truncate);
    file.close();
}

void FileOperate :: FileRead(Tree* &tr,QString filename){
    queue<Tree* > q;
   // Tree *tr;
    Tree *q_t;
    Tree *tr_t;
    bool ok;
    QFile file(filename +".txt");
    if(file.open(QFile::ReadOnly)){
        QTextStream ts(&file);
        QString line;
        tr=new(Tree);
        if((line=ts.readLine())!=NULL)
             tr->father_name=line;
        if((line=ts.readLine())!=NULL)
             tr->selfname=line;
        if((line=ts.readLine())!=NULL)
             tr->gender=line;
        if((line=ts.readLine())!=NULL)
           
                tr->IsLife=line;
           
               
    
        if((line=ts.readLine())!=NULL)
            tr->telnum=line;
        if((line=ts.readLine())!=NULL)
            tr->address=line;
        if((line=ts.readLine())!=NULL) {
            tr->generation=line.toInt(&ok,10);
        }

    q.push(tr);
    line=ts.readLine();
    while(!line.isNull()){

            tr_t=new(Tree);

            tr_t->father_name=line;
            if((line=ts.readLine())!=NULL)
                 tr_t->selfname=line;
            if((line=ts.readLine())!=NULL)
                 tr_t->Sex=line;
            if((line=ts.readLine())!=NULL)
                tr_t->IsLife=line;

            if((line=ts.readLine())!=NULL) {
                tr->generation=line.toInt(&ok,10);
            }
            if((line=ts.readLine())!=NULL)
                tr_t->telnum=line;
            if((line=ts.readLine())!=NULL)
                tr_t->address=line;
            line=ts.readLine();

    if(tr_t->father_name==q.back()->selfname)
    {
        q.back()->leftone=tr_t;
    tr_t->fatherone=q.back();
    tr_t->brotherone=q.back();
    q.push(tr_t);
}
else{

            q_t=new(Tree);
            q_t=q.back();
    while(q_t->father_name!=tr_t->father_name)
        q_t=q_t->fatherone;
        tr_t->brotherone=q_t;
    q_t->rightone=tr_t;
            tr_t->fatherone=q_t->fatherone;
    q.push(tr_t);
    //delete q_t;
}
 //delete tr_t;
    }

    ts.flush();
    file.close();
    return;
}
    return;
}
