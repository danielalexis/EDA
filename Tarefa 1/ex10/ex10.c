#include <stdio.h>

void main() {
    int array[5];
    int *ptr = array;
    for (int i = 0; i < 5; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("Dobro do numero %d: %d\n", i + 1, *(ptr + i) * 2);
    }
}

