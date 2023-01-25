#ifndef autoPlay
#define autoPlay

#include <stdio.h>
#include <string.h>
#include "consts.h"
#include "output.h"

int checkWin(char oldLadyBoard[max][maxStr]);
void makePlay(FILE *outputFile, char oldLadyBoard[max][maxStr], char wordPlayed);

#endif