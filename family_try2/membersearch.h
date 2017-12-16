#ifndef MEMBERSEARCH_H
#define MEMBERSEARCH_H

#include <QSqlTableModel>
#include <QDebug>
#include <QStringList>
#include <QMessageBox>
#include <QButtonGroup>
namespace Ui {
class MemberSearch;
}

class MemberSearch : public QWidget
{
    Q_OBJECT

public:
    explicit MemberSearch(QWidget *parent = 0);
    ~MemberSearch();

private:
    Ui::MemberSearch *ui;
    QButtonGroup *buttongroup;
private slots:
    void searchbtnSlot();
    void comeFamilyManage(Tree*);
    void returnbtnSlot();
    void inputeditSlot(QString);
    void buttongroupSlot(int);
    void searchchidren(Tree*,QString);
    void searchbrother(Tree*,QString);
    Tree* search(Tree*,QString);
signals:
    void EmitToFamilyManage();
    void EmitToFamilyManageToChangeStack();
};

#endif // MEMBERSEARCH_H
