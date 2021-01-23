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
bool whiteTurn = true;

int random;
void writeRandom()
{
    printf("%d",random);
}

void writeCoordinatesOfPieces(FILE *savedData)//writes the coordinates of pieces in game in a txt file
{
    for (int i = 0; i < 16; i++)
    {
        fprintf(&*savedData,"%c %d %c\n",pieces1[i].costume,pieces1[i].posX,pieces1[i].posY);
    }
    fprintf(&*savedData,"\n");
    for (int i = 0; i < 16; i++)
    {
        fprintf(&*savedData,"%c %d %c\n",pieces2[i].costume,pieces2[i].posX,pieces2[i].posY);
    }
    fprintf(&*savedData,"\n");
}

void writePlayerTurn(FILE *savedData)//writes the game turn in game file
{
    fprintf(&*savedData,"%d",whiteTurn);
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
void checkGame()//check if game is over by checking if the king still exists in game
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
            break;
        }
    }
    
    if(foundKingW && !foundKingB)
    {
        printf("%s won the match\nCongratulations!",players[0].nickname);
        exit(1);
    }
    else if(!foundKingW && foundKingB)
    {
        printf("%s won the match\nCongratulations!",players[1].nickname);
        exit(1);
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

void createTable()//creates a new game table with new pieces and positions
{
    srand(time(0));
    random = rand()%2;    
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

void loadTable(piece _pieces1[], piece _pieces2[] )
{
    for(int i = 0; i < 16; i++){


        pieces1[i].costume = _pieces1[i].costume;
        pieces1[i].posX = _pieces1[i].posX;
        pieces1[i].posY = _pieces1[i].posY;

        pieces2[i].costume = _pieces2[i].costume;
        pieces2[i].posX = _pieces2[i].posX;
        pieces2[i].posY = _pieces2[i].posY;



        printf("%c %d",pieces1[i].costume,i);
        printf("%d ",pieces1[i].posX);
        printf("%c\n",pieces1[i].posY); 
        printf("\n");
    }

    printf("Peças pretas DIVISÃO");

    for (int i = 0; i < 16 ; i++)
    {
        printf("%c %d",pieces2[i].costume,i);
        printf("%d ",pieces2[i].posX);
        printf("%c\n",pieces2[i].posY); 
        printf("\n");
    }

    reCreateTable();
}

void reCreateTable()//recreates the table given the positions of the pieces in the table if the match 
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

void movePiece()
{
    int index = 0;//index of selected piece
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
                break;
            }else if(pieces2[i].posX == posX && pieces2[i].posY == posY)
            {
                selectedPieceCostume = pieces2[i].costume;
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
                break;
            }
        }else if(whiteTurn == false)
        {
            if(selectedPiece.costume == pieces2[i].costume && selectedPiece.posX == pieces2[i].posX && selectedPiece.posY == pieces2[i].posY)
            {
                index = i;    
                break;
            }
        }                
    }

    posX = 0;//select new line to move
    posY = 0;//select new column to move
    
        if(selectedPiece.costume == 'p' || selectedPiece.costume == 'P')//movement of pawn
        {
            //-> move forawrd only once
            movePawn(selectedPiece,index,posX,posY);            
        }
        else if(selectedPiece.costume == 'r' || selectedPiece.costume == 'R')//movement rook
        {
            moveRook(selectedPiece,index,posX,posY);          
        }
        else if(selectedPiece.costume == 'n' || selectedPiece.costume == 'N')//movement of knight
        {
            //-> move in L chape 
            moveKnight(selectedPiece,index,posX,posY);         
        }
        else if(selectedPiece.costume == 'b' || selectedPiece.costume == 'B')//movement of bishop
        {
            //-> moves diagonaly
            moveBishop(selectedPiece,index,posX,posY);
        }
        else if(selectedPiece.costume == 'q' || selectedPiece.costume == 'Q')//movement of Queen
        {
            //-> moves at any direction as many spaces as needed
            moveQueen(selectedPiece,index,posX,posY);
        }
        else if(selectedPiece.costume == 'k' || selectedPiece.costume == 'K')//movement of King
        {
            //-> moves at any direction only once
            moveKing(selectedPiece,index,posX,posY);
        }
        
        reCreateTable();
        whiteTurn = !whiteTurn;    
}

void movePawn(piece selectedPiece,int index,int posX,char posY)//done
{
    int availablePositionsAttack[4] ={0};
            int availablePositions[2] = {0};
            int enemyIndex1 = 0,enemyIndex2 = 0;
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

                for(int i = 0; i < sizeof pieces2/sizeof pieces2[0];i++)
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
                bool checkPosX= false;
                bool checkPosY= false;
                do
                {
                    printf("Select line:");
                    scanf("%d",&posX);
                    for (int i = 0; i < sizeof availablePositions /sizeof availablePositions[0]; i+=2)
                    {
                        if(posX == availablePositions[i])
                        {
                            checkPosX = true;
                            break;
                        }                    
                    }     

                    for (int i = 0; i < sizeof availablePositionsAttack /sizeof availablePositionsAttack[0]; i+=2)
                    {
                        if(posX == availablePositionsAttack[i])
                        {
                            checkPosX = true;
                            break;
                        }                    
                    }

                    if(checkPosX == false)//if the choice is outside of the table, teel the player that he is out of bounds
                    {
                        printf("Not available line for movement!\n");
                    }
                }while(checkPosX == false);

                do
                {
                    printf("Select column:");
                    scanf(" %c",&posY);
                    posY = toupper(posY);
                    
                    for (int i = 1; i < sizeof availablePositions /sizeof availablePositions[0]; i+=2)
                    {
                        if(posY == availablePositions[i])
                        {
                            checkPosY = true;
                            break;
                        }                    
                    }

                    for (int i = 1; i < sizeof availablePositionsAttack /sizeof availablePositionsAttack[0]; i+=2)
                    {
                        if(posY == availablePositionsAttack[i])
                        {
                            checkPosY = true;
                            break;
                        }                    
                    } 
                    if(checkPosY == false)//if the choice is outside of the table, teel the player that he is out of bounds
                    {
                        printf("Not available column for movement!\n");
                    }
                }while(checkPosY == false);

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
                }
                else
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
            }
}

