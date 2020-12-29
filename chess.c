#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int posX,posY;
    char costume;
}piece;

void createTable()
{
    //creates a random table of black and white chess pieces represented 
    //by lower case and upper case characters respectively on the 8x8 board
    piece pieces1[16];
    piece pieces2[16];
    char costumes[9] = {'p','r','n','b','q','k','b','n','r'};
    for (int i = 0, b = 'A'; i < 16; i++,b++)
    {
        if(i<=7)
        {
            pieces1[i].costume = toupper(costumes[i+1]);
            pieces1[i].posY = b; 
            pieces1[i].posX = i+1;

        }else
        {
            pieces1[i].costume = toupper(costumes[0]);
            pieces1[i].posY = b;
        }        
    }

    for (int i = 0; i < 16; i++)
    {
        if(i<=7)
        {

        }else
        {
            
        }        
    }
    

}

// void createTable()
// {
//     //creates a random table of black and white chess pieces represented 
//     //by lower case and upper case characters respectively on the 8x8 board
//     piece pieces[32];
//     char costumes[9] = {'p','r','n','b','q','k','b','n','r'};
//     srand(time(0));
//     int random = rand()%2;
//     for (int i = 'A'; i <= 'H'; i++)
//     {
//         printf("   %c",i);
//     }
//     printf("\n");
//     if(random == 0)
//     {    
//         for (int l = 0; l < 8; l++)
//         {
//             printf("%d ",l+1);
//             for (int i = 0,b ='A'; i < 8; i++,b++)
//             {
//                 if(l+1 == 1)
//                 {
//                     pieces[i+1].costume = costumes[i+1];
//                     pieces[i+1].posX = l+1;
//                     pieces[i+1].posY = b;
//                     printf(" [%c]",costumes[i+1]);
//                 }else if(l+1 == 2)
//                 {
//                     pieces[0].costume = costumes[0];
//                     pieces[i+1].posX = l+1;
//                     pieces[i+1].posY = b;
//                     printf(" [%c]",costumes[0]);                    
//                 }else if(l+1 == 7)
//                 {
//                     printf(" [%c]",toupper(costumes[0]));
//                 }else if(l+1 == 8)
//                 {
//                     printf(" [%c]",toupper(costumes[i+1]));
//                 }else
//                 {
//                     printf(" [ ]");
//                 }                        
//             }
//             printf("\n");        
//         }
//     }else
//     {
//         for (int l = 0; l < 8; l++)
//         {
//             printf("%d ",l+1);
//             for (int i = 0; i < 8; i++)
//             {
//                 if(l+1 == 1)
//                 {
//                     printf(" [%c]",toupper(costumes[i+1]));
//                 }else if(l+1 == 2)
//                 {
//                     printf(" [%c]",toupper(costumes[0]));
//                 }else if(l+1 == 7)
//                 {
//                     printf(" [%c]",costumes[0]);
//                 }else if(l+1 == 8)
//                 {
//                     printf(" [%c]",costumes[i+1]);
//                 }else
//                 {
//                     printf(" [ ]");
//                 }                        
//             }
//             printf("\n");        
//         }
//     }    
// }

// void createTable(int x1,int y1,int x2,int y2,char piece)
// {
//     //given two coordinates re creates the table moving the selected piece


// }