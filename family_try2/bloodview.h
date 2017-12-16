#ifndef BLOODVIEW_H
#define BLOODVIEW_H

#include <QWidget>

namespace Ui {
class BloodView;
}

class BloodView : public QWidget
{
    Q_OBJECT

public:
    explicit BloodView(QWidget *parent = 0);
    ~BloodView();

private:
    Ui::BloodView *ui;
};

#endif // BLOODVIEW_H
