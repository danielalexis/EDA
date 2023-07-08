#include <stdio.h>

typedef struct {
    int numCC;
    int dataNasc[3];
    float altura;
    int peso;
} Pessoa;

void main() {
    FILE *filePessoas;
    FILE *fileDatas;
    Pessoa pessoa, pessoas[100];
    int count = 0;
    int ano, peso;

    filePessoas = fopen("Pessoas.txt", "r");
    if (filePessoas == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    while (fscanf(filePessoas, "%d %d/%d/%d %f %d\n", &pessoa.numCC, &pessoa.dataNasc[0], &pessoa.dataNasc[1], &pessoa.dataNasc[2], &pessoa.altura, &pessoa.peso) != EOF) {
        pessoas[count] = pessoa;
        count++;
    }

    for (int i = 0; i < count; i++) {
        printf("Numero de CC: %d\n", pessoas[i].numCC);
        printf("Data de nascimento: %d/%d/%d\n", pessoas[i].dataNasc[0], pessoas[i].dataNasc[1], pessoas[i].dataNasc[2]);
        printf("Altura: %.2f\n", pessoas[i].altura);
        printf("Peso: %d\n", pessoas[i].peso);
        printf("\n");
    }

    fclose(filePessoas);

    filePessoas = fopen("Pessoas.bin", "wb");
    if (filePessoas == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    fwrite(pessoas, sizeof(Pessoa), count, filePessoas);
    fclose(filePessoas);

    printf("Digite o ano de nascimento: ");
    scanf("%d", &ano);
    printf("Digite o peso mínimo: ");
    scanf("%d", &peso);

    filePessoas = fopen("Pessoas.bin", "rb");
    fileDatas = fopen("Datas.bin", "wb");
    if (filePessoas == NULL || fileDatas == NULL) {
        printf("Erro ao abrir os ficheiros.\n");
        return;
    }

    while (fread(&pessoa, sizeof(Pessoa), 1, filePessoas) == 1) {
        if (pessoa.dataNasc[2] == ano && pessoa.peso > peso) {
            fwrite(&pessoa.numCC, sizeof(int), 1, fileDatas);
            fwrite(&pessoa.peso, sizeof(int), 1, fileDatas);
        }
    }

    fclose(filePessoas);
    fclose(fileDatas);

    fileDatas = fopen("Datas.bin", "rb");
    if (fileDatas == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    printf("Dados do ficheiro Datas.bin:\n");
    while (fread(&pessoa.numCC, sizeof(int), 1, fileDatas) == 1) {
        fread(&pessoa.peso, sizeof(int), 1, fileDatas);
        printf("Numero de CC: %d\n", pessoa.numCC);
        printf("Peso: %d\n", pessoa.peso);
        printf("\n");
    }

    fclose(fileDatas);

    return;
}
