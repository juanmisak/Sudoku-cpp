#include "estadistica.h"
#include "ui_estadistica.h"
#include "home.h"

Estadistica::Estadistica(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Estadistica)
{
    ui->setupUi(this);
}

Estadistica::~Estadistica()
{
    delete ui;
}

void Estadistica::on_pushButton_7_clicked()
{
    Home *d;
    d = new Home();
    d->setVisible(true);
    this->close();
}
