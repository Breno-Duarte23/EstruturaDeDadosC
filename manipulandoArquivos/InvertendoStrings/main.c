#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arquivo;
    FILE *arquivo1;
    int aux[500], pos = 0, i;
    char c;

    arquivo = fopen("inverter.txt", "r");
    arquivo1 = fopen("invertido.txt", "w");

    if(arquivo==NULL || arquivo1 == NULL){
        printf("Falha ao abrir/criar arquivo!");
        return 1;
    }


    while(feof(arquivo)==0){
        c = fgetc(arquivo);
        printf("%c", c);
        aux[pos] = c;
        pos++;
    }

    for(i = pos - 2; i >= 0; i--){
        fputc(aux[i], arquivo1);
    }

    fclose(arquivo);
    fclose(arquivo1);

    return 0;
}
