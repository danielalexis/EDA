#include <stdio.h>
#include <stdlib.h>

typedef struct produto {
    int codigo;
    float preco;
    int quantidade;
    struct produto *prox;
} Produto;



void main() {
    Produto *lista = NULL;
    for (int i = 0; i < 5; i++) {
        int codigo, quantidade;
        float preco;
        printf("Codigo do produto: ");
        scanf("%d", &codigo);
        printf("Preco do produto: ");
        scanf("%f", &preco);
        printf("Quantidade do produto: ");
        scanf("%d", &quantidade);
        
        Produto* novoProduto = (Produto*)malloc(sizeof(Produto));
        novoProduto->codigo = codigo;
        novoProduto->preco = preco;
        novoProduto->quantidade = quantidade;
        novoProduto->prox = lista;
        lista = novoProduto;
    }

    int desconto, quantidadeProdutos10 = 0;
    printf("Desconto Global: ");
    scanf("%d", &desconto);

    Produto *aux = lista;
    while (aux != NULL) {
        aux->preco = aux->preco * (1 - desconto/100.0);
        printf("Codigo: %d\n", aux->codigo);
        printf("Preco: %.2f\n", aux->preco);
        if (aux->quantidade > 10) {
            quantidadeProdutos10++;
        }
        aux = aux->prox;
    }
    printf("Quantidade de produtos com mais de 10 unidades: %d\n", quantidadeProdutos10);
}