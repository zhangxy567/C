#include <stdio.h>
#include <string.h>

int main() {
    int a,m=10;
    printf("请输入一个整数\n");
    scanf("%d",&a);
    switch(a) {
        case 1:
            printf("Mon  ");
            break;
        case 2:
            printf("Tue  ");
            break;
        case 3:
            printf("Wed  ");
            break;
        case 4:
            printf("Thur ");
            break;
        case 5:
            printf("Fri  ");
            break;
        case 6:
            printf("Sat  ");
            break;
        case 7:
            printf("Sun  ");
            break;
        default:
            printf("error");

    }

    return 0;
}
