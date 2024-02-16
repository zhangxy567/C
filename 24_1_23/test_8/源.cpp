#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int startYear = 1000;
    int endYear = 2000;

    printf("Leap years between %d and %d:\n", startYear, endYear);

    for (int year = startYear; year <= endYear; year++) {
        // 判断闰年的条件
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            printf("%d ", year);
        }
    }

    return 0;
}
