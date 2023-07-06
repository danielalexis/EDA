#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main() {
    int a, b;
    printf("Primeiro Inteiro: ");
    scanf(" %d", &a);
    printf("Segundo Inteiro: ");
    scanf(" %d", &b);
    if (a > b) {
        trocar(&a, &b);
    } else {
        trocar(&b, &a);
    }
    printf("O maior inteiro é %d\n", a);
    printf("O menor inteiro é %d", b);
}

