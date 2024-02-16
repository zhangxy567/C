#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 设置随机数种子
    srand(time(NULL));

    // 生成一个1到100之间的随机数
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    printf("欢迎参加猜数字游戏！\n");
    printf("猜一个1到100之间的数字。\n");

    do {
        // 获取用户输入
        printf("请输入你的猜测：");
        scanf("%d", &guess);

        // 增加猜测次数
        attempts++;

        // 检查猜测是否正确
        if (guess == secretNumber) {
            printf("恭喜你，猜对了！你用了 %d 次猜测。\n", attempts);
            break; // 结束循环
        }
        else if (guess < secretNumber) {
            printf("猜小了，请再试一次。\n");
        }
        else {
            printf("猜大了，请再试一次。\n");
        }

    } while (1); // 无限循环，直到猜对为止

    return 0;
}
