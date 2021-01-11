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
//void createTable(int x1,int y1,int x2,int y2,char piece);
