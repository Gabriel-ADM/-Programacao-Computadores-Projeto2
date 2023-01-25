#include "treatError.h"

// Read Command Line
// Le strings passadas pela linha de comando verificando se a entrada esta no tamanho correto
void readCMLine(int argc)
{
    if (argc != 3)
    {
        printf("%d Entradas\n", argc);
        printf("Execute programa executavel de forma correta:\n\t.\\main entrada.arquivo saida.arquivo");
        exit(0);
    }
}

// Test File
// Verifica se arquivos utilizados estao inexistentes
void testFile(FILE *fp, const char *fileName, char *mode)
{
    if (fp == NULL)
    {
        printf("\nErro ao tentar acessar %s em modo %s", fileName, mode);
        exit(0);
    }
}