#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    int id;
}TipoItem;

typedef struct celula *apontador;

typedef struct celula{
    TipoItem item;
    apontador prox;
}celula;

typedef struct{
    apontador primeiro;
}TipoFila;

typedef struct{
    TipoFila filaNormal;
    TipoFila filaPrioritaria;
    int contadorPrioritaria;
}Filas;

void criarFila(TipoFila *fila){
    fila->primeiro = (apontador) malloc(sizeof(celula));
    fila->primeiro->prox = NULL;
}

void enfileirar(TipoFila *fila, TipoItem item){
    apontador aux = fila->primeiro;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = (apontador) malloc(sizeof(celula));
    aux = aux->prox;
    aux->item = item;
    aux->prox = NULL;
}

void enfileirarNormal(Filas *filas, TipoItem item){
    enfileirar(&filas->filaNormal, item);
}

void imprimir(Filas filas){
    printf("************************************************************\n");
    printf("\nFila Normal: ");
    if (filas.filaNormal.primeiro->prox == NULL)
        printf("vazia");
    else {
        apontador aux = filas.filaNormal.primeiro->prox;
        while(aux!=NULL){
            printf("[%d] ", aux->item.id);
            aux = aux->prox;
        }
    }
    printf("\n");
    printf("************************************************************\n");
    printf("\nFila Prioritaria: ");
    if (filas.filaPrioritaria.primeiro->prox == NULL)
        printf("vazia");
    else {
        apontador aux = filas.filaPrioritaria.primeiro->prox;
        while(aux!=NULL){
            printf("[%d] ", aux->item.id);
            aux = aux->prox;
        }
    }
    printf("\n");
}

void enfileirarPreferencial(Filas *filas, TipoItem item){
    enfileirar(&filas->filaPrioritaria, item);
    filas->contadorPrioritaria++;
}

void desenfileirar(Filas *filas){
    if (filas->contadorPrioritaria > 0) {
        printf("\nDesenfileirando da fila prioritaria.\n\n");
        filas->contadorPrioritaria--;
        if (filas->filaPrioritaria.primeiro->prox != NULL) {
            apontador aux = filas->filaPrioritaria.primeiro->prox;
            filas->filaPrioritaria.primeiro->prox = aux->prox;
            free(aux);
            return;
        }
    }

    if (filas->filaNormal.primeiro->prox != NULL) {
        printf("\nDesenfileirando da fila normal.\n\n");
        apontador aux = filas->filaNormal.primeiro->prox;
        filas->filaNormal.primeiro->prox = aux->prox;
        free(aux);
    } else {
        printf("\nAs filas estão vazias.\n");
    }
}


int main()
{
    setlocale(LC_ALL, "Portuguese");
    Filas filas;
    criarFila(&filas.filaNormal);
    criarFila(&filas.filaPrioritaria);
    filas.contadorPrioritaria = 0;

    TipoItem item;
    int senha = 1;

    int escolha = 0;
    do {

        printf("************************************************************\n");
        printf("O que deseja fazer? \n");
        printf("1- Enfileirar na fila normal:  \n");
        printf("2- Enfileirar na fila prioritária: \n");
        printf("3- Desenfileirar \n");
        printf("4- Imprimir as filas: \n");
        printf("5- Sair: \n");
        printf("************************************************************\n");
        scanf("%d", &escolha);


        switch(escolha)
        {
            case 1:
                item.id = senha++;
                enfileirarNormal(&filas, item);
                printf("Enfileirado normal\n");
                break;
            case 2:
                item.id = senha++;
                enfileirarPreferencial(&filas, item);
                printf("Enfileirado Prioritaria\n");
                break;
            case 3:
                desenfileirar(&filas);
                break;
            case 4:
                imprimir(filas);
                break;
            case 5:
                printf("\nObrigado por utilizar nosso sistema!");
                break;
            default:
                printf("\n\n");
                printf("*****************\n");
                printf("*Opção inválida!*\n");
                printf("*****************\n\n");
                break;
        }

    } while(escolha != 5);

    return 0;
}





