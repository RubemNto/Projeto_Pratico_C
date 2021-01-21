#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "chess.h"
#include <stdbool.h>
#include <conio.h>
#include <math.h>

piece pieces1[16];//brancos
piece pieces2[16];//pretos

player players[2];
bool turn;
bool winW,winB;

int random;
void writeRandom()
{
    printf("%d",random);
}

void writeCoordinatesOfPieces()
{
    for (int i = 0; i < 16; i++)
    {
        printf("%c %d %c",pieces1[i].costume,pieces1[i].posX,pieces1[i].posY);
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 16; i++)
    {
        printf("%c %d %c",pieces2[i].costume,pieces2[i].posX,pieces2[i].posY);
        printf("\n");
    }
}

void createPlayers(){
                            //CYCLE TO REQUEST FOR PLAYER'S NICKNAME AND STORE IT IN """THE PLAYERSLIST"""
     do                     //GRANTS PLAYERS DON'T PICK THE SAME NICKNAME
    {
        for (int i = 0; i < 2; i++)
        {
            do{
                printf("Player %d's Nickname:  ",(i + 1));
                gets(players[i].nickname);     

                if(strlen(players[i].nickname) > 12){
                    printf("Nickname is too long, maximum characters is 12. Please choose a new one! \n");
                }
            }while(strlen(players[i].nickname) > 12);
        }
        if (!strcmp(players[0].nickname , players[1].nickname))
        {
            printf("Players Nicknames can't be the same. Please choose new ones! \n");
        }
              
    } while (!strcmp(players[0].nickname , players[1].nickname));      
}

//--------------------   FUNCTION TO INFORM THE PLAYERS OF WHO PLAYS FIRST/ IS WHITE  ------------------//
void checkGame()
{    
    bool foundKingW;
    bool foundKingB;
    for (int i = 0; i < sizeof pieces1/sizeof pieces1[0]; i++)
    {
        if(pieces1[i].costume == 'K')
        {
            foundKingW = true;
            break;
        }
    }
    for (int i = 0; i < sizeof pieces2/sizeof pieces2[0]; i++)
    {
        if(pieces2[i].costume == 'k')
        {
            foundKingB = true;
        }
    }
    
    if(foundKingW && !foundKingB)
    {
        winB = false;
        winW = true;
    }
    else if(!foundKingW && foundKingB)
    {
        winW = false;
        winB = true;
    }    
}

void setWhite(){

    srand(time(NULL));
    int random = rand();       //Generates random value -> If pair Player[0] stays player 0 ----> ELSE Player[0] becomes player[1]
    player temp[2];            //USER DOESN'T SEE THIS CHANGE HAPPENING, IT JUST ORGANIZES PLAYER ORDER

    if(random % 2 == 1){
       
       // player[0] becomes player[1] and vice versa -----> player[0] always starts, but which one it is is random
        temp[0] = players[1];
        temp[1] = players[0];
        for (int i = 0; i < 2; i++)
        {
            players[i] = temp[i];
        }   
        printf("\n ");
        printf(players[0].nickname);
        printf(" is White and will start the game! \n \n ");
        printf(players[1].nickname);
        printf(" is Black and will go second! \n \n");       
    }
    else{ //ELSE ALL REMAINS THE SAME AND INITIAL PLAYER[0] STARTS
        printf(players[0].nickname);
        printf(" is Whites and will start the game! \n \n ");
        printf(players[1].nickname);
        printf(" is Blacks and will go second! \n \n");  
    }
}

