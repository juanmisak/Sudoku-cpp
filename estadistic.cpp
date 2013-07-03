#include "estadistic.h"
#include "ui_estadistic.h"
#include <home.h>

Estadistic::Estadistic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Estadistic)
{
    ui->setupUi(this);
}

Estadistic::~Estadistic()
{
    delete ui;
}

void Estadistic::on_pushButton_7_clicked()
{
    Home *d;
    d = new Home();
    d->setVisible(true);
    this->close();
}
