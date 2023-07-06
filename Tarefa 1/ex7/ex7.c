#include <stdio.h>

void soma(int *a, int *b) {
    *a = *a + *b;
}

void main() {
    int a, b;
    printf("Primeiro Inteiro: ");
    scanf(" %d", &a);
    printf("Segundo Inteiro: ");
    scanf(" %d", &b);
    soma(&a, &b);
    printf("A soma (valor de a) é %d\n", a);
    printf("O valor de b é %d", b);
}

