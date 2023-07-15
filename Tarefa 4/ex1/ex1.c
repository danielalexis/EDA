#include <stdio.h>
#define TABLE_SIZE 97

int hash(int key) {
  return key % TABLE_SIZE;
}

void main() {
    int key;
    printf("Valor: ");
    scanf("%d", &key);
    printf("O valor %d sera indexado na posicao %d", key, hash(key));
}