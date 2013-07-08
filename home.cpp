#include "home.h"
#include "mainwindow.h"
#include "ui_home.h"
#include "developer.h"
#include "estadistica.h"
#include <QMessageBox>
#include <QLCDNumber>
#include <timer.h>
/**
 * La clase Home representa un Widget donde se da inicio a la
 * aplicacion dando al usuario una opcion para ingresar su
 * nombre y nivel de dificultad.
 * @author Juan Mite, Esteban Muñoz
 */
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

    Timer *cronometro;
    MainWindow *w; //Refetencia a la ventana que presenta la tabla sudoku
       QMessageBox msgBox;
       w = new MainWindow();
       cronometro = new Timer();
       bool noChenck = ui->radioButtonDificil->isChecked() | ui->radioButtonIntermedio->isChecked() | ui->radioButtonFacil->isChecked();
       if(noChenck == false){
           this->setVisible(false);
           w->show();
           w->dificultad=1;
           cronometro->start();
           msgBox.setText("Nivel facil, por defecto ;)");
           msgBox.setAutoFillBackground(false);
           msgBox.exec();
       }
       else if (ui->radioButtonDificil->isChecked()){
           this->setVisible(false);
           w->show();
           w->dificultad=3;
           cronometro->start();
           msgBox.setText("Nivel Dificil");
           msgBox.exec();
       }
       else if (ui->radioButtonIntermedio->isChecked()){
           this->setVisible(false);
           w->show();
           w->dificultad=2;
           cronometro->start();
           msgBox.setText("Nivel intermedio");
           msgBox.exec();
       }else{
           this->setVisible(false);
           w->show();
           w->dificultad=1;
           cronometro->start();
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
    d->setVisible(true);
    this->close();
}
