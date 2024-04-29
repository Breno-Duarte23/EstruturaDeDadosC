#include <stdio.h>
#include <stdlib.h>
void SelectionSort(int a[], int n){
    int i, j, min, aux,t=0;
    unsigned long long int comp = 0, troca = 0;
    for(i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++){
            if(a[j] < a[min]){
                min = j;
                t=1;
            }
            comp++;
        }
        if(t==1){
            troca++;
        }
        t=0;
        aux = a[min];
        a[min] = a[i];
        a[i] = aux;
    }
    printf("\n\nComparacoes:\n{ %ld }\n", comp);
    printf("Trocas:\n{ %ld }\n", troca);
}

void bubbleSort(int v[], int n){
    int i, j, x;
    unsigned long long int contTrocas = 0, comparacao = 0;
    for (i=0; i<n-1; i++){
		for (j=0; j<n-1-i; j++){
            comparacao++;
            if (v[j] > v[j+1]){
                contTrocas++;
                x = v[j];
                v[j] = v[j+1];
                v[j+1] = x;
		    }
		    comparacao++;
        }
        if(contTrocas == 0){
            break;
        }
	}
	printf("\n\nComparacoes:\n{ %ld }\n", comparacao);
    printf("Trocas:\n{ %ld }\n", contTrocas);
}

void insertionSort(int v[], int n){
    int i, j, valorAtual;
    unsigned long long int contTrocas = 0, comparacao = 0;
    for(i=1; i<n; i++){
        valorAtual = v[i];
        j = i - 1;
        comparacao++;
        while((j >= 0) && (valorAtual < v[j])){
            contTrocas++;
            v[j+1] = v[j];
            j--;
            comparacao++;
        }
        v[j+1] = valorAtual;
    }
    printf("\n\nComparacoes:\n{ %ld }\n", comparacao);
    printf("Trocas:\n{ %ld }\n", contTrocas);
}
void aleatorio(int v[], int n, int max){
    int i;
    for(i=0; i<n; i++){
        v[i] = rand()%max;
    }
}

void copiarVetor(int origem[], int destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

void imprimir(int v[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("[%d] ", v[i]);
    }
}
int main()
{
    srand(time(NULL));

    //Preenchendo o Vetor
    int tamanho1k = 1000,i;
    int max = tamanho1k * 5;
    int *vetor1k = (int) malloc(sizeof(int) * tamanho1k);
    aleatorio(vetor1k, tamanho1k, max);

    //Clonando os vetores dos métodos de ordenação
    //Vetores 1k
    int *vetorBubble1k = (int) malloc(sizeof(int) * tamanho1k);
    int *vetorInsertion1k = (int) malloc(sizeof(int) * tamanho1k);
    int *vetorSelection1k = (int) malloc(sizeof(int) * tamanho1k);

    copiarVetor(vetor1k, vetorBubble1k, tamanho1k);
    copiarVetor(vetor1k, vetorInsertion1k, tamanho1k);
    copiarVetor(vetor1k, vetorSelection1k, tamanho1k);

    printf("***Vetores de 1000***");
    printf("\nBubbleSort: ");
    bubbleSort(vetorBubble1k, tamanho1k);

    printf("\nInsertionSort: ");
    insertionSort(vetorInsertion1k, tamanho1k);

    printf("\nSelectionSort: ");
    SelectionSort(vetorSelection1k, tamanho1k);

    //vetores 10k
    printf("\n***Vetores de 10000***\n");
    int tamanho10k = 10000;
    max = tamanho10k * 5;
    int *vetor10k = (int) malloc(sizeof(int) * tamanho10k);
    aleatorio(vetor10k, tamanho10k, max);

    int *vetorBubble10k = (int) malloc(sizeof(int) * tamanho10k);
    int *vetorInsertion10k = (int) malloc(sizeof(int) * tamanho10k);
    int *vetorSelection10k = (int) malloc(sizeof(int) * tamanho10k);

    copiarVetor(vetor10k, vetorBubble10k, tamanho10k);
    copiarVetor(vetor10k, vetorInsertion10k, tamanho10k);
    copiarVetor(vetor10k, vetorSelection10k, tamanho10k);

    printf("\nBubbleSort: ");
    bubbleSort(vetorBubble10k, tamanho10k);

    printf("\nInsertionSort: ");
    insertionSort(vetorInsertion10k, tamanho10k);

    printf("\nSelectionSort: ");
    SelectionSort(vetorSelection10k, tamanho10k);


    //Vetores 100k
    printf("\n***Vetores de 100000***\n");
    int tamanho100k = 100000;
    max = tamanho100k * 5;
    int *vetor100k = (int) malloc(sizeof(int) * tamanho100k);
    aleatorio(vetor100k, tamanho100k, max);

    int *vetorBubble100k = (int) malloc(sizeof(int) * tamanho100k);
    int *vetorInsertion100k = (int) malloc(sizeof(int) * tamanho100k);
    int *vetorSelection100k = (int) malloc(sizeof(int) * tamanho100k);

    copiarVetor(vetor100k, vetorBubble100k, tamanho100k);
    copiarVetor(vetor100k, vetorInsertion100k, tamanho100k);
    copiarVetor(vetor100k, vetorSelection100k, tamanho100k);

    printf("\nBubbleSort: ");
    bubbleSort(vetorBubble100k, tamanho100k);

    printf("\nInsertionSort: ");
    insertionSort(vetorInsertion100k, tamanho100k);

    printf("\nSelectionSort: ");
    SelectionSort(vetorSelection100k, tamanho100k);

    //Vetores 500k

    printf("\n***Vetores de 500000***\n");
    int tamanho500k = 500000;
    max = tamanho500k * 5;
    int *vetor500k = (int) malloc(sizeof(int) * tamanho500k);
    aleatorio(vetor500k, tamanho500k, max);

    int *vetorBubble500k = (int) malloc(sizeof(int) * tamanho500k);
    int *vetorInsertion500k = (int) malloc(sizeof(int) * tamanho500k);
    int *vetorSelection500k = (int) malloc(sizeof(int) * tamanho500k);

    copiarVetor(vetor500k, vetorBubble500k, tamanho500k);
    copiarVetor(vetor500k, vetorInsertion500k, tamanho500k);
    copiarVetor(vetor500k, vetorSelection500k, tamanho500k);

    printf("\nBubbleSort: ");
    bubbleSort(vetorBubble500k, tamanho500k);

    printf("\nInsertionSort: ");
    insertionSort(vetorInsertion500k, tamanho500k);

    printf("\nSelectionSort: ");
    SelectionSort(vetorSelection500k, tamanho500k);
    return 0;
}
