#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int data[MAX_SIZE];
} Pilha;

typedef struct {
    int front;
    int rear;
    int data[MAX_SIZE];
} Fila;

void initStack(Pilha *p1) {
    p1->top = -1;
}

void push(Pilha *p1, int data) {
    if (p1->top == MAX_SIZE - 1) {
        printf("A pilha está cheia.\n");
        return;
    }
    p1->data[++p1->top] = data;
}


void initQueue(Fila *f1) {
    f1->front = f1->rear = -1;
}

void enqueue(Fila *f1, int data) {
    if ((f1->rear + 1) % MAX_SIZE == f1->front) {
        printf("A fila está cheia.\n");
        return;
    }
    if (f1->front == -1) {
        f1->front = f1->rear = 0;
    } else {
        f1->rear = (f1->rear + 1) % MAX_SIZE;
    }
    f1->data[f1->rear] = data;
}

int dequeue(Fila *f1) {
    if (f1->front == -1) {
        printf("A fila está vazia.\n");
        return -1;
    }
    int data = f1->data[f1->front];
    if (f1->front == f1->rear) {
        f1->front = f1->rear = -1;
    } else {
        f1->front = (f1->front + 1) % MAX_SIZE;
    }
    return data;
}

void main() {
    Pilha p1;
    Fila filaPar, filaImpar;
    int num;

    initStack(&p1);
    initQueue(&filaPar);
    initQueue(&filaImpar);

    printf("Digite vários números para a pilha (Número menor que 0 para finalizar):\n");

    while (1) {
        scanf("%d", &num);
        if (num < 0) {
            break;
        }
        push(&p1, num);
    }

    printf("\nPilha digitada: ");
    while (p1.top != -1) {
        num = p1.data[p1.top--];
        printf("%d ", num);
        if (num % 2 == 0) {
            enqueue(&filaPar, num);
        } else {
            enqueue(&filaImpar, num);
        }
    }
    printf("\n");
    printf("Fila par: ");
    while (filaPar.front != -1) {
        num = dequeue(&filaPar);
        printf("%d ", num);
    }
    printf("\n");

    printf("Fila ímpar: ");
    while (filaImpar.front != -1) {
        num = dequeue(&filaImpar);
        printf("%d ", num);
    }


    return;
}
