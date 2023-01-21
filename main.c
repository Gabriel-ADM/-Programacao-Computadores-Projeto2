#include <stdio.h>
#include <stdlib.h>

#define max 3

// Declara arquivos e define permissoes de acesso para eles
FILE *getFile(const char *file, char *mode)
{
    FILE *fp;
    fp = fopen(file, mode);
    return fp;
}

// Le arquivo de entrada e armazena em matriz 3x3
void readBoard(FILE *entryfp, char oldLadyBoard[max][max])
{
    for (int i = 0; i < max; i++)
    {
        fscanf(entryfp, "%s", oldLadyBoard[i]);
    }
}

int main(int argc, char const *argv[])
{
    FILE *entryFile;
    entryFile = getFile(argv[1], "r");

    FILE *outFile;
    outFile = getFile(argv[2], "w");

    char board[max][max];
    readBoard(entryFile, board);

    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    // Armazena as coordenadas em branco 
    int blankPositions[max * max][2];
    int blankCount = 0;
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            if (board[i][j] == 'B')
            {
                blankPositions[blankCount][0] = i;
                blankPositions[blankCount][1] = j;
                blankCount++;
                // printf("(%d,%d)", i, j);
            }
        }
    }

    for (int i = 0; i < max; i++)
    {
        printf("\n(%d,%d)", blankPositions[i][0], blankPositions[i][1]);
    }

    fclose(outFile);
    fclose(entryFile);
    /* code */
    return 0;
}
