#include <stdio.h>

void main() {
    float matriz[3][3] = {
        {1.1, 2.2, 3.3}, 
        {4.4, 5.5, 6.6}, 
        {7.7, 8.8, 9.9}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%p ", &matriz[i][j]);
        }
        printf("\n");
    }
}

