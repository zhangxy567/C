#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef enum Bool
{
    False=0,
    True=1
}bool;
int main() {

    return 0;
}
bool LinkIntersect(link* p1,link* p2)
{
    link* plong=p1;
    link* pshort=p2;
    link* temp=NULL;
    int num1=0,num2=0,step;
    while(plong)
    {
        plong=plong->next;
        num1++;
    }
    while(pshort)
    {
        pshort=pshort->next;
        num2++
    }
    if(num1<num2)
    {
        plong=p2;
        pshort=p1;
        step=num2-num1;
    }
    else step=num1-num2;
    temp=plong;
    while(step)
    {
        temp=temp->next;
        step--;
    }
    while (temp&&pshort)
    {
        if(temp==pshort) return True;
        temp=temp->next;
        pshort=pshort->next;
    }
    return False;
}