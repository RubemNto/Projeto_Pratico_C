#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "chess.h"
#include "fileio.h"

int main(void)
{
    startMenu();
    while(true)
    {        
        saveGame();
        confirmContinueGame();
        movePiece();
    }    
    return 0;
}
