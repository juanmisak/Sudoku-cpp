#include "sudoku.h"

#include <cstdlib>
#include <ctime>

#include <QDebug>

Sudoku::Sudoku(QObject *parent) :
    QObject(parent)
{
}

void Sudoku::generate(int empty)
{
    static int preboard[] = {
        5,3,4,6,7,8,9,1,2,
        6,7,2,1,9,5,3,4,8,
        1,9,8,3,4,2,5,6,7,
        8,5,9,7,6,1,4,2,3,
        4,2,6,8,5,3,7,9,1,
        7,1,3,9,2,4,8,5,6,
        9,6,1,5,3,7,2,8,4,
        2,8,7,4,1,9,6,3,5,
        3,4,5,2,8,6,1,7,9,
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

    // Emit signal for filled cells
    for (int i =  0; i < BOARD_SIZE * BOARD_SIZE; i++)
        if (cell[i] != 0)
            emit cellChanged(i, cell[i]);
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
    int i, sum = 0, mul = 1;

    // validate columns
    for ( int x = 0; x < BOARD_SIZE; x++ ) {

        sum = 0; mul = 1;
        for ( int y = 0; y < BOARD_SIZE; y++) {
            i = x + BOARD_SIZE*y;
            sum += cell[i];
            mul *= cell[i];
        }

        if (sum != 45 || mul != 362880)
            return false;
    }

    // validate rows
    for( int y = 0; y < BOARD_SIZE; y++) {

        sum = 0; mul = 1;
        for( int x = 0; x < BOARD_SIZE; x++){
            i = x + 9*y;
            sum += cell[i];
            mul *= cell[i];
        }

        if (sum != 45 || mul != 362880)
            return false;
    }

    return true;
}

void Sudoku::badCells(int cells[])
{
}

void Sudoku::suggestedValues(int index, int suggestedValues[])
{
    int x0 = index % BOARD_SIZE;
    int y0 = index / BOARD_SIZE;

    int i = 0;

    /* Counter
     * 0 have the number of 1's, 1 have the number of
     * 2's... n have the number of n+1's in the board
     */
    int usedValues[BOARD_SIZE] = {0};

    for (int x = 0; x < BOARD_SIZE; x++)
        if (x != x0) {
            i = cell[x + y0*BOARD_SIZE];
            usedValues[i]++;
        }

    for (int y = 0; y < BOARD_SIZE; y++)
        if (y != y0) {
            i = cell[x0 + y*BOARD_SIZE];
            usedValues[i]++;
        }

    i = cell[x0-1 + (y0-1)*BOARD_SIZE];
    usedValues[i]++;
    i = cell[x0+1 + (y0-1)*BOARD_SIZE];
    usedValues[i]++;
    i = cell[x0-1 + (y0+1)*BOARD_SIZE];
    usedValues[i]++;
    i = cell[x0+1 + (y0+1)*BOARD_SIZE];
    usedValues[i]++;

    i = 0;
    for (int j = 0; j < BOARD_SIZE; j++) {
        /* if there is no use of the number in the
         * board then, suggest it */
        if (usedValues[j] == 0)
            suggestedValues[i++] = j+1;
    }
}

void Sudoku::setCellValue(int index, int value)
{
    if (cell[index] != value) {
        cell[index] = value;
        emit cellChanged(index, value);
    }
}

void Sudoku::setCellValue(int value, int x, int y)
{
    setCellValue(value, x + y*BOARD_SIZE);
}

int Sudoku::getCellValue(int index)
{
    return cell[index];
}
