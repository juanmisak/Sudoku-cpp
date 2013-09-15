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

    w = new MainWindow();
    d = new Developer();
    e = new Estadistica();
  }

Home::~Home()
{
    delete ui;
    delete w;
    delete d;
    delete e;
}
/**
 * Inserta un título en la clase descripción.
 * Al ser el título obligatorio, si es nulo o vacío se lanzará
 * una excepción.
 *
 * @param titulo El nuevo título de la descripción.
 * @throws IllegalArgumentException Si titulo es null, está vacío o contiene sólo espacios.
 */
void Home::on_btnJugar_clicked()
{
       //Nivel facil 36 celdas vacias."""
       if(ui->radioButtonFacil->isChecked()){
           this->setVisible(false);

           w->setVisible(true);
           w->dificultad=1;
       }     
       else if (ui->radioButtonIntermedio->isChecked()){
           this->setVisible(false);
           w->show();
           w->dificultad=2;
       }
       else if (ui->radioButtonDificil->isChecked()){
           this->setVisible(false);
           w->show();
           w->dificultad=3;
       }else{
           this->setVisible(false);
           w->show();
           w->dificultad=1;
       }
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
