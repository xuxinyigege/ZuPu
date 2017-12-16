#include "creatfamily.h"
#include "ui_creatfamily.h"

CreatFamily :: CreatFamily(QWidget *parent);
    QWidget(parent),
    ui(new Ui::CreatFamily)
{
        ui->setupUi(this);
        ui->nameline->setPlaceholderText("name");
        ui->line->setPlaceholderText("generation");


