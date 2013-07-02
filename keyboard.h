#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <QIcon>
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
    QIcon icon1;
    QGridLayout *keyboard;
    QPushButton *numbers[10];
    QIcon setIcon(int numero);
};

#endif // KEYBOARD_H
