#include <stdio.h>
#include <string.h>
int max( int a, int b)
{
    return (a>b?a:b);
}

int main()
{   int x,y,maxvalue;
    int (* pmax)(int,int)=max;
    printf("����������\n");
    scanf("%d %d",&x,&y);
    maxvalue=(*pmax)(x,y);
    printf("������������%d   \n",maxvalue);
    return 0;


}
