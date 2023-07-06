#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main() {
    int a;
    int b;
    printf("Primeiro Inteiro: ");
    scanf(" %d", &a);
    printf("Segundo Inteiro: ");
    scanf(" %d", &b);
    printf("Valores originais:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    trocar(&a, &b);
    printf("Valores trocados:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
}

