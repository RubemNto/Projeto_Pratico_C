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

void startMenu();
void createTable();
//void loadTable(piece _pieces1[], piece _pieces2[]);
void reCreateTable();
void writeRandom();
void writeCoordinatesOfPieces(FILE *savedData);
void writePlayerTurn(FILE *savedData);
char lookForPiece(int posX, int posY);
//void writePlayersNickname(FILE *savedData);
void movePiece();
void confirmContinueGame();

void createPlayers();
void setWhite();
void checkGame();
void loadTable(piece _pieces1[], piece _pieces2[], player tempPlayers[2], int vez);


void movePawn(piece selectedPiece,int index,int posX,char posY);
void moveRook(piece selectedPiece,int index,int posX,char posY);
void moveKnight(piece selectedPiece,int index,int posX,char posY);
void moveBishop(piece selectedPiece,int index,int posX,char posY);
void moveQueen(piece selectedPiece,int index,int posX,char posY);
void moveKing(piece selectedPiece,int index,int posX,char posY);


