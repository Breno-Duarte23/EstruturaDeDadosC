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
            novo->ant = aux;
            apontador temp = novo-> prox;
            temp-> ant = novo;
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
        apontador aux = buscar(*lista, id);
        apontador anterior = aux->ant;
        apontador prox = aux->prox;
        anterior->prox = aux->prox;

        if(prox != NULL){
            prox->ant = aux->ant;
        }

        free(aux);
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

        ant1 = aux1->ant;
        ant2 = aux2->ant;

        aux = aux2->prox;

        ant1->prox = aux2;
        aux2->prox = aux1->prox;
        ant2->prox = aux1;
        aux1->prox = aux;

        if(aux!=NULL){
            aux->ant = aux1;
        } else{
            lista->ultimo = aux1;
        }

        aux1->ant = ant2;

        ant2->ant = aux2;

        apontador temp = ant2->ant;
        temp->ant = aux2;

        aux2->ant = ant1;
    }
}

int main()
{
    TipoLista lista;
    TipoItem item;

    criar(&lista);

    item.id = 1;
    inserirFinal(&lista, item);

    item.id = 2;
    inserirFinal(&lista, item);

    item.id = 3;
    inserirFinal(&lista, item);

    item.id = 4;
    inserirFinal(&lista, item);

    //item.id = 5;
    //inserirFinal(&lista, item);

    printf("Primeira impressao: \n");
    imprimir(lista);

    //item.id = 6;
    //inserirDepois(&lista, item, 5);

    trocar(&lista, 2, 4);

    //remover(&lista, 5);

    printf("\n\nSegunda impressao: \n");
    imprimir(lista);
    //imprimirDecrescente(lista);
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





