#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    char endereco[50];
} Pessoa;

void main() {
    Pessoa p;
    printf("Digite o nome: ");
    scanf("%s", p.nome);
    printf("Digite a idade: ");
    scanf("%d", &p.idade);
    getchar();
    printf("Digite o endereco: ");
    gets(p.endereco);
    printf("Nome: %s\nIdade: %d\nEndereco: %s\n", p.nome, p.idade, p.endereco);
}