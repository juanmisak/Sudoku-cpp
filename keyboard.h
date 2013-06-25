#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>

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

private slots:
    void selectNumber();

private:
    QGridLayout *keyboard;
    QPushButton *numbers[10];
};

#endif // KEYBOARD_H
