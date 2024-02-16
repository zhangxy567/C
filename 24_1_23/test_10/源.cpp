#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 函数声明
int gcd(int a, int b);

int main() {
    int num1, num2;


    // 输入两个数
    printf("请输入两个整数，以空格分隔：");
    scanf("%d %d", &num1, &num2);

    // 调用函数计算最大公约数
    int result = gcd(num1, num2);

    // 输出结果
    printf("最大公约数是：%d\n", result);

    return 0;
}

// 辗转相除法求最大公约数
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