void moveRook(piece selectedPiece,int index,int posX,char posY)//done
{
    int positionsTop[7][2] = {0};
    int positionsBottom[7][2] = {0};
    int positionsLeft[7][2] = {0};
    int positionsRight[7][2] = {0};
    bool foundPiece = false;
    bool existsPositions = false;

    for (int i = 0; i < 7; i++)//top positions
    {
        if(selectedPiece.posX-(i+1) >= 1)
        {
            for (int p = 0; p < 16; p++)
            {
                if(whiteTurn == true)
                {
                    if(pieces1[p].posX == selectedPiece.posX-(i+1) && pieces1[p].posY == selectedPiece.posY && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        foundPiece = true;
                    }
                    else if(pieces2[p].posX == selectedPiece.posX-(i+1) && pieces2[p].posY == selectedPiece.posY && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        positionsTop[i][0] = selectedPiece.posX-(i+1);
                        positionsTop[i][1] = selectedPiece.posY;
                        foundPiece = true;
                    }         
                }
                else
                {
                    if(pieces2[p].posX == selectedPiece.posX-(i+1) && pieces2[p].posY == selectedPiece.posY && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        foundPiece = true;
                    }
                    else if(pieces1[p].posX == selectedPiece.posX-(i+1) && pieces1[p].posY == selectedPiece.posY && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        positionsTop[i][0] = selectedPiece.posX-(i+1);
                        positionsTop[i][1] = selectedPiece.posY;
                        foundPiece = true;
                    }
                }                
            }
            if(foundPiece == false)
            {
                // printf("%d %c\n",selectedPiece.posX-(i+1),selectedPiece.posY);
                positionsTop[i][0] = selectedPiece.posX-(i+1);
                positionsTop[i][1] = selectedPiece.posY;
            }
            
        }
    }
    foundPiece = false;
    for (int i = 0; i < 7; i++)//bottom positions
    {
        if(selectedPiece.posX+(i+1) <= 8)
        {
            for (int p = 0; p < 16; p++)
            {
                if(whiteTurn == true)
                {
                    if(pieces1[p].posX == selectedPiece.posX+(i+1) && pieces1[p].posY == selectedPiece.posY && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        foundPiece = true;
                    }
                    else if(pieces2[p].posX == selectedPiece.posX+(i+1) && pieces2[p].posY == selectedPiece.posY && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        positionsBottom[i][0] = selectedPiece.posX+(i+1);
                        positionsBottom[i][1] = selectedPiece.posY;
                        foundPiece = true;
                    }           
                }
                else
                {
                    if(pieces2[p].posX == selectedPiece.posX+(i+1) && pieces2[p].posY == selectedPiece.posY && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        foundPiece = true;
                    } 
                    else if(pieces1[p].posX == selectedPiece.posX+(i+1) && pieces1[p].posY == selectedPiece.posY && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        positionsBottom[i][0] = selectedPiece.posX+(i+1);
                        positionsBottom[i][1] = selectedPiece.posY;
                        foundPiece = true;
                    }
                }                
            }
            if(foundPiece == false)
            {
                // printf("%d %c\n",selectedPiece.posX+(i+1),selectedPiece.posY);
                positionsBottom[i][0] = selectedPiece.posX+(i+1);
                positionsBottom[i][1] = selectedPiece.posY;
            }
            
        }
    }
    foundPiece = false;
    for (int i = 0; i < 7; i++)//Right positions
    {
        if(selectedPiece.posY+(i+1) <= 'H')
        {
            for (int p = 0; p < 16; p++)
            {
                if(whiteTurn == true)
                {
                    if(pieces1[p].posX == selectedPiece.posX && pieces1[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        foundPiece = true;
                    }else if(pieces2[p].posX == selectedPiece.posX && pieces2[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        positionsRight[i][0] = selectedPiece.posX;
                        positionsRight[i][1] = selectedPiece.posY+(i+1);
                        foundPiece = true;
                    }           
                }
                else
                {
                    if(pieces2[p].posX == selectedPiece.posX && pieces2[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        foundPiece = true;
                    }else if(pieces1[p].posX == selectedPiece.posX && pieces1[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        positionsRight[i][0] = selectedPiece.posX;
                        positionsRight[i][1] = selectedPiece.posY+(i+1);
                        foundPiece = true;
                    } 
                }                
            }
            if(foundPiece == false)
            {
                // printf("%d %c\n",selectedPiece.posX,selectedPiece.posY+(i+1));
                positionsRight[i][0] = selectedPiece.posX;
                positionsRight[i][1] = selectedPiece.posY+(i+1);
            }
            
        }
    }
    foundPiece = false;
    for (int i = 0; i < 7; i++)//Left positions
    {
        if(selectedPiece.posY-(i+1) >= 'A')
        {
            for (int p = 0; p < 16; p++)
            {
                if(whiteTurn == true)
                {
                    if(pieces1[p].posX == selectedPiece.posX && pieces1[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        foundPiece = true;
                    }else if(pieces2[p].posX == selectedPiece.posX && pieces2[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        positionsLeft[i][0] = selectedPiece.posX;
                        positionsLeft[i][1] = selectedPiece.posY-(i+1);
                        foundPiece = true;
                    }           
                }
                else
                {
                    if(pieces2[p].posX == selectedPiece.posX && pieces2[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        foundPiece = true;
                    }else if(pieces1[p].posX == selectedPiece.posX && pieces1[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        positionsLeft[i][0] = selectedPiece.posX;
                        positionsLeft[i][1] = selectedPiece.posY-(i+1);
                        foundPiece = true;
                    }
                }                
            }
            if(foundPiece == false)
            {
                // printf("%d %c\n",selectedPiece.posX,selectedPiece.posY-(i+1));
                positionsLeft[i][0] = selectedPiece.posX;
                positionsLeft[i][1] = selectedPiece.posY-(i+1);
            }
            
        }
    }

    for (int i = 0; i < 7; i++)
    {        
        if(positionsTop[i][0] != 0 && positionsTop[i][1] != 0)
        {
            printf("-> %d %c\n",positionsTop[i][0],positionsTop[i][1]);
            existsPositions = true;
        }
    }
    for (int i = 0; i < 7; i++)
    {        
        if(positionsBottom[i][0] != 0 && positionsBottom[i][1] != 0)
        {
            printf("-> %d %c\n",positionsBottom[i][0],positionsBottom[i][1]);
            existsPositions = true;
        }
    }
    for (int i = 0; i < 7; i++)
    {        
        if(positionsRight[i][0] != 0 && positionsRight[i][1] != 0)
        {
            printf("-> %d %c\n",positionsRight[i][0],positionsRight[i][1]);
            existsPositions = true;
        }
    }
    for (int i = 0; i < 7; i++)
    {        
        if(positionsLeft[i][0] != 0 && positionsLeft[i][1] != 0)
        {
            printf("-> %d %c\n",positionsLeft[i][0],positionsLeft[i][1]);
            existsPositions = true;
        }
    }
    
    if(existsPositions == true)
    {
        bool checkPosX = false;
        bool checkPosY = false;
        do
        {
            printf("Select line: ");
            scanf("%d",&posX);
            for (int i = 0; i < 7; i++)
            {
                if((positionsTop[i][0] == posX || positionsRight[i][0] == posX || positionsBottom[i][0] == posX || positionsLeft[i][0] == posX) && posX != 0)
                {
                    checkPosX = true;
                }
            }
            
        } while (checkPosX == false);

        do
        {
            printf("Select Column: ");
            scanf(" %c",&posY);
            posY = toupper(posY);
            for (int i = 0; i < 7; i++)
            {
                if((positionsTop[i][1] == posY || positionsRight[i][1] == posY || positionsBottom[i][1] == posY || positionsLeft[i][1] == posY) && posY != 0)
                {
                    checkPosY = true;
                }
            }
        } while (checkPosY == false);

        if(whiteTurn == true)
        {
            for (int i = 0; i < 16; i++)
            {
                if(pieces2[i].posX == posX && pieces2[i].posY == posY)
                {
                    pieces2[i].posX = 0;
                    pieces2[i].posY = 0;
                }
            }

            pieces1[index].posX = posX;
            pieces1[index].posY = posY;
        }
        else if(whiteTurn == false)
        {
            for (int i = 0; i < 16; i++)
            {
                if(pieces1[i].posX == posX && pieces1[i].posY == posY)
                {
                    pieces1[i].posX = 0;
                    pieces1[i].posY = 0;
                }
            }

            pieces2[index].posX = posX;
            pieces2[index].posY = posY;
        }        
    }    
}

void moveKnight(piece selectedPiece,int index,int posX,char posY)//done
{
    int availablePositions[8][2] = {0};
            bool checkPosX = false;
            bool checkPosY = false;
            availablePositions[0][0] = selectedPiece.posX+2;
            availablePositions[1][0] = selectedPiece.posX+2;
            availablePositions[0][1] = selectedPiece.posY-1;
            availablePositions[1][1] = selectedPiece.posY+1;

            availablePositions[2][0] = selectedPiece.posX+1;
            availablePositions[3][0] = selectedPiece.posX-1;
            availablePositions[2][1] = selectedPiece.posY+2;
            availablePositions[3][1] = selectedPiece.posY+2;

            availablePositions[4][0] = selectedPiece.posX-2;
            availablePositions[5][0] = selectedPiece.posX-2;
            availablePositions[4][1] = selectedPiece.posY-1;
            availablePositions[5][1] = selectedPiece.posY+1;

            availablePositions[6][0] = selectedPiece.posX-1;
            availablePositions[7][0] = selectedPiece.posX+1;
            availablePositions[6][1] = selectedPiece.posY-2;
            availablePositions[7][1] = selectedPiece.posY-2;
          


            for(int i = 0; i < 8 ; i++)
            {
                if(availablePositions[i][0] < 1 || availablePositions[i][0] > 8)
                {
                    availablePositions[i][0] = 0;
                    availablePositions[i][1] = 0;
                }

                if(availablePositions[i][1] < 'A' || availablePositions[i][1] > 'H')
                {
                    availablePositions[i][0] = 0;
                    availablePositions[i][1] = 0;
                }
            }

            if(whiteTurn == true)
            {
                for(int p = 0; p < 16 ; p++)
                {
                    for(int pos = 0; pos < 8 ; pos++)
                    {
                        if(pieces1[p].posX == availablePositions[pos][0] && pieces1[p].posY == availablePositions[pos][1])
                        {
                            availablePositions[pos][0] = 0;
                            availablePositions[pos][1] = 0;
                        }
                    }
                }
            }
            else if(whiteTurn == false)
            {
                for(int p = 0; p < 16 ; p++)
                {
                    for(int pos = 0; pos < 8 ; pos++)
                    {
                        if(pieces2[p].posX == availablePositions[pos][0] && pieces2[p].posY == availablePositions[pos][1])
                        {
                            availablePositions[pos][0] = 0;
                            availablePositions[pos][1] = 0;
                        }
                    }
                }
            }

            bool existPositions = false;
            for(int i = 0;i<8;i++)
            {
                if(availablePositions[i][0] != 0 && availablePositions[i][1] != 0)
                {
                    printf("-> %d %c\n",availablePositions[i][0],availablePositions[i][1]);
                    existPositions = true;
                }
            }

            if(existPositions == true)
            {
                do
                {
                    printf("Select line: ");
                    scanf("%d",&posX);
                    for(int pos = 0; pos < 8 ; pos++)
                    {
                        if(availablePositions[pos][0] == posX)
                        {
                            checkPosX = true;
                            break;
                        }else
                        {
                            checkPosX = false;
                        }                    
                    }
                    if(checkPosX == false)
                    {
                        printf("Not available line for movement!\n");
                    }

                } while (checkPosX == false);
                
                do
                {
                    printf("Select column: ");
                    scanf(" %c",&posY);
                    posY = toupper(posY);
                    for(int pos = 0; pos < 8 ; pos++)
                    {
                        if(availablePositions[pos][1] == posY)
                        {
                            checkPosY = true;
                            break;
                        }else
                        {
                            checkPosY = false;
                        }                    
                    }
                    if(checkPosY == false)
                    {
                        printf("Not available column for movement!\n");
                    }
                } while (checkPosY == false);

                if(whiteTurn == true)
                {
                    for(int i = 0; i<16;i++)
                    {
                        if(posX == pieces2[i].posX && posY == pieces2[i].posY)
                        {
                            pieces2[i].posX = 0;
                            pieces2[i].posY = 0;
                            break;
                        }
                    }
                    pieces1[index].posX = posX;
                    pieces1[index].posY = posY;

                }
                else if(whiteTurn == false)
                {
                    for(int i = 0; i<16;i++)
                    {
                        if(posX == pieces1[i].posX && posY == pieces1[i].posY)
                        {
                            pieces1[i].posX = 0;
                            pieces1[i].posY = 0;
                            break;
                        }
                    }
                    pieces2[index].posX = posX;
                    pieces2[index].posY = posY;                
                }
            }                
}

void moveBishop(piece selectedPiece,int index,int posX,char posY)//done
{
    int availablePositionsDiagonal1Up[7][2] = {0};
    int availablePositionsDiagonal1Down[7][2] = {0};
    
    int availablePositionsDiagonal2Up[7][2] = {0};
    int availablePositionsDiagonal2Down[7][2] = {0};
    bool existsPositions = false;
    bool foundPiece = false;

    ////check diagonal 1

    for (int i = 0; i < 7; i++)
    {
        if(selectedPiece.posX+(i+1) <= 8 && selectedPiece.posY-(i+1) >= 'A')
        {
            for (int p = 0; p < 16; p++)
            {
                if(whiteTurn)
                {
                    if(pieces1[p].posX == selectedPiece.posX+(i+1) && pieces1[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Down\n");
                        // printf("%c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        foundPiece = true;
                    }else if(pieces2[p].posX == selectedPiece.posX+(i+1) && pieces2[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Down\n");
                        // printf("%c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        availablePositionsDiagonal1Down[i][0] = selectedPiece.posX+(i+1);
                        availablePositionsDiagonal1Down[i][1] = selectedPiece.posY-(i+1);
                        foundPiece = true;
                    }
                }
                else if(whiteTurn == false)
                {
                    if(pieces2[p].posX == selectedPiece.posX+(i+1) && pieces2[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Down\n");
                        // printf("%c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        foundPiece = true;                        
                    }else if(pieces1[p].posX == selectedPiece.posX+(i+1) && pieces1[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Down\n");
                        // printf("%c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        availablePositionsDiagonal1Down[i][0] = selectedPiece.posX+(i+1);
                        availablePositionsDiagonal1Down[i][1] = selectedPiece.posY-(i+1);
                        foundPiece = true;
                    }
                }
            }
            if(foundPiece == false)
            {
                availablePositionsDiagonal1Down[i][0] = selectedPiece.posX+(i+1);
                availablePositionsDiagonal1Down[i][1] = selectedPiece.posY-(i+1);
                //printf("%d %c\n",selectedPiece.posX+(i+1),selectedPiece.posY-(i+1));
            }
            
        }
    }
    foundPiece = false;
    for (int i = 0; i < 7; i++)
    {
        if(selectedPiece.posX-(i+1) > 0 && selectedPiece.posY+(i+1) <= 'H')
        {
            for (int p = 0; p < 16; p++)
            {
                if(whiteTurn)
                {
                    if(pieces1[p].posX == selectedPiece.posX-(i+1) && pieces1[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Up\n");
                        // printf("%c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        foundPiece = true;
                    }
                    else if(pieces2[p].posX == selectedPiece.posX-(i+1) && pieces2[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Up\n");
                        // printf("%c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        availablePositionsDiagonal1Up[i][0] = selectedPiece.posX-(i+1);
                        availablePositionsDiagonal1Up[i][1] = selectedPiece.posY+(i+1);
                        foundPiece = true;
                    }
                }
                else if(whiteTurn == false)
                {
                    if(pieces2[p].posX == selectedPiece.posX-(i+1) && pieces2[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Up\n");
                        // printf("%c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        foundPiece = true;
                    }else if(pieces1[p].posX == selectedPiece.posX-(i+1) && pieces1[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Up\n");
                        // printf("%c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        availablePositionsDiagonal1Up[i][0] = selectedPiece.posX-(i+1);
                        availablePositionsDiagonal1Up[i][1] = selectedPiece.posY+(i+1);
                        foundPiece = true;
                    }
                }
            }
            if(foundPiece == false)
            {
                availablePositionsDiagonal1Up[i][0] = selectedPiece.posX-(i+1);
                availablePositionsDiagonal1Up[i][1] = selectedPiece.posY+(i+1);
                // printf("%d %c\n",selectedPiece.posX-(i+1),selectedPiece.posY+(i+1));
            }
        }
    }

    //check diagonal 2
    foundPiece = false;
    for (int i = 0; i < 7; i++)
    {
        if(selectedPiece.posX+(i+1) <= 8 && selectedPiece.posY+(i+1) <= 'H')
        {
            for (int p = 0; p < 16; p++)
            {
                if(whiteTurn)
                {
                    if(pieces1[p].posX == selectedPiece.posX+(i+1) && pieces1[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Down\n");
                        // printf("%c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        foundPiece = true;
                    }else if(pieces2[p].posX == selectedPiece.posX+(i+1) && pieces2[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Down\n");
                        // printf("%c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        availablePositionsDiagonal2Down[i][0] = selectedPiece.posX+(i+1);
                        availablePositionsDiagonal2Down[i][1] = selectedPiece.posY+(i+1);
                        foundPiece = true;
                        
                    }
                }
                else if(whiteTurn == false)
                {
                    if(pieces2[p].posX == selectedPiece.posX+(i+1) && pieces2[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Down\n");
                        // printf("%c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        foundPiece = true;                        
                    }else if(pieces1[p].posX == selectedPiece.posX+(i+1) && pieces1[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Down\n");
                        // printf("%c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        availablePositionsDiagonal2Down[i][0] = selectedPiece.posX+(i+1);
                        availablePositionsDiagonal2Down[i][1] = selectedPiece.posY+(i+1);
                        foundPiece = true;
                    }
                }
            }
            if(foundPiece == false)
            {
                availablePositionsDiagonal2Down[i][0] = selectedPiece.posX+(i+1);
                availablePositionsDiagonal2Down[i][1] = selectedPiece.posY+(i+1);
                // printf("%d %c\n",selectedPiece.posX+(i+1),selectedPiece.posY-(i+1));
            }
            
        }
    }
    foundPiece = false;
    for (int i = 0; i < 7; i++)
    {
        if(selectedPiece.posX-(i+1) > 0 && selectedPiece.posY-(i+1) >= 'A')
        {
            for (int p = 0; p < 16; p++)
            {
                if(whiteTurn)
                {
                    if(pieces1[p].posX == selectedPiece.posX-(i+1) && pieces1[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Up\n");
                        // printf("%c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        foundPiece = true;
                    }else if(pieces2[p].posX == selectedPiece.posX-(i+1) && pieces2[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Up\n");
                        // printf("%c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        availablePositionsDiagonal2Up[i][0] = selectedPiece.posX-(i+1);
                        availablePositionsDiagonal2Up[i][1] = selectedPiece.posY-(i+1);
                        foundPiece = true;
                    }
                }
                else if(whiteTurn == false)
                {
                    if(pieces2[p].posX == selectedPiece.posX-(i+1) && pieces2[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Up\n");
                        // printf("%c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        foundPiece = true;
                    }else if(pieces1[p].posX == selectedPiece.posX-(i+1) && pieces1[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Up\n");
                        // printf("%c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        availablePositionsDiagonal2Up[i][0] = selectedPiece.posX-(i+1);
                        availablePositionsDiagonal2Up[i][1] = selectedPiece.posY-(i+1);
                        foundPiece = true;
                    }
                }
            }
            if(foundPiece == false)
            {
                availablePositionsDiagonal2Up[i][0] = selectedPiece.posX-(i+1);
                availablePositionsDiagonal2Up[i][1] = selectedPiece.posY-(i+1);
                // printf("%d %c\n",selectedPiece.posX-(i+1),selectedPiece.posY+(i+1));
            }
        }
    }

    //Show available positions
    for (int i = 0; i < 7; i++)
    {        
        if(availablePositionsDiagonal1Down[i][0] != 0 && availablePositionsDiagonal1Down[i][1] != 0)
        {
            printf("-> %d %c D1D\n",availablePositionsDiagonal1Down[i][0],availablePositionsDiagonal1Down[i][1]);
            existsPositions = true;
        }
    }
    for (int i = 0; i < 7; i++)
    {        
        if(availablePositionsDiagonal1Up[i][0] != 0 && availablePositionsDiagonal1Up[i][1] != 0)
        {
            printf("-> %d %c D1U\n",availablePositionsDiagonal1Up[i][0],availablePositionsDiagonal1Up[i][1]);
            existsPositions = true;
        }
    }
    for (int i = 0; i < 7; i++)
    {        
        if(availablePositionsDiagonal2Down[i][0] != 0 && availablePositionsDiagonal2Down[i][1] != 0)
        {
            printf("-> %d %c D2D\n",availablePositionsDiagonal2Down[i][0],availablePositionsDiagonal2Down[i][1]);
            existsPositions = true;
        }
    }
    for (int i = 0; i < 7; i++)
    {        
        if(availablePositionsDiagonal2Up[i][0] != 0 && availablePositionsDiagonal2Up[i][1] != 0)
        {
            printf("-> %d %c D2U\n",availablePositionsDiagonal2Up[i][0],availablePositionsDiagonal2Up[i][1]);
            existsPositions = true;
        }
    }     

    if(existsPositions)
    {
        bool checkPosX = false;
        bool checkPosY = false;
        do
        {
            printf("Select line: ");
            scanf("%d",&posX);
            for (int i = 0; i < 7; i++)
            {
                if((availablePositionsDiagonal1Down[i][0] == posX || availablePositionsDiagonal1Up[i][0] == posX || availablePositionsDiagonal2Down[i][0] == posX || availablePositionsDiagonal2Up[i][0] == posX) && posX != 0)
                {
                    checkPosX = true;
                }
            }
            
        } while (checkPosX == false);

        do
        {
            printf("Select Column: ");
            scanf(" %c",&posY);
            posY = toupper(posY);
            for (int i = 0; i < 7; i++)
            {
                if((availablePositionsDiagonal1Down[i][1] == posY || availablePositionsDiagonal1Up[i][1] == posY || availablePositionsDiagonal2Down[i][1] == posY || availablePositionsDiagonal2Up[i][1] == posY) && posY != 0)
                {
                    checkPosY = true;
                }
            }
        } while (checkPosY == false);

        if(whiteTurn == true)
        {
            for (int i = 0; i < 16; i++)
            {
                if(pieces2[i].posX == posX && pieces2[i].posY == posY)
                {
                    pieces2[i].posX = 0;
                    pieces2[i].posY = 0;
                }
            }

            pieces1[index].posX = posX;
            pieces1[index].posY = posY;
        }
        else if(whiteTurn == false)
        {
            for (int i = 0; i < 16; i++)
            {
                if(pieces1[i].posX == posX && pieces1[i].posY == posY)
                {
                    pieces1[i].posX = 0;
                    pieces1[i].posY = 0;
                }
            }

            pieces2[index].posX = posX;
            pieces2[index].posY = posY;
        }        
    }        
}

void moveQueen(piece selectedPiece,int index,int posX,char posY)//done
{
    int positionsTop[7][2] = {0};
    int positionsBottom[7][2] = {0};
    int positionsLeft[7][2] = {0};
    int positionsRight[7][2] = {0};

    int availablePositionsDiagonal1Up[7][2] = {0};
    int availablePositionsDiagonal1Down[7][2] = {0};
    
    int availablePositionsDiagonal2Up[7][2] = {0};
    int availablePositionsDiagonal2Down[7][2] = {0};

    bool foundPiece = false;
    bool existsPositions = false;
    
    for (int i = 0; i < 7; i++)//top positions
    {
        if(selectedPiece.posX-(i+1) >= 1)
        {
            for (int p = 0; p < 16; p++)
            {
                if(whiteTurn == true)
                {
                    if(pieces1[p].posX == selectedPiece.posX-(i+1) && pieces1[p].posY == selectedPiece.posY && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        foundPiece = true;
                    }
                    else if(pieces2[p].posX == selectedPiece.posX-(i+1) && pieces2[p].posY == selectedPiece.posY && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        positionsTop[i][0] = selectedPiece.posX-(i+1);
                        positionsTop[i][1] = selectedPiece.posY;
                        foundPiece = true;
                    }         
                }
                else
                {
                    if(pieces2[p].posX == selectedPiece.posX-(i+1) && pieces2[p].posY == selectedPiece.posY && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        foundPiece = true;
                    }
                    else if(pieces1[p].posX == selectedPiece.posX-(i+1) && pieces1[p].posY == selectedPiece.posY && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        positionsTop[i][0] = selectedPiece.posX-(i+1);
                        positionsTop[i][1] = selectedPiece.posY;
                        foundPiece = true;
                    }
                }                
            }
            if(foundPiece == false)
            {
                // printf("%d %c\n",selectedPiece.posX-(i+1),selectedPiece.posY);
                positionsTop[i][0] = selectedPiece.posX-(i+1);
                positionsTop[i][1] = selectedPiece.posY;
            }
            
        }
    }
    foundPiece = false;
    for (int i = 0; i < 7; i++)//bottom positions
    {
        if(selectedPiece.posX+(i+1) <= 8)
        {
            for (int p = 0; p < 16; p++)
            {
                if(whiteTurn == true)
                {
                    if(pieces1[p].posX == selectedPiece.posX+(i+1) && pieces1[p].posY == selectedPiece.posY && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        foundPiece = true;
                    }
                    else if(pieces2[p].posX == selectedPiece.posX+(i+1) && pieces2[p].posY == selectedPiece.posY && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        positionsBottom[i][0] = selectedPiece.posX+(i+1);
                        positionsBottom[i][1] = selectedPiece.posY;
                        foundPiece = true;
                    }           
                }
                else
                {
                    if(pieces2[p].posX == selectedPiece.posX+(i+1) && pieces2[p].posY == selectedPiece.posY && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        foundPiece = true;
                    } 
                    else if(pieces1[p].posX == selectedPiece.posX+(i+1) && pieces1[p].posY == selectedPiece.posY && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        positionsBottom[i][0] = selectedPiece.posX+(i+1);
                        positionsBottom[i][1] = selectedPiece.posY;
                        foundPiece = true;
                    }
                }                
            }
            if(foundPiece == false)
            {
                // printf("%d %c\n",selectedPiece.posX+(i+1),selectedPiece.posY);
                positionsBottom[i][0] = selectedPiece.posX+(i+1);
                positionsBottom[i][1] = selectedPiece.posY;
            }
            
        }
    }
    foundPiece = false;
    for (int i = 0; i < 7; i++)//Right positions
    {
        if(selectedPiece.posY+(i+1) <= 'H')
        {
            for (int p = 0; p < 16; p++)
            {
                if(whiteTurn == true)
                {
                    if(pieces1[p].posX == selectedPiece.posX && pieces1[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        foundPiece = true;
                    }else if(pieces2[p].posX == selectedPiece.posX && pieces2[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        positionsRight[i][0] = selectedPiece.posX;
                        positionsRight[i][1] = selectedPiece.posY+(i+1);
                        foundPiece = true;
                    }           
                }
                else
                {
                    if(pieces2[p].posX == selectedPiece.posX && pieces2[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        foundPiece = true;
                    }else if(pieces1[p].posX == selectedPiece.posX && pieces1[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        positionsRight[i][0] = selectedPiece.posX;
                        positionsRight[i][1] = selectedPiece.posY+(i+1);
                        foundPiece = true;
                    } 
                }                
            }
            if(foundPiece == false)
            {
                // printf("%d %c\n",selectedPiece.posX,selectedPiece.posY+(i+1));
                positionsRight[i][0] = selectedPiece.posX;
                positionsRight[i][1] = selectedPiece.posY+(i+1);
            }
            
        }
    }
    foundPiece = false;
    for (int i = 0; i < 7; i++)//Left positions
    {
        if(selectedPiece.posY-(i+1) >= 'A')
        {
            for (int p = 0; p < 16; p++)
            {
                if(whiteTurn == true)
                {
                    if(pieces1[p].posX == selectedPiece.posX && pieces1[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        foundPiece = true;
                    }else if(pieces2[p].posX == selectedPiece.posX && pieces2[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        positionsLeft[i][0] = selectedPiece.posX;
                        positionsLeft[i][1] = selectedPiece.posY-(i+1);
                        foundPiece = true;
                    }           
                }
                else
                {
                    if(pieces2[p].posX == selectedPiece.posX && pieces2[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        foundPiece = true;
                    }else if(pieces1[p].posX == selectedPiece.posX && pieces1[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        //printf("Found Piece -> %c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        positionsLeft[i][0] = selectedPiece.posX;
                        positionsLeft[i][1] = selectedPiece.posY-(i+1);
                        foundPiece = true;
                    }
                }                
            }
            if(foundPiece == false)
            {
                // printf("%d %c\n",selectedPiece.posX,selectedPiece.posY-(i+1));
                positionsLeft[i][0] = selectedPiece.posX;
                positionsLeft[i][1] = selectedPiece.posY-(i+1);
            }
            
        }
    }
    
    //check diagonal 1
    for (int i = 0; i < 7; i++)
    {
        if(selectedPiece.posX+(i+1) <= 8 && selectedPiece.posY-(i+1) >= 'A')
        {
            for (int p = 0; p < 16; p++)
            {
                if(whiteTurn)
                {
                    if(pieces1[p].posX == selectedPiece.posX+(i+1) && pieces1[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        printf("Found Piece Down\n");
                        printf("%c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        foundPiece = true;
                    }else if(pieces2[p].posX == selectedPiece.posX+(i+1) && pieces2[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        printf("Found Piece Down\n");
                        printf("%c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        availablePositionsDiagonal1Down[i][0] = selectedPiece.posX+(i+1);
                        availablePositionsDiagonal1Down[i][1] = selectedPiece.posY-(i+1);
                        foundPiece = true;
                    }
                }
                else if(whiteTurn == false)
                {
                    if(pieces2[p].posX == selectedPiece.posX+(i+1) && pieces2[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        printf("Found Piece Down\n");
                        printf("%c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        foundPiece = true;                        
                    }else if(pieces1[p].posX == selectedPiece.posX+(i+1) && pieces1[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        printf("Found Piece Down\n");
                        printf("%c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        availablePositionsDiagonal1Down[i][0] = selectedPiece.posX+(i+1);
                        availablePositionsDiagonal1Down[i][1] = selectedPiece.posY-(i+1);
                        foundPiece = true;
                    }
                }
            }
            if(foundPiece == false)
            {
                availablePositionsDiagonal1Down[i][0] = selectedPiece.posX+(i+1);
                availablePositionsDiagonal1Down[i][1] = selectedPiece.posY-(i+1);
                //printf("%d %c\n",selectedPiece.posX+(i+1),selectedPiece.posY-(i+1));
            }
            
        }
    }
    foundPiece = false;
    for (int i = 0; i < 7; i++)
    {
        if(selectedPiece.posX-(i+1) > 0 && selectedPiece.posY+(i+1) <= 'H')
        {
            for (int p = 0; p < 16; p++)
            {
                if(whiteTurn)
                {
                    if(pieces1[p].posX == selectedPiece.posX-(i+1) && pieces1[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Up\n");
                        // printf("%c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        foundPiece = true;
                    }
                    else if(pieces2[p].posX == selectedPiece.posX-(i+1) && pieces2[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Up\n");
                        // printf("%c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        availablePositionsDiagonal1Up[i][0] = selectedPiece.posX-(i+1);
                        availablePositionsDiagonal1Up[i][1] = selectedPiece.posY+(i+1);
                        foundPiece = true;
                    }
                }
                else if(whiteTurn == false)
                {
                    if(pieces2[p].posX == selectedPiece.posX-(i+1) && pieces2[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Up\n");
                        // printf("%c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        foundPiece = true;
                    }else if(pieces1[p].posX == selectedPiece.posX-(i+1) && pieces1[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Up\n");
                        // printf("%c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        availablePositionsDiagonal1Up[i][0] = selectedPiece.posX-(i+1);
                        availablePositionsDiagonal1Up[i][1] = selectedPiece.posY+(i+1);
                        foundPiece = true;
                    }
                }
            }
            if(foundPiece == false)
            {
                availablePositionsDiagonal1Up[i][0] = selectedPiece.posX-(i+1);
                availablePositionsDiagonal1Up[i][1] = selectedPiece.posY+(i+1);
                // printf("%d %c\n",selectedPiece.posX-(i+1),selectedPiece.posY+(i+1));
            }
        }
    }
    //check diagonal 2
    foundPiece = false;
    for (int i = 0; i < 7; i++)
    {
        if(selectedPiece.posX+(i+1) <= 8 && selectedPiece.posY+(i+1) <= 'H')
        {
            for (int p = 0; p < 16; p++)
            {
                if(whiteTurn)
                {
                    if(pieces1[p].posX == selectedPiece.posX+(i+1) && pieces1[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Down\n");
                        // printf("%c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        foundPiece = true;
                    }else if(pieces2[p].posX == selectedPiece.posX+(i+1) && pieces2[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Down\n");
                        // printf("%c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        availablePositionsDiagonal2Down[i][0] = selectedPiece.posX+(i+1);
                        availablePositionsDiagonal2Down[i][1] = selectedPiece.posY+(i+1);
                        foundPiece = true;
                        
                    }
                }
                else if(whiteTurn == false)
                {
                    if(pieces2[p].posX == selectedPiece.posX+(i+1) && pieces2[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Down\n");
                        // printf("%c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        foundPiece = true;                        
                    }else if(pieces1[p].posX == selectedPiece.posX+(i+1) && pieces1[p].posY == selectedPiece.posY+(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Down\n");
                        // printf("%c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        availablePositionsDiagonal2Down[i][0] = selectedPiece.posX+(i+1);
                        availablePositionsDiagonal2Down[i][1] = selectedPiece.posY+(i+1);
                        foundPiece = true;
                    }
                }
            }
            if(foundPiece == false)
            {
                availablePositionsDiagonal2Down[i][0] = selectedPiece.posX+(i+1);
                availablePositionsDiagonal2Down[i][1] = selectedPiece.posY+(i+1);
                // printf("%d %c\n",selectedPiece.posX+(i+1),selectedPiece.posY-(i+1));
            }
            
        }
    }
    foundPiece = false;
    for (int i = 0; i < 7; i++)
    {
        if(selectedPiece.posX-(i+1) > 0 && selectedPiece.posY-(i+1) >= 'A')
        {
            for (int p = 0; p < 16; p++)
            {
                if(whiteTurn)
                {
                    if(pieces1[p].posX == selectedPiece.posX-(i+1) && pieces1[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Up\n");
                        // printf("%c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        foundPiece = true;
                    }else if(pieces2[p].posX == selectedPiece.posX-(i+1) && pieces2[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Up\n");
                        // printf("%c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        availablePositionsDiagonal2Up[i][0] = selectedPiece.posX-(i+1);
                        availablePositionsDiagonal2Up[i][1] = selectedPiece.posY-(i+1);
                        foundPiece = true;
                    }
                }
                else if(whiteTurn == false)
                {
                    if(pieces2[p].posX == selectedPiece.posX-(i+1) && pieces2[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Up\n");
                        // printf("%c %d %c\n",pieces2[p].costume,pieces2[p].posX,pieces2[p].posY);
                        foundPiece = true;
                    }else if(pieces1[p].posX == selectedPiece.posX-(i+1) && pieces1[p].posY == selectedPiece.posY-(i+1) && foundPiece == false)
                    {
                        // printf("Found Piece Up\n");
                        // printf("%c %d %c\n",pieces1[p].costume,pieces1[p].posX,pieces1[p].posY);
                        availablePositionsDiagonal2Up[i][0] = selectedPiece.posX-(i+1);
                        availablePositionsDiagonal2Up[i][1] = selectedPiece.posY-(i+1);
                        foundPiece = true;
                    }
                }
            }
            if(foundPiece == false)
            {
                availablePositionsDiagonal2Up[i][0] = selectedPiece.posX-(i+1);
                availablePositionsDiagonal2Up[i][1] = selectedPiece.posY-(i+1);
                // printf("%d %c\n",selectedPiece.posX-(i+1),selectedPiece.posY+(i+1));
            }
        }
    }

    //show diagonal positions
    for (int i = 0; i < 7; i++)
    {        
        if(availablePositionsDiagonal1Down[i][0] != 0 && availablePositionsDiagonal1Down[i][1] != 0)
        {
            printf("-> %d %c D1D\n",availablePositionsDiagonal1Down[i][0],availablePositionsDiagonal1Down[i][1]);
            existsPositions = true;
        }
    }
    for (int i = 0; i < 7; i++)
    {        
        if(availablePositionsDiagonal1Up[i][0] != 0 && availablePositionsDiagonal1Up[i][1] != 0)
        {
            printf("-> %d %c D1U\n",availablePositionsDiagonal1Up[i][0],availablePositionsDiagonal1Up[i][1]);
            existsPositions = true;
        }
    }
    for (int i = 0; i < 7; i++)
    {        
        if(availablePositionsDiagonal2Down[i][0] != 0 && availablePositionsDiagonal2Down[i][1] != 0)
        {
            printf("-> %d %c D2D\n",availablePositionsDiagonal2Down[i][0],availablePositionsDiagonal2Down[i][1]);
            existsPositions = true;
        }
    }
    for (int i = 0; i < 7; i++)
    {        
        if(availablePositionsDiagonal2Up[i][0] != 0 && availablePositionsDiagonal2Up[i][1] != 0)
        {
            printf("-> %d %c D2U\n",availablePositionsDiagonal2Up[i][0],availablePositionsDiagonal2Up[i][1]);
            existsPositions = true;
        }
    }     
    //show cross positions
    for (int i = 0; i < 7; i++)
    {        
        if(positionsTop[i][0] != 0 && positionsTop[i][1] != 0)
        {
            printf("-> %d %c\n",positionsTop[i][0],positionsTop[i][1]);
            existsPositions = true;
        }
    }
    for (int i = 0; i < 7; i++)
    {        
        if(positionsBottom[i][0] != 0 && positionsBottom[i][1] != 0)
        {
            printf("-> %d %c\n",positionsBottom[i][0],positionsBottom[i][1]);
            existsPositions = true;
        }
    }
    for (int i = 0; i < 7; i++)
    {        
        if(positionsRight[i][0] != 0 && positionsRight[i][1] != 0)
        {
            printf("-> %d %c\n",positionsRight[i][0],positionsRight[i][1]);
            existsPositions = true;
        }
    }
    for (int i = 0; i < 7; i++)
    {        
        if(positionsLeft[i][0] != 0 && positionsLeft[i][1] != 0)
        {
            printf("-> %d %c\n",positionsLeft[i][0],positionsLeft[i][1]);
            existsPositions = true;
        }
    }

    if(existsPositions)
    {
        bool checkPosX = false;
        bool checkPosY = false;
        do
        {
            printf("Select line: ");
            scanf("%d",&posX);
            for (int i = 0; i < 7; i++)
            {
                if((availablePositionsDiagonal1Down[i][0] == posX || availablePositionsDiagonal1Up[i][0] == posX || availablePositionsDiagonal2Down[i][0] == posX || availablePositionsDiagonal2Up[i][0] == posX || positionsTop[i][0] == posX || positionsRight[i][0] == posX || positionsBottom[i][0] == posX || positionsLeft[i][0] == posX) && posX != 0)
                {
                    checkPosX = true;
                }
            }
            
        } while (checkPosX == false);

        do
        {
            printf("Select Column: ");
            scanf(" %c",&posY);
            posY = toupper(posY);
            for (int i = 0; i < 7; i++)
            {
                if((availablePositionsDiagonal1Down[i][1] == posY || availablePositionsDiagonal1Up[i][1] == posY || availablePositionsDiagonal2Down[i][1] == posY || availablePositionsDiagonal2Up[i][1] == posY || positionsTop[i][1] == posY || positionsRight[i][1] == posY || positionsBottom[i][1] == posY || positionsLeft[i][1] == posY) && posY != 0)
                {
                    checkPosY = true;
                }
            }
        } while (checkPosY == false);

        if(whiteTurn == true)
        {
            for (int i = 0; i < 16; i++)
            {
                if(pieces2[i].posX == posX && pieces2[i].posY == posY)
                {
                    pieces2[i].posX = 0;
                    pieces2[i].posY = 0;
                }
            }

            pieces1[index].posX = posX;
            pieces1[index].posY = posY;
        }
        else if(whiteTurn == false)
        {
            for (int i = 0; i < 16; i++)
            {
                if(pieces1[i].posX == posX && pieces1[i].posY == posY)
                {
                    pieces1[i].posX = 0;
                    pieces1[i].posY = 0;
                }
            }

            pieces2[index].posX = posX;
            pieces2[index].posY = posY;
        }        
    }        
}

void moveKing(piece selectedPiece,int index,int posX,char posY)//done
{
    int availablePositions[8][2] = {0};
            bool checkPosX = false;
            bool checkPosY = false;
            availablePositions[0][0] = selectedPiece.posX+1;
            availablePositions[0][1] = selectedPiece.posY;
            availablePositions[1][0] = selectedPiece.posX+1;
            availablePositions[1][1] = selectedPiece.posY+1;
            availablePositions[2][0] = selectedPiece.posX+1;
            availablePositions[2][1] = selectedPiece.posY-1;

            availablePositions[3][0] = selectedPiece.posX-1;
            availablePositions[3][1] = selectedPiece.posY;
            availablePositions[4][0] = selectedPiece.posX-1;
            availablePositions[4][1] = selectedPiece.posY+1;
            availablePositions[5][0] = selectedPiece.posX-1;
            availablePositions[5][1] = selectedPiece.posY-1;

            availablePositions[6][0] = selectedPiece.posX;
            availablePositions[6][1] = selectedPiece.posY-1;

            availablePositions[7][0] = selectedPiece.posX;
            availablePositions[7][1] = selectedPiece.posY+1;

            for(int i = 0; i < 8 ; i++)
            {
                if(availablePositions[i][0] < 1 || availablePositions[i][0] > 8)
                {
                    availablePositions[i][0] = 0;
                    availablePositions[i][1] = 0;
                }

                if(availablePositions[i][1] < 'A' || availablePositions[i][1] > 'H')
                {
                    availablePositions[i][0] = 0;
                    availablePositions[i][1] = 0;
                }
            }

            if(whiteTurn == true)
            {
                for(int p = 0; p < 16 ; p++)
                {
                    for(int pos = 0; pos < 8 ; pos++)
                    {
                        if(pieces1[p].posX == availablePositions[pos][0] && pieces1[p].posY == availablePositions[pos][1])
                        {
                            availablePositions[pos][0] = 0;
                            availablePositions[pos][1] = 0;
                        }
                    }
                }
            }
            else if(whiteTurn == false)
            {
                for(int p = 0; p < 16 ; p++)
                {
                    for(int pos = 0; pos < 8 ; pos++)
                    {
                        if(pieces2[p].posX == availablePositions[pos][0] && pieces2[p].posY == availablePositions[pos][1])
                        {
                            availablePositions[pos][0] = 0;
                            availablePositions[pos][1] = 0;
                        }
                    }
                }
            }
            bool existPositions = false;
            for(int i = 0;i<8;i++)
            {
                if(availablePositions[i][0] != 0 && availablePositions[i][1] != 0)
                {
                    printf("-> %d %c\n",availablePositions[i][0],availablePositions[i][1]);
                    existPositions = true;
                }
            }

            if(existPositions == true)
            {
                do
                {
                    printf("Select line: ");
                    scanf("%d",&posX);
                    for(int pos = 0; pos < 8 ; pos++)
                    {
                        if(availablePositions[pos][0] == posX)
                        {
                            checkPosX = true;
                            break;
                        }else
                        {
                            checkPosX = false;
                        }                    
                    }
                    if(checkPosX == false)
                    {
                        printf("Not available line for movement!\n");
                    }

                } while (checkPosX == false);
                
                do
                {
                    printf("Select column: ");
                    scanf(" %c",&posY);
                    posY = toupper(posY);
                    for(int pos = 0; pos < 8 ; pos++)
                    {
                        if(availablePositions[pos][1] == posY)
                        {
                            checkPosY = true;
                            break;
                        }else
                        {
                            checkPosY = false;
                        }                    
                    }
                    if(checkPosY == false)
                    {
                        printf("Not available column for movement!\n");
                    }
                } while (checkPosY == false);

                if(whiteTurn == true)
                {
                    for(int i = 0; i<16;i++)
                    {
                        if(posX == pieces2[i].posX && posY == pieces2[i].posY)
                        {
                            pieces2[i].posX = 0;
                            pieces2[i].posY = 0;
                        }
                    }
                    pieces1[index].posX = posX;
                    pieces1[index].posY = posY;

                }
                else if(whiteTurn == false)
                {
                    for(int i = 0; i<16;i++)
                    {
                        if(posX == pieces1[i].posX && posY == pieces1[i].posY)
                        {
                            pieces1[i].posX = 0;
                            pieces1[i].posY = 0;
                            break;
                        }
                    }
                    pieces2[index].posX = posX;
                    pieces2[index].posY = posY;                
                }
            }          
}    