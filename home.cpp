#include "home.h"
#include "mainwindow.h"
#include "ui_home.h"

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
    this->close();
    w->show();

}
