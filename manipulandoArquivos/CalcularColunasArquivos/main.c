#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arquivo;
    int total = 0;
    char c;

    arquivo = fopen("numeros.txt", "r");

    if(arquivo == NULL){
        printf("Falha ao abrir/criar arquivo!");
    }

    while(feof(arquivo) == 0){
        c = fgetc(arquivo);
        printf("%c", c);
        total += atoi(c);
    }

    printf(total);
    fclose(arquivo);
    return 0;
}
