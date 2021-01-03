#include <stdio.h>
#include "chess.h"
#include "fileio.h"
#include "Players.c"

int main()
{    
    createPlayers();
    setWhite(players);
    createTable();
    createFile();
    return 0;
}