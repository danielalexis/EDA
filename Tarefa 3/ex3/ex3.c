#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100

typedef struct pilha {
    int top;
    int stack[SIZE];
} Pilha;

void init(Pilha *p1) {
    p1->top = -1;
};

void push(Pilha *p1, int value) {
    if (p1->top == SIZE) {
        printf("Pilha cheia!\n");
        return;
    }
    p1->stack[p1->top] = value;
    p1->top++;
}

bool isEqual(Pilha *p1, Pilha *p2) {
    if (p1->top != p2->top) {
        return false;
    }
    for (int i = 0; i < p1->top; i++) {
        if (p1->stack[i] != p2->stack[i]) {
            return false;
        }
    }
    return true;
}

void maxMinAvg(Pilha *p1) {
    float max = p1->stack[0];
    float min = p1->stack[0];
    float avg = 0;
    for (int i = 0; i < p1->top; i++) {
        if (p1->stack[i] > max) {
            max = p1->stack[i];
        }
        if (p1->stack[i] < min) {
            min = p1->stack[i];
        }
        avg += p1->stack[i];
    }
    avg /= p1->top;
    printf("Maximo: %.2f\n", max);
    printf("Minimo: %.2f\n", min);
    printf("Media: %.2f\n", avg);
}

void copy(Pilha *p1, Pilha *p2) {
    for (int i = 0; i < p1->top; i++) {
        p2->stack[i] = p1->stack[i];
    }
    p2->top = p1->top;
}

void numsPar(Pilha *p1) {
    int count = 0;
    for (int i = 0; i < p1->top; i++) {
        if (p1->stack[i] % 2 == 0) {
            count++;
        }
    }
    printf("Quantidade de numeros pares: %d\n", count);
}

void numsImpar(Pilha *p1) {
    int count = 0;
    for (int i = 0; i < p1->top; i++) {
        if (p1->stack[i] % 2 != 0) {
            count++;
        }
    }
    printf("Quantidade de numeros impares: %d\n", count);
}

void main() {
    Pilha p1, p2;
    int value;
    init(&p1);
    init(&p2);

    for (int i = 0; i < 5; i++) {
        printf("Valor (pilha 1): ");
        scanf("%d", &value);
        push(&p1, value);
    }

    copy(&p1, &p2);



    if (isEqual(&p1, &p2)) {
        printf("Pilhas iguais!\n");
    } else {
        printf("Pilhas diferentes!\n");
    }

    printf("Valor (pilha 2): ");
    scanf("%d", &value);
    push(&p2, value);

    if (isEqual(&p1, &p2)) {
        printf("Pilhas iguais!\n");
    } else {
        printf("Pilhas diferentes!\n");
    }

    maxMinAvg(&p1);

    numsPar(&p1);

    numsImpar(&p1);
    return;
}