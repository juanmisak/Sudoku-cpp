#include "saver.h"

#include <QFile>
#include "sudoku.h"
#include <cstdlib>
/**
 * La clase Saver representa un Objeto que permite crear un archivo txt
 * del tablero que el jugador deseo guardar pero los valores que se guardan
 * son almacenado con un tipo de incriptacion adecuada.
 * @author Ramón Carrillo
 */
Saver::Saver(QObject *parent) :
    QObject(parent)
{
}

bool Saver::save(int cell[])
{
    QFile file(FILE_NAME);

    if ( !file.open(QIODevice::WriteOnly) )
        return false;

    // Generte mask
    char r = rand() % 256;

    // Store mask
    if ( !file.putChar(r) )
        return false;

    // Store cell values
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
    {
        char c = cell[i] ^ r;

        if ( !file.putChar(c) )
            return false;
    }

    file.close();

    return true;
}

bool Saver::load(int cell[])
{
    QFile file(FILE_NAME);

    if ( !file.open(QIODevice::ReadOnly) )
        return false;

    // Get mask
    char r;
    if ( !file.getChar(&r) )
        return false;

    // Get cell values
    char c;
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
        if ( file.getChar(&c) )
            cell[i] = c ^ r;
        else
            return false;

    return true;
}
