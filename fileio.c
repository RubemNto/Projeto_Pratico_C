#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "chess.h"

//#include "Players.c"


//Função para criar ou abrir ficheiro
void fileManipulation() {
	
	//Apontador do ficheiro
	FILE *game_state;

	//Cria/Abre o ficheiro
	game_state = fopen("Game State.txt", "w");

	/*
	//Guarda o nickname de ambos os players
	char nickname1[12];
	char nickname2[12];

	//Copia os nicknames dos players
	strcpy(nickname1, players[1].nickname);
	strcpy(nickname2,players[2].nickname);

	//Escreve no ficheiro o nickname do player 1
	for (int i = 0; i < 12; i++)
	{
	    fprintf(game_state, "Player 1 nickname: %c", nickname1[12]);	
	}
	*/	
	fclose(game_state);
} 

void saveGame()
{
	FILE *gameData;
	gameData = fopen("GameData.txt","w");
	writeCoordinatesOfPieces(gameData);
	writePlayerTurn(gameData);
	fclose(gameData);
}

void loadGame()
{
	char fileLocation[200] = "";
	char data[67][6];
	piece tempPieces1[16];
	piece tempPieces2[16];
	printf("Write location of data file: ");
	gets(fileLocation);

	FILE *fp = fopen(fileLocation,"r");
	if(fp == NULL)
	{
		printf("Error!");   
		exit(1);             
	}else
	{
		for (int i = 0; i < 16; i++)
		{
			fscanf(fp," %c",&(tempPieces1[i].costume)); 
			fgetc(fp);
			fscanf(fp,"%d",&(tempPieces1[i].posX)); 
			fgetc(fp);
			fscanf(fp," %c",&(tempPieces1[i].posY)); 
			fgetc(fp);

			
			//printf("%c",tempPieces1[i].costume);
			//printf("\n");
			//printf("%d \n",tempPieces1[i].posX);
		

		}
		fgetc(fp);
		for (int i = 0; i < 16; i++)
		{
			fscanf(fp," %c",&(tempPieces2[i].costume)); 
			fgetc(fp);
			fscanf(fp,"%d",&(tempPieces2[i].posX)); 
			fgetc(fp);
			fscanf(fp,"%c",&(tempPieces2[i].posY)); 
			fgetc(fp);

			//printf("%c",tempPieces2[i].costume);
			//printf("\n");
			//printf("%d \n",tempPieces2[i].posX);
		
		}

		loadTable(tempPieces1, tempPieces2);
		
						
	}
	fclose(fp);
	
}