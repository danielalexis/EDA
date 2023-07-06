#include <stdio.h>

typedef struct {
    char nome[50];
    int matricula;
    float notas[3];
} Aluno;

void main() {
    Aluno alunos[5];
    for (int i = 0; i < 5; i++) {
        printf("Nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);
        printf("Matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);
        for (int j = 0; j < 3; j++) {
            printf("Nota %d do aluno %d: ", j + 1, i + 1);
            scanf("%f", &alunos[i].notas[j]);
        }
    }

    printf("\n\n");

    float maiorNota = 0;
    int alunoMaiorNota = 0;
    for (int i = 0; i < 5; i++) {
        if (alunos[i].notas[0] > maiorNota) {
            maiorNota = alunos[i].notas[0];
            alunoMaiorNota = i;
        }
    }
    printf("Maior nota da primeira prova: %.2f\n", maiorNota);

    float maiorMedia = 0;
    int alunoMaiorMedia = 0;
    for (int i = 0; i < 5; i++) {
        float media = 0;
        for (int j = 0; j < 3; j++) {
            media += alunos[i].notas[j];
        }
        media /= 3;
        if (media > maiorMedia) {
            maiorMedia = media;
            alunoMaiorMedia = i;
        }
    }
    printf("Maior media: %.2f\n", maiorMedia);

    float menorMedia = 0;
    int alunoMenorMedia = 0;
    for (int i = 0; i < 5; i++) {
        float media = 0;
        for (int j = 0; j < 3; j++) {
            media += alunos[i].notas[j];
        }
        media /= 3;
        if (media < menorMedia || menorMedia == 0) {
            menorMedia = media;
            alunoMenorMedia = i;
        }
    }
    printf("Menor media: %.2f\n", menorMedia);

    for (int i = 0; i < 5; i++) {
        float media = 0;
        for (int j = 0; j < 3; j++) {
            media += alunos[i].notas[j];
        }
        media /= 3;
        if (media >= 10) {
            printf("Aluno %s aprovado com media %.2f\n", alunos[i].nome, media);
        } else {
            printf("Aluno %s reprovado com media %.2f\n", alunos[i].nome, media);
        }
    }
}