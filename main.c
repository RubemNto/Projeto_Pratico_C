#include <stdio.h>
#include <stdbool.h>
#include "chess.h"

int main(void)
{
    bool playing = true;
    bool turn = true;    
    createTable();
    while(playing)
    {
        //writeCoordinatesOfPieces();
        movePiece(turn);
        turn = !turn;
    }
    //writeRandom();
    return 0;
}
