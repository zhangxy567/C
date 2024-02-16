#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    double result = 0.0;

    for (int i = 1; i <= 100; ++i) {
        if (i % 2 == 1) {
            // 对于奇数项，直接加上 1/i
            result += 1.0 / i;
        }
        else {
            // 对于偶数项，减去 1/i
            result -= 1.0 / i;
        }
    }

    printf("序列的和为: %.6f\n", result);

    return 0;
}