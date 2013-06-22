#include "home.h"
#include "mainwindow.h"
#include "ui_home.h"
#include "developer.h"

Home::Home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Home)
  {
    ui->setupUi(this);
}

Home::~Home()
{
    delete ui;
}

void Home::on_pushButton_3_clicked()
{
    MainWindow *w;
    w = new MainWindow();
    this->setVisible(false);
    w->show();

}

void Home::on_pushButton_4_clicked()
{
    Developer *d;
    d = new Developer();
    d->setVisible(true);
    this->close();

}
