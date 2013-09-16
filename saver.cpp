#include "saver.h"

#include <QFile>
#include "sudoku.h"
#include <cstdlib>

/**
 * @class Saver
 * @author Juan Mite
 * @brief Con ayuda de esta clase se van a guardar los datos de la partida
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
