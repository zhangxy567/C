#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

// ��������
bool isPrime(int num);

int main() {
    printf("100��200֮�������:\n");

    for (int i = 100; i <= 200; ++i) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}

// �ж�һ�����Ƿ�Ϊ�����ĺ���
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
