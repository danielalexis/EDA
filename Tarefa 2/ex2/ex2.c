#include <stdio.h>

void main() {
    FILE *file;
    char nome[50];
    float nota, soma = 0;
    int alunos = 0;

    file = fopen("notas.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    while (fscanf(file, "NOME: %s NOTA: %f", nome, &nota) != EOF) {
        printf("Nome: %s Nota: %.2f\n", nome, nota);
        soma += nota;
        alunos++;
        fgetc(file);
    }

    fclose(file);

    if (alunos > 0) {
        float media = soma / alunos;
        printf("Média das notas: %.2f\n", media);
    } else {
        printf("Nenhuma nota encontrada no ficheiro.\n");
    }

    return;
}
