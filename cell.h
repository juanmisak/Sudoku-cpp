#ifndef CELL_H
#define CELL_H
#include <QWidget>

#define N_ANNOTATIONS 9

class Keyboard;
class QGridLayout;
class QLabel;
class QPushButton;

/**
 * La clase Cell representa las celdas del tablero QtSudoku.
 * @author Ramón Carrillo, Esteban Muñoz
 */

class Cell : public QWidget
{
    Q_OBJECT
public:

    enum Mode {
        Annotation,
        Final
    };
    /**
        * Un constructor.
        * @param parent un argumento QWidget .
        * Una descripción más elaborada del constructor.
        */
    explicit Cell(QWidget *parent = 0);
    ~Cell();
    void setKeyboard(Keyboard *keyboard);
    int getValue();
    void setText(QString t);
    QString text();

signals:
    void valueChanged(int value);
    void clicked();
    
public slots:
    void setValue(int value);
    void setMode(Mode mode);

protected:
    void mouseReleaseEvent(QMouseEvent *event);

private slots:

private:
    Mode mode;
    QGridLayout *layout;
    QLabel *annotations[N_ANNOTATIONS];
    int emptyAnnotation;
    QPushButton *value;
    Keyboard *keyboard;
};

#endif // CELL_H
