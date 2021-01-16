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
        movePiece(turn);
        turn = !turn;
        //checkKing(turn)
    }    
    return 0;
}
