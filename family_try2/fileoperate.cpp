#include<QTextStream>
#include<QFile>
#include "fileoperate.h"
#include "tree.h"
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

        save(tr->leftone);
        save(tr->rightone);


        }

}

void FileOperate :: FileClean(QString filename){
    QFile file(filename+".txt");
    file.open(QFile::Truncate);
    file.close();
}

void FileOperate :: FileRead(Tree* &tr,QString filename){
    queue<Tree* > q;
   // Tree *tr;
    Tree *q_t;
    Tree *tr_t;
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
            stringstream s(line);
            s>>tr->generation;
        }

    q.push(tr);
    line=ts.readLine();
    while(!ts.stEnd()){

            tr_t=new(Tree);

            tr_t->father_name=line;
            if((line=ts.readLine())!=NULL)
                 tr_t->selfname=line;
            if((line=ts.readLine())!=NULL)
                 tr_t->Sex=line;
            if((line=ts.readLine())!=NULL){
                if(line=="0")
                    tr_t->IsLife=0;
                else
                    tr_t->IsLife=1;
             }
            if((line=ts.readLine())!=NULL) {
                stringstream s(line);
                s>>tr_t->generation;
            }
            if((line=ts.readLine())!=NULL)
                tr_t->telnum=line;
            if((line=ts.readLine())!=NULL)
                tr_t->address=line;
            line=ts.redLine();

    if(tr_t->father_name==q.back()->name)
    {
        q.back()->left=tr_t;
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
            tr_t->fatherone=q_t->fatheoner;
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
