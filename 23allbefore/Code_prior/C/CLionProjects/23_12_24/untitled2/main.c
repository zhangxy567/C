#include <stdio.h>
#include <string.h>
int max( int a, int b)
{
    return (a>b?a:b);
}

int main()
{   int x,y,maxvalue;
    int (* pmax)(int,int)=max;
    printf("请输入两数\n");
    scanf("%d %d",&x,&y);
    maxvalue=(*pmax)(x,y);
    printf("两数中最大的是%d   \n",maxvalue);
    return 0;


}
