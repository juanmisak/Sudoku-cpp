#ifndef SUDOKU_H
#define SUDOKU_H

#include <QObject>

#define BOARD_SIZE 9

class Sudoku : public QObject
{
    Q_OBJECT
public:
    explicit Sudoku(QObject *parent = 0);
    void generate(int empty);
    bool validate();
    void badCells(int cells[]);
    void suggestedValues(int index, int suggestedCells[]);

signals:
    
public slots:
    void setCell(int value, int index);
    void setCell(int value, int x, int y);

private:
    void swapRow(int i, int j);
    void swapColumn(int i, int j);

    int cell[BOARD_SIZE * BOARD_SIZE];
};

#endif // SUDOKU_H
