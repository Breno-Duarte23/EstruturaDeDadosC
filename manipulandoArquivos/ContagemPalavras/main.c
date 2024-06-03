#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main()
{
    FILE *arquivo, *arquivo_saida;
    char palavra[50];
    int contador=0;

    arquivo = fopen("arquivo.txt", "r");

    arquivo_saida = fopen("arquivo_saida.txt", "w");

    if(arquivo==NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    if(arquivo_saida==NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    while(fscanf(arquivo, "%s", palavra)==1){
        contador++;
    }

    fprintf(arquivo_saida, "Quantidade de palavras: %d", contador);

    fclose(arquivo);

    fclose(arquivo_saida);

    return 0;
}

