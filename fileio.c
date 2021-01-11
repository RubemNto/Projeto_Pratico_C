#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
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