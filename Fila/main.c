#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
}TipoItem;

typedef struct celula *apontador;

typedef struct celula{
    TipoItem item;
    apontador *prox;
}celula;

typedef struct{
    apontador primeiro;
}TipoFila;

void criar(TipoFila *fila){
    fila->primeiro = (apontador) malloc(sizeof(celula));
    fila->primeiro->prox = NULL;
}

int vazia(TipoFila fila){
    if(fila.primeiro->prox == NULL)
        return 1;
    return 0;
}

void enfileirar(TipoFila *fila, TipoItem item){
    apontador aux = fila->primeiro->prox;

    if(buscar(*fila, item.id)==0){
        while(aux != NULL){
            fila->primeiro->prox = (apontador) malloc(sizeof(celula));
            aux = aux->prox;

        }
    }
}

void imprimir(TipoFila fila){
    if(vazia(fila)==1){
        printf("A fila esta vazia!!!");
    }else{
        apontador aux = fila.primeiro->prox;
        while(aux!=NULL){
            printf("[%d] ", aux->item.id);
            aux = aux->prox;
        }
    }
}
/*
void remover(TipoLista *lista, int id){
    if(vazia(*lista)==1){
        printf("A lista esta vazia!");
    }else{
        apontador anterior, atual;
        anterior = lista->primeiro;
        atual = lista->primeiro->prox;
        while(atual!=NULL){
            if(atual->item.id == id){
                anterior->prox = atual->prox;
                free(atual);
                break;
            }
            anterior = atual;
            atual = atual->prox;
        }
    }
}
*/
int buscar(TipoFila fila, int id){
    apontador aux;
    aux = fila.primeiro->prox;
    while(aux!=NULL){
        if(aux->item.id == id)
            return aux;
        aux = aux->prox;
    }
    return 0;
}
/*
void trocar(TipoLista *lista, int id1, int id2){
    if((buscar(*lista, id1)!=0) && (buscar(*lista, id2)!=0)){
        apontador ant1, aux1, ant2, aux2, aux;
        aux1 = buscar(*lista, id1);
        aux2 = buscar(*lista, id2);
        ant1 = buscarAnterior(*lista, id1);
        ant2 = buscarAnterior(*lista, id2);

        aux = aux2->prox;
        ant1->prox = aux2;
        aux2->prox = aux1->prox;
        ant2->prox = aux1;
        aux1->prox = aux;
    }
}

int buscarAnterior(TipoLista lista, int id){
    apontador aux, ant;
    ant = lista.primeiro;
    aux = lista.primeiro->prox;
    while(aux!=NULL){
        if(aux->item.id == id)
            return ant;
        ant = aux;
        aux = aux->prox;
    }
    return 0;
}
*/
int main()
{
    TipoFila fila;
    TipoItem item;

    criar(&fila);

    item.id = 1;
    enfileirar(&fila, item);

    item.id = 2;
    enfileirar(&fila, item);

    item.id = 3;
    enfileirar(&fila, item);

    item.id = 4;
    enfileirar(&fila, item);

    item.id = 5;
    enfileirar(&fila, item);

    if(vazia(fila)){
        printf("a lista está vazia");
    } else{
        printf("a lista não está vazia");
    }

    //item.id = 6;
    //inserirDepois(&lista, item, 5);

    //trocar(&lista, 2, 4);

    //remover(&lista, 3);

    //printf("\n\nSegunda impressao: \n");
    //imprimir(lista);

    //printf("\n");

    /*
    if(buscar(lista, 2)!=0){
        printf("O ID 2 esta na lista");
    }else{
        printf("O ID 2 NAO esta na lista");
    }
    */

    return 0;
}




