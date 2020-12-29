#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "chess.h"
#include "fileio.h"

typedef struct
{
    //Individual Player Struct - Defines PlayerName
    char nickname[12];
}player;
player players[2];

void createPlayers(){

    for (int i = 0; i < 2; i++)
    {
        printf("Player %d 's Nickname",&i);
        gets(players[i].nickname);
    }
}
