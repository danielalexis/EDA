#include <stdio.h>

void main() {
    int a;
    int b;
    printf("Primeiro Inteiro: ");
    scanf(" %d", &a);
    printf("Segundo Inteiro: ");
    scanf(" %d", &b);
    if (&a > &b) {
        printf("O maior endereço é do inteiro %d com o endereço %d", a, &a);
    } else {
        printf("O maior endereço é do inteiro %d com o endereço %d", b, &b);
    }
}