#include"output.h"

// Imprime tabuleiro padrao no arquivo de saida
// Output Board
void outputBoard(FILE *outpuFile, char oldLadyBoard[max][maxStr])
{
    fprintf(outpuFile, "\n");
    for (int i = 0; i < max; i++)
        fprintf(outpuFile, "%s\n", oldLadyBoard[i]);
}

// Imprime tabuleiro padrao no terminal
// Print Board
void printBoard(char oldLadyBoard[max][maxStr])
{
    for (int i = 0; i < max; i++)
        printf("%s\n", oldLadyBoard[i]);
}

