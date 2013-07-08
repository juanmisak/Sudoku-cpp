#include "cell.h"
#include "keyboard.h"

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

Cell::Cell(QWidget *parent) :
    QWidget(parent),
    mode(Cell::Final),
    emptyAnnotation(0)
{
    QFont font1;
          font1.setFamily(QStringLiteral("Arial"));
          font1.setPointSize(16);
          font1.setBold(false);
          font1.setWeight(50);
          //this->setFont(font1);
    //QIcon icon1;
    //       icon1.addFile(QStringLiteral(":/images/Mysitemyway-Blue-Jeans-Social-Media-Delicious-square.ico"), QSize(), QIcon::Normal, QIcon::Off);
    //this->setIcon(icon1);
    //this->setIconSize(QSize(30, 30));
    this->backgroundRole();    
    //this->setFlat(true);

    value = new QPushButton();
    connect(value, &QPushButton::clicked, this, &Cell::clicked);

    for (int i = 0; i < N_ANNOTATIONS; i++) {
        annotations[i] = new QLabel("__");
    }

    layout = new QGridLayout(this);

    setMode(Cell::Final);
}

Cell::~Cell()
{
    delete value;
    for (int i = 0; i < N_ANNOTATIONS; i++)
        delete annotations[i];
    delete layout;
}

void Cell::setKeyboard(Keyboard *keyboard)
{
    this->keyboard = keyboard;
    connect(this, &Cell::clicked, keyboard, &Keyboard::activate);
}

void Cell::setValue(int value)
{
    switch (mode) {
        // If it's in final mode, set the final value
        case Cell::Final:
            if (this->value->text().toInt() != value)
            {
                this->value->setText(QString::number(value));
                emit valueChanged(value);
            }
            break;

        // If it's in annotation mode, add an annotation
        case Cell::Annotation:
            annotations[emptyAnnotation]->setText(QString::number(value));
            emptyAnnotation = (emptyAnnotation + 1) % N_ANNOTATIONS;
            break;
    }
}

int Cell::getValue()
{
    if (mode != Cell::Final) return 0;

    return this->value->text().toInt();
}

void Cell::setMode(Mode mode)
{
    // if (this->mode == mode) return;

    // Remove all elements from the layout
    while(layout->takeAt(0) != 0);

    switch (mode) {

        case Cell::Final:
            for (int i = 0; i < N_ANNOTATIONS; i++)
                annotations[i]->hide();
            value->show();
            layout->addWidget(value);
            break;

        case Cell::Annotation:
            value->hide();
            for (int i = 0; i < N_ANNOTATIONS; i++)
            {
                annotations[i]->show();
                layout->addWidget(annotations[i], i/3, i%3);
            }
            break;

    }

    this->mode = mode;
}

void Cell::setText(QString t)
{
    value->setText(t);
}

QString Cell::text()
{
    return value->text();
}

void Cell::mouseReleaseEvent(QMouseEvent *)
{
    emit clicked();
}
