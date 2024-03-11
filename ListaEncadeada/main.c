#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[10];
    char endereco[200];
} TipoItem;

typedef struct celula  *apontador;

typedef struct celula{
    TipoItem item;
    apontador prox;
} celula;

typedef struct{
    apontador *primeiro,  *ultimo;
} TipoLista;

void criar(TipoLista *lista){
    lista->primeiro = (apontador*) malloc(sizeof(celula));
    lista->primeiro->prox = NULL;
    lista->ultimo = lista->primeiro;
}

int vazia(TipoLista lista){
    if(lista.primeiro == lista.ultimo)
        return 1;
    return 0;
}

int main()
{
    TipoLista lista;

    criar(&lista);
    if(vazia(lista) == 1)
        printf("A lista esta vazia");
    else
        printf("A lista NAO esta vazia");

    return 0;
}
