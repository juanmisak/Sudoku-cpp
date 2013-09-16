#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QTimer>
#include <QPushButton>
#include <QMessageBox>
#include "keyboard.h"
#include "cell.h"
#include "home.h"
#include "saver.h"

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
    // Generate sudoku and make the board visible,
    sudoku = new Sudoku();
    connect(sudoku, &Sudoku::cellChanged, this, &MainWindow::setCellValue);
    sudoku->generate(dificultad*BOARD_SIZE + 3*BOARD_SIZE);
    disconnect(sudoku, &Sudoku::cellChanged, this, &MainWindow::setCellValue);
    initTimer(0);
    // Update the model when the view is changed
    connect(this, &MainWindow::cellValueChanged, sudoku, &Sudoku::setCellValue);
}

/**
 * Destructor
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete keyboard;
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
/*
        connect(cell[i], &Cell::clicked , this, &MainWindow::celda_clicked);
        connect(cell[i], &Cell::clicked, keyboard, &Keyboard::show);
        connect(cell[i], &Cell::valueChanged, this, &MainWindow::setCellValueFromView);
*/
        cell[i]->setKeyboard(keyboard);
         cell[i]->setStyleSheet("font: italic 26pt Courier 20 Pitch; background-color: rgb(82, 163, 53);");
    }/*
    connect(ui->pushButton1, &QPushButton::clicked, this, &MainWindow::number_clicked);
    connect(ui->pushButton2, &QPushButton::clicked, this, &MainWindow::number_clicked);
    connect(ui->pushButton3, &QPushButton::clicked, this, &MainWindow::number_clicked);
    connect(ui->pushButton4, &QPushButton::clicked, this, &MainWindow::number_clicked);
    connect(ui->pushButton5, &QPushButton::clicked, this, &MainWindow::number_clicked);
    connect(ui->pushButton6, &QPushButton::clicked, this, &MainWindow::number_clicked);
    connect(ui->pushButton7, &QPushButton::clicked, this, &MainWindow::number_clicked);
    connect(ui->pushButton8, &QPushButton::clicked, this, &MainWindow::number_clicked);
    connect(ui->pushButton9, &QPushButton::clicked, this, &MainWindow::number_clicked);*/
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
void MainWindow::timerTimeout()
{
    this->s++;
    if (this->s > 59) {
        this->s = 0;
        this->m++;
        if (this->m > 59) {
            this->m = 0;
            this->h++;
            if (this->h > 23) {
                this->h = 0;
            }
        }
    }
    ui->btnTiempo->setText(QString ("%1:%2:%3")
                           .arg (h)
                           .arg (m)
                           .arg (s));
}

void MainWindow::setName(QString name)
{
    ui->btnJugador->setText(name);
}

void MainWindow::on_actionSalir_triggered()
/**
 * Evento que permite salir de la aplicacion.
 * @author Esteban Muñoz.
 */
{
    qApp->quit();
}
/*
void MainWindow::celda_clicked()
{
    // Get input number
    Cell *cell = (Cell *) sender();
   //cell->setText(QString(selectedNumber));
    //cell->setIcon(icon1);

}

void MainWindow::number_clicked()
{
    QPushButton *button = (QPushButton *) sender();
        if (button == ui->pushButton1)
            icon1.addFile(QStringLiteral(": "), QSize(), QIcon::Normal, QIcon::Off);
        else if (button == ui->pushButton2)
            icon1.addFile(QStringLiteral(":/images/Numbers-2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        else if (button == ui->pushButton3)
            icon1.addFile(QStringLiteral(":/images/Numbers-3.ico"), QSize(), QIcon::Normal, QIcon::Off);
        else if (button == ui->pushButton4)
            icon1.addFile(QStringLiteral(":/images/Numbers-4.ico"), QSize(), QIcon::Normal, QIcon::Off);
        else if (button == ui->pushButton5)
            icon1.addFile(QStringLiteral(":/images/Numbers-5.ico"), QSize(), QIcon::Normal, QIcon::Off);
        else if (button == ui->pushButton6)
            icon1.addFile(QStringLiteral(":/images/Numbers-6.ico"), QSize(), QIcon::Normal, QIcon::Off);
        else if (button == ui->pushButton7)
            icon1.addFile(QStringLiteral(":/images/Numbers-7.ico"), QSize(), QIcon::Normal, QIcon::Off);
        else if (button == ui->pushButton8)
            icon1.addFile(QStringLiteral(":/images/Numbers-8.ico"), QSize(), QIcon::Normal, QIcon::Off);
        else if (button == ui->pushButton9)
            icon1.addFile(QStringLiteral(":/images/Numbers-9.ico"), QSize(), QIcon::Normal, QIcon::Off);
}*/

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

void MainWindow::on_actionJUEGO_NUEVO_triggered()
{

}

void MainWindow::on_endGameButton_triggered()
{
    QMessageBox msj;

    msj.setText( sudoku->validate() ? "Tablero válido" : "Tablaro NO válido" );
    msj.exec();
}

void MainWindow::on_actionGUARDAR_triggered()
{
 QMessageBox ms;
 saver->save(cell);
    ms.setText("Partida guardada");
    ms.exec();
}

void MainWindow::on_actionCARGAR_triggered()
{

}
