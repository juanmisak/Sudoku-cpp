#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGridLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
 /**
  * Constructor
  * Se inicializa el constructor con 81 celdas que seran
  * utilizadas como un tablero para el juego de QtSudoku v1.0.
  * @author Ramón Carrillo & Juan Mite.
  * @param x int que trabaja como fila.
  * @param y int que trabaja como columna.
  * @param cell QTextEdit que trabaja como celda del tablero.
  * @see ui referencia a MainWindow
  */

{
    ui->setupUi(this);
    initBoard();
}
/**
 * Destructor
 */
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initBoard()
{
    for ( int x = 0; x < BOARD_SIZE; x++ )
    {
      for( int y = 0; y < BOARD_SIZE; y++ )
      {
        cell[x+y] = new Cell();

        if ( (y % 3 == 0 && y != 0) || ( y == 0 && x % 3 == 0) )
          cell[x+y]->swapBackgroundColor();

        // TODO This this should be here

        cell[x+y]->setText(":)");
        ui->board->addWidget( cell[x+y], x, y);
      }
    }    
}


void MainWindow::on_actionSalir_triggered()
/**
 * Evento que permite salir de la aplicacion.
 * @author Esteban Muñoz.
 */
{
    qApp->quit();
}


