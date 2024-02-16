#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Link
{
    char elem;
    struct Link *next;
}link;
link *initLink()
{
    link* p=NULL;
    link* temp=(link*)malloc(sizeof(link));
    temp->elem=1;
    temp->next=NULL;
    p=temp;
    for(int i=2;i<5;i++)
    {
        link* a= malloc(sizeof (link));
        a->elem=i;
        a->next=NULL;
        temp->next=a;
        temp=temp->next;
    }
    return p;
}
int main() {

    return 0;
}
