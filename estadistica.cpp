#include "estadistica.h"
#include "ui_estadistica.h"
#include "home.h"
#include "QGraphicsRectItem"
#include <QColor>

#include "QGraphicsScene"
#include "QGraphicsView"
#include "QGraphicsTextItem"

Estadistica::Estadistica(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Estadistica)
{
    ui->setupUi(this);
    lienzo=new QGraphicsScene(this);
    ui->graphicsView->setScene(lienzo);
    lienzo->setBackgroundBrush(QColor(82,163,53,255));

}

void Estadistica::graficarEstadisticas(QString nombre1,qreal puntaje1,
                                      QString nombre2,qreal puntaje2,
                                      QString nombre3,qreal puntaje3,
                                      QString nombre4,qreal puntaje4,
                                      QString nombre5,qreal puntaje5){
qreal Puntuacion1 = 200*puntaje1/puntaje1,
      Puntuacion2 = 200*puntaje2/puntaje1,
      Puntuacion3 = 200*puntaje3/puntaje1,
      Puntuacion4 = 200*puntaje4/puntaje1,
      Puntuacion5 = 200*puntaje5/puntaje1,
      width=40;

QBrush blackBrush(Qt::black);
QPen blackPen(Qt::black);

rectangulo= lienzo->addRect(80.0, 35.0, width,-Puntuacion1,blackPen,blackBrush);
nombre=lienzo->addText(nombre1);
nombre->setX(80);nombre->setY(40);

rectangulo= lienzo->addRect(160.0, 35.0, width,-Puntuacion2,blackPen,blackBrush);
nombre=lienzo->addText(nombre2);
nombre->setX(160);nombre->setY(40);

rectangulo= lienzo->addRect(240.0, 35.0, width,-Puntuacion3,blackPen,blackBrush);
nombre=lienzo->addText(nombre3);
nombre->setX(240);nombre->setY(40);

rectangulo= lienzo->addRect(320.0, 35.0, width,-Puntuacion4,blackPen,blackBrush);
nombre=lienzo->addText(nombre4);
nombre->setX(320);nombre->setY(40);

rectangulo= lienzo->addRect(400.0, 35.0, width,-Puntuacion5,blackPen,blackBrush);
nombre=lienzo->addText(nombre5);
nombre->setX(400);nombre->setY(40);

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
