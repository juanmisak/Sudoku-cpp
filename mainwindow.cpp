#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGridLayout>
#include <QPushButton>


#include <QDebug>

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
    for ( int x = 0; x < BOARD_SIZE; x++ ){
      for( int y = 0; y < BOARD_SIZE; y++ ){
        cell[x+y] = new Cell();
        //cell[x+y]->setText("O.O");
        ui->board->addWidget( cell[x+y], x, y);

        //connect(cell[x+y],SIGNAL(clicked()) , this, SLOT(celda_clicked()));
        connect(cell[x+y],&Cell::clicked , this, &MainWindow::celda_clicked);
      }
    }
    connect(ui->pushButton1, &QPushButton::clicked, this, &MainWindow::number_clicked);
    connect(ui->pushButton2, &QPushButton::clicked, this, &MainWindow::number_clicked);
    connect(ui->pushButton3, &QPushButton::clicked, this, &MainWindow::number_clicked);
    connect(ui->pushButton4, &QPushButton::clicked, this, &MainWindow::number_clicked);
    connect(ui->pushButton5, &QPushButton::clicked, this, &MainWindow::number_clicked);
    connect(ui->pushButton6, &QPushButton::clicked, this, &MainWindow::number_clicked);
    connect(ui->pushButton7, &QPushButton::clicked, this, &MainWindow::number_clicked);
    connect(ui->pushButton8, &QPushButton::clicked, this, &MainWindow::number_clicked);
    connect(ui->pushButton9, &QPushButton::clicked, this, &MainWindow::number_clicked);
}

void MainWindow::on_actionSalir_triggered()
/**
 * Evento que permite salir de la aplicacion.
 * @author Esteban Muñoz.
 */
{
    qApp->quit();
}

void MainWindow::celda_clicked()
{
    // Get input number
    Cell *cell = (Cell *) sender();
   //cell->setText(QString(selectedNumber));
    cell->setIcon(icon1);

}

void MainWindow::number_clicked()
{
    QPushButton *button = (QPushButton *) sender();


        if (button == ui->pushButton1)
            icon1.addFile(QStringLiteral(":/images/Numbers-1.ico"), QSize(), QIcon::Normal, QIcon::Off);
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
/*
    if (button == ui->pushButton1)
        selectedNumber = '1';
    else if (button == ui->pushButton2)
        selectedNumber = '2';
    else if (button == ui->pushButton3)
        selectedNumber = '3';
    else if (button == ui->pushButton4)
        selectedNumber = '4';
    else if (button == ui->pushButton5)
        selectedNumber = '5';
    else if (button == ui->pushButton6)
        selectedNumber = '6';
    else if (button == ui->pushButton7)
        selectedNumber = '7';
    else if (button == ui->pushButton8)
        selectedNumber = '8';
    else if (button == ui->pushButton9)
        selectedNumber = '9';*/
}
