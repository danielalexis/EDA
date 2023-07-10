#include <stdio.h>
#include <string.h>

typedef struct {
    int BI;
    char nome[100];
    float altura;
    int peso;
} Aluno;

void main() {
    FILE *fileOriginal, *fileBinario;
    char letra;
    Aluno aluno;
    Aluno alunoMaxPeso;
    int maxPeso = 0;

    fileOriginal = fopen("dados2.txt", "r");
    if (fileOriginal == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return; 
    }

    fileBinario = fopen("dados2.bin", "wb");
    if (fileBinario == NULL) {
        printf("Erro ao criar o ficheiro.\n");
        return;
    }

    while (fscanf(fileOriginal, "%d\n", &aluno.BI) != EOF) {
        fgets(aluno.nome, sizeof(aluno.nome), fileOriginal);
        aluno.nome[strcspn(aluno.nome, "\n")] = '\0'; 
        fscanf(fileOriginal, "%f\n", &aluno.altura);
        fscanf(fileOriginal, "%d\n", &aluno.peso);

        fwrite(&aluno, sizeof(Aluno), 1, fileBinario);

        if (aluno.peso > maxPeso) {
            maxPeso = aluno.peso;
            alunoMaxPeso = aluno;
        }
    }

    fclose(fileOriginal);
    fclose(fileBinario);

    fileBinario = fopen("dados2.bin", "rb");
    if (fileBinario == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    printf("Conteúdo do ficheiro binário:\n");
    while (fread(&aluno, sizeof(Aluno), 1, fileBinario) == 1) {
        printf("BI: %d\n", aluno.BI);
        printf("Nome: %s\n", aluno.nome);
        printf("Altura: %.2f\n", aluno.altura);
        printf("Peso: %d\n\n", aluno.peso);
    }

    fclose(fileBinario);
    printf("Insira uma letra: ");
    scanf(" %c", &letra);

    char nomeFicheiro[15];
    snprintf(nomeFicheiro, sizeof(nomeFicheiro), "%c_inicial.bin", letra);

    fileBinario = fopen(nomeFicheiro, "wb");
    if (fileBinario == NULL) {
        printf("Erro ao criar o ficheiro.\n");
        return;
    }

    fileOriginal = fopen("dados2.bin", "rb");
    if (fileOriginal == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    while (fread(&aluno, sizeof(Aluno), 1, fileOriginal) == 1) {
        if (aluno.nome[0] == letra) {
            fwrite(&aluno, sizeof(Aluno), 1, fileBinario);
        }
    }

    fclose(fileOriginal);
    fclose(fileBinario);

    printf("Aluno com o peso mais elevado:\n");
    printf("Nome: %s\n", alunoMaxPeso.nome);

    fileBinario = fopen("dados2.bin", "ab");
    if (fileBinario == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    printf("\nAdicionar um novo registo:\n");
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

    return;
}
