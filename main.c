#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "chess.h"
#include "fileio.h"

int main(void)
{
    bool playing = true;
    // createPlayers();
    // setWhite();    
    // loadGame();
    //createTable();
    startMenu();
    while(playing)
    {        
        saveGame();
        confirmContinueGame();
        movePiece();        
        //checkKing(turn)
    }    
    return 0;
}
