#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    double result = 0.0;

    for (int i = 1; i <= 100; ++i) {
        if (i % 2 == 1) {
            // ���������ֱ�Ӽ��� 1/i
            result += 1.0 / i;
        }
        else {
            // ����ż�����ȥ 1/i
            result -= 1.0 / i;
        }
    }

    printf("���еĺ�Ϊ: %.6f\n", result);

    return 0;
}