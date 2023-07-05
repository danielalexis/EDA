#include <stdio.h>
#include <stdlib.h>

void main() {
    FILE *file;
    char nome[200];
    int quantidade;
    float preco;
    float total = 0;

    file = fopen("compras.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    while (fscanf(file, "%s %d %f", nome, &quantidade, &preco) != EOF) {
        printf("%s %d %.2f\n", nome, quantidade, preco);
        total += quantidade * preco;
    }
    printf("Total: %.2f\n", total);
}