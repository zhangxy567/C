#include <stdio.h>
#include <stdlib.h>
int main()
{   int a[]={1,2,3,4,5,6};
    int* p=a,i=2;
    printf("%d\n",a[i]);
    printf("%d\n",*(p+i));
    printf("%d\n",p[i]);
    p=a+i;
    printf("%d\n",*p);

    return 0;
}
