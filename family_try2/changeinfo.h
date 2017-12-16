#ifndef CHANGEINFO_H
#define CHANGEINFO_H

#include <QWidget>

namespace Ui {
class ChangeInfo;
}

class ChangeInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeInfo(QWidget *parent = 0);
    ~ChangeInfo();

private:
    Ui::ChangeInfo *ui;
    QSqlTableModel *model;
    int judge;
private slots:
    void comeFamilyManage(Tree*);
    void confirmbtnSlot();
    void returnbtnSlot();
    void judgeSlot(QModelIndex,QModelIndex);
    void inputeditSlot();
signals:
    void EmitToFamilyManage();
    void EmitToFamilyManageToChangeStack();
};

#endif // CHANGEINFO_H
