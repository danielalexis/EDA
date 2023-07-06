#include <stdio.h>

void main() {
    float a[10] = {1.1, 2.234, 3.2345, 4.543, 5.132, 6.123, 7.312, 8.13, 9.13, 10.23123};
    for (int i = 0; i < 10; i++) {
        printf("%d\n", &a[i]);
    }
}