void createTable()
{
    srand(time(0));
    random = rand()%2;
    //creates a random table of black and white chess pieces represented 
    //by lower case and upper case characters respectively on the 8x8 board
    // piece pieces1[16];
    // piece pieces2[16];
    char costumes[9] = {'p','r','n','b','q','k','b','n','r'};
    if(random == 0)
    {
        for (int i = 0, b = 'A'; i < 16; i++,b++)
        {
            if(i<=7)
            {
                pieces1[i].costume = toupper(costumes[i+1]);
                pieces1[i].posY = b; 
                pieces1[i].posX = 1;

                pieces2[i].costume = costumes[i+1];
                pieces2[i].posY = b; 
                pieces2[i].posX = 8;
            }else
            {
                pieces1[i].costume = toupper(costumes[0]);
                pieces1[i].posY = b-8;
                pieces1[i].posX = 2;

                pieces2[i].costume = costumes[0];
                pieces2[i].posY = b-8; 
                pieces2[i].posX = 7;
            }        
        }
    }else
    {
        for (int i = 0, b = 'A'; i < 16; i++,b++)
        {
            if(i<=7)
            {
                pieces1[i].costume = toupper(costumes[i+1]);
                pieces1[i].posY = b; 
                pieces1[i].posX = 8;

                pieces2[i].costume = costumes[i+1];
                pieces2[i].posY = b; 
                pieces2[i].posX = 1;
            }else
            {
                pieces1[i].costume = toupper(costumes[0]);
                pieces1[i].posY = b-8;
                pieces1[i].posX = 7;

                pieces2[i].costume = costumes[0];
                pieces2[i].posY = b-8; 
                pieces2[i].posX = 2;
            }        
        }
    }

    printf("   A");
    for (int i = 'B'; i <= 'H'; i++)
    {
        printf("  %c",i);
    }
    printf("\n");    
    if(random == 0)
    {
        //upper case top        
        for (int l = 0; l < 8; l++)//creates lines
        {
            printf("%d ", l+1);
            for (int c = 0; c < 8; c++)//create colums
            {
                if(l == 0)
                {
                    printf("[%c]",pieces1[c].costume);
                }else if(l == 1)
                {
                    printf("[%c]",pieces1[c+8].costume);
                }else if(l == 6)
                {
                    printf("[%c]",pieces2[c+8].costume);
                }else if(l == 7)
                {
                    printf("[%c]",pieces2[c].costume);
                }else
                {
                    printf("[ ]");
                }
            }
            printf("\n");            
        }
    }else
    {
        //upper case down
        for (int l = 0; l < 8; l++)//creates lines
        {
            printf("%d ", l+1);
            for (int c = 0; c < 8; c++)//create colums
            {
                if(l == 0)
                {
                    printf("[%c]",pieces2[c].costume);
                }else if(l == 1)
                {
                    printf("[%c]",pieces2[c+8].costume);
                }else if(l == 6)
                {
                    printf("[%c]",pieces1[c+8].costume);
                }else if(l == 7)
                {
                    printf("[%c]",pieces1[c].costume);
                }else
                {
                    printf("[ ]");
                }
            }
            printf("\n");    
        }
    }
}

void reCreateTable()
{
    bool foundPiece;
    system("cls");
    printf("   A");
    for (int i = 'B'; i <= 'H'; i++)
    {
        printf("  %c",i);
    }
    printf("\n");
    
    for (int l = 1; l <= 8; l++)
    {
        printf("%d ", l);
        for (int c = 65; c <= 72; c++)
        {
            for(int p = 0; p < 16; p++)
            {
                if(pieces1[p].posX == l && pieces1[p].posY == c)
                {
                    printf("[%c]",pieces1[p].costume);
                    foundPiece = true;
                    break;
                }else if(pieces2[p].posX == l && pieces2[p].posY == c)
                {
                    printf("[%c]",pieces2[p].costume);
                    foundPiece = true;
                    break;                    
                }              
            }
            if(foundPiece == false)
            {
                printf("[ ]");
            }
            foundPiece = false;                                    
        }
        printf("\n");
    }    
}

