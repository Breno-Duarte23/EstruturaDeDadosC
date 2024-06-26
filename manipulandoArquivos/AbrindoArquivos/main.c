#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main()
{
    // cria ponteiro do arquivo
    FILE *arquivo;
    char palavra[50], c;
    int sair=0, linhas=0;

    // abre o arquivo
    arquivo = fopen("exercicio1.txt", "w");

    // verifica se o arquivo foi aberto ou criado corretamente
    if(arquivo==NULL){
        printf("Falha ao abrir/criar arquivo!");
        return 1;
    }

    do{
        printf("Informe uma palavra ou 0 para sair: ");
        fgets(palavra, 50, stdin);

        if(strcmp(palavra, "0\n")==0){
            sair = 1;
        }

        if(sair==0){
            fprintf(arquivo, "%s", palavra);
        }

    }while(sair==0);

    fclose(arquivo);

    arquivo = fopen("exercicio1.txt", "r");

    if(arquivo==NULL){
        printf("Falha ao abrir/criar arquivo!");
        return 1;
    }

    printf("\nConteudo do Arquivo:\n", linhas);

    while(feof(arquivo)==0){
        c = fgetc(arquivo);
        printf("%c", c);
        if(c=='\n'){
            linhas++;
        }
    }

    fclose(arquivo);

    printf("\nNumero de linhas: %d\n", linhas);

    return 0;
}
