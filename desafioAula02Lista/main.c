#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <locale.h>

#define tam 5

typedef struct{
    int id;
    char nome[30];
    double vendasBrutas;
} Vendedor;

typedef struct{
    int inicio;
    int fim;
    Vendedor atr [tam];
} ListaVendedores;

void criarLista(ListaVendedores *lista){
    lista->inicio = 0;
    lista->fim = 0;
}

int vazia(ListaVendedores lista){
    if(lista.inicio == lista.fim )
        return 1;
    else
        return 0;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int escolha;
    Vendedor vendedor;
    ListaVendedores lista;

    do{
        printf("Digite o numero de qual operação você deseja fazer; \n");
        printf("[1] Cadastrar vendedor: \n");
        printf("[2] Alterar vendedor vendedor: \n");
        printf("[3] Excluir vendedor: \n");
        printf("[4] Buscar vendedor: \n");
        printf("[5] Calcular e exibir o salário de um vendedor: \n");
        printf("[6] Calcular e exibir o salário de todos os vendedores: \n");
        printf("[7] Sair: ");
        scanf("%d", &escolha);

        switch(escolha){
            case   1:
                printf("Digite o nome do vendedor, o ID e as vendas brutas: ");
                int id;
                char nome [30];
                double vendasBrutas;
                break;
            case 2:
                printf("Digite o ID do funcionário que será alterado e o novo nome: ");
                break;
            case 3:
                printf("Digite o ID do funcionário que será excluído: ");
                break;
            case 4:
                printf("Digite o ID que deseja buscar: ");
                break;
            case 5:
                printf("Digite o ID do funcionário que deseja calcular o salário: ");
                break;
            case 6:
                printf("Salário de cada vendedor ");
                break;
            case 7:
                escolha = 7;
                break;
            default:
                printf("Digite um valor válido: ");
        }
    } while(escolha != 7 );
    return 0;
}
