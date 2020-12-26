#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "chess.h"
#include "fileio.h"

typedef struct 
{
    char v;
    char h;
    char index;    
    //char pieces[6] = {'p','r','n','b','k','q'};    
}piece;
typedef struct
{
    char pi[6];// = {'p','r','n','b','k','q'};    
}pieces;



int main()
{    
    createTable();
    return 0;
}