void movePiece(bool whiteTurn)
{
    int index = 0;
    int posX = 0;//select piece line
    char posY = 0;//select piece column
    char selectedPieceCostume = ' ';
    char answer = 0;
    piece selectedPiece;
    bool choose = false;
    //select piece
    //receive coordinates from the table and verify if exists in the table
    if(whiteTurn == true)
    {
        printf("<< %s turn >>\n",players[0].nickname);
    }else
    {
        printf("<< %s turn >>\n",players[1].nickname);
    }
        
    while(selectedPieceCostume == ' ' && choose == false)
    {
        //choose a line form the table
        do
        {
            printf("Select piece\n");
            printf("Line of the Piece: ");
            scanf("%d",&posX);
            if(posX <= 0 || posX > 8)//if the choice is outside of the table, teel the player that he is out of bounds
            {
                printf("Outside of the table\nWrite a valid number from the table!\n");
            }
        }while(posX <= 0 || posX > 8);

        do
        {
            printf("Column of the Piece: ");
            scanf(" %c",&posY);
            posY = toupper(posY);
            if(posY < 'A' || posY > 'H')//if the choice is outside of the table, teel the player that he is out of bounds
            {
                printf("Outside of the table\nWrite a valid Column from the table!\n");
            }
        }while(posY < 'A' || posY > 'H');
        
        for (int i = 0; i < 16; i++)
        {
            if(pieces1[i].posX == posX && pieces1[i].posY == posY)
            {
                selectedPieceCostume = pieces1[i].costume;
                // selectedPiece.costume = pieces1[i].costume;
                // selectedPiece.posX = posX;
                // selectedPiece.posY = posY;
                break;
            }else if(pieces2[i].posX == posX && pieces2[i].posY == posY)
            {
                selectedPieceCostume = pieces2[i].costume;
                // selectedPiece.costume = pieces2[i].costume;
                // selectedPiece.posX = posX;
                // selectedPiece.posY = posY;
                break;
            }
        }
        if(selectedPieceCostume == ' ')//if player selects a blank space
        {
            printf("Blank space, select a valid piece");
            selectedPieceCostume = ' ';
            posX = 0;
            posY=0;
            continue;
        }else if(whiteTurn == true && selectedPieceCostume != toupper(selectedPieceCostume))//if player selects a piece form the opponent
        {
            printf("Opponent piece selected, choose one of your own!\n");
            selectedPieceCostume = ' ';
            posX = 0;
            posY=0;
            continue;
        }else if(whiteTurn == false && selectedPieceCostume == toupper(selectedPieceCostume))//if player selects a piece form the opponent
        {
            printf("Opponent piece selected, choose one of your own!\n");
            selectedPieceCostume = ' ';
            posX = 0;
            posY=0;
            continue;
        }
        
        do{
            printf("Selected Piece %c(%d,%c)\nDo you wish to switch(Y/N)?",selectedPieceCostume,posX,posY);
            scanf(" %c",&answer);
            answer = toupper(answer);
            //printf("%c",answer);
            if(answer == 'Y')
            {
                choose = false;
                selectedPieceCostume = ' ';
                posX = 0;
                posY = 0;
                continue;
            }else if(answer == 'N')
            {
                choose = true;
                selectedPiece.costume = selectedPieceCostume;
                selectedPiece.posX = posX;
                selectedPiece.posY = posY;                
            }
        }while(answer != 'Y' && answer != 'N');

    }
    for (int i = 0; i < 16; i++)
    {
        if(whiteTurn == true)
        {
            if(selectedPiece.costume == pieces1[i].costume && selectedPiece.posX == pieces1[i].posX && selectedPiece.posY == pieces1[i].posY)
            {
                index = i;
                //pieces1[i] = selectedPiece;
                //printf("Selected Piece %c %d %c\n",pieces1[i].costume,pieces1[i].posX,pieces1[i].posY);    
                break;
            }
        }else if(whiteTurn == false)
        {
            if(selectedPiece.costume == pieces2[i].costume && selectedPiece.posX == pieces2[i].posX && selectedPiece.posY == pieces2[i].posY)
            {
                //pieces2[i] = selectedPiece;
                //printf("Selected Piece %c %d %c\n",pieces2[i].costume,pieces2[i].posX,pieces2[i].posY);
                index = i;    
                break;
            }
        }                
    }
    printf("Selected Piece Index(%d) %c(%d,%c)\n",index,selectedPiece.costume,selectedPiece.posX,selectedPiece.posY);
    
    //show possible coordinates
    posX = 0;//select new line to move
    posY = 0;//select new column to move
    
        if(selectedPiece.costume == 'p' || selectedPiece.costume == 'P')
        {
            //-> move forawrd only once
            //write available spaces
            int availablePositionsAttack[4] ={0};
            int availablePositions[2] = {0};
            int enemyIndex1,enemyIndex2;
            if(random == 0 && whiteTurn == true)
            {
                availablePositions[0] = selectedPiece.posX + 1;
                availablePositions[1] = selectedPiece.posY;
                if(selectedPiece.posY != 'A' && selectedPiece.posY !='H')
                {
                    availablePositionsAttack[0] = selectedPiece.posX + 1;
                    availablePositionsAttack[1] = selectedPiece.posY + 1;
                    availablePositionsAttack[2] = selectedPiece.posX + 1;
                    availablePositionsAttack[3] = selectedPiece.posY - 1;
                }
                else if(selectedPiece.posY == 'A')
                {
                    availablePositionsAttack[0] = selectedPiece.posX + 1;
                    availablePositionsAttack[1] = selectedPiece.posY + 1;
                    availablePositionsAttack[2] = selectedPiece.posX + 1;
                    availablePositionsAttack[3] = selectedPiece.posY + 1;
                }
                else if(selectedPiece.posY == 'H')
                {
                    availablePositionsAttack[0] = selectedPiece.posX + 1;
                    availablePositionsAttack[1] = selectedPiece.posY - 1;
                    availablePositionsAttack[2] = selectedPiece.posX + 1;
                    availablePositionsAttack[3] = selectedPiece.posY - 1;
                }
            }
            else if(random == 0 && whiteTurn == false)
            {
                availablePositions[0] = selectedPiece.posX - 1;
                availablePositions[1] = selectedPiece.posY;
                if(selectedPiece.posY != 'A' && selectedPiece.posY !='H')
                {
                    availablePositionsAttack[0] = selectedPiece.posX - 1;
                    availablePositionsAttack[1] = selectedPiece.posY + 1;
                    availablePositionsAttack[2] = selectedPiece.posX - 1;
                    availablePositionsAttack[3] = selectedPiece.posY - 1;
                }
                else if(selectedPiece.posY == 'A')
                {
                    availablePositionsAttack[0] = selectedPiece.posX - 1;
                    availablePositionsAttack[1] = selectedPiece.posY + 1;
                    availablePositionsAttack[2] = selectedPiece.posX - 1;
                    availablePositionsAttack[3] = selectedPiece.posY + 1;
                }
                else if(selectedPiece.posY == 'H')
                {
                    availablePositionsAttack[0] = selectedPiece.posX - 1;
                    availablePositionsAttack[1] = selectedPiece.posY - 1;
                    availablePositionsAttack[2] = selectedPiece.posX - 1;
                    availablePositionsAttack[3] = selectedPiece.posY - 1;
                }
            }
            else if(random == 1 && whiteTurn == true)
            {
                availablePositions[0] = selectedPiece.posX - 1;
                availablePositions[1] = selectedPiece.posY;
                if(selectedPiece.posY != 'A' && selectedPiece.posY !='H')
                {
                    availablePositionsAttack[0] = selectedPiece.posX - 1;
                    availablePositionsAttack[1] = selectedPiece.posY + 1;
                    availablePositionsAttack[2] = selectedPiece.posX - 1;
                    availablePositionsAttack[3] = selectedPiece.posY - 1;
                }
                else if(selectedPiece.posY == 'A')
                {
                    availablePositionsAttack[0] = selectedPiece.posX - 1;
                    availablePositionsAttack[1] = selectedPiece.posY + 1;
                    availablePositionsAttack[2] = selectedPiece.posX - 1;
                    availablePositionsAttack[3] = selectedPiece.posY + 1;
                }
                else if(selectedPiece.posY == 'H')
                {
                    availablePositionsAttack[0] = selectedPiece.posX - 1;
                    availablePositionsAttack[1] = selectedPiece.posY - 1;
                    availablePositionsAttack[2] = selectedPiece.posX - 1;
                    availablePositionsAttack[3] = selectedPiece.posY - 1;
                }
            }
            else if(random == 1 && whiteTurn == false)
            {
                availablePositions[0] = selectedPiece.posX + 1;
                availablePositions[1] = selectedPiece.posY;

                if(selectedPiece.posY != 'A' && selectedPiece.posY !='H')
                {
                    availablePositionsAttack[0] = selectedPiece.posX + 1;
                    availablePositionsAttack[1] = selectedPiece.posY + 1;
                    availablePositionsAttack[2] = selectedPiece.posX + 1;
                    availablePositionsAttack[3] = selectedPiece.posY - 1;
                }
                else if(selectedPiece.posY == 'A')
                {
                    availablePositionsAttack[0] = selectedPiece.posX + 1;
                    availablePositionsAttack[1] = selectedPiece.posY + 1;
                    availablePositionsAttack[2] = selectedPiece.posX + 1;
                    availablePositionsAttack[3] = selectedPiece.posY + 1;
                }
                else if(selectedPiece.posY == 'H')
                {
                    availablePositionsAttack[0] = selectedPiece.posX + 1;
                    availablePositionsAttack[1] = selectedPiece.posY - 1;
                    availablePositionsAttack[2] = selectedPiece.posX + 1;
                    availablePositionsAttack[3] = selectedPiece.posY - 1;
                }
            }
            
            //printf("-> %d %c\n",availablePositions[0],availablePositions[1]);
            if(whiteTurn == true)
            {
                bool found1,found2;//found eatable pieces;
                bool found3 = false;//found forward enemy or ally piece 

                for(int i = 0; i< sizeof pieces2/sizeof pieces2[0];i++)
                {

                    if((pieces2[i].posX == availablePositions[0] && pieces2[i].posY == availablePositions[1]) || (pieces1[i].posX == availablePositions[0] && pieces1[i].posY == availablePositions[1]))
                    {
                        found3 = true;
                        availablePositions[0] = 0;
                        availablePositions[1] = 0;
                    }

                    if(pieces2[i].posX == availablePositionsAttack[0] && pieces2[i].posY == availablePositionsAttack[1])
                    {
                        printf("-> %d %c\n",availablePositionsAttack[0],availablePositionsAttack[1]);
                        enemyIndex1 = i;
                        found1 = true;
                    }

                    if(pieces2[i].posX == availablePositionsAttack[2] && pieces2[i].posY == availablePositionsAttack[3])
                    {
                        printf("-> %d %c\n",availablePositionsAttack[2],availablePositionsAttack[3]);
                        enemyIndex2 = i;
                        found2 = true;
                    }
                }

                if(found1 == false)
                {
                    availablePositionsAttack[0] = 0;
                    availablePositionsAttack[1] = 0;
                }
                if(found2 == false)
                {
                    availablePositionsAttack[2] = 0;
                    availablePositionsAttack[3] = 0;
                }
                if(found3 == false)
                {
                    printf("-> %d %c\n",availablePositions[0],availablePositions[1]);
                }

            }
            else if(whiteTurn ==false)
            {
                bool found1,found2;//found eatable enemy piece
                bool found3 = false;//found forward enemy or ally piece
                for(int i = 0; i< sizeof pieces1/sizeof pieces1[0];i++)
                {      
                    if((pieces1[i].posX == availablePositions[0] && pieces1[i].posY == availablePositions[1]) || (pieces2[i].posX == availablePositions[0] && pieces2[i].posY == availablePositions[1]))
                    {
                        found3 = true;
                        availablePositions[0] = 0;
                        availablePositions[1] = 0;
                    }

                    if(pieces1[i].posX == availablePositionsAttack[0] && pieces1[i].posY == availablePositionsAttack[1])
                    {
                        printf("-> %d %c\n",availablePositionsAttack[0],availablePositionsAttack[1]);
                        enemyIndex1 = i;
                        found1 = true;
                    }

                    if(pieces1[i].posX == availablePositionsAttack[2] && pieces1[i].posY == availablePositionsAttack[3])
                    {
                        printf("-> %d %c\n",availablePositionsAttack[2],availablePositionsAttack[3]);
                        enemyIndex2 = i;
                        found2 = true;
                    }                    
                }
                if(found1 == false)
                {
                    availablePositionsAttack[0] = 0;
                    availablePositionsAttack[1] = 0;
                }
                if(found2 == false)
                {
                    availablePositionsAttack[2] = 0;
                    availablePositionsAttack[3] = 0;
                } 
                if(found3 == false)
                {
                    printf("-> %d %c\n",availablePositions[0],availablePositions[1]);
                }
            }
            

            //get position inputed by player
            if(!(availablePositions[0] == 0 && availablePositions[1] == 0) || !(availablePositionsAttack[0] == 0 && availablePositionsAttack[1] == 0) || !(availablePositionsAttack[2] == 0 && availablePositionsAttack[3] == 0))
            {
                do
                {
                    printf("Select Line:");
                    scanf("%d",&posX);
                    for (int i = 1; i < sizeof availablePositions /sizeof availablePositions[0]; i+=2)
                    {
                        if(posX == availablePositions[i])
                        {
                            break;
                        }                    
                    }     

                    for (int i = 1; i < sizeof availablePositionsAttack /sizeof availablePositionsAttack[0]; i+=2)
                    {
                        if(posX == availablePositionsAttack[i])
                        {
                            break;
                        }                    
                    }

                    if(posX <= 0 || posX > 8)//if the choice is outside of the table, teel the player that he is out of bounds
                    {
                        printf("Not available line for movement!\n");
                    }
                }while(posX <= 0 || posX > 8);

                do
                {
                    printf("Select column:");
                    scanf(" %c",&posY);
                    posY = toupper(posY);
                    for (int i = 0; i < sizeof availablePositions /sizeof availablePositions[0]; i+=2)
                    {
                        if(posY == availablePositions[i])
                        {
                            break;
                        }                    
                    } 
                    if(posY < 'A' || posY > 'H')//if the choice is outside of the table, teel the player that he is out of bounds
                    {
                        printf("Not available column for movement!\n");
                    }
                }while(posY < 'A' || posY > 'H');

                if(whiteTurn == true)
                {
                    if((posX == pieces2[enemyIndex1].posX && posY == pieces2[enemyIndex1].posY))
                    {
                        pieces2[enemyIndex1].posX = 0;
                        pieces2[enemyIndex1].posY = 0;
                    }

                    if((posX == pieces2[enemyIndex2].posX && posY == pieces2[enemyIndex2].posY))
                    {
                        pieces2[enemyIndex2].posX = 0;
                        pieces2[enemyIndex2].posY = 0;
                    }

                    pieces1[index].posX = posX;
                    pieces1[index].posY = posY;
                }else
                {
                    if((posX == pieces1[enemyIndex1].posX && posY == pieces1[enemyIndex1].posY))
                    {
                        pieces1[enemyIndex1].posX = 0;
                        pieces1[enemyIndex1].posY = 0;
                    }

                    if((posX == pieces1[enemyIndex2].posX && posY == pieces1[enemyIndex2].posY))
                    {
                        pieces1[enemyIndex2].posX = 0;
                        pieces1[enemyIndex2].posY = 0;
                    }

                    pieces2[index].posX = posX;
                    pieces2[index].posY = posY;
                }
                reCreateTable();
            }
            else
            {
                reCreateTable();
            }
            
            
            
        }
        else if(selectedPiece.costume == 'r' || selectedPiece.costume == 'R')
        {
            int diferenceTop = selectedPiece.posX - 1;
            int diferenceRight = 'H' - selectedPiece.posY;
            int diferenceBottom = 8 - selectedPiece.posX;
            int diferenceLeft = selectedPiece.posY - 'A';
            int availablePositions[14][2] = {0};
            int index = 0;
            bool foundPiece = false;

            for(int i = 0; i<diferenceTop;i++)//positions on top of tower
            {
                for(int p = 0;p < 16;p++)
                {
                    if(whiteTurn == true)
                    {
                        if(pieces1[p].posX == selectedPiece.posX-(i+1) && pieces1[p].posY == selectedPiece.posY)
                        {
                            foundPiece = true;
                            availablePositions[i][0] = 0;
                            availablePositions[i][1] = 0;
                            printf("Found a piece 1 top\n\n");
                            index++;
                        }
                        else if(foundPiece == false)
                        {
                            availablePositions[i][0] = selectedPiece.posX-(i+1);
                            availablePositions[i][1] = selectedPiece.posY;
                            printf("cant come up here 1\n\n");
                            index++;
                        }
                    }else if(whiteTurn == false)
                    {
                        if(pieces2[p].posX == selectedPiece.posX-(i+1) && pieces2[p].posY == selectedPiece.posY)
                        {
                            foundPiece = true;
                            availablePositions[i][0] = 0;
                            availablePositions[i][1] = 0;
                            printf("Found a piece 2 top\n\n");
                            index++;
                        }
                        else if(foundPiece == false)
                        {
                            availablePositions[i][0] = selectedPiece.posX-(i+1);
                            availablePositions[i][1] = selectedPiece.posY;
                            printf("cant come up here 2\n\n");
                            index++;
                        }
                    }                    
                }
            }
            printf("%d\n\n",index);
            for(int i = index; i<diferenceBottom+index;i++)//positions on bottom of tower
            {
                for(int p = 0;p < 16;p++)
                {
                    if(whiteTurn == true)
                    {
                        if(pieces1[p].posX == selectedPiece.posX+(i+1) && pieces1[p].posY == selectedPiece.posY)
                        {
                            foundPiece = true;
                            availablePositions[i][0] = 0;
                            availablePositions[i][1] = 0;
                            printf("Found a piece 1 bottom\n\n");
                            index++;
                        }
                        else if(foundPiece == false)
                        {
                            availablePositions[i][0] = selectedPiece.posX+(i+1);
                            availablePositions[i][1] = selectedPiece.posY;
                            printf("cant come down here 1\n\n");
                            index++;
                        }
                    }else if(whiteTurn == false)
                    {
                        if(pieces2[p].posX == selectedPiece.posX+(i+1) && pieces2[p].posY == selectedPiece.posY)
                        {
                            foundPiece = true;
                            availablePositions[i][0] = 0;
                            availablePositions[i][1] = 0;
                            printf("Found a piece 2 bottom\n\n");
                            index++;
                        }
                        else if(foundPiece == false)
                        {
                            availablePositions[i][0] = selectedPiece.posX+(i+1);
                            availablePositions[i][1] = selectedPiece.posY;
                            printf("cant come down here 2\n\n");
                            index++;
                        }
                    }        
                }
            }
            
            for(int i = index; i<diferenceRight+index;i++)//positions on bottom of tower
            {
                for(int p = 0;p < 16;p++)
                {
                    if(whiteTurn == true)
                    {
                        if(pieces1[p].posX == selectedPiece.posX && pieces1[p].posY == selectedPiece.posY+(i+1))
                        {
                            foundPiece = true;
                            availablePositions[i][0] = 0;
                            availablePositions[i][1] = 0;
                            printf("Found a piece 1 bottom\n\n");
                            index++;
                        }
                        else if(foundPiece == false)
                        {
                            availablePositions[i][0] = selectedPiece.posX+(i+1);
                            availablePositions[i][1] = selectedPiece.posY;
                            printf("cant come down here 1\n\n");
                            index++;
                        }
                    }else if(whiteTurn == false)
                    {
                        if(pieces2[p].posX == selectedPiece.posX+(i+1) && pieces2[p].posY == selectedPiece.posY)
                        {
                            foundPiece = true;
                            availablePositions[i][0] = 0;
                            availablePositions[i][1] = 0;
                            printf("Found a piece 2 bottom\n\n");
                            index++;
                        }
                        else if(foundPiece == false)
                        {
                            availablePositions[i][0] = selectedPiece.posX+(i+1);
                            availablePositions[i][1] = selectedPiece.posY;
                            printf("cant come down here 2\n\n");
                            index++;
                        }
                    }        
                }
            }
            for(int i = 0;i<14;i++)
            {
                printf("%d %c\n",availablePositions[i][0],availablePositions[i][1]);
            }



            //-> move forward or sideways as much as needed
            // int availableLines[14] = {0};//vertical
            // int availableColums[14] = {0};//herizontal
            // if(selectedPiece.posX == 1)
            // {
            //     for (int i = 0; i < 7; i++)
            //     {
            //         availableLines[i] = i+2;
            //     }     
            //     for (int i = 7; i < sizeof availableLines/sizeof availableLines[0]; i++)
            //     {                
            //         availableLines[i] = selectedPiece.posX;
            //     }           
            // }
            // else if(selectedPiece.posX == 8)
            // {
            //     for (int i = 6; i >= 0; i--)
            //     {
            //         availableLines[i] = i+1;
            //     }
            //     for (int i = 7; i < sizeof availableLines/sizeof availableLines[0]; i++)
            //     {                
            //         availableLines[i] = selectedPiece.posX;
            //     }
            // }
            // else if(selectedPiece.posX > 1 && selectedPiece.posX < 8)
            // {
            //     int down = selectedPiece.posX - 1;
            //     //int up = 8 - selectedPiece.posX;
            //     int p = 0;
            //     for (int i = down; i > 0; i--,p++)
            //     {
            //         availableLines[p] = i;
            //     }
            //     for (int i = selectedPiece.posX+1; i <= 8; i++,p++)
            //     {
            //         availableLines[p] = i;
            //     }
            //     for (int i = 7; i < sizeof availableLines/sizeof availableLines[0]; i++)
            //     {                
            //         availableLines[i] = selectedPiece.posX;
            //     }
            // }            
            
            // if(selectedPiece.posY == 'A')
            // {
            //     for (int i = 0; i < 7; i++)
            //     {
            //         availableColums[i] = selectedPiece.posY;
            //     }
            //     for (int i = 7; i < sizeof availableColums/sizeof availableColums[0]; i++)
            //     {
            //         availableColums[i] = selectedPiece.posY+(i-6);
            //     }
                
            // }
            // else if(selectedPiece.posY == 'H')
            // {
            //     for (int i = 0; i < 7; i++)
            //     {
            //         availableColums[i] = selectedPiece.posY;
            //     }
            //     for (int i = 7; i < sizeof availableColums/sizeof availableColums[0]; i++)
            //     {
            //         availableColums[i] = selectedPiece.posY-(i-6);
            //     }
                
            // }
            // else if(selectedPiece.posY > 'A' && selectedPiece.posY < 'H')
            // {
            //     int down = selectedPiece.posY - 'A';
            //     int p = 0;
            //     for (int i = down; i >= 0; i--,p++)
            //     {
            //         availableColums[p] = i;
            //     }
            //     for (int i = selectedPiece.posY+1; i <= 'H'; i++,p++)
            //     {
            //         availableColums[p] = i;
            //     }
            //     for (int i = 7; i < sizeof availableColums/sizeof availableColums[0]; i++)
            //     {
            //         availableColums[i] = selectedPiece.posY+(i-6);
            //     }                
            // }
            
            // int posVL[7] = {0};
            // int posVC[7] = {0};
            // int posHL[7]= {0};
            // int posHC[7]= {0};

            // if(selectedPiece.costume == 'R')
            // {
            //     //verificar coluna da torre pos 0 -> 6
            //     //verificar linha da torre  pos 7 -> 13
               
            //     // int diferenceDown = 8 - selectedPiece.posX;
            //     // int diferenceUp = selectedPiece.posX-1;
            //     // int counterDown = 0;
            //     // for (int i = 0; i < diferenceDown; i++)
            //     // {
            //     //     for (int p = 0; p < sizeof pieces1/sizeof pieces1[0]; p++)
            //     //     {
            //     //         if(pieces1[p].posX == selectedPiece.posX+(p+1))
            //     //         {
            //     //             posVL[counterDown] = pieces1[p].posX;
            //     //             posVC[counterDown] = pieces1[p].posY;
            //     //             counterDown++;
            //     //         }
            //     //     }                    
            //     // }
            //     // for (int i = 0; i < diferenceUp; i++)
            //     // {
            //     //     for (int p = 0; p < sizeof pieces1/sizeof pieces1[0]; p++)
            //     //     {
            //     //         if(pieces1[p].posX == selectedPiece.posX-(p+1))
            //     //         {
            //     //             posVL[counterDown] = pieces1[p].posX;
            //     //             posVC[counterDown] = pieces1[p].posY;
            //     //             counterDown++;
            //     //         }
            //     //     }
            //     // }
                
                
            //     bool foundPiece = false;
                
            //     for (int i = 0; i < (sizeof availableColums/sizeof availableColums[0])/2; i++)//verificar a coluna da torre
            //     {
            //         for (int p = 0; p < sizeof pieces1/sizeof pieces1[0]; p++)
            //         {
            //             if(foundPiece == true)
            //             {
            //                 availableLines[i] = 0;
            //                 availableColums[i] = 0;
            //             }
            //             else if(pieces1[p].posX == availableLines[i] && pieces1[p].posY == availableColums[i] && foundPiece == false)
            //             {
            //                 availableLines[i] = 0;
            //                 availableColums[i] = 0;
            //                 foundPiece = true;
            //                 break;
            //             }
                        
            //         }
            //     }
            //     foundPiece = false;
            //     for (int i = 7; i < sizeof availableColums/sizeof availableColums[0]; i++)//verificar linha da torre
            //     {
            //         for (int p = 0; p < sizeof pieces1/sizeof pieces1[0]; p++)
            //         {
            //             if(pieces1[p].posX == availableLines[i] && pieces1[p].posY == availableColums[i] && foundPiece == false)
            //             {
            //                 availableLines[i] = 0;
            //                 availableColums[i] = 0;
            //                 foundPiece = true;
            //                 break;
            //             }else if(foundPiece == true)
            //             {
            //                 availableLines[i] = 0;
            //                 availableColums[i] = 0;
            //             }
                        
            //         }
            //     }                

            // }
            // else if(selectedPiece.costume == 'r')
            // {
            //     bool foundPiece = false;
                
            //     for (int i = 0; i < (sizeof availableColums/sizeof availableColums[0])/2; i++)//verificar a coluna da torre
            //     {
            //         for (int p = 0; p < sizeof pieces2/sizeof pieces2[0]; p++)
            //         {
            //             if(pieces2[p].posX == availableLines[i] && pieces2[p].posY == availableColums[i] && foundPiece == false)
            //             {
            //                 availableLines[i] = 0;
            //                 availableColums[i] = 0;
            //                 foundPiece = true;
            //                 break;
            //             }else if(foundPiece == true)
            //             {
            //                 availableLines[i] = 0;
            //                 availableColums[i] = 0;
            //             }
                        
            //         }
            //     }
            //     foundPiece = false;
            //     for (int i = 7; i < sizeof availableColums/sizeof availableColums[0]; i++)//verificar linha da torre
            //     {
            //         for (int p = 0; p < sizeof pieces2/sizeof pieces2[0]; p++)
            //         {
            //             if(pieces2[p].posX == availableLines[i] && pieces2[p].posY == availableColums[i] && foundPiece == false)
            //             {
            //                 availableLines[i] = 0;
            //                 availableColums[i] = 0;
            //                 foundPiece = true;
            //                 break;
            //             }else if(foundPiece == true)
            //             {
            //                 availableLines[i] = 0;
            //                 availableColums[i] = 0;
            //             }
                        
            //         }
            //     } 
            // }
            

            // printf("Available spaces for movement:\n");
            // for (int l = 0,c = 0; l < sizeof availableLines/sizeof availableLines[0]; l++,c++)
            // {
            //     if(availableLines[l] != 0 && availableColums[l] != 0) 
            //     {
            //         printf("-> %d %c\n",availableLines[l],availableColums[c]);
            //     }
            // }
            // //input player movement
            // do
            // {
            //     printf("Select Line:");
            //     scanf("%d",&posX);
            //     for (int i = 0; i < sizeof availableLines /sizeof availableLines[0]; i++)
            //     {
            //         if(posX == availableLines[i])
            //         {
            //             break;
            //         }                    
            //     }                
            //     if(posX <= 0 || posX > 8)//if the choice is outside of the table, teel the player that he is out of bounds
            //     {
            //         printf("Not available line for movement!\n");
            //     }
            // }while(posX <= 0 || posX > 8);

            // do
            // {
            //     printf("Select column:");
            //     scanf(" %c",&posY);
            //     posY = toupper(posY);
            //     for (int i = 0; i < sizeof availableLines /sizeof availableLines[0]; i+=2)
            //     {
            //         if(posY == availableColums[i])
            //         {
            //             break;
            //         }                    
            //     } 
            //     if(posY < 'A' || posY > 'H')//if the choice is outside of the table, teel the player that he is out of bounds
            //     {
            //         printf("Not available column for movement!\n");
            //     }
            // }while(posY < 'A' || posY > 'H');
            // if(whiteTurn == true)
            // {
            //     pieces1[index].posX = posX;
            //     pieces1[index].posY = posY;
            // }else
            // {
            //     pieces2[index].posX = posX;
            //     pieces2[index].posY = posY;
            // }
            // printf("Selected Piece index %d new pos =>%d %c\n",index,selectedPiece.posX,selectedPiece.posY);

            // reCreateTable();
        }
        else if(selectedPiece.costume == 'n' || selectedPiece.costume == 'N')
        {
            //-> move in L chape   
        }
        else if(selectedPiece.costume == 'b' || selectedPiece.costume == 'B')
        {
            //-> moves diagonaly
        }
        else if(selectedPiece.costume == 'q' || selectedPiece.costume == 'Q')
        {
            //-> moves at any direction as many spaces as needed
        }
        else if(selectedPiece.costume == 'k' || selectedPiece.costume == 'K')
        {
            //-> moves at any direction only once
        }
    
}    


    
