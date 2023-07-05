#include <stdio.h>

void main() {
    FILE * file;
    int linha = 0;

    file = fopen("palavras.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    for (int c = fgetc(file); c != EOF; c = fgetc(file)) {
        if (c == '\n') {
            linha++;
        }
    }

    printf("O ficheiro tem %d linhas.\n", linha);

    fclose(file);

}