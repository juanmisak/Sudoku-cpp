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
    // Copy base board
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
        cell[i] = preboard[i];

    srand(time(NULL));



    // Swap block rows and columns at most 10 times each
    for(int swaps = 1; swaps <= 30; swaps++) {
        // Randomize the rows/columns
        int i = rand() % 2;
        int j = rand() % 2;
        int k = rand() % 2;
        int l = rand() % 2;

        swapBigRow(i, j);
        swapBigColumn(i, j);
        swapRow(k, i, j);
        swapColumn(l, i, j);
    }

    // Empty cells
  /*  while(empty == 81)
    {
        int i = BOARD_SIZE * BOARD_SIZE;

        if (i != 10)
        {
            cell[i] = 0;
            empty--;
        }
    }*/
    for(int i=0;i<BOARD_SIZE * BOARD_SIZE;i++){
        if (i%2==1) cell[i]=0;
        if(i==26||i==74||i==78||i==62) cell[i] = 0;}


    for(int i=2;i<BOARD_SIZE * BOARD_SIZE;i=i*3)
        cell[i]=0;



    // Emit signal for filled cells
    for (int i =  0; i < BOARD_SIZE * BOARD_SIZE; i++)
        if (cell[i] != 0)
            emit cellChanged(i, cell[i]);


}

void Sudoku::swapBigRow(int i, int j)
{
    for(int y = 0; y < 3; y++)
        for(int x = 0; x < BOARD_SIZE; x++)
            swap(x, y+3*i, x, y+3*j);
}



void Sudoku::swapBigColumn(int i, int j)
{
    for(int x = 0; x < 3; x++)
        for(int y = 0; y < BOARD_SIZE; y++)
            swap(x+3*i, y, x+3*j, y);
}

void Sudoku::swapRow(int bigRow, int i, int j)
{
    for(int x = 0; x < BOARD_SIZE; x++)
        swap(x, 3*bigRow + i, x, 3*bigRow + j);
}

void Sudoku::swapColumn(int bigColumn, int i, int j)
{
    for(int y = 0; y < BOARD_SIZE; y++)
        swap(3*bigColumn + i, y, 3*bigColumn + j, y);
}

inline void Sudoku::swap(int x1, int y1, int x2, int y2)
{
    int temp, a, b;

    a = x1 + y1*BOARD_SIZE;
    b = x2 + y2*BOARD_SIZE;
    temp = cell[a];
    cell[a]  = cell[b];
    cell[b] = temp;
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
            i = x + BOARD_SIZE*y;
            sum += cell[i];
            mul *= cell[i];
        }

        if (sum != 45 || mul != 362880)
            return false;
    }

    for (int i = 0; i < BOARD_SIZE; i++) {

        sum = 0; mul = 1;
        for (int j = 0; j < BOARD_SIZE; j++) {
            int x = ( j % 3 ) + ( (i*3) % 3 );
            int y = ( j / 3 ) + ( (i/3) % 3 );

            i = x + BOARD_SIZE*y;
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

int Sudoku::getCellValue(int index)
{
    return cell[index];
}
