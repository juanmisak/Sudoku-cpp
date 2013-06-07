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
        int cont = 0;
        cont = cont + y + BOARD_SIZE * x;
        cell[x+y] = new Cell();
        cell[x+y]->setFontItalic("true");
        cell[x+y]->setTextColor("#000066");
        cell[x+y]->setFontPointSize(17);
        if((((cont)<3) && ((cont)>-1))||(((cont)<12) && ((cont)>8))||(((cont)<21) && ((cont)>17))||
             (((cont)<9) && ((cont)>5))||(((cont)<18) && ((cont)>14))||(((cont)<27) && ((cont)>23))||
            (((cont)<63) && ((cont)>59))||(((cont)<72) && ((cont)>68))||(((cont)<81) && ((cont)>77))||
            (((cont)<57) && ((cont)>53))||(((cont)<66) && ((cont)>62))||(((cont)<75) && ((cont)>71))||
            (((cont)<33) && ((cont)>29))||(((cont)<42) && ((cont)>38))||(((cont)<51) && ((cont)>47)))
        {
            cell[x+y]->setTextBackgroundColor("#CCCCFF");
        }
        else
            cell[x+y]->setTextBackgroundColor("#CCFFCC");
        cell[x+y]->setText(QString::number(cont));
        ui->board->addWidget( cell[x+y], x, y );
      }
    }
}

MainWindow::~MainWindow()
{
    delete ui;}

void MainWindow::on_actionSalir_triggered()
{
    qApp->quit();
}
