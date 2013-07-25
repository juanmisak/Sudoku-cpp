#include "home.h"
#include "mainwindow.h"
#include "ui_home.h"
#include "developer.h"
#include "estadistica.h"
#include <QMessageBox>

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


    MainWindow *w; //Refetencia a la ventana que presenta la tabla sudoku
       QMessageBox msgBox;
       w = new MainWindow();
       bool noChenck = ui->radioButtonDificil->isChecked() | ui->radioButtonIntermedio->isChecked() | ui->radioButtonFacil->isChecked();
       if(noChenck == false){
           this->setVisible(false);
           w->show();
           w->dificultad=1;
           msgBox.setText("Nivel facil, por defecto ;)");
           msgBox.setAutoFillBackground(false);
           msgBox.exec();
       }
       else if (ui->radioButtonDificil->isChecked()){
           this->setVisible(false);
           w->show();
           w->dificultad=3;
           msgBox.setText("Nivel Dificil");
           msgBox.exec();
       }
       else if (ui->radioButtonIntermedio->isChecked()){
           this->setVisible(false);
           w->show();
           w->dificultad=2;
           msgBox.setText("Nivel intermedio");
           msgBox.exec();
       }else{
           this->setVisible(false);
           w->show();
           w->dificultad=1;
           msgBox.setText("Nivel facil");
           msgBox.exec();
       }

}

void Home::on_pushButton_4_clicked()
{
    Developer *d;
    d = new Developer();
    d->setVisible(true);
    this->close();

}



void Home::on_pushButton_2_clicked()
{
    Estadistica *d;
    d = new Estadistica();
    d->graficarEstadisticas("Juan",133,"Esteban",106,"Ramón",84,"Micka",50,"Andrea",40);
    d->setVisible(true);
    this->close();
}
