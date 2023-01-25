#ifndef getBoard
#define getBoard

#include "getBoard.h"
#include "consts.h"
#include <stdio.h>

FILE *getFile(const char *file, char *mode);
void readBoard(FILE *entryfp, char oldLadyBoard[max][maxStr]);

#endif