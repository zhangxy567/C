#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int numbers[10];  // ���ڴ洢�����10������
    int i, max;

    // ��ȡ�û�����
    printf("������10��������\n");
    for (i = 0; i < 10; ++i) {
        printf("������� %d ��������", i + 1);
        scanf("%d", &numbers[i]);
    }

    // �����һ���������ֵ
    max = numbers[0];

    // ���������ҵ����ֵ
    for (i = 1; i < 10; ++i) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    // ������
    printf("�����10�������е����ֵ�ǣ�%d\n", max);

    return 0;
}
