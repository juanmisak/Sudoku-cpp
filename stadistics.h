#ifndef STADISTICS_H
#define STADISTICS_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsView>
#include <QRect>

namespace Ui {
class stadistics;
}

class stadistics : public QDialog
{
    Q_OBJECT
    
public:
    explicit stadistics(QWidget *parent = 0);
    void graficarEstadisticas(QString nombre1,qreal puntaje1,QString nombre2,qreal puntaje2,QString nombre3,qreal puntaje3,QString nombre4,qreal puntaje4,QString nombre5,qreal puntaje5);
    ~stadistics();
    
private:
    Ui::stadistics *ui;
    QGraphicsScene *lienzo;
    QGraphicsRectItem *rectangulo;
    QGraphicsTextItem *nombre;
};

#endif // STADISTICS_H
