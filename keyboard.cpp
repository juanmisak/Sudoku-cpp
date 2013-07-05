#include "keyboard.h"
#include "cell.h"

#include <QGridLayout>
#include <QIcon>

Keyboard::Keyboard(QWidget *parent) :
    QWidget(parent, Qt::Popup)
{
    setFixedHeight(150);
    setFixedWidth(150);

    keyboard = new QGridLayout(this);
    keyboard->setSpacing(1);


    for ( int i = 1; i <= 10; i++)
    {
        numbers[i] = new QPushButton( );
        numbers[i]->setFlat(true);
        numbers[i]->setText(QString::number(i));
        //QIcon icono = setIcon(i);
        //numbers[i]->setIcon(icono);
        //numbers[i]->setIconSize(QSize(20, 20));
        connect(numbers[i], &QPushButton::clicked, this, &Keyboard::selectNumber);

        /*
         * Given a number Z you can deduce a formula to get
         * its row and column. In orden to get the layout
         *  x 0 1 2
         * y
         * 0  7 8 9
         * 1  4 5 6
         * 2  3 2 1
         * 3      0
         *
         * one posible formula is
         * x = ( z + 2 ) % 3
         * y = 3 - ( z + 2 ) / 3
         */
        keyboard->addWidget( numbers[i], 3-(i+2)/3, (i+2)%3 );
    }
}

Keyboard::~Keyboard()
{
    for ( int i = 0; i < 10; i++)
        delete numbers[i];

    delete keyboard;
}

QIcon Keyboard::setIcon(int numero){

    switch (numero) {
    case 0:
         icon1.addFile(QStringLiteral(":/images/Numbers-1.ico"), QSize(), QIcon::Normal, QIcon::Off);return icon1;
        break;
    case 1:
         icon1.addFile(QStringLiteral(":/images/Numbers-2.ico"), QSize(), QIcon::Normal, QIcon::Off);return icon1;
        break;
    case 2:
        icon1.addFile(QStringLiteral(":/images/Numbers-3.ico"), QSize(), QIcon::Normal, QIcon::Off);return icon1;
        break;
    case 3:
        icon1.addFile(QStringLiteral(":/images/Numbers-4.ico"), QSize(), QIcon::Normal, QIcon::Off);return icon1;
        break;
    case 4:
        icon1.addFile(QStringLiteral(":/images/Numbers-5.ico"), QSize(), QIcon::Normal, QIcon::Off);return icon1;
        break;
    case 5:
        icon1.addFile(QStringLiteral(":/images/Numbers-6.ico"), QSize(), QIcon::Normal, QIcon::Off);return icon1;
        break;
    case 6:
          icon1.addFile(QStringLiteral(":/images/Numbers-7.ico"), QSize(), QIcon::Normal, QIcon::Off);return icon1;
        break;
    case 7:
       icon1.addFile(QStringLiteral(":/images/Numbers-8.ico"), QSize(), QIcon::Normal, QIcon::Off);return icon1;
        break;
    case 8:
          icon1.addFile(QStringLiteral(":/images/Numbers-9.ico"), QSize(), QIcon::Normal, QIcon::Off);return icon1;
        break;
    default:
        break;
    }

}

void Keyboard::selectNumber()
{
    QPushButton *button = (QPushButton *) sender();

    if (!button || !attachedCell) return;

    hide();

    emit numberSelected( button->text().toInt() );
    disconnect(this, &Keyboard::numberSelected, attachedCell, &Cell::setValue);
}

void Keyboard::activate()
{
    Cell *cell = (Cell *) sender();

    if (cell != 0)
    {
        this->move(cell->pos());
        connect(this, &Keyboard::numberSelected, cell, &Cell::setValue);
        attachedCell = cell;
        show();
    }
}
