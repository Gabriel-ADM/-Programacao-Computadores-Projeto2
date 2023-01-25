#include "getBoard.h"

// Get File
// Declara arquivos e define permissoes de acesso para eles
FILE *getFile(const char *file, char *mode)
{
    FILE *fp;
    fp = fopen(file, mode);
    return fp;
}

// Read Game Board
// Le arquivo de entrada e armazena em matriz 3x3
void readBoard(FILE *entryfp, char oldLadyBoard[max][maxStr])
{
    for (int i = 0; i < max; i++)
        fscanf(entryfp, "%s", oldLadyBoard[i]);
}
