#ifndef FILEOPERATE_H
#define FILEOPERATE_H
#include <QWidget>
#include "tree.h"
namespace  Ui {
class FileOperate;
}
class FileOperate : public QWidget
{
    Q_OBJECT
public:
    explicit FileOperate(QWidget *parent=0);
    ~FileOperate();
    void FileSave(Tree*);
    void FileClean(Tree* &,QString);
    void FileRead(Tree* &,QString);
};

#endif // FILEOPERATE_H
