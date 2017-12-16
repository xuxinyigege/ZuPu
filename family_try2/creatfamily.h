#ifndef CREATFAMILY_H
#define CREATFAMILY_H

#include <QDialog>
#include <QWidget>
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class CreatFamily;
}

class CreatFamily : public QDialog
{
    Q_OBJECT

public:
    explicit CreatFamily(QDialog *parent = 0);
    ~CreatFamily();
    bool judgeEmpty();
    void clearAll();

private:
    Ui::CreatFamily *ui;
private slots:
    void returnbtnSlot();
    void confirmbtnSlot();
signals:
    void EmitToMenu();
};

#endif // CREATFAMILY_H
