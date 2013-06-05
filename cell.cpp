#include "cell.h"

Cell::Cell(QWidget *parent) :
    QTextEdit(parent)
{
  this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
