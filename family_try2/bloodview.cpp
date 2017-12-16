#include "bloodview.h"
#include "ui_bloodview.h"

BloodView::BloodView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BloodView)
{
    ui->setupUi(this);
}

BloodView::~BloodView()
{
    delete ui;
}
