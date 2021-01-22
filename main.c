//_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "chess.h"
#include "fileio.h"

int main(void)
{
    bool playing = true;
    // createPlayers();
    // setWhite();    
    loadGame();
    createTable();
    while(playing)
    {        
        saveGame();
        movePiece();
        //checkKing(turn)
    }    
    return 0;
}
