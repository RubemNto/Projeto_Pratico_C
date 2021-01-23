#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "chess.h"

void saveGame()
{
	FILE *gameData;
	gameData = fopen("GameData.txt","w");
	writeCoordinatesOfPieces(gameData);
	writePlayerTurn(gameData);
	//writePlayersNickname(gameData);
	fclose(gameData);
}


void loadGame()
{
	char fileLocation[200] = "";
	char data[67][6];
	piece tempPieces1[16];
	piece tempPieces2[16];
	_flushall();
	printf("Write location of data file: ");
	gets(fileLocation);

	FILE *fp = fopen(fileLocation,"r");
	if(fp == NULL)
	{
		printf("Error!");   
		exit(1);             
	}else
	{
		int counter;
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