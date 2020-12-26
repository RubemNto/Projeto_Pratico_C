#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void createTable()
{
    //creates a random table of black and white chess pieces represented 
    //by lower case and upper case characters respectively on the 8x8 board

    char row[9] = {'p','r','n','b','q','k','b','n','r'};
    srand(time(0));
    int random = rand()%2;
    for (int i = 'A'; i <= 'H'; i++)
    {
        printf("   %c",i);
    }
    printf("\n");
    if(random == 0)
    {    
        for (int l = 0; l < 8; l++)
        {
            printf("%d ",l+1);
            for (int i = 0; i < 8; i++)
            {
                if(l+1 == 1)
                {
                    printf(" [%c]",row[i+1]);
                }else if(l+1 == 2)
                {
                    printf(" [%c]",row[0]);
                }else if(l+1 == 7)
                {
                    printf(" [%c]",toupper(row[0]));
                }else if(l+1 == 8)
                {
                    printf(" [%c]",toupper(row[i+1]));
                }else
                {
                    printf(" [ ]");
                }                        
            }
            printf("\n");        
        }
    }else
    {
        for (int l = 0; l < 8; l++)
        {
            printf("%d ",l+1);
            for (int i = 0; i < 8; i++)
            {
                if(l+1 == 1)
                {
                    printf(" [%c]",toupper(row[i+1]));
                }else if(l+1 == 2)
                {
                    printf(" [%c]",toupper(row[0]));
                }else if(l+1 == 7)
                {
                    printf(" [%c]",row[0]);
                }else if(l+1 == 8)
                {
                    printf(" [%c]",row[i+1]);
                }else
                {
                    printf(" [ ]");
                }                        
            }
            printf("\n");        
        }
    }    
}

// void createTable(int x1,int y1,int x2,int y2,char piece)
// {
//     //given two coordinates re creates the table moving the selected piece


// }