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
    apontador primeiro, ultimo;
}TipoLista;

void criar(TipoLista *lista){
    lista->primeiro = (apontador) malloc(sizeof(celula));
    lista->primeiro->prox = NULL;
    lista->ultimo = lista->primeiro;
}

int vazia(TipoLista lista){
    if(lista.primeiro == lista.ultimo)
        return 1;
    return 0;
}

void inserirFinal(TipoLista *lista, TipoItem item){
    if(buscar(*lista, item.id)==0){
        lista->ultimo->prox = (apontador) malloc(sizeof(celula));
        lista->ultimo = lista->ultimo->prox;
        lista->ultimo->prox = NULL;
        lista->ultimo->item = item;
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
            return 1;
        aux = aux->prox;
    }
    return 0;
}

void inserirPosicao(TipoLista *lista, TipoItem item, int chave){
    apontador anterior, novo;
    anterior = lista->primeiro;

    if(buscar(*lista, chave)== 0){
        printf("Chave nao encontrada na lista.\n");
        return;
    }
    novo = (apontador) malloc(sizeof(celula));
    novo->item = item;
    novo->prox = anterior->prox;
    anterior->prox = novo;
}

void trocarElementos(TipoLista *lista, int chave1, int chave2) {

    if (chave1 == chave2) {
        printf("As chaves fornecidas sao iguais. Nenhuma troca sera feita.\n");
        return;
    }

    apontador ant1, ant2, elem1, elem2;
    ant1 = lista->primeiro;
    ant2 = lista->primeiro;

    while ((buscar(*lista, chave1) != 0) && (ant1->prox->item->id != chave1)){
        ant1 = ant1->prox;
    }
    while ((buscar(*lista, chave1) != 0)&& (ant2->prox->item->id != chave2) ){
        ant2 = ant2->prox;
    }

    if (ant1->prox == NULL || ant2->prox == NULL) {
        printf("Uma ou ambas as chaves nao foram encontradas na lista. Nenhuma troca sera feita.\n");
        return;
    }

    elem1 = ant1->prox;
    elem2 = ant2->prox;

    ant1->prox = elem2;
    ant2->prox = elem1;
    apontador temp = elem2->prox;
    elem2->prox = elem1->prox;
    elem1->prox = temp;

    printf("Troca realizada com sucesso!\n");
}


int main()
{
    TipoLista lista;
    TipoItem item;
    TipoItem novoItem;

    int chaveAntecessor = 0;
    int chave1, chave2;

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

    printf("Primeira impressao: \n");
    imprimir(lista);

    remover(&lista, 3);

    printf("\n\nSegunda impressao: \n");
    imprimir(lista);

    printf("\n");

    if(buscar(lista, 2)==1){
        printf("O ID 2 esta na lista");
    }else{
        printf("O ID 2 NAO esta na lista");
    }

    printf("\nDigite a chave do antecessor e o que sera gravado na chave: ");
    scanf("%d", &chaveAntecessor);
    scanf("%d", &novoItem);

    inserirPosicao(&lista, novoItem, chaveAntecessor);
    imprimir(lista);

    printf("\nDigite as chaves dos elementos que serao trocados: ");
    scanf("%d", &chave1);
    scanf("%d", &chave2);

    trocarElementos(&lista, chave1, chave2);

    imprimir(lista);
    return 0;
}
