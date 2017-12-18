#ifndef CREATFAMILY_H
#define CREATFAMILY_H

#include <QDialog>
#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QLineEdit>
#include <QButtonGroup>

namespace Ui {
class creatfamily;
}

class creatfamily : public QDialog
{
    Q_OBJECT

public:
    explicit creatfamily(QWidget *parent = 0);
    ~creatfamily();

    bool judgeEmpty();

    void clearAll();

private slots:
    void returnbtnSlot();
    void confirmbtnSlot();
    void onRadioClickGender(int);
    void onRadioClickIslive(int);
public slots:
    void comeMainMenu();
private:
    Ui::creatfamily *ui;
    QButtonGroup *buttongroup1, *buttongroup2;

signals:
    void EmitToMenu();
};

#endif // CREATFAMILY_H
