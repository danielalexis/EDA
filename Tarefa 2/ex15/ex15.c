#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 50
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    float nota;
} Aluno;

typedef struct {
    Aluno alunos[MAX_ALUNOS];
    int numAlunos;
    char nomeTurma[MAX_NOME];
} Turma;

void definirInformacoes(Turma *turma) {
    printf("Digite o nome da turma: ");
    fgets(turma->nomeTurma, MAX_NOME, stdin);
    turma->nomeTurma[strcspn(turma->nomeTurma, "\n")] = '\0';
}

void inserirAluno(Turma *turma) {
    if (turma->numAlunos == MAX_ALUNOS) {
        printf("Limite de alunos atingido.\n");
        return;
    }

    Aluno novoAluno;

    printf("Digite o nome do aluno: ");
    fgets(novoAluno.nome, MAX_NOME, stdin);
    novoAluno.nome[strcspn(novoAluno.nome, "\n")] = '\0';

    printf("Digite a nota do aluno: ");
    scanf("%f", &novoAluno.nota);

    getchar();

    turma->alunos[turma->numAlunos] = novoAluno;
    turma->numAlunos++;
}

void exibirAlunosMedias(const Turma *turma) {
    printf("Alunos e suas medias:\n", 130, 130);

    for (int i = 0; i < turma->numAlunos; i++) {
        printf("Aluno: %s\n", turma->alunos[i].nome);
        printf("Media: %.2f\n\n", turma->alunos[i].nota);
    }
}

void exibirAlunosAprovados(const Turma *turma) {
    printf("Alunos aprovados:\n");

    for (int i = 0; i < turma->numAlunos; i++) {
        if (turma->alunos[i].nota >= 6.0) {
            printf("%s\n", turma->alunos[i].nome);
        }
    }
}

void exibirAlunosReprovados(const Turma *turma) {
    printf("Alunos reprovados:\n");

    for (int i = 0; i < turma->numAlunos; i++) {
        if (turma->alunos[i].nota < 6.0) {
            printf("%s\n", turma->alunos[i].nome);
        }
    }
}

void salvarDadosEmDisco(const Turma *turma) {
    FILE *arquivo;

    arquivo = fopen("notas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Nome da turma: %s\n\n", turma->nomeTurma);
    fprintf(arquivo, "Alunos e suas medias:\n");

    for (int i = 0; i < turma->numAlunos; i++) {
        fprintf(arquivo, "Aluno: %s\n", turma->alunos[i].nome);
        fprintf(arquivo, "Media: %.2f\n\n", turma->alunos[i].nota);
    }

    fclose(arquivo);

    printf("Dados salvos com sucesso.\n");
}

void main() {
    Turma turma;
    char opcao;

    turma.numAlunos = 0;

    do {
        printf("Menu:\n");
        printf("(a) Definir informaçoes da turma\n");
        printf("(b) Inserir aluno e notas\n");
        printf("(c) Exibir alunos e médias\n");
        printf("(d) Exibir alunos aprovados\n");
        printf("(e) Exibir alunos reprovados\n");
        printf("(f) Salvar dados em disco\n");
        printf("(g) Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%c", &opcao);

        getchar();

        switch (opcao) {
            case 'a':
                definirInformacoes(&turma);
                break;
            case 'b':
                inserirAluno(&turma);
                break;
            case 'c':
                exibirAlunosMedias(&turma);
                break;
            case 'd':
                exibirAlunosAprovados(&turma);
                break;
            case 'e':
                exibirAlunosReprovados(&turma);
                break;
            case 'f':
                salvarDadosEmDisco(&turma);
                break;
            case 'g':
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != 'g');

    return;
}
