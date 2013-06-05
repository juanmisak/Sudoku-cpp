#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for( int x = 0; x < BOARD_SIZE; x++ )
    {
      for( int y = 0; y < BOARD_SIZE; y++ )
      {
        cell[x+y] = new Cell();
        ui->board->addWidget( cell[x+y], x, y );
      }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
