#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arquivo;
    char c, linha[5];
    int soma=0;

    arquivo = fopen("arquivo.txt", "r");

    if(arquivo==NULL){
        printf("Falha ao ler o arquivo");
        return 1;
    }

    while(feof(arquivo)==0){
        fgets(linha, 5, arquivo);
        soma = soma + atoi(linha);
    }

    printf("A soma eh: %d", soma);

    fclose(arquivo);

    return 0;
}
