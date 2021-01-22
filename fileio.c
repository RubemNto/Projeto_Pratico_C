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
	piece tempPiece2[16];
	printf("Write location of data file: ");
	gets(fileLocation);

	FILE *fp = fopen(fileLocation,"r");
	if(fp == NULL)
	{
		printf("Error!");   
		exit(1);             
	}else
	{
		for (int i = 0; i < 67; i++)
		{
			fgets(data[i],6,fp);
		}
		//0 --> 31 --> pieces1 data
		//33 --> 64 --> pieces2 data
		//66 --> whiteTurn
		int counter;
		for (int i = 0; i < 32; i++)
		{
			data[i][0];//costume
			data[i][2];//line
			data[i][4];//column
		}
		for (int i = 33; i < 65; i++)
		{
			
		}
		
						
	}
	fclose(fp);
	
}