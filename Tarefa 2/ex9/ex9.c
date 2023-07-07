#include <stdio.h>

void main() {
    FILE *file;
    FILE *fileSaida;
    int num, numMultiplo;

    printf("Introduza um número: ");
    scanf("%d", &num);

    file = fopen("multiplos.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }
    
    fileSaida = fopen("saida.txt", "w");
    if (fileSaida == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    while (fscanf(file, "%d", &numMultiplo) != EOF) {
        if (numMultiplo % num == 0) {
            printf("%d é múltiplo de %d\n", numMultiplo, num);
            fprintf(fileSaida, "%d é múltiplo de %d\n", numMultiplo, num);
        }
    }

    fclose(file);
    fclose(fileSaida);
    return;
}