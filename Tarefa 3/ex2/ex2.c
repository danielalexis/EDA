#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario {
    char nome[50];
    float salario;
    struct funcionario *prox;
} Funcionario;

void main() {
    Funcionario *lista = NULL;
    for (int i = 0; i < 8; i++) {
        char nome[50];
        float salario;
        printf("Nome do funcionario: ");
        scanf("%s", nome);
        printf("Salario do funcionario: ");
        scanf("%f", &salario);

        Funcionario *novoFuncionario = (Funcionario*)malloc(sizeof(Funcionario));
        strcpy(novoFuncionario->nome, nome);
        novoFuncionario->salario = salario;
        novoFuncionario->prox = lista;
        lista = novoFuncionario;
    }

    Funcionario *aux = lista;
    while (aux != NULL) {
        Funcionario *aux2 = aux->prox;
        while (aux2 != NULL) {
            if (aux2->salario > aux->salario) {
                char nomeAux[50];
                strcpy(nomeAux, aux->nome);
                float salarioAux = aux->salario;

                strcpy(aux->nome, aux2->nome);
                aux->salario = aux2->salario;

                strcpy(aux2->nome, nomeAux);
                aux2->salario = salarioAux;
            }
            aux2 = aux2->prox;
        }
        aux = aux->prox;
    }

    float salarioMaiorQue;
    printf("Salario maior que: ");
    scanf("%f", &salarioMaiorQue);

    // Média dos salários
    aux = lista;
    float somaSalarios = 0;
    int quantidadeFuncionarios = 0;
    while (aux != NULL) {
        somaSalarios += aux->salario;
        quantidadeFuncionarios++;
        aux = aux->prox;
    }
    printf("Media dos salarios: %.2f\n", somaSalarios/quantidadeFuncionarios);

    // Quantidade de funcionários com salário maior que X
    aux = lista;
    int quantidade = 0;
    while (aux != NULL) {
        if (aux->salario > salarioMaiorQue) {
            quantidade++;
        }
        aux = aux->prox;
    }
    printf("Quantidade de funcionarios com salario maior que %.2f: %d\n", salarioMaiorQue, quantidade);
}