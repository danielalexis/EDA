#include <stdio.h>
#include <string.h>

typedef struct Produto {
    int codigo;
    char nome[15];
    float preco;
    int quantidade;
} Produto;

void main() {
    // Cria um vetor de produtos
    Produto produtos[5];
    // Cria varios produots
    produtos[0].codigo = 1;
    strcpy(produtos[0].nome, "Arroz");
    produtos[0].preco = 10.0;
    produtos[0].quantidade = 10;

    produtos[1].codigo = 2;
    strcpy(produtos[1].nome, "Feijao");
    produtos[1].preco = 5.0;
    produtos[1].quantidade = 5;

    produtos[2].codigo = 3;
    strcpy(produtos[2].nome, "Macarrao");
    produtos[2].preco = 3.0;
    produtos[2].quantidade = 3;

    produtos[3].codigo = 4;
    strcpy(produtos[3].nome, "Carne");
    produtos[3].preco = 20.0;
    produtos[3].quantidade = 2;

    produtos[4].codigo = 5;
    strcpy(produtos[4].nome, "Frango");
    produtos[4].preco = 15.0;
    produtos[4].quantidade = 1;

    int codigo, quantidade, encontrado = 0;
    while (1)
    {
        printf("Codigo do produto: ");
        scanf("%d", &codigo);
        printf("Quantidade: ");
        scanf("%d", &quantidade);
        if (codigo == 0) {
            break;
        }
        for (int i = 0; i < 5; i++) {
            if (produtos[i].codigo == codigo) {
                encontrado = 1;
                if (produtos[i].quantidade >= quantidade) {
                    printf("Nome: %s\n", produtos[i].nome);
                    printf("Preco: %.2f\n", produtos[i].preco);
                    printf("Total: %.2f\n", produtos[i].preco * quantidade);
                    produtos[i].quantidade -= quantidade;
                    printf("Quantidade restante: %d\n", produtos[i].quantidade);
                } else {
                    printf("Quantidade insuficiente\n");
                }
            }
        }
        if (!encontrado) {
            printf("Produto nao encontrado\n");
        }
        encontrado = 0;
    }
    

}