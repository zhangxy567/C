#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // �������������
    srand(time(NULL));

    // ����һ��1��100֮��������
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    printf("��ӭ�μӲ�������Ϸ��\n");
    printf("��һ��1��100֮������֡�\n");

    do {
        // ��ȡ�û�����
        printf("��������Ĳ²⣺");
        scanf("%d", &guess);

        // ���Ӳ²����
        attempts++;

        // ���²��Ƿ���ȷ
        if (guess == secretNumber) {
            printf("��ϲ�㣬�¶��ˣ������� %d �β²⡣\n", attempts);
            break; // ����ѭ��
        }
        else if (guess < secretNumber) {
            printf("��С�ˣ�������һ�Ρ�\n");
        }
        else {
            printf("�´��ˣ�������һ�Ρ�\n");
        }

    } while (1); // ����ѭ����ֱ���¶�Ϊֹ

    return 0;
}
