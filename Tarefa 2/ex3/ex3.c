#include <stdio.h>

void main() {
    FILE *file;
    int numero;
    int somaPositivos = 0;
    int somaNegativos = 0;

    file = fopen("Inteiros.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    while (fscanf(file, "%d", &numero) != EOF) {
        if (numero > 0) {
            somaPositivos += numero;
        } else {
            somaNegativos += numero;
        }
    }

    fclose(file);

    printf("Soma dos positivos: %d\n", somaPositivos);
    printf("Soma dos negativos: %d\n", somaNegativos);

    file = fopen("Saida1.txt", "w");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(file, "Soma dos positivos: %d\n", somaPositivos);
    fprintf(file, "Soma dos negativos: %d\n", somaNegativos);
    fclose(file);

}