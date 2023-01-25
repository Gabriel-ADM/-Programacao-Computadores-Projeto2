#include "autoPlay.h"

// Check win
// Armazena linhas, colunas e diagonais de um tabuleiro e verifica se algum deles sao tres O's seguidos
// Retorna valor 1 para verdadeiro e 0 para falso
int checkWin(char oldLadyBoard[max][maxStr])
{
    char rows[max][maxStr];
    char col[max][maxStr];
    char diag[max - 1][maxStr];

    for (int i = 0; i < max; i++)
        strcpy(rows[i], oldLadyBoard[i]);
    for (int i = 0; i < max; i++)
    {
        memset(col[i], '\0', maxStr);
        for (int j = 0; j < max; j++)
            col[i][j] = oldLadyBoard[j][i];
    }
    int k = 2;
    for (int i = 0; i < max; i++)
        memset(diag[i], '\0', maxStr);
    for (int i = 0; i < max; i++)
    {
        diag[0][i] = oldLadyBoard[i][i];
        diag[1][i] = oldLadyBoard[i][k];
        k--;
    }

    for (int i = 0; i < max; i++)
    {
        if (!strcmp(rows[i], "OOO"))
            return 1;
        else if (!strcmp(col[i], "OOO"))
            return 1;
    }
    for (int i = 0; i < max - 1; i++)
    {
        if (!strcmp(diag[i], "OOO"))
            return 1;
    }

    return 0;
}

// Make Play
// Realiza jogadas com letra selecionadas de forma alternada e gera tabuleiros copias para mais verificacoes
// A cada utilizacao tambem é verficado se jogador 'O' foi vitorioso na rodada caso afirmativo imprime no arquivo de saida
void makePlay(FILE *outputFile, char oldLadyBoard[max][maxStr], char wordPlayed)
{
    if (checkWin(oldLadyBoard))
    {
        outputBoard(outputFile, oldLadyBoard);
        return;
    }

    char newLadyBoard[max][maxStr];
    for (int i = 0; i < max; i++)
        strcpy(newLadyBoard[i], oldLadyBoard[i]);

    for (int i = 0; i < max; i++)
        for (int j = 0; j < max; j++)
            if (oldLadyBoard[i][j] == 'B')
            {
                newLadyBoard[i][j] = wordPlayed;
                if (wordPlayed == 'O')
                {
                    makePlay(outputFile, newLadyBoard, 'X');
                    // printBoard(newLadyBoard);
                    newLadyBoard[i][j] = 'B';
                }
                else
                {
                    makePlay(outputFile, newLadyBoard, 'O');
                    // printBoard(newLadyBoard);
                    newLadyBoard[i][j] = 'B';
                }
            }
}
