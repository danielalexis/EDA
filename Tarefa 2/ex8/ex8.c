#include <stdio.h>

void main() {
    FILE *file;
    int num, numMultiplo;

    printf("Introduza um número: ");
    scanf("%d", &num);

    file = fopen("multiplos.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    while (fscanf(file, "%d", &numMultiplo) != EOF) {
        if (numMultiplo % num == 0) {
            printf("%d é múltiplo de %d\n", numMultiplo, num);
        }
    }

    fclose(file);
    return;
}