#include <stdbool.h>

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
void reCreateTable();
void writeRandom();
void writeCoordinatesOfPieces();
void movePiece(bool whiteTurn);

void createPlayers();
void setWhite();

