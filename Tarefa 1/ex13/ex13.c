#include <stdio.h>

typedef struct {
    char nome[50];
    int matricula;
    char curso[50];
} Aluno;

void main() {
    Aluno alunos[5];
    for (int i = 0; i < 5; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);
        printf("Digite a matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);
        printf("Digite o curso do aluno %d: ", i + 1);
        scanf("%s", alunos[i].curso);
    }

    for (int i = 0; i < 5; i++) {
        printf("Nome: %s\nMatricula: %d\nCurso: %s\n", alunos[i].nome, alunos[i].matricula, alunos[i].curso);
    }
}