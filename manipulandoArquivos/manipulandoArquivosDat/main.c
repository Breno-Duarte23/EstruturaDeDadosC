#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct{
    char nome[50];
    int pontuacao;
}TipoTime;

int main()
{
    FILE *arquivo;
    TipoTime time;
    int op;

    arquivo = fopen("times.dat", "w+b");

    if(arquivo==NULL){
        printf("Falha");
        return 1;
    }

    do{
        printf("Informe 1 para continuar ou 0 para sair: ");
        scanf("%d", &op);
        if (op!=0){
            getchar();
            printf("Informe o nome do time: ");
            fgets(time.nome, 50, stdin);
            time.nome[strlen(time.nome)-1] = '\0';
            printf("Informe a pontuacao do time: ");
            scanf("%d", &time.pontuacao);
            fseek(arquivo, 0, SEEK_END);
            fwrite(&time, sizeof(TipoTime), 1, arquivo);
        }
    } while (op!=0);

    fseek(arquivo, 0, SEEK_SET);

    printf("\n\nDados: \n");
    while(feof(arquivo)==0){
        fread(&time, sizeof(TipoTime), 1, arquivo);
        if(feof(arquivo)==0){
            printf("Nome: %s - Pontuacao: %d\n", time.nome, time.pontuacao);
        }
    }

    fclose(arquivo);

    return 0;
}
