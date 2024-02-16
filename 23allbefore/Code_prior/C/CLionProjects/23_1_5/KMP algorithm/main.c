#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Next(char*T,int *next)
{
    next[1]=0;
    int j=0;
    int i=1;
    while(i< strlen(T))
    {
        if(j==0||T[j-1]==T[i-1])
        {
            i++;
            j++;
            if(T[j-1]!=T[i-1]) next[i]=j;
            else next[i]=next[j];
        }
        else j=next[j];
    }

}
int KMP(char* S,char * T)
{
    int next[20];
    Next(T,next);
    int i=1;
    int j=1;

    while (i<=strlen(S)&&j<= strlen(T))
    {
        if(j==0||T[j-1]==S[i-1])
        {
            j++;
            i++;
        }
        else j=next[j];
    }
    if(j> strlen(T)) return i- strlen(T);
    return -1;
}
int main()
{
    int i=KMP("ababcabcacbab","abcac");
    if(i>0) printf("∆•≈‰≥…π¶Œª÷√ «%d\n",i);
    else printf("∆•≈‰ ß∞‹\n");
}
