#ifndef MEMBERINSERT_H
#define MEMBERINSERT_H
#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QWidget>
#include <QButtonGroup>

namespace Ui {
class MemberInsert;
}

class MemberInsert : public QWidget
{
    Q_OBJECT

public:
    explicit MemberInsert(QWidget *parent = 0);
    ~MemberInsert();
    bool judgeEmpty();
    void clearAll();

private:
    Ui::MemberInsert *ui;
    QSqlTable *model;
private slots:
    void returnbtnSlot();
    void confirmbtnSlot();
    void insertchildren(Tree*);
    void comeFamilyManage(Tree*);
signals:
    void EmitToFamilyManage(Tree*);
};

#endif // MEMBERINSERT_H
