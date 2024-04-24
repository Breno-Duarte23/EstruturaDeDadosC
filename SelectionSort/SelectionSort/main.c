#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SelectionSort(int a[], int n){
    int i, j, min, aux;
    for(i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        aux = a[min];
        a[min] = a[i];
        a[i] = aux;
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
    int tamanho = 10, max = tamanho * 5;
    int v[tamanho],i;

    aleatorio(v, tamanho, max);

    printf("Vetor Desordenado:\n");
    imprimir(v, tamanho);

    SelectionSort(v, tamanho);

    printf("\n\nVetor Ordenado: \n");

    imprimir(v, tamanho);

    return 0;
}
