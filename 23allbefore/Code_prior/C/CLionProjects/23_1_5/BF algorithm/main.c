#include <stdio.h>
#include <string.h>

int mate(char* B,char*A);
int main()
{
    int number=mate("ababcabcacbab","abcac");
    printf("相互匹配的位置是%d",number);
}
int mate(char* B,char*A)
{
    int i=0,j=0;
    while(i< strlen(B)&&j< strlen(A))
    {
        if(A[j]==B[i]){i++;j++;}
        else
        {   i = i - j + 1; j=0;   }
    }
    if(j== strlen(A)) return (i- strlen(A)+1);
    return 0;
}