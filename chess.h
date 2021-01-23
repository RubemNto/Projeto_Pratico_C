#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int posX,posY;
    char costume;
}piece;

typedef struct
{
    char nickname[12];
}player;

void createTable();
void loadTable(piece _pieces1[], piece _pieces2[]);
void reCreateTable();
void writeRandom();
void writeCoordinatesOfPieces(FILE *savedData);
void writePlayerTurn(FILE *savedData);
void movePiece();

void createPlayers();
void setWhite();
void checkGame();
void setUpPieces();

