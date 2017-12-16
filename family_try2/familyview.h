#ifndef FAMILYVIEW_H
#define FAMILYVIEW_H

#include <QWidget>

namespace Ui {
class FamilyView;
}

class FamilyView : public QWidget
{
    Q_OBJECT

public:
    explicit FamilyView(QWidget *parent = 0);
    ~FamilyView();

private:
    Ui::FamilyView *ui;
};

#endif // FAMILYVIEW_H
