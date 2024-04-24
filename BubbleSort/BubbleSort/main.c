#include <stdio.h>
#include <stdlib.h>

/*
void bubbleSort(int v[], int n){
    int i, j, x;
    for (i=0; i<n-1; i++){
		for (j=0; j<n-1; j++){
            if (v[j] > v[j+1]){
                x = v[j];
                v[j] = v[j+1];
                v[j+1] = x;
		    }
        }
	}
}
*/


/*
void bubbleSort(int v[], int n){
    int i, j, x;
    for (i=0; i<n-1-i; i++){
		for (j=0; j<n-1; j++){
            if (v[j] > v[j+1]){
                x = v[j];
                v[j] = v[j+1];
                v[j+1] = x;
		    }
        }
	}
}
*/




void bubbleSort(int v[], int n){
    int i, j, x, contTrocas;
    for (i=0; i<n-1-i; i++){
        contTrocas = 0;
		for (j=0; j<n-1; j++){
            if (v[j] > v[j+1]){
                x = v[j];
                v[j] = v[j+1];
                v[j+1] = x;
                contTrocas++;
		    }
        }
        if(contTrocas == 0){
            break;
        }
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

    bubbleSort(v, tamanho);

    printf("\n\nVetor Ordenado: \n");
    imprimir(v, tamanho);

    return 0;
}
