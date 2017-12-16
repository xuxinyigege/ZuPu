#ifndef TREE_H
#define TREE_H
#include <QWidget>
namespace  Ui {
class Tree;
}
class Tree : public QWidget
{
    Q_OBJECT
public:
    QString gender;
    QString IsLife;
    QString father_name;
    QString telnum;
    QString address;
    QString selfname;
    Tree *leftone;
    Tree *rightone;
    Tree *fatherone;
    Tree *brotherone;
    int generation;
};

#endif // TREE_H
