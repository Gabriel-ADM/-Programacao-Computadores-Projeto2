#include"consts.h"
#include"treatError.h"
#include"getBoard.h"
#include"autoPlay.h"
#include"output.h"

// Meu VS Code nao está reconhecendo o max do cabelhaco consts
// por esta razao o declarei novamente aq
#define max 3

int main(int argc, char const *argv[])
{
    // Função que le linha de comando e verifica se argc esta do tamanho 
    // correto para executar o programa
    readCMLine(argc);

    // Declarando e verificando arquivo de entrada
    FILE *entryFile;
    entryFile = getFile(argv[1], "r");
    testFile(entryFile, argv[1], "r");

    // Declarando e verificando arquivo de saida
    FILE *outFile;
    outFile = getFile(argv[2], "w");
    testFile(outFile, argv[2], "w");

    // Declaração de tabuleiro que conterá entrada 
    // e realizando leitura de acordo com arquivo de entrada
    char board[max][maxStr];
    readBoard(entryFile, board);

    // Realizando jogada ao mesmo tempo verificando se
    // jogador 'O' venceu as possiveis vitorias
    makePlay(outFile, board, 'O');

    // Liberando cada arquivo utilizado do cache
    fclose(entryFile);
    fclose(outFile);

    return 0;
}
