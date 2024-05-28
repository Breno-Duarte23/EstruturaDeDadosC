#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main()
{
    // cria ponteiro do arquivo
    FILE *arquivo;
    char palavra[50], c;
    int vogais = 0, consoantes = 0;

    // abre o arquivo

    arquivo = fopen("VogaisConsoantes.txt", "r");

    if(arquivo==NULL){
        printf("Falha ao abrir/criar arquivo!");
        return 1;
    }

   // printf("\nConteudo do Arquivo:\n", linhas);

    while(feof(arquivo)==0){
        c = fgetc(arquivo);
        printf("%c", c);
        if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')){
            vogais++;
        }else if((c >= 97) && (c<=122)){
            consoantes++;
        }
    }

    fclose(arquivo);
    printf("\nVogais: %d", vogais);
    printf("\nConsoantes: %d", consoantes);
    //printf("\nNumero de linhas: %d\n", linhas);

    return 0;
}
