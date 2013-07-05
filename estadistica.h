#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <QWidget>

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
    
private slots:
    void on_pushButton_7_clicked();

private:
    Ui::Estadistica *ui;
};

#endif // ESTADISTICA_H
