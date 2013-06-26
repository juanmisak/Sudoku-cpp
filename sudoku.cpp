#include "sudoku.h"

#include <cstdlib>
#include <ctime>

Sudoku::Sudoku(QObject *parent) :
    QObject(parent)
{
}

void Sudoku::generate(int empty)
{
    static int preboard[] = {
        3,2,9,6,5,7,8,4,1,
        7,4,5,8,3,1,2,9,6,
        6,1,8,2,4,9,3,7,5,
        1,9,3,4,6,8,5,2,7,
        2,7,6,1,9,5,4,8,3,
        8,5,4,3,7,1,6,1,9,
        4,3,2,7,1,6,9,5,8,
        5,8,7,9,3,2,1,6,4,
        9,6,1,5,8,4,7,3,2
    };

    srand(time(NULL));

    // Copy base board
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
        cell[i] = preboard[i];

    // Swap block rows and columns at most 10 times each
    for(int swaps = 1; swaps <= 10; swaps++) {
        // Randomize the rows/columns
        int i = rand() % 3 + 1;
        int j = rand() % 3 + 1;

        if ( rand() % 2 )
            swapRow(i, j);

        if ( rand() % 2 )
            swapColumn(i, j);
    }

    // Empty cells
    while(empty > 0)
    {
        int i = rand() % (BOARD_SIZE * BOARD_SIZE);

        if (cell[i] != 0)
        {
            cell[i] = 0;
            empty--;
        }
    }
}

void Sudoku::swapRow(int i, int j)
{
    int temp, a, b;

    for(int y = 1; y <= 3; y++)
        for(int x = 0; x < BOARD_SIZE; x++)
        {
            a = x + i*y - 1;
            b = x + j*y - 1;
            temp = cell[a];
            cell[a]  = cell[b];
            cell[b] = temp;
        }
}

void Sudoku::swapColumn(int i, int j)
{
    int temp, a, b;

    for(int x = 1; x <= 3; x++)
        for(int y = 0; y < BOARD_SIZE; y++)
        {
            a = i*x + y - 1;
            b = j*x + y - 1;
            temp = cell[a];
            cell[a]  = cell[b];
            cell[b] = temp;
        }
}

bool Sudoku::validate()
{
    return true;
}

void Sudoku::badCells(int cells[])
{
}

void Sudoku::setCell(int value, int index)
{
    cell[index] = value;
}

void Sudoku::setCell(int value, int x, int y)
{
    setCell(value, x+y);
}
