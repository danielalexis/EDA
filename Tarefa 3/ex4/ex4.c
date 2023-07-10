#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100

typedef struct fila {
    int front;
    int rear;
    int queue[SIZE];
} Fila;

void init(Fila *f1) {
    f1->front = -1;
    f1->rear = -1;
}

void enqueue(Fila *f1, int value) {
    if ((f1->rear + 1) % SIZE == f1->front) {
        printf("Fila cheia!\n");
        return;
    }
    if (f1->front == -1) {
        f1->front = 0;
        f1->rear = 0;
    } else {
        f1->rear = (f1->rear + 1) % SIZE;
    }
    f1->queue[f1->rear] = value;
}

int dequeue(Fila *f1) {
    if (f1->front == -1) {
        printf("Fila vazia!\n");
        return -1;
    }
    int value = f1->queue[f1->front];
    if (f1->front == f1->rear) {
        f1->front = -1;
        f1->rear = -1;
    } else {
        f1->front = (f1->front + 1) % SIZE;
    }
    return value;
}

bool isEqual(Fila *f1, Fila *f2) {
    if ((f1->rear - f1->front) != (f2->rear - f2->front)) {
        return false;
    }
    int i = f1->front;
    int j = f2->front;
    while (i != f1->rear) {
        if (f1->queue[i] != f2->queue[j]) {
            return false;
        }
        i = (i + 1) % SIZE;
        j = (j + 1) % SIZE;
    }
    return true;
}

void maxMinAvg(Fila *f1) {
    float max = f1->queue[f1->front];
    float min = f1->queue[f1->front];
    float avg = 0;
    int count = 0;
    int i = f1->front;
    while (i != f1->rear) {
        if (f1->queue[i] > max) {
            max = f1->queue[i];
        }
        if (f1->queue[i] < min) {
            min = f1->queue[i];
        }
        avg += f1->queue[i];
        count++;
        i = (i + 1) % SIZE;
    }
    avg /= count;
    printf("Máximo: %.2f\n", max);
    printf("Mínimo: %.2f\n", min);
    printf("Média: %.2f\n", avg);
}

void copy(Fila *f1, Fila *f2) {
    f2->front = f1->front;
    f2->rear = f1->rear;
    int i = f1->front;
    while (i != f1->rear) {
        f2->queue[i] = f1->queue[i];
        i = (i + 1) % SIZE;
    }
    f2->queue[f1->rear] = f1->queue[f1->rear];
}

void numsPar(Fila *f1) {
    int count = 0;
    int i = f1->front;
    while (i != f1->rear) {
        if (f1->queue[i] % 2 == 0) {
            count++;
        }
        i = (i + 1) % SIZE;
    }
    printf("Quantidade de números pares: %d\n", count);
}

void numsImpar(Fila *f1) {
    int count = 0;
    int i = f1->front;
    while (i != f1->rear) {
        if (f1->queue[i] % 2 != 0) {
            count++;
        }
        i = (i + 1) % SIZE;
    }
    printf("Quantidade de números ímpares: %d\n", count);
}

void main() {
    Fila f1, f2;
    int value;
    init(&f1);
    init(&f2);

    for (int i = 0; i < 5; i++) {
        printf("Valor (fila 1): ");
        scanf("%d", &value);
        enqueue(&f1, value);
    }

    copy(&f1, &f2);

    if (isEqual(&f1, &f2)) {
        printf("Filas iguais!\n");
    } else {
        printf("Filas diferentes!\n");
    }

    printf("Valor (fila 2): ");
    scanf("%d", &value);
    enqueue(&f2, value);

    if (isEqual(&f1, &f2)) {
        printf("Filas iguais!\n");
    } else {
        printf("Filas diferentes!\n");
    }

    maxMinAvg(&f1);

    numsPar(&f1);

    numsImpar(&f1);

    return;
}
