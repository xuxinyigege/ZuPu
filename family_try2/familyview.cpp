#include "familyview.h"
#include "ui_familyview.h"

FamilyView::FamilyView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FamilyView)
{
    ui->setupUi(this);
}

FamilyView::~FamilyView()
{
    delete ui;
}
