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
    char name1[10] = "";
    char name2[10] = "";
    createTable();
    return 0;
}

// typedef struct
//     {
//         int idade;
//     }me;

// int main()
// {
//     struct {
//     char nome[60];
//     int dia, mes, ano;
//     } pessoas[4];

    
//     me eu[100];

//     int i;
//     for(i=0; i<4; i++) {
//     printf("NOME: "); fgets(pessoas[i].nome,60,stdin);
//     printf("DATA NASCIMENTO:\n");
//     printf("\tDIA: "); scanf("%d", &pessoas[i].dia);
//     printf("\tMES: "); scanf("%d", &pessoas[i].mes);
//     printf("\tANO: "); scanf("%d", &pessoas[i].ano);
//     //fflush(stdin);
//     while( getchar() != '\n');
//     }
//     printf("LISTA:\n");
//     for(i=0; i<4; i++) {
//     printf("[%d] %s ", i, pessoas[i].nome);
//     printf("%d-%d-%d\n",pessoas[i].dia,pessoas[i].mes,pessoas[i].ano);
//     }


//     return 0;
// }

