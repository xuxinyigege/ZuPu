

#include "mainmenu.h"

#include<QMessageBox>
#include<QApplication>
#include <QSqlDatabase>
#include<QPushButton>


// main//
int main(int argc, char* argv[]){
    QApplication a(argc,argv);
    QSqlDatabase db=QSqlDatabase::addDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("member.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open database1","Unable to establish a database connection.",QMessageBox::Cancel);
        return false;
    }
    else ui->status_Label->setText(tr("创建sqlite数据库成功"));

    QSqlQuery query;
    bool success=query.exec("create table member (familyname varchar(40) primary key,name varchar(40),gender varchar(40),fathername varchar(40),islive varchar(40),address varchar(100),telnumber varchar(40),generation int,");
       if (success){
           qDebug()<<QObject::tr("数据库表创建成功");
           return true;
        }
       else {
           qDebug()<<QObject::tr("failed");
           return false;
       }
       if(db.open())
       {
          MainMenu w;
          w.show();
          return a.exec();
       }
       else
      {
          QMessageBox::information(NULL,"提示","系统载入数据库失败，无法运行",QMessageBox::Yes);
      }

}
