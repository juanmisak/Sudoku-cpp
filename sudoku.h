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
    int getCellValue(int index);

signals:
    void cellChanged(int index, int value);
    
public slots:
    void setCellValue(int index, int value);

private:
    void swapBigRow(int i, int j);
    void swapBigColumn(int i, int j);
    void swapRow(int bigRow, int i, int j);
    void swapColumn(int bigColumn, int i, int j);
    void swap(int x1, int y1, int x2, int y2);

    int cell[BOARD_SIZE * BOARD_SIZE];
};

#endif // SUDOKU_H
