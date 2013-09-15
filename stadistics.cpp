#include "stadistics.h"
#include "ui_stadistics.h"
#include "qgraphicsview.h"
#include "QGraphicsBlurEffect"
#include <QGraphicsRectItem>
#include "qgraphicsitem.h"

stadistics::stadistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stadistics)
{
    ui->setupUi(this);
    lienzo = new QGraphicsScene(this);
    ui->graLienzo->setScene(lienzo);
}

    void stadistics::graficarEstadisticas(QString nombre1,qreal puntaje1,
                                          QString nombre2,qreal puntaje2,
                                          QString nombre3,qreal puntaje3,
                                          QString nombre4,qreal puntaje4,
                                          QString nombre5,qreal puntaje5){
    qreal Puntuacion1 = 100*puntaje1/puntaje1,
          Puntuacion2 = 100*puntaje2/puntaje1,
          Puntuacion3 = 100*puntaje3/puntaje1,
          Puntuacion4 = 100*puntaje4/puntaje1,
          Puntuacion5 = 100*puntaje5/puntaje1,
          width=40;


    QBrush blackpen(Qt::black);
    QBrush blackBrush(Qt::black);
    rectangulo= lienzo->addRect(-100, 5, width, Puntuacion1);
    nombre=lienzo->addText(nombre1);
    nombre->setX(-100);

    rectangulo= lienzo->addRect(-200, 5, width,Puntuacion2);
    nombre=lienzo->addText(nombre2);
    nombre->setX(-200);//nombre->setY(y);

    rectangulo= lienzo->addRect(-300, 5, width, Puntuacion3);
    nombre=lienzo->addText(nombre3);
    nombre->setX(-300);//nombre->setY(y);

    rectangulo= lienzo->addRect(-400, 5, width, Puntuacion4);
    nombre=lienzo->addText(nombre4);
    nombre->setX(-500);//nombre->setY(y);

    rectangulo= lienzo->addRect(-500, 5, width, Puntuacion5);
    nombre=lienzo->addText(nombre5);
    nombre->setX(-600);//nombre->setY(y);

    }


stadistics::~stadistics()
{
    delete ui;
}
