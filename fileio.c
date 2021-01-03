#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void createFile() {
	FILE* game_state;

	//Error message
	char error[] = {"\nError while opening file."};

	//Cria o ficheiro
	game_state = fopen("Game State.txt", "w");

	//Fechar o ficheiro
	fclose(game_state);
}

void writeInFile() {


} 