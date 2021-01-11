#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "chess.h"
#include <stdbool.h>
#include <math.h>

piece pieces1[16];
piece pieces2[16];

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
    printf("   A");
    for (int i = 'B'; i <= 'H'; i++)
    {
        printf("  %c",i);
    }
    printf("\n");
    for (int l = 1; l <= 8; l++)
    {
        printf("%d ", l);
        for (int c = 'A',i = 0; c <= 'H'; c++,i++)
        {
            if((l == pieces1[i].posX) && (c == pieces1[i].posY))
            {
                printf("[%c]",pieces1[i].costume);
            }else if((l == pieces2[i].posX) && (c == pieces2[i].posY))
            {
                printf("[%c]",pieces2[i].costume);
            }else if((l == pieces1[i+8].posX) && (c == pieces1[i+8].posY))
            {
                printf("[%c]",pieces1[i+8].costume);
            }else if((l == pieces2[i+8].posX) && (c == pieces2[i+8].posY))
            {
                printf("[%c]",pieces2[i+8].costume);
            }else
            {
                printf("[ ]");
            }                                    
        }
        printf("\n");        
    }    
}

void movePiece(bool whiteTurn)
{
    int posX = 0;//select piece line
    int posY = 0;//select piece column
    char selectedPieceCostume = ' ';
    piece selectedPiece;
    //select piece
    //receive coordinates from the table and verify if exists in the table
    if(whiteTurn == true)
    {
        printf("<<Whites turn>>\n");
    }else
    {
        printf("<<Blacks turn>>\n");
    }
        
    // while(selectedPieceCostume == ' ')
    // {
        while(posX <= 0 || posX > 8)//choose a line form the table
        {
            printf("Select piece\n");
            printf("Line of the Piece: ");
            scanf("%d",&posX);
            if(posX <= 0 || posX > 8)//if the choice is outside of the table, teel the player that he is out of bounds
            {
                printf("Outside of the table\nWrite a valid number from the table!\n");
            }
        }
        while(posY <= 0 || posY > 'H')//choose a column from the table
        {
            printf("Column of the Piece: ");
            scanf("%d",&posY);
            posY = toupper(posY);
            if(posY <= 0 || posY > 'H')//if the choice is outside of the table, teel the player that he is out of bounds
            {
                printf("Outside of the table\nWrite a valid Column from the table!\n");
            }
        }
        // for (int i = 0; i < 16; i++)
        // {
        //     if(pieces1[i].posX == posX && pieces1[i].posY == posY)
        //     {
        //         selectedPieceCostume = pieces1[i].costume;
        //         break;
        //     }else if(pieces2[i].posX == posX && pieces2[i].posY == posY)
        //     {
        //         selectedPieceCostume = pieces2[i].costume;
        //         break;
        //     }
        // }
        // if(selectedPieceCostume == ' ')//if player selects a blank space
        // {
        //     printf("Blank space, select a valid piece");
        //     selectedPieceCostume = ' ';
        //     posX = 0;
        //     posY=0;
        // }else if(whiteTurn == true && selectedPieceCostume != toupper(selectedPieceCostume))//if player selects a piece form the opponent
        // {
        //     printf("Opponent piece selected, choose one of your own!\n");
        //     selectedPieceCostume = ' ';
        //     posX = 0;
        //     posY=0;
        // }else if(whiteTurn == false && selectedPieceCostume == toupper(selectedPieceCostume))//if player selects a piece form the opponent
        // {
        //     printf("Opponent piece selected, choose one of your own!\n");
        //     selectedPieceCostume = ' ';
        //     posX = 0;
        //     posY=0;
        // }
    //}
    // for (int i = 0; i < 16; i++)//Select the piece from the board given the data received
    // {
    //     if(pieces1[i].posX == posX && pieces1[i].posY == posY && pieces1[i].costume == selectedPieceCostume)
    //     {
    //         selectedPiece = pieces1[i];
    //         break;
    //     }else if(pieces2[i].posX == posX && pieces2[i].posY == posY && pieces2[i].costume == selectedPieceCostume)
    //     {
    //         selectedPiece = pieces2[i];
    //         break;
    //     }        
    // }
    
    //show possible coordinates
        //given the costume of the piece, show the positions allowed
    /*'p','r','n','b','q','k','b','n','r'*/
    // posX = 0;//select new line to move
    // posY = 0;//select new column to move
    
    //     if(selectedPiece.costume == 'p' || selectedPiece.costume == 'P')
    //     {
    //         //-> move forawrd only once
    //         //write available spaces
    //         int availablePositions[2] = {0};
    //         availablePositions[0] = selectedPiece.posX + 1;
    //         availablePositions[1] = selectedPiece.posY;
    //         printf("Available spaces for movement:\n -> %d %c",availablePositions[0],availablePositions[1]);
    //         //get position inputed by player
    //         //change piece position on the board

    //     }else if(selectedPiece.costume == 'r' || selectedPiece.costume == 'R')
    //     {
    //         //-> move forward or sideways as much as needed
    //         int availableLines[7] = {0};//vertical
    //         int availableColums[7] = {0};//herizontal
    //         if(selectedPiece.posX == 1)
    //         {
    //             for (int i = 0; i < 7; i++)
    //             {
    //                 availableLines[i] = i+2;
    //             }                
    //         }
    //         else if(selectedPiece.posX == 8)
    //         {
    //             for (int i = 6; i >= 0; i--)
    //             {
    //                 availableLines[i] = i+1;
    //             }
    //         }
    //         else if(selectedPiece.posX > 1 && selectedPiece.posX < 8)
    //         {
    //             int down = selectedPiece.posX - 1;
    //             //int up = 8 - selectedPiece.posX;
    //             int p = 0;
    //             for (int i = down; i > 0; i--,p++)
    //             {
    //                 availableLines[p] = i;
    //             }
    //             for (int i = selectedPiece.posX+1; i <= 8; i++,p++)
    //             {
    //                 availableLines[p] = i;
    //             }                
    //         }
            
    //         if(selectedPiece.posY == 'A')
    //         {
    //             for (int i = 0; i < 7; i++)
    //             {
    //                 availableColums[i] = selectedPiece.posY+1;
    //             }
                
    //         }
    //         else if(selectedPiece.posY == 'H')
    //         {
    //             for (int i = 0,c = 'A'; i < 7; i++,c++)
    //             {
    //                 availableColums[i] = c;
    //             }
                
    //         }
    //         else if(selectedPiece.posY > 'A' && selectedPiece.posY < 'H')
    //         {
    //             int down = selectedPiece.posY - 'A';
    //             int p = 0;
    //             for (int i = down; i >= 0; i--,p++)
    //             {
    //                 availableColums[p] = i;
    //             }
    //             for (int i = selectedPiece.posY+1; i <= 'H'; i++,p++)
    //             {
    //                 availableColums[p] = i;
    //             }
    //         }
            

    //     }else if(selectedPiece.costume == 'n' || selectedPiece.costume == 'N')
    //     {
    //         //-> move in L chape   
    //     }else if(selectedPiece.costume == 'b' || selectedPiece.costume == 'B')
    //     {
    //         //-> moves diagonaly
    //     }else if(selectedPiece.costume == 'q' || selectedPiece.costume == 'Q')
    //     {
    //         //-> moves at any direction as many spaces as needed
    //     }else if(selectedPiece.costume == 'k' || selectedPiece.costume == 'K')
    //     {
    //         //-> moves at any direction only once
    //     }
    
    



    
    //check coordinates added by player
        //if the player gives a coordinate that is not allowed, keep asking for one allowed
    //check if they are equal to any piece of the opponent
        //check every piece of the opponent, if any of them have the same as the players added coordinates, the costume is " "
    //recreate table
}
// // void createTable()
// // {
// //     //creates a random table of black and white chess pieces represented 
// //     //by lower case and upper case characters respectively on the 8x8 board
// //     piece pieces[32];
// //     char costumes[9] = {'p','r','n','b','q','k','b','n','r'};
// //     srand(time(0));
// //     int random = rand()%2;
// //     for (int i = 'A'; i <= 'H'; i++)
// //     {
// //         printf("   %c",i);
// //     }
// //     printf("\n");
// //     if(random == 0)
// //     {    
// //         for (int l = 0; l < 8; l++)
// //         {
// //             printf("%d ",l+1);
// //             for (int i = 0,b ='A'; i < 8; i++,b++)
// //             {
// //                 if(l+1 == 1)
// //                 {
// //                     pieces[i+1].costume = costumes[i+1];
// //                     pieces[i+1].posX = l+1;
// //                     pieces[i+1].posY = b;
// //                     printf(" [%c]",costumes[i+1]);
// //                 }else if(l+1 == 2)
// //                 {
// //                     pieces[0].costume = costumes[0];
// //                     pieces[i+1].posX = l+1;
// //                     pieces[i+1].posY = b;
// //                     printf(" [%c]",costumes[0]);                    
// //                 }else if(l+1 == 7)
// //                 {
// //                     printf(" [%c]",toupper(costumes[0]));
// //                 }else if(l+1 == 8)
// //                 {
// //                     printf(" [%c]",toupper(costumes[i+1]));
// //                 }else
// //                 {
// //                     printf(" [ ]");
// //                 }                        
// //             }
// //             printf("\n");        
// //         }
// //     }else
// //     {
// //         for (int l = 0; l < 8; l++)
// //         {
// //             printf("%d ",l+1);
// //             for (int i = 0; i < 8; i++)
// //             {
// //                 if(l+1 == 1)
// //                 {
// //                     printf(" [%c]",toupper(costumes[i+1]));
// //                 }else if(l+1 == 2)
// //                 {
// //                     printf(" [%c]",toupper(costumes[0]));
// //                 }else if(l+1 == 7)
// //                 {
// //                     printf(" [%c]",costumes[0]);
// //                 }else if(l+1 == 8)
// //                 {
// //                     printf(" [%c]",costumes[i+1]);
// //                 }else
// //                 {
// //                     printf(" [ ]");
// //                 }                        
// //             }
// //             printf("\n");        
// //         }
// //     }    
// // }

// // void createTable(int x1,int y1,int x2,int y2,char piece)
// // {
// //     //given two coordinates re creates the table moving the selected piece


// }