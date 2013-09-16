#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>
#include "keyboard.h"
#include "cell.h"
#include "home.h"

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

    // Generate sudoku and make the board visible,
    sudoku = new Sudoku();
    connect(sudoku, &Sudoku::cellChanged, this, &MainWindow::setCellValue);
    sudoku->generate(dificultad*BOARD_SIZE + 3*BOARD_SIZE);
    disconnect(sudoku, &Sudoku::cellChanged, this, &MainWindow::setCellValue);

    connect(keyboard, &Keyboard::numberSelected, this, &MainWindow::diag);

//    diag(0);

/*    for(int i = 0; i < BOARD_SIZE * BOARD_SIZE; i = i + 10) {
        connect(cell[i], &Cell::valueChanged, this, &MainWindow::diag);
    }
*/
    // Update the model when the view is changed
    connect(this, &MainWindow::cellValueChanged, sudoku, &Sudoku::setCellValue);
}

void MainWindow::diag(int x) {
    int sum = 0;

    for(int i = 0; i < BOARD_SIZE * BOARD_SIZE; i = i + 10) {
        sum += cell[i]->getValue();
    }
    ui->label->setText(QString::number(sum));
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
        cell[i]->setStyleSheet("font: italic 26pt Courier 20 Pitch; background-color: rgb(82, 163, 53);");
/*
        if ( (y % 3 == 0 && y != 0) || ( y == 0 && x % 3 == 0) ){

             cell[i]->setAutoFillBackground(false);

        }
*/
        ui->board->addWidget(cell[i], y, x);
/*
        connect(cell[i], &Cell::clicked , this, &MainWindow::celda_clicked);
        connect(cell[i], &Cell::clicked, keyboard, &Keyboard::show);
        connect(cell[i], &Cell::valueChanged, this, &MainWindow::setCellValueFromView);
*/
        cell[i]->setKeyboard(keyboard);
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


void MainWindow::on_endGameButton_triggered()
{
    QMessageBox msj;

    msj.setText( sudoku->validate() ? "Tablero válido" : "Tablaro NO válido" );
    msj.exec();
}
