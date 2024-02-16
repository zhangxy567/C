#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

// 函数声明
bool isPrime(int num);

int main() {
    printf("100到200之间的素数:\n");

    for (int i = 100; i <= 200; ++i) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}

// 判断一个数是否为素数的函数
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}
