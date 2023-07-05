#include <stdio.h>
#include <string.h>

void main() {
    FILE *file;
    char palavra[50];
    char palavraFile[50];
    int count = 0;

    printf("Insira uma palavra: ");
    scanf("%s", palavra);

    file = fopen("palavras.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    while (fscanf(file, "%s", palavraFile) != EOF) {
        if (strcmp(palavra, palavraFile) == 0) {
            count++;
        }
    }
    printf("A palavra %s aparece %d vezes no ficheiro.\n", palavra, count);
    return;
}