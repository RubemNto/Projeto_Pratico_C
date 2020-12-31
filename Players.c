#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "chess.h"
#include "fileio.h"


//char player [2] [12];
  typedef struct
{
    //Individual Player Struct - Defines PlayerName
    char nickname[12];
}player;
player players[2];
  

/* void createPlayers(){
  
     do
    {
        for (int i = 0; i < 2; i++)
        {
            printf("Player %d's Nickname ",(i + 1));
            scanf("%s",&player[i]);     
        }
        if (!strcmp(player[0] , player[1]))
        {
            printf("Players Nicknames can't be the same. Please choose new ones! \n");
        }
              
    } while (!strcmp(player[0] , player[1]));       
} */

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

       
} 

/* void setWhite(char player[] ){

    srand(time(0));
    int random = rand()%2;
    char temp[2];

    if(random = 1){
       
       // player[0] becomes player[1] and vice versa -----> player[0] always starts, but which one it is is random
        temp[0] = player[1];
        temp[1] = player[0];
        for (int i = 0; i < 2; i++)
        {
            player[i] = temp[i];
        }   
        printf("%s",player[0]);
        printf(" is White and will start the game");       
    }
    

    
} */

 void setWhite(player players[2]){

    srand(time(NULL));
    int random = rand();
    player temp[2];

    if(random % 2 == 1){
       
       // player[0] becomes player[1] and vice versa -----> player[0] always starts, but which one it is is random
        temp[0] = players[1];
        temp[1] = players[0];
        for (int i = 0; i < 2; i++)
        {
            players[i] = temp[i];
        }   
        printf(players[0].nickname);
        printf(" is White and will start the game \n \n");       
    }
    else{ //ELSE ALL REMAINS THE SAME AND INITIAL PLAYER[0] STARTS
        printf(players[0].nickname);
        printf(" is White and will start the game \n \n"); 
    }
} 
