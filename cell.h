#ifndef CELL_H
#define CELL_H
#include <QPushButton>

class Keyboard;
/**
 * La clase Cell representa las celdas del tablero QtSudoku.
 * @author Ramón Carrillo, Esteban Muñoz
 */

class Cell : public QPushButton
{
    Q_OBJECT
public:
    /**
        * Un constructor.
        * @param parent un argumento QWidget .
        * Una descripción más elaborada del constructor.
        */
    explicit Cell(QWidget *parent = 0);
    void setKeyboard(Keyboard *keyboard);

signals:
    
public slots:

private slots:
    void activateKeyboard();

private:
    Keyboard *keyboard;

};

#endif // CELL_H
