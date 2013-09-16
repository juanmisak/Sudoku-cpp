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
    mainwindow = new MainWindow();
    d = new Developer();
    e = new Estadistica();
}

Home::~Home()
{
    delete ui;
}




void Home::on_btnJugar_clicked()
{

        //Nivel facil 36 celdas vacias."""
       if(ui->radioButtonFacil->isChecked())
           dificultad=1;

       //Nivel intermedio 36+9 = 45 celdas vacias.
       else if (ui->radioButtonDificil->isChecked())
           dificultad=3;

       //Nivel dificil 36+9+9 = 63 celdas vacias.
       else if (ui->radioButtonIntermedio->isChecked())
           dificultad=2;


       this->setVisible(false);
       mainwindow->show();
       mainwindow->setName(ui->txtNombre->text());
       mainwindow->newGame(dificultad);


}

void Home::on_btnEstadistica_clicked()
{

    e->graficarEstadisticas("Juan",133,"Esteban",106,"Ramón",84,"Micka",50,"Andrea",40);
    e->setVisible(true);
    this->close();
}

void Home::on_btnDesarrolladores_clicked()
{

    d->setVisible(true);
    this->close();
}
