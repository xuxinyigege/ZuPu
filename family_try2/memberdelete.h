#ifndef MEMBERDELETE_H
#define MEMBERDELETE_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRecord>

namespace Ui {
class MemberDelete;
}

class MemberDelete : public QWidget
{
    Q_OBJECT

public:
    explicit MemberDelete(QWidget *parent = 0);
    ~MemberDelete();

private:
    Ui::MemberDelete *ui;
    QSqlTableModel *model;
private:
    void delbtnSlot();
    void returnbtnSlot();
    void comeFamilyManage();
    void deletemember(Tree*,QString);
signals:
    void EmitToFamilyManage(Tree*);

};

#endif // MEMBERDELETE_H
