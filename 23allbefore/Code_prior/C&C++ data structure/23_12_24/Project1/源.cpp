#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main() {
    int a[3][4] = { {0,1,2,3},{4,5,6,7},{8,9,10,11} };
    int(*p)[4] = a;
    printf("%d\n", sizeof(*(p + 1)));
    printf("%d\n", sizeof(*(p + 1) + 1));
    printf("%d\n", sizeof(*(*(p + 1) + 1)));
    printf("%d\n", sizeof(p[1][1]));
    return 0;
}
