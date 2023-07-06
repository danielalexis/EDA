#include <stdio.h>

void main() {
    int a = 10;
    float b = 3.14;
    char c = 'A';
    int *ptrA = &a;
    float *ptrB = &b;
    char *ptrC = &c;

    printf("Valores das variaveis originais:\n");
    printf("a = %d\n", a);
    printf("b = %f\n", b);
    printf("c = %c\n", c);

    printf("Valores dos ponteiros originais:\n");
    printf("ptrA = %d\n", *ptrA);
    printf("ptrB = %f\n", *ptrB);
    printf("ptrC = %c\n", *ptrC);

    *ptrA = 20;
    *ptrB = 6.28;
    *ptrC = 'B';

    printf("Valores das variaveis alteradas:\n");
    printf("a = %d\n", a);
    printf("b = %f\n", b);
    printf("c = %c\n", c);

    printf("Valores das ponteiros alterados:\n");
    printf("ptrA = %d\n", *ptrA);
    printf("ptrB = %f\n", *ptrB);
    printf("ptrC = %c\n", *ptrC);
}