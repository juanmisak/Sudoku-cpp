#include "cell.h"

Cell::Cell(QWidget *parent) :
    QTextEdit(parent)
{
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setFontItalic("true");
  setTextColor("#000066");
  setFontPointSize(17);
  setTextBackgroundColor(defaultBackgroundColor);
}

void Cell::swapBackgroundColor()
{
    QColor c1 = QColor("#CCCCFF");
    QColor c2 = QColor("#CCFFCC");

    QColor& c = (textBackgroundColor() == c1) ? c2 : c1;

    setTextBackgroundColor(c);
    defaultBackgroundColor = c;
}

QColor Cell::defaultBackgroundColor = QColor("#CCCCFF");
