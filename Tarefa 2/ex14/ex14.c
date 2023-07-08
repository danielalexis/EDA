#include <stdio.h>
#include <string.h>

typedef struct {
    int BI;
    char nome[100];
    float altura;
    int peso;
} Aluno;

void imprimirAluno(Aluno aluno) {
    printf("BI: %d\n", aluno.BI);
    printf("Nome: %s\n", aluno.nome);
    printf("Altura: %.2f\n", aluno.altura);
    printf("Peso: %d\n\n", aluno.peso);
}

void listarConteudoBinario() {
    FILE *fileBinario;
    Aluno aluno;

    fileBinario = fopen("dados2.bin", "rb");
    if (fileBinario == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    printf("Conteúdo do ficheiro binário:\n");
    while (fread(&aluno, sizeof(Aluno), 1, fileBinario) == 1) {
        imprimirAluno(aluno);
    }

    fclose(fileBinario);
}

void copiarRegistrosPorLetra() {
    FILE *fileBinario, *fileNovo;
    char letra;
    Aluno aluno;
    char nomeFicheiro[15];

    printf("Insira uma letra: ");
    scanf(" %c", &letra); // Espaço antes do %c para consumir o caractere de nova linha pendente

    snprintf(nomeFicheiro, sizeof(nomeFicheiro), "%c_inicial.bin", letra);

    fileBinario = fopen("dados2.bin", "rb");
    if (fileBinario == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    fileNovo = fopen(nomeFicheiro, "wb");
    if (fileNovo == NULL) {
        printf("Erro ao criar o ficheiro.\n");
        return;
    }

    while (fread(&aluno, sizeof(Aluno), 1, fileBinario) == 1) {
        if (aluno.nome[0] == letra) {
            fwrite(&aluno, sizeof(Aluno), 1, fileNovo);
        }
    }

    fclose(fileBinario);
    fclose(fileNovo);

    printf("Registros copiados para o ficheiro %s.\n", nomeFicheiro);
}

void encontrarAlunoMaxPeso() {
    FILE *fileBinario;
    Aluno aluno, alunoMaxPeso;
    int maxPeso = 0;

    fileBinario = fopen("dados2.bin", "rb");
    if (fileBinario == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    while (fread(&aluno, sizeof(Aluno), 1, fileBinario) == 1) {
        if (aluno.peso > maxPeso) {
            maxPeso = aluno.peso;
            alunoMaxPeso = aluno;
        }
    }

    fclose(fileBinario);

    printf("Aluno com o peso mais elevado:\n");
    imprimirAluno(alunoMaxPeso);
}

void adicionarNovoRegistro() {
    FILE *fileBinario;
    Aluno aluno;

    fileBinario = fopen("dados2.bin", "ab");
    if (fileBinario == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    printf("\nAdicionar novo registo:\n");
    printf("BI: ");
    scanf("%d", &aluno.BI);
    printf("Nome: ");
    scanf(" %[^\n]", aluno.nome);
    printf("Altura: ");
    scanf("%f", &aluno.altura);
    printf("Peso: ");
    scanf("%d", &aluno.peso);

    fwrite(&aluno, sizeof(Aluno), 1, fileBinario);

    fclose(fileBinario);

    printf("Novo registo adicionado.\n");
}

int main() {
    int escolha;

    do {
        printf("\nMenu:\n");
        printf("1. Listar conteúdo do ficheiro binário\n");
        printf("2. Copiar registros por letra inicial do nome\n");
        printf("3. Encontrar aluno com maior peso\n");
        printf("4. Adicionar novo registro\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                listarConteudoBinario();
                break;
            case 2:
                copiarRegistrosPorLetra();
                break;
            case 3:
                encontrarAlunoMaxPeso();
                break;
            case 4:
                adicionarNovoRegistro();
                break;
            case 0:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return;
}
