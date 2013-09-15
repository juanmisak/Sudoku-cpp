#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QTimer>
#include <QMessageBox>
#include <QSettings>
#include <QResizeEvent>
#include "cell.h"
#include "keyboard.h"
#include <home.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dificultad(2)
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
    timer = new QTimer(this);




    sudoku->generate(dificultad*BOARD_SIZE + 3*BOARD_SIZE);


}

/**
 * Destructor
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete keyboard;   
}

void MainWindow::initTimer(int elapsedSeconds)
{
    timer->setInterval(1000);
    timer->start();
    h = (elapsedSeconds / 3600);
    m = (elapsedSeconds - 3600*h) / 60;
    s = (elapsedSeconds - 3600*h) % 60;
    connect(timer,SIGNAL(timeout()),this,SLOT(timerTimeout()));
}

void MainWindow::stopTimer()
{
    timer->stop();
}

/**
 *Funcion que permite tener actualizado el
 *timer mientras el jugador tenga activo el juego.
 */
void MainWindow::timerTimeout()
{
    s++;
    if (s > 59) {
        s = 0;
        m++;
    }
    else if (m > 59) {
            m = 0;
            h++;
    }
    else if (h > 23) {
                this->h = 0;
    }
    ui->btnTiempo->setText(QString ("%1:%2:%3")
                           .arg (h)
                           .arg (m)
                           .arg (s));
}

void MainWindow::initBoard()
{
    keyboard = new Keyboard( ui->centralWidget );

    int x, y;
    for ( int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++ ) {
        x = i % BOARD_SIZE;
        y = i / BOARD_SIZE;
        cell[i] = new Cell();

        if ( (y % 3 == 0 && y != 0) || ( y == 0 && x % 3 == 0) ){

             cell[i]->setAutoFillBackground(false);
        }

        ui->board->addWidget(cell[i], y, x);

        cell[i]->setKeyboard(keyboard);
    }
}

void MainWindow::newGame(QString name,int elapsedSeconds = 0 , Sudoku *sudoku = NULL)
{
    if (sudoku == NULL){
        this->sudoku = new Sudoku();
        this->sudoku->generate(getDifficulty()*BOARD_SIZE + 3*BOARD_SIZE);
    }
    else{
        this->sudoku = sudoku;        
    }
    connect(sudoku, &Sudoku::cellValueChanged, this, &MainWindow::setCellValue);
    this->sudoku->triggerChanges();
    disconnect(sudoku, &Sudoku::cellValueChanged, this, &MainWindow::setCellValue);
    // Update the model when the view is changed
    connect(this, &MainWindow::cellValueChanged, this->sudoku, &Sudoku::setCellValue);
    initTimer(elapsedSeconds);
    ui->btnJugador->setText(name);

}

void MainWindow::endGame()
{

}

void MainWindow::setCellValue(int index, int value)
{
    cell[index]->setValue(value);
    cell[index]->setDisabled(true);
}

void MainWindow::setCellValueFromView(int value)
{
    Cell *c = (Cell *) sender();

    int index = 0;
    for ( ; index < BOARD_SIZE * BOARD_SIZE; index++)
        if ( c == cell[index] )
            break;
    emit cellValueChanged(index, value);
}

void MainWindow::setDifficulty(int value)
{
    this->dificultad = value;
}

int MainWindow::getDifficulty()
{
    return this->dificultad;
}

void MainWindow::on_actionSalir_triggered()
/**
 * Evento que permite salir de la aplicacion.
 * @author Esteban Muñoz.
 */
{
    qApp->quit();
}

void MainWindow::on_finishButton_clicked()
{
    QMessageBox msj;

    msj.setText( sudoku->validate() ? "Tablero válido" : "Tablaro NO válido" );
    msj.exec();
}

void MainWindow::on_actionSALIR_triggered()
{
    this->close();
}

void MainWindow::on_actionATRAS_triggered()
{
    Home *home;
    home = new Home();
    home->setVisible(true);
    this->close();
}

