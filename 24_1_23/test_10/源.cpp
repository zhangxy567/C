#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// ��������
int gcd(int a, int b);

int main() {
    int num1, num2;


    // ����������
    printf("�����������������Կո�ָ���");
    scanf("%d %d", &num1, &num2);

    // ���ú����������Լ��
    int result = gcd(num1, num2);

    // ������
    printf("���Լ���ǣ�%d\n", result);

    return 0;
}

// շת����������Լ��
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
