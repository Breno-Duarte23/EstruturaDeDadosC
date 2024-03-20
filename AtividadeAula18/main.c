#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
}TipoItem;

typedef struct celula *apontador;

typedef struct celula{
    TipoItem item;
    apontador *prox;
    apontador *ant;
}celula;

typedef struct{
    apontador primeiro, ultimo;
}TipoLista;

void criar(TipoLista *lista){
    lista->primeiro = (apontador) malloc(sizeof(celula));
    lista->primeiro->prox = NULL;
    lista->primeiro->ant = NULL;
    lista->ultimo = lista->primeiro;
}

int vazia(TipoLista lista){
    if(lista.primeiro == lista.ultimo)
        return 1;
    return 0;
}

void inserirFinal(TipoLista *lista, TipoItem item){
    if(buscar(*lista, item.id)==0){
        apontador novo = (apontador) malloc(sizeof(celula));
        lista->ultimo->prox = novo;
        novo->ant = lista->ultimo;
        novo->prox = NULL;
        lista->ultimo = novo;
        lista->ultimo->item = item;
    }
}

void inserirDepois(TipoLista *lista, TipoItem item, int antecessor){
    apontador aux = buscar(*lista, antecessor);
    if (aux!=0){
        if(buscar(*lista, item.id)==0){
            apontador novo = (apontador) malloc(sizeof(celula));
            novo->item = item;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
}

void imprimir(TipoLista lista){
    if(vazia(lista)==1){
        printf("A lista esta vazia!!!");
    }else{
        apontador aux = lista.primeiro->prox;
        while(aux!=NULL){
            printf("[%d] ", aux->item.id);
            aux = aux->prox;
        }
    }
}

void imprimirDecrescente(TipoLista lista){
    if(vazia(lista)==1){
        printf("A lista esta vazia!!!");
    }else{
        apontador aux = lista.ultimo;
        while(aux != lista.primeiro){
            printf("[%d] ", aux->item.id);
            aux = aux->ant;
        }
    }
}

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

int buscar(TipoLista lista, int id){
    apontador aux;
    aux = lista.primeiro->prox;
    while(aux!=NULL){
        if(aux->item.id == id)
            return aux;
        aux = aux->prox;
    }
    return 0;
}

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

int main()
{
    TipoLista lista;
    TipoItem item;

    criar(&lista);

    item.id = 1;
    inserirFinal(&lista, item);

    item.id = 1;
    inserirFinal(&lista, item);

    item.id = 1;
    inserirFinal(&lista, item);

    item.id = 2;
    inserirFinal(&lista, item);

    item.id = 3;
    inserirFinal(&lista, item);

    item.id = 4;
    inserirFinal(&lista, item);

    item.id = 5;
    inserirFinal(&lista, item);

    printf("Primeira impressao: \n");
    imprimir(lista);

    //item.id = 6;
    //inserirDepois(&lista, item, 5);

    //trocar(&lista, 2, 4);

    //remover(&lista, 3);

    printf("\n\nSegunda impressao: \n");
    //imprimir(lista);
    imprimirDecrescente(lista);
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





