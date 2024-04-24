#include <stdio.h>
#include <stdlib.h>

void insertionSort(int v[], int n){
    int i, j, valorAtual;

    for(i=1; i<n; i++){
        valorAtual = v[i];
        j = i - 1;
        while((j >= 0) && (valorAtual < v[j])){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = valorAtual;
    }
}

void aleatorio(int v[], int n, int max){
    int i;
    for(i=0; i<n; i++){
        v[i] = rand()%max;
    }
}

void imprimir(int v[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("[%d] ", v[i]);
    }
}

int main(){

    srand(time(NULL));
    int tamanho = 5, max = tamanho * 5;
    int v[tamanho],i;

    aleatorio(v, tamanho, max);

    printf("Vetor Desordenado:\n");
    imprimir(v, tamanho);

    insertionSort(v, tamanho);

    printf("\n\nVetor Ordenado: \n");

    imprimir(v, tamanho);

    return 0;
}
