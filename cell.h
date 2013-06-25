#ifndef CELL_H
#define CELL_H
#include <QPushButton>

class Keyboard;

class Cell : public QPushButton
{
    Q_OBJECT
public:
    explicit Cell(QWidget *parent = 0);
    void setKeyboard(Keyboard *keyboard);

signals:
    
public slots:

private slots:
    void activateKeyboard();

private:
    Keyboard *keyboard;

};

#endif // CELL_H
