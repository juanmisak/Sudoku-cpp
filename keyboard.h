#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <QIcon>
#include <QWidget>
#include "cell.h"

class QGridLayout;
class QPushButton;

class Keyboard : public QWidget
{
    Q_OBJECT
public:
    explicit Keyboard(QWidget *parent = 0);
    ~Keyboard();
    
signals:
    void numberSelected(int number);
    void modeChanged(Cell::Mode);

public slots:
    void activate();

private slots:
    void selectNumber();
    void setModeToFinal();
    void setModeToAnnotation();

private:
    QIcon icon1,icon2,icon3,icon4,icon5,icon6,icon7,icon8,icon9;
    QGridLayout *keyboard;
    QPushButton *numbers[10];
    Cell *attachedCell;
    QIcon setIcon(int numero);
};

#endif // KEYBOARD_H
