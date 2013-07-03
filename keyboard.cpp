#include "keyboard.h"

#include <QGridLayout>
#include <QPushButton>

#include <QDebug>

Keyboard::Keyboard(QWidget *parent) :
    QWidget(parent)
{
    setFixedHeight(200);
    setFixedWidth(150);
    move(0, 0);

    keyboard = new QGridLayout(this);
    keyboard->setSpacing(1);


    for ( int i = 0; i < 10; i++)
    {
        numbers[i] = new QPushButton( QString("%1").arg(i) );
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

void Keyboard::selectNumber()
{
    QPushButton *button = (QPushButton *) sender();

    emit numberSelected( button->text().toInt() );
}
