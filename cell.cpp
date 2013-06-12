#include "cell.h"

Cell::Cell(QWidget *parent) :
    QTextEdit(parent)
{
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setFontItalic("true");
  setTextColor("#000066");
  setFontPointSize(17);
}
