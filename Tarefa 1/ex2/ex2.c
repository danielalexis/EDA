#include <stdio.h>

void main() {
    int a = 1;
    int b = 3;
    if (&a > &b) {
        printf("%d", &a);
    } else {
        printf("%d", &b);
    }
}