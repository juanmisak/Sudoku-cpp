#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cell.h"
#include "sudoku.h"
#include <QLCDNumber>
namespace Ui {
class MainWindow;
}
/**
 * La clase Time representa un momento del tiempo.
 * @author Ramón Carrillo, Esteban Muñoz , Juan mite
 */
class Keyboard;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
      * Un constructor.
      * @param parent un argumento QWidget .
      * Una descripción más elaborada del constructor.
      */
    explicit MainWindow(QWidget *parent = 0);
    /**
      * Un destructor.
      * Una descripción más elaborada del destructor.
      */
    ~MainWindow();
    int dificultad;

<<<<<<< HEAD
=======
signals:
    void cellValueChanged(int index, int value);

>>>>>>> 8a7aa006b7705dd9a0c6dab4cfb8eadad6409c0c
private slots:
    void on_actionSalir_triggered();

    void number_clicked();
    void setCellValue(int index, int value);
    void setCellValueFromView(int value);
    void on_finishButton_clicked();

private:
    Ui::MainWindow *ui;
    Cell *cell[BOARD_SIZE * BOARD_SIZE];
    Sudoku *sudoku;
    Keyboard *keyboard;
    /**
      * Permite utilizar un icono .
      */
    QIcon icon1;
    char selectedNumber;

    /**
       * Inicializa el tablero que se mostrara en el layout.
       */
    void initBoard();
};

#endif // MAINWINDOW_H

