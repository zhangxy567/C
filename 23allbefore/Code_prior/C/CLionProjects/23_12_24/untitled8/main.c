#include <stdio.h>
#include <string.h>

typedef char(*PTR_TO_ARR)[30];
typedef int (*PTR_TO_FUNC)(int ,int );

int max(int a,int b)
{
    return (a>b?a:b);
}

char str[3][30] = {
        "http://c.biancheng.net",
        "CÓïÑÔÖĞÎÄÍø",
        "C-Language"
};


int main() {
    int i;
    PTR_TO_ARR parr=str;
    PTR_TO_FUNC pfunc=max;
    printf("max=%d\n",(*pfunc)(10,20));
    for(i=0;i<3;i++)
    {
        printf("%s\n",parr+i);
    }
    return 0;
}
