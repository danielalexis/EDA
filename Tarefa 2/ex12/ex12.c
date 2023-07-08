#include <stdio.h>

typedef struct {
    int numCC;
    int dataNasc[3];
    float altura;
    int peso;
} Pessoa;

void main() {
    FILE *filePessoas;
    Pessoa pessoa, pessoas[100];
    int count = 0;
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
        printf("\n");    }
    
    fclose(filePessoas);
    return;
}

