#include "developer.h"
#include "ui_developer.h"
#include "home.h"

Developer::Developer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Developer)
{
    ui->setupUi(this);
}

Developer::~Developer()
{
    delete ui;
}





void Developer::on_btnInicio_clicked()
{
    Home *d;
    d = new Home();
    d->setVisible(true);
    this->close();
}
