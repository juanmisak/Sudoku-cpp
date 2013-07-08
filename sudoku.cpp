#include "sudoku.h"

#include <cstdlib>
#include <ctime>
#include <QMessageBox>

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
    int sumTotal=0,multTotal=1,contColumna=0,multCol=1,contFila =0,multFila=1;
    QMessageBox mensaje;
    for ( int x = 0; x < BOARD_SIZE; x++ ){ //valida columnas
        int n=0;
        contColumna=0,multCol=1;
        for( int z = 0; z < BOARD_SIZE; z++){
        n=x+(9*z);
        contColumna=contColumna+cell[n];
        multCol=multCol*cell[n];
        if(contColumna!=45 && multCol!=362880){
            mensaje.setText("Error en la columna "+x);
            mensaje.exec();
            return false;
        }}
    }
      for( int y = 0; y < BOARD_SIZE; y++){ //valida las filas
          int n=0;
          contFila =0,multFila=1;
          for( int z = 0; z < BOARD_SIZE; z++){
          n=z+(9*y);
          contFila=contFila+cell[n];
          multFila=multFila+cell[n];
          if(contFila!=45 && multFila!=362880){
              mensaje.setText("Error en la fila "+y);
              mensaje.exec();
              return false;
          }}
      }
      sumTotal=sumTotal+contFila;       //valida todo el tablero
      if(multTotal==3265920&& sumTotal==405){
          mensaje.setText("tablero válido");
          mensaje.exec();
          return true;}
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
