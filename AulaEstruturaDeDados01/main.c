#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define tam 5

typedef struct{
    int id;
    char nome[30];
}TipoItem;

typedef struct{
    int inicio;
    int fim;
    TipoItem itens[tam];
}TipoLista;

void criarLista(TipoLista *lista){
    lista->inicio = 0;
    lista->fim = 0;
}

int vazia(TipoLista lista){
    if(lista.inicio == lista.fim)
        return 1;
    else
        return 0;
}

int cheia(TipoLista lista){
    if(lista.fim >= tam)
        return 1;
    else
        return 0;
}

void inserirFinal(TipoLista *lista, TipoItem item){
    if(cheia(*lista)==1){
        printf("Lista cheia");
    }else{
        lista->itens[lista->fim] = item;
        lista->fim++;
    }
}

int buscar(TipoLista lista, int id){
    int i;
    for(i=0; i < lista.fim; i++){
        if(lista.itens[i].id == id){
           return i;
        }
    }
    return -1;
}


int remover(TipoLista *lista, int id){
    int i, pos;
    pos = buscar(*lista, id);
    if(pos==-1){
        return 0;
    }else{
        for(i=pos; i < lista->fim; i++){
            lista->itens[i] = lista->itens[i+1];
        }
        lista->fim--;
        return 1;
    }
}

void imprimir(TipoLista lista){
    int i;
    if(vazia(lista)==1){
        printf("Lista vazia!!!");
    }else{
        for(i=0; i<lista.fim; i++){
            printf("ID: [%d]", lista.itens[i].id);
            printf(" - Nome: %s", lista.itens[i].nome);
            printf("\n");
        }
    }
}

int trocar(TipoLista *lista, int id1, int id2){
    int pos_id1, pos_id2;
    TipoItem aux;
    pos_id1 = buscar(*lista, id1);
    pos_id2 = buscar(*lista, id2);
    if((pos_id1==-1) || (pos_id2 == -1)){
        return 0;
    }else{
        aux = lista->itens[pos_id2];
        lista->itens[pos_id2] = lista->itens[pos_id1];
        lista->itens[pos_id1] = aux;
        return 1;
    }
}

int editar(TipoLista *lista, int id){
    char nome[30];
    int tamanho;
    int pos_item = buscar(*lista, id);
    if(pos_item==-1){
        return 0;
    }else{
        printf("Informe o novo nome: ");
        fgets(lista->itens[pos_item].nome, 30, stdin);
        tamanho = strlen(lista->itens[pos_item].nome);
        lista->itens[pos_item].nome[tamanho-1] = '\0';
        return 1;
    }
}

 void imprimirItem(TipoLista lista, int id){
    int pos_item = buscar(lista, id);
    if(pos_item != -1){
        printf("[%d] ", lista.itens[pos_item].id);
        printf("%s", lista.itens[pos_item].nome);
    }
}

void zerarLista(TipoLista *lista){
    criarLista(lista);
}

int main(){

    TipoLista lista;
    TipoItem item;

    criarLista(&lista);

    item.id = 1;
    strcpy(item.nome, "Joao");
    inserirFinal(&lista, item);

    item.id = 2;
    strcpy(item.nome, "Robson");
    inserirFinal(&lista, item);

    item.id = 3;
    strcpy(item.nome, "Leandro");
    inserirFinal(&lista, item);

    item.id = 4;
    strcpy(item.nome, "Breno");
    inserirFinal(&lista, item);

    item.id = 5;
    strcpy(item.nome, "Guilherme");
    inserirFinal(&lista, item);

    imprimir(lista);

    if(trocar(&lista, 1, 3) == 1){
        printf("Troca de elementos realizada com sucesso!\n");
    }else{
        printf("ERRO ao trocar os elementos.\n");
    }

    imprimir(lista);


    zerarLista(&lista);
    imprimir(lista);

    //remover(&lista, 3);

    //imprimir(lista);


    return 0;
}


