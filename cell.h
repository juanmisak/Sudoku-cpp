#ifndef CELL_H

#define CELL_H

#include <QTextEdit>

class Cell : public QTextEdit
{
    Q_OBJECT
public:
    explicit Cell(QWidget *parent = 0);

    void swapBackgroundColor();
    
signals:
    
public slots:
    
private:
    static QColor defaultBackgroundColor;
};

#endif // CELL_H
