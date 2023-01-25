#ifndef output
#define output

#include <stdio.h>
#include "consts.h"
#include "output.h"

void outputBoard(FILE *outpuFile, char oldLadyBoard[max][maxStr]);
void printBoard(char oldLadyBoard[max][maxStr]);

#endif