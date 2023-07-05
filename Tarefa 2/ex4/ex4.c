#include <stdio.h>

void main() {
    FILE *file;
    int numero;
    int maior = 0;
    int menor = 0;

    file = fopen("Inteiros.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    while (fscanf(file, "%d", &numero) != EOF) {
        if (numero > maior) {
            maior = numero;
        } else if (numero < menor) {
            menor = numero;
        }
    }

    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);

    fclose(file);

    file = fopen("Saida1.txt", "w");
    fprintf(file, "Maior: %d\n", maior);
    fprintf(file, "Menor: %d\n", menor);
    fclose(file);

    return;
}