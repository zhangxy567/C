#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define linkNum 5


typedef struct link
{
    char a[linkNum];
    struct link* next;
}link;

link* initLink(link* head,char* str);
void display(link*head);

int main()
{
    link* head=NULL;
    head= initLink(head,"data.biancheng.net");
    display(head);
    return  0;
}
link* initLink(link * head,char *str)
{
    int length=strlen(str);
    int num=length/linkNum;
    if(length%linkNum){++num;}
    head=(link*) malloc(sizeof (link));
    head->next=NULL;
    link* temp=head;
    for(int i=0;i<num;i++)
    {
        int j=0;
        for(;j<linkNum;j++)
        {
            if(i*linkNum+j<length)
            {temp->a[j]=str[i*linkNum+j];}
            else temp->a[j]='#';
        }
        if(i*linkNum+j<length)
        {
            link * body=(char *) malloc(sizeof (link));
            body->next=NULL;
            temp->next=body;
            temp=body;
        }
    }
    return head;
}
void display(link * head)
{
    link *temp=head;
    while(temp)
    {
        for (int i = 0; i < linkNum; i++)
        {
            printf("%c", temp->a[i]);
        }
        temp=temp->next;
    }
}