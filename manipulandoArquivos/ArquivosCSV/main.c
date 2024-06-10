#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void extract_and_write_columns(FILE *input_file, FILE *output_file, int columns[], int num_columns) {
    char line[MAX_LINE_LENGTH];
    char *token;
    int current_column;

    while (fgets(line, sizeof(line), input_file)) {
        current_column = 0;
        int column_index = 0;
        int first = 1;

        line[strcspn(line, "\n")] = '\0';
        printf("Linha original: %s\n", line);

        token = strtok(line, ";;");
        while (token != NULL) {
            if (current_column == columns[column_index] || current_column == 15 || current_column == 16) {
                if (!first) {
                    fprintf(output_file, ";");
                }
                fprintf(output_file, "%s", token);
                first = 0;
                column_index++;

                if (column_index >= num_columns) {
                    break;
                }
            }
            printf("Coluna atual: %d, Token: %s\n", current_column, token);
            token = strtok(NULL, ";");
            current_column++;
        }
        fprintf(output_file, "\n");
    }
}

int main() {
    FILE *input_file = fopen("municipios_csv.csv", "r");
    if (input_file == NULL) {
        perror("Não foi possível abrir o arquivo de entrada");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen("filtrado_municipios_csv.csv", "w");
    if (output_file == NULL) {
        perror("Não foi possível abrir o arquivo de saída");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    char header_line[MAX_LINE_LENGTH];
    fgets(header_line, sizeof(header_line), input_file);
    header_line[strcspn(header_line, "\n")] = '\0';

    char *header_token;
    int column_index = 0;
    int cod_municipio_index = -1, uf_index = -1, nome_index = -1, populacao_21_index = -1;

    header_token = strtok(header_line, ";");
    while (header_token != NULL) {
        printf("Header token: %s\n", header_token);
        if (strcmp(header_token, "municipio") == 0) {
            cod_municipio_index = column_index;
        } else if (strcmp(header_token, "uf_code") == 0) {
            uf_index = column_index;
        } else if (strcmp(header_token, "name") == 0) {
            nome_index = column_index;
        } else if (strcmp(header_token, "pop_21") == 0) {
            populacao_21_index = column_index;
        }
        column_index++;
        header_token = strtok(NULL, ";");
    }

    printf("Indices das colunas: municipio=%d, uf_code=%d, name=%d, pop_21=%d\n", cod_municipio_index, uf_index, nome_index, populacao_21_index);  // Linha de debug

    if (cod_municipio_index == -1 || uf_index == -1 || nome_index == -1 || populacao_21_index == -1) {
        fprintf(stderr, "Uma ou mais colunas não foram encontradas no cabeçalho\n");
        fclose(input_file);
        fclose(output_file);
        return EXIT_FAILURE;
    }

    int columns_to_extract[] = {cod_municipio_index, uf_index, nome_index, populacao_21_index};
    int num_columns = sizeof(columns_to_extract) / sizeof(columns_to_extract[0]);

    fprintf(output_file, "cod_municipio;uf_code;name;pop_21;\n");

    extract_and_write_columns(input_file, output_file, columns_to_extract, num_columns);
    printf("%Numero de colunas %d", num_columns);
    fclose(input_file);
    fclose(output_file);
    return EXIT_SUCCESS;
}
