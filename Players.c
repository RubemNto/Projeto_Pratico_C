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
  
     do
    {
        for (int i = 0; i < 2; i++)
        {
            printf("Player %d's Nickname ",(i + 1));
            scanf("%s",&players[i].nickname);     
        }
        if (!strcmp(players[0].nickname , players[1].nickname))
        {
            printf("Players Nicknames can't be the same. Please choose new ones! \n");
        }
              
    } while (!strcmp(players[0].nickname , players[1].nickname)); 
    //asasdsads
       
}
