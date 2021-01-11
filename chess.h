#include <stdbool.h>

typedef struct
{
    int posX,posY;
    char costume;
}piece;

void createTable();
void reCreateTable();
void writeRandom();
void writeCoordinatesOfPieces();
void movePiece(bool whiteTurn);
