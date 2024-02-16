#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int i, j;

    printf("9*9 ³Ë·¨¿Ú¾÷±í£º\n");

    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d * %d = %2d\t", j, i, j * i);
        }
        printf("\n");
    }

    return 0;
}
