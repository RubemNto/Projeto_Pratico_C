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
	int turn;
	piece tempPieces1[16];
	piece tempPieces2[16];
	player tempPlayers[2];
	printf("Write location of data file: ");
	gets(fileLocation);

	FILE *fp = fopen(fileLocation,"r");
	if(fp == NULL)
	{
		printf("Error!");   
		exit(1);             
	}else
	{
		char miracle;
		for (int i = 0; i < 16; i++)
		{
			fscanf(fp," %c",&(tempPieces1[i].costume)); 
			fgetc(fp);
			fscanf(fp,"%d",&(tempPieces1[i].posX)); 
			fgetc(fp);
			fscanf(fp," %c",&(miracle)); 
			fgetc(fp);

			switch (miracle)
			{
			case 'A':
				tempPieces1[i].posY = 65;
				break;
			case 'B':
				tempPieces1[i].posY = 66;
				break;
			case 'C':
				tempPieces1[i].posY = 67;
				break;	
			case 'D':
				tempPieces1[i].posY = 68;
				break;
			case 'E':
				tempPieces1[i].posY = 69;
				break;
			case 'F':
				tempPieces1[i].posY = 70;
				break;
			case 'G':
				tempPieces1[i].posY = 71;
				break;
			case 'H':
				tempPieces1[i].posY = 72;
				break;	
			default:
				break;
			}

			
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
			fscanf(fp," %c",&miracle); 
			fgetc(fp);

			//printf("%c",tempPieces2[i].costume);
			//printf("\n");
			//printf("%d \n",tempPieces2[i].posX);

			switch (miracle)
			{
			case 'A':
				tempPieces2[i].posY = 65;
				break;
			case 'B':
				tempPieces2[i].posY = 66;
				break;
			case 'C':
				tempPieces2[i].posY = 67;
				break;	
			case 'D':
				tempPieces2[i].posY = 68;
				break;
			case 'E':
				tempPieces2[i].posY = 69;
				break;
			case 'F':
				tempPieces2[i].posY = 70;
				break;
			case 'G':
				tempPieces2[i].posY = 71;
				break;
			case 'H':
				tempPieces2[i].posY = 72;
				break;	
			default:
				break;
			}
		
		}
		fgetc(fp);
		fscanf(fp,"%d",&turn);
		fgetc(fp);

		fscanf(fp,"%s",&(tempPlayers[0].nickname));
		fgetc(fp);
		fscanf(fp,"%s",&(tempPlayers[1].nickname));
		fgetc(fp);

		// printf("Branco: ");
		// printf("%s\n",tempPlayers[0].nickname);
		// printf("Preto: ");
		// printf("%s\n",tempPlayers[1].nickname);

		
		loadTable(tempPieces1, tempPieces2, tempPlayers, turn);
		
						
	}
	fclose(fp);
	
}