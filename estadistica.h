#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <QWidget>
#include<QtGui>
#include<QtCore>
#include<QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>

namespace Ui {
class Estadistica;
}
/**
 * La clase Estadistica representa un Widget para los jugadores.
 * @author Juan Mite
 */

class Estadistica : public QWidget
{
    Q_OBJECT
    
public:
    explicit Estadistica(QWidget *parent = 0);
    ~Estadistica();
    void graficarEstadisticas(QString nombre1,qreal puntaje1,QString nombre2,qreal puntaje2,QString nombre3,qreal puntaje3,QString nombre4,qreal puntaje4,QString nombre5,qreal puntaje5);
private slots:
    void on_pushButton_7_clicked();

private:
    Ui::Estadistica *ui;
    QGraphicsScene *lienzo;
    QGraphicsWidget *icono;
    QGraphicsRectItem *rectangulo;
    QGraphicsTextItem *nombre;

};

#endif // ESTADISTICA_H
