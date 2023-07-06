#include <stdio.h>

void soma_dobro(int *a, int *b, int *soma) {
    *a *= 2;
    *b *= 2;
    *soma = *a + *b;
}

void main() {
    int a, b, soma;
    printf("Primeiro Inteiro: ");
    scanf(" %d", &a);
    printf("Segundo Inteiro: ");
    scanf(" %d", &b);
    soma_dobro(&a, &b, &soma);
    printf("A soma dos dobro é %d", soma);
}

