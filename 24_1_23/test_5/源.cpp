#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int numbers[10];  // 用于存储输入的10个整数
    int i, max;

    // 获取用户输入
    printf("请输入10个整数：\n");
    for (i = 0; i < 10; ++i) {
        printf("请输入第 %d 个整数：", i + 1);
        scanf("%d", &numbers[i]);
    }

    // 假设第一个数是最大值
    max = numbers[0];

    // 遍历数组找到最大值
    for (i = 1; i < 10; ++i) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    // 输出结果
    printf("输入的10个整数中的最大值是：%d\n", max);

    return 0;
}
