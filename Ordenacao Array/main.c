#include <stdio.h>
#include <stdlib.h>

void breno(int vetor[], int tamanho){

    for(int i = 0; i < tamanho; i++)
    {
        for(int j = i; j < tamanho; j++)
        {
            if(vetor[i] > vetor[j])
            {
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}


void imprimirVetor(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("{%d}", vetor[i]);
    }
}

void preencherVetor(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % 100;
    }
}

int main()
{
    int vetor[10];
    int tamanho =  sizeof(vetor) / sizeof(vetor[0]);
    int aux;

    preencherVetor(vetor, tamanho);
    printf("Vetor antes da ordenacao: \n");
    imprimirVetor(vetor, tamanho);

    breno(vetor, tamanho);
    printf("\nVetor depois da ordenacao: \n");
    imprimirVetor(vetor, tamanho);
    return 0;
}